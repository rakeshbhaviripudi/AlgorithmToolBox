//
// Created by rakesh bhaviripudi on 15/02/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

long long MaxPairwiseProduct_Best(std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();
    std::sort(numbers.begin(),numbers.end());
    return (long long)numbers[n-1]* numbers[n-2];
}

int main() {
    int n;
    cout<<"hello\n";
    return 0;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << (long long)MaxPairwiseProduct_Best(numbers) << "\n";
    return 0;
}
