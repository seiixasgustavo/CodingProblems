#include <iostream>
#include <vector>

using namespace std;

int waysToClimb(const vector<int> &ways, int n)
{

  if (n == 0)
    return 1;
  int sum = 0;
  for (int i = 0; i < ways.size(); i++)
    if (n >= ways[i])
      sum += waysToClimb(ways, n - ways[i]);
  return sum;
}

int main()
{
  vector<int> ways{1, 2};
  cout << waysToClimb(ways, 4) << endl;
  return 0;
}