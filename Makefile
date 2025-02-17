# Lexon compiler Makefile
#
#	works with
#
#	gcc 7.5.0
#	clang 12.0.5
#	bison 3.8
#	flex 2.5.35
#	make 3.81
#
#	earlier versions may work
#
# This makefile is two in one as it takes care of two building cycles, with or
# without generation of the required c sources on the way: if the c sources are
# provided--as in the master branch--the build works without the requirement of
# Flex and Bison allowing for easier building and better portability. If the
# sources are not provided--as after cleaning--they are generated using lexccc,
# Flex and Bison. This requires two different dependencies paths, essentially
# one being content with all c sources, the other, building them when outdated.


SHELL := /bin/bash
VPATH = bin:grammar:src:build
MAKEFLAGS += --no-print-directory

# installation location
ifeq ($(PREFIX),)
  ifneq ($(DESTDIR),)
    PREFIX := $(DESTDIR)
  else
    PREFIX := /usr/local
  endif
endif

tmp = $(shell date "+%Y-%m-%d-%H-%M-%S")

hi = \033[97m
lo = \033[38m
err = \033[91m
warn = \033[38;5;214m
ok = \033[36m
off = \033[0m

has_gindent = $(shell which gindent)
has_valgrind = $(shell which valgrind)

ifeq ($(wildcard tests/tag.exp),)
  define check_for_exp
	@printf "\n$(warn)Can't run regression tests: test expectation files are missing.$(off)\n"
	@echo "Depending on what you meant to achieve, it can make sense to check out the"
	@echo "original expectation files that came with this commit to tests/. Or to create"
	@echo "them yourself using"
	@echo
	@echo "	make expectations"
	@echo
	@exit 1
  endef
else
  define check_for_exp
  endef
endif

all: build sample

help:
	# make rules
	#
	# all           build compiler and run an example (default)
	# build         build compiler
	# install       install compiler (run with sudo)
	# mac install   install pre-built mac binary and copy it as bin/lexon
	# linux install install pre-built linux binary and copy it as bin/lexon
	# sample        compile escrow example to solidity
	# check         compiler tests: focustest, deeptest
	# devcheck      all tests: envtest, grammarcheck, memtest, focustest, deeptest
	# testlog       dump the 100 last lines of the test log
	# clean         delete all built files, except pre-built binaries
	# ls            show the source and build directories
	# license       show the license agreement
	# help          this list
	#
	# ▫️  dev support
	#
	# lexccc        a build part: build lexccc compiler compiler
	# lexon         a build part: build lexon compiler
	# distclean     clean and pre-build cycle 2 sources for master branch
	# devclean      clean and delete pre-build binaries (dev branch)
	# diffclean     clean and pre-build backend modules (targets branch)
	# srcclean      devclean and delete test expectations (sources branch)
	# rulecheck     test of different repository clean state transitions
	#
	# ▫️  3rd level of tests: grammar
	# grammarcheck  grammar check with extended yacc grammar checks
	# conflicts     grammar check that lists ambiguously used tokens (slow)
	# counter       grammar check that lists examples for ambiguous code
	# focustest     grammar check compiling release-defining examples
	# focusprep     build result references for future focustest runs
	#
	# ▫️  2nd level of tests: components
	# deeptest      memory handling, includes, language parser, compiler
	# comptest      compile the _results_ of all failing deep tests natively
	# compall       compile all deep test results natively
	# compmiss      compile the deep test results that failed before
	# memtest       valgrind & internal memory leak tests
	# update        interactive update of failing deeptests's result references
	# recheck       faster update, skipping successful tests of earlier deeptest
	# autoupdate    automatic update of failing deeptests's result references
	# expectations  full non-interactive update of all deeptest result references
	# new           creation of missing deeptest result references
	#
	# ▫️  1st level of tests: build environment
	# envtest       test of build environment, gcc, flex, mtrac memory checks

build:
	@if (! $(MAKE) -s -o lexccc -q lexccc.c build/.parser & ! $(MAKE) -s lexccc) ; \
		then printf "\n$(hi)▫️  cycle 1: build compiler compiler $(off)\n\n" ; \
		$(MAKE) lexccc ; \
	fi
	@if (! $(MAKE) -s -o lexccc -q lexon) ; \
		then printf "\n$(hi)▫️  cycle 2: build compiler $(off)\n\n" ; \
		$(MAKE) -o lexccc lexon ; \
	fi
	@if [[ ! -e build/.built ]] ; \
		then printf "$(ok)build done: bin/lexon.$(off)\n\n" ; \
		touch build/.built ; \
	fi

lexccc: lexccc.c

	@mkdir -p bin
	cd build ; gcc -std=c99 -o ../bin/lexccc lexccc.c
	@echo

lexccc.c: src/lexon.l

	@mkdir -p build
	cd build ; lex -o lexccc.c ../src/lexon.l

build/.parser: lexccc src/lexon.l grammar/english.lgf
	@printf "$(ok)» frontend $(off)\n\n"
	@mkdir -p build
	@rm -f build/.built
	@cp README.MD build/README
	cd build ; ../bin/lexccc -Yparser.y -Hparser.h -Sscanner.l -F../src/lexon.l -Lcore ../grammar/english.lgf
	cd build ; bison -d -Wn -o parser.c parser.y
	cd build ; flex -d -o scanner.c scanner.l
	@touch build/.parser
	@echo

lexon: build/.parser build/.targets
	@printf "$(ok)» compiler $(off)\n\n"
	cd build ; gcc -std=c99 -o ../bin/lexon scanner.c parser.c core.c javascript.c solidity.c sophia.c
	@echo

build/.targets: build/scanner.c build/parser.c build/.backend build/core.c build/javascript.c build/solidity.c build/sophia.c
	@cd build ; sed -i.bak -e "/^$$/{N;/^\n$$/d;}" core.c
	@cd build ; sed -i.bak -e "/^$$/{N;/^\n$$/d;}" javascript.c
	@cd build ; sed -i.bak -e "/^$$/{N;/^\n$$/d;}" solidity.c
	@cd build ; sed -i.bak -e "/^$$/{N;/^\n$$/d;}" sophia.c
	@cd build ; rm -f *.c.bak
ifeq (, $(has_gindent))
	@printf "$(warn)» skipping indentation. gindent not installed. $(off)\n"
else
	@printf "» indenting\n"
	@cp src/.indent.pro build/
	@cd build ; gindent javascript.c solidity.c sophia.c
	@cd build ; rm -f *.c~
endif
	@touch build/.targets
	@touch build/.parser
	@echo

build/.backend:
	@printf "$(ok)» backend $(off)\n\n"
	@mkdir -p build
	@touch build/.backend

build/scanner.c build/parser.h build/parser.c: | build/.parser

build/core.c: lexccc grammar/english.lgf $(wildcard src/core.c)
	@if [[ -e src/core.c ]] ; then \
		printf "$(ok)» using core target module from src/$(off)\n" ; \
		cp src/core.c build/ ; \
	else \
		echo "» building core target from english grammar definition" ; \
		cd build ; \
		../bin/lexccc -Tcore.c ../grammar/english.lgf ; \
		sed -E -i.bak -e "s/\/\*T\*\///" core.c ; \
	fi

build/javascript.c: src/target.c src/.indent.pro $(wildcard src/javascript.c)
	@if [[ -e src/javascript.c ]] ; then \
		printf "$(ok)» using javascript target module from src/$(off)\n" ; \
		cp src/javascript.c build/ ; \
	else \
		echo "» building javascript target from unified target module" ; \
		cd build ; \
		sed -E -e "s/\/\*T\*\///" -e "s/\/\*JS \*\/ ?//" -e "s/\/\*J\+S\*\/ ?//" -e "s/\/\*Sol.*//" -e "s/\/\*Sop.*//" -e "s/\/\*S\+S.*//" -e "s/xxx_/js_/g" -e 's/ ##.*//g' ../src/target.c > javascript.c ; \
	fi

build/solidity.c: src/target.c src/.indent.pro $(wildcard src/solidity.c)
	@if [[ -e src/solidity.c ]] ; then \
		printf "$(ok)» using solidity target module from src/$(off)\n" ; \
		cp src/solidity.c build/ ; \
	else \
		echo "» building solidity target from unified target module" ; \
		cd build ; \
		sed -E -e "s/\/\*T\*\///" -e "s/\/\*Sol\*\/ ?//" -e "s/\/\*S\+S\*\/ ?//" -e "s/\/\*J\+S\*\///" -e "s/\/\*Sop.*//" -e "s/\/\*JS.*//" -e "s/xxx_/sol_/g" -e 's/ ##.*//g' ../src/target.c > solidity.c ; \
	fi

build/sophia.c: src/target.c src/.indent.pro $(wildcard src/sophia.c)
	@if [[ -e src/sophia.c ]] ; then \
		printf "$(ok)» using sophia target module from src/$(off)\n" ; \
		cp src/sophia.c build/ ; \
	else \
		echo "» building sophia target from unified target module" ; \
		cd build ; \
		sed -E -e "s/\/\*T\*\///" -e "s/\/\*Sop\*\/ ?//" -e "s/\/\*S\+S\*\/ ?//" -e "s/\/\*Sol.*//" -e "s/\/\*JS.*//" -e "s/\/\*J\+S.*//" -e "s/xxx_/sophia_/g" -e 's/ ##.*//g' ../src/target.c > sophia.c ; \
	fi

install:
	@install -d $(PREFIX)/bin/
	install bin/lexon $(PREFIX)/bin/

mac:
ifeq (,$(wildcard bin/lexon_mac))
	$(error Lexon binary for Mac not present in bin/. Try a fresh clone of the master branch.)
endif
	@touch -A-0100 bin/lexon_mac
	cp -p bin/lexon_mac bin/lexon

linux:
ifeq (,$(wildcard bin/lexon_linux))
	$(error Lexon binary for Linux not present in bin/. Try a fresh clone of the master branch.)
endif
	@touch -A-0100 bin/lexon_linux
	cp -p bin/lexon_linux bin/lexon


sample: build
ifeq (,$(wildcard .nosample))
	@printf "\n$(hi)▫️  compile escrow example $(off)\n\n"
	@printf "$(ok)bin/lexon --solidity examples/escrow.lex$(off)\n\n"
	@bin/lexon --solidity examples/escrow.lex
	@echo
endif

check: focustest deeptest

devcheck: envtest grammarcheck memtest focustest deeptest

grammarcheck: build
	@printf "\n$(hi)▫️  grammar checks $(off)\n\n"
	@echo "» expected: 7 shift/reduce and 2 reduce/reduce conflicts .."
	cd build ; bison -d -Wall --color=yes -Wdangling-alias parser.y
	@echo "» to run with -Wcounterexamples use 'make conflicts' (brief output) and 'make counter' (detailed output)."
	@echo "» The temporary ambiguities reflected in these conflicts are intented."
	@echo

conflicts: build
	@printf "\n$(hi)▫️  grammar ambiguity check: conflicting tokens $(off)\n\n"
	@echo "» this test takes time"
	cd build ; bison -d -Wcounterexamples parser.y 2>&1 | grep conflict | sed -e "s/parser.y: warning: //" -e "s/\[-W.*\]//" | awk '!x[$$0]++'
	@echo

counter: build
	@printf "\n$(hi)▫️  grammar ambiguity check: details of any shift/reduce problems of the grammar $(off)\n\n"
	cd build ; bison -d -Wcounterexamples --color=yes parser.y
	@echo

focusprep: build
	@cd tests ; $(MAKE) focusprep

focustest: build
	@cd tests ; $(MAKE) focustest

expclean:
	@cd tests ; $(MAKE) expclean

deeptest: build
	@printf "\n$(hi)▫️  deep test $(off)\n"
ifneq (,$(wildcard tests/tag.exp))
	@cd tests ; $(MAKE) deeptest
	@echo
else
	@printf "\n$(warn)Can't run regression tests: test expectation files are missing.$(off)\n"
	@echo "Depending on what you meant to achieve, it can make sense to check out the"
	@echo "original expectation files that came with this commit to tests/. Or to create"
	@echo "them yourself using"
	@echo
	@echo "	make expectations"
	@echo
	@exit 1
endif

comptest: build
	@printf "\n$(hi)▫️  deep test with native compilation for failing tests$(off)\n"
ifneq (,$(wildcard tests/tag.exp))
	@cd tests ; $(MAKE) comptest 
	@echo
else
	@printf "\n$(warn)Can't run regression tests: test expectation files are missing.$(off)\n"
	@echo "Depending on what you meant to achieve, it can make sense to check out the"
	@echo "original expectation files that came with this commit to tests/. Or to create"
	@echo "them yourself using"
	@echo
	@echo "	make expectations"
	@echo
	@exit 1
endif

compmiss: build
	@printf "\n$(hi)▫️  deep test with native compilation for all that did not pass native$(off)\n"
	$(check_for_exp)
	@cd tests ; $(MAKE) compmiss
	@echo

compall: build
	@printf "\n$(hi)▫️  deep test with native compilation for all$(off)\n"
ifneq (,$(wildcard tests/tag.exp))
	@cd tests ; $(MAKE) compall
	@echo
else
	@printf "\n$(warn)Can't run regression tests: test expectation files are missing.$(off)\n"
	@echo "Depending on what you meant to achieve, it can make sense to check out the"
	@echo "original expectation files that came with this commit to tests/. Or to create"
	@echo "them yourself using"
	@echo
	@echo "	make expectations"
	@echo
	@exit 1
endif

update: build
	@printf "\n$(hi)▫️  interactive update of deeptest reference results $(off)\n\n"
	@cd tests ; $(MAKE) update
	@echo

autoupdate: build
	@printf "\n$(hi)▫️  auto-update of deeptest reference results $(off)\n\n"
	@cd tests ; $(MAKE) autoupdate
	@echo

autocomp: build
	@printf "\n$(hi)▫️  auto-update of deeptest reference results and native compile test$(off)\n\n"
	@cd tests ; $(MAKE) autocomp
	@echo

recheck: build
	@printf "\n$(hi)▫️  interactive update of deeptest reference results,  skipping successful tests of last test run $(off)\n\n"
	@cd tests ; $(MAKE) recheck
	@echo

expectations: build
	@printf "\n$(hi)▫️  recreate all deeptest result references $(off)\n"
	@cd tests ; $(MAKE) expectations
	@$(MAKE) focusprep

new: build
	@printf "\n$(hi)▫️  create missing deeptest result references $(off)\n\n"
	@cd tests ; $(MAKE) new
	@echo

envtest:
	@printf "\n$(hi)▫️  test build environment: flex, gcc, mtrac memory tracker $(off)\n\n"
	cd tests ; flex -DWHITEBOX -o whitebox.c ../src/lexon.l
	cd tests ; gcc -o test -include whitebox.c test-memory-14.c
	cd tests ; ./test
	@echo "√ build environment tests passed ok." # otherwise would not reach here
	@echo

memtest: build
	@printf "\n$(hi)▫️  memory leak tests: valgrind and internal $(off)\n\n"

	@printf "$(ok)» internal leak checks$(off)\n\n"
	bin/lexon -M -Q --core examples/escrow.lex 
	@echo
	bin/lexon -M -Q --javascript examples/evaluation.lex 
	@echo
	bin/lexon -M -Q --solidity examples/statement.lex 
	@echo

ifeq (, $(has_valgrind))
	@printf "$(warn)» skipping valgrind, not installed. $(off)\n\n"
else
	@printf "$(ok)» valgrind leak checks$(off)\n\n"
	valgrind --leak-check=full bin/lexon -Q --core examples/escrow.lex 
	@echo
	valgrind --leak-check=full bin/lexon -Q --javascript examples/evaluation.lex 
	@echo
	valgrind --leak-check=full bin/lexon -Q --solidity examples/statement.lex 
	@echo
endif

testlog:
	@cd tests ; $(MAKE) testlog

clean:
	@printf "\n\n$(hi)▫️  clean built and generated files $(off)\n\n"
	rm -f .????????
	rm -f bin/lexccc
	rm -f bin/lexon
	rm -rf build
	@echo
	@cd tests ; $(MAKE) clean
	@echo
	@echo .:
	@ls -A
	@echo
	@echo bin:
	@if [ -e bin ] ; then ls bin ; else echo "[not present]" ; fi
	@echo
	@echo src:
	@ls -A src
	@echo
	@printf "$(ok)√ cleaned for building from cycle 1 $(off)\n\n"

distclean: restore_binaries
	@printf "\n\n$(hi)▫️  clean and pre-build for distribution $(off)\n\n"
	@$(MAKE) binaries clean build
	@printf "\n$(hi)▫️  clean build folder for distribution  $(off)\n\n"
	rm -f bin/lexccc
	rm -f bin/lexon
	rm -f build/.indent.pro
	rm -f build/.built
	rm -f build/README
	@echo cd tests
	@cd tests ; $(MAKE) clean
	@$(MAKE) ls
	@printf "$(ok)√ cleaned and pre-built for master branch $(off)\n\n"
	@echo
	@echo ls should look like this:
	@printf "$(lo)\n\n"
	@echo "ls -A"
	@echo ".git		bin		LICENSE		README.MD	build		grammar		tests"
	@echo ".gitignore	CREDITS		Makefile	examples	src		.bin.bak"
	@echo ""
	@echo "ls -A grammar"
	@echo "english.lgf"
	@echo ""
	@echo "ls -A src"
	@echo ".indent.pro	lexon.l		target.c"
	@echo ""
	@echo "ls -A build"
	@echo ".backend	.targets	javascript.c	parser.c	parser.y	scanner.l	sophia.c"
	@echo ".parser		core.c		lexccc.c	parser.h	scanner.c	solidity.c"
	@echo ""
	@echo "ls -A bin"
	@echo "lexon_linux	lexon_mac"
	@echo ""
	@echo "ls -A examples"
	@echo "escrow.lex	evaluation.lex	statement.lex"
	@printf "$(off)\n"
	@echo ""
	git status

binaries:
	@echo "» checking that binaries are in place"
ifeq (,$(wildcard bin/lexon_mac))
	$(error Mac binary bin/lexon_mac missing)
endif
ifeq (,$(wildcard bin/lexon_linux))
	$(error Linux binary bin/lexon_linux missing)
endif

restore_binaries:
	@mkdir -p bin
	-cp -n .bin.bak/lexon_* bin/

diffclean:
	@printf "\n\n$(hi)▫️  clean and pre-build for targets branch $(off)\n\n"
	@$(MAKE) clean expclean build
	mkdir -p .bin.bak
	-mv bin/lexon_* .bin.bak
	@rm -rf bin
	rm -f build/scanner.*
	rm -f build/parser.*
	rm -f build/.backend
	rm -f build/.built
	rm -f build/.parser
	rm -f build/.targets
	rm -f build/README
	@echo
	@echo .:
	@ls -A
	@echo
	@echo bin:
	@if [ -e bin ] ; then ls bin ; else echo "[not present]" ; fi
	@echo
	@echo src:
	@ls -A src
	@echo
	@printf "$(ok)√ cleaned for targets branch $(off)\n\n"
	@git branch
	@git status

devclean: clean
	mkdir -p .bin.bak
	-mv bin/lexon_* .bin.bak
	@rm -rf bin
	@echo
	@echo .:
	@ls -A
	@echo
	@echo bin:
	@if [ -e bin ] ; then ls bin ; else echo "[not present]" ; fi
	@echo
	@echo build:
	@if [ -e build ] ; then ls build ; else echo "[not present]" ; fi
	@echo
	@echo src:
	@ls -A src
	@echo
	@printf "$(ok)√ deep cleaned for dev branch$(off)\n"
	@printf "Deleted all pre-built and gererated files except test expectations.\n\n"
	@git branch
	@git status

srcclean:
	@printf "\n$(hi)▫️  all clean for sources branch $(off)\n\n"
	@$(MAKE) clean expclean
	mkdir -p .bin.bak
	-mv bin/lexon_* .bin.bak
	@rm -rf bin
	@rm -rf build

	@echo
	@echo .:
	@ls -A
	@echo
	@echo bin:
	@if [ -e bin ] ; then ls bin ; else echo "[not present]" ; fi
	@echo
	@echo build:
	@if [ -e build ] ; then ls bin ; else echo "[not present]" ; fi
	@echo
	@echo src:
	@ls -A src
	@echo
	@printf "$(ok)√ cleaned for sources branch $(off)\n\n"
	@git branch
	@git status

ls:
	@echo

	-ls -A
	@echo

	-ls -A grammar
	@echo

	-ls -A src
	@echo

	-ls -A build
	@echo

	-ls -A bin
	@echo

	-ls -A examples
	@echo

license:
	cat LICENSE

rulecheck:
	echo 'n' | $(MAKE) distclean
	$(MAKE) all
	echo 'n' | $(MAKE) distclean
	$(MAKE) build
	$(MAKE) devclean
	$(MAKE) all
	$(MAKE) devclean
	$(MAKE) build
	$(MAKE) diffclean
	$(MAKE) all
	$(MAKE) diffclean
	$(MAKE) build
	$(MAKE) clean
	$(MAKE) lexccc
	$(MAKE) clean
	$(MAKE) lexon
	$(MAKE) clean
	$(MAKE) all
	$(MAKE) clean
	$(MAKE) build
	$(MAKE) srcclean
	$(MAKE) all
	$(MAKE) new
	echo 'y' | $(MAKE) expectations
	$(MAKE) new
	$(MAKE) sample
	$(MAKE) check
	$(MAKE) devcheck
	$(MAKE) envtest
	$(MAKE) testlog
	$(MAKE) ls
	$(MAKE) license
	$(MAKE) help
	$(MAKE) check
	$(MAKE) deeptest
	$(MAKE) recheck
	$(MAKE) update
	$(MAKE) check
	$(MAKE) grammarcheck
	$(MAKE) conflicts
	$(MAKE) counter
	$(MAKE) focustest
	$(MAKE) focusprep
	$(MAKE) focustest
	$(MAKE) clean
	$(MAKE) restore_binaries
	echo 'n' | $(MAKE) distclean
	$(MAKE) ls
	@printf "\n$(hi)√ sanity check of make rules complete$(off)\n\n"

.PHONY: all help build install sample check comptest compall devcheck grammarcheck conflicts counter focusprep focustest expclean deeptest update autoupdate autocomp recheck expectations new envtest testlog clean distclean binaries restore_binaries diffclean devclean srcclean ls license rulecheck

# (c) 2025 H. Diedrich, see file LICENSE
