// grid traveller  Memoization
// m = rows of grid, n = cols of grid
// brute force --> time complexity = O(2^(m+n)), space complexity = O(m+n)
// memoized --> time complexity = O(m*n), space complexity = O(m+n)

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

// function declarations
ull gridTraveler(int, int);
ull gridTravelerUtil(int, int, unordered_map<string, ull>&); 

// main function
int main() {
    cout << gridTraveler(1, 1) << endl;      // 1
    cout << gridTraveler(2, 3) << endl;      // 3
    cout << gridTraveler(3, 2) << endl;      // 3
    cout << gridTraveler(3, 3) << endl;      // 6
    cout << gridTraveler(18, 18) << endl;    // 2333606220
    return 0;
}

// function definitions
ull gridTraveler(int m, int n) {
    unordered_map<string, ull> memo;
    return gridTravelerUtil(m, n, memo);
}

ull gridTravelerUtil(int m, int n, unordered_map<string, ull> &memo) {
    string key = to_string(m) + ',' + to_string(n);

    if(memo[key]) {
        return memo[key];
    }

    if(m == 1 && n == 1) {
        return 1;
    }
    if(m == 0 || n == 0) {
        return 0;
    }
    memo[key] = gridTravelerUtil(m-1, n, memo) + gridTravelerUtil(m, n-1, memo);
    return memo[key];
}