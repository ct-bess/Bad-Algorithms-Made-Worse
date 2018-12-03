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
> `a` is the Back-Chaining binaries  
> `b` is a helper to convert stdout to a file

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

## Tic-Tac-Toe: Strategy (4)

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

- LUT of winning states

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

## Example Trace: 

From `animals.sol`
> This is the output from a text editor, notice the ESC characters. 

The input query was `animal ?m`

The program will infer that facts defined as mammals, birds, apes, etc 
are animals by the rules. 

``` console
[1;33mProgram start:[1;36m -- input "q" to quit[0m
# facts
((mammal dog))
((mammal cat))
((bird penguin))
((car Ford))
((car Tesla))
((ape gorilla))
((man Mark_Wolf))
# rules
((mammal ?m) (animal ?m)) # forall m mammal m  --> animal m
((ape ?m) (animal ?m)) 
((bird ?m) (animal ?m))
((man ?m) (mammal ?m)) 
((car ?m) (vehicle ?m))
Parsed facts:
mammal dog 
mammal cat 
bird penguin 
car Ford 
car Tesla 
ape gorilla 
man Mark_Wolf 
Parsed rules:
mammal ?m animal ?m 
ape ?m animal ?m 
bird ?m animal ?m 
man ?m mammal ?m 
car ?m vehicle ?m 
[1;35mQuery: animal[0m
Rule in question: mammal ?m animal ?m 
Adding rule: mammal ?m animal ?m 
Rule in question: ape ?m animal ?m 
Adding rule: ape ?m animal ?m 
Rule in question: bird ?m animal ?m 
Adding rule: bird ?m animal ?m 
Rule in question: man ?m mammal ?m 
Rule in question: car ?m vehicle ?m 
: 0 0
Checking fact: mammal dog || With rule: mammal  m  animal  m  
[1;32mUnification Success: mammal dog  && animal[0m
: 0 1
Checking fact: mammal dog || With rule: ape  m  animal  m  
[1;31mUnification failed[0m
: 0 2
Checking fact: mammal dog || With rule: bird  m  animal  m  
[1;31mUnification failed[0m
: 1 0
Checking fact: mammal cat || With rule: mammal  m  animal  m  
[1;32mUnification Success: mammal cat  && animal[0m
: 1 1
Checking fact: mammal cat || With rule: ape  m  animal  m  
[1;31mUnification failed[0m
: 1 2
Checking fact: mammal cat || With rule: bird  m  animal  m  
[1;31mUnification failed[0m
: 2 0
Checking fact: bird penguin || With rule: mammal  m  animal  m  
[1;31mUnification failed[0m
: 2 1
Checking fact: bird penguin || With rule: ape  m  animal  m  
[1;31mUnification failed[0m
: 2 2
Checking fact: bird penguin || With rule: bird  m  animal  m  
[1;32mUnification Success: bird penguin  && animal[0m
: 3 0
Checking fact: car Ford || With rule: mammal  m  animal  m  
[1;31mUnification failed[0m
: 3 1
Checking fact: car Ford || With rule: ape  m  animal  m  
[1;31mUnification failed[0m
: 3 2
Checking fact: car Ford || With rule: bird  m  animal  m  
[1;31mUnification failed[0m
: 4 0
Checking fact: car Tesla || With rule: mammal  m  animal  m  
[1;31mUnification failed[0m
: 4 1
Checking fact: car Tesla || With rule: ape  m  animal  m  
[1;31mUnification failed[0m
: 4 2
Checking fact: car Tesla || With rule: bird  m  animal  m  
[1;31mUnification failed[0m
: 5 0
Checking fact: ape gorilla || With rule: mammal  m  animal  m  
[1;31mUnification failed[0m
: 5 1
Checking fact: ape gorilla || With rule: ape  m  animal  m  
[1;32mUnification Success: ape gorilla  && animal[0m
: 5 2
Checking fact: ape gorilla || With rule: bird  m  animal  m  
[1;31mUnification failed[0m
: 6 0
Checking fact: man Mark_Wolf || With rule: mammal  m  animal  m  
[1;31mUnification failed[0m
: 6 1
Checking fact: man Mark_Wolf || With rule: ape  m  animal  m  
[1;31mUnification failed[0m
: 6 2
Checking fact: man Mark_Wolf || With rule: bird  m  animal  m  
[1;31mUnification failed[0m
[1;36m
Original Query: animal 
[1;35m-- Result: --
[1;32mdog animal 
cat animal 
penguin animal 
gorilla animal 
[0m

--- End Of Solution Trace ---

```
