[1;33mProgram start:[1;36m -- input "q" to quit[0m
# Try query: "mortal legend" --> I miss billy :'(
# facts:
((wrestler Billy_Herrington))
((man Billy_Herrington))
((man socrates))
# rules:
((man ?m) (mortal ?m))
((wrestler ?m) (legend ?m))
Parsed facts:
wrestler Billy_Herrington 
man Billy_Herrington 
man socrates 
Parsed rules:
man ?m mortal ?m 
wrestler ?m legend ?m 
[1;35mQuery: mortal[0m
Rule in question: man ?m mortal ?m 
Adding rule: man ?m mortal ?m 
Rule in question: wrestler ?m legend ?m 
: 0 0
Checking fact: wrestler Billy_Herrington || With rule: man  m  mortal  m  
[1;31mUnification failed[0m
: 1 0
Checking fact: man Billy_Herrington || With rule: man  m  mortal  m  
[1;32mUnification Success: man Billy_Herrington  && mortal[0m
: 2 0
Checking fact: man socrates || With rule: man  m  mortal  m  
[1;32mUnification Success: man socrates  && mortal[0m
[1;35mQuery: legend[0m
Rule in question: man ?m mortal ?m 
Rule in question: wrestler ?m legend ?m 
Adding rule: wrestler ?m legend ?m 
: 0 0
Checking fact: wrestler Billy_Herrington || With rule: wrestler  m  legend  m  
[1;32mUnification Success: wrestler Billy_Herrington  && legend[0m
: 1 0
Checking fact: man Billy_Herrington || With rule: wrestler  m  legend  m  
[1;31mUnification failed[0m
: 2 0
Checking fact: man socrates || With rule: wrestler  m  legend  m  
[1;31mUnification failed[0m
[7mInput a Query ("q" to quit):[0m [1;36m
Original Query: mortal legend 
[1;35m-- Result: --
[1;32mBilly_Herrington mortal 
[0m

--- End Of Solution Trace ---
