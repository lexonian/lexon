# Lexon Compiler 0.3

	0.3 alpha 93 U, grammar 0.2.20 / subset 0.3.8 alpha 79 - English / Reyes

This is for developing the Lexon grammar and compiler, not for writing or reading
Lexon texts.

Lexon is a human-readable programming language that can be understood without
any prior knowledge about programming. It has been used to express statute,
contracts, smart contracts and workflows to make them both human-readable and
executable by a computer.

This compiler that can translate such texts written in controlled natural-
language into other programming languages: Solidity, Javascript, Sophia and a
Lexon-specific 'core' syntax.

For more on Lexon see https://lexon.org/about.html. The Lexon site has articles,
[books](https://lexon.org/books.html) and [papers](https://lexon.org/papers.html)
about Lexon, its application and background.

A comprehensive intro to the concept is the [Lexon book](https://lexon.org/books.html#book).

A paper by a legal scholar introducing Lexon is
[Creating Cryptolaw for the Uniform Commercial Code](https://lexon.org/papers.html#reyes)
by asst. prof. Carla L. Reyes.

Examples for Lexon texts are in the `examples/` folder. They can be explored
wired into the online word list at https://lexon.org/vocabulary.html#examples.

Note that neither for reading nor writing Lexon this word list has to be memorized.

This grammar release is nicknamed 'Reyes' in honor of asst. prof. of law
Carla L. Reyes' contribution and support.


## Writing Lexon

Lexon texts are *readable* without any preparation or familiarity with programming.
Lexon thus includes non-programmers into the discussion of programs, most notable
lawyers and judges to understand the meaning of a smart contract, for example,
a fintech instrument.

To *write* Lexon, you don't need to install this program but can use the online
compiler at https://www.lexon.org/compiler.html.

To use Lexon on your own machine—e.g., to create your own workflows and be
protected from bitrot—you don't have to build it yourself but can use the
binaries for Mac or Linux that are located in the bin/ folder of this project.
You can also download the binaries from https://www.lexon.org/download.html.
That page also has a step-by-step installation instruction. But note that this
compiler is used from the command-line of a terminal. The online compiler
does not require any installation or knowledge of the terminal.

The following is for developers who would like to take part in developing the
Lexon language and this compiler.

The compiler is an alpha version (0.3) that demonstrates the fundamental
functionality: implementing a relevant part of natural language grammar
so that it can be executed like a program. The parsing approach [(GLR)][1]
was pioneered by Bernard Lang and Masaru Tomitai. Lexon adds the
execution to realize the vision of 'programming with words' as envisioned,
i.a., by Mersenne, Descartes and Leibniz. For more on the philosophy of Lexon,
see https://www.lexon.org/books.html#characteristica.



## Quick Start

	git clone https://github.com/lexonian/lexon.git
	cd lexon ; make ; make install
	lexon --solidity examples/escrow.lex

On Mac, use

	sudo make install


## Pre-Builds

The repo is primed for ease of use and code browsing: there are pre-built
binaries in bin/ (`lexon_mac` and `lexon_linux`) and pre-generated sources in
build/.

The standard build is the second half of cycle 2, starting from all generated
C sources and uses only gcc. Builds from cycle 1 can be made after using
`clean`. This requires Flex and Bison. It is tested on Linux and Mac.


## Stack

The Lexon compiler 0.3 is written in C using GNU Flex and Bison.
It leverages Bison's [GLR][1] (generalized left-to-right rightmost derivation)
parser to process the temporary ambiguities of natural languge.

The compiler uses no libraries beyond the C standard library and Bison's
and has a small footprint that makes it well-suited to run in the web browser
and blockchain VMs in a WASM build.

Lexon introduces a variation of the Bachus-Naur Form (BNF) called the
Lexon Grammar Form (LGF) as demonstrated in grammar/english.lgf. LGF
is compiled to BNF for use with Bison.

The reason for using BNF instead of RE-type grammar definitions is the
greater versatility of BNF, and Bison's GLR is more powerful for human
language parsing than PEG or ALL(*) as it was made to deal with temporary
ambiguities as found in natural language grammar. Tools for language
development have developed into the direction of speed and programmer
productivity based on what has emerged as common denominator of modern
programming languages. Lexon breaks with these standards in multiple ways.
Its philospphy is based on the idea to use BNF on natural language, which is
where BNF is said to have come from: the linguistics department at MIT.



## Prerequisites Standard Build

* gcc
* make

Alternatively, there is an online compiler at
https://www.lexon.org/compiler.html.

Or, use the binaries `lexon_mac` or `lexon_linux` in `bin/`
to skip building. Rename one of them to `lexon` and run `make install`.

You can also download them at https://www.lexon.org/download.html.

To avoid **make**, use:

        cd build ; gcc -o ../bin/lexon scanner.c parser.c core.c javascript.c solidity.c sophia.c ; cd ..
	bin/lexon --solidity examples/escrow.lex



## Prerequisites Deep Build

To build from cycle 1, generating all source and using the compiler compilers:

* Mac or Linux
* C
* Flex
* Bison
* make


**Optional Formatting**

To indent generated intermediary C code during build:

* gindent

To color diffs of failing tests during check:

* colordiff



## Prerequisite for running created javascript contracts

* node


#### For persistence and emailing from created javascript contracts

* npm
* serialize-javascript

	npm install serialize-javascript



## Files

	README          this file
	LICENSE         License conditions and agreement
	grammar         Natural language grammar
	examples        Lexon example contracts
	bin             pre-built binaries and built binaries
	src             C and Flex compiler sources / cycle 1
	build           intermediary C sources / cycle 2
	Makefile        build script
	tests           compiler self-tests
	CREDITS         contributers and supporters


## Building

	$ make
	$ make install

On Mac use

	$ sudo make install

As the repo comes, make will compile the pre-built sources using gcc, building
the compiler `lexon`.

The deep build from cycle 1 first builds the compiler compiler `lexccc`, which
then builds the compiler `lexon`.


## Tests

	$ make check

This runs tests located in `tests/`. The tests verify that the compiler works
as expected.



## Build Rules

	$ make <rules>

	all             clean, build and run an example
	build           build compiler
	lexcc           [a build part] build lexon compiler compiler compiler
	lexon           [a build part] build lexon compiler
	sample          build escrow example to javascript
	check           compilation tests: deeptest, focustest, sample
	devcheck        all tests: envtest, deeptest, grammarcheck, focustest, sample
	clean           delete all built files
	distclean       clean and create backend modules
	ls              show the source and build directories
	license         show the license agreement
	help            this rules list

**3rd level of tests: grammar**

	grammarcheck    grammar checks with extended yacc grammar checks
	conflicts       grammar check that lists ambiguously used tokens
	counter         grammar check that lists examples for ambiguous code
	focusprep       build result references for future focustest runs
	focustest       grammar check compiling release-defining examples

**2nd level of tests: components**

	deeptest        memory handling, includes, language parser, compiler
	update          interactive, selective update of deeptest result references
	recheck         faster update, skipping successful tests of earlier deeptest
	expectations    full non-interactive update of deeptest result references
	new             creation of missing deeptest result references

**1st level of tests: build environment**

	envtest         test of build environment, gcc, flex, mtrac memory checks



## Use

	$ bin/lexon --solidity examples/escrow.lex

This, as an example, compiles the file `escrow.lex`.


### Examples

**Compile the U.C.C. Finance Statement example to Javascript**

        bin/lexon --javascript --feedback --log --chaining --signatures --persistence --comment examples/statement.lex

**Compile the Evaluation License example to Solidity**

        bin/lexon --solidity --comment examples/evaluation.lex

**Compile the escrow example to Lexon Core**

        bin/lexon --core examples/escrow.lex

**Draw a tree representation (AST) of escrow example**

        bin/lexon --flat --tree examples/escrow.lex


### Compiler Parameters

	usage: lexon [options] [<source file>]

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

**Examples**

	lexon sample.lex
	lexon --javascript sample.lex
	lexon -vQ sample.lex
	lexon -P sample.lex
	lexon --flat --color --tree sample.lex
	lexon -B english.lgf
	lexon -Yparser.y -Hparser.h -Sscanner.l -Flexon.l -Lcore english.lgf


## Syntax Highlighting

To help visually telling apart the targets in src/target.c use this additional syntax highlighting in your `~/.vimrc`:

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



## License

Copyright (C) 2016-24 Henning Diedrich. Licensed under AGPL3 subject to
the conditions described in the file LICENSE.

hd@lexon.org



## Repo

https://github.com/lexonian/lexon



[1]: https://en.wikipedia.org/wiki/GLR_parser

