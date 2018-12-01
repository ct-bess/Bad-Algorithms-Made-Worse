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
((mammal ?m) (ape ?m)) 
((mammal ?m) (man ?m)) 
((bird ?m) (animal ?m))
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
mammal ?m ape ?m 
mammal ?m man ?m 
bird ?m animal ?m 
car ?m vehicle ?m 
[1;35mQuery: animal[0m
Rule in question: mammal ?m animal ?m 
Adding rule: mammal ?m animal ?m 
Rule in question: mammal ?m ape ?m 
Rule in question: mammal ?m man ?m 
Rule in question: bird ?m animal ?m 
Adding rule: bird ?m animal ?m 
Rule in question: car ?m vehicle ?m 
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
[1;32mUnify: mammal cat  && animal[0m
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
[0m: 4 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 4 1
currRule: bird 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 5 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 5 1
currRule: bird 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 6 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 6 1
currRule: bird 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m[1;35mQuery: mammal[0m
Rule in question: mammal ?m animal ?m 
Adding rule: mammal ?m animal ?m 
Rule in question: mammal ?m ape ?m 
Adding rule: mammal ?m ape ?m 
Rule in question: mammal ?m man ?m 
Adding rule: mammal ?m man ?m 
Rule in question: bird ?m animal ?m 
Rule in question: car ?m vehicle ?m 
: 0 0
currRule: mammal 
[1;32mUnify: mammal dog  && mammal[0m
: 0 1
currRule: mammal 
[1;32mUnify: mammal dog  && mammal[0m
: 0 2
currRule: mammal 
[1;32mUnify: mammal dog  && mammal[0m
: 1 0
currRule: mammal 
[1;32mUnify: mammal cat  && mammal[0m
: 1 1
currRule: mammal 
[1;32mUnify: mammal cat  && mammal[0m
: 1 2
currRule: mammal 
[1;32mUnify: mammal cat  && mammal[0m
: 2 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 2 1
currRule: mammal 
currRule: m 
currRule: ape 
currRule: m 
[1;31mUnification failed
[0m: 2 2
currRule: mammal 
currRule: m 
currRule: man 
currRule: m 
[1;31mUnification failed
[0m: 3 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 3 1
currRule: mammal 
currRule: m 
currRule: ape 
currRule: m 
[1;31mUnification failed
[0m: 3 2
currRule: mammal 
currRule: m 
currRule: man 
currRule: m 
[1;31mUnification failed
[0m: 4 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 4 1
currRule: mammal 
currRule: m 
currRule: ape 
currRule: m 
[1;31mUnification failed
[0m: 4 2
currRule: mammal 
currRule: m 
currRule: man 
currRule: m 
[1;31mUnification failed
[0m: 5 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 5 1
currRule: mammal 
currRule: m 
currRule: ape 
[1;32mUnify: ape gorilla  && mammal[0m
: 5 2
currRule: mammal 
currRule: m 
currRule: man 
currRule: m 
[1;31mUnification failed
[0m: 6 0
currRule: mammal 
currRule: m 
currRule: animal 
currRule: m 
[1;31mUnification failed
[0m: 6 1
currRule: mammal 
currRule: m 
currRule: ape 
currRule: m 
[1;31mUnification failed
[0m: 6 2
currRule: mammal 
currRule: m 
currRule: man 
[1;32mUnify: man Mark_Wolf  && mammal[0m
[1;35mQuery: fukc[0m
Rule in question: mammal ?m animal ?m 
Rule in question: mammal ?m ape ?m 
Rule in question: mammal ?m man ?m 
Rule in question: bird ?m animal ?m 
Rule in question: car ?m vehicle ?m 

--- End Of Solution Trace ---
