#include <algorithm>
#include <sstream>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std;

bool GreaterOrEqual(string& a, string& b) {
    return (b + a > a + b);
}

string largest_number(vector<string> a) {
  //write your code here
  int n = a.size();
    for (size_t i = 1; i < n; i++) {
        for (size_t j = 0; j < n - i; j++) {
            if (GreaterOrEqual(a[j], a[j + 1])) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    stringstream Salary;
    for (size_t i = 0; i < n; i++) {
        Salary << a[i];
    }
    return Salary.str();
}


int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
  //std::cout << largest_number_handbook(a);
}
/*
 *
 5
9 4 6 1 9

 3
23 39 92

 2
21 2


 */