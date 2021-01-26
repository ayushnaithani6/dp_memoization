// can Sum  Memoization
// m = targetSum, n = numbers.size()
// brute force --> time complexity = O(n^m), space complexity = O(m)
// memoized --> time complexity = O(m*n), space complexity = O(m)
#include <bits/stdc++.h>
using namespace std;

// function declaration
bool canSum(int, vector<int>);
bool canSumUtil(int, vector<int>, unordered_map<int, bool>&);


// main function
int main() {
    cout << canSum(7, {2, 3}) << endl;         // 1  (1 is true)
    cout << canSum(7, {5, 3, 4, 7}) << endl;   // 1
    cout << canSum(7, {2, 4}) << endl;         // 0 (0 is false)
    cout << canSum(8, {2, 3, 5}) << endl;      // 1
    cout << canSum(300, {7, 14}) << endl;      // 0
    return 0;
}


// function definition
bool canSum(int targetSum, vector<int> numbers) {
    unordered_map<int, bool> memo;
    return canSumUtil(targetSum, numbers, memo);
}

bool canSumUtil(int targetSum, vector<int> numbers, unordered_map<int, bool> &memo) {
    if(memo.find(targetSum) != memo.end()) {
        return memo[targetSum];
    }
    if(targetSum == 0) {
        return true;
    }

    if(targetSum < 0) {
        return false;
    }

    for(int i=0; i<numbers.size(); ++i) {
        int remainder = targetSum-numbers[i];
        if(canSumUtil(remainder, numbers, memo)) {
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}

