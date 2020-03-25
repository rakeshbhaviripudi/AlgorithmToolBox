#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
void multiply(int F[2][2], int M[2][2],int m)
{
    int x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x%m;
    F[0][1] = y%m;
    F[1][0] = z%m;
    F[1][1] = w%m;
}



void power(int F[2][2], long long n,int m)
{
    if( n == 0 || n == 1)
        return;
    int M[2][2] = {{1,1},{1,0}};

    power(F, n/2,m);
    multiply(F, F,m);

    if (n%2 != 0)
        multiply(F, M,m);
}
/* Optimized version of power() in method 4 */

long long fibonacci_sum_naive(long long n, int m) {
    int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1,m);
    return F[0][0];
}

long long get_fibonacci_partial_sum_fast(long long from, long long to){
    long long sum_till_from = fibonacci_sum_naive(from+1,10)-1+10;
   // std::cout<<from <<" "<<sum_till_from<<std::endl;

    long long sum_till_to = fibonacci_sum_naive(to+2,10)-1+10;
   // std::cout<< to<<" "<<sum_till_to<<std::endl;
    return (sum_till_to-sum_till_from +10)%10;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}


