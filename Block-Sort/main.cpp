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
#define ULTRAVERBOSE true

using namespace std;

const string DELIMITER = "|";

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
  cout << "S: size = " << state.vCurrState.size() << "\n";
  cout << "S: size[0-2] " << state.vCurrState.at(0).size() << " " <<
          state.vCurrState.at(1).size() << " " <<
          state.vCurrState.at(2).size() << endl;
  for( auto s : state.vCurrState ) {
    cout << "S: " << s << "\n";
  }
  #endif

  vector< pair<int, char> > candidates;
  pair<int, char> p;

  for( int i = 0; i < state.vCurrState.size(); ++i ) {

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

/*
    if( state.vCurrState.at(i).front() != ' ' && state.vCurrState.at(i).back() != ' ' ) {

      p = make_pair( i, state.vCurrState.at(i).back() );
      candidates.push_back( p );

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
  for( int i = 0; i < candidatePermutations; ++i ) {

    int cIndex = candidates.at( candidateNo ).first;
    char cChar = candidates.at( candidateNo ).second;

    nextState = state.vCurrState;
    size_t pos = nextState.at( cIndex ).find( cChar );
    nextState.at( cIndex ).at( pos ) = ' ';
    //nextState.at( cIndex ).back() = ' ';  // WRONG
    if( i % state.blkPlane - 1 == 0 ) ++succNo;

    cout << "Iteration: " << i << ", candidateNo: " << candidateNo << endl;
    cout << "Candidate: " << cChar << endl;

    int succIndex = ((cIndex + 1) + i) % state.blkPlane;
    pos = nextState.at( succIndex ).find(' ');
    nextState.at( succIndex ).at( pos ) = cChar;

    #if SUPERVERBOSE
    for( auto s : nextState ) {
      cout << "S: " << s << "\n";
    }
    #endif

    successors.push_back( nextState );

    // TODO: CHECK THIS, FRRRRRAGILE
    if( i % state.blkPlane - 1 == 0 ) ++candidateNo;

  }

  return successors;

}

float heuristic( vector<string> currState, State &state ) {

  float hofn = 0.0;
  int score = 0;
  vector<string> goalState = state.vGoalState;

  // Counts blocks out of place & flag them
  for( int i = 0; i < currState.size(); ++i ) {

    for( int j = 0; j < currState.at(i).size(); ++j ) {

      #if ULTRAVERBOSE
      cout << "U- Current Block: " << currState.at(i).at(j);
      cout << " Goal Block: " << goalState.at(i).at(j) << endl;
      #endif

      if( currState.at(i).at(j) == ' ' ) { //&& goalState.at(i).at(j) == ' ' ) {

        score += 0;

      }

      else if( currState.at(i).at(j) != goalState.at(i).at(j) ) {

        score += 1;
        // Flag here via pair

      }

    }

  }

  // for the flagged blocks, count how many blocks are on top of them

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

  #if SUPERVERBOSE
  for( auto s : openList ) {
    cout << "Successor: " << s.first << ", hofn: " << s.second << endl;
  }
  #endif

  // Sort openList --> Finds our *best* move based on our heuristic
  sort( openList.begin(), openList.end(), secondPairSort );

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
  Node node;

  readFile( "blkchp/blkchp01", state );
  node.state = state.vCurrState;

  #if VERBOSE
  cout << "blkCount: " << state.blkCount << "\nblkPlane: " << state.blkPlane << "\n";
  cout << "currState: " << state.currState << "\n";
  cout << "goalState: " << state.goalState << "\n";
  #endif

  //char A => 65, B => 66 ... Z => 90
  //comma , => 44
  //cout << state.currState.at(0) << "\n";
  //cout << (int)( state.currState.at(0) ) << "\n";

  graphSearch( state, node );
  graphSearch( state, node );

  return( /*CSCE*/420 );

}
