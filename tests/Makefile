# Lexon main test suite.
#
# The test logic is in this file, the source in the *.lex files and others in this folder and the subfolders.

SHELL := /bin/bash


hi = \033[97m
ok = \033[36m
dim = \033[90m
err = \033[91m
off = \033[0m
errtag = if [[ $$? -eq 0 ]] ; then printf "$(ok) ok √$(off)\n" ;  else printf "$(err)\# error$(off)\n" ; fi


ifeq (, $(shell which md5sum))
        MD5=md5 -q
else
        MD5=md5sum
endif

ifeq (, $(shell which colordiff))
        DIFF=diff
else
        DIFF=colordiff
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
	@cat ../Makefile | grep -o -E '\.targets:.*' | cut -c 2- | sed 's/ .*backend//g' | sed 's/build\///g' | sed 's/\.c//g' >> $(1)
	@printf commit: echo `git rev-parse HEAD` >> $(1)
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
	    printf "\n## $(1) tests\n\n" >> test.log ; \
	    if [[ ! -f concise ]] ; then printf '–%.0s' {1..$(shell printf "$(1) tests" | wc -c | sed 's/ //g')} ; echo ; fi ; \
	    testnumber=`cat testnumber.tmp` ; \
	    quit=0 ; \
	    for filename in `$(6)`; do \
		testnumber=$$(($$testnumber+1)) \
		; echo "$(3) $(4) $$filename" > now.tmp \
		; if [[ -f lastfail ]] &&  [[ ! -f nopickup ]]; then diff -B now.tmp lastfail > tmp ; rret=$$? \
			; if (( $$rret == 0 )) ; then \
				echo " picking up:" \
				; echo -n " picking up at " >> test.log ; cat lastfail >> test.log \
				; rm -f lastfail \
				; echo \
			; else printf "·" \
				; $(call count,skip) \
				; echo -n "skipping " >> test.log ; cat now.tmp >> test.log \
				; continue \
			; fi \
		; fi \
		; echo -n "testing " >> test.log ; cat now.tmp | tr '\n' ' ' >> test.log \
		; expfile=$$(basename "$$filename" .lex)$(7) \
		; testfile=$$(basename "$$expfile" .exp).now \
		; coktag=$$(basename "$$expfile" .exp).cok \
		; testname="`echo $$filename | sed -e 's/test-//g' -e 's/\.lex//g' -e 's/\.c//g' -e 's/\.lgf//g' -e 's/-/ /g' -e 's/\// /g' -e 's/\./ /g'`" \
		; if [[ ! -f concise ]] ; then printf "test #%03d $$testname .. " $$testnumber ; fi \
		; if [ -n "$(8)" ] ; then \
			failer=`grep -c -E "%ERR|$(8)" $$filename` \
		; else \
			failer=0 \
		; fi \
		; failer2=`grep -c -E "%ERR" $$filename` \
		; $(2) \
		; $(3) $(4) $$filename &> tmp \
		; $(5) >> tmp 2>&1 \
		; ret=$$? \
		; mv tmp $$testfile \
		; echo $$((`cat testlines.tmp` + `cat $$filename | wc -l`)) > testlines.tmp \
		; echo $$((`cat nowlines.tmp` + `cat $$testfile | wc -l`)) > nowlines.tmp \
		; if [[ ! -f $$expfile ]] ; then read -p "\n» no expectation on file for $(3) $(4) $$filename, create .exp file now? " -n 1 -r ; echo ; if [[ $$REPLY =~ ^[Yy]$$ ]] ; then \
				mv $$testfile $$expfile ;  $(call count,update) \
			; fi \
			; continue \
		; fi \
		; echo $$((`cat explines.tmp` + `cat $$expfile | wc -l`)) > explines.tmp \
		; cat $$expfile | LC_ALL=C sed -e "s/compiler:.*/compiler:    [...]/g" -e "s/grammar:.*/grammar:     [...]/g" -e "s/backend:.*/backend:     [...]/g" > unvers.exp \
		; cat $$testfile | LC_ALL=C sed -e "s/compiler:.*/compiler:    [...]/g" -e "s/grammar:.*/grammar:     [...]/g" -e "s/backend:.*/backend:     [...]/g" > unvers.tmp \
		; diff -B -d -y --suppress-common-lines unvers.exp unvers.tmp > diff.tmp \
		; dret=$$? \
		; if (( $$dret == 1 )) && [[ ! -f compmiss ]] ; then rm -f $$coktag ; fi \
		; if (( $$dret == 0 )) ; then printf "  √\n" >> test.log ; fi \
		; if (( $$dret == 1 )) ; then printf "  #  failed\n" >> test.log ; fi \
		; if (( $$dret == 2 )) ; then printf "  o  can't perform test\n" >> test.log ; fi \
		\
		; if [[ -f concise ]] ; then \
		      if (( $$dret == 0 )) ; then printf "+" ; $(call count,ok) ; fi \
		    ; if (( $$dret == 1 )) ; then printf "#" ; $(call count,err) ; if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; touch nopickup ; fi ; fi \
		    ; if (( $$dret == 2 )) ; then printf "o" ; $(call count,skip) ; fi \
		; else \
		      if (( $$dret == 0 )) && (( $$ret == 0 )) && (( $$failer == 0 )) ; then echo ok ; $(call count,ok) ; fi \
		    ; if (( $$dret == 0 )) && (( $$ret >  0 )) && (( $$failer >  0 )) ; then echo "ok (errors as expected)" ; $(call count,ok) ; fi \
		    ; if (( $$dret == 0 )) && (( $$ret >  0 )) && (( $$failer == 0 )) ; then echo "ok (unmarked error, but output as expected)" ; $(call count,warn) ; fi \
		    ; if (( $$dret == 0 )) && (( $$ret == 0 )) && (( $$failer >  0 )) ; then echo "ok (marked error, output as expected)" ; $(call count,ok) ; fi \
		    ; if (( $$dret == 2 )) ; then echo "can't perform test -> skip" ; $(call count,skip) ; fi \
		; fi ; \
		if [[ -f showdiff ]] ; then \
		    if (( $$dret == 1 )) ; then echo "failed: $(3) $(4) $$filename #< exp | got >#" ;  $(call count,err) ; $(call sep,#,132) ; cat diff.tmp ; $(call sep,#,132) ; \
		    fi ; \
		fi ; \
		if [[ -f compdiff ]] || [[ -f compall ]] ; then \
			if [[ ! -f $$coktag ]] || [[ -f compall ]] ; then \
			    if (( $$failer2 > 0 )) ; then \
				if [[ "$(4)" =~ .*javascript.* ]] || [[ "$(4)" =~ .*solidity.* ]] || [[ "$(4)" =~ .*sophia.* ]] ; then \
			    		rm -f $$coktag ; \
			        	if [[ -f concise ]] ; then printf "$(ok) $(off)" ; \
					else printf "  $(ok)skipped expected error √$(off)\n" ; fi ; \
				fi ; \
			    else \
				if [[ "$(4)" =~ .*javascript.* ]] ; then \
					if [[ ! -f concise ]] ; then \
						printf "$(ok)» node instantiation of $$testfile .. $(dim)" ; \
					fi ; \
					node -e "contract = require('./$$testfile')" ; \
					s0ret=$$? ; \
					if [[ -f concise ]] ; then \
						if (( $$s0ret == 0 )) ; then printf "$(ok)+$(off)" ; \
						else printf "$(err)#$(off)" ; fi ; \
					else \
						if (( $$s0ret == 0 )) ; then printf "  $(ok)ok √$(off)\n" ; \
						else printf "  $(err)failed #$(off)\n" ; fi ; \
					fi ; \
					if [[ ! -f concise ]] ; then \
						printf "$(ok)» linting of $$testfile .. $(dim)" ; \
					fi ; \
					npx eslint $$testfile ; \
					s1ret=$$? ; \
					if [[ -f concise ]] ; then \
						if (( $$s1ret == 0 )) ; then printf "$(ok)+ $(off)" ; \
						else printf "$(err)# $(off)" ; fi ; \
					else \
						if (( $$s1ret == 0 )) ; then printf "  $(ok)ok √$(off)\n" ; \
						else printf "  $(err)failed #$(off)\n" ; fi ; \
					fi ; \
					if (( $$s0ret == 0 )) && (( $$s1ret == 0 )) ; then touch $$coktag ; \
					else rm -f $$coktag ; fi ; \
				elif [[ "$(4)" =~ .*solidity.* ]] ; then \
					if [[ ! -f concise ]] ; then \
						printf "$(ok)» solidity compilation of $$testfile .. $(dim)" ; \
					fi ; \
					solcjs --bin $$testfile ; \
					sret=$$? ; \
					if [[ -f concise ]] ; then \
						if (( $$sret == 0 )) ; then printf "$(ok)+ $(off)" ; touch $$coktag ; fi ; \
						if (( $$sret == 1 )) ; then printf "$(err)# $(off)" ; rm -f $$coktag ; fi ; \
					else \
						if (( $$sret == 0 )) ; then printf "  $(ok)ok √$(off)\n" ; touch $$coktag ; fi ; \
						if (( $$sret == 1 )) ; then printf "  $(err)failed #$(off)\n" ; rm -f $$coktag ; fi ; \
					fi ; \
				elif [[ "$(4)" =~ .*sophia.* ]] ; then \
					if [[ ! -f concise ]] ; then \
						printf "$(ok)» sophia compilation of $$testfile .. $(dim)" ; \
					fi ; \
					aesophia_cli $$testfile > tmp ; \
					sret=$$? ; \
					if [[ -f concise ]] ; then \
						if (( $$sret == 0 )) ; then printf "$(ok)+ $(off)" ; touch $$coktag ; fi ; \
						if (( $$sret == 1 )) ; then printf "$(err)# $(off)" ; rm -f $$coktag ; fi ; \
					else \
						if (( $$sret == 0 )) ; then printf "  $(ok)ok √$(off)\n" ; touch $$coktag ; fi ; \
						if (( $$sret == 1 )) ; then printf "  $(err)failed #$(off)\n" ; rm -f $$coktag ; fi ; \
					fi ; \
				fi ; \
			    fi ; \
			fi ; \
		fi ; \
		if [[ -f autoupdate ]] ; then \
		    if (( $$dret == 1 )) ; then \
			mv $$expfile $$expfile.bak ; mv $$testfile $$expfile ; $(call count,update) ; $(call discount,err) \
	  		; printf "$(ok)› updated √$(off)\n\n" ; \
		    fi ; \
		elif (( $$dret == 1 )) && [[ ! -f noupdate ]] ; then \
		    while :; do echo; printf "$(hi) Update expectation file for $(3) $(4) $$filename? $(off)"; read -p "(U)pdate, (K)eep old, (I)gnore now, (Q)uit, (R)esult, (E)xpected, (S)ource, (P)recompile, (D)iff, (F)ull side-by-side diff, ignore (W)hitespace diff: " -n 1 -r ; echo \
				; if   [[ $$REPLY =~ ^[Uu]$$ ]] ; then echo "previous expectation backed up in $$expfile.bak (version tags are ignored)" \
					; mv $$expfile $$expfile.bak ; mv $$testfile $$expfile ;  $(call count,update) ; $(call discount,err) ; break \
				; elif [[ $$REPLY =~ ^[Rr]$$ ]] ; then echo "Result now ($$testfile -- version tags are ignored):" ; $(call sep,_,132) ; cat $$testfile ; $(call sep,_,132) \
				; elif [[ $$REPLY =~ ^[Ee]$$ ]] ; then echo "Expected result not gotten ($$expfile -- version tags are ignored):" ; $(call sep,:~,66) ; cat $$expfile ; $(call sep,:~,66) \
				; elif [[ $$REPLY =~ ^[Ss]$$ ]] ; then echo "Source code ($$filename):" ; $(call sep,=•,66) ; cat $$filename ; $(call sep,=•,66) \
				; elif [[ $$REPLY =~ ^[Pp]$$ ]] ; then echo "Precompiled source code ($$filename):" ; $(call sep,«»,66) ; $(3) $(4) -p $$filename ; $(call sep,«»,66) \
				; elif [[ $$REPLY =~ ^[Ff]$$ ]] ; then echo "Difference #< exp | got ># (version tags are ignored):" \
					; diff -B -y $$expfile $$testfile | sed -e "s/»/»  /g" | sed -e "s/.*|.*/`printf "\033[33m&\033[0m"`/" -e "s/.*<.*/`printf "\033[31m&\033[0m"`/" -e "s/.*>.*/`printf "\033[36m&\033[0m"`/" \
				; elif [[ $$REPLY =~ ^[Dd]$$ ]] ; then echo "Difference from expectation (version tags are ignored):" \
					; diff -B -u $$expfile $$testfile | sed -e "s/^-/`printf "\033[31m"`-/" -e "s/^+/`printf "\033[36m"`+/" -e "s/$$/`printf "\033[0m"`/" \
				; elif [[ $$REPLY =~ ^[Ww]$$ ]] ; then echo "Difference from expectation, ignoring whitespace (and version tags):" \
					; diff -w -b -B -u $$expfile $$testfile | sed -e "s/^-/`printf "\033[31m"`-/" -e "s/^+/`printf "\033[36m"`+/" -e "s/$$/`printf "\033[0m"`/" \
				; elif [[ $$REPLY =~ ^[Kk]$$ ]] ; then if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; touch nopickup ; fi ; break \
				; elif [[ $$REPLY =~ ^[Ii]$$ ]] ; then if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; touch nopickup ; fi ; touch noupdate ; break \
				; elif [[ $$REPLY =~ ^[Qq]$$ ]] ; then if [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; fi ; quit=1 ; break 2 \
				; fi \
		    ; done ; \
		elif [[ ! -f lastfail ]] ; then echo "$(3) $(4) $$filename" > lastfail ; touch nopickup ; \
		fi \
	    ; done \
	    ; echo \
	    ; echo $$testnumber > testnumber.tmp \
	    ; if (( $$quit == 1 )) ; then touch quit.tmp ; fi ; \
	fi
endef

define focustest
	cd focus ; \
	cat $(1) | sed "s/compiler:.*/compiler:    [...]/g" | sed "s/grammar:.*/grammar:     [...]/g" | sed "s/backend:.*/backend:     [...]/g" > unvers.exp ; \
	cat $(2) | sed "s/compiler:.*/compiler:    [...]/g" | sed "s/grammar:.*/grammar:     [...]/g" | sed "s/backend:.*/backend:     [...]/g" > unvers.now ; \
	$(DIFF) -wB unvers.exp unvers.now ; \
	$(errtag)
endef


define focuscomp
	cd focus ; \
	cat $(1) | sed "s/compiler:.*/compiler:    [...]/g" | sed "s/grammar:.*/grammar:     [...]/g" | sed "s/backend:.*/backend:     [...]/g" > unvers.exp ; \
	cat $(2) | sed "s/compiler:.*/compiler:    [...]/g" | sed "s/grammar:.*/grammar:     [...]/g" | sed "s/backend:.*/backend:     [...]/g" > unvers.now ; \
	$(DIFF) -wB unvers.exp unvers.now ; \
	$(errtag)
	cd focus ; \
	if [[ $(2) = *.jsx ]] ; then \
		printf "npx eslint $(2) > $(2).lint$(dim) .. " ; \
		npx eslint $(2) > $(2).lint ; \
		$(errtag) ; \
	fi ; \
	if [[ $(2) = *.sol ]] ; then \
		printf "solcjs --bin $(2) > $(2).bin$(dim) .. " ; \
		solcjs --bin $(2) > $(2).bin ; \
		$(errtag) ; \
	fi ; \
	if [[ $(2) = *.aes ]] ; then \
		printf "aesophia_cli $(2) > $(2).bin$(dim) .. " ; \
		aesophia_cli $(2) > $(2).bin ; \
		$(errtag) ; \
	fi ;
endef

define log
	printf "\n# %s %s\n\n" "$(1)" $(shell date "+%Y-%m-%d-%H-%M-%S") >> test.log
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
	rm -f *.bin
	rm -f *.lint
	rm -f *.bak
	rm -f *.test
	rm -f unvers.exp
	rm -f whitebox.c
	rm -f a.out
	rm -f test
	rm -f focus/*.jsx
	rm -f focus/*.sol
	rm -f focus/*.aes
	rm -f focus/*.lcc
	rm -f focus/*.now
	rm -f focus/*.bin
	rm -f focus/*.lint
	rm -f focus/unvers.exp
	rm -f onlynew
	rm -f perfect
	rm -f concise
	rm -f noupdate
	rm -f nopickup
	rm -f showdiff
	rm -f compdiff
	rm -f compmiss
	rm -f compall
	rm -f autoupdate
	rm -f autocomp
	rm -f lastfail

expclean: clean
	@printf "$(ok)» deleting regression test expectations and native compilation check mark$(off)\n"
	rm -f *.exp
	rm -f *.cok
	rm -f focus/*.exp
	rm -f focus/*.cok

deeptest:
	@$(call log,DEEP TEST)
	@echo
	@echo Run all deep tests with a single-character bar indicating successes
	@echo and failures and finale tally. No updates of expectations.
	@echo
	@touch concise
	@touch noupdate
	@touch nopickup
	@touch showdiff
	@rm -f compdiff
	@rm -f compmiss
	@rm -f compall
	@rm -f autoupdate
	@rm -f lastfail
	@$(MAKE) _test

comptest:
	@$(call log,DEEP TEST AND COMPILE CHANGED)
	@echo
	@echo Compile deep test results that differ from expectations with their
	@echo native compiler. Does not set new expectations but marks passed.
	@echo
	@touch concise
	@touch noupdate
	@touch nopickup
	@touch showdiff
	@touch compdiff
	@rm -f compmiss
	@rm -f compall
	@rm -f autoupdate
	@rm -f lastfail
	@$(MAKE) _test

compmiss:
	@$(call log,DEEP TEST AND COMPILE THOSE MISSING PASS)
	@echo
	@echo Compile all test results differing from expectations or not that
	@echo miss the pass mark with their native compiler. 
	@echo
	@touch concise
	@touch noupdate
	@touch nopickup
	@touch showdiff
	@touch compdiff
	@touch compmiss
	@rm -f compall
	@rm -f autoupdate
	@rm -f lastfail
	@$(MAKE) _test

update:
	@$(call log,INTERACTIVE UPDATE OF FAILING DEEP TESTS)
	@echo
	@echo Run all deep tests and interactively update expectations where
	@echo they do not match newest compilation results.
	@echo
	@rm -f concise
	@rm -f noupdate
	@touch nopickup
	@touch showdiff
	@rm -f compdiff
	@rm -f compmiss
	@rm -f compall
	@rm -f autoupdate
	@rm -f lastfail
	@$(MAKE) _test

compall:
	@$(call log,TEST-COMPILE ALL DEEP TESTS)
	@echo
	@echo Compile all deep test results with their native language compiler.
	@echo Does not set new expectations but marks which results passed.
	@echo
	@touch concise
	@touch noupdate
	@touch nopickup
	@rm -f showdiff
	@rm -f compdiff
	@rm -f compmiss
	@touch compall
	@rm -f autoupdate
	@rm -f lastfail
	@$(MAKE) _test

autoupdate:
	@$(call log,AUTO UPDATE OF FAILING DEEP TESTS)
	@echo
	@echo Update expectations of all deep tests that fail.
	@echo Compilation with the native compiler is not checked.
	@echo
	@rm -f concise
	@rm -f noupdate
	@touch nopickup
	@touch showdiff 
	@rm -f compdiff
	@rm -f compmiss
	@rm -f compall
	@touch autoupdate
	@rm -f lastfail
	@$(MAKE) _test

autocomp:
	@$(call log,AUTO UPDATE OF FAILING DEEP TESTS)
	@echo
	@echo Update expectations of all deep tests that fail.
	@echo Compile with native compiler and mark when passed.
	@echo
	@rm -f concise
	@rm -f noupdate
	@touch nopickup
	@touch showdiff 
	@touch compdiff
	@rm -f compmiss
	@rm -f compall
	@touch autoupdate
	@rm -f lastfail
	@$(MAKE) _test

recheck:
	@echo
	@echo Redo deep tests from where the last test run first failed.
	@echo Interactive updates of expectations like with 'update.' 
	@echo
	@if [[ ! -f lastfail ]] ; then \
	  echo "no failure in last test run" ; \
	else \
	  $(MAKE) _recheck ; \
	fi

_recheck:
	@$(call log,RECHECK FAILED TESTS)
	@rm -f concise
	@rm -f noupdate
	@rm -f nopickup
	@touch showdiff
	@rm -f compdiff
	@rm -f compall
	@rm -f autoupdate
	@$(MAKE) _test

_test_proto:
	@echo
	@printf "$(ok)» regression tests$(off)\n"
	@echo ===================
	@printf "\nexpectations from:\n"
	@cat tag.exp
	@rm -f *.tmp
	$(call init)
	@$(call testrun,coverage core,:,../bin/lexon,--core,:,ls -1 cover/*.lex,.lcc.exp,)
	@$(call testrun,coverage javascript,:,../bin/lexon,--javascript -x,:,ls -1 cover/*.lex,.jsx.exp,)
	@$(call testrun,coverage solidity,:,../bin/lexon,--solidity -x,:,ls -1 cover/*.lex,.solx.exp,)
	@$(call testrun,coverage javascript,:,../bin/lexon,--javascript -x,:,ls -1 cover/*.lex,.jsx.exp,)
	@$(call testrun,javascript barebone,:,../bin/lexon,--javascript -b,:,ls -1 lexon/*.lex,.jsb.exp,)
	@$(call testrun,javascript full-feature,:,../bin/lexon,--javascript -x,:,ls -1 lexon/*.lex,.jsx.exp,)
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
		printf "Processed %'.f lines of source, %'.f lines of output, %'.f lines of expectations, running %'.f tests vs %'.f+ files.\n" \
			`cat testlines.tmp` `cat nowlines.tmp` `cat explines.tmp` $$((`cat testnumber.tmp` - `cat skip.tmp`)) $$((`ls -1 *.lex | wc -w | sed 's/ //g'` + `ls -1 english/*.lex | wc -w | sed 's/ //g'` + `ls -1 lexon/*.lex | wc -w | sed 's/ //g'`)) ; \
		if (( $$err != 0 )) || (( $$warn != 0 )) ; then \
			echo ; \
			printf "Regarding failing tests, unless you changed the source code of Lexon itself, they should have worked.\n" ; \
			printf "➡︎ If you are developing, you can rebuild all expectations at once with 'make expectations'.\n" ; \
			if [[ -f noupdate ]] ; then printf "➡︎ Better yet, run 'make update' to update test expectations one by one and interactively. You will be able to list the source and outputs.\n" ; fi ; \
			if [[ -f lastfail ]] && [[ -f nopickup ]] ; then printf "➡︎ When developing, run 'make recheck' to skip tests before the first error. It otherwise works like 'make update'.\n" ; fi ; \
		fi ; \
	fi
	@echo



___test_proto2:
	@echo
	@printf "$(ok)» regression tests$(off)\n"
	@echo ===================
	@printf "\nexpectations from:\n"
	@cat tag.exp
	@rm -f *.tmp
	$(call init)
	@$(call testrun,coverage solidity,:,../bin/lexon,--solidity -x,:,ls -1 cover/*.lex,.solx.exp,)
	@$(call testrun,solidity barebone,:,../bin/lexon,--solidity -b,:,ls -1 lexon/*.lex,.solb.exp,)
	@$(call testrun,solidity full-feature,:,../bin/lexon,--solidity -x,:,ls -1 lexon/*.lex,.solx.exp,)
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
		printf "Processed %'.f lines of source, %'.f lines of output, %'.f lines of expectations, running %'.f tests vs %'.f+ files.\n" \
			`cat testlines.tmp` `cat nowlines.tmp` `cat explines.tmp` $$((`cat testnumber.tmp` - `cat skip.tmp`)) $$((`ls -1 *.lex | wc -w | sed 's/ //g'` + `ls -1 english/*.lex | wc -w | sed 's/ //g'` + `ls -1 lexon/*.lex | wc -w | sed 's/ //g'`)) ; \
		if (( $$err != 0 )) || (( $$warn != 0 )) ; then \
			echo ; \
			printf "Regarding failing tests, unless you changed the source code of Lexon itself, they should have worked.\n" ; \
			printf "➡︎ If you are developing, you can rebuild all expectations at once with 'make expectations'.\n" ; \
			if [[ -f noupdate ]] ; then printf "➡︎ Better yet, run 'make update' to update test expectations one by one and interactively. You will be able to list the source and outputs.\n" ; fi ; \
			if [[ -f lastfail ]] && [[ -f nopickup ]] ; then printf "➡︎ When developing, run 'make recheck' to skip tests before the first error. It otherwise works like 'make update'.\n" ; fi ; \
		fi ; \
	fi
	@echo


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
	@$(call testrun,coverage precompile,:,../bin/lexon,-P,:,ls -1 cover/*.lex,.pre.exp,)
	@$(call testrun,coverage core,:,../bin/lexon,--core,:,ls -1 cover/*.lex,.lcc.exp,)
	@$(call testrun,coverage javascript,:,../bin/lexon,--javascript -x,:,ls -1 cover/*.lex,.jsx.exp,)
	@$(call testrun,coverage solidity,:,../bin/lexon,--solidity -x,:,ls -1 cover/*.lex,.solx.exp,)
	@$(call testrun,coverage sophia,:,../bin/lexon,--sophia -x,:,ls -1 cover/*.lex,.sopx.exp,)
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
	@$(call testrun,english grammar parsing,:,../bin/lexon,-Dallow_double_names,:,ls -1 english/test-*.lex,.eng.exp,)
	@$(call testrun,core language,:,../bin/lexon,--core,:,ls -1 lexon/*.lex,.core.exp,)
	@$(call testrun,tree,:,../bin/lexon,--tree,:,ls -1 lexon/*.lex,.tree.exp,)
	@$(call testrun,flat tree,:,../bin/lexon,--flat --tree,:,ls -1 lexon/*.lex,.flat.exp,)
	@$(call testrun,javascript barebone,:,../bin/lexon,--javascript -b,:,ls -1 lexon/*.lex,.jsb.exp,)
	@$(call testrun,javascript full-feature,:,../bin/lexon,--javascript -x,:,ls -1 lexon/*.lex,.jsx.exp,)
	@$(call testrun,solidity barebone,:,../bin/lexon,--solidity -b,:,ls -1 lexon/*.lex,.solb.exp,)
	@$(call testrun,solidity full-feature,:,../bin/lexon,--solidity -x,:,ls -1 lexon/*.lex,.solx.exp,)
	@$(call testrun,sophia barebone,:,../bin/lexon,--sophia -b,:,ls -1 lexon/*.lex,.sopb.exp,)
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
		printf "Processed %'.f lines of source, %'.f lines of output, %'.f lines of expectations, running %'.f tests vs %'.f+ files.\n" \
			`cat testlines.tmp` `cat nowlines.tmp` `cat explines.tmp` $$((`cat testnumber.tmp` - `cat skip.tmp`)) $$((`ls -1 *.lex | wc -w | sed 's/ //g'` + `ls -1 english/*.lex | wc -w | sed 's/ //g'` + `ls -1 lexon/*.lex | wc -w | sed 's/ //g'`)) ; \
		if (( $$err != 0 )) || (( $$warn != 0 )) ; then \
			echo ; \
			printf "Regarding failing tests, unless you changed the source code of Lexon itself, they should have worked.\n" ; \
			printf "➡︎ If you are developing, you can rebuild all expectations at once with 'make expectations'.\n" ; \
			if [[ -f noupdate ]] ; then printf "➡︎ Better yet, run 'make update' to update test expectations one by one and interactively. You will be able to list the source and outputs.\n" ; fi ; \
			if [[ -f lastfail ]] && [[ -f nopickup ]] ; then printf "➡︎ When developing, run 'make recheck' to skip tests before the first error. It otherwise works like 'make update'.\n" ; fi ; \
		fi ; \
	fi
	@echo


_test_solidity:
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
	#@$(call testrun,coverage precompile,:,../bin/lexon,-P,:,ls -1 cover/*.lex,.pre.exp,)
	#@$(call testrun,coverage core,:,../bin/lexon,--core,:,ls -1 cover/*.lex,.lcc.exp,)
	#@$(call testrun,coverage javascript,:,../bin/lexon,--javascript -x,:,ls -1 cover/*.lex,.jsx.exp,)
	@$(call testrun,coverage solidity,:,../bin/lexon,--solidity -x,:,ls -1 cover/*.lex,.solx.exp,)
	#@$(call testrun,coverage sophia,:,../bin/lexon,--sophia -x,:,ls -1 cover/*.lex,.sopx.exp,)
	#@$(call testrun,memory,rm -f a.out,gcc,-include whitebox.c,./a.out,grep -l %MEM test-memory-*.c,.mem.exp,)
	#@$(call testrun,precompile,:,../bin/lexon,-P,:,grep -l %PRE $(files),.pre.exp,%PREERR)
	#@$(call testrun,gui generator info,:,../bin/lexon,-U,:,grep -l %GEN $(files),.gen.exp,%GENERR)
	#@$(call testrun,circular includes,:,../bin/lexon,-C -P,:,grep -l %PRE $(files),.cir.exp,%CIRERR)
	#@$(call testrun,repeat includes,:,../bin/lexon,-R -P,:,grep -l %PRE $(files),.rep.exp,%REPERR)
	#@$(call testrun,circular and repeat,:,../bin/lexon,-R -C -P,:,grep -l %PRE $(files),.car.exp,%CARERR)
	#@$(call testrun,jurisdictions list,:,../bin/lexon,-J,:,ls -1 test-hello-00.lex,.jur.exp,)
	#@$(call testrun,jurisdiction parsing,:,../bin/lexon,-P,:,grep -l %JUR test-*.lex,.jur.exp,)
	#@$(call testrun,lxf extension grammar production,:,../bin/lexon,,:,grep -l %LXF test-*.lex,.lxf.exp,%LXFERR)
	#@$(call testrun,lgf lexon grammar production,:,../bin/lexon,-B,:,ls -1 test-*.lgf,.lgf.exp,%LGFERR)
	#@$(call testrun,english grammar parsing,:,../bin/lexon,-Dallow_double_names,:,ls -1 english/test-*.lex,.eng.exp,)
	#@$(call testrun,core language,:,../bin/lexon,--core,:,ls -1 lexon/*.lex,.core.exp,)
	#@$(call testrun,tree,:,../bin/lexon,--tree,:,ls -1 lexon/*.lex,.tree.exp,)
	#@$(call testrun,flat tree,:,../bin/lexon,--flat --tree,:,ls -1 lexon/*.lex,.flat.exp,)
	#@$(call testrun,javascript barebone,:,../bin/lexon,--javascript -b,:,ls -1 lexon/*.lex,.jsb.exp,)
	#@$(call testrun,javascript full-feature,:,../bin/lexon,--javascript -x,:,ls -1 lexon/*.lex,.jsx.exp,)
	@$(call testrun,solidity barebone,:,../bin/lexon,--solidity -b,:,ls -1 lexon/*.lex,.solb.exp,)
	@$(call testrun,solidity full-feature,:,../bin/lexon,--solidity -x,:,ls -1 lexon/*.lex,.solx.exp,)
	#@$(call testrun,sophia barebone,:,../bin/lexon,--sophia -b,:,ls -1 lexon/*.lex,.sopb.exp,)
	#@$(call testrun,sophia full-feature,:,../bin/lexon,--sophia -x,:,ls -1 lexon/*.lex,.sopx.exp,)
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
		printf "Processed %'.f lines of source, %'.f lines of output, %'.f lines of expectations, running %'.f tests vs %'.f+ files.\n" \
			`cat testlines.tmp` `cat nowlines.tmp` `cat explines.tmp` $$((`cat testnumber.tmp` - `cat skip.tmp`)) $$((`ls -1 *.lex | wc -w | sed 's/ //g'` + `ls -1 english/*.lex | wc -w | sed 's/ //g'` + `ls -1 lexon/*.lex | wc -w | sed 's/ //g'`)) ; \
		if (( $$err != 0 )) || (( $$warn != 0 )) ; then \
			echo ; \
			printf "Regarding failing tests, unless you changed the source code of Lexon itself, they should have worked.\n" ; \
			printf "➡︎ If you are developing, you can rebuild all expectations at once with 'make expectations'.\n" ; \
			if [[ -f noupdate ]] ; then printf "➡︎ Better yet, run 'make update' to update test expectations one by one and interactively. You will be able to list the source and outputs.\n" ; fi ; \
			if [[ -f lastfail ]] && [[ -f nopickup ]] ; then printf "➡︎ When developing, run 'make recheck' to skip tests before the first error. It otherwise works like 'make update'.\n" ; fi ; \
		fi ; \
	fi
	@echo

_test_sophia:
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
	@$(call testrun,coverage sophia,:,../bin/lexon,--sophia -x,:,ls -1 cover/*.lex,.sopx.exp,)
	@$(call testrun,sophia barebone,:,../bin/lexon,--sophia -b,:,ls -1 lexon/*.lex,.sopb.exp,)
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
		printf "Processed %'.f lines of source, %'.f lines of output, %'.f lines of expectations, running %'.f tests vs %'.f+ files.\n" \
			`cat testlines.tmp` `cat nowlines.tmp` `cat explines.tmp` $$((`cat testnumber.tmp` - `cat skip.tmp`)) $$((`ls -1 *.lex | wc -w | sed 's/ //g'` + `ls -1 english/*.lex | wc -w | sed 's/ //g'` + `ls -1 lexon/*.lex | wc -w | sed 's/ //g'`)) ; \
		if (( $$err != 0 )) || (( $$warn != 0 )) ; then \
			echo ; \
			printf "Regarding failing tests, unless you changed the source code of Lexon itself, they should have worked.\n" ; \
			printf "➡︎ If you are developing, you can rebuild all expectations at once with 'make expectations'.\n" ; \
			if [[ -f noupdate ]] ; then printf "➡︎ Better yet, run 'make update' to update test expectations one by one and interactively. You will be able to list the source and outputs.\n" ; fi ; \
			if [[ -f lastfail ]] && [[ -f nopickup ]] ; then printf "➡︎ When developing, run 'make recheck' to skip tests before the first error. It otherwise works like 'make update'.\n" ; fi ; \
		fi ; \
	fi
	@echo

_test_javascript:
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
	@$(call testrun,coverage javascript,:,../bin/lexon,--javascript -x,:,ls -1 cover/*.lex,.jsx.exp,)
	@$(call testrun,javascript barebone,:,../bin/lexon,--javascript -b,:,ls -1 lexon/*.lex,.jsb.exp,)
	@$(call testrun,javascript full-feature,:,../bin/lexon,--javascript -x,:,ls -1 lexon/*.lex,.jsx.exp,)
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
		printf "Processed %'.f lines of source, %'.f lines of output, %'.f lines of expectations, running %'.f tests vs %'.f+ files.\n" \
			`cat testlines.tmp` `cat nowlines.tmp` `cat explines.tmp` $$((`cat testnumber.tmp` - `cat skip.tmp`)) $$((`ls -1 *.lex | wc -w | sed 's/ //g'` + `ls -1 english/*.lex | wc -w | sed 's/ //g'` + `ls -1 lexon/*.lex | wc -w | sed 's/ //g'`)) ; \
		if (( $$err != 0 )) || (( $$warn != 0 )) ; then \
			echo ; \
			printf "Regarding failing tests, unless you changed the source code of Lexon itself, they should have worked.\n" ; \
			printf "➡︎ If you are developing, you can rebuild all expectations at once with 'make expectations'.\n" ; \
			if [[ -f noupdate ]] ; then printf "➡︎ Better yet, run 'make update' to update test expectations one by one and interactively. You will be able to list the source and outputs.\n" ; fi ; \
			if [[ -f lastfail ]] && [[ -f nopickup ]] ; then printf "➡︎ When developing, run 'make recheck' to skip tests before the first error. It otherwise works like 'make update'.\n" ; fi ; \
		fi ; \
	fi
	@echo

%.try: %.lex
	../bin/lexon $*
	@echo $^ $@
	diff -w -B $^ $@
	if (( $? == 0 )) ; then echo ok ; fi
	if (( $? == 1 )) ; then echo not ; fi
	if (( $? == 2 )) ; then echo worse ; fi

new:
	@$(call log,CREATE MISSING EXPECTATIONS)
	@echo
	@echo Building missing expectation files that regression tests will compare against
	@echo This sets the current lexon build as benchmark for future tests.
	@echo
	@touch onlynew
	$(MAKE) _expects

expectations:
	@$(call log,REMAKE EXPECTATIONS)
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
	$(call buildexp,coverage precompile,:,../bin/lexon,-P,:,ls -1 cover/*.lex,.pre.exp,%PREERR)
	$(call buildexp,coverage core,:,../bin/lexon,--core,:,ls -1 cover/*.lex,.lcc.exp,%ERR)
	$(call buildexp,coverage javascript,:,../bin/lexon,--javascript -x,:,ls -1 cover/*.lex,.jsx.exp,%ERR)
	$(call buildexp,coverage solidity,:,../bin/lexon,--solidity -x,:,ls -1 cover/*.lex,.solx.exp,%ERR)
	$(call buildexp,coverage sophia,:,../bin/lexon,--sophia -x,:,ls -1 cover/*.lex,.sopx.exp,)
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
	$(call buildexp,javascript barebone,:,../bin/lexon,--javascript -b,:,ls -1 lexon/*.lex,.jsb.exp,)
	$(call buildexp,javascript full-feature,:,../bin/lexon,--javascript -x,:,ls -1 lexon/*.lex,.jsx.exp,)
	$(call buildexp,solidity barebone,:,../bin/lexon,--solidity -b,:,ls -1 lexon/*.lex,.solb.exp,)
	$(call buildexp,solidity full-feature,:,../bin/lexon,--solidity -x,:,ls -1 lexon/*.lex,.solx.exp,)
	$(call buildexp,sophia barebone,:,../bin/lexon,--sophia -b,:,ls -1 lexon/*.lex,.sopb.exp,)
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
	@if [[ -f onlynew ]] ; then echo "(valid for newest only)" >> tag.exp ; fi
	@cat tag.exp
	@echo

grammar_expectations:
	@$(call log,REMAKE GRAMMAR EXPECTATIONS)
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
	@if [[ -f onlynew ]] ; then echo "(valid for newest only)" >> tag.exp ; fi
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

focustest:
	@$(call log,FOCUS TEST)
	@printf "\n$(hi)▫️  focus test $(off)\n\n"
	@echo compiling and diffing of distribution-defining example texts.
	@echo

	@printf "$(ok)• escrow ⟶   core $(off)\n"
	-cd focus ; ../../bin/lexon --core escrow.lex > escrow.lcc
	-@$(call focustest,escrow.lcc.exp,escrow.lcc)

	@printf "$(ok)• escrow 2 ⟶   core $(off)\n"
	-cd focus ; ../../bin/lexon --core escrow2.lex > escrow2.lcc
	-@$(call focustest,escrow2.lcc.exp,escrow2.lcc)

	@printf "$(ok)• statement ⟶   core $(off)\n"
	-cd focus ; ../../bin/lexon --core statement.lex > statement.lcc
	-@$(call focustest,statement.lcc.exp,statement.lcc)

	@printf "$(ok)• evaluation ⟶   core $(off)\n"
	-cd focus ; ../../bin/lexon --core evaluation.lex > evaluation.lcc
	-@$(call focustest,evaluation.lcc.exp,evaluation.lcc)

	@printf "$(ok)• escrow ⟶   javascript / barebone $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --bare escrow.lex > escrow.bb.jsx
	-@$(call focustest,escrow.bb.jsx.exp,escrow.bb.jsx)

	@printf "$(ok)• escrow 2 ⟶   javascript / barebone $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --bare escrow2.lex > escrow2.bb.jsx
	-@$(call focustest,escrow2.bb.jsx.exp,escrow2.bb.jsx)

	@printf "$(ok)• statement ⟶   javascript / barebone $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --bare statement.lex > statement.bb.jsx
	-@$(call focustest,statement.bb.jsx.exp,statement.bb.jsx)

	@printf "$(ok)• evaluation ⟶   javascript / barebone $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --bare evaluation.lex > evaluation.bb.jsx
	-@$(call focustest,evaluation.bb.jsx.exp,evaluation.bb.jsx)

	@printf "$(ok)• escrow ⟶   javascript / multi aux $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow.lex > escrow.ma.jsx
	-@$(call focustest,escrow.ma.jsx.exp,escrow.ma.jsx)

	@printf "$(ok)• escrow 2 ⟶   / multi aux javascript $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow2.lex > escrow2.ma.jsx
	-@$(call focustest,escrow2.ma.jsx.exp,escrow2.ma.jsx)

	@printf "$(ok)• statement ⟶   javascript / multi aux $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment statement.lex > statement.ma.jsx
	-@$(call focustest,statement.ma.jsx.exp,statement.ma.jsx)

	@printf "$(ok)• evaluation ⟶   javascript / multi aux $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment evaluation.lex > evaluation.ma.jsx
	-@$(call focustest,evaluation.ma.jsx.exp,evaluation.ma.jsx)

	@printf "$(ok)• escrow ⟶   javascript / hardened $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --harden --comment escrow.lex > escrow.h.jsx
	-@$(call focustest,escrow.h.jsx.exp,escrow.h.jsx)

	@printf "$(ok)• escrow 2 ⟶   javascript / hardened $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --harden --comment escrow2.lex > escrow2.h.jsx
	-@$(call focustest,escrow2.h.jsx.exp,escrow2.h.jsx)

	@printf "$(ok)• statement ⟶   javascript / hardened $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --harden --comment statement.lex > statement.h.jsx
	-@$(call focustest,statement.h.jsx.exp,statement.h.jsx)

	@printf "$(ok)• evaluation ⟶   javascript / hardened $(off)\n"
	-cd focus ; ../../bin/lexon --javascript --harden --comment evaluation.lex > evaluation.h.jsx
	-@$(call focustest,evaluation.h.jsx.exp,evaluation.h.jsx)

	@printf "$(ok)• escrow ⟶   solidity $(off)\n"
	-cd focus ; ../../bin/lexon --solidity --comment escrow.lex > escrow.sol
	-@$(call focustest,escrow.sol.exp,escrow.sol)

	@printf "$(ok)• escrow 2 ⟶   solidity $(off)\n"
	-cd focus ; ../../bin/lexon --solidity --comment escrow2.lex > escrow2.sol
	-@$(call focustest,escrow2.sol.exp,escrow2.sol)

	@printf "$(ok)• statement ⟶   solidity $(off)\n"
	-cd focus ; ../../bin/lexon --solidity --comment statement.lex > statement.sol
	-@$(call focustest,statement.sol.exp,statement.sol)

	@printf "$(ok)• evaluation ⟶   solidity $(off)\n"
	-cd focus ; ../../bin/lexon --solidity --comment evaluation.lex > evaluation.sol
	-@$(call focustest,evaluation.sol.exp,evaluation.sol)

	@printf "$(ok)• escrow ⟶   solidity / hardened $(off)\n"
	-cd focus ; ../../bin/lexon --solidity --harden --comment escrow.lex > escrow.h.sol
	-@$(call focustest,escrow.h.sol.exp,escrow.h.sol)

	@printf "$(ok)• escrow 2 ⟶   solidity / hardened $(off)\n"
	-cd focus ; ../../bin/lexon --solidity --harden --comment escrow2.lex > escrow2.h.sol
	-@$(call focustest,escrow2.h.sol.exp,escrow2.h.sol)

	@printf "$(ok)• statement ⟶   solidity / hardened $(off)\n"
	-cd focus ; ../../bin/lexon --solidity --harden --comment statement.lex > statement.h.sol
	-@$(call focustest,statement.h.sol.exp,statement.h.sol)

	@printf "$(ok)• evaluation ⟶   solidity / hardened $(off)\n"
	-cd focus ; ../../bin/lexon --solidity --harden --comment evaluation.lex > evaluation.h.sol
	-@$(call focustest,evaluation.h.sol.exp,evaluation.h.sol)

	@printf "$(ok)• escrow ⟶   sophia $(off)\n"
	-cd focus ; ../../bin/lexon --sophia --comment escrow.lex > escrow.aes
	-@$(call focustest,escrow.aes.exp,escrow.aes)

	@printf "$(ok)• escrow 2 ⟶   sophia $(off)\n"
	-cd focus ; ../../bin/lexon --sophia --comment escrow2.lex > escrow2.aes
	-@$(call focustest,escrow2.aes.exp,escrow2.aes)

	@printf "$(ok)• statement ⟶   sophia $(off)\n"
	-cd focus ; ../../bin/lexon --sophia --comment statement.lex > statement.aes
	-@$(call focustest,statement.aes.exp,statement.aes)

	@printf "$(ok)• evaluation ⟶   sophia $(off)\n"
	-cd focus ; ../../bin/lexon --sophia --comment evaluation.lex > evaluation.aes
	-@$(call focustest,evaluation.aes.exp,evaluation.aes)

	@printf "$(ok)• statement / hardened ⟶   sophia $(off)\n"
	-cd focus ; ../../bin/lexon --sophia --comment --harden statement.lex > statement.h.aes
	-@$(call focustest,statement.h.aes.exp,statement.h.aes)

	@printf "$(ok)• evaluation / hardened ⟶   sophia $(off)\n"
	-cd focus ; ../../bin/lexon --sophia --comment --harden evaluation.lex > evaluation.h.aes
	-@$(call focustest,evaluation.h.aes.exp,evaluation.h.aes)

	@echo ---
	@printf "$(ok)done$(off)\n"
	@echo

focuscomp:
	@$(call log,FOCUS REGRESSION AND SYNTAX TEST)
	@printf "\n$(hi)▫️  focus regression and syntax test $(off)\n\n"
	@echo compiling and diffing of distribution-defining example texts.
	@echo Syntax check using node, eslint, solcjs, and aesophia_cli. 
	@echo

	@printf "$(ok)• escrow ⟶   core $(off)\n"
	@printf "/bin/lexon --core escrow.lex > escrow.lcc .. "
	-@cd focus ; ../../bin/lexon --core escrow.lex > escrow.lcc
	-@$(call focuscomp,escrow.lcc.exp,escrow.lcc)

	@printf "$(ok)• escrow 2 ⟶   core $(off)\n"
	@printf "/bin/lexon --core escrow2.lex > escrow2.lcc .. "
	-@cd focus ; ../../bin/lexon --core escrow2.lex > escrow2.lcc
	-@$(call focuscomp,escrow2.lcc.exp,escrow2.lcc)

	@printf "$(ok)• statement ⟶   core $(off)\n"
	@printf "/bin/lexon --core statement.lex > statement.lcc .. "
	-@cd focus ; ../../bin/lexon --core statement.lex > statement.lcc
	-@$(call focuscomp,statement.lcc.exp,statement.lcc)

	@printf "$(ok)• evaluation ⟶   core $(off)\n"
	@printf "/bin/lexon --core evaluation.lex > evaluation.lcc .. "
	-@cd focus ; ../../bin/lexon --core evaluation.lex > evaluation.lcc
	-@$(call focuscomp,evaluation.lcc.exp,evaluation.lcc)

	@printf "$(ok)• escrow ⟶   javascript / barebone $(off)\n"
	@printf "/bin/lexon --javascript -b escrow.lex > escrow.bb.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript -b escrow.lex > escrow.bb.jsx
	-@$(call focuscomp,escrow.bb.jsx.exp,escrow.bb.jsx)

	@printf "$(ok)• escrow 2 ⟶   javascript / barebone $(off)\n"
	@printf "/bin/lexon --javascript -b escrow2.lex > escrow2.bb.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript -b escrow2.lex > escrow2.bb.jsx
	-@$(call focuscomp,escrow2.bb.jsx.exp,escrow2.bb.jsx)

	@printf "$(ok)• statement ⟶   javascript / barebone $(off)\n"
	@printf "/bin/lexon --javascript -b statement.lex > statement.bb.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript -b statement.lex > statement.bb.jsx
	-@$(call focuscomp,statement.bb.jsx.exp,statement.bb.jsx)

	@printf "$(ok)• evaluation ⟶   javascript / barebone $(off)\n"
	@printf "/bin/lexon --javascript -b evaluation.lex > evaluation.bb.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript -b evaluation.lex > evaluation.bb.jsx
	-@$(call focuscomp,evaluation.bb.jsx.exp,evaluation.bb.jsx)

	@printf "$(ok)• escrow ⟶   javascript / multi aux $(off)\n"
	@printf "/bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow.lex > escrow.ma.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow.lex > escrow.ma.jsx
	-@$(call focuscomp,escrow.ma.jsx.exp,escrow.ma.jsx)

	@printf "$(ok)• escrow 2 ⟶   javascript / multi aux $(off)\n"
	@printf "/bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow2.lex > escrow2.ma.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow2.lex > escrow2.ma.jsx
	-@$(call focuscomp,escrow2.ma.jsx.exp,escrow2.ma.jsx)

	@printf "$(ok)• statement ⟶   javascript / multi aux $(off)\n"
	@printf "/bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment statement.lex > statement.ma.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment statement.lex > statement.ma.jsx
	-@$(call focuscomp,statement.ma.jsx.exp,statement.ma.jsx)

	@printf "$(ok)• evaluation ⟶   javascript / multi aux $(off)\n"
	@printf "/bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment evaluation.lex > evaluation.ma.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment evaluation.lex > evaluation.ma.jsx
	-@$(call focuscomp,evaluation.ma.jsx.exp,evaluation.ma.jsx)

	@printf "$(ok)• escrow ⟶   javascript / hardened $(off)\n"
	@printf "/bin/lexon --javascript --harden --comment escrow.lex > escrow.h.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript --harden --comment escrow.lex > escrow.h.jsx
	-@$(call focuscomp,escrow.h.jsx.exp,escrow.h.jsx)

	@printf "$(ok)• escrow 2 ⟶   javascript / hardened $(off)\n"
	@printf "/bin/lexon --javascript --harden --comment escrow2.lex > escrow2.h.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript --harden --comment escrow2.lex > escrow2.h.jsx
	-@$(call focuscomp,escrow2.h.jsx.exp,escrow2.h.jsx)

	@printf "$(ok)• statement ⟶   javascript / hardened $(off)\n"
	@printf "/bin/lexon --javascript --harden --comment statement.lex > statement.h.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript --harden --comment statement.lex > statement.h.jsx
	-@$(call focuscomp,statement.h.jsx.exp,statement.h.jsx)

	@printf "$(ok)• evaluation ⟶   javascript / hardened $(off)\n"
	@printf "/bin/lexon --javascript --harden --comment evaluation.lex > evaluation.h.jsx .. "
	-@cd focus ; ../../bin/lexon --javascript --harden --comment evaluation.lex > evaluation.h.jsx
	-@$(call focuscomp,evaluation.h.jsx.exp,evaluation.h.jsx)

	@printf "$(ok)• escrow ⟶   solidity $(off)\n"
	@printf "/bin/lexon --solidity --comment escrow.lex > escrow.sol .. "
	-@cd focus ; ../../bin/lexon --solidity --comment escrow.lex > escrow.sol
	-@$(call focuscomp,escrow.sol.exp,escrow.sol)

	@printf "$(ok)• escrow 2 ⟶   solidity $(off)\n"
	@printf "/bin/lexon --solidity --comment escrow2.lex > escrow2.sol .. "
	-@cd focus ; ../../bin/lexon --solidity --comment escrow2.lex > escrow2.sol
	-@$(call focuscomp,escrow2.sol.exp,escrow2.sol)

	@printf "$(ok)• statement ⟶   solidity $(off)\n"
	@printf "/bin/lexon --solidity --comment statement.lex > statement.sol .. "
	-@cd focus ; ../../bin/lexon --solidity --comment statement.lex > statement.sol
	-@$(call focuscomp,statement.sol.exp,statement.sol)

	@printf "$(ok)• evaluation ⟶   solidity $(off)\n"
	@printf "/bin/lexon --solidity --comment evaluation.lex > evaluation.sol .. "
	-@cd focus ; ../../bin/lexon --solidity --comment evaluation.lex > evaluation.sol
	-@$(call focuscomp,evaluation.sol.exp,evaluation.sol)

	@printf "$(ok)• escrow ⟶   solidity / hardened $(off)\n"
	@printf "/bin/lexon --solidity --harden --comment escrow.lex > escrow.h.sol .. "
	-@cd focus ; ../../bin/lexon --solidity --harden --comment escrow.lex > escrow.h.sol
	-@$(call focuscomp,escrow.h.sol.exp,escrow.h.sol)

	@printf "$(ok)• escrow 2 ⟶   solidity / hardened $(off)\n"
	@printf "/bin/lexon --solidity --harden --comment escrow2.lex > escrow2.h.sol .. "
	-@cd focus ; ../../bin/lexon --solidity --harden --comment escrow2.lex > escrow2.h.sol
	-@$(call focuscomp,escrow2.h.sol.exp,escrow2.h.sol)

	@printf "$(ok)• statement ⟶   solidity / hardened $(off)\n"
	@printf "/bin/lexon --solidity --harden --comment statement.lex > statement.h.sol .. "
	-@cd focus ; ../../bin/lexon --solidity --harden --comment statement.lex > statement.h.sol
	-@$(call focuscomp,statement.h.sol.exp,statement.h.sol)

	@printf "$(ok)• evaluation ⟶   solidity / hardened $(off)\n"
	@printf "/bin/lexon --solidity --harden --comment evaluation.lex > evaluation.h.sol .. "
	-@cd focus ; ../../bin/lexon --solidity --harden --comment evaluation.lex > evaluation.h.sol
	-@$(call focuscomp,evaluation.h.sol.exp,evaluation.h.sol)

	@printf "$(ok)• escrow ⟶   sophia $(off)\n"
	@printf "/bin/lexon --sophia --comment escrow.lex > escrow.aes .. "
	-@cd focus ; ../../bin/lexon --sophia --comment escrow.lex > escrow.aes
	-@$(call focuscomp,escrow.aes.exp,escrow.aes)

	@printf "$(ok)• escrow 2 ⟶   sophia $(off)\n"
	@printf "/bin/lexon --sophia --comment escrow2.lex > escrow2.aes .. "
	-@cd focus ; ../../bin/lexon --sophia --comment escrow2.lex > escrow2.aes
	-@$(call focuscomp,escrow2.aes.exp,escrow2.aes)

	@printf "$(ok)• statement ⟶   sophia $(off)\n"
	@printf "/bin/lexon --sophia --comment statement.lex > statement.aes .. "
	-@cd focus ; ../../bin/lexon --sophia --comment statement.lex > statement.aes
	-@$(call focuscomp,statement.aes.exp,statement.aes)

	@printf "$(ok)• evaluation ⟶   sophia $(off)\n"
	@printf "/bin/lexon --sophia --comment evaluation.lex > evaluation.aes .. "
	-@cd focus ; ../../bin/lexon --sophia --comment evaluation.lex > evaluation.aes
	-@$(call focuscomp,evaluation.aes.exp,evaluation.aes)

	@printf "$(ok)• statement ⟶   sophia / hardened $(off)\n"
	@printf "/bin/lexon --sophia --comment --harden statement.lex > statement.h.aes .. "
	-@cd focus ; ../../bin/lexon --sophia --comment --harden statement.lex > statement.h.aes
	-@$(call focuscomp,statement.h.aes.exp,statement.h.aes)

	@printf "$(ok)• evaluation ⟶   sophia / hardened $(off)\n"
	@printf "/bin/lexon --sophia --comment --harden evaluation.lex > evaluation.h.aes .. "
	-@cd focus ; ../../bin/lexon --sophia --comment --harden evaluation.lex > evaluation.h.aes
	-@$(call focuscomp,evaluation.h.aes.exp,evaluation.h.aes)

	@echo ---
	@printf "$(ok)done$(off)\n"
	@echo

focusprep:
	@$(call log,CREATE FOCUS TEST EXPECTATIONS)
	@printf "\n\n$(hi)▫️  preparation of expectations for focustest. $(off)\n\n"

	@echo »»» escrow core
	cd focus ; ../../bin/lexon --core escrow.lex > escrow.lcc.exp

	@echo »»» escrow 2 core
	cd focus ; ../../bin/lexon --core escrow2.lex > escrow2.lcc.exp

	@echo »»» statement core
	cd focus ; ../../bin/lexon --core statement.lex > statement.lcc.exp

	@echo »»» evaluation core
	cd focus ; ../../bin/lexon --core evaluation.lex > evaluation.lcc.exp

	@echo »»» escrow javascript / barebone
	cd focus ; ../../bin/lexon --javascript --bare escrow.lex > escrow.bb.jsx.exp

	@echo »»» escrow 2 javascript / barebone
	cd focus ; ../../bin/lexon --javascript --bare escrow2.lex > escrow2.bb.jsx.exp

	@echo »»» statement javascript / barebone
	cd focus ; ../../bin/lexon --javascript --bare statement.lex > statement.bb.jsx.exp

	@echo »»» evaluation javascript / barebone
	cd focus ; ../../bin/lexon --javascript --bare evaluation.lex > evaluation.bb.jsx.exp

	@echo »»» escrow javascript / multi aux
	cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow.lex > escrow.ma.jsx.exp

	@echo »»» escrow 2 javascript / multi aux
	cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment escrow2.lex > escrow2.ma.jsx.exp

	@echo »»» statement javascript / multi aux
	cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment statement.lex > statement.ma.jsx.exp

	@echo »»» evaluation javascript / multi aux
	cd focus ; ../../bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment evaluation.lex > evaluation.ma.jsx.exp

	@echo »»» escrow javascript / hardenend
	cd focus ; ../../bin/lexon --javascript --harden --comment escrow.lex > escrow.h.jsx.exp

	@echo »»» escrow 2 javascript / hardenend
	cd focus ; ../../bin/lexon --javascript --harden --comment escrow2.lex > escrow2.h.jsx.exp

	@echo »»» statement javascript / hardenend
	cd focus ; ../../bin/lexon --javascript --harden --comment statement.lex > statement.h.jsx.exp

	@echo »»» evaluation javascript / hardenend
	cd focus ; ../../bin/lexon --javascript --harden --comment evaluation.lex > evaluation.h.jsx.exp

	@echo »»» escrow solidity
	cd focus ; ../../bin/lexon --solidity --comment escrow.lex > escrow.sol.exp

	@echo »»» escrow 2 solidity
	cd focus ; ../../bin/lexon --solidity --comment escrow2.lex > escrow2.sol.exp

	@echo »»» statement solidity
	cd focus ; ../../bin/lexon --solidity --comment statement.lex > statement.sol.exp

	@echo »»» evaluation solidity
	cd focus ; ../../bin/lexon --solidity --comment evaluation.lex > evaluation.sol.exp

	@echo »»» escrow solidity / hardened
	cd focus ; ../../bin/lexon --solidity --harden --comment escrow.lex > escrow.h.sol.exp

	@echo »»» escrow 2 solidity / hardened
	cd focus ; ../../bin/lexon --solidity --harden --comment escrow2.lex > escrow2.h.sol.exp

	@echo »»» statement solidity / hardened
	cd focus ; ../../bin/lexon --solidity --harden --comment statement.lex > statement.h.sol.exp

	@echo »»» evaluation solidity / hardened
	cd focus ; ../../bin/lexon --solidity --harden --comment evaluation.lex > evaluation.h.sol.exp

	@echo »»» escrow sophia
	cd focus ; ../../bin/lexon --sophia --comment escrow.lex > escrow.aes.exp

	@echo »»» escrow 2 sophia
	cd focus ; ../../bin/lexon --sophia --comment escrow2.lex > escrow2.aes.exp

	@echo »»» statement sophia
	cd focus ; ../../bin/lexon --sophia --comment statement.lex > statement.aes.exp

	@echo »»» evaluation sophia
	cd focus ; ../../bin/lexon --sophia --comment evaluation.lex > evaluation.aes.exp

	@echo »»» statement sophia / hardened
	cd focus ; ../../bin/lexon --sophia --comment --harden statement.lex > statement.h.aes.exp

	@echo »»» evaluation sophia / hardened
	cd focus ; ../../bin/lexon --sophia --comment --harden evaluation.lex > evaluation.h.aes.exp

	@echo ---
	@echo done
	@echo

testlog:
	@printf "\nLast 100 lines of test.log:\n\n"
	@tail -n100 test.log
	@ls -alth test.log

cleanlog:
	rm -f test.log

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
	@printf "\n$(hi)▫️  LEXON COVERAGE TESTS $(off)\n"
	@awk 'FNR==1 {print "\n$(hi)» ", FILENAME, "$(off)\n"}{print}' cover/*.lex

.PHONY: all one clean expclean deeptest comptest compmiss update autoupdate autocomp recheck _recheck _test new expectations compall _expects grammar_expectations grammar_expects focustest focusprep focuscomp testlog list_expectations list_sources 
