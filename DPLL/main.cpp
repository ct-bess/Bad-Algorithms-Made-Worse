/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 * TODO: commentRE will not match comments on the last line b/c of newline req
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <streambuf>
#include <fstream>
#include <regex>

using namespace std;

typedef vector< vector< pair<bool,char> > > KnowledgeBase;
typedef vector< pair<bool,char> > Clause;
typedef pair<bool,char> Literal;

void printKB( KnowledgeBase &KB ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

      cout << "KB[ " << i << " ]" << "[ " << j << " ]: ";
      cout << KB.at(i).at(j).first << " " << KB.at(i).at(j).second << "\n";

    }

  }

  cout << endl;

  return;

}

void readFile( string &problemFile, KnowledgeBase &KB ) {

  ifstream inputFile( problemFile );
  string fileString;

  inputFile.seekg( 0, ios::end );
  fileString.reserve( inputFile.tellg() );
  inputFile.seekg( 0, ios::beg );
  fileString.assign( istreambuf_iterator<char>(inputFile), istreambuf_iterator<char>() );

  regex commentRE( "#.+\\n" );
  smatch matches;

  // remove comments
  while( regex_search( fileString, matches, commentRE ) ) {

    fileString = matches.suffix().str();

  }

  regex clauseRE( "\\S+|\\n" );
  Clause clause;
  Literal p;

  // Build clauses
  while( regex_search( fileString, matches, clauseRE ) ) {

    string matchedLit = matches[0];

    // Full clause on newline
    if( matchedLit == "\n" ) { 

      KB.push_back( clause );
      clause.clear();

    }

    // Continue adding literals
    else {

      // Negated case = "-{literal}"
      if( matchedLit.size() == 2 ) { p = make_pair( false, matchedLit[1] ); }

      else if( matchedLit.size() == 1 ) { p = make_pair( true, matchedLit[0] ); }

      else { cout << "-- ERROR: Malformed literal\n"; }

      // This should be in both upper if & else if blocks
      clause.push_back( p );

    }

    fileString = matches.suffix().str();

  }

  return;

}

int main( int argc, char** argv ) {

  string problemName;

  if( argc == 2 ) problemName = string( argv[1] );

  else cin >> problemName;

  problemName = "problemSet/" + problemName + ".cnf";

  KnowledgeBase KB;
  readFile( problemName, KB );
  printKB( KB );

  return( 0x5F3759DF );

}
