#include <iostream>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
int fib_m(int a, int b)
{
    int previous = 0, current = 1;
    if (a <= 1)
        return a;
    for (int i = 0; i < a - 1; ++i)
    {
        int temp = previous;
        previous = current;
        current = (temp + previous) % b;
    }
    // cout << current << "\n";
    return current;
}
int pisano_period(int m)
{
    int first = -1, second = -1, i = 2;
    while (1)
    {
        second = fib_m(i, m);
        // cout << fib_m(i, m) << "\n";
        if (first == 0 && second == 1)
        {
            return (i - 1);
        }
        i++;
        first = second;
    }
}
int get_fibonacci_huge_fast(long long n, int m)
{
    int len = pisano_period(m);
    cout << "len: " << len << "\n";
    long long rem;
    do
    {
        rem = n % len;
        n = rem;
    } while (rem >= len);
    return fib_m(n, m);
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_fast(n, m) << '\n';
}
