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
