#include <iostream>
using namespace std;

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum = (sum + current) % 10;
    }

    return sum % 10;
}
int fibonacci_sum_fast(long long n)
{
    int len = 60;
    do
    {
        n = n % 60;
    } while (n >= len);
    int previous = 0;
    int current = 1;
    int temp;
    for (int i = 2; i <= n; i++)
    {
        temp = previous;
        previous = current;
        current = (previous + temp) % 10;
    }
    return current == 0 ? 9 : current - 1;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n + 2);
}
