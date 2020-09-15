#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int reservoirSampling(const vector<int> &v)
{
  srand(time(NULL));
  int el = v[0];
  int count = 1;
  int x;

  // Imagine that this would be the loop to get the stream elements
  for (int i = 1; i < v.size(); i++)
  {
    count++;
    x = rand() % count;
    if (x == count - 1)
      el = v[i];
  }

  return el;
}

int main()
{
  cout << reservoirSampling({1, 2, 3, 4, 5}) << endl;
  return 0;
}