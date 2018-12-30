/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *
 * File: hw9.c
 * Author: Connor Bessell
 *
 * Compile: gcc -o hw9 hw9.c -lgmp
 * Run: ./hw9
 *
 * 9.7 #1:
 *   ElGamal Signature Scheme: Let p = 65539, alpha = 2, beta = 33384
 *   Sending 2 messages:
 *   hi = ( m, r, s ) = ( 809, 18357, 1042 )
 *   bye = ( m, r, s ) = ( 22505, 18357, 26272 )
 *   a) show each signature uses the same value of k
 *   b) Find the values of k and a where beta === alpha^a ( mod p )
 *
 * 9.7 #2:
 *   RSA Signature Scheme:
 *   nA = 171024704183616109700818066925197841516671277
 *   nB = 839073542734369359260871355939062622747633109
 *   eA = 1571
 *   eB = 87697
 *   pB = 98763457697834568934613
 *   qB = 8495789457893457345793
 *   Alice signs document --> sends sig(m,s) where s === m^(dA)(mod nA) to Bob
 *   Bob recieves encrypted sig pair(m1,s1) === ( m^(eB), s^(eB) )(mod nB)
 *   m1 = 418726553997094258577980055061305150940547956
 *   s1 = 749142649641548101520133634736865752883277237
 *   find message m and verify it came from Alice
 *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <gmp.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// strings for #1
const char inputStr_p2[1024] = "65539";
const char inputStr_bt[1024] = "33384";
const char inputStr_m2[1024] = "809";
const char inputStr_r2[1024] = "18357";
const char inputStr_s2[1024] = "1042";
const char inputStr_m3[1024] = "22505";
const char inputStr_r3[1024] = "18357";
const char inputStr_s3[1024] = "26272";
const char inputStr_al[1024] = "2";

// strings for #2
const char inputStr_pB[1024] = "98763457697834568934613";
const char inputStr_qB[1024] = "8495789457893457345793"; 
const char inputStr_nB[1024] = "839073542734369359260871355939062622747633109";
const char inputStr_nA[1024] = "171024704183616109700818066925197841516671277";
const char inputStr_eB[1024] = "87697";
const char inputStr_eA[1024] = "1571";
const char inputStr_m1[1024] = "418726553997094258577980055061305150940547956";
const char inputStr_s1[1024] = "749142649641548101520133634736865752883277237";

// Baby-Step-Gitan-Step using GMP
void BSGS( mpz_t al, mpz_t bt, mpz_t n ){

  // Chose some k: usually k = ceil( sqrt( n ) ), but any k will do
  mpz_t k;

  // indices[i] = alk[i] = al^k
  unsigned long int *indices; 
  mpz_t *alk;
  mpz_t alinv;

  // b*al^-rk
  mpz_t btk;

  mpz_init( k );
  mpz_sqrt( k, n );
  mpz_add_ui( k, k, 1 );

  // Table 1: Baby Step
  alk = malloc( mpz_get_ui( k ) * sizeof( mpz_t ) );
  indices = malloc( mpz_get_ui( k ) * sizeof( long int ) );

  // Base case
  mpz_init_set_ui( alk[0], 1 );

  // Create Table 1: al^1, al^2, ..., al^(k-1) ( mod n )
  unsigned long int i;
  for ( i = 1; i <= mpz_get_ui( k ); ++i ) {

    indices[i - 1] = i - 1;
    mpz_init( alk[i] );

    // Rather than compute a large power every iteration
    // increment the current element by the previous element times alpha
    mpz_mul( alk[i], alk[i - 1], al );
    mpz_mod( alk[i], alk[i], n );

  }

  // Table 2: Giant Step
  // Create Table 2: bt*al^-k, bt*al^-2k, ..., bt*al^-rk ( mod n ) , rk > n
  //                 Compare Table 1 while Table 2 is being created
  mpz_init_set( alinv, al );
  mpz_powm( alinv, alinv, k, n );
  mpz_invert( alinv, alinv, n );

  mpz_init_set( btk, bt );

  // The following is a naive "bubble search" method
  // Faster results w/: sort Table 1, binary search Table 1 for current Table 2 element

  // A match in each table means: x = ik + j
  unsigned long int j;
  for ( i = 0; i <= mpz_get_ui( k ); ++i ) {

    for ( j = 0; j <= mpz_get_ui( k ); ++j ) {

      if ( mpz_cmp( alk[j], btk ) == 0 ) {

        mpz_mul_ui( k, k, i );           // ik
        mpz_add_ui( k, k, indices[j] );  // ik + j
 
        printf ( "\nx (or 'a' in #2) = " );
        mpz_out_str( stdout, 10, k );

        return;

      }

    }
    
    // Search fail: calculate next bt*al^-jk
    mpz_mul( btk, btk, alinv );
    mpz_mod( btk, btk, n );

  }

  return;

}

int main( void ){

  int flag;

  // ------------------- / 9.7 #1 \ ------------------- //
  printf("\n9.7 #1:\nElGamal Signature Scheme:");

  mpz_t p2, bt, m2, r2, s2, m3, r3, s3, k, al, a;

  mpz_init( p2 );
  mpz_init( bt );
  mpz_init( m2 );
  mpz_init( r2 );
  mpz_init( s2 );
  mpz_init( m3 );
  mpz_init( r3 );
  mpz_init( s3 );
  mpz_init(  k );
  mpz_init( al );
  mpz_init(  a );
  mpz_set_si( p2, 0 );
  mpz_set_si( bt, 0 );
  mpz_set_si( m2, 0 );
  mpz_set_si( r2, 0 );
  mpz_set_si( s2, 0 );
  mpz_set_si( m3, 0 );
  mpz_set_si( r3, 0 );
  mpz_set_si( s3, 0 );
  mpz_set_si(  k, 0 );
  mpz_set_si( al, 0 );
  mpz_set_si(  a, 0 );

  flag = mpz_set_str( p2, inputStr_p2, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( bt, inputStr_bt, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( m2, inputStr_m2, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( r2, inputStr_r2, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( s2, inputStr_s2, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( m3, inputStr_m3, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( r3, inputStr_r3, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( s3, inputStr_s3, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( al, inputStr_al, 10 );
  assert( flag == 0 ); 

  // Since the same k is used for m2 and m3
  // ----> r2 === r3 ( mod p )
  //       k = (s2 - s3)^-1 * (m2 - m3) ( mod p - 1 )
  mpz_sub( s2, s2, s3 );
  mpz_sub( m2, m2, m3 );
  mpz_sub_ui( p2, p2, 1 );
  mpz_abs( s2, s2 );
  mpz_abs( m2, m2 );

  // gcd( s1 - s2, p - 1 ) = 1 --> confirms Alice used the same k for m2 & m3
  mpz_gcd( k, s2, p2 );

  printf ( "\ngcd( s2 - s3, p - 1 ) = " );
  mpz_out_str( stdout, 10, k );

  mpz_gcd( k, m2, p2 );

  printf ( "\ngcd( m2 - m3, p - 1 ) = " );
  mpz_out_str( stdout, 10, k );

  // (s2 - s3)^-1 ( mod p - 1 )
  mpz_invert( s2, s2, p2 );

  printf ( "\n(s2 - s3)^-1 ( mod p - 1 ) = " );
  mpz_out_str( stdout, 10, s2 );

  // (m2 - m3) ( mod p - 1 )
  mpz_mod( m2, m2, p2 );

  printf ( "\n(m2 - m3) ( mod p - 1 ) = " );
  mpz_out_str( stdout, 10, m2 );

  // (s2 - s3)^-1 ( mod p - 1 ) * (m2 - m3) ( mod p - 1 )
  mpz_mul( k, m2, s2 );
  mpz_mod( k, k, p2 );

  printf ( "\nk = " );
  mpz_out_str( stdout, 10, k );

  // Recover p for BSGS
  mpz_add_ui( p2, p2, 1 );
 
  // Solving discrete log: bt === al^a ( mod p )
  //  ( al, bt, n )
  BSGS( al, bt, p2 );

  mpz_clear( p2 );
  mpz_clear( bt );
  mpz_clear( m2 );
  mpz_clear( r2 );
  mpz_clear( s2 );
  mpz_clear( m3 );
  mpz_clear( r3 );
  mpz_clear( s3 );
  mpz_clear(  k );
  mpz_clear( al );
  mpz_clear(  a );

  printf("\n");

  // ------------------- / 9.7 #2 \ ------------------- //
  printf("\n9.7 #2:\nRSA Signature Scheme:");
 
  // mpz_t is the type defined for GMP integers.
  // It is a pointer to the internals of the GMP integer data structure
  mpz_t pB, qB, nB, phi_nB, dB, eB, m, m1, s, s1, mV, eA, nA;

  // Initialize the (arbitrarily large) numbers
  mpz_init( pB );
  mpz_init( qB );
  mpz_init( nB );
  mpz_init( phi_nB );
  mpz_init( dB );
  mpz_init( eB );
  mpz_init( m );
  mpz_init( m1 );
  mpz_init( s );
  mpz_init( s1 );
  mpz_init( mV );
  mpz_init( eA );
  mpz_init( nA );
  mpz_set_si( pB, 0 );
  mpz_set_si( qB, 0 );
  mpz_set_si( nB, 0 );
  mpz_set_si( phi_nB, 0 );
  mpz_set_si( dB, 0 );
  mpz_set_si( eB, 0 );
  mpz_set_si( m, 0 );
  mpz_set_si( m1, 0 );
  mpz_set_si( s, 0 );
  mpz_set_si( s1, 0 );
  mpz_set_si( mV, 0 );
  mpz_set_si( nA, 0 );
  mpz_set_si( eA, 0 );

  // Parse the input string as a base 10 number
  flag = mpz_set_str( nB, inputStr_nB, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( pB, inputStr_pB, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( qB, inputStr_qB, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( eB, inputStr_eB, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( m1, inputStr_m1, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( s1, inputStr_s1, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( eA, inputStr_eA, 10 );
  assert( flag == 0 ); 
  flag = mpz_set_str( nA, inputStr_nA, 10 );
  assert( flag == 0 ); 

  // calculate phi_nB = (p - 1)(q - 1)
  mpz_sub_ui( pB, pB, 1 );
  printf ( "\npB - 1 = " );
  mpz_out_str( stdout, 10, pB );

  mpz_sub_ui( qB, qB, 1 );
  printf ( "\nqB - 1 = " );
  mpz_out_str( stdout, 10, qB );

  mpz_mul( phi_nB, pB, qB ); 

  printf ("\nphi_nB = (pB - 1)(qB - 1) = ");
  mpz_out_str( stdout, 10, phi_nB );

  // Computes inverse of eB mod phi_nB --> dB === 1/eB ( mod phi_nB )
  // Returns undef if DNE
  mpz_invert( dB, eB, phi_nB );

  printf ("\ndB = ");
  mpz_out_str( stdout, 10, dB );

  // Decrypt: m === m1^(dB)( mod nB )
  mpz_powm( m, m1, dB, nB );

  printf ("\nm = ");
  mpz_out_str( stdout, 10, m );

  // Decrypt: m === m1^(dB)( mod nB )
  mpz_powm( s, s1, dB, nB );

  printf ("\ns = ");
  mpz_out_str( stdout, 10, s );

  // Verify that Alice signed m ( aka that m came from Alice )
  // calculate: mV === s^(eB)( mod nB ) --> Curious! mV = s1
  //            mV === s^(eA)( mod nA ) --> mV = m (if sig is valid)
  mpz_powm( mV, s, eA, nA );

  printf ("\nmV (message to be verified) = ");
  mpz_out_str( stdout, 10, mV );
  printf ( "\n" );

  flag = mpz_cmp( m, mV );
  if ( flag == 0 ) { 

    printf( "m = mV\nSignature is Valid\n" );

  }

  // Clean up the mpz_t handles or else we will leak memory 
  mpz_clear( nB );
  mpz_clear( pB );
  mpz_clear( qB );
  mpz_clear( phi_nB );
  mpz_clear( dB );
  mpz_clear( eB );
  mpz_clear( m );
  mpz_clear( m1 );
  mpz_clear( s );
  mpz_clear( s1 );
  mpz_clear( mV );
  mpz_clear( eA );
  mpz_clear( nA );

  printf("\n");
  return 0;

}
