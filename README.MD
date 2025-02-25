# Lexon Compiler 0.3

	0.3 beta 1, grammar 0.2.20 / subset 0.3.9 beta 1 - English / Reyes

**This is about developing the Lexon grammar and compiler, not about
writing or reading Lexon texts.**



## Quick Start



	git clone https://github.com/lexonian/lexon.git
	cd lexon ; make && sudo make install
	lexon --solidity examples/escrow.lex

Also see **Install Pre-built Binaries**, below.


## Introduction

[Lexon](https://lexon.org) is a human-readable programming language that can be
read without any prior knowledge about programming. It has been used to express
[statute](examples/statement.lex), [contracts](examples/evaluation.lex), [smart
contracts](examples/escrow.lex) and workflows to make them at the same time
human-readable and executable by a computer.

This compiler can translate such texts written in
controlled natural-language into other programming languages:
[Solidity](tests/escrow.0.solb.exp), [Javascript](tests/escrow.0.jsx.exp),
[Sophia](tests/escrow.0.sopx.exp) and a Lexon-specific
[Core](tests/escrow.0.core.exp) syntax. It can render a
[visual](tests/escrow.0.flat.exp) representation of the internal abstract
syntax tree (AST) that expresses the meaning of a text.

There is a [hosted](https://lexon.org/compiler.html) version of the compiler
available, a [manual](https://lexon.org/docs/Lexon%20Manual%200.3.pdf) and a
[tutorial](https://lexon.org/docs/Lexon%20Tutorial%200.3.pdf) that focus on
writing Lexon texts.

This compiler version 0.3 demonstrates Lexon's fundamental functionality,
implementing a relevant part of natural language grammar so that it can be
executed like a program. The parsing approach [(GLR)][1] was pioneered by
Bernard Lang and Masaru Tomitai. Lexon adds the execution to realize the vision
of 'programming with words' as envisioned, i.a., by Marin Mersenne, Gottfried
Leibniz, or Betrand Russel. For more on the origin and philosophy of Lexon, see
[Characteristica Universalis](https://lexon.org/books.html#characteristica).
Other languages with similar aims are discussed in the Lexon books (see below).

The Lexon [grammar](grammar/english.lgf) defines a 'controlled English,' a
subset of English grammar that is sufficient for expressing programs in a most
accessible way. It establishes one possibility to articulate grammatically
unambiguous texts, which turns out to be relevant to achieve computability,
instead of the creation of an unambiguous lexicon (cf.
[Characteristica](https://lexon.org/books.html#characteristica)).

This grammar release is nicknamed 'Reyes' in honor of asst. prof. of law Carla
L. Reyes' contribution and support. The file [CREDITS](CREDITS) lists more
contributors and supporters. Input that shaped the grammar came from about one
hundred developers, lawyers, scholars, finance, governance, and business
people.

For more on Lexon see this [introduction](https://lexon.org/about.html), and
its [misson statement](https://lexon.org/mission.html). The Lexon
[site](https://lexon.org) has [articles](https://lexon.org/deep-dive.html),
[books](https://lexon.org/books.html) and
[papers](https://lexon.org/papers.html) about Lexon, its application and
background.

A comprehensive intro is the [Lexon book](https://lexon.org/books.html#book). A
more playful and in-depth version of the book is the Lexon
[BIBLE](https://lexon.org/books.html#bible).

In her paper [Creating Cryptolaw for the Uniform Commercial
Code](https://lexon.org/papers.html#reyes), prof. Reyes, as a director of the
U.S. trade law reform commission and leading scholar in crypto, describes how
and why to use Lexon to write trade law. Prof. Clack of the University
College London [compares Lexon](https://lexon.org/papers.html#clack) to other
approaches in Computational Law.

Examples of Lexon texts are in the [`examples/`](examples/) folder. They can
also be explored crosslinked, word for word, at the online
[vocabulary](https://lexon.org/vocabulary.html#examples).  Note that it is not
required——neither for reading nor writing Lexon——to memorize this word list.
Just like programmers do not memorize references, nor lawyers memorize the
lexicon of legalese.  All the while, by necessity, Lexon is more accessible
than legalese or programming languages.

The compiler is licensed to you under the conditions and terms explained in the
file [`LICENSE`](LICENSE).




## Writing Lexon

Lexon texts are **readable** without any preparation or familiarity with
programming.  Lexon thus includes non-programmers into the discussion of
programs——notably also lawyers and judges——to understand the meaning of a smart
contract, for example a fintech instrument.

There are no requirements for reading Lexon, which is its primary use case.

To **write** Lexon, you also don't need to install this program but can use the
[online compiler](https://www.lexon.org/compiler.html) instead.

**To learn to write, read the examples provided by the online compiler (click
the `example` button repeatedly), then briefly explore the online
[vocabulary](https://lexon.org/vocabulary.html), before using the
[manual](https://lexon.org/docs/Lexon%20Manual%200.3.pdf) or the
[tutorial](https://lexon.org/docs/Lexon%20Tutorial%200.3.pdf) for a structured
introduction. They are all linked from the online compiler.**

However, note that most anything in this repository, including the downloaded
binaries, is to be used from the command-line of a terminal. (The online
compiler does not require any installation or knowledge of the terminal.)

The following, accordingly, is not about writing nor reading Lexon but **for
developers who would like to take part in developing the Lexon language and the
Lexon compiler.**



# The Compiler

## Online Documentation


* [ Manual     ]( https://lexon.org/docs/Lexon%20Manual%200.3.pdf )
* [ Tutorial   ]( https://lexon.org/docs/Lexon%20Tutorial%200.3.pdf )
* [ Vocabulary ]( https://lexon.org/vocabulary.html )
* [ Examples   ]( https://lexon.org/vocabulary.html#examples )
* [ Resources  ]( https://lexon.org/resources.html )
* [ Papers     ]( https://lexon.org/papers.html )
* [ Books      ]( https://lexon.org/books.html )
* [ Site       ]( https://lexon.org )




## Files and Folders


	README          this file
	LICENSE         License conditions and agreement
	grammar         Natural language grammar
	examples        Lexon example contracts
	bin             pre-built binaries and built binaries
	src             C and Flex compiler sources / cycle 1
	build           intermediary C sources / cycle 2
	Makefile        build scripts
	tests           compiler self-tests (*)
	CREDITS         contributors and supporters

(*) Note that github will omit relevant files and sub folders of the `tests/` directory.


## Stack

The Lexon compiler 0.3 is written in C using GNU Flex and Bison.  It leverages
Bison's [GLR][1] (generalized left-to-right rightmost derivation) parser to
process the temporary ambiguities of natural languge.

The compiler uses no libraries beyond the C standard library and Bison's
skeleton and has a small footprint that makes it well-suited to run in the web
browser and blockchain VMs in a WASM build.

To express its human-readable grammar, Lexon introduces a variation of the
Bachus-Naur Form (BNF) called the Lexon Grammar Form (LGF) as demonstrated in
[`grammar/english.lgf`](grammar/english.lgf#L26). LGF is compiled to BNF for
use with Bison as part of the build process (see use of `lexccc -Y` in the
Makefile, in essence, `bin/lexccc -Y grammar/english.lgf`).  The result can be
seen in file [`build/parser.y`](build/parser.y#L1056) from tag `%%`.

BNF and Bison are preferred over RE-based compiler building suits because BNF
is more versatile and Bison's GLR is more powerful for human language parsing
than PEG or ALL(*), as it can deal with the temporary ambiguities found in
natural language. Compiler tools have for obvious reasons prioritized
simplicity and compilation speed based on what emerged as common denominators
of modern programming languages; but in the process they confined the path of
language development to the status quo, basically, the 3rd generation language
syntax. It is considered obvious currently that a programming language should
not require the parser to look ahead to figure out the meaning of a token.
Lexon breaks with the de facto standards in multiple ways. Its philosphy is
based on the idea to use BNF to describe natural language, which connects with
BNF's purported origin, the 1950s linguistics department at MIT. In this, Lexon
merely acknowledges that the era of optimization for the needs of the machine
is over and programmer productivity has been firmly established as priority in
programming; for which the unintended consequenes of path dependency in
compiler building have to be addressed, and overcome.




## Compile Cycles

The Lexon compiler is created in two cycles: first, a lexon compiler compiler,
`lexccc` is built that in the second cycle creates BNF from the Lexon grammar
description `grammar/english.lgf` and produces all files that Flex and Bison
need as input to create the Lexon compiler. See files in `build/`.

The Lexon compiler is built and ready to go after the end of the 2nd cycle.
Any translation of a Lexon text——into other languages or to create a
tree——comes after this, aguably as the 3rd cycle.

The use of the code that the compiler created——the application——is yet another
separate program invocation, after the 3rd build cycle.

This depth is sometimes visible in the code where generated code is spliced
into code of the 1st cycle for the 2nd, or code is being created in the 1st
that will generate code that will generate code in the 3rd cycle, as part of
the actual compiler, e.g. the abstract syntax tree graphic.

This degree of nested generation is not unusual for compilers. Lexon has a
focus on supporting work on an incrementally evolving grammar that comes as a
stand-alone, human-readable file, not mixed with target code. It also creates
type-safe abstract syntax trees and template walk code for it (option `-T`).
This makes the 2nd cycle the language development work phase, where the actual
work happens, both in terms of iterating the grammar and adapting the code
generation to it; with changes to `lexccc` and its code base being rare in
comparison.




## Portability

Because of its low number of dependencies, the content of this repository
should remain usable for an extended amount of time, on a wide array of current
and future platforms.  It should be immediately portable to all 60 hardware
platforms that GCC supports, and with slight formal adaptions, beyond. In
essence it needs but a C99 compiler.

Because of its small footprint and fast pace, the compiler can be embedded in
web sites and run on smart phones. Compilation of medium size texts takes
milliseconds on a normal machine, with virtually no overhead for start up and
wind down. The size of the compiler executable is roughly 1MB. Building the
compiler itself from source takes seconds. This makes all kinds of nimble edge
devices possible hosts.

To use Lexon on your own machine——to create your own workflows and be protected
from bitrot——you don't have to build it yourself but can use the binaries for
Mac or Linux that are located in the [`bin/`](bin/) folder of this repository's
master branch. You can also download the
[binaries](https://www.lexon.org/download.html) from the Lexon site. That page
also has step-by-step installation instructions.



## Pre-Built Sources

This repository's master branch is primed for ease of use and code browsing.
Besides the pre-built binaries in the [`bin/`](bin/) folder (`lexon_mac` and
`lexon_linux`) there are pre-generated sources in [`build/`](build/).

The standard build starting with these sources present is the second half of
Lexon's build **cycle 2**. Starting with C sources pre-generated, it needs only
a C compiler (gcc / clang) to build the Lexon compiler. Builds from **cycle 1**
can be made after `make clean`. This full building requires Flex and Bison.  It
is tested on Linux and Mac. The `dev` branch starts from this stage.




## Prerequisites for Standard Build

* C
* make

Build by

	$ make


#### Tested With

	gcc 7.5.0 / c99
	clang 12.0.5 / c99
	make 3.81 and 4.1


### Alternatives to Building


#### Pre-built Binaries

You can use the pre-built binaries `lexon_mac` or `lexon_linux` in
[`bin/`](bin/) to skip building. The following installs the pre-built binaries
from `bin/`. It also copies them over `bin/lexon`. (The latter is undone buy
running `make` again, which will build a new `bin/lexon` from source.)

	$ sudo make mac install

or

	$ sudo make linux install


#### Download Binaries

You can also [download](https://lexon.org/download.html) the binaries, or use
the [online](https://lexon.org/compiler.html) compiler.


### Alternative to `make`

If you want or need to avoid `make`, you can just compile:

        cd build ; gcc -o ../bin/lexon scanner.c parser.c core.c javascript.c solidity.c sophia.c ; cd ..

If you deleted the C sources in build/, e.g., using `make clean`, and don't
have Flex and Bison availabe, get the sources needed for cycle 2 back by `git
reset --hard` to be able to build again.


## Prerequisites for Complete Build

To build from **cycle 1**, i.e., generating all sources and using the compiler
compilers:

* Linux or Darwin (Mac)
* C
* Flex
* Bison
* make


#### Tested With

	gcc 7.5.0 / c99
	clang 12.0.5 / c99
	bison 3.8
	flex 2.5.35 and 2.6.4
	make 3.81 and 4.1


#### Optional

Building skips the following automatically when not installed:

**To check for memory leaks:**

* valgrind

There is a thorrough internal check for memory leaks, without valgrind, that
does not cover the interfacing to Bison and Flex. Valgrind does but may not
be availaible on all platforms.

**To indent generated intermediary C code during build from cycle 1:**

* gindent

**To color diffs of failing tests during check:**

* colordiff

**For syntax sanity tests:**

* node + npm modules listed below
* eslint
* solcjs
* aesophia_cli

These are needed for `make comp*` rules that test compiling/instantiating
of the created Javascript, Solidity, or Sophia code. This tests the syntax
of the Lexon compiler output.


## Prerequisites for Running Created Javascript Contracts

Lexon can create Solidity, Javascript or Sophia code. To run the Javascript you
will want to use:

* node


#### For Persistence and Emailing from Created Javascript Contracts

Depending on the options given to the compiler, Javascript code will be
generated with different additional features. For emailing a contract to
someone else, and for persisting its state on your computer, you will need:

* npm
* serialize-javascript
* prompt-sync
* tar
* nodemailer

Install these libraries with:

	npm install serialize-javascript
	npm install prompt-sync
	npm install tar
	npm install nodemailer

Note that NO Javascript elements are needed when compiling a Lexon text, no
matter to what language, even to Javascript. The above applies solely for
executing the produced Javascript at a later time.




## Building

	$ make

As the repo comes, on the master branch, it is ready for build **cycle 2**:
`make` will compile the pre-built C sources in `build/`, calling `gcc` to build
the compiler executable `lexon`. This is the most portable state of the
repository.

The full build from **cycle 1** first builds the compiler compiler `lexccc`,
which then builds the sources required to build the compiler `lexon` in cycle
2. The dev branch is set up for this full build and `make clean` prepares the
index for it on any branch. (The master branch is prepared with `make
distclean`.)




## Installation

	$ sudo make install

If you can't sudo, copy the file `bin/lexon` into your path or call it directly,
like in `bin/lexon --solidity examples/escrow.lex` while in the `lexon` folder.

To install to a different path than `/usr/local/bin` set `PREFIX`, or copy
`bin/lexon` to the path manually.




## Tests

	$ make check

This runs tests located in sub directories of [`tests/`](tests/).

All tests passing is sufficient verification that the compiler built as expected.

Note that github will not list all files and sub folders in `tests/`. Relevant
sub folders are [`tests/english`](tests/english), [`tests/lexon`](tests/lexon),
and [`tests/focus`](tests/focus). But there are also test files in `tests/`
itself that github will not show.

The tests of `make check` verify that the compiler works as expected. Other
tests, like `make envtest` check the environment and internal memory handling
mechanisms. `make devcheck` runs all tests, except the slow, extended syntax
checks. See below for all available rules.

Note again that this section is about testing the Lexon compiler when improving
it. It is not relevant for writing and testing Lexon texts.


### Testing While Developing

When implementing a new feature, an new example Lexon text that demonstrates it
should be placed into folder `tests/cover`. It will be picked up by all deep
and comp test rules. The naming convention is loosly base-version-description.
The name is used to call out the running test later.  For examples, see the
`tests/` folder. 

Running `make new` will provide the opportunity to automatically register the
expected results of compiling this new Lexon text to four targets: core,
Javascript, Solidity, and Sophia.

To get a first impression of the effect of your changes while coding, run `make
focustest`, which diffs the current results of the three main examples that are
also given in `examples\`, with expected outcomes. Different compiler options
(barebone, w/aux, hardenend) are tried for each target (js, solidity, sophia).
Running the tests takes about a second. To bulk-update the expectations, run
`make focusprep`. Obviously, this should be done only after close inspection of
the results of `focustest`. To make a syntax check for the result of each test
(failing or not, this is not optimized) use `make focuscomp`. This is useful
only if some `focustests` fail, and need to be updated with `focusprep`. It
retests all files and takes ca. 2 minutes.

To do the full regression test of 5000+ test compilations, run `make check`.
Like `focustest`, it diffs the results of compiling Lexon texts with
`bin/lexon` with expectations on file that came with the repo.  It takes about
3 minutes. After fixing errors in the Lexon compiler code, use `make recheck`
to skip tests that passed the previous run, and be afforded the opportunity to
interactively update expectations to the new compilation results, blessing
intended changes as reference for future test runs. To bulk-update all
expectations, run `make expectations`. This can be useful but loses a lot of
signal obviously. To bulk-update only failing expectations, `make autoupdate`.
Expectations are deleted by `make expclean`, not by running `make clean`.
Updating the expectations is as fast as the tests themselves.

#### Syntax Checks

In the case that many test results are expected to change, bulk-test the syntax
of new results with `make comptest`—which instantiates Javascript code, and
compiles Solidity and Sophia code—for syntax verification of exactly those
tests that fail the diff with expectations. That is, only the resulting code of
failing tests is test-compiled. The syntax tests can take hours.  The
expectations are not updated. This requires node, eslint, solcjs, and
aesophia_cli, and a handfull of node modules installed.

Later runs of `comptest` will skip compilation of those test results that had
passed successfully before, even if the diff with expectations (the actual
regression test) still fails in the case that you have not updated expectations
(yet). Note that catching regressions can be far more important than testing
syntax. To syntax-test all test results, use `compall`. Use `compmiss` to
compile only those that had not yet been done or had failed (that is, where
node, eslint, solcjs, or aesophia_cli gave errors, independently of whether the
expectations diff succeeded). To auto-update failing expectations and
test-compile exactly those updated, use `autocomp`. This is the opposite of
`comptest`.

#### Summary

In summary, do `make focustest` for sufficient orientation while developing.
Use `make check` for a more comprehensive assurance that nothing broke while
you were looking elsewhere.  Use `make comptest` to check the syntax of the
failing regression tests of `make check`. 


## Build Rules

	$ make <rules>

	all             build compiler and run an example (default)
	build           build compiler
	install         install compiler (run with sudo)
	mac install     install pre-built mac binary and copy it as bin/lexon
	linux install   install pre-built linux binary and copy it as bin/lexon
	sample          build escrow example to solidity
	check           compiler tests: focustest, deeptest
	devcheck        more tests: envtest, grammarcheck, memtest, focustest, deeptest
	testlog         dump the 100 last lines of the test log
	clean           delete all built files, except pre-built binaries
	ls              show the source and build directories
	license         show the license agreement
	help            this list

**dev support**

	lexcc           a build part: build lexccc compiler compiler
	lexon           a build part: build lexon compiler
	distclean       clean and pre-build cycle 2 sources for master branch
	diffclean       clean and pre-build backend modules (targets branch)
	devclean        clean and delete pre-build binaries (dev branch)
	srcclean        devclean and delete test expectations (sources branch)
	rulecheck       test of different repository clean state transitions

**3rd level of tests: grammar**

	grammarcheck    grammar checks with extended yacc grammar checks
	conflicts       grammar check that lists ambiguously used tokens
	counter         grammar check that lists examples for ambiguous code
	focustest       grammar check compiling release-defining examples
	focusprep       build result references for future focustest runs

**2nd level of tests: components, syntax**

	focuscomp       syntax check of focus tests by native compilation, linting*
	deeptest        memory handling, includes, language parser, compiler
	comptest        natively compile* the result of all failing deep tests
	compall         natively compile* all deep test results
	compmiss        natively compile* the deep test results that failed before
	memtest         valgrind & internal memory leak tests
	update          interactive update of failing deeptests's result references
	recheck         faster update, skipping successful tests of earlier deeptest
	autoupdate      automatic update of failing deeptests's result references
	expectations    full non-interactive update of all deeptest result references
	new             creation of missing deeptest result references

**1st level of tests: build environment**

	envtest         test of build environment, gcc, flex, mtrac memory checks


* the extended compilation tests use node, eslint, solcjs, and aesophia_cli.


## Use

	lexon [<options>] [<source>]

Options are described below. If the <source> file is not given, stdin is used.

	$ bin/lexon --solidity examples/escrow.lex

This, as an example, compiles the Lexon text in file `escrow.lex` to solidity.


### Examples

**Compile the U.C.C. Finance Statement example to Javascript**

        bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment examples/statement.lex

**Compile the Evaluation License example to Solidity**

        bin/lexon --solidity --comment examples/evaluation.lex

**Compile the escrow example to Lexon Core**

        bin/lexon --core examples/escrow.lex

**Draw a tree representation (AST) of the escrow example**

        bin/lexon --flat --tree examples/escrow.lex


### Compiler Options

	usage: lexon [<options>] [<source file>]

	-V --version                    print version slug and exit
	-h --help                       print this text and exit
	-m --manual                     print the readme text and exit
	-o --output <file name>         write result of source translation to <file name>, not stdout
	-j --echo-source                list the source code that will be processed
	-Q --no-result                  no output of resulting code to screen even absent <out file>

**Developing Lexon Code**

	-2 --javascript                 produce javascript output
	-3 --solidity                   produce solidity output
	-4 --sophia                     produce sophia output
	-v --verbose                    trace detailed compilation steps to find code errors
	-N --names                      list found names - ie. symbols - and exit
	-W --echo-precompile            show sanitized source code, with included files
	-P --precompile                 show sanitized source code, with included files, and exit
	-J --jurisdictions              list known jurisdictions and exit
	-b --bare                       generated code is barebones happy path demonstration\n\
	-y --comment                    generated code has explanatory comments\n\
	-u --instructions               generated code leads in with user instructions\n\
	-z --harden                     generated code checks for unset arguments and variables\n\
	-f --feedback                   javascript: generated code confirms calls on-screen\n\
	-l --log [<file>]               javascript: generated code logs state changes to <file> (default: log)\n\
	-s --signatures [<pem file>]    javascript: generated code signs log using <pem file> (default: key.pem)\n\
	-c --chaining [<hash length>]   javascript: generated code hash-chains log-entries (default length: 12)\n\
	-p --persistence [<file>]       javascript: generated code stores state in <file> (default: state)\n\
	-t --bundle [<file>]            javascript: generated code can tar code, log and state (default: contract.tgz)\n\
	-x --all-auxiliaries            generated code features all applicable extras (-y -u -z -f -l -s -c -p -t)\n\
	-i --include-path <path>        set a default path to look for include files
	-I --included-files             print cascade of included and sub-included files and exit
	-R --ignore-repeat-includes     ignore include files that are given repeatedly
	-C --ignore-circular-includes   ignore include files that effectively call themselves

**Inspecting Lexon Code**

	-G --grammar                    list the implemented grammar (LGF), and exit
	-1 --core                       produce lexon core code output
	-0 --tree                       produce abstract syntax tree output
	   --flat                       produce a tree with flattened binary lists
	   --color [<sgr,sgr..>]        ansi sgr codes for highlighting (default: 1), adds following four
	   --symbols [<sgr,sgr..>]      highlight the symbols in tree, core, or output code (default: 36)
	   --highlight [<word,word..>]  highlight specific nodes (default: clause,subject,object,if)
	   --leaves [<word,word..>]     highlight specific node leaves (default: type,combinator,illocutor)
	   --subleaves [<word,word..>]  highlight specific node sub leaves (default: predicate)

**Developing Lexon Grammars**

	-S --scanner [<out file>]       produce scanner code from an LGF grammar
	-F --source base [<file name>]  source file to be included into scanner code (-S)
	-H --header [<file name>]       prepend #include "<file name>" to scanner code (-S)
	-Y --parser [<out file>]        produce parser code, incl. BNF, from an LGF grammar
	-K --keywords                   list the keywords produced from an LGF grammar, and exit
	-B --bnf                        produce BNF from an LGF grammar (subset of -Y), and exit
	-y --comment                    include comments in grammar output (-S, -Y)
	-k --check                      check consistency and completeness of LGF grammar (equals -QE)
	-E --examples [<path stub>]     produce examples from <path stub>-nn.lex for an LGF grammar
	-n --max-examples [<cap>]       produce ca. <cap> number of examples (default: 1000)
	-w --wipe                       delete pre-existing example files <path stub>-*.lex for -E

**Developing Lexon Targets**

	-T --template [<out file>]      produce skeleton AST walk functions for an LGF grammar
	-L --language-prefix [<prefix>] prepend <prefix> to the functions of -T (default: 'core')

**Debugging Lexon**

	-d --debug                      detailed trace of processing steps to debug lexon itself
	-D --debug-modules [<modules>]  detailed trace of specific modules. Use -Dh to list modules
	-M --memory-check               run-time check and post-mortem of memory allocation and errors

**Further Examples**

	lexon sample.lex
	lexon --javascript sample.lex
	lexon -vQ sample.lex
	lexon -P sample.lex
	lexon --flat --color --tree sample.lex
	lexon -B english.lgf
	lexon -Yparser.y -Hparser.h -Sscanner.l -Flexon.l -Lcore english.lgf




## Syntax Highlighting

The file [`src/target.c`](src/target.c) combines code for three targets (Solidity, Sophia, and Javascript) to allow for a more productive implementation of grammar enhancements. 

To help visually telling apart the targets in the source of `src/target.c`, use this additional syntax highlighting in your `~/.vimrc`:

	:syntax on

	autocmd ColorScheme *
		\ syn match lexfrontT "\/\*T.*" contains=cFunction |
		\ syn match lexfrontJS "\/\*JS .*" contains=cString |
		\ syn match lexfrontSol "\/\*Sol.*" contains=cString |
		\ syn match lexfrontSop "\/\*Sop.*" contains=cString |
		\ syn match lexfrontSaS "\/\*S+S.*" contains=cString |
		\ syn match lexfrontJaS "\/\*J+S.*" contains=cString |
		\ hi lexfrontT ctermfg=110 guifg=#84a0c6 |
		\ hi lexfrontJS ctermfg=76 guifg=#5fd700 |
		\ hi lexfrontSol ctermfg=51 guifg=#00ffff |
		\ hi lexfrontSaS ctermfg=21 guifg=#0000ff |
		\ hi lexfrontJaS ctermfg=28 guifg=#008700 |
		\ hi lexfrontJxS ctermfg=94 guifg=#875f00 |
		\ hi lexfrontSop ctermfg=127 guifg=#af00afv

See [`src/target.c`](src/target.c) for more details.




## License

Copyright (C) 2016-25 Henning Diedrich.

Licensed under AGPL3 subject to the conditions described in the file
[LICENSE](LICENSE).

hd@lexon.org




## Repo

https://github.com/lexonian/lexon



[1]: https://en.wikipedia.org/wiki/GLR_parser

