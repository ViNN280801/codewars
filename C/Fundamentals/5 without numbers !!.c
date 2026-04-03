#include <tgmath.h>

int unusual_five (void)
{
  // Main log property: log_a(b)=c => a^c=b
  // By default <math.h> provides log, that is log_e, where e=2.718281828... (Euler's number)
  // log_e(5)=X, so, e^x=5, where X we exactly can calculate with log() function
  // But we can't use any digits or math operations, therefore, we can use ASCII characters
  // ASCII 5 => <ENQ> (enquiry) this is not printable symbol
  // We can use another symbol, for example 'z' which is 122 in dec; ln(122)=4.8
  // after that we just need to use `nearbyint` or round
  return nearbyint(log('z'));
}

#include <stdio.h>

int main(void)
{
  printf("%d\n", unusual_five());
}

