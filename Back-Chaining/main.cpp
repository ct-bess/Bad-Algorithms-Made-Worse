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

  if( argc == 2 ) { 

    problemFile = string( argv[1] );

    cout << "\033[1;33m";
    cout << "Program start:";
    cout << "\033[1;36m";
    cout << " -- input \"q\" to quit";
    cout << "\033[0m\n";

  }

  else {

    cout << "Availible problem files:\n";
    system( "ls problemSet/ | grep .kb" );
    cout << "\033[7m";
    cout << "Input a file (don't include \".kb\"): ";
    cout << "\033[0m";
    cin >> problemFile;

  }

  problemFile = "problemSet/" + problemFile + ".kb";

  KnowledgeBase KB;

  readFile( problemFile, KB, false );

  cout << "Parsed facts:\n";
  for( auto v : KB.factBinV ) {
    cout << v << EOL;
  }

  cout << "Parsed rules:\n";
  for( auto v :KB.ruleBinV ) {
    cout << v << EOL;
  }

  string input;
  while( getline( cin, input ) ) {

    if( input == "q" || input == "YAMETE" ) break;

    inferencer( input, KB );

  }

  return( 0x5F3759DF );

}
