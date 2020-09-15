#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool isInside(double x, double y)
{
  double dist = sqrt(pow(x - 0.5, 2) + pow(y - 0.5, 2));
  return (dist <= 0.5);
}

double piValue()
{
  srand(time(NULL));
  double x, y;
  int nInside = 0, nOutside = 0;
  for (int i = 0; i < 10000000; i++)
  {
    x = (double)rand() / (RAND_MAX);
    y = (double)rand() / (RAND_MAX);
    if (isInside(x, y))
      nInside++;
    else
      nOutside++;
  }
  return (4 * nInside / (double)(nOutside + nInside));
}

int main()
{
  cout.precision(3);
  cout << fixed << piValue() << endl;
  return 0;
}