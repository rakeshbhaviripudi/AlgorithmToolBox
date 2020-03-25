#include <iostream>

int get_change(int m) {
  //write your code here
  int weight =m,remaining_weight=0,min_coins_required=0;
  int value[3] ={10,5,1};
  //int weight_value[3]= {m/10,m/5,m/1};
  while(weight != 0){
      for (int i=0; i<3; i++) {
          if(weight/value[i] > 0){
              min_coins_required += weight/value[i];
              weight = weight%value[i];
          }
      }
  }
  return min_coins_required;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
