#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
using std::vector;
using std::pair;
using std::make_pair;
using std:: reverse;
double get_optimal_value1(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int W = capacity;
  int n;
  n = values.size();
  //std::cout<<"n is:" <<n;
    vector<double> v_w_ratio(n);
    vector<pair<double,int>>vect;
    for(int i=0; i<n; i++){
        v_w_ratio[i] = ((double)values[i])/(weights[i]);
    }
    for(int i=0; i<n; i++){
        vect.push_back(make_pair(v_w_ratio[i],i));
    }

  std:: sort(vect.rbegin(), vect.rend());
   // std:: sort(vect.begin(), vect.end());
//    for(int i=0; i<n; i++){
//      std::cout<<vect[i].first<<" "<<vect[i].second<<std::endl;
//    }
    double weight =0.0;
    vector<float>x(n);
    for(int i=0; i<n; i++){
        x[i]=0;
    }
    int i=0;
    while((weight<= W) && (i<n)){
       // std::cout<<weight<<'\n';

        if(weight + weights[vect[i].second]<= W){
            x[vect[i].second]+=1;
            weight += weights[vect[i].second];
        }
        else{
            x[vect[i].second] = ((double)(W-weight))/(weights[vect[i].second]);
            weight += (double)weights[vect[i].second]* x[i];
        }
        i++;
       // std::cout<<i<<'\n';
    }
    for(int i=0; i<n;i++){
//       std::cout<<x[i]<<" ";
        value += x[i] * values[i];
    }
   // std::cout<<'\n';
  return value;
}

int get_max_index(vector<int> weights, vector<int> values) {
    int max_i = 0;
    double max = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
            max = (double) values[i] / weights[i];
            max_i = i;
        }
    }
    return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    for (int i = 0; i < weights.size(); i++) {
        if (capacity == 0) return value;
        int index = get_max_index(weights, values);
        int a = std::min(capacity, weights[index]);
        value += a * (double) values[index] / weights[index];
        weights[index] -= a;
        capacity -= a;
    }

    return value;
}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  //std::cout<<"CHECK 1:";
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  //std::cout<<"CHECK 2:";
  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

/*
 *
3 50
60 20
100 50
120 30

3 57
60 20
100 50
120 30


1 10
500 30


1 10000
500 30

2 50
60 10
100 20

3 50
60 10
100 20
120 30

 * */