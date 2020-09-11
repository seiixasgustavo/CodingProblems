#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void deleteNegativeNumbers(vector<int> &numbers)
{
  int j = 0;
  for (int i = 0; i < numbers.size(); i++)
  {
    if (numbers[i] <= 0)
    {
      swap(numbers[i], numbers[j]);
      j++;
    }
  }
  numbers.erase(numbers.begin(), numbers.begin() + j);
}

int lowestPositiveInteger(vector<int> &numbers)
{
  deleteNegativeNumbers(numbers);
  vector<bool> haveInteger(numbers.size(), false);
  for (auto x : numbers)
  {
    if (x <= numbers.size())
      haveInteger[x - 1] = true;
  }

  int i = 0;
  for (i = 0; i <= haveInteger.size(); i++)
  {
    if (haveInteger[i] == false)
      return i + 1;
  }

  return i + 1;
}

int main()
{
  vector<int> numbers{1, 2, 3, 4};
  vector<int> numbers2{3, 4, 1, -1};
  cout << lowestPositiveInteger(numbers) << ' ' << lowestPositiveInteger(numbers2) << '\n';
  return 0;
}