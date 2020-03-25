#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int previous_prize_value, current_price_value=0;
  while(n > 0){
      previous_prize_value = current_price_value;
      if(n == 1) {
          summands.push_back(1);
      }
      else if (n==2){
       while((n>0) && ())
      }
  }
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
