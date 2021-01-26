// best Sum  Memoization
// m = targetSum, n = numbers.size()
// brute force --> time complexity = O((n^m) * m), space complexity = O(m)
// memoized --> time complexity = O(m*n*m), space complexity = O(m*m)

#include <bits/stdc++.h>
using namespace std;

// function declaration
vector<int> bestSum(int, vector<int>);
vector<int> bestSumUtil(int, vector<int>, unordered_map<int, vector<int>>&);
void printAns(vector<int>);

// main function
int main() {
    // bestSum returns vector<int> it is passed as an argument to function printAns() 
    // see definition of printAns() for more clarity 
    printAns(bestSum(7, {2, 3}));              // [3, 2, 2]
    printAns(bestSum(7, {5, 3, 4, 7}));        // [7]
    printAns(bestSum(7, {2, 4}));             // []
    printAns(bestSum(8, {2, 3, 5}));          // [5, 3]
    printAns(bestSum(300, {7, 14}));          // []
    printAns(bestSum(8, {1, 4, 5}));          // [4, 4]
    printAns(bestSum(100, {1, 2, 5, 25}));    // [25, 25, 25, 25]
    return 0;
}


// function definition
vector<int> bestSum(int targetSum, vector<int> numbers) {
    unordered_map<int, vector<int>> memo;
    return bestSumUtil(targetSum, numbers, memo);
}

vector<int> bestSumUtil(int targetSum, vector<int> numbers, unordered_map<int, vector<int>> &memo) {
    if(memo.find(targetSum) != memo.end()) {
        return memo[targetSum];
    }
    if(targetSum == 0) {
        return {};
    }

    if(targetSum < 0) {
        return {INT_MIN};
    }

    vector<int> shortestCombination = {INT_MIN};

    for(int i=0; i<numbers.size(); ++i) {
        int remainder = targetSum-numbers[i];
        vector<int> combination = bestSumUtil(remainder, numbers, memo);
        if(combination != (vector<int>){INT_MIN}) {
            combination.push_back(numbers[i]);
            if(shortestCombination == (vector<int>){INT_MIN} || shortestCombination.size() > combination.size()) {
                shortestCombination = combination;
            }
        }

    }
    memo[targetSum] = shortestCombination;
    return shortestCombination;
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