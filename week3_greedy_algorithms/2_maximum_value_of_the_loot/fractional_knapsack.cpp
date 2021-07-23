#include <iostream>
#include <cstdio>
#include <vector>

using std::vector;
using namespace std;

int get_max_value_index(vector<int> weights, vector<int> values)
{
  double max = 0;
  int index = 0;
  int n = weights.size();
  for (int i = 0; i < n; i++)
  {
    if (weights[i] > 0)
    {
      if (((double)values[i] / weights[i]) > max)
      {
        max = (double)values[i] / weights[i];
        index = i;
      }
    }
  }
  return index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int len = weights.size();
  for (int i = 0; i < len; i++)
  {
    if (capacity == 0)
    {
      return value;
    }
    int maxIndex = get_max_value_index(weights, values);
    if (capacity < weights[maxIndex])
    {
      value += (double)capacity * ((double)values[maxIndex] / weights[maxIndex]);
      weights[maxIndex] -= capacity;
      capacity -= capacity;
    }
    else
    {
      value += (double)values[maxIndex];
      capacity -= weights[maxIndex];
      weights[maxIndex] = 0;
    }
  }
  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  printf("%.4f\n", optimal_value);
  return 0;
}
