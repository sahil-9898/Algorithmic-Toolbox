#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
int get_fibonacci_partial_sum_fast(long long from, long long to)
{
    int len = 60;
    do
    {
        from = from % 60;
    } while (from >= len);
    do
    {
        to = to % 60;
    } while (to >= len);
    int previous = 0, current = 1, temp;
    for (int i = 2; i <= from; i++)
    {
        temp = previous;
        previous = current;
        current = (temp + previous) % 10;
    }
    int res1 = current;
    current = 1;
    previous = 0;
    for (int i = 2; i <= to; i++)
    {
        temp = previous;
        previous = current;
        current = (temp + previous) % 10;
    }
    int res2 = current;
    return res2 - res1 < 0 ? (res2 - res1) + 10 : res2 - res1;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from + 1, to + 2) << '\n';
}
