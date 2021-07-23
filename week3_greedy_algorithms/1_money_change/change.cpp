#include <iostream>

int get_change(int m)
{
  int coins = 0;
  while (m != 0)
  {
    if (m >= 10)
    {
      m -= 10;
      coins++;
    }
    else if (m >= 5)
    {
      m -= 5;
      coins++;
    }
    else
    {
      m--;
      coins++;
    }
  }
  return coins;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
