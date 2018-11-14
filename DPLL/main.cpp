/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * 
 * TODO: commentRE will not match comments on the last line b/c of newline req
 * TODO: Need a way to hold truth assignments: tuple or parallel pairs or typedef TRUTHS
 *     : : Done, used Clause model in State
 * TODO: Might need a vector of KnowledgeBase to backtrack on
 * 
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <streambuf>
#include <fstream>
#include <regex>
#include <algorithm>

#define READABLE_PRINT true

using namespace std;

typedef pair<bool,char> Literal;
typedef vector<Literal> Clause;
typedef vector<Clause> KnowledgeBase;

struct State {

  unsigned int DPLLcalls = 0;
  unsigned int backtraces = 0;
  bool satisfiability = false;
  Clause model; // our truth assignments
  //vector<KnowledgeBase> KBtree // for backtracking
  vector<char> modelOptions;
  // Unit clauses
  // Pure literals

};

// TESTED
void printKB( KnowledgeBase &KB ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    #if READABLE_PRINT
    cout << i << ": ";
    #endif

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

      #if READABLE_PRINT
      if( KB.at(i).at(j).first == false ) cout << "-";
      else cout << " ";
      cout << KB.at(i).at(j).second;
      if( j < KB.at(i).size() - 1 ) cout << " v ";
      #else
      cout << "KB[ " << i << " ]" << "[ " << j << " ]: ";
      cout << KB.at(i).at(j).first << " " << KB.at(i).at(j).second << "\n";
      #endif

    }

    #if READABLE_PRINT
    cout << "\n";
    #endif

  }

  cout << endl;

  return;

}

// FIXME UNTESTED
bool satCheck( KnowledgeBase &KB, State &s ) {

  // if every clause in KB is true in our model return true
  for( unsigned int i = 0; i < KB.size(); ++i ) {

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

      // Loop thru model type Clause ==> FIXME might be better as outer loop
      for( unsigned int m = 0; m < s.model.size(); ++m ) {

        if( s.model.at(i).second == KB.at(i).at(j).second ) {
          if( s.model.at(i).first != KB.at(i).at(j).first ) {

            return( false );

          }

        }

      }      

    }

  }

  return( true );

}

// TESTED
bool emptyClauseCheck( KnowledgeBase &KB ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    if( KB.at(i).empty() == true ) return( true );

  }

  return( false );

}

// AKA: resolution ==> TESTED
void unitPropogate( Literal &unitClause, KnowledgeBase &KB ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

      if( unitClause.second == KB.at(i).at(j).second ) {

        // Full clause removal ==> FIXME might not be needed
        if( unitClause.first == KB.at(i).at(j).first ) {

          KB.at(i).erase( KB.at(i).begin(), KB.at(i).end() );

        }

        // Partial clause removal
        else if( unitClause.first != KB.at(i).at(j).first ) {

          KB.at(i).erase( KB.at(i).begin() + j );

        }

      }

    }

  }

  return;

}

// FIXME UNTESTED
bool DPLL( KnowledgeBase &KB, State &s ) {

  s.DPLLcalls += 1;

  // 1: if KB is a consistent set of literals return true
  if( satCheck( KB, s ) == true ) return( true );

  // 2: if KB contains an empty clause return false
  if( emptyClauseCheck( KB ) == true ) return( false );

  // 3: for each unit clause {uc} in KB
  //      KB = unitPropagate( uc, KB )

  // 4: for each pure literal {l} in KB
  //      KB = pureLiteralAssign( l, KB )

  // 5: l = chooseLiteral( KB )

  if( s.model.empty() ) s.model.push_back( Literal( true, s.modelOptions.front() ) );
  //                                           this ^^^^ truth doesn't matter

  // FIXME wtf is this doing?
  else {

    s.model.push_back( Literal( true, s.modelOptions.at( s.model.size() - 1 ) ) );

  }

  const Literal chosenLit = s.model.back();

  // 6: return( DPLL( KB && l ) or DPLL( KB && !l ) )
  
  // if no backtrack do true of chosenLit

  // else do false of chosenLit

  // UNITPROP
  // -- Delets literals from inside a clause, bringing us closer to an empty clause
  // -- Recall empty clause means unSat

  // PURELIT
  // -- Observation that a literal occurs with only 1 polarity
  // -- Only true or only false occurances of the variable in the KB
  // -- Lets us set the pure variable to true and delete those entire clauses
  // -- brings us closer to trivially sat

  // FIXME -- PLACEHOLDER --
  return( false );

}

// TESTED
void readFile( string &problemFile, KnowledgeBase &KB, State &s ) {

  ifstream inputFile( problemFile );
  string fileString;

  inputFile.seekg( 0, ios::end );
  fileString.reserve( inputFile.tellg() );
  inputFile.seekg( 0, ios::beg );
  fileString.assign( istreambuf_iterator<char>(inputFile), istreambuf_iterator<char>() );

  regex commentRE( "#.+\\n" );
  smatch matches;

  // remove comments in file
  while( regex_search( fileString, matches, commentRE ) ) {

    fileString = matches.suffix().str();

  }

  regex clauseRE( "\\S+|\\n" );
  Clause clause;
  Literal p;

  // Build clauses from file
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

      // The following if else block identifies the set of literals we have
      if( s.modelOptions.empty() ) s.modelOptions.push_back( p.second );

      else {

        bool hasSameP = false;
        for( unsigned int i = 0; i < s.modelOptions.size(); ++i ) {
        
          if( s.modelOptions.at(i) == p.second ) { hasSameP = true; break; }

        }

        if( hasSameP == false ) s.modelOptions.push_back( p.second );

      }

    }

    fileString = matches.suffix().str();

  }

  sort( s.modelOptions.begin(), s.modelOptions.end() );

  return;

}

int main( int argc, char** argv ) {

  cout << boolalpha;

  string problemName;

  if( argc == 2 ) problemName = string( argv[1] );

  else cin >> problemName;

  problemName = "problemSet/" + problemName + ".cnf";

  State s;
  KnowledgeBase KB;
  readFile( problemName, KB, s );

  cout << "Props: ";
  for( auto w : s.modelOptions ) cout <<  w << " ";
  cout << endl;

  printKB( KB );
  Literal p = make_pair( true, 'A' );
  unitPropogate( p, KB );
  printKB( KB );
  p.second = 'B';
  unitPropogate( p, KB );
  printKB( KB );
  cout << "Empty Clause?: " << emptyClauseCheck( KB ) << endl;

  return( 0x5F3759DF );

}
