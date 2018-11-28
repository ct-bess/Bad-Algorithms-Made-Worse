#include "Expr.hpp" // ??????????????????????????????????????????????????????????????
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

//#define EOL '\n'

using namespace std;

typedef pair<string, string> Fact;
typedef vector<Fact> FactBin;

float FastInvSqrt( float x ) {

  float xhalf = 0.5f * x;
  int i = *(int*) &x;
  i = 0x5f3759df - ( i >> 1 );
  x = *(float*) &i;
  x = x * ( 1.5f - ( xhalf * x * x ) );
  return x;

}

int main( int argc, char** argv ){

  cout << boolalpha;

  string problemFile;

  if( argc == 2 ) problemFile = string( argv[1] );

  else {

    cout << "Availible problem files:\n";
    system( "ls -1 problemSet/ | grep -E *.kb" );
    cout << "Input a file (don't include \".kb\"): ";
    cin >> problemFile;

  }

  // --- Read File --- //
  problemFile = "problemSet/" + problemFile + ".kb";

  ifstream inputFile( problemFile );
  string fileString;
  inputFile.seekg( 0, ios::end );
  fileString.reserve( inputFile.tellg() );
  inputFile.seekg( 0, ios::beg );
  fileString.assign( istreambuf_iterator<char>(inputFile), istreambuf_iterator<char>() );

  cout << fileString;

  smatch matches;

  regex ruleRE( "(\\(.+)(?=#)|(\\(.+)" );

  while( regex_search( fileString, matches, ruleRE ) ) {

    cout << "Rule match: " << matches[0] << EOL;
    fileString = matches.suffix().str();

  }

  cout << "Final: " << fileString;

  return( 0x5F3759DF );

}
