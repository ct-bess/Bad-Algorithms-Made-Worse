/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * FIXME: expressionRE in Expr will pull parenths behind comments
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Expr.hpp" // TYFYS

using namespace std;

int main( int argc, char** argv ){

  cout << boolalpha;

  string problemFile;

  if( argc == 2 ) problemFile = string( argv[1] );

  else {

    cout << "Availible problem files:\n";
    system( "ls problemSet/ | grep .kb" );
    cout << "Input a file (don't include \".kb\"): ";
    cin >> problemFile;

  }

  problemFile = "problemSet/" + problemFile + ".kb";

  KnowledgeBase KB;

  readFile( problemFile, KB, true );

  cout << "Parsed facts:\n";
  for( auto v : KB.factBinV ) {
    cout << v << EOL;
  }

  cout << "Parsed rules:\n";
  for( auto v :KB.ruleBinV ) {
    cout << v << EOL;
  }

  return( 0x5F3759DF );

}
