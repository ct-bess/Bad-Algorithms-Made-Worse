# Back-Chaining Readme

This program takes a decision (query) and finds supporting facts. Though, don't use 
my program to solve life-changing problems; I can't guarentee the solution will be 
optimal.

## Compiling:

This program was developed on a machine running Ubuntu 16.04 (xenial) 
using g++ 5.4.0

C++11 is required.

If your local machine does not support g++ 5.4.0 or higher, consider using a server 
such as `linux.tamu.edu` and compile via `$ ssh`

To compile run the makefile script. Simply change your terminal's directory into 
this README's directory and input the following command:

``` console
$ make
```

2 executables will be generated: `a` and `b`
> `a` is the Back-Chaining binaries.  
> `b` is a helper for piping stdout from `a` into a file.

## Running:

To run the Back-Chaining program input one of the following commands into the README's 
directory in the terminal:

The avalible first order logic knowledge base files will display and prompt you 
to choose one with the following command:

``` console
$ ./a
```

You can also specify a file before runtime:

``` console
$ ./a FILENAME
```

If you want to save to a file, pipe stdout as stdin to the helper program: 
> **Note:** You will still input queries normally. There will not be any visual 
> feedback until you input \"q\". 

``` console
$ ./a FILENAME | ./b FILENAME
```

During runtime, input queries through stdin. Input \"q\" to quit. 
> The queries must be *decisions* since this is back-chaining. 
> To get an idea of queries you can ask, query a **rule** from the `.kb` file. 

You can input compound queries like `surgeon texas` to pull a list of surgeons 
that live in texas in `3.kb` 

## Output:

You will find an output file in `problemSet-SolutionTraces/` if you chose to pipe 
`a` to `b`.
> **N.B.** Opening the solution trace in a text editor may result in malformed 
> characters. This is because the program uses terminal colors. 
> Try running `$ cat problemSet-SolutionTraces/FILENAME.sol` for optimal formatting. 

Else, the output will be sent straight to the terminal.

## :one: Nono

Proving Colonel West is a criminal, checkout `1.sol` or run `./a 1` and query 
`criminal`

The knowledgebase for this problem (and all problems) is found in `problemSet/*.kb`
> This specific problem is `1.kb`

## :two: Wumpus World

This knowledgebase only contains info knowing details on rooms (1,1), (1,2), and (2,1). 

- (1,1) is safe and the starting point for the agent. 

- (1,2) is safe but has a breeze

- (2,1) is safe but has a stentch

The goal is to create a knowledgebase to infer that room (2,2) is safe. 

The solution is found in `2.sol`, and can be run with `./a 2` and querying `safe`

## :three: Datalog Emulation

This knowledgebase contains a list of people, their occupation, and where they live. 
We can query the knowledgebase for lawyers, surgeons, and texans. In addition, we can 
use compound queries to generate a list of all surgeons that live in texas. 

We can view this in `3.sol`, or run `./a 3` using query `surgeon texas`

We could also query `lawyer texas` to return a list of lawyers living in texas. 

New rules would need to be created to query other states, try adding 
`((omaha ?x) (nebraska ?x))` into the rule section and query `surgeon nebraska`

## :four: Tic-Tac-Toe: Strategy

I have generated 3 board knowledgebases for this problem: `4-board1.kb`, `4-board2.kb`, 
and `4-board3.kb`. The optimal move for each board is in their corresponding `.sol` file. 
Query `best move` to generate the best move given the board state. 

The implementation of the facts and rules for tic-tac-toe are as follows:

Facts: 

- blank spaces

- occupied spaces

- optimal spaces

Rules: 

- moving into a blank space

- moving into the optimal space (best space)

I defined the general board state within the facts. Then I defined rules for making 
a move, and if that particular move was optimal. I am able to query this KB 
for the best move. 

Other KB considerations: 

- a LUT of winning states

### Tic-Tac-Toe: Sample Trace: 

From `4-board2.sol`

Input query was `best ?m ?p move ?m ?p`

``` console
[1;33mProgram start:[1;36m -- input "q" to quit[0m
# Problem 4: board 2
# | | |o|
# | |x| |
# |x| | |
# KB for a particular tic tac toe board
# The query will output the *optimal* move the next player can make
# occ = occupied
# facts:
((blank 11))
((blank 12))
((occ o 13))
((blank 21))
((occ x 22))
((blank 23))
((occ x 31))
((blank 32))
((blank 33))
# best move facts:
((move x 32))
((move o 13))
# rules:
((move ?m ?p) (blank ?m))
((best ?m ?p) (move ?m ?p))
Parsed facts:
blank 11 
blank 12 
occ o 13 
blank 21 
occ x 22 
blank 23 
occ x 31 
blank 32 
blank 33 
move x 32 
move o 13 
Parsed rules:
move ?m ?p blank ?m 
best ?m ?p move ?m ?p 
[7mInput Query("q" to quit): [0m[1;35mQuery: best[0m
Rule in question: move ?m ?p blank ?m 
Rule in question: best ?m ?p move ?m ?p 
Adding rule: best ?m ?p move ?m ?p 
: 0 0
Checking fact: blank 11 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 1 0
Checking fact: blank 12 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 2 0
Checking fact: occ o 13 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 3 0
Checking fact: blank 21 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 4 0
Checking fact: occ x 22 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 5 0
Checking fact: blank 23 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 6 0
Checking fact: occ x 31 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 7 0
Checking fact: blank 32 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 8 0
Checking fact: blank 33 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 9 0
Checking fact: move x 32 || With rule: best  m  p  move  m  p  
[1;32mUnification Success: move x 32  && best[0m
: 10 0
Checking fact: move o 13 || With rule: best  m  p  move  m  p  
[1;32mUnification Success: move o 13  && best[0m
[1;35mQuery: move[0m
Rule in question: move ?m ?p blank ?m 
Adding rule: move ?m ?p blank ?m 
Rule in question: best ?m ?p move ?m ?p 
Adding rule: best ?m ?p move ?m ?p 
: 0 0
Checking fact: blank 11 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 11  && move[0m
: 0 1
Checking fact: blank 11 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 1 0
Checking fact: blank 12 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 12  && move[0m
: 1 1
Checking fact: blank 12 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 2 0
Checking fact: occ o 13 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 2 1
Checking fact: occ o 13 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 3 0
Checking fact: blank 21 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 21  && move[0m
: 3 1
Checking fact: blank 21 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 4 0
Checking fact: occ x 22 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 4 1
Checking fact: occ x 22 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 5 0
Checking fact: blank 23 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 23  && move[0m
: 5 1
Checking fact: blank 23 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 6 0
Checking fact: occ x 31 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 6 1
Checking fact: occ x 31 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 7 0
Checking fact: blank 32 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 32  && move[0m
: 7 1
Checking fact: blank 32 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 8 0
Checking fact: blank 33 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 33  && move[0m
: 8 1
Checking fact: blank 33 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 9 0
Checking fact: move x 32 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 9 1
Checking fact: move x 32 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 10 0
Checking fact: move o 13 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 10 1
Checking fact: move o 13 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
[1;36m
Original Query: best move 
[1;35m-- Result: --
[1;32m32 move 
[0m

--- End Of Solution Trace ---

```

## Misc. Examples: 

### animals.kb

View `animals.sol`, the input query was `animal ?m`

The program will infer that facts defined as mammals, birds, apes, etc 
are animals by the rules. 

You may also want to run `./a animals` and query `vehicle`. The expected inference 
should be that a Ford and Tesla are vehicles. 

### classic.kb

View `classic.sol`, the input query was `mortal ?m`

This is the classic Modus Ponens example: 

1. fact: Socrates is a man

   `((man socrates))`

2. rule: all men are mortal

   `((man ?m) (mortal ?m))`

3. Therefore Socrates is mortal

   This result is generated by the inferencer with query `mortal`

As a bonus, I added a rule stating all wrestlers are legends. 
