#include <iostream>
#include <vector>

#define ALPHABET_SIZE 26

using namespace std;

bool isValid(vector<int> kChars, int k)
{
  int value = 0;
  for (int i = 0; i < ALPHABET_SIZE; i++)
    if (kChars[i] > 0)
      value++;
  return (k >= value);
}

string longestSubstring(string str, int k)
{
  int cur_start, cur_size, max_start = 0, max_size = 0;
  vector<int> kChars(ALPHABET_SIZE, 0);

  for (int i = 0; i < str.size(); ++i)
    kChars[(str[i] - 'a')]++;
  if (isValid(kChars, k))
    return "";

  kChars.clear();
  kChars = vector<int>(ALPHABET_SIZE, 0);

  cur_start = 0;
  cur_size = 1;
  kChars[(str[0] - 'a')]++;

  for (int i = 1; i < str.size(); ++i)
  {
    kChars[str[i] - 'a']++;
    cur_size++;
    while (!isValid(kChars, k))
    {
      kChars[str[cur_start] - 'a']--;
      cur_start++;
      cur_size--;
    }
    if (cur_size > max_size)
    {
      max_start = cur_start;
      max_size = cur_size;
    }
  }

  return str.substr(max_start, max_size);
}

int main()
{
  cout << longestSubstring("aabacbebebe", 3) << endl;
  return 0;
}