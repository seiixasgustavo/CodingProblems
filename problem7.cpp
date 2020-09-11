#include <iostream>
#include <string>

using namespace std;

int decode(string toDecode)
{
  if (toDecode.length() == 0)
    return 1;
  if (toDecode.length() == 1)
    return 1;
  if (toDecode.length() == 3 && toDecode.at(2) == '0')
    return decode(toDecode.substr(1));

  auto x = stoi(toDecode.substr(0, 2));
  if (x <= 26 && x != 10 && x != 20)
    return decode(toDecode.substr(2)) + decode(toDecode.substr(1));
  else if (x == 10 || x == 20)
    return decode(toDecode.substr(2));

  return decode(toDecode.substr(1));
}

int main()
{
  cout << decode("3256") << endl;
  return 0;
}