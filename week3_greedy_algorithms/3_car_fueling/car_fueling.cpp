#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    int refills = 0;
    int last = 0;
    int index = 0;
    stops.push_back(dist);
    int len = stops.size();
    while (true)
    {
        while ((stops[index] - last <= tank) && (index < len))
        {
            index++;
        }
        if (stops[index - 1] == last)
        {
            return -1;
        }
        if (index == len)
        {
            break;
        }
        refills++;
        last = stops[index - 1];
    }
    return refills;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 1);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    stops[n] = d;
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
