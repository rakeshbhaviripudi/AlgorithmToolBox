#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
int gcd_fast(int a, int b){
    int a_per;
    while(b !=0){
        a_per = a%b;
        a= b;
        b= a_per;
    }
    return a;
}


long long lcm_fast(int a, int b){
   int gcd = gcd_fast(a,b);
   //std::cout << gcd << std::endl;
   long long lcm = ((long long) a*b)/gcd;
   return lcm;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
