[1;33mProgram start:[1;36m -- input "q" to quit[0m
# facts
((mammal dog))
((mammal dog))
((bird penguin))
((car ford))
# rules
((mammal ?m) (animal ?m)) # forall m mammal m  --> animal m
((bird ?m) (animal ?m))
Parsed facts:
mammal dog 
mammal dog 
bird penguin 
car ford 
Parsed rules:
mammal ?m animal ?m 
bird ?m animal ?m 
[1;35mQuery: animal[0m
Rule in question: mammal ?m animal ?m 
Adding rule: mammal ?m animal ?m 
Rule in question: bird ?m animal ?m 
Adding rule: bird ?m animal ?m 
: 0 0
currRule: mammal 
[1;32mUnify: mammal dog  && animal[0m
: 0 1
currRule: bird 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 1 0
currRule: mammal 
[1;32mUnify: mammal dog  && animal[0m
: 1 1
currRule: bird 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 2 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 2 1
currRule: bird 
[1;32mUnify: bird penguin  && animal[0m
: 3 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 3 1
currRule: bird 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m[1;35mQuery: Mark[0m
Rule in question: mammal ?m animal ?m 
Rule in question: bird ?m animal ?m 

--- End Of Solution Trace ---
