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
[1;35mQuery: surgeon[0m
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
Checking fact: occupation joe hotel_manager || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 0 1
Checking fact: occupation joe hotel_manager || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 0 2
Checking fact: occupation joe hotel_manager || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 0 3
Checking fact: occupation joe hotel_manager || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 1 0
Checking fact: lives_in joe pittsburgh || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 1 1
Checking fact: lives_in joe pittsburgh || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 1 2
Checking fact: lives_in joe pittsburgh || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 1 3
Checking fact: lives_in joe pittsburgh || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 2 0
Checking fact: occupation sam brain_surgeon || With rule: brain_surgeon  x  surgeon  x  
[1;32mUnify Succ: occupation sam brain_surgeon  && surgeon[0m
: 2 1
Checking fact: occupation sam brain_surgeon || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 2 2
Checking fact: occupation sam brain_surgeon || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 2 3
Checking fact: occupation sam brain_surgeon || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 3 0
Checking fact: lives_in sam houston || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 3 1
Checking fact: lives_in sam houston || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 3 2
Checking fact: lives_in sam houston || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 3 3
Checking fact: lives_in sam houston || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 4 0
Checking fact: occupation bill trial_lawyer || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 4 1
Checking fact: occupation bill trial_lawyer || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 4 2
Checking fact: occupation bill trial_lawyer || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 4 3
Checking fact: occupation bill trial_lawyer || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 5 0
Checking fact: lives_in bill los_angeles || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 5 1
Checking fact: lives_in bill los_angeles || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 5 2
Checking fact: lives_in bill los_angeles || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 5 3
Checking fact: lives_in bill los_angeles || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 6 0
Checking fact: occupation cindy oral_surgeon || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 6 1
Checking fact: occupation cindy oral_surgeon || With rule: oral_surgeon  x  surgeon  x  
[1;32mUnify Succ: occupation cindy oral_surgeon  && surgeon[0m
: 6 2
Checking fact: occupation cindy oral_surgeon || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 6 3
Checking fact: occupation cindy oral_surgeon || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 7 0
Checking fact: lives_in cindy omaha || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 7 1
Checking fact: lives_in cindy omaha || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 7 2
Checking fact: lives_in cindy omaha || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 7 3
Checking fact: lives_in cindy omaha || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 8 0
Checking fact: occupation joan civil_lawyer || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 8 1
Checking fact: occupation joan civil_lawyer || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 8 2
Checking fact: occupation joan civil_lawyer || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 8 3
Checking fact: occupation joan civil_lawyer || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 9 0
Checking fact: lives_in joan chicago || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 9 1
Checking fact: lives_in joan chicago || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 9 2
Checking fact: lives_in joan chicago || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 9 3
Checking fact: lives_in joan chicago || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 10 0
Checking fact: occupation len graphic_artist || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 10 1
Checking fact: occupation len graphic_artist || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 10 2
Checking fact: occupation len graphic_artist || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 10 3
Checking fact: occupation len graphic_artist || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 11 0
Checking fact: lives_in len austin || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 11 1
Checking fact: lives_in len austin || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 11 2
Checking fact: lives_in len austin || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 11 3
Checking fact: lives_in len austin || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 12 0
Checking fact: occupation lance heart_surgeon || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 12 1
Checking fact: occupation lance heart_surgeon || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 12 2
Checking fact: occupation lance heart_surgeon || With rule: heart_surgeon  x  surgeon  x  
[1;32mUnify Succ: occupation lance heart_surgeon  && surgeon[0m
: 12 3
Checking fact: occupation lance heart_surgeon || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 13 0
Checking fact: lives_in lance dallas || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 13 1
Checking fact: lives_in lance dallas || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 13 2
Checking fact: lives_in lance dallas || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 13 3
Checking fact: lives_in lance dallas || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 14 0
Checking fact: occupation frank patent_lawyer || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 14 1
Checking fact: occupation frank patent_lawyer || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 14 2
Checking fact: occupation frank patent_lawyer || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 14 3
Checking fact: occupation frank patent_lawyer || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 15 0
Checking fact: lives_in frank dallas || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 15 1
Checking fact: lives_in frank dallas || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 15 2
Checking fact: lives_in frank dallas || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 15 3
Checking fact: lives_in frank dallas || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 16 0
Checking fact: occupation charlie plastic_surgeon || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 16 1
Checking fact: occupation charlie plastic_surgeon || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 16 2
Checking fact: occupation charlie plastic_surgeon || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 16 3
Checking fact: occupation charlie plastic_surgeon || With rule: plastic_surgeon  x  surgeon  x  
[1;32mUnify Succ: occupation charlie plastic_surgeon  && surgeon[0m
: 17 0
Checking fact: lives_in charlie houston || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 17 1
Checking fact: lives_in charlie houston || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 17 2
Checking fact: lives_in charlie houston || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 17 3
Checking fact: lives_in charlie houston || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 18 0
Checking fact: occupation lisa investment_banker || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 18 1
Checking fact: occupation lisa investment_banker || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 18 2
Checking fact: occupation lisa investment_banker || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 18 3
Checking fact: occupation lisa investment_banker || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 19 0
Checking fact: lives_in lisa albuquerque || With rule: brain_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 19 1
Checking fact: lives_in lisa albuquerque || With rule: oral_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 19 2
Checking fact: lives_in lisa albuquerque || With rule: heart_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
: 19 3
Checking fact: lives_in lisa albuquerque || With rule: plastic_surgeon  x  surgeon  x  
[1;31mUnification failed[0m
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
Checking fact: occupation joe hotel_manager || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 0 1
Checking fact: occupation joe hotel_manager || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 0 2
Checking fact: occupation joe hotel_manager || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 1 0
Checking fact: lives_in joe pittsburgh || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 1 1
Checking fact: lives_in joe pittsburgh || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 1 2
Checking fact: lives_in joe pittsburgh || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 2 0
Checking fact: occupation sam brain_surgeon || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 2 1
Checking fact: occupation sam brain_surgeon || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 2 2
Checking fact: occupation sam brain_surgeon || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 3 0
Checking fact: lives_in sam houston || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 3 1
Checking fact: lives_in sam houston || With rule: houston  x  texas  x  
[1;32mUnify Succ: lives_in sam houston  && texas[0m
: 3 2
Checking fact: lives_in sam houston || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 4 0
Checking fact: occupation bill trial_lawyer || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 4 1
Checking fact: occupation bill trial_lawyer || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 4 2
Checking fact: occupation bill trial_lawyer || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 5 0
Checking fact: lives_in bill los_angeles || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 5 1
Checking fact: lives_in bill los_angeles || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 5 2
Checking fact: lives_in bill los_angeles || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 6 0
Checking fact: occupation cindy oral_surgeon || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 6 1
Checking fact: occupation cindy oral_surgeon || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 6 2
Checking fact: occupation cindy oral_surgeon || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 7 0
Checking fact: lives_in cindy omaha || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 7 1
Checking fact: lives_in cindy omaha || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 7 2
Checking fact: lives_in cindy omaha || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 8 0
Checking fact: occupation joan civil_lawyer || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 8 1
Checking fact: occupation joan civil_lawyer || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 8 2
Checking fact: occupation joan civil_lawyer || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 9 0
Checking fact: lives_in joan chicago || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 9 1
Checking fact: lives_in joan chicago || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 9 2
Checking fact: lives_in joan chicago || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 10 0
Checking fact: occupation len graphic_artist || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 10 1
Checking fact: occupation len graphic_artist || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 10 2
Checking fact: occupation len graphic_artist || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 11 0
Checking fact: lives_in len austin || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 11 1
Checking fact: lives_in len austin || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 11 2
Checking fact: lives_in len austin || With rule: austin  x  texas  x  
[1;32mUnify Succ: lives_in len austin  && texas[0m
: 12 0
Checking fact: occupation lance heart_surgeon || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 12 1
Checking fact: occupation lance heart_surgeon || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 12 2
Checking fact: occupation lance heart_surgeon || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 13 0
Checking fact: lives_in lance dallas || With rule: dallas  x  texas  x  
[1;32mUnify Succ: lives_in lance dallas  && texas[0m
: 13 1
Checking fact: lives_in lance dallas || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 13 2
Checking fact: lives_in lance dallas || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 14 0
Checking fact: occupation frank patent_lawyer || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 14 1
Checking fact: occupation frank patent_lawyer || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 14 2
Checking fact: occupation frank patent_lawyer || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 15 0
Checking fact: lives_in frank dallas || With rule: dallas  x  texas  x  
[1;32mUnify Succ: lives_in frank dallas  && texas[0m
: 15 1
Checking fact: lives_in frank dallas || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 15 2
Checking fact: lives_in frank dallas || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 16 0
Checking fact: occupation charlie plastic_surgeon || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 16 1
Checking fact: occupation charlie plastic_surgeon || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 16 2
Checking fact: occupation charlie plastic_surgeon || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 17 0
Checking fact: lives_in charlie houston || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 17 1
Checking fact: lives_in charlie houston || With rule: houston  x  texas  x  
[1;32mUnify Succ: lives_in charlie houston  && texas[0m
: 17 2
Checking fact: lives_in charlie houston || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 18 0
Checking fact: occupation lisa investment_banker || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 18 1
Checking fact: occupation lisa investment_banker || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 18 2
Checking fact: occupation lisa investment_banker || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
: 19 0
Checking fact: lives_in lisa albuquerque || With rule: dallas  x  texas  x  
[1;31mUnification failed[0m
: 19 1
Checking fact: lives_in lisa albuquerque || With rule: houston  x  texas  x  
[1;31mUnification failed[0m
: 19 2
Checking fact: lives_in lisa albuquerque || With rule: austin  x  texas  x  
[1;31mUnification failed[0m
[1;36m
Original Query: surgeon texas 
[1;35m-- Result: --
[1;32moccupation sam surgeon 
occupation lance surgeon 
occupation charlie surgeon 
lives_in sam texas 
lives_in lance texas 
lives_in charlie texas 
[0m

--- End Of Solution Trace ---
