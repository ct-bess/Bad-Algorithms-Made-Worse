# Block Sort Readme

## Compiling:

This program was developed on Ubuntu 16.04 xenial using g++ 5.4.0

C++11 is required. 

Please use your local machine or a server like `linux.tamu.edu` via ssh.

To compile run one of the following commands:

``` sh
g++ -o main main.cpp -std=c++11
```

``` sh
make
```

## Running:

To run the program type `./main` with or without problem flags. 

To specify which problem to run, add 01 to 53. Here's some examples:

``` sh
./main

./main 01

./main 09

./main 14
```

You can also run the `ALL` script to do all 01 to 53 problems.

Type: `bash ALL.sh` to do all problems.

## Output:

When and if a solution is found a corresponding output file is generated in 
`blkchp-SolutionTraces/`

For example: `./main 01` produces `blkchp-SolutionTraces/blkchp01`

## Heuristic Description

My heuristic takes 2 things into account to generate a score:

1. How many blocks are out of place.

2. How many blocks are on top of blocks that are out of place.

For instance:

```
start state:
|ABCD
|
|

End state
|ADCB
|
|
```
Let score = 0 initially

Block A is in place so score does not change

Block B is out of place and at the top of the stack, so score = score + 1 + 0
> 1 for out of place, 0 for number of blocks on top of B

Block C is in place, score stays the same

Block D is out of place and in the middle of the stack, score = score + 1 + 2
> 1 for out of place, 2 for 2 blocks on top of block D

Therefore, the heuristic score for this examples start state is 4.

## Example Traces

#### 1

```
START STATE: |ABCDE|     |     |
GOAL  STATE: |AE   |CD   |B    |

Depth: 0, f(n) = 7
| ABCD 
| E    
|      

Depth: 1, f(n) = 5
| ABC  
| ED   
|      

Depth: 2, f(n) = 4
| AB   
| ED   
| C    

Depth: 3, f(n) = 5
| A    
| EDB  
| C    

Depth: 4, f(n) = 5
| A    
| ED   
| CB   

Depth: 5, f(n) = 5
| AD   
| E    
| CB   

Depth: 6, f(n) = 5
| ADB  
| E    
| C    

Depth: 7, f(n) = 5
| AD   
| EB   
| C    

Depth: 8, f(n) = 6
| A    
| EB   
| CD   

Depth: 9, f(n) = 5
| AB   
| E    
| CD   

Depth: 10, f(n) = 5
| ABD  
| E    
| C    

Depth: 11, f(n) = 6
| ABD  
|      
| CE   

Depth: 12, f(n) = 5
| AB   
| D    
| CE   

Depth: 13, f(n) = 5
| ABE  
| D    
| C    

Depth: 14, f(n) = 5
| AB   
| DE   
| C    

Depth: 15, f(n) = 6
| A    
| DE   
| CB   

Depth: 16, f(n) = 4
| AE   
| D    
| CB   

Depth: 17, f(n) = 3
| AEB  
| D    
| C    

Depth: 18, f(n) = 4
| AE   
| DB   
| C    

Depth: 19, f(n) = 4
| AE   
| D    
| CB   

Depth: 20, f(n) = 4
| AED  
|      
| CB   

Depth: 21, f(n) = 3
| AED  
| B    
| C    

Depth: 22, f(n) = 3
| AE   
| BD   
| C    

Depth: 23, f(n) = 3
| AEC  
| BD   
|      

Depth: 24, f(n) = 3
| AEC  
| B    
| D    

Depth: 25, f(n) = 4
| AE   
| BC   
| D    

Depth: 26, f(n) = 4
| AE   
| B    
| DC   

Depth: 27, f(n) = 4
| AEB  
|      
| DC   

Depth: 28, f(n) = 2
| AEB  
| C    
| D    

Depth: 29, f(n) = 1
| AEB  
| CD   
|      

Depth: 30, f(n) = 0
| AE   
| CD   
| B    

-- End of solution trace --

```

#### 2

```
START STATE: |A    |CB   |ED   |
GOAL  STATE: |ABCDE|     |     |

Depth: 0, f(n) = 4
| AB   
| C    
| ED   

Depth: 1, f(n) = 3
| ABC  
|      
| ED   

Depth: 2, f(n) = 1
| ABCD 
|      
| E    

Depth: 3, f(n) = 0
| ABCDE
|      
|      

-- End of solution trace --

```
