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
: 0 0
a: mammal dog 
b: mammal ?m animal ?m 
Unification success: animal dog 
: 0 1
a: mammal dog 
b: bird ?m animal ?m 
Unification failed
: 1 0
a: mammal dog 
b: mammal ?m animal ?m 
Unification success: animal dog 
: 1 1
a: mammal dog 
b: bird ?m animal ?m 
Unification failed
: 2 0
a: bird penguin 
b: mammal ?m animal ?m 
Unification failed
: 2 1
a: bird penguin 
b: bird ?m animal ?m 
Unification success: animal penguin 
: 3 0
a: car ford 
b: mammal ?m animal ?m 
Unification failed
: 3 1
a: car ford 
b: bird ?m animal ?m 
Unification failed
-- end of solution trace --
