#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last_digit_fast(int n) {
    // write your code here
    int fib_array[n];
    fib_array[0] =0;
    fib_array[1] =1;
    if (n<= 1) return n;
    else{
        for(int i =2; i<=n; i++){
            fib_array[i] = ((fib_array[i-1] + fib_array[i-2])%10);

        }
    }
    return (long long)fib_array[n];
}

void test_solution() {
    for (int n = 0; n < 20; ++n){
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
    }
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    //std::cout << c << '\n';
    //test_solution();
    int c1 = get_fibonacci_last_digit_fast(n);
    std::cout <<c1 << '\n';
    }
