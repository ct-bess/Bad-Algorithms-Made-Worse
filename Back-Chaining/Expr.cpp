#include "Expr.hpp"

using namespace std;

void unify( string a, string b, KnowledgeBase &KB ) {

  // Given 2 expressions (a,b), return a substitution or nothing if they dont unify
  // -- from Figure 9.1 in text book
  // -- you may want to make a unifier class to store this mapping
  // -- or just be retarded as usual and dump it into a new KB var
  // e.g.
  // a = "author huckleberry_finn ?b"
  // b = "author ?a mark_twain"
  // unify(a,b) = "author huckleberry_finn mark_twain
  // 
  // TODO use regex

  return;

}

//void BackChain()
// -- figure 9.6 in text book
// -- TODO Use regex btw

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

