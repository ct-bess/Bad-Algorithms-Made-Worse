[1;33mProgram start:[1;36m -- input "q" to quit[0m
# Problem 3:
# Facts:
((occupation joe hotel_manager))
((lives_in joe pittsburgh))

((occupation sam brain_surgeon))
((lives_in sam houston))

((occupation bill trial_lawyer))
((lives_in bill los_angeles))

((occupation cindy oral_surgeon))
((lives_in cindy omaha))

((occupation joan civil_lawyer))
((lives_in joan chicago))

((occupation len graphic_artist))
((lives_in len austin))

((occupation lance heart_surgeon))
((lives_in lance dallas))

((occupation frank patent_lawyer))
((lives_in frank dallas))

((occupation charlie plastic_surgeon))
((lives_in charlie houston))

((occupation lisa investment_banker))
((lives_in lisa albuquerque))

# Rules:
((brain_surgeon ?x) (surgeon ?x))
((oral_surgeon ?x) (surgeon ?x))
((heart_surgeon ?x) (surgeon ?x))
((plastic_surgeon ?x) (surgeon ?x))

((trial_lawyer ?x) (lawyer ?x))
((civil_lawyer ?x) (lawyer ?x))
((patent_lawyer ?x) (lawyer ?x))

((dallas ?x) (texas ?x))
((houston ?x) (texas ?x))
((austin ?x) (texas ?x))
Parsed facts:
occupation joe hotel_manager 
lives_in joe pittsburgh 
occupation sam brain_surgeon 
lives_in sam houston 
occupation bill trial_lawyer 
lives_in bill los_angeles 
occupation cindy oral_surgeon 
lives_in cindy omaha 
occupation joan civil_lawyer 
lives_in joan chicago 
occupation len graphic_artist 
lives_in len austin 
occupation lance heart_surgeon 
lives_in lance dallas 
occupation frank patent_lawyer 
lives_in frank dallas 
occupation charlie plastic_surgeon 
lives_in charlie houston 
occupation lisa investment_banker 
lives_in lisa albuquerque 
Parsed rules:
brain_surgeon ?x surgeon ?x 
oral_surgeon ?x surgeon ?x 
heart_surgeon ?x surgeon ?x 
plastic_surgeon ?x surgeon ?x 
trial_lawyer ?x lawyer ?x 
civil_lawyer ?x lawyer ?x 
patent_lawyer ?x lawyer ?x 
dallas ?x texas ?x 
houston ?x texas ?x 
austin ?x texas ?x 
[1;35mQuery: texas[0m
Rule in question: brain_surgeon ?x surgeon ?x 
Rule in question: oral_surgeon ?x surgeon ?x 
Rule in question: heart_surgeon ?x surgeon ?x 
Rule in question: plastic_surgeon ?x surgeon ?x 
Rule in question: trial_lawyer ?x lawyer ?x 
Rule in question: civil_lawyer ?x lawyer ?x 
Rule in question: patent_lawyer ?x lawyer ?x 
Rule in question: dallas ?x texas ?x 
Adding rule: dallas ?x texas ?x 
Rule in question: houston ?x texas ?x 
Adding rule: houston ?x texas ?x 
Rule in question: austin ?x texas ?x 
Adding rule: austin ?x texas ?x 
: 0 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 0 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 0 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 1 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 1 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 1 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 2 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 2 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 2 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 3 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 3 1
currRule: houston 
[1;32mUnify: lives_in sam houston  && texas[0m
: 3 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 4 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 4 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 4 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 5 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 5 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 5 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 6 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 6 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 6 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 7 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 7 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 7 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 8 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 8 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 8 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 9 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 9 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 9 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 10 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 10 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 10 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 11 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 11 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 11 2
currRule: austin 
[1;32mUnify: lives_in len austin  && texas[0m
: 12 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 12 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 12 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 13 0
currRule: dallas 
[1;32mUnify: lives_in lance dallas  && texas[0m
: 13 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 13 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 14 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 14 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 14 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 15 0
currRule: dallas 
[1;32mUnify: lives_in frank dallas  && texas[0m
: 15 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 15 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 16 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 16 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 16 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 17 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 17 1
currRule: houston 
[1;32mUnify: lives_in charlie houston  && texas[0m
: 17 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 18 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 18 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 18 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 19 0
currRule: dallas 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 19 1
currRule: houston 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m: 19 2
currRule: austin 
currRule: x 
currRule: texas 
currRule: x 
[1;31mUnification failed
[0m[1;35mQuery: surgeon[0m
Rule in question: brain_surgeon ?x surgeon ?x 
Adding rule: brain_surgeon ?x surgeon ?x 
Rule in question: oral_surgeon ?x surgeon ?x 
Adding rule: oral_surgeon ?x surgeon ?x 
Rule in question: heart_surgeon ?x surgeon ?x 
Adding rule: heart_surgeon ?x surgeon ?x 
Rule in question: plastic_surgeon ?x surgeon ?x 
Adding rule: plastic_surgeon ?x surgeon ?x 
Rule in question: trial_lawyer ?x lawyer ?x 
Rule in question: civil_lawyer ?x lawyer ?x 
Rule in question: patent_lawyer ?x lawyer ?x 
Rule in question: dallas ?x texas ?x 
Rule in question: houston ?x texas ?x 
Rule in question: austin ?x texas ?x 
: 0 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 0 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 0 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 0 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 1 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 1 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 1 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 1 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 2 0
currRule: brain_surgeon 
[1;32mUnify: occupation sam brain_surgeon  && surgeon[0m
: 2 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation sam brain_surgeon  && surgeon[0m
: 2 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation sam brain_surgeon  && surgeon[0m
: 2 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation sam brain_surgeon  && surgeon[0m
: 3 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 3 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 3 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 3 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 4 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 4 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 4 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 4 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 5 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 5 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 5 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 5 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 6 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation cindy oral_surgeon  && surgeon[0m
: 6 1
currRule: oral_surgeon 
[1;32mUnify: occupation cindy oral_surgeon  && surgeon[0m
: 6 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation cindy oral_surgeon  && surgeon[0m
: 6 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation cindy oral_surgeon  && surgeon[0m
: 7 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 7 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 7 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 7 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 8 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 8 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 8 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 8 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 9 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 9 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 9 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 9 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 10 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 10 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 10 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 10 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 11 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 11 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 11 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 11 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 12 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation lance heart_surgeon  && surgeon[0m
: 12 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation lance heart_surgeon  && surgeon[0m
: 12 2
currRule: heart_surgeon 
[1;32mUnify: occupation lance heart_surgeon  && surgeon[0m
: 12 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation lance heart_surgeon  && surgeon[0m
: 13 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 13 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 13 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 13 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 14 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 14 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 14 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 14 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 15 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 15 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 15 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 15 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 16 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation charlie plastic_surgeon  && surgeon[0m
: 16 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation charlie plastic_surgeon  && surgeon[0m
: 16 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
[1;32mUnify: occupation charlie plastic_surgeon  && surgeon[0m
: 16 3
currRule: plastic_surgeon 
[1;32mUnify: occupation charlie plastic_surgeon  && surgeon[0m
: 17 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 17 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 17 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 17 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 18 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 18 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 18 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 18 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 19 0
currRule: brain_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 19 1
currRule: oral_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 19 2
currRule: heart_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m: 19 3
currRule: plastic_surgeon 
currRule: x 
currRule: surgeon 
currRule: x 
[1;31mUnification failed
[0m[1;35mQuery: VanDarkHolm[0m
Rule in question: brain_surgeon ?x surgeon ?x 
Rule in question: oral_surgeon ?x surgeon ?x 
Rule in question: heart_surgeon ?x surgeon ?x 
Rule in question: plastic_surgeon ?x surgeon ?x 
Rule in question: trial_lawyer ?x lawyer ?x 
Rule in question: civil_lawyer ?x lawyer ?x 
Rule in question: patent_lawyer ?x lawyer ?x 
Rule in question: dallas ?x texas ?x 
Rule in question: houston ?x texas ?x 
Rule in question: austin ?x texas ?x 

--- End Of Solution Trace ---
