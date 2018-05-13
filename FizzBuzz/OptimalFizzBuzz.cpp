/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                         *
 * Reference: texus.me/2015/11/17/intel-tbb-parallel-for/  *
 *                                                         *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <vector>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

struct FizzBuzz {

  // Initializer list
  FizzBuzz( std::vector<int> *pNumFizzBuzz ) :
    numFizzBuzz{ pNumFizzBuzz }
    {}

  // Loop to be parallel-ed
  void operator()( const tbb::blocked_range<size_t> &range ) const {

    for ( int i = range.begin(); i < range.end(); ++i ) {

      // 3 | i and 5 | i --> 15 | i (Chinese Remainder Theorem)
      if ( i % 15 == 0 ) ( *numFizzBuzz )[2] += 1;

      // 5 | i
      else if ( i % 5 == 0 ) ( *numFizzBuzz )[1] += 1;

      // 3 | i
      else if ( i % 3 == 0 ) ( *numFizzBuzz )[0] += 1;

      //else printf( "%d\n", i );

    }

  }

  std::vector<int> *numFizzBuzz;

};

int main() {

  // Storing each Fizz Buzz and FizzBuzz rather than printing to sdtout
  // due to the nature of parallel processes, loop output will not be serial
  std::vector<int> FizzBuzzes( 3, 0 );

  tbb::parallel_for( tbb::blocked_range<size_t>( 1, 101 ), FizzBuzz( &FizzBuzzes ) );

  printf( "\tFizz'es = %d\n\tBuzz'es = %d\n\tFizzBuzz'es = %d\n", 
          FizzBuzzes[0], FizzBuzzes[1], FizzBuzzes[2] ); 

  return 0;

}
