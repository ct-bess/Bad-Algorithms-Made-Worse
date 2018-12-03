[1;33mProgram start:[1;36m -- input "q" to quit[0m
# Problem 4: board 1
# |x|x| |
# | |o| |
# | | | |
# KB for a particular tic tac toe board
# The query will output the *optimal* move the next player can make
# occ = occupied
# facts:
((occ x 11))
((occ x 12))
((blank 13))
((blank 21))
((occ o 22))
((blank 23))
((blank 31))
((blank 32))
((blank 33))
# best move facts:
((move x 13))
((move o 13))
# rules:
((move ?m ?p) (blank ?m))
((best ?m ?p) (move ?m ?p))
Parsed facts:
occ x 11 
occ x 12 
blank 13 
blank 21 
occ o 22 
blank 23 
blank 31 
blank 32 
blank 33 
move x 13 
move o 13 
Parsed rules:
move ?m ?p blank ?m 
best ?m ?p move ?m ?p 
[7mInput Query("q" to quit): [0m[1;35mQuery: best[0m
Rule in question: move ?m ?p blank ?m 
Rule in question: best ?m ?p move ?m ?p 
Adding rule: best ?m ?p move ?m ?p 
: 0 0
Checking fact: occ x 11 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 1 0
Checking fact: occ x 12 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 2 0
Checking fact: blank 13 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 3 0
Checking fact: blank 21 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 4 0
Checking fact: occ o 22 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 5 0
Checking fact: blank 23 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 6 0
Checking fact: blank 31 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 7 0
Checking fact: blank 32 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 8 0
Checking fact: blank 33 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 9 0
Checking fact: move x 13 || With rule: best  m  p  move  m  p  
[1;32mUnification Success: move x 13  && best[0m
: 10 0
Checking fact: move o 13 || With rule: best  m  p  move  m  p  
[1;32mUnification Success: move o 13  && best[0m
[1;35mQuery: move[0m
Rule in question: move ?m ?p blank ?m 
Adding rule: move ?m ?p blank ?m 
Rule in question: best ?m ?p move ?m ?p 
Adding rule: best ?m ?p move ?m ?p 
: 0 0
Checking fact: occ x 11 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 0 1
Checking fact: occ x 11 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 1 0
Checking fact: occ x 12 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 1 1
Checking fact: occ x 12 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 2 0
Checking fact: blank 13 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 13  && move[0m
: 2 1
Checking fact: blank 13 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 3 0
Checking fact: blank 21 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 21  && move[0m
: 3 1
Checking fact: blank 21 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 4 0
Checking fact: occ o 22 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 4 1
Checking fact: occ o 22 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 5 0
Checking fact: blank 23 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 23  && move[0m
: 5 1
Checking fact: blank 23 || With rule: best  m  p  move  m  p  
[1;31mUnification failed[0m
: 6 0
Checking fact: blank 31 || With rule: move  m  p  blank  m  
[1;32mUnification Success: blank 31  && move[0m
: 6 1
Checking fact: blank 31 || With rule: best  m  p  move  m  p  
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
Checking fact: move x 13 || With rule: move  m  p  blank  m  
[1;31mUnification failed[0m
: 9 1
Checking fact: move x 13 || With rule: best  m  p  move  m  p  
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
[1;32m13 move 
[0m

--- End Of Solution Trace ---
