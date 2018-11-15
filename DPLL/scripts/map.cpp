// Code to generate CNF KB for coloring a map of Australia where no 2 same colors touch each other
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Western Australia

// Northern Territory

// South Australia

// Queensland

// New South Whales

// Victoria

// Tasmania

int main() {

  // Colors: RBG

  vector<string> AUS{ "WA", "NT", "SA", "Q", "NSW", "V", "T" };

  vector<string> WAx{ "NT", "SA" };
  vector<string> NTx{ "WA", "SA", "Q" };
  vector<string> SAx{ "WA", "NT", "NSW", "Q", "V" };
  vector<string> Qx{ "NSW", "SA", "NT" };
  vector<string> Vx{ "SA", "NSW" }
  vector<string> Tx;

  return( 0x5F3759DF );

}

