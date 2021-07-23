#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::string;
using std::vector;

bool greater_between(string a, string b)
{
  return (stoi(a + b) > stoi(b + a));
}

string largest_number(vector<string> a)
{
  //write your code here
  string result;
  for (size_t i = 0; i < a.size(); i++)
  {
    for (size_t j = i; j < a.size(); j++)
    {
      if (greater_between(a[j], a[i]))
      {
        string temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  for (size_t i = 0; i < a.size(); i++)
  {
    result += a[i];
  }
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
