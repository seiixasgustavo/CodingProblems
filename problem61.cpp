#include <iostream>

using namespace std;

float manualPow(float x, int y)
{
  if (y == 0)
    return 1;
  if (y == 1)
    return x;
  auto aux = manualPow(x, y / 2);

  if (y % 2 == 0)
    return aux * aux;
  else
  {
    if (y > 0)
      return x * aux * aux;
    return (aux * aux) / x;
  }
}

int main()
{
  cout << manualPow(2, -4) << endl;
  return 0;
}