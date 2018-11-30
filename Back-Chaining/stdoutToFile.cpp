#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main( int argc, char** argv ) {

  string data, myFile;
  ofstream outputFile;

  if( argc != 2 ) {

    cout << "USAGE: ./a problemName | ./b problemName\n";
    return( -1 );

  }

  myFile = "problemSet-solutionTraces/" + string( argv[1] ) + ".sol";

  outputFile.open( myFile );

  while( getline( cin, data ) ) {

    outputFile << data << endl;

  }

  outputFile << "\n--- End Of Solution Trace ---\n";

  cout << "Output written in: " << myFile << endl;

  outputFile.close();
  return( 0x5F3759DF );

}
