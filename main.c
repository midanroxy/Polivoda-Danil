
#include <stdlib.h>
#include <math.h>
int main()
{
  int a = 8.11;
   int b = 3.09;
   int x = -1.16;
  double result;
  result = pow(b*tan(2*x),1.0/3)/a*sin(2-x);
  printf("%f",result);
  return 0;
}
