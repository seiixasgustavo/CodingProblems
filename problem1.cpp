#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool hasValue(const vector<int> &list, int sum)
{
  unordered_set<int> complements;
  for (int e : list)
  {
    if (complements.find(e) != complements.end())
      return true;
    complements.insert(sum - e);
  }

  return false;
}

int main()
{
  int sum = 7;
  vector<int> elements = {1, 2, 3, 4};

  cout << (hasValue(elements, sum) == true ? "true" : "false") << '\n';
}
