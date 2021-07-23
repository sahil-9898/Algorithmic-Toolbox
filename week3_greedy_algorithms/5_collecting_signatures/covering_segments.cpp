#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using namespace std;
struct Segment
{
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  sort(segments.begin(), segments.end(), [](Segment a, Segment b)
       { return a.start < b.start; });
  int temp = segments[0].end;
  for (size_t i = 1; i < segments.size(); i++)
  {
    if (segments[i].start <= temp)
    {
      if (segments[i].end < temp)
      {
        temp = segments[i].end;
      }
      continue;
    }
    points.push_back(temp);

    temp = segments[i].end;
  }
  points.push_back(temp);
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
