#include "Expr.hpp"

using namespace std;

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

//------------------------------------

