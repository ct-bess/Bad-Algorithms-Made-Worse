#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <regex>
#include <streambuf>
#include <vector>

#define VERBOSE true
#define SUPERVERBOSE true

using namespace std;

const string DELIMITER = "|";

struct State {

  int solutionAttempts;
  int blkCount;
  int blkPlane;
  float gofn;
  string currState = DELIMITER;
  string goalState = DELIMITER;
  vector<string> vCurrState;
  vector<string> vGoalState;

  //bool matches( State other ) //?
  bool goalTest() {

    if( currState == goalState ) return( true );

    else return( false );

  }

  //void print()

};

struct Node {

  State state;
  Node* parent;
  int depth;
  float fofn;
  //vector<Node*> successors()
  //bool goalTest( State &state )
  //void print()
  //void printSolution()
  //void traceback()

};

// will return vector of strings in Node --> then give succs to heuristic
void generateSuccessors( State &state ) {

  #if SUPERVERBOSE
  for( auto s : state.vCurrState ) {
    cout << "S: " << s << "\n";
  }
  #endif

  vector< pair<int, char> > candidates;
  pair<int, char> p;

  for( int i = 0; i < state.vCurrState.size(); ++i ) {

    if( state.vCurrState.at(i).front() != ' ' && state.vCurrState.at(i).back() != ' ' ) {

      p = make_pair( i, state.vCurrState.at(i).back() );
      candidates.push_back( p );

    }

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
  for( int i = 0; i < candidatePermutations; ++i ) {

    int cIndex = candidates.at( candidateNo ).first;
    char cChar = candidates.at( candidateNo ).second;

    nextState = state.vCurrState;
    nextState.at( cIndex ).back() = ' ';
    if( i % state.blkPlane == 0 ) ++succNo;

    cout << "Iteration: " << i << ", candidateNo: " << candidateNo << endl;
    cout << "succNo: " << succNo << endl;

    int succIndex = ((cIndex + 1) + i) % state.blkPlane;
    size_t pos = nextState.at( succIndex ).find(' ');
    nextState.at( succIndex ).at( pos ) = cChar;

    #if SUPERVERBOSE
    for( auto s : nextState ) {
      cout << "S: " << s << "\n";
    }
    #endif

    successors.push_back( nextState );

  }

}

float heuristic( State &state, Node &node ) {

  float hofn = 0.0;
  regex blkOrderRE( DELIMITER + "(.+)" + DELIMITER );

  smatch matches;
  string currState = state.currState;

  while( regex_search( currState, matches, blkOrderRE ) ) {

    currState = matches.suffix().str();

  }

  //generate successors

  //calc hofn based on:
  //>> blks out of order
  //>> stack on blks out of order

  return hofn;

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
    cout << "Match: " << m << "\n";
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
    cout << "Token: " << token << " -- Size: " << token.size() << endl;
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

  readFile( "blkchp/blkchp01", state );

  #if VERBOSE
  cout << "blkCount: " << state.blkCount << "\nblkPlane: " << state.blkPlane << "\n";
  cout << "currState: " << state.currState << "\n";
  cout << "goalState: " << state.goalState << "\n";
  #endif

  //char A => 65, B => 66 ... Z => 90
  //comma , => 44
  //cout << state.currState.at(0) << "\n";
  //cout << (int)( state.currState.at(0) ) << "\n";

  generateSuccessors( state );

  return( 420 );

}
