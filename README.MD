# Lexon Compiler 0.3

	0.3 alpha 93 U, grammar 0.2.20 / subset 0.3.8 alpha 79 - English / Reyes

**This is about developing the Lexon grammar and compiler, not about
writing or reading Lexon texts.**



## Quick Start



	git clone https://github.com/lexonian/lexon.git
	cd lexon ; make && sudo make install
	lexon --solidity examples/escrow.lex




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
	tests           compiler self-tests*
	CREDITS         contributors and supporters

Note * that github will omit relevant files and sub folders of the `test/` directory.


## Stack

The Lexon compiler 0.3 is written in C using GNU Flex and Bison.  It leverages
Bison's [GLR][1] (generalized left-to-right rightmost derivation) parser to
process the temporary ambiguities of natural languge.

The compiler uses no libraries beyond the C standard library and Bison's
skeleton and has a small footprint that makes it well-suited to run in the web
browser and blockchain VMs in a WASM build.

To express its human-readable grammar, Lexon introduces a variation of the
Bachus-Naur Form (BNF) called the Lexon Grammar Form (LGF) as demonstrated in
[`grammar/english.lgf`](grammar/english.lgf#L26). LGF is compiled to BNF for use
with Bison as part of the build process. The result can be seen in file
[`build/parser.y`](build/parser.y#L1056) from tag `%%`.

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




## Portability

Because of its low number of dependencies, the content of this repository should
remain usable for an extended amount of time. In essence it
needs but a (slighlty tolerant) C99 compiler.

It should be immediately portable to all 60 hardware platforms that GCC
supports, and with slight formal adaptions, beyond.

Because of its small footprint and fast pace, it can be embedded in web sites
and run on smart phones. Compilation of medium size texts takes milliseconds,
with virtually no overhead for start up and wind down. The size of the compiler
executable is roughly 1MB.

To use Lexon on your own machine——to create your own workflows and be protected
from bitrot——you don't have to build it yourself but can use the binaries for
Mac or Linux that are located in the [`bin/`](bin/) folder of this repository's
master branch. You can also download the
[binaries](https://www.lexon.org/download.html) from the Lexon site. That page
also has a step-by-step installation instruction.




## Pre-Builds

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


#### Tested With

	gcc 7.5.0
	clang 12.0.5
	make 3.81 and 4.1


#### Alternatives to Building

You can use the binaries `lexon_mac` or `lexon_linux` in [`bin/`](bin/) to skip
building. Rename one of them to `lexon` and run `make install`.

You can also [download](https://lexon.org/download.html) the binaries, or use
the [online](https://lexon.org/compiler.html) compiler.


#### Alternative to `make`

If you want or need to avoid `make`, you can just run the compiler:

        cd build ; gcc -o ../bin/lexon scanner.c parser.c core.c javascript.c solidity.c sophia.c ; cd ..

If you deleted the C sources in build/, e.g., using `make clean`, refresh the repo
index.


## Prerequisites for Complete Build

To build from **cycle 1**, i.e., generating all sources and using the compiler
compilers:

* Linux or Darwin (Mac)
* C
* Flex
* Bison
* make


#### Tested With

	gcc 7.5.0
	clang 12.0.5
	bison 3.8
	flex 2.5.35 and 2.6.4
	make 3.81 and 4.1


#### Optional Formatting

Building skips the following automatically when not installed.

To indent generated intermediary C code during build from cycle 1:

* gindent

To color diffs of failing tests during check:

* colordiff




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

Install this library with:

	npm install serialize-javascript

Note that no Javascript elements are needed when compiling a Lexon text, no
matter to what language, even to Javascript. The above applies solely for
executing the produced Javascript.




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

Note that github will not list all files and sub folders in `tests/`. Relevant
sub folders are [`tests/english`](tests/english), [`tests/lexon`](tests/lexon),
and [`tests/focus`](tests/focus). But there are also test files in `tests/`
itself that github will not show.

The tests of `make check` verify that the compiler works as expected. Other
tests, like `make envtest` check the environment and internal memory handling
mechanisms. `make devcheck` runs all tests. See immediately below for all
options.




## Build Rules

	$ make <rules>

	all             build compiler and run an example
	build           build compiler
	install         install compiler
	lexcc           [a build part:] build lexccc compiler compiler
	lexon           [a build part:] build lexon compiler
	sample          build escrow example to solidity
	check           compiler tests: deeptest, focustest, sample
	devcheck        all tests: envtest, deeptest, grammarcheck, focustest, sample
	clean           delete all built files, except pre-built binaries
	distclean       clean and pre-build cycle 2 sources for master branch
	diffclean       clean and pre-build backend modules (targets branch)
	devclean        clean and delete pre-build binaries (dev branch)
	srcclean        devclean and delete test expectations (sources branch)
	ls              show the source and build directories
	license         show the license agreement
	help            this list

**3rd level of tests: grammar**

	grammarcheck    grammar checks with extended yacc grammar checks
	conflicts       grammar check that lists ambiguously used tokens
	counter         grammar check that lists examples for ambiguous code
	focustest       grammar check compiling release-defining examples
	focusprep       build result references for future focustest runs

**2nd level of tests: components**

	deeptest        memory handling, includes, language parser, compiler
	update          interactive, selective update of deeptest result references
	recheck         faster update, skipping successful tests of earlier deeptest
	expectations    full non-interactive update of deeptest result references
	new             creation only of missing deeptest result references

**1st level of tests: build environment**

	envtest         test of build environment, gcc, flex, mtrac memory checks




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
	-b --bare                       generated code is barebones happy path demonstration
	-y --comment                    generated code has explanatory comments
	-u --instructions               generated code leads in with user instructions
	-f --feedback                   generated code confirms calls on-screen
	-z --harden                     generated code checks for unset arguments and variables
	-l --log [<file>]               generated code logs state changes to <file> (default: log)
	-s --signatures [<pem file>]    generated code signs log using <pem file> (default: key.pem)
	-c --chaining [<hash length>]   generated code hash-chains log-entries (default length 12)
	-p --persistence [<file>]       generated code stores state in <file> (default: state)
	-t --bundle [<file>]            generated code can tar code, log and state (default: contract.tgz)
	-x --all-auxiliaries            generated code features all extras (equals -y -u -f -z -l -s -c -p -t)
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

Copyright (C) 2016-24 Henning Diedrich.  

Licensed under AGPL3 subject to the conditions described in the file
[LICENSE](LICENSE).

hd@lexon.org




## Repo

https://github.com/lexonian/lexon



[1]: https://en.wikipedia.org/wiki/GLR_parser

