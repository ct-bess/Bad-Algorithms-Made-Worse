#include "Expr.hpp"

// TODO: make unify return a string
//     : make a container to store unified facts and rules
//
// TODO: unify is probably not safe and not optimal
//
// TODO: dallas ?m and such wont work b/c of dupe logic

using namespace std;

void unionize( vector<string> uniMap ) {

  smatch matches;
  const RuleV ruleBinV = uniMap;
  regex wordRE( "\\w+ " );

  vector<vector<string>> ruleVV;
  for( uint_fast16_t i = 0; i < ruleBinV.size(); ++i ) {

    string rule = ruleBinV.at(i);

    vector<string> currRule;

    while( regex_search( rule, matches, wordRE ) ) {

      currRule.push_back( matches[0] );
      rule = matches.suffix().str();

    }

    ruleVV.push_back( currRule );

  }

  // FIXME this dont work dude, you gotta run down the middle and find dupes
  for( uint_fast16_t i = 0; i < ruleVV.size(); ++i ) {

    for( uint_fast16_t j = 1; j < ruleVV.at(i).size(); ++j ) {

      if( ruleVV.at(i).at(1) == ruleVV.at(j).at(1) ) {
        cout << "\033[1;31m";
        cout << ruleVV.at(i).at(1);
        cout << "\033[0m\n";
      }

    }

  }

  return;

}

void unify( string fact, vector<string> rule, KnowledgeBase &KB ) {

  // Given 2 expressions (a,b), return a substitution or nothing if they dont unify
  // -- from Figure 9.1 in text book
  // -- you may want to make a unifier class to store this mapping
  // -- or just be retarded as usual and dump it into a new KB var
  // e.g.
  // a = "author huckleberry_finn ?b"
  // b = "author ?a mark_twain"
  // unify(a,b) = "author huckleberry_finn mark_twain

  const RuleV ruleBinV = KB.ruleBinV;
  const FactV factBinV = KB.factBinV;

  //regex varRE( "[?]" );
  //regex wordRE( "\\w+" );
  smatch matches;

  /*int factSize;
  string subFact = fact;
  while( regex_search( subFact, matches, wordRE ) ) {
    ++factSize;
    subFact = matches.suffix().str();
  }*/

  for( uint_fast16_t i = 0; i < rule.size(); ++i ) {

    const string currRule = rule.at(i);


    cout << "currRule: " << currRule << EOL;

    //if( regex_search( currRule, matches, varRE ) == true ) continue;

    regex ruleRE( currRule );

    // Dont pull duplicate rules onto our unifier mapping!
    //regex queryRE( "\\b" + currRule );
    //if( regex_search( KB.query, matches, queryRE ) == true ) continue;
    if( currRule == KB.query + " " ) continue;

    // Link rule to fact
    if( regex_search( fact, matches, ruleRE ) == true ) {

      cout << "\033[1;32m";
      cout << "Unify: " << fact << " && " << KB.query;
      cout << "\033[0m\n";

      /*if( factSize < 3 ) {

        fact = string( matches.suffix().str() );
        KB.uniMap.push_back( KB.query + " " + fact );

      }*/

      //else {

      fact = regex_replace( fact, ruleRE, "$2" );
      KB.uniMap.push_back( fact + KB.query + " " );

      //}

      return;

    }

  }

  cout << "\033[1;31m";
  cout << "Unification failed";
  cout << "\033[0m\n";

  return;

}

// -- Back-Chaining brains: Figure 9.6 in text book
void inferencer( string decisionQ, KnowledgeBase &KB ) {

  // 1: loop thru factBinV (outer loop)
  // 2: loop thru ruleBinV (inner loop) --> use rules w.r.t decisionQuery
  //  : : attempt to unify our current fact with the current rule
  //  : : update map on success, do not map on failure
  // 3: Output the facts that lead to the decision
  //  : : this is simply the unifier mappings (in order preferably)

  RuleV ruleBinV = KB.ruleBinV;
  const FactV factBinV = KB.factBinV;

  // 1: Find relivant rules w.r.t the input query
  smatch matches;
  string query;
  queue<string> queryQ;
  {
    //regex queryRE( "^\\w+" );
    regex queryRE( "[^? ]\\w+" ); 

    while( regex_search( decisionQ, matches, queryRE ) ) {

      //query += string( matches[0] );
      queryQ.push( matches[0] );
      decisionQ = matches.suffix().str();

    }
  }

  int querySize = queryQ.size();

  while( queryQ.empty() == false ) {

    query = queryQ.front();

    cout << "\033[1;35m";
    cout << "Query: " << query;
    cout << "\033[0m\n";
    KB.query = query;
    
    regex queryRE( query );
    regex wordRE( "\\w+ " );

    vector<vector<string>> ruleVV;
    for( uint_fast16_t i = 0; i < ruleBinV.size(); ++i ) {

      string rule = ruleBinV.at(i);

      cout << "Rule in question: " << rule << EOL;

      if( regex_search( rule, matches, queryRE ) == false ) continue;

      cout << "Adding rule: " << rule << EOL;

      vector<string> currRule;

      // else:
      while( regex_search( rule, matches, wordRE ) ) {

        currRule.push_back( matches[0] );
        rule = matches.suffix().str();

      }

      ruleVV.push_back( currRule );

    }

    // Unify all ruleVV with all facts in KB
    for( uint_fast16_t i = 0; i < factBinV.size(); ++i ) {

      for( uint_fast16_t j = 0; j < ruleVV.size(); ++j ) {

        cout << ": " << i << " " << j << EOL;
        cout << "Checking fact: " << factBinV.at(i);
        cout << "|| With rule: ";
        for( auto s : ruleVV.at(j) ) cout << s << " ";
        cout << EOL;

        unify( factBinV.at(i), ruleVV.at(j), KB );

      }

    }

    queryQ.pop();

  }

  // Output the union from the compound query
  if( querySize > 1 ) {

    unionize( KB.uniMap );

  }

  return;

}

void readFile( string &fileName, KnowledgeBase &KB, bool verbose ) {

  ifstream inputFile( fileName );
  string fileString;
  inputFile.seekg( 0, ios::end );
  fileString.reserve( inputFile.tellg() );
  inputFile.seekg( 0, ios::beg );
  fileString.assign( istreambuf_iterator<char>(inputFile), istreambuf_iterator<char>() );

  cout << fileString;

  vector<string> symbolV;

  smatch matches;

  regex expressionRE( "\\(.+\\)(?=#)|\\(.+\\)" );

  // Pull each rule or fact w/o the comments
  while( regex_search( fileString, matches, expressionRE ) ) {

    if( verbose ) cout << "Match: " << matches[0] << EOL;

    symbolV.push_back( matches[0] );
    fileString = matches.suffix().str();

  }

  if( verbose ) cout << "Final fileString (should be empty): " << fileString;

  regex factRE( "[^() ]+" );
  regex ruleRE( "\\?" );

  for( unsigned int i = 0; i < symbolV.size(); ++i ) {

    bool ruleFlag = false;
    string sentence = "";

    if( regex_search( symbolV.at(i), matches, ruleRE ) == true ) ruleFlag = true;

    while( regex_search( symbolV.at(i), matches, factRE ) ) {

      if( verbose ) cout << "Match: " << matches[0] << EOL;

      if( ruleFlag == true ) sentence += string(matches[0]) + " ";

      else sentence += string(matches[0]) + " ";

      symbolV.at(i) = matches.suffix().str();

    }

    if( ruleFlag == true ) KB.ruleBinV.push_back( sentence );

    else KB.factBinV.push_back( sentence );

  }

  return;

}

float Q_rsqrt( float number ) {

  long i;
  float x2, y;
  const float threehalfs = 1.5f;

  x2 = number * 0.5f;
  y = number;
  i = *( long* ) &y;                          // evil floating point bit level hacking
  i = 0x5f3759df - ( i >> 1 );                // what the fuck?
  y = *( float* ) &i;
  y = y * ( threehalfs - ( x2 * y * y ) );    // 1st iteration
  //y = y * ( threehalfs - ( x2 * y * y ) );  // 2nd iteration, this can be removed

  return y;

}

//------------------------------------

