#include "Expr.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char** argv ){

  string problemFile;

  if( argc == 2 ) problemFile = string( argv[1] );

  else {

    cout << "Availible problem files:\n";
    system( "ls -1 problemSet/ | grep -E *.kb" );
    cout << "Input a file (don't include \".kb\"): ";
    cin >> problemFile;

  }

  problemFile = "problemSet/" + problemFile + ".kb";

  ifstream inputFile( problemFile );
  string fileString;
  inputFile.seekg( 0, ios::end );
  fileString.reserve( inputFile.tellg() );
  inputFile.seekg( 0, ios::beg );
  fileString.assign( istreambuf_iterator<char>(inputFile), istreambuf_iterator<char>() );

  cout << fileString;

  Expr FFF( problemFile );

  cout << FFF.getSym();

  return( 0x5F3759DF );

}
