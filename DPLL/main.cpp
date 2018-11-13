/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 * TODO: commentRE will not match comments on the last line b/c of newline req
 * TODO: Need a way to hold truth assignments: tuple or parallel pairs or typedef TRUTHS
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

typedef pair<bool,char> Literal;
typedef vector<Literal> Clause;
typedef vector<Clause> KnowledgeBase;

struct State {

  unsigned int DPLLcalls = 0;
  unsigned int backtraces = 0;
  bool satisfiability = false;
  Clause truthAssignments;

};

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

bool satCheck( KnowledgeBase &KB ) {

  // -- PLACEHOLDER -- 
  return( true );

}

bool emptyClauseCheck( KnowledgeBase &KB ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    if( KB.at(i).empty() == true ) return( true );

  }

  return( false );

}

// AKA: resolution
void unitPropogate( Literal &unitClause, KnowledgeBase &KB ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

      if( unitClause.second == KB.at(i).at(j).second ) {
        if( unitCluase.first != KB.at(i).at(j).first ) {

          KB.at(i).erase( KB.begin() + j );

        }

      }

    }

  }

  return;

}

bool DPLL( KnowledgeBase &KB ) {

  // if KB is a consistent set of literals return true
  if( satCheck( KB ) == true ) return( true );

  // if KB contains an empty clause return false
  if( emptyClauseCheck( KB ) == true ) return( false );

  // Store unit clauses
  // Store pure literals

  // for each unit clause {uc} in KB
  //   KB = unitPropagate( uc, KB )
  // for each pure literal {l} in KB
  //   KB = pureLiteralAssign( l, KB )
  // l = chooseLiteral( KB )
  // return( DPLL( KB && l ) or DPLL( KB && !l ) )

  // UNITPROP
  // -- Delets literals from inside a clause, bringing us closer to an empty clause
  // -- Recall empty clause means unSat

  // PURELIT
  // -- Observation that a literal occurs with only 1 polarity
  // -- Only true or only false occurances of the variable in the KB
  // -- Lets us set the pure variable to true and delete those entire clauses
  // -- brings us closer to trivially sat

  // -- PLACEHOLDER --
  return( false );

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

      else { cout << "-- ERROR: Malformed literal\n"; exit(0xF); }

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
