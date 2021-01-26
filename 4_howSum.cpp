// how Sum  Memoization
// m = targetSum, n = numbers.size()
// brute force --> time complexity = O((n^m) * m), space complexity = O(m*m)
// memoized --> time complexity = O(m*n*m), space complexity = O(m*m)

#include <bits/stdc++.h>
using namespace std;

// function declaration
vector<int> howSum(int, vector<int>);
vector<int> howSumUtil(int, vector<int>, unordered_map<int, vector<int>>&);
void printAns(vector<int>);

// main function
int main() {
    // howSum returns vector<int> it is passed as an argument to function printAns() 
    // see definition of printAns() for more clarity 
    printAns(howSum(7, {2, 3}));              // [3, 2, 2]
    printAns(howSum(7, {5, 3, 4, 7}));        // [4, 3]
    printAns(howSum(7, {2, 4}));             // []
    printAns(howSum(8, {2, 3, 5}));          // [2, 2, 2, 2]
    printAns(howSum(300, {7, 14}));          // []
    return 0;
}


// function definition
vector<int> howSum(int targetSum, vector<int> numbers) {
    unordered_map<int, vector<int>> memo;
    return howSumUtil(targetSum, numbers, memo);
}

vector<int> howSumUtil(int targetSum, vector<int> numbers, unordered_map<int, vector<int>> &memo) {
    if(memo.find(targetSum) != memo.end()) {
        return memo[targetSum];
    }
    if(targetSum == 0) {
        return {};
    }

    if(targetSum < 0) {
        return {INT_MIN};
    }

    for(int i=0; i<numbers.size(); ++i) {
        int remainder = targetSum-numbers[i];
        vector<int> combination = howSumUtil(remainder, numbers, memo);
        if(combination != (vector<int>){INT_MIN}) {
            combination.push_back(numbers[i]);
            memo[targetSum] = combination;
            return combination;
        }

    }
    memo[targetSum] = {INT_MIN};
    return {INT_MIN};
}

void printAns(vector<int> combination) {
    // if first element is INT_MIN then no combinations are possible for making targetSum
    // in this case combination vector only contains single element i.e INT_MIN
    cout << "[";
    if(combination[0] != INT_MIN) {
        int n = combination.size();
        for(int i=0; i<n-1; ++i) {
            cout << combination[i] << ", ";
        }
        cout << combination[n-1];
    }
    cout << "]";
    cout << endl;
}