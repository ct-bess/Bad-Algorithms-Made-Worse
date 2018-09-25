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

#define VERBOSE true
#define SUPERVERBOSE true
#define ULTRAVERBOSE false

using namespace std;

const string DELIMITER = "|";
const int SOLUTION_CUTOFF = 1000;

struct Node {

  vector<string> state;
  Node* parent;
  int depth = 0;
  float fofn;
  //vector< vector<string> > successors;
  //vector<Node*> successors;
  //bool goalTest( State &state )
  //void print()
  //void printSolution()
  //void traceback()

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
  //bool matches( State other ) //?
  /*
  bool goalTest() {

    if( currState == goalState ) return( true );

    else return( false );

  }
  */
  //void print()

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

    /*
    //           or   < state.blkPlane
    for( int j = 0; j < state.vCurrState.at(i).size() - 1; ++j ) {

      if( state.vCurrState.at(i).at(j) != ' ' && state.vCurrState.at(i).at(j+1) == ' ' ){

        p = make_pair( i, state.vCurrState.at(i).at(j) );
        candidates.push_back( p );

      }

      else if( state.vCurrState.at(i).front() != ' ' && state.vCurrState.at(i).back() != ' ' ) {

        p = make_pair( i, state.vCurrState.at(i).back() );
        candidates.push_back( p );

      }

    }
    */

  }

  if( candidates.size() <= 0 ) {

    cout << "Candidates for successors are 0, consider fixing your program.\n";
    exit(-1);

  }

  for( int i = 0; i < candidates.size(); ++i ) {

    cout << "Candidate: " << candidates.at(i).first << ", " << candidates.at(i).second;
    cout << endl;

  }

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
    cout << "S: Candidate: " << cChar << endl;
    #endif

    int succIndex = ((cIndex + 1) + i) % state.blkPlane;
    pos = nextState.at( succIndex ).find(' ');
    nextState.at( succIndex ).at( pos ) = cChar;

/*
    if( cIndexMem.empty() == false ) {

      for( int succIndex = 0; succIndex < state.blkPlane - 1; ++succIndex ) {

        // Find an candidate index that hasent been used yet for our successor
        for( int k = 0; k < cIndexMem.size(); ++k ) {

          if( succIndex != cIndexMem.at(k) ) { 
            pos = nextState.at( succIndex ).find(' ');
            nextState.at( succIndex ).at( pos ) = cChar;
            break;
          }

        }

      }

    }

    else {

      int succIndex = ((cIndex + 1) + i) % state.blkPlane;
      pos = nextState.at( succIndex ).find(' ');
      nextState.at( succIndex ).at( pos ) = cChar;

    }
*/

    cIndexMem.push_back( cIndex );

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

        score += 1;
        // Flag here via pair
        p = make_pair( i, j );
        misplacedBlks.push_back( p );

      }

    }

  }

  // for the flagged blocks, count how many blocks are on top of them
  for( int i = 0; i < misplacedBlks.size(); ++i ) {

    int blk = misplacedBlks.at(i).second;
    int plane = misplacedBlks.at(i).first;
    //size_t pos = currState.at(plane).find(' ');

    // Loop thru current stack
    int j = currState.at(plane).size() - 1;
    for(;;) {

      if( j == -1 ) break;

      // Top of the stack case
      else if( currState.at(plane).back() == currState.at(plane).at(blk) ) break;

      else if( currState.at(plane).at(j) == currState.at(plane).at(blk) ) break;


      --j;

    }

    score += (state.blkCount - j + 1);

  }

  hofn = (float)(score);

  return hofn;

}

bool secondPairSort( const pair<int, float> &p1, const pair<int, float> &p2 ) {
  return( p1.second < p2.second );
}

// A* implementation
void graphSearch( State &state, Node &node ) {

  vector< vector<string> > successors = generateSuccessors( state );

  // loop thru successors
  // --> Calculate heuristic per successor
  // --> ** Keep graph search sorted by f(n) = g(n) + h(n) **
  //     Meaning explore the succ that costs the least f(n) 

  // When we find our candidate
  // --> Update current state
  // --> Make link new node with parent
  // --> update depth of new node
  // Then do it again, ThAt's GoOd

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

  // 1st element of sorted openList is what we shall explore
  node.state = successors.at( openList.at(0).first );
  node.depth = state.succTree.size();
  node.fofn = openList.at(0).second;

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

  if( matches.size() != 3 ) cout << "-- I/O YEETED\n";

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

int main( void ) {

  State state;
  Node node;

  readFile( "blkchp/blkchp01", state );
  node.state = state.vCurrState;

  #if VERBOSE
  cout << "blkCount: " << state.blkCount << "\nblkPlane: " << state.blkPlane << "\n";
  cout << "currState: " << state.currState << "\n";
  cout << "goalState: " << state.goalState << "\n";
  #endif

  while( state.vCurrState != state.vGoalState ) {

    graphSearch( state, node );

    if( state.solutionAttempts > SOLUTION_CUTOFF ) {

      cout << "Too many solution attempts, consider a better heuristic...\n";
      cout << "-- Error Code: Brian Maxon vs Mark Wolf round 2\n\n";
      break;

    }

  }

  if( state.vCurrState == state.vGoalState ) {

    cout << "Solution found! Now print it!\n";
    //state.succTree

  }

  return( /*CSCE*/420 );

}
