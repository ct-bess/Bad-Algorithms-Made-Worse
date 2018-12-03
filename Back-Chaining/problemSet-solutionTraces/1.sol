[1;33mProgram start:[1;36m -- input "q" to quit[0m
# Problem 1: Prove Colonel West is a criminal
# ... is a crime for an American to sell weapons to hostile nations
# Nono ... has some missiles
# Colonel West sold Nono missels
# A missile is a weapon
# An enemy of America is hostile
# Colonel West is American
# Nono is an enemy of America
# facts
((owns nono missile))
((weapon missile))
((enemy america nono))
((hostile nono))
((american west))
((sells_weapons west nono))
# rules
((sells_weapons ?x) (criminal ?x))
((hostile ?x) (criminal ?x))
((enemy ?x) (hostile ?x))
((missile ?x) (weapon ?x))
Parsed facts:
owns nono missile 
weapon missile 
enemy america nono 
hostile nono 
american west 
sells_weapons west nono 
Parsed rules:
sells_weapons ?x criminal ?x 
hostile ?x criminal ?x 
enemy ?x hostile ?x 
missile ?x weapon ?x 
[7mInput Query("q" to quit): [0m[1;35mQuery: criminal[0m
Rule in question: sells_weapons ?x criminal ?x 
Adding rule: sells_weapons ?x criminal ?x 
Rule in question: hostile ?x criminal ?x 
Adding rule: hostile ?x criminal ?x 
Rule in question: enemy ?x hostile ?x 
Rule in question: missile ?x weapon ?x 
: 0 0
Checking fact: owns nono missile || With rule: sells_weapons  x  criminal  x  
[1;31mUnification failed[0m
: 0 1
Checking fact: owns nono missile || With rule: hostile  x  criminal  x  
[1;31mUnification failed[0m
: 1 0
Checking fact: weapon missile || With rule: sells_weapons  x  criminal  x  
[1;31mUnification failed[0m
: 1 1
Checking fact: weapon missile || With rule: hostile  x  criminal  x  
[1;31mUnification failed[0m
: 2 0
Checking fact: enemy america nono || With rule: sells_weapons  x  criminal  x  
[1;31mUnification failed[0m
: 2 1
Checking fact: enemy america nono || With rule: hostile  x  criminal  x  
[1;31mUnification failed[0m
: 3 0
Checking fact: hostile nono || With rule: sells_weapons  x  criminal  x  
[1;31mUnification failed[0m
: 3 1
Checking fact: hostile nono || With rule: hostile  x  criminal  x  
[1;32mUnification Success: hostile nono  && criminal[0m
: 4 0
Checking fact: american west || With rule: sells_weapons  x  criminal  x  
[1;31mUnification failed[0m
: 4 1
Checking fact: american west || With rule: hostile  x  criminal  x  
[1;31mUnification failed[0m
: 5 0
Checking fact: sells_weapons west nono || With rule: sells_weapons  x  criminal  x  
[1;32mUnification Success: sells_weapons west nono  && criminal[0m
: 5 1
Checking fact: sells_weapons west nono || With rule: hostile  x  criminal  x  
[1;31mUnification failed[0m
[1;36m
Original Query: criminal 
[1;35m-- Result: --
[1;32mnono criminal 
west nono criminal 
[0m

--- End Of Solution Trace ---
