#include <iostream>
using namespace std;

int fibonacci_sum_squares_naive(long long n)
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
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int fibonacci_sum_squares_fast(long long n)
{
    if (n == 0)
        return 0;
    int len = 60;
    long long m = n + 1;
    do
    {
        n = n % 60;
    } while (n >= len);
    int previous = 0, current = 1, temp;
    if (n == 0)
        current = 0;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            temp = previous;
            previous = current;
            current = (temp + previous) % 10;
        }
    }
    int res = current;
    do
    {
        m = m % 60;
    } while (m >= len);
    previous = 0;
    current = 1;
    if (m == 0)
        current = 0;
    else
    {
        for (int i = 2; i <= m; i++)
        {
            temp = previous;
            previous = current;
            current = (temp + previous) % 10;
        }
    }
    return (res * current) % 10;
}
int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
