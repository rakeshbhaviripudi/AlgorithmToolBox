#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};
bool compareSegmentsByEnd(Segment &s1, Segment &s2){
    return s1.end < s2.end;
}
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int min_end_value;
  //write your code here
  std::sort(segments.begin(),segments.end(),compareSegmentsByEnd);
  min_end_value = -1;
    for (size_t i = 0; i < segments.size(); ++i) {
        if(min_end_value < segments[i].start) {
            min_end_value = segments[i].end;
            points.push_back(min_end_value);
        }

    }
//  for (size_t i = 0; i < segments.size(); ++i) {
//    points.push_back(segments[i].start);
//    points.push_back(segments[i].end);
//  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
/*
 *
 *
3
1 3
2 5
3 6

4
4 7
1 3
2 5
5 6

 */