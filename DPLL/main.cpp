/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * 
 * TODO: commentRE will not match comments on the last line b/c of newline req
 * TODO: commentRE removes CNF terms that are in between commented lines
 * TODO: commentRE ignores commented line with no text
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
  unsigned int backtracks = 0;
  unsigned int possibleBacktracks;
  bool satisfiability = false;
  vector<char> modelOptions;
  vector<char> modelOptionsRecovery;
  Clause model; 
  Clause pureSymbols;
  vector<KnowledgeBase> KBTree; // for backtracking
  KnowledgeBase modelTree;
  KnowledgeBase pureSymbolsTree; // do i really need this?

};

ofstream outputFile;

void openFile( string myFile ) {
  outputFile.open( myFile );
}

// TESTED
void printKB( KnowledgeBase &KB ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    #if READABLE_PRINT
    cout << i << ": (";
    outputFile << i << ": (";
    #endif

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

      #if READABLE_PRINT
      if( KB.at(i).at(j).first == false ) { 
        cout << "-";
        outputFile << "-";
      }
      else { 
        cout << " ";
        outputFile << " ";
      }
      cout << KB.at(i).at(j).second;
      outputFile << KB.at(i).at(j).second;
      if( j < KB.at(i).size() - 1 ) { 
        cout << " v ";
        outputFile << " v ";
      }
      #else
      cout << "KB[ " << i << " ]" << "[ " << j << " ]: ";
      outputFile << "KB[ " << i << " ]" << "[ " << j << " ]: ";
      cout << KB.at(i).at(j).first << " " << KB.at(i).at(j).second << "\n";
      outputFile << KB.at(i).at(j).first << " " << KB.at(i).at(j).second << "\n";
      #endif

    }

    #if READABLE_PRINT
    cout << " )\n";
    outputFile << " )\n";
    #endif

  }

  cout << endl;
  outputFile << "\n";

  return;

}

bool satCheck( KnowledgeBase &KB, State &s ) {

  for( unsigned int i = 0; i < KB.size(); ++i ) {

    if( KB.at(i).empty() == true ) return( false );

    for( unsigned int j = 0; j < KB.at(i).size(); ++j ) {

      if( KB.at(i).at(j).second != '*' ) return( false );

    }

  }

  return( true );

  /* // Dont need any of this garbage
  cout << "satCheck\n";
  if( s.KBTree.empty() || s.model.empty() ) return( false );

  Clause unpureModel = s.model;

  // Pure check
  for( unsigned int n = 0; n < s.pureSymbols.size(); ++n ) {
    for( unsigned int m = 0; m < unpureModel.size(); ++m ) {
      if( unpureModel.at(m).second == s.pureSymbols.at(n).second ) { 
        unpureModel.erase( unpureModel.begin() + m );
      }
    }
  }

  if( unpureModel.empty() ) return( false );

  const KnowledgeBase startKB = s.KBTree.front();

  for( unsigned int i = 0; i < startKB.size(); ++i ) {
    for( unsigned int j = 0; j < startKB.at(i).size(); ++j ) {

      const char KBSymbol = startKB.at(i).at(j).second;
      const bool KBPolarity = startKB.at(i).at(j).first;

      for( unsigned int m = 0; m < unpureModel.size(); ++m ) {

        const char ModelSymbol = unpureModel.at(m).second;
        const bool ModelPolarity = unpureModel.at(m).first;

        if( ModelSymbol == KBSymbol && ModelPolarity != KBPolarity )
          return( false );

      }
    }
  }

  return( true );
  */

}

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
        else { 
          if( unitClause.first == KB.at(i).at(j).first ) {
            //KB.at(i).erase( KB.at(i).begin() + j ); // nonononono!
            KB.at(i).erase( KB.at(i).begin(), KB.at(i).end() );
            KB.at(i).push_back( Literal( true, '*' ) );
          }

          else if( unitClause.first != KB.at(i).at(j).first )
            KB.at(i).erase( KB.at(i).begin() + j );
        }

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
  //  : : this is done by calling unitPropogate on KB

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

bool DPLL( KnowledgeBase &KB, State &s ) {

  s.DPLLcalls += 1;
  s.KBTree.push_back( KB );

  cout << "Model: { ";
  outputFile << "Model: { ";
  for( unsigned int i = 0; i < s.model.size(); ++i ) {
    if( s.model.at(i).first == false ) { 
      cout << "-";
      outputFile << "-";
    }
    else { 
      cout << " ";
      outputFile << " ";
    }
    cout << s.model.at(i).second << " ";
    outputFile << s.model.at(i).second << " ";
  }
  cout << " }" << endl;
  outputFile << " }\n";

  // 1: if KB is a consistent set of literals return true
  if( satCheck( KB, s ) == true ) return( true );

  // 2: if KB contains an empty clause return false
  if( emptyClauseCheck( KB ) == true &&
      s.backtracks > s.possibleBacktracks ) return( false );

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
    outputFile << "Pure Symbol: " << pureSymbol.first << " " << pureSymbol.second << "\n";
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
    outputFile << "Unit Clause: " << unitClause.first << " " << unitClause.second << "\n";
    s.model.push_back( unitClause );
    unitPropogate( unitClause, KB, false );
    printKB( KB );
    return( DPLL( KB, s ) );

  }

  // 5: else choose a literal in model options that hasnt been chosen yet

  // Backtracking Case: (im so sorry)
  if( s.model.size() == s.modelOptionsRecovery.size() ) {

    if( s.backtracks <= s.possibleBacktracks ) {

      cout << "Back-tracking...\n";
      outputFile << "Back-tracking...\n";
      s.backtracks += 1;

      // Save previous models
      s.modelTree.push_back( s.model );

      vector<char> exhaustedSymbols;

      for( unsigned int i = 0; i < s.modelTree.size(); ++i ) {
        for( unsigned int j = 0; j < s.modelTree.at(i).size(); ++j ) {
    
          const char modelTreeSymbol = s.modelTree.at(i).at(j).second;
          const bool modelTreePolarity = s.modelTree.at(i).at(j).first;

          for( unsigned int k = 0; k < s.model.size(); ++k ) {

            const char modelSymbol = s.model.at(k).second;
            const bool modelPolarity = s.model.at(k).first;

            bool pure = false;
            for( unsigned int w = 0; w < s.pureSymbols.size(); ++w ) {
              if( modelSymbol == s.pureSymbols.at(w).second ) pure = true;
            }

            if( pure == false ) {
              if( modelSymbol == modelTreeSymbol && modelPolarity != modelTreePolarity ) {
                exhaustedSymbols.push_back( modelSymbol );
              }

            }

          }
        }
      }

      Literal backtrackLit;
      unsigned int KBTreeIndex = 0;

      if( exhaustedSymbols.empty() ) {

        for( unsigned int i = 0; i < s.model.size(); ++i ) {

          const char modelSymbol = s.model.at(i).second;
          const bool modelPolarity = s.model.at(i).first;

          bool pure = false;
          for( unsigned int w = 0; w < s.pureSymbols.size(); ++w ) {
            if( modelSymbol == s.pureSymbols.at(w).second ) pure = true;
          }

          if( pure == false ) { 

            backtrackLit = make_pair( !modelPolarity, modelSymbol );
            break;

          }

        }

      }

      else {

        // Select the symbole to start backtracking
        for( unsigned int i = 0; i < s.model.size(); ++i ) {
          for( unsigned int j = 0; j < exhaustedSymbols.size(); ++j ) {

            const char modelSymbol = s.model.at(i).second;
            const bool modelPolarity = s.model.at(i).first;

            bool pure = false;
            for( unsigned int w = 0; w < s.pureSymbols.size(); ++w ) {
              if( modelSymbol == s.pureSymbols.at(w).second ) pure = true;
            }

            if( modelSymbol != exhaustedSymbols.at(j) && pure == false ) {

              backtrackLit = make_pair( !modelPolarity, modelSymbol );
              KBTreeIndex = i;

            }
            
          }
        }

      }

      // clear model for next iterations
      s.model.clear();
      s.model.push_back( backtrackLit );
      s.modelOptions = s.modelOptionsRecovery;

      // FIXME: use .at( KBTreeIndex ) and recover model from that point
      KB = s.KBTree.front();
      s.KBTree.clear();

      // Remove from model options:
      for( unsigned int i = 0; i < s.modelOptions.size(); ++i ) {
        if( s.modelOptions.at(i) == backtrackLit.second ) {
          s.modelOptions.erase( s.modelOptions.begin() + i );
        }
      }

      cout << "Chose: " << backtrackLit.first << " " << backtrackLit.second << "\n";
      outputFile << "Chose: " << backtrackLit.first << " " << backtrackLit.second << "\n";
      unitPropogate( backtrackLit, KB, false );
      printKB( KB );

      return( DPLL( KB, s ) );

    }

    else return( false );

  }

  // The rest of the function is what happens when no backtracking

  if( s.model.empty() ) s.model.push_back( Literal( true, s.modelOptions.front() ) );

  else {

    // Use the next unused symbol
    s.model.push_back( Literal( true, s.modelOptions.front() ) );

  }

  const Literal chosenLit = s.model.back();

  // Remove from model options:
  for( unsigned int i = 0; i < s.modelOptions.size(); ++i ) {
    if( s.modelOptions.at(i) == chosenLit.second ) {
      s.modelOptions.erase( s.modelOptions.begin() + i );
    }
  }

  // 6: return( DPLL( KB && l ) or DPLL( KB && !l ) )

  cout << "Chose: " << chosenLit.first << " " << chosenLit.second << "\n";
  outputFile << "Chose: " << chosenLit.first << " " << chosenLit.second << "\n";
  unitPropogate( chosenLit, KB, false );
  printKB( KB );
  return( DPLL( KB, s ) );

}

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
  s.modelOptionsRecovery = s.modelOptions;

  const unsigned int modelOptSize = s.modelOptions.size();
  s.possibleBacktracks = ( modelOptSize * modelOptSize ) - 1;

  return;

}

int main( int argc, char** argv ) {

  cout << boolalpha;

  string problemName;

  if( argc == 2 ) problemName = string( argv[1] );

  else cin >> problemName;

  string fileName = "problemSet/" + problemName + ".cnf";
  string myFile = "problemSet-SolutionTraces/" + problemName;

  State s;
  KnowledgeBase KB;
  readFile( fileName, KB, s );

  cout << "Knowledge Base\nSymbols: ";
  for( auto w : s.modelOptions ) cout << w << " ";
  cout << endl;

  openFile( myFile );
  outputFile << boolalpha;

  printKB( KB );

  s.satisfiability = DPLL( KB, s );

  cout << "Satisfiable? : " << s.satisfiability << endl;

  if( s.satisfiability == true ) {

    cout << "!!-- Trace in: " << myFile << endl;

    outputFile << "The logic is satisfiable\n";
    outputFile << "Model: { ";
    for( unsigned int i = 0; i < s.model.size(); ++i ) {
      if( s.model.at(i).first == false ) outputFile << "-";
      else outputFile << " ";
      outputFile << s.model.at(i).second << " ";
    }
    outputFile << " }" << endl;

    outputFile.close();

  }

  return( 0x5F3759DF );

}
