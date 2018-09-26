/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * file: main.cpp
 * author: Connor Bessell
 * comments: It's all one file... Needs house keeping and grooming
 *
 * compile: g++ -std=c++11 -o main main.cpp
 * run: ./main
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <regex>
#include <streambuf>
#include <vector>
#include <algorithm>

// Because I'm bad at GDB
#define VERBOSE true
#define SUPERVERBOSE false
#define ULTRAVERBOSE false

using namespace std;

const string DELIMITER = "|";
const int SOLUTION_CUTOFF = 2 * 5000;

struct Node {

  vector<string> state;
  Node* parent;
  int depth = 0;
  float fofn;

};

struct State {

  int solutionAttempts = 0;
  int blkCount;
  int blkPlane;
  float gofn = 0.0;
  string currState = DELIMITER;
  string goalState = DELIMITER;
  vector<string> vCurrState;
  vector<string> vGoalState;
  vector<Node> succTree;

};

vector< vector<string> > generateSuccessors( State &state ) {

  #if SUPERVERBOSE
  for( auto s : state.vCurrState ) {
    cout << "S: " << s << "\n";
  }
  #endif

  vector< pair<int, char> > candidates;
  pair<int, char> p;

  // Find candidate blocks to move
  for( int i = 0; i < state.vCurrState.size(); ++i ) {

    regex blkStackRE( "(\\w)\\b" );

    smatch matches;

    if ( regex_search( state.vCurrState.at(i), matches, blkStackRE ) ) {

      string s = matches[1];
      char sec = s.front();
      p = make_pair( i, sec );
      candidates.push_back( p );

    }

  }

  if( candidates.size() <= 0 ) {

    cout << "Candidates for successors are 0, consider fixing your program.\n";
    exit(-1);

  }

  #if SUPERVERBOSE
  for( int i = 0; i < candidates.size(); ++i ) {

    cout << "Candidate: " << candidates.at(i).first << ", " << candidates.at(i).second;
    cout << endl;

  }
  #endif

  vector< vector<string> > successors;
  vector<string> nextState;

  // Possible permutations of candidates
  int succNo = -1;
  int candidateNo = 0;
  int candidatePermutations = candidates.size() * (state.blkPlane - 1);
  int permuteMod = state.blkPlane - 1;
  vector<int> cIndexMem;
  for( int i = 0; i < candidatePermutations; ++i ) {

    int cIndex = candidates.at( candidateNo ).first;
    char cChar = candidates.at( candidateNo ).second;

    nextState = state.vCurrState;
    size_t pos = nextState.at( cIndex ).find( cChar );
    nextState.at( cIndex ).at( pos ) = ' ';
    //nextState.at( cIndex ).back() = ' ';  // WRONG
    if( i % state.blkPlane - 1 == 0 ) ++succNo;

    #if SUPERVERBOSE
    cout << "S: Iteration: " << i << ", candidateNo: " << candidateNo << endl;
    cout << "S: Candidate: " << cChar << ", totPermutations: " << candidatePermutations << endl;
    #endif

    // -- Old bad way: only works for stack/plane index 0
    //int succIndex = ((cIndex + 1) + i) % state.blkPlane;
    //pos = nextState.at( succIndex ).find(' ');
    //nextState.at( succIndex ).at( pos ) = cChar;

    // Move successors to an index that has yet to be successored
    int succIndex = 0;
    bool insertedSucc = false;
    if( cIndexMem.empty() == false ) {

      int j = 0;
      while( j <= state.blkPlane - 1 ) {

        for( int cI : cIndexMem ) {

          if( cI != j && j != cIndex ) {
            pos = nextState.at( j ).find(' ');
            nextState.at( j ).at( pos ) = cChar;
            succIndex = cI;
            insertedSucc = true;
            break;
          }

        }

        if( insertedSucc == true ) break;

        ++j;

      }

    }

    // Successor has not been added yet, can be added almost anywhere
    else {

      //int succIndex = ((cIndex + 1) + i) % state.blkPlane;
      succIndex = ((cIndex + 1) + 0) % state.blkPlane;
      pos = nextState.at( succIndex ).find(' ');
      nextState.at( succIndex ).at( pos ) = cChar;

    }

    cIndexMem.push_back( succIndex );

    #if SUPERVERBOSE
    for( auto s : nextState ) {
      cout << "S: " << s << "\n";
    }
    #endif

    successors.push_back( nextState );

    // why
    if( i % permuteMod == 1 ) { 

      ++candidateNo;
      cIndexMem.clear();

    }

  }

  return successors;

}

float heuristic( vector<string> currState, State &state ) {

  // The general idea:
  // +1 to score if the block is out of place
  // +1 to score for every block on top of out of place block

  float hofn = 0.0;
  int score = 0;
  vector<string> goalState = state.vGoalState;

  pair<int, int> p;
  vector< pair<int, int> > misplacedBlks;

  // Counts blocks out of place & flag them
  for( int i = 0; i < currState.size(); ++i ) {

    for( int j = 0; j < currState.at(i).size(); ++j ) {

      #if ULTRAVERBOSE
      cout << "U: Current Block: " << currState.at(i).at(j);
      cout << " Goal Block: " << goalState.at(i).at(j) << endl;
      #endif

      if( currState.at(i).at(j) == ' ' ) { //&& goalState.at(i).at(j) == ' ' ) {

        score += 0;

      }

      else if( currState.at(i).at(j) != goalState.at(i).at(j) ) {

        // +1 for block out of place
        score += 1;

        // +1 per block on top of out of place block
        string stackInQuestion = currState.at(i);
        char blkInQuestion = currState.at(i).at(j);
        int blkPos = stackInQuestion.find( blkInQuestion );
        int spacePos = stackInQuestion.find( ' ' );

        // Empty stack
        if( stackInQuestion.front() == stackInQuestion.back() ) {
          score += 0;
        }

        // Top of full stack
        else if( blkPos == state.blkCount - 1 ) {
          score += 0;
        }

        // Top of non full stack
        else if( blkPos == spacePos - 1 ) {
          score += 0;
        }

        // Full middle stack
        else if( spacePos < 0 ) {
          score += (state.blkCount - 1) - blkPos;
        }

        // Middle of stack
        else {
          score += spacePos - blkPos - 1;
        }

        #if ULTRAVERBOSE
        cout << "U: -- STACK: " << stackInQuestion << " -- " << score << "\n";
        cout << "U: -- blk: " << blkInQuestion << ", blkPos: " << blkPos 
             << ", spacePos: " << spacePos << "\n";
        #endif

      }

      #if ULTRAVERBOSE
      cout << "U: -- current score = " << score << "\n";
      #endif

    }

  }

  hofn = (float)(score);

  return hofn;

}

bool secondPairSort( const pair<int, float> &p1, const pair<int, float> &p2 ) {
  return( p1.second < p2.second );
}

// A* implementation
void graphSearch( State &state, Node &node ) {

  // loop thru successors
  // --> Calculate heuristic per successor
  // --> ** Keep graph search sorted by f(n) = g(n) + h(n) **
  //     Meaning explore the succ that costs the least f(n) 

  // When we find our candidate
  // --> Update current state
  // --> Make link new node with parent
  // --> update depth of new node
  // Then do it again, ThAt's GoOd

  vector< vector<string> > successors = generateSuccessors( state );

  vector< pair<int, float> > openList;
  pair<int, float> p;
  
  // Calculate herustics for openList
  for( int i = 0; i < successors.size(); ++i ) {

    int succIndex = i;
    float fofn = heuristic( successors.at(i), state ) + state.gofn;
    p = make_pair( succIndex, fofn );
    openList.push_back(p);

  }

  // Sort openList --> Finds our *best* move based on our heuristic
  sort( openList.begin(), openList.end(), secondPairSort );

  #if SUPERVERBOSE
  for( auto s : openList ) {
    cout << "S: Successor: " << s.first << ", hofn: " << s.second << endl;
  }
  #endif

  if( openList.empty() == true ) {
    cout << "-- Open list empty\n";
    exit(-1);
  }

  // Check previous states so that we don't traverse the same state
  int j = 0;
  for( int i = 0; i < state.succTree.size(); ++i ) {

    vector<string> pathInQuestion = successors.at( openList.at(j).first );
    vector<string> previousPaths = state.succTree.at(i).state;

    if( pathInQuestion == previousPaths ) { 
      ++j;
      // NO BREAK: we need to count ALL THE WAY DOWN!
      //break;
    }

  }

  // Safety net
  j = j % openList.size();

  // jth element of sorted openList is what we shall explore
  // -- typically the 1st element but not always
  node.state = successors.at( openList.at(j).first );
  node.depth = state.succTree.size();

  node.fofn = openList.at(j).second;

  state.succTree.push_back( node );
  state.solutionAttempts += 1;

  // Print chosen node if flagged:
  #if VERBOSE
  cout << "Depth: " << node.depth << " f(n) = " << node.fofn << "\n";
  for( auto chosenPath : node.state ) {
    cout << "| " << chosenPath << "\n";
  }
  #endif

  // AND dont forget to update the board state!
  state.vCurrState = node.state;

  return;

}

void readFile( string inputInputFile, State &state ) {

  ifstream inputFile( inputInputFile );
  string fileString;

  // whole input file to string
  inputFile.seekg( 0, ios::end );
  fileString.reserve( inputFile.tellg() );
  inputFile.seekg( 0, ios::beg );
  fileString.assign( istreambuf_iterator<char>(inputFile), istreambuf_iterator<char>() );

  regex blkInfoRE( "(\\d+)\\s(\\d+)" );

  smatch matches;

  regex_search( fileString, matches, blkInfoRE );

  if( matches.size() != 3 ) cout << "-- FILE YEETED\n";

  state.blkPlane = stoi( matches[1] );
  state.blkCount = stoi( matches[2] );

  #if SUPERVERBOSE
  for( auto m : matches ) {
    cout << "S: Match: " << m << "\n";
  }
  #endif

  fileString = matches.suffix().str();
  fileString.erase( 0, 1 );

  // Build states
  string stateDelimiter = "\n";
  string token;
  size_t pos = 0;
  int i = 0;
  while( (pos = fileString.find(stateDelimiter)) != string::npos ) {

    token = fileString.substr( 0, pos );

    // Pad delimiter bounds to make uniform strings
    for( int sizeFactor = token.size(); sizeFactor < state.blkCount; ++sizeFactor ) {
      token += " ";
    }

    #if SUPERVERBOSE
    cout << "S: Token: " << token << " -- Size: " << token.size() << endl;
    #endif
    fileString.erase( 0, pos + stateDelimiter.length() );

    if( i >= state.blkPlane ) { 

      state.vGoalState.push_back( token );
      state.goalState += token + DELIMITER;

    }
    else { 

      state.vCurrState.push_back( token );
      state.currState += token + DELIMITER;

    }

    ++i;

  }

  return;

}

int main( int argc, char** argv ) {

  string argName; 

  if( argc == 2 ) argName = string( argv[1] );

  else { 

    cout << "No command line argument found.\n Input file 01 to 53: ";
    cin >> argName;

  }

  string fileName = "blkchp/blkchp" + argName;

  State state;
  Node node;

  readFile( fileName, state );
  node.state = state.vCurrState;

  #if VERBOSE
  cout << "blkCount: " << state.blkCount << "\nblkPlane: " << state.blkPlane << "\n";
  cout << "currState: " << state.currState << "\n";
  cout << "goalState: " << state.goalState << "\n";
  #endif

  while( state.vCurrState != state.vGoalState ) {

    graphSearch( state, node );

    if( state.solutionAttempts > SOLUTION_CUTOFF ) {

      cout << "Too many solution attempts, consider a different heuristic for this one\n";
      cout << "-- Error Code: Brian Maxon vs Mark Wolf round 2\n\n";
      break;

    }

  }

  if( state.vCurrState == state.vGoalState ) {

    cout << "!!-- Solution found --!!\n";

    string myFile = "blkchp-SolutionTraces/blkchp" + argName;

    cout << "-- Solution in: " << myFile << " --\n";

    ofstream outputFile;
    outputFile.open( myFile );

    outputFile << "START STATE: " + state.currState << "\n";
    outputFile << "GOAL  STATE: " + state.goalState << "\n";

    for( int i = 0; i < state.succTree.size(); ++i ) {

      vector<string> currState = state.succTree.at(i).state;
      int depth = state.succTree.at(i).depth;
      float fofn = state.succTree.at(i).fofn;
      
      outputFile << "\nDepth: " << depth << ", f(n) = " << fofn << "\n";
      for( auto s : currState ) {
        outputFile << "| " << s << "\n";
      }

    }

    outputFile << "\n-- End of solution trace --\n";

  }

  return( /*CSCE*/420 );

}
