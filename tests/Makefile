# Lexon main test suite.
#
# The test logic is in this file, the source in the *.lex files and others in this folder and the subfolders.

SHELL := /bin/bash

hi = \033[97m
ok = \033[36m
err = \033[91m
off = \033[0m

ifeq (, $(shell which md5sum))
        MD5=md5 -q
else
        MD5=md5sum
endif

define sep
	printf '$(1)%.0s' {1..$(2)} ; printf '\n'
endef

define init
	@echo 0 > ok.tmp
	@echo 0 > err.tmp
	@echo 0 > warn.tmp
	@echo 0 > skip.tmp
	@echo 0 > update.tmp
	@echo 0 > testnumber.tmp
	@echo 0 > testlines.tmp
	@echo 0 > nowlines.tmp
	@echo 0 > explines.tmp
endef

define count
	echo $$((`cat $(1).tmp` + 1)) > $(1).tmp
endef

define discount
	echo $$((`cat $(1).tmp` - 1)) > $(1).tmp
endef

define tag
	@echo OS: `uname` `printf "$$OSTYPE "` > $(1)
	@echo lexon: `../bin/lexon --version` `$(MD5) ../bin/lexon | cut -c-5` >> $(1)
	@cat ../Makefile | grep -o -E '\.targets:.*' | cut -c 2- | sed 's/build\/._targets //g' | sed 's/build\///g' | sed 's/\.c//g' >> $(1)
	@# 	@printf commit: echo `git rev-parse HEAD` >> $(1)
	@printf "tests: %d+ files (" $$((`find . | grep -e '\.lex$$' -e '\.c$$' -e '\.lgf$$' | wc -l`)) >> $(1)
	@cat `find . | grep -e '\.lex$$' -e '\.c$$' -e '\.lgf$$'` | $(MD5) | cut -c -5 | tr "\n" "\0" >> $(1)
	@printf "), %d+ tests (" $$((`find . | grep -e '\.exp$$' | wc -l | sed 's/ //g'`)) >> $(1)
	@cat `find . | grep -e '\.exp$$'` | $(MD5) | cut -c -5 | tr "\n" "\0" >> $(1)
	@echo "), script (`$(MD5) Makefile | cut -c-5`)" >> $(1)
endef

define buildexp
	@echo
	@echo "$(1) expectations"
	@printf '–%.0s' {1..$(shell printf "$(1) expectations" | wc -c | sed 's/ //g')}
	@echo ; \
	testnumber=`cat testnumber.tmp`; \
	for filename in `$(6)`; do \
		testnumber=$$(($$testnumber+1)) \
		; expname=$$(basename "$$filename" .lex)$(7) \
		; if [[ -f onlynew ]] && [[ -f "$$expname" ]] ; then printf "·" ; touch skipped.tmp ; continue ; fi \
		; testname="`echo $$filename | sed -e 's/test-//g' -e 's/.lex//g' -e 's/-/ /g'`" \
		; if [[ -f skipped.tmp ]] ; then printf "\n" ; rm skipped.tmp ; fi \
		; printf "build #%03d $$testname .. " $$testnumber \
		; if [ -n "$(8)" ] ; then \
			failer=`grep -c -E "%ERR|$(8)" $$filename` \
		; else \
			failer=0 \
		; fi \
		; $(2) \
		; $(3) $(4) $$filename &> tmp \
		; ret=$$? \
		; $(5) >> tmp 2>&1 \
		; ret=$$(($$ret+$$?)) \
		; mv tmp $$expname \
		; if (( $$ret == 0 )) && (( $$failer == 0 )) ; then echo ok ; $(call count,ok) ; fi \
		; if (( $$ret == 0 )) && (( $$failer > 0 )) ; then echo "should have failed: $(3) $(4) $$filename ???" ; $(call count,err) ; fi \
		; if (( $$ret == 1 )) && (( $$failer > 0 )) ; then echo "ok (fails as expected)" ;  $(call count,ok) ; fi \
		; if (( $$ret == 1 )) && (( $$failer == 0 )) ; then echo "fails unexpectedly: $(3) $(4) $$filename ###" ;  $(call count,err) ; fi \
		; if (( $$ret > 1 )) ; then echo "error #$$ret: $(3) $(4) $$filename ###" ;  $(call count,err) ; fi \
	; done ; \
	echo $$testnumber > testnumber.tmp
endef

define testrun
	@if [[ ! -f quit.tmp ]] ; then \
	    printf "\n$(ok)$(1) tests$(off)\n" ; \
	    if [[ ! -f concise ]] ; then printf '–%.0s' {1..$(shell printf "$(1) tests" | wc -c | sed 's/ //g')} ; echo ; fi ; \
	    testnumber=`cat testnumber.tmp` ; \
	    quit=0 ; \
	    for filename in `$(6)`; do \
		testnumber=$$(($$testnumber+1)) \
		; echo "$(3) $(4) $$filename" > now.tmp \
		; if [[ -f lastfail ]] &&  [[ ! -f nopickup ]]; then diff now.tmp lastfail > tmp ; rret=$$? \
			; if (( $$rret == 0 )) ; then \
				echo " picking up:" ; rm lastfail ; echo \
			; else printf "·" \
				; $(call count,skip) \
				; continue \
			; fi \
		; fi \
		; expfile=$$(basename "$$filename" .lex)$(7) \
		; testfile=$$(basename "$$expfile" .exp).now \
		; testname="`echo $$filename | sed -e 's/test-//g' -e 's/.lex//g' -e 's/-/ /g'`" \
		; if [[ ! -f concise ]] ; then printf "test #%03d $$testname .. " $$testnumber ; fi \
		; if [ -n "$(8)" ] ; then \
			failer=`grep -c -E "%ERR|$(8)" $$filename` \
		; else \
			failer=0 \
		; fi \
		; $(2) \
		; $(3) $(4) $$filename &> tmp \
		; $(5) >> tmp 2>&1 \
		; ret=$$? \
		; mv tmp $$testfile \
		; echo $$((`cat testlines.tmp` + `cat $$filename | wc -l`)) > testlines.tmp \
		; echo $$((`cat nowlines.tmp` + `cat $$testfile | wc -l`)) > nowlines.tmp \
		; if [[ ! -f $$expfile ]] ; then read -p "no expectation on file for $(3) $(4) $$filename, create .exp file now? " -n 1 -r ; echo ; if [[ $$REPLY =~ ^[Yy]$$ ]] ; then \
				mv $$testfile $$expfile ;  $(call count,update) \
			; fi \
			; continue \
		; fi \
		; echo $$((`cat explines.tmp` + `cat $$expfile | wc -l`)) > explines.tmp \
		; diff -d -y --suppress-common-lines $$expfile $$testfile > diff.tmp \
		; dret=$$? \
		; if [[ -f concise ]] ; then \
		    if (( $$dret == 0 )) ; then printf "+" ; $(call count,ok) ; fi \
		    ; if (( $$dret == 1 )) ; then printf "#" ; $(call count,err) ; if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; touch nopickup ; fi ; fi \
		    ; if (( $$dret == 2 )) ; then printf "o" ; $(call count,skip) ; fi \
		; else \
		    if (( $$dret == 0 )) && (( $$ret == 0 )) && (( $$failer == 0 )) ; then echo ok ; $(call count,ok) ; fi \
		    ; if (( $$dret == 0 )) && (( $$ret >  0 )) && (( $$failer >  0 )) ; then echo "ok (errors as expected)" ; $(call count,ok) ; fi \
		    ; if (( $$dret == 0 )) && (( $$ret >  0 )) && (( $$failer == 0 )) ; then echo "ok (unmarked error, output as expected)" ; $(call count,warn) ; fi \
		    ; if (( $$dret == 0 )) && (( $$ret == 0 )) && (( $$failer >  0 )) ; then echo "ok (marked error, output as expected)" ; $(call count,warn) ; fi \
		    ; if (( $$dret == 2 )) ; then echo "can't perform test -> skip" ; $(call count,skip) ; fi \
		    ; if (( $$dret == 1 )) ; then echo "failed: $(3) $(4) $$filename #< exp | got >#" ;  $(call count,err) ; $(call sep,#,132) ; cat diff.tmp ; $(call sep,#,132) ; \
			if [[ ! -f noupdate ]] ; then \
			    while :; do echo; printf "$(hi) Update expectation file for $(3) $(4) $$filename? $(off)"; read -p "(U)pdate, (K)eep old, (I)gnore now, (Q)uit, (R)esult, (E)xpected, (S)ource, (P)recompile, (D)iff, (F)ull diff, ignore (W)hitespace diff: " -n 1 -r ; echo \
				; if   [[ $$REPLY =~ ^[Uu]$$ ]] ; then echo "previous expectation backed up in $$expfile.bak" \
					; mv $$expfile $$expfile.bak ; mv $$testfile $$expfile ;  $(call count,update) ; $(call discount,err) ; break \
				; elif [[ $$REPLY =~ ^[Rr]$$ ]] ; then echo "Result now ($$testfile):" ; $(call sep,_,132) ; cat $$testfile ; $(call sep,_,132) \
				; elif [[ $$REPLY =~ ^[Ee]$$ ]] ; then echo "Expected result not gotten ($$expfile):" ; $(call sep,:~,66) ; cat $$expfile ; $(call sep,:~,66) \
				; elif [[ $$REPLY =~ ^[Ss]$$ ]] ; then echo "Source code ($$filename):" ; $(call sep,=•,66) ; cat $$filename ; $(call sep,=•,66) \
				; elif [[ $$REPLY =~ ^[Pp]$$ ]] ; then echo "Precompiled source code ($$filename):" ; $(call sep,«»,66) ; $(3) $(4) -p $$filename ; $(call sep,«»,66) \
				; elif [[ $$REPLY =~ ^[Ff]$$ ]] ; then echo "Difference #< exp | got >#:" \
					; diff -y $$expfile $$testfile | sed -e "s/»/»  /g" | sed -e "s/.*|.*/`printf "\033[33m&\033[0m"`/" -e "s/.*<.*/`printf "\033[31m&\033[0m"`/" -e "s/.*>.*/`printf "\033[36m&\033[0m"`/" \
				; elif [[ $$REPLY =~ ^[Dd]$$ ]] ; then echo "Difference from expectation:" \
					; diff -u $$expfile $$testfile | sed -e "s/^-/`printf "\033[31m"`-/" -e "s/^+/`printf "\033[36m"`+/" -e "s/$$/`printf "\033[0m"`/" \
				; elif [[ $$REPLY =~ ^[Ww]$$ ]] ; then echo "Difference from expectation, ignoring whitespace:" \
					; diff -b -u $$expfile $$testfile | sed -e "s/^-/`printf "\033[31m"`-/" -e "s/^+/`printf "\033[36m"`+/" -e "s/$$/`printf "\033[0m"`/" \
				; elif [[ $$REPLY =~ ^[Kk]$$ ]] ; then if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; touch nopickup ; fi ; break \
				; elif [[ $$REPLY =~ ^[Ii]$$ ]] ; then if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; touch nopickup ; fi ; touch noupdate ; break \
				; elif [[ $$REPLY =~ ^[Qq]$$ ]] ; then if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; fi ; quit=1 ; break 2 \
				; fi \
			    ; done \
			; else if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; touch nopickup ; fi \
			; fi \
		  ; fi \
		; fi \
	    ; done \
	    ; echo \
	    ; echo $$testnumber > testnumber.tmp \
	    ; if (( $$quit == 1 )) ; then touch quit.tmp ; fi ; \
	fi
endef

files=test-*.lex

all: clean test
	@echo tests done.

one:
	$(MAKE) test files=test-include-01.lex

clean:
	@echo » deleting regression test results
	rm -f tmp
	rm -f *.tmp
	rm -f *.now
	rm -f *.bak
	rm -f *.test
	rm -f whitebox.c
	rm -f a.out
	rm -f test
	rm -f focus/*.jsx
	rm -f focus/*.sol
	rm -f focus/*.aes
	rm -f focus/*.lcc
	rm -f lastfail
	rm -f nopickup
	rm -f noupdate
	rm -f concise
	rm -f onlynew
	rm -f perfect

expclean: clean
	@echo » deleting regression test expectations
	rm -f *.exp

test:
	@touch concise
	@touch noupdate
	@rm -f lastfail
	@$(MAKE) _test

update:
	@rm -f concise
	@rm -f noupdate
	@rm -f lastfail
	@$(MAKE) _test

recheck:
	@rm -f concise
	@rm -f noupdate
	@rm -f nopickup
	@$(MAKE) _test

_test:
	@echo
	@printf "$(ok)» regression tests$(off)\n"
	@echo ===================
	@printf "\nexpectations from:\n"
	@cat tag.exp
	$(call tag,tag.now)
	@printf "\ncurrent setup:\n"
	@cat tag.now
	@rm -f *.tmp
	$(call init)
	@flex -D WHITEBOX -o whitebox.c ../src/lexon.l
	@$(call testrun,memory,rm -f a.out,gcc,-include whitebox.c,./a.out,grep -l %MEM test-memory-*.c,.mem.exp,)
	@$(call testrun,precompile,:,../bin/lexon,-P,:,grep -l %PRE $(files),.pre.exp,%PREERR)
	@$(call testrun,gui generator info,:,../bin/lexon,-U,:,grep -l %GEN $(files),.gen.exp,%GENERR)
	@$(call testrun,circular includes,:,../bin/lexon,-C -P,:,grep -l %PRE $(files),.cir.exp,%CIRERR)
	@$(call testrun,repeat includes,:,../bin/lexon,-R -P,:,grep -l %PRE $(files),.rep.exp,%REPERR)
	@$(call testrun,circular and repeat,:,../bin/lexon,-R -C -P,:,grep -l %PRE $(files),.car.exp,%CARERR)
	@$(call testrun,jurisdictions list,:,../bin/lexon,-J,:,ls -1 test-hello-00.lex,.jur.exp,)
	@$(call testrun,jurisdiction parsing,:,../bin/lexon,-P,:,grep -l %JUR test-*.lex,.jur.exp,)
	@$(call testrun,lxf extension grammar production,:,../bin/lexon,,:,grep -l %LXF test-*.lex,.lxf.exp,%LXFERR)
	@$(call testrun,lgf lexon grammar production,:,../bin/lexon,-B,:,ls -1 test-*.lgf,.lgf.exp,%LGFERR)
	@$(call testrun,english grammar parsing,:,../bin/lexon,,:,ls -1 english/test-*.lex,.eng.exp,)
	@$(call testrun,core language,:,../bin/lexon,--core,:,ls -1 lexon/*.lex,.core.exp,)
	@$(call testrun,tree,:,../bin/lexon,--tree,:,ls -1 lexon/*.lex,.tree.exp,)
	@$(call testrun,flat tree,:,../bin/lexon,--flat --tree,:,ls -1 lexon/*.lex,.flat.exp,)
	@$(call testrun,javascript barebones,:,../bin/lexon,--javascript -b,:,ls -1 lexon/*.lex,.jsb.exp,)
	@$(call testrun,javascript full-feature,:,../bin/lexon,--javascript -x,:,ls -1 lexon/*.lex,.jsx.exp,)
	@$(call testrun,solidity barebones,:,../bin/lexon,--solidity -b,:,ls -1 lexon/*.lex,.solb.exp,)
	@$(call testrun,solidity full-feature,:,../bin/lexon,--solidity -x,:,ls -1 lexon/*.lex,.solx.exp,)
	@$(call testrun,sophia barebones,:,../bin/lexon,--sophia -b,:,ls -1 lexon/*.lex,.sopb.exp,)
	@$(call testrun,sophia full-feature,:,../bin/lexon,--sophia -x,:,ls -1 lexon/*.lex,.sopx.exp,)
	@if [[ ! -f quit.tmp ]] ; then \
		echo ; \
		ok=`cat ok.tmp` ; \
		err=`cat err.tmp` ; \
		warn=`cat warn.tmp` ; \
		skip=`cat skip.tmp` ; \
		update=`cat update.tmp` ; \
		rm -f perfect ; \
		echo ; \
		echo "OK: $$ok - errors: $$err - warnings: $$warn - updates: $$update - skipped: $$skip" ; \
		if (( $$err == 1 )) ; then printf "$(err)### $$err error #############################################$(off)\n"; fi ; \
		if (( $$err > 1 ))  ; then printf "$(err)### $$err errors ############################################$(off)\n"; fi ; \
		if (( $$warn > 0 )) ; then printf "$(hi)/// $$warn warnings //////////////////////////////////////////$(off)\n"; fi ; \
		if (( $$skip > 0 )) ; then printf "$(hi)||| $$skip tests skipped |||||||||||||||||||||||||||||||||||||$(off)\n"; fi ; \
		if (( $$ok == 0 )) && (( $$err == 0 )) && (( $$warn == 0 )) && (( $$update == 0 )) && (( $$skip == 0 )) \
			; then printf "$(hi)### no tests ###############################################$(off)\n"; fi ; \
		if (( $$ok == 0 )) && (( $$err == 0 )) && (( $$warn == 0 )) && (( $$update == 0 )) && (( $$skip != 0 )) \
			; then printf "$(ok)### all skipped ############################################$(off)\n"; fi ; \
		if (( $$ok != 0 )) && (( $$err == 0 )) && (( $$warn == 0 )) && (( $$update == 0 )) && (( $$skip == 0 )) \
			; then printf "$(hi)=== perfect ================================================$(off)\n"; touch perfect ; fi ; \
		printf "Processed %'.f lines of source, %'.f lines of output, %'.f lines of expectations, running %'.f tests vs more than %'.f files.\n" \
			`cat testlines.tmp` `cat nowlines.tmp` `cat explines.tmp` $$((`cat testnumber.tmp` - `cat skip.tmp`)) $$((`ls -1 *.lex | wc -w | sed 's/ //g'` + `ls -1 english/*.lex | wc -w | sed 's/ //g'` + `ls -1 lexon/*.lex | wc -w | sed 's/ //g'`)) ; \
		if [[ ! -f perfect ]] ; then \
			echo ; \
			printf "Regarding the failing tests, unless you changed the source code of Lexon itself, they should have worked.\n" ; \
			printf "➡︎ If you are developing, you can rebuild all expectations at once with 'make expectations'.\n" ; \
			if [[ -f noupdate ]] ; then printf "➡︎ Better yet, run 'make update' to update test expectations one by one and interactively. You will be able to list the source and outputs.\n" ; fi ; \
			if [[ -f lastfail ]] && [[ -f nopickup ]] ; then printf "➡︎ When developing, run 'make recheck' to skip tests before the first error. It otherwise works like 'make update'.\n" ; fi ; \
		fi ; \
	fi
	@echo

%.try: %.lex
	../bin/lexon $*
	@echo $^ $@
	diff $^ $@
	if (( $? == 0 )) ; then echo ok ; fi
	if (( $? == 1 )) ; then echo not ; fi
	if (( $? == 2 )) ; then echo worse ; fi

new:
	@echo
	@echo Building missing expectation files that regression tests will compare against
	@echo This sets the current lexon build as benchmark for future tests.
	@echo
	@touch onlynew
	$(MAKE) _expects

expectations:
	@echo
	@echo Rebuilding expectation files that regression tests will compare against
	@echo This sets the current lexon build as benchmark for future tests.
	@echo
	@read -p "Proceed to overwrite all .exp files? " -n 1 -r ; echo ; if [[ $$REPLY =~ ^[Yy]$$ ]] ; then \
		rm -f onlynew ; \
		$(MAKE) expclean ; \
		$(MAKE) _expects ; \
	    fi

_expects:
	@echo
	@echo Regression Expectations
	@echo =======================
	$(call init)
	@flex -D WHITEBOX -o whitebox.c ../src/lexon.l
	$(call buildexp,memory,rm -f a.out,gcc,-include whitebox.c,./a.out,grep -l %MEM test-memory-*.c,.mem.exp,)
	$(call buildexp,precompile,:,../bin/lexon,-P,:,grep -l %PRE test-*.lex,.pre.exp,%PREERR)
	$(call buildexp,gui generator info,:,../bin/lexon,-U,:,grep -l %GEN test-*.lex,.gen.exp,%GENERR)
	$(call buildexp,circular includes,:,../bin/lexon,-C -P,:,grep -l %PRE test-*.lex,.cir.exp,%CIRERR)
	$(call buildexp,repeat includes,:,../bin/lexon,-R -P,:,grep -l %PRE test-*.lex,.rep.exp,%REPERR)
	$(call buildexp,circular and repeat,:,../bin/lexon,-C -R -P,:,grep -l %PRE test-*.lex,.car.exp,%CARERR)
	$(call buildexp,jurisdictions list,:,../bin/lexon,-J,:,ls -1 test-hello-00.lex,.jur.exp,)
	$(call buildexp,jurisdiction parsing,:,../bin/lexon,-P,:,grep -l %JUR test-*.lex,.jur.exp,)
	$(call buildexp,lxf grammar production,:,../bin/lexon,,:,grep -l %LXF test-*.lex,.lxf.exp,%LXFERR)
	$(call buildexp,lgf lexon grammar production,:,../bin/lexon,-B,:,ls -1 test-*.lgf,.lgf.exp,%LGFERR)
	$(call buildexp,english grammar parsing,:,../bin/lexon,,:,ls -1 english/test-*.lex,.eng.exp,%ERR)
	$(call buildexp,core language,:,../bin/lexon,--core,:,ls -1 lexon/*.lex,.core.exp,)
	$(call buildexp,tree,:,../bin/lexon,--tree,:,ls -1 lexon/*.lex,.tree.exp,)
	$(call buildexp,flat tree,:,../bin/lexon,--flat --tree,:,ls -1 lexon/*.lex,.flat.exp,)
	$(call buildexp,javascript barebones,:,../bin/lexon,--javascript -b,:,ls -1 lexon/*.lex,.jsb.exp,)
	$(call buildexp,javascript full-feature,:,../bin/lexon,--javascript -x,:,ls -1 lexon/*.lex,.jsx.exp,)
	$(call buildexp,solidity barebones,:,../bin/lexon,--solidity -b,:,ls -1 lexon/*.lex,.solb.exp,)
	$(call buildexp,solidity full-feature,:,../bin/lexon,--solidity -x,:,ls -1 lexon/*.lex,.solx.exp,)
	$(call buildexp,sophia barebones,:,../bin/lexon,--sophia -b,:,ls -1 lexon/*.lex,.sopb.exp,)
	$(call buildexp,sophia full-feature,:,../bin/lexon,--sophia -x,:,ls -1 lexon/*.lex,.sopx.exp,)
	@echo ; \
	ok=`cat ok.tmp` ; \
	err=`cat err.tmp` ; \
	echo "OK: $$ok errors: $$err" ; \
	if (( $$err > 0 )) ; then echo "Fails with error code < 2 are interpreted as ok. Check the real errors." ; fi ; \
	if (( $$err > 0 )); then echo "### $$err errors #########################"; fi ; \
	if (( $$ok == 0 )) && (( $$err == 0 )) ; then echo "### no tests #########################"; fi ; \
	if (( $$ok != 0 )) && (( $$err == 0 )) ; then echo "==== perfect ===="; fi
	$(call tag,tag.exp)
	@if [[ -f onlynew ]] ; then echo "VALID FOR NEWEST ONLY" >> tag.exp ; fi
	@cat tag.exp
	@echo

grammar_expectations:
	@echo
	@echo Rebuilding grammar test expectation files that regression tests will compare against
	@echo This sets the current lexon build as benchmark for future tests.
	@echo
	@read -p "Proceed to overwrite all grammar test .exp files? " -n 1 -r ; echo ; if [[ $$REPLY =~ ^[Yy]$$ ]] ; then \
		rm -f onlynew ; \
		$(MAKE) grammar_expclean ; \
		$(MAKE) grammar_expects ; \
	    fi

grammar_expects:
	@echo
	@echo Grammar Test Regression Expectations
	@echo ====================================
	$(call tag,tag.exp)
	@if [[ -f onlynew ]] ; then echo "VALID FOR NEWEST ONLY" >> tag.exp ; fi
	@cat tag.exp
	$(call init)
	$(call buildexp,english grammar parsing,:,../bin/lexon,,:,ls -1 english/test-*.lex,.eng.exp,%ERR)
	@echo ; \
	ok=`cat ok.tmp` ; \
	err=`cat err.tmp` ; \
	echo "OK: $$ok errors: $$err" ; \
	if (( $$err > 0 )) ; then echo "Fails with error code < 2 are interpreted as ok. Check the real errors." ; fi ; \
	if (( $$err > 0 )); then echo "### $$err errors #########################"; fi ; \
	if (( $$ok == 0 )) && (( $$err == 0 )) ; then echo "### no tests #########################"; fi ; \
	if (( $$ok != 0 )) && (( $$err == 0 )) ; then echo "==== perfect ===="; fi
	@echo

list_expectations:
	@echo Listing of the expected results for the test source files used in the deeptest suit.
	@echo Test sources that are being re-used will sometimes have different results.
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-memory-*.c.mem.exp
	@printf "\n$(hi)▫️  PRECOMPILE TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.pre.exp
	@printf "\n$(hi)▫️  GUI GENERATOR INFO TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.gen.exp
	@printf "\n$(hi)▫️  INCLUDES TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.cir.exp
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.rep.exp
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.car.exp
	@printf "\n$(hi)▫️  JURISDICTION TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.jur.exp
	@printf "\n$(hi)▫️  LXF GRAMMAR EXTENSION PRODUCTION TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.lxf.exp
	@printf "\n$(hi)▫️  LGF LEXON GRAMMAR PRODUCTION TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.lgf.exp
	@printf "\n$(hi)▫️  ENGLISH GRAMMAR PARSING TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.eng.exp
	@printf "\n$(hi)▫️  LEXON COMPILATION TESTS: CORE LANGUAGE $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.core.exp
	@printf "\n$(hi)▫️  LEXON COMPILATION TESTS: TREE $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.tree.exp
	@printf "\n$(hi)▫️  LEXON COMPILATION TESTS: FLAT TREE $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.flat.exp
	@printf "\n$(hi)▫️  LEXON COMPILATION TESTS: JAVASCRIPT $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.jsb.exp
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.jsx.exp
	@printf "\n$(hi)▫️  LEXON COMPILATION TESTS: SOLIDITY $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.solb.exp
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.solx.exp
	@printf "\n$(hi)▫️  LEXON COMPILATION TESTS: SOPHIA $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.sopb.exp
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' *.sopx.exp

list_sources:
	@echo Listing of the test source files used in the deeptest suit.
	@echo Some test source files are re-used by different types of tests. They appear multiple times below.
	@echo Tests are pulling them in by grepping for tags \(\%PRE, \%GEN, \%JUR, \%LXF\) and globbing extensions \(.c, .lex, .lgf\).
	@printf "\n$(hi)▫️  MEMORY TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-memory-*.c
	@printf "\n$(hi)▫️  PRECOMPILE TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' `grep -l %PRE test-*.lex`
	@printf "\n$(hi)▫️  GUI GENERATOR INFO TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' `grep -l %GEN test-*.lex`
	@printf "\n$(hi)▫️  INCLUDES TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' `grep -l %PRE test-*.lex`
	@printf "\n$(hi)▫️  JURISDICTION TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-hello-00.lex
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' `grep -l %JUR test-*.lex`
	@printf "\n$(hi)▫️  LXF GRAMMAR EXTENSION PRODUCTION TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' `grep -l %LXF test-*.lex`
	@printf "\n$(hi)▫️  LGF LEXON GRAMMAR PRODUCTION TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' test-*.lgf
	@printf "\n$(hi)▫️  ENGLISH GRAMMAR PARSING TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' english/test-*.lex
	@printf "\n$(hi)▫️  LEXON COMPILATION TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' lexon/*.lex

.PHONY: all build run clean expclean test update recheck _test expectations new _expects one

features:
	echo $(.FEATURES)
