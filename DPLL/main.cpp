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
  Clause pureSymbols;
  //pair<vector<unsigned int>,Clause> pureSymbols;
  vector<KnowledgeBase> KBtree; // for backtracking
  vector<char> modelOptions;
  // Unit clauses
  // Pure literals

};

// TESTED
void printKB( KnowledgeBase &KB ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    #if READABLE_PRINT
    cout << i << ": (";
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
    cout << " )\n";
    #endif

  }

  cout << endl;

  return;

}

// FIXME UNTESTED
bool satCheck( KnowledgeBase &KB, State s ) {

  cout << "satCheck\n";
  Clause unpureModel = s.model;

  for( unsigned int n = 0; n < s.pureSymbols.size(); ++n ) {
    for( unsigned int m = 0; m < unpureModel.size(); ++m ) {
      if( unpureModel.at(m).second == s.pureSymbols.at(n).second ) { 
        //cout << "Found Pure\n";
        unpureModel.erase( unpureModel.begin() + m );
      }
    }
  }

  if( unpureModel.empty() ) return( false );

  // Loop thru model type Clause 
  for( unsigned int m = 0; m < unpureModel.size(); ++m ) {

    // if every clause in KB is true in our model return true
    for( unsigned int i = 0; i < KB.size(); ++i ) {

      for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

        if( unpureModel.at(m).second == KB.at(i).at(j).second ) {
          if( unpureModel.at(m).first != KB.at(i).at(j).first ) {
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

  cout << "emptyClauseCheck\n";

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    if( KB.at(i).empty() == true ) return( true );

  }

  return( false );

}

// AKA: resolution ==> TESTED
void unitPropogate( const Literal &unitClause, KnowledgeBase &KB, bool pureSym ) {

  // UNIT PROPOGATION
  // -- Delets literals from inside a clause, bringing us closer to an empty clause
  // -- Recall empty clause means unSat

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

      if( unitClause.second == KB.at(i).at(j).second ) {

        // Pure symbol ==> full clause removal
        if( pureSym == true ) { 
          KB.at(i).erase( KB.at(i).begin(), KB.at(i).end() );
          KB.at(i).push_back( Literal( true, '*' ) );
        }

        // regular unit clause ==> partial removal
        else { // FIXME        vv
          if( unitClause.first == KB.at(i).at(j).first )
            KB.at(i).erase( KB.at(i).begin() + j );
        }

        /*
        // Full clause removal ==> FIXME might not be needed
        if( unitClause.first == KB.at(i).at(j).first ) {

          KB.at(i).erase( KB.at(i).begin(), KB.at(i).end() );

        }

        // Partial clause removal
        else if( unitClause.first != KB.at(i).at(j).first ) {

          KB.at(i).erase( KB.at(i).begin() + j );

        }
        */

      }

    }

  }

  return;

}

Literal findUnitClause( KnowledgeBase &KB, State &s ) {

  // UNIT CLAUSE (heuristic)
  // -- Observation that a clause contains 1 literal
  // -- The model will define new unit clauses throughout DPLL
  // -- e.g. if our model says B = true
  // -- -- the clause (-B v -C) simplifies to (-C) ==> a unit clause
  // -- -- thus we return C = false

  // model = type Clause ==> vector<Literal> 

  // 1: check for clause size == 1
  for( unsigned int i = 0; i < KB.size(); ++i ) {

    if( KB.at(i).empty() ) break;;

    if( KB.at(i).front().second == '*' ) continue;

    if( KB.at(i).size() == 1 ) return( KB.at(i).at(0) );
  
  }

  // 2: use model to identify a unit clause
  //  : : NOTE this might be done by calling unitPropogate on a temp KB
  //  : : BUT only using the partial clause removal case
  /* FIXME OMIT FOR NOW
  for( unsigned int i = 0; i < KB.size(); ++i ) {

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {


    }
  
  }
  */

  // on failure
  return( Literal( false, '!' ) );

}

// TESTED but wtf...
Literal findPureSymbol( KnowledgeBase &KB, State &s ) {

  // PURE SYMBOL / LITERAL (heuristic)
  // -- Observation that a literal occurs with only 1 polarity
  // -- Only true or only false occurances of the variable in the KB
  // -- Lets us set the pure variable to true and delete those entire clauses
  // -- brings us closer to trivially sat

  for( unsigned int m = 0; m < s.modelOptions.size(); ++m ) {

    const char symbol = s.modelOptions.at(m);

    bool setPolarity = false;
    bool polarity;
    bool pureSymbolFound = true;

    for( unsigned int i = 0; i < KB.size(); ++i ) {

      for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

        if( KB.at(i).at(j).second == symbol ) {

          if( setPolarity == false ) {
            polarity = KB.at(i).at(j).first;
            setPolarity = true;
            continue;
          }

          if( KB.at(i).at(j).first != polarity ) {
            pureSymbolFound = false;
            break;
          }

        }

      }

    }

    if( pureSymbolFound == true ) {
      return( Literal( polarity, symbol ) );
    }

  }

  // on failure
  return( Literal( false, '!' ) );

}

// FIXME UNTESTED
bool DPLL( KnowledgeBase &KB, State &s ) {

  s.DPLLcalls += 1;
  s.KBtree.push_back( KB );

  cout << "Model: { ";
  for( unsigned int i = 0; i < s.model.size(); ++i ) {
    if( s.model.at(i).first == false ) cout << "-";
    else cout << " ";
    cout << s.model.at(i).second << " ";
  }
  cout << " }" << endl;

  // 1: if KB is a consistent set of literals return true
  if( satCheck( KB, s ) == true ) return( true );

  // 2: if KB contains an empty clause return false
  if( emptyClauseCheck( KB ) == true ) return( false );

  // 3: Fine Pure Symbol
  //  : : if we found 1, unitPropogate with pureSymbol BUT only delet the pure symbol
  //  : : dont delet the whole clause that pure symbol is in.
  //  : : mark the pure symbol = true in our model
  //  : : return DPLL()
  const Literal pureSymbol = findPureSymbol( KB, s );

  // meaning it found a pure symbol
  if( pureSymbol.second != '!' ) {

    // Remove from model options:
    for( unsigned int i = 0; i < s.modelOptions.size(); ++i ) {
      if( s.modelOptions.at(i) == pureSymbol.second ) {
        s.modelOptions.erase( s.modelOptions.begin() + i );
      }
    }

    cout << "Pure Symbol: " << pureSymbol.first << " " << pureSymbol.second << "\n";
    s.model.push_back( pureSymbol );
    s.pureSymbols.push_back( pureSymbol );
    unitPropogate( pureSymbol, KB, true );
    printKB( KB );
    return( DPLL( KB, s ) );

  }

  // 4: Find Unit Clause
  //  : : Same as pure symbol case, but now for a unit clause
  //  : : return DPLL() after the unit propogation

  const Literal unitClause = findUnitClause( KB, s );

  if( unitClause.second != '!' ) {

    // Remove from model options:
    for( unsigned int i = 0; i < s.modelOptions.size(); ++i ) {
      if( s.modelOptions.at(i) == unitClause.second ) {
        s.modelOptions.erase( s.modelOptions.begin() + i );
      }
    }

    cout << "Unit Clause: " << unitClause.first << " " << unitClause.second << "\n";
    s.model.push_back( unitClause );
    unitPropogate( unitClause, KB, false );
    printKB( KB );
    return( DPLL( KB, s ) );

  }

  // 5: else choose a literal in model options that hasnt been chosen yet

  if( s.model.empty() ) s.model.push_back( Literal( true, s.modelOptions.front() ) );
  //                                           this ^^^^ truth doesn't matter

  else {

    // Use the next unused symbol
    //s.model.push_back( Literal( true, s.modelOptions.at( s.model.size() - 1 ) ) );
    s.model.push_back( Literal( true, s.modelOptions.front() ) );

  }

  const Literal chosenLit = s.model.back();
  //s.model.push_back( chosenLit ); // allready in

  // Remove from model options:
  for( unsigned int i = 0; i < s.modelOptions.size(); ++i ) {
    if( s.modelOptions.at(i) == chosenLit.second ) {
      s.modelOptions.erase( s.modelOptions.begin() + i );
    }
  }

  // 6: return( DPLL( KB && l ) or DPLL( KB && !l ) )
  //  : : FIXME backtracking

  cout << "Chose: " << chosenLit.first << " " << chosenLit.second << "\n";
  unitPropogate( chosenLit, KB, false );
  printKB( KB );
  return( DPLL( KB, s ) );

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

  cout << "Knowledge Base\nSymbols: ";
  for( auto w : s.modelOptions ) cout << w << " ";
  cout << endl;

  printKB( KB );

  s.satisfiability = DPLL( KB, s );

  cout << "Satisfiable? : " << s.satisfiability << endl;

  /*
  Literal ps = findPureSymbol( KB, s );
  cout << "PureLit: " << ps.first << " " << ps.second << endl;

  Literal p = make_pair( true, 'A' );
  unitPropogate( p, KB );
  printKB( KB );
  p.second = 'B';
  unitPropogate( p, KB );
  printKB( KB );
  cout << "Empty Clause?: " << emptyClauseCheck( KB ) << endl;
  */

  return( 0x5F3759DF );

}
