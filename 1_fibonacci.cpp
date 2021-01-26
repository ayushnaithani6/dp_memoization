// Fibonacci Memoization
// brute force --> time complexity = O(2^n), space complexity = O(n)
// memoized --> time complexity = O(n), space complexity = O(n)

#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;

// function declarations 
ull fibUtil(int, unordered_map<int, ull>&);
ull fib(int);

// main function
int main() {
    cout << fib(6) << endl;    // 8
    cout << fib(7) << endl;    // 13
    cout << fib(8) << endl;    // 21
    cout << fib(50) << endl;   // 12586269025
    return 0;
} 

// function definitions
ull fib(int n) {
    unordered_map<int, ull> memo;
    return fibUtil(n, memo);
}

ull fibUtil(int n, unordered_map<int, ull> &memo) {
    if(memo.find(n) != memo.end()) {
        return memo[n];
    }
    if(n <= 2) {
        return 1;
    }
    memo[n] = fibUtil(n-1, memo) + fibUtil(n-2, memo);
    return memo[n];
}
