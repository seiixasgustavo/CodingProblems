#include <iostream>
#include <vector>

#define ALPHABET_SIZE 26

using namespace std;

struct Trie
{
  char value;
  bool isWord;
  Trie *children[ALPHABET_SIZE];

  Trie(char value) : value(value), isWord(false)
  {
    for (int i = 0; i < ALPHABET_SIZE; ++i)
      children[i] = nullptr;
  };
};

bool isLeaf(Trie *root)
{
  for (int i = 0; i < ALPHABET_SIZE; ++i)
    if (root->children[i] != nullptr)
      return false;
  return true;
}

void insert(Trie *root, string value)
{
  auto aux = root;
  for (int i = 0, index = 0; i < value.size(); ++i)
  {
    index = value[i] - 'a';
    if (aux->children[index] == nullptr)
      aux->children[index] = new Trie(value[i]);
    aux = aux->children[index];
    if (i == value.size() - 1)
      aux->isWord = true;
  }
}

void findWords(Trie *root, vector<string> &value, string word)
{
  if (root == nullptr)
    return;
  if (root->isWord)
    value.push_back(word);
  if (isLeaf(root))
    return;
  for (int i = 0; i < ALPHABET_SIZE; ++i)
  {
    word.push_back((i + 'a'));
    findWords(root->children[i], value, word);
    word.pop_back();
  }
}

vector<string> find(Trie *root, string value)
{
  auto aux = root;
  int index;
  for (auto e : value)
  {
    index = e - 'a';
    if (aux->children[index] == nullptr)
      return vector<string>();
    aux = aux->children[index];
  }
  vector<string> ans;
  findWords(aux, ans, value);
  return ans;
}

int main()
{
  vector<string> list{"deal", "deer", "dog"};
  Trie *root = new Trie('0');
  for (auto x : list)
    insert(root, x);
  auto ans = find(root, "de");
  for (auto x : ans)
    cout << x << ' ';
  cout << endl;
  return 0;
};
