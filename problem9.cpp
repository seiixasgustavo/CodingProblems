#include <iostream>
#include <vector>

using namespace std;

int sumNonAdjacent(const vector<int> &list)
{
  int size = list.size();
  int sum1, sum2;

  sum1 = list[0];
  sum2 = list[1];
  for (int i = 2, temp = 0; i < size; ++i)
  {
    temp = sum2;
    sum2 = sum1 + list[i];
    sum1 = (sum1 > temp ? sum1 : temp);
  }
  return (sum1 > sum2 ? sum1 : sum2);
}

int main()
{
  vector<int> list{-2, -3, -4, -5};
  vector<int> list2{2, 4, 6, 2, 5};

  cout << sumNonAdjacent(list) << ' ' << sumNonAdjacent(list2) << endl;
  return 0;
}