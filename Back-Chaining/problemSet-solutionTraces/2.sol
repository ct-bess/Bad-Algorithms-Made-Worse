[1;33mProgram start:[1;36m -- input "q" to quit[0m
# Problem 2: Wumpus World
# Show room (2,2) can be inferred safe after our brave warrior has visited 
# rooms (1,1) (1,2) and (2,1)
# --> The agent only has knowledge from those rooms
# Layout:
# 4: Stentch |                       | breeze | pit    |
# 3: WUMPUS  | Gold, breeze, stentch |   pit  | breeze |
# 2: Stentch |                       | breeze |        |
# 1: Warrior |        breeze         |  pit   | breeze |
# 
# I am using fragrant as no stentch
#            calm_winds as no breeze
# facts
((safe 11))
((safe 12))
((safe 21))
((breeze 12))
((fragrant 12))
((stentch 21))
((calm_winds 21))
((adjacent 12 22))
((adjacent 21 22))
((fragrant 22))
((calm_winds 22))
# rules
((unsafe ?r) (pit ?r))
((unsafe ?r) (wumpus ?r))
((calm_winds ?r) (no_adjacent_pit ?r))
((fragrant ?r) (no_adjacent_wumpus ?r))
((calm_winds ?r) (fragrant ?r) (safe ?r))
Parsed facts:
2,2 
1,1 1,2 and 2,1 
safe 11 
safe 12 
safe 21 
breeze 12 
fragrant 12 
stentch 21 
calm_winds 21 
adjacent 12 22 
adjacent 21 22 
fragrant 22 
calm_winds 22 
Parsed rules:
unsafe ?r pit ?r 
unsafe ?r wumpus ?r 
calm_winds ?r no_adjacent_pit ?r 
fragrant ?r no_adjacent_wumpus ?r 
calm_winds ?r fragrant ?r safe ?r 
[1;35mQuery: safe[0m
Rule in question: unsafe ?r pit ?r 
Adding rule: unsafe ?r pit ?r 
Rule in question: unsafe ?r wumpus ?r 
Adding rule: unsafe ?r wumpus ?r 
Rule in question: calm_winds ?r no_adjacent_pit ?r 
Rule in question: fragrant ?r no_adjacent_wumpus ?r 
Rule in question: calm_winds ?r fragrant ?r safe ?r 
Adding rule: calm_winds ?r fragrant ?r safe ?r 
: 0 0
Checking fact: 2,2 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 0 1
Checking fact: 2,2 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 0 2
Checking fact: 2,2 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 1 0
Checking fact: 1,1 1,2 and 2,1 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 1 1
Checking fact: 1,1 1,2 and 2,1 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 1 2
Checking fact: 1,1 1,2 and 2,1 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 2 0
Checking fact: safe 11 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 2 1
Checking fact: safe 11 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 2 2
Checking fact: safe 11 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 3 0
Checking fact: safe 12 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 3 1
Checking fact: safe 12 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 3 2
Checking fact: safe 12 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 4 0
Checking fact: safe 21 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 4 1
Checking fact: safe 21 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 4 2
Checking fact: safe 21 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 5 0
Checking fact: breeze 12 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 5 1
Checking fact: breeze 12 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 5 2
Checking fact: breeze 12 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 6 0
Checking fact: fragrant 12 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 6 1
Checking fact: fragrant 12 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 6 2
Checking fact: fragrant 12 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;32mUnification Success: fragrant 12  && safe[0m
: 7 0
Checking fact: stentch 21 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 7 1
Checking fact: stentch 21 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 7 2
Checking fact: stentch 21 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 8 0
Checking fact: calm_winds 21 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 8 1
Checking fact: calm_winds 21 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 8 2
Checking fact: calm_winds 21 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;32mUnification Success: calm_winds 21  && safe[0m
: 9 0
Checking fact: adjacent 12 22 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 9 1
Checking fact: adjacent 12 22 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 9 2
Checking fact: adjacent 12 22 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 10 0
Checking fact: adjacent 21 22 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 10 1
Checking fact: adjacent 21 22 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 10 2
Checking fact: adjacent 21 22 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;31mUnification failed[0m
: 11 0
Checking fact: fragrant 22 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 11 1
Checking fact: fragrant 22 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 11 2
Checking fact: fragrant 22 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;32mUnification Success: fragrant 22  && safe[0m
: 12 0
Checking fact: calm_winds 22 || With rule: unsafe  r  pit  r  
[1;31mUnification failed[0m
: 12 1
Checking fact: calm_winds 22 || With rule: unsafe  r  wumpus  r  
[1;31mUnification failed[0m
: 12 2
Checking fact: calm_winds 22 || With rule: calm_winds  r  fragrant  r  safe  r  
[1;32mUnification Success: calm_winds 22  && safe[0m
[1;36m
Original Query: safe 
[1;35m-- Result: --
[1;32m12 safe 
21 safe 
22 safe 
22 safe 
[0m

--- End Of Solution Trace ---
