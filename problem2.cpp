#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int> &el)
{
  int size = static_cast<int>(el.size());
  vector<int> left(size, 1), right(size, 1);
  int result = 1, result2 = 1, j = size - 1;

  for (int i = 0; i < size; i++, j--)
  {
    left[i] = result;
    result *= el[i];
    right[j] = result2;
    result2 *= el[j];
  }

  for (int i = 0; i < size; i++)
  {
    left[i] = left[i] * right[i];
  }

  return left;
}

void printAns(const vector<int> &el)
{
  for (auto x : el)
  {
    cout << x << ' ';
  }
  cout << '\n';
}

int main()
{
  const vector<int> el{1, 2, 3, 4, 5};
  auto ans = multiply(el);
  printAns(ans);
  return 0;
}