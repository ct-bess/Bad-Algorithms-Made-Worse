#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <regex>
#include <streambuf>

#define VERBOSE true
#define SUPERVERBOSE true

using namespace std;

struct State {

  int blkCount;
  int blkPlane;
  string currState;
  string goalState;

};

void readFile( string inputInputFile, State &state ) {

  ifstream inputFile( inputInputFile );
  string fileString;

  inputFile.seekg( 0, ios::end );
  fileString.reserve( inputFile.tellg() );
  inputFile.seekg( 0, ios::beg );

  fileString.assign( istreambuf_iterator<char>(inputFile), 
                     istreambuf_iterator<char>() );

  regex blkInfoRE( "(\\d+)\\s(\\d+)" );
  regex blkStatesRE( "([A-Z]+\\b)" );

  smatch matches;

  regex_search( fileString, matches, blkInfoRE );
  state.blkPlane = stoi( matches[1] );
  state.blkCount = stoi( matches[2] );

  #if SUPERVERBOSE
  for( auto m : matches ) {
    cout << "Match: " << m << "\n";
  }
  #endif

  int i = 0;
  bool currState = true;
  while( regex_search( fileString, matches, blkStatesRE ) ) {

    if ( currState ) {

      i += matches.str().size();
      if( i < state.blkCount ) state.currState += matches.str() + ",";

      else if( i == state.blkCount ) {

       state.currState += matches.str() + ",";
        currState = false;

      }

      else currState = false;

    }

    else {

      //if( i <= state.blkCount ) 
      state.goalState += matches.str() + ",";

    }

    #if SUPERVERBOSE
    cout << "Match: " << matches[1] << "\n";
    #endif

    fileString = matches.suffix().str();

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

  return 420;

}
