#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  int current = 1, next = 2, sum = 0;
  while (sum != n)
  {
    if ((sum + current + next) <= n)
    {
      summands.push_back(current);
      sum += current;
      current++;
      next++;
    }
    else
    {
      current = n - sum;
      summands.push_back(current);
      sum += current;
    }
  }
  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
}
