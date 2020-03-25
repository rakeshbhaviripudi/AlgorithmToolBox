#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int L = tank;
    int n=stops.size();
    int numRefill=0;
    int currentFill =0;
    int previousFill=0;
    while(tank < dist){
        previousFill = currentFill;
        while((currentFill<n) && (stops[currentFill]<=tank)){
            currentFill++;
        }
        if(previousFill == currentFill) return -1;
        numRefill++;
        tank = L+ stops[currentFill-1];
    }
    return numRefill;

}

int compute_min_refills_tut(int dist, int tank, vector<int> & stops) {
    int n = stops.size();
    vector<int> solution(n+2);
    solution[0] =0;
    solution[n+1]= dist;
    for(int i=1; i<=n; i++){
        solution[i]= stops[i-1];
    }
    int currentFill=0, previousFill, noOfRefills=0;
    while(currentFill<=n){
        previousFill = currentFill;
        while(((solution[currentFill+1]-solution[previousFill])<=tank) && (currentFill<=n)){
            currentFill++;
        }
        if(currentFill == previousFill) return -1;
        else if((currentFill<=n)){
            noOfRefills++;
        }
    }
    return noOfRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    //cout << compute_min_refills_tut(d, m, stops) << "\n";
    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;
}
/*
 *
950
400
4
200 375 550 750


10
3
4
1 2 5 9


200
250
2
100
150


 */

