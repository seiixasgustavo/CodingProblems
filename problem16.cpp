#include <iostream>
#include <vector>

using namespace std;

struct recorder
{
  vector<int> list;
  int currentIndex;
  int maxSize;

  recorder(int maxSize) : maxSize(maxSize), currentIndex(0), list(vector<int>(maxSize, 0)){};

  void record(int id)
  {
    list[currentIndex] = id;
    currentIndex = (currentIndex + 1) % maxSize;
  }

  int getIthElement(int i)
  {
    return list[(currentIndex - i - 1 + maxSize) % maxSize];
  }
};

int main()
{
  recorder x = recorder(5);

  x.record(1);
  x.record(2);
  x.record(3);
  x.record(4);
  x.record(5);
  x.record(6);

  cout << x.getIthElement(0) << endl;
  cout << x.getIthElement(1) << endl;
  cout << x.getIthElement(2) << endl;
  cout << x.getIthElement(3) << endl;
  cout << x.getIthElement(4) << endl;

  return 0;
}