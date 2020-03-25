#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
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

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << ((fibonacci_sum_naive(n+2,10)-1+10)%10);
}
