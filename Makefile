# Lexon compiler: Makefile

SHELL := /bin/bash
VPATH = bin:grammar:src:build

tmp = $(shell date "+%Y-%m-%d-%H-%M-%S")
hi = \033[97m
err = \033[91m
warn = \033[38;5;214m
ok = \033[36m
off = \033[0m
errtag = if [[ $$? -eq 0 ]] ; then printf "$(ok)ok$(off)\n" ;  else printf "$(err)\# error$(off)\n" ; fi

has_gindent = $(shell which gindent)

ifeq (, $(shell which colordiff))
        DIFF=diff
else
        DIFF=colordiff
endif


all: build sample

help:
	# make rules
	#
	# all		build compiler and run an example
	# build		build compiler
	# lexccc	[a build part] build lexon compiler compiler compiler
	# lexon		[a build part] build lexon compiler
	# sample	build escrow example to javascript
	# check		all tests: envtest, deeptest, grammarcheck, focustest, sample
	# clean		delete all built files
	# distclean     clean and create backend modules
	# ls            show the source and build directories
	# license       show the license agreement
	# help		this rules list
	#
	# ▫️  3rd level of tests: grammar
	# grammarcheck	grammar checks with extended yacc grammar checks
	# conflicts	grammar check that lists ambiguously used tokens
	# counter	grammar check that lists examples for ambiguous code
	# focusprep	build result references for future focustest runs
	# focustest	grammar check compiling release-defining examples
	#
	# ▫️  2nd level of tests: components
	# deeptest	memory handling, includes, language parser, compiler
	# update	interactive, selective update of deeptest result references
	# recheck	faster update, skipping successful tests of earlier deeptest
	# expectations	full non-interactive update of deeptest result references
	# new		creation of missing deeptest result references
	#
	# ▫️  1st level of tests: build environment
	# envtest	test of build environment, gcc, flex, mtrac memory checks

build: bin/lexon
	@if [[ ! -e build/.built ]] ; then printf "$(ok)build done: bin/lexon.$(off)\n\n" ; fi
	@touch build/.built

bin/lexccc: src/lexon.l
	@printf "\n$(hi)▫️  cycle 1: build compiler compiler $(off)\n\n"
	@mkdir -p build
	@mkdir -p bin
	cd build ; lex -o lexon.c ../src/lexon.l
	cd build ; gcc -o ../bin/lexccc lexon.c
	@echo

bin/lexon: bin/lexccc build/.compiler grammar/english.lgf .targets
	@printf "$(ok)» frontend $(off)\n\n"
	@mkdir -p build
	@rm -f build/.built
	@cp README build/
	cd build ; ../bin/lexccc -Yparser.y -Hparser.h -Sscanner.l -F../src/lexon.l -Lcore ../grammar/english.lgf
	cd build ; bison -d -Wn -o parser.c parser.y
	cd build ; flex -d -o scanner.c scanner.l
	@printf "\n$(ok)» compiler $(off)\n\n"
	cd build ; gcc -o ../bin/lexon scanner.c parser.c core.c javascript.c solidity.c sophia.c
	@echo

build/.compiler:
	@printf "\n$(hi)▫️  cycle 2: build compiler $(off)\n"
	@mkdir -p build
	@touch build/.compiler

inter:
	cd build ; gcc -o ../bin/lexon scanner.c parser.c core.c javascript.c solidity.c sophia.c

build/._targets:
	@printf "\n$(ok)» backend $(off)\n\n"
	@mkdir -p build
	@touch build/._targets

.targets: build/._targets build/core.c build/javascript.c build/solidity.c build/sophia.c
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
	@touch .targets
	@echo

build/core.c: bin/lexccc grammar/english.lgf $(wildcard src/core.c)
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

sample: build
	@printf "\n$(hi)▫️  compile escrow example $(off)\n\n"
	@printf "$(ok)bin/lexon --solidity examples/escrow.lex$(off)\n\n"
	@bin/lexon --solidity examples/escrow.lex
	@echo

check: envtest grammarcheck deeptest focustest

grammarcheck: build
	@printf "\n$(hi)▫️  grammar checks $(off)\n\n"
	@echo "» expected: 7 shift/reduce and 2 reduce/reduce conflicts .."
	cd build ; bison -d -Wall -Wdangling-alias parser.y
	@echo "» to run with -Wcounterexamples use 'make conflicts' (brief output) and 'make counter' (detailed output)."
	@echo "» The temporary ambiguities reflected in these conflicts are intented."
	@echo

conflicts: build
	@printf "\n$(hi)▫️  grammar ambiguity check: conflicting tokens $(off)\n\n"
	cd build ; bison -d -Wcounterexamples parser.y 2>&1 | grep conflict | sed -e "s/parser.y: warning: //" -e "s/\[-W.*\]//" | awk '!x[$$0]++'
	@echo

counter: build
	@printf "\n$(hi)▫️  grammar ambiguity check: details of any shift/reduce problems of the grammar $(off)\n\n"
	cd build ; bison -d -Wcounterexamples parser.y
	@echo

focusprep: build
	@printf "\n$(hi)▫️  preparation for the compiling and diffing of the focustest. $(off)\n\n"

	@echo »»» escrow core
	cd tests/focus ; ../../bin/lexon --core --feedback --log --chaining --signatures --persistence --comment escrow.lex > escrow.lcc.exp

	@echo »»» escrow 2 core
	cd tests/focus ; ../../bin/lexon --core --feedback --log --chaining --signatures --persistence --comment escrow2.lex > escrow2.lcc.exp

	@echo »»» statement core
	cd tests/focus ; ../../bin/lexon --core --feedback --log --chaining --signatures --persistence --comment statement.lex > statement.lcc.exp

	@echo »»» evaluation core
	cd tests/focus ; ../../bin/lexon --core --feedback --log --chaining --signatures --persistence --comment evaluation.lex > evaluation.lcc.exp

	@echo »»» escrow javascript
	cd tests/focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow.lex > escrow.jsx.exp

	@echo »»» escrow 2 javascript
	cd tests/focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow2.lex > escrow2.jsx.exp

	@echo »»» statement javascript
	cd tests/focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment statement.lex > statement.jsx.exp

	@echo »»» evaluation javascript
	cd tests/focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment evaluation.lex > evaluation.jsx.exp

	@echo »»» escrow solidity
	cd tests/focus ; ../../bin/lexon --solidity --comment escrow.lex > escrow.sol.exp

	@echo »»» escrow 2 solidity
	cd tests/focus ; ../../bin/lexon --solidity --comment escrow2.lex > escrow2.sol.exp

	@echo »»» statement solidity
	cd tests/focus ; ../../bin/lexon --solidity --comment statement.lex > statement.sol.exp

	@echo »»» evaluation solidity
	cd tests/focus ; ../../bin/lexon --solidity --comment evaluation.lex > evaluation.sol.exp

	@echo »»» escrow sophia
	cd tests/focus ; ../../bin/lexon --sophia --comment escrow.lex > escrow.aes.exp

	@echo »»» escrow 2 sophia
	cd tests/focus ; ../../bin/lexon --sophia --comment escrow2.lex > escrow2.aes.exp

	@echo »»» statement sophia
	cd tests/focus ; ../../bin/lexon --sophia --comment statement.lex > statement.aes.exp

	@echo ---
	@echo done
	@echo

focustest: build
	@printf "\n$(hi)▫️  focus test $(off)\n\n"
	@echo compiling and diffing of distribution-defining example code.

	@printf "$(ok)• escrow ⟶   core $(off)\n"
	-cd tests/focus ; ../../bin/lexon --core --feedback --log --chaining --signatures --persistence --comment escrow.lex > escrow.lcc
	@cd tests/focus ; $(DIFF) -wB escrow.lcc.exp escrow.lcc ; $(errtag)

	@printf "$(ok)• escrow 2 ⟶   core $(off)\n"
	-cd tests/focus ; ../../bin/lexon --core --feedback --log --chaining --signatures --persistence --comment escrow2.lex > escrow2.lcc
	@cd tests/focus ; $(DIFF) -wB escrow2.lcc.exp escrow2.lcc ; $(errtag)

	@printf "$(ok)• statement ⟶   core $(off)\n"
	-cd tests/focus ; ../../bin/lexon --core --feedback --log --chaining --signatures --persistence --comment statement.lex > statement.lcc
	@cd tests/focus ; $(DIFF) -wB statement.lcc.exp statement.lcc ; $(errtag)

	@printf "$(ok)• evaluation ⟶   core $(off)\n"
	-cd tests/focus ; ../../bin/lexon --core --feedback --log --chaining --signatures --persistence --comment evaluation.lex > evaluation.lcc
	@cd tests/focus ; $(DIFF) -wB evaluation.lcc.exp evaluation.lcc ; $(errtag)

	@printf "$(ok)• escrow ⟶   javascript $(off)\n"
	-cd tests/focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow.lex > escrow.jsx
	@cd tests/focus ; $(DIFF) -wB escrow.jsx.exp escrow.jsx ; $(errtag)

	@printf "$(ok)• escrow 2 ⟶   javascript $(off)\n"
	-cd tests/focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow2.lex > escrow2.jsx
	@cd tests/focus ; $(DIFF) -wB escrow2.jsx.exp escrow2.jsx ; $(errtag)

	@printf "$(ok)• statement ⟶   javascript $(off)\n"
	-cd tests/focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment statement.lex > statement.jsx
	@cd tests/focus ; $(DIFF) -wB statement.jsx.exp statement.jsx ; $(errtag)

	@printf "$(ok)• evaluation ⟶   javascript $(off)\n"
	-cd tests/focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment evaluation.lex > evaluation.jsx
	@cd tests/focus ; $(DIFF) -wB evaluation.jsx.exp evaluation.jsx ; $(errtag)

	@printf "$(ok)• escrow ⟶   solidity $(off)\n"
	-cd tests/focus ; ../../bin/lexon --solidity --comment escrow.lex > escrow.sol
	@cd tests/focus ; $(DIFF) -wB escrow.sol.exp escrow.sol ; $(errtag)

	@printf "$(ok)• escrow 2 ⟶   solidity $(off)\n"
	-cd tests/focus ; ../../bin/lexon --solidity --comment escrow2.lex > escrow2.sol
	@cd tests/focus ; $(DIFF) -wB escrow2.sol.exp escrow2.sol ; $(errtag)

	@printf "$(ok)• statement ⟶   solidity $(off)\n"
	-cd tests/focus ; ../../bin/lexon --solidity --comment statement.lex > statement.sol
	@cd tests/focus ; $(DIFF) -wB statement.sol.exp statement.sol ; $(errtag)

	@printf "$(ok)• evaluation ⟶   solidity $(off)\n"
	-cd tests/focus ; ../../bin/lexon --solidity --comment evaluation.lex > evaluation.sol
	@cd tests/focus ; $(DIFF) -wB evaluation.sol.exp evaluation.sol ; $(errtag)

	@printf "$(ok)• escrow ⟶   sophia $(off)\n"
	-cd tests/focus ; ../../bin/lexon --sophia --comment escrow.lex > escrow.aes
	@cd tests/focus ; $(DIFF) -wB escrow.aes.exp escrow.aes ; $(errtag)

	@printf "$(ok)• escrow 2 ⟶   sophia $(off)\n"
	-cd tests/focus ; ../../bin/lexon --sophia --comment escrow2.lex > escrow2.aes
	@cd tests/focus ; $(DIFF) -wB escrow2.aes.exp escrow2.aes ; $(errtag)

	@printf "$(ok)• statement ⟶   sophia $(off)\n"
	-cd tests/focus ; ../../bin/lexon --sophia --comment statement.lex > statement.aes
	@cd tests/focus ; $(DIFF) -wB statement.aes.exp statement.aes ; $(errtag)

	@echo ---
	@printf "$(ok)done$(off)\n"
	@echo

focusclean:
	rm -rf tests/focus/*.exp

deeptest: build
	@printf "\n$(hi)▫️  deep test $(off)\n\n"
ifneq (,$(wildcard tests/tag.exp))
	@cd tests ; $(MAKE) test
	@echo
else
	@printf "$(warn)Can't run regression tests: test expectation files are missing.$(off)\n"
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

recheck: build
	@printf "\n$(hi)▫️  interactive update of deeptest reference results,  skipping successful tests of last test run $(off)\n\n"
	@cd tests ; $(MAKE) recheck
	@echo

expectations: build
	@printf "\n$(hi)▫️  recreate all deeptest result references $(off)\n"
	@cd tests ; $(MAKE) expectations
	@$(MAKE) focusprep
	@echo

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

clean:
	@printf "\n$(hi)▫️  clean build files $(off)\n\n"
	rm -rf build
	rm -f bin/lexon
	rm -f bin/lexccc
	rm -f .targets
	rm -f .targets
	rm -f build/._targets
	@echo cd tests
	@cd tests ; $(MAKE) clean
	@echo

distclean: clean build expectations
	rm -f .targets
	rm -f bin/lexon
	rm -f bin/lexccc
	rm -f build/.built
	rm -f build/.compiler
	rm -f build/.indent.pro
	rm -f build/._targets
	rm -f build/parser.*
	rm -f build/scanner.*
	rm -f build/README
	rm -f build/lexon.c
	@echo cd tests
	@cd tests ; $(MAKE) clean
	@echo
	@printf "\n$(hi)cleaned and pre-built for distribution $(off)\n\n"
	ls -A bin
	@echo
	ls -A build
	@echo
	ls -A src
	@echo

devclean: clean focusclean
	@rm -f .????????
	@rm -f .targets
	@rm -rf bin
	@cd tests ; $(MAKE) expclean
	@printf "\n$(ok)cleaned, including test expectations, for dev branch$(off)\n"
	@echo
	ls -A src
	@echo
	find . -name "*.exp"
	@echo

install: build
	@echo "There is no install rule. The lexon compiler is in the bin/ folder. You may copy it to /usr/local/bin/ or similar."

ls:
	@echo

	ls grammar
	@echo

	ls src
	@echo

	ls build
	@echo

	ls bin
	@echo

	ls examples
	@echo

license:
	cat LICENSE

.PHONY: all help build builddir inter sample check grammarcheck conflicts counter focusprep focustest deeptest update recheck expectations new envtest clean distclean ls license

# (c) 2024 H. Diedrich, see LICENSE
