/* * * * * *
 *
 * File: DES.cpp
 * By: Connor Bessell
 *
 * !!-- This is just 1 round of the DES scheme. Don't actually use this for anything.
 * 
 * * */
#include <iostream>
#include <vector>

using namespace std;

const int S1[4][16] = {
  14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
  0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
  4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
  15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
};

const int S2[4][16] = {
  15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
  3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
  0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
  13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
};

const int S3[4][16] = {
  10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
  13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
  13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
  1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
};

const int S4[4][16] = {
  7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
  13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
  10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
  3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
};

const int S5[4][16] = {
  2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
  14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
  4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
  11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
};

const int S6[4][16] = {
  12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
  10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
  9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
  4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
};

const int S7[4][16] = {
  4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
  13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
  1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
  6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
};

const int S8[4][16] = {
  13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
  1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
  7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
  2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
};



// input blocks 32 bits each
const long int inputR = 0xdf9573f5;
const int inputL =      0x5f3759df;

// 48 bit key
const long int inputK = 0x123456789abc;

long int expandR( long int R ) {

  // Split R:
  long int ReR = R % 0x10000;
  long int ReL = R - ReR;

  // expansion peices
  int ReRxp = (ReR - (ReR % 0x100)) >> 8;
  int ReLxp = (ReL % 0x1000000) >> 16;

  ReR = ReR % 0x100;
  ReL = ReL - (ReL % 0x1000000);

  // add expansion peices
  ReR = ReR + (ReLxp << 8) + (ReRxp << 16);
  ReL = ReL + (ReRxp << 16) + (ReLxp << 8);

  // final shift before combine
  ReL = ReL << 16;

  return( ReL + ReR );

}

int sBox( long int RxK ) {

  cout << "RxK: " << RxK << endl;

  vector<int> selR;

  // pick apart 6-bits --> xx_xxxx --> 0x40 modulus

  {

    int RxK1 = (RxK % 0x40);
    int RxK2 = (RxK % 0x400) >> 4;
    int RxK3 = (RxK % 0x4000) >> 8;
    int RxK4 = (RxK % 0x40000) >> 12;
    int RxK5 = (RxK % 0x400000) >> 16;
    int RxK6 = (RxK % 0x4000000) >> 20;
    int RxK7 = (RxK % 0x40000000) >> 24;
    int RxK8 = (RxK % 0x400000000) >> 28;
    selR = { RxK1, RxK2, RxK3, RxK4, RxK5, RxK6, RxK7, RxK8 };

  }

  cout << "RxK's: ";
  for( auto v : selR ) cout << v << ", ";
  cout << endl;

  // it JUST works (seriously)
  for( unsigned int i = 0; i < selR.size(); ++i ) {

    // strip row bits: XxxxxX
    int rowSel = ( ((selR[i] >> 5) % 2) << 1 ) + ( selR[i] % 2 );

    // strip col bits: xXXXXx
    int colSel = ( selR[i] >> 1 ) % 16;

    cout << "i=" << i << ": rowSel = " << rowSel << ", colSel = " << colSel << endl;

    switch(i) {
      case 0:
        selR[i] = S1[rowSel][colSel];
        break;
      case 1:
        selR[i] = S2[rowSel][colSel];
        break;
      case 2:
        selR[i] = S3[rowSel][colSel];
        break;
      case 3:
        selR[i] = S4[rowSel][colSel];
        break;
      case 4:
        selR[i] = S5[rowSel][colSel];
        break;
      case 5:
        selR[i] = S6[rowSel][colSel];
        break;
      case 6:
        selR[i] = S7[rowSel][colSel];
        break;
      case 7:
        selR[i] = S8[rowSel][colSel];
        break;
    }

  }

  cout << "S-box subs: ";
  for( auto v : selR ) cout << v << ", ";
  cout << endl;

  int subs = 0;
  for( unsigned int i = 0; i < selR.size(); ++i ) {
   
    subs = subs + (selR[i] << (i*4));
    cout << "i=" << i << ", substitution = " << subs << endl;

  }

  return( subs );

}

int permutation( int subs ) {

  int perm = 0;

  // permutation order: 46213857
  perm = perm + ((subs % 0x10000000) >> 6*4 );

  if( perm == 0 ) cout << "leading zero in permutation\n";

  perm = perm << 7*4;
  perm = perm + ( ((subs % 0x100000) >> 4*4) << 6*4 );
  perm = perm + ( ( subs >> 7*4 ) << 5*4 );
  perm = perm + ( ((subs % 0x1000) >> 2*4) << 4*4 );
  perm = perm + ((subs % 0x10) << 3*4);
  perm = perm + ( ((subs % 0x100) >> 1*4) << 2*4 );
  perm = perm + ( ((subs % 0x1000000) >> 5*4) << 1*4 );
  perm = perm + ((subs % 0x10000) >> 3*4 );

  return( perm );

}

int main( void ) {
  
  cout << "\t!!-- 1-Round of DES --!! \n";
  cout << hex << "\tAll numerics are in \033[1;33mHEX\033[0m\n";
  cout << "\033[32mInput PlainText: " << inputR << " + " << inputL << "\033[0m" << endl;

  // Li+1 <-- Ri
  int Lip1 = inputR;

  // expansion( Ri ) 32b --> 48b
  long int R = inputR;
  long int expR = expandR( R );
  cout << "Expansion: " << expR << endl;

  // Sbox <-- expansion( Ri ) xor Ki
  long int RxK = expR xor inputK;
  int substitutionRxK = sBox( RxK );
  cout << "S-Box: " << substitutionRxK << endl;

  // Permutation <-- Sbox
  int permutationSBox = permutation( substitutionRxK );
  cout << "Permutation: " << permutationSBox << endl;

  // mangler <-- Permutation
  const int mangler = permutationSBox;

  // Ri+1 <-- mangler( Ri, Ki ) xor Li
  int Rip1 = mangler xor inputL;

  cout << "\033[36mOutput CipherText: " << Rip1 << " + " << Lip1 << "\033[0m" << endl;

  return( 0x5f3759df );

}
