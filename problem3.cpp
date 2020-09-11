#include <iostream>

using namespace std;

class node
{
public:
  char value;
  node *left;
  node *right;
  node();
  node(int);
  node(int, node *, node *);
  string serialize(node *);
  node *deserialize(string &, node *);
  void printInOrder(node *);
};

node::node() : value(0), left(nullptr), right(nullptr) {}

node::node(int value)
{
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
}

node::node(int value, node *left, node *right)
{
  this->value = value;
  this->left = left;
  this->right = right;
}

string node::serialize(node *n)
{
  string result = "";
  if (n == nullptr)
    return "#-";
  result += to_string(n->value) + '-';
  result += serialize(n->left);
  result += serialize(n->right);
  return result;
}

node *node::deserialize(string &s, node *root)
{
  if (s.size() == 0)
    return nullptr;
  if (s[0] == '#')
  {
    s.erase(0, 2);
    return nullptr;
  }
  size_t pos = s.find('-');
  int ele = stoi(s.substr(0, pos));
  root = new node(ele);
  s.erase(0, pos + 1);
  root->left = deserialize(s, root->left);
  root->right = deserialize(s, root->right);
  return root;
}

void node::printInOrder(node *root)
{
  if (root == nullptr)
    return;
  cout << to_string(root->value) << ' ';
  printInOrder(root->left);
  printInOrder(root->right);
}

int main()
{
  node x;
  string result = x.serialize(
      new node(10,
               new node(20, new node(30), new node(40)),
               new node(35)));
  cout << result << endl;
  node *v = nullptr;
  v = x.deserialize(result, v);
  //cout << v->value << '\n';
  x.printInOrder(v);
  return 0;
}
