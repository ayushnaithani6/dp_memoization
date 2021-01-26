// count construct  Memoization
// m = target.size(), n = wordBank.size()
// brute force --> time complexity = O((n^m) * m), space complexity = O(m*m)
// memoized --> time complexity = O(m*n*m), space complexity = O(m*m)

#include <bits/stdc++.h>
using namespace std;

// function declarations
int countConstruct(string, vector<string>);
int countConstructUtil(string, vector<string>, unordered_map<string, int>&);

// main function
int main() {
    cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << endl;                           // 2
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;                            // 1 
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;            // 0
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;          // 4 
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}); // 0
    return 0;
}

// function definitions
int countConstruct(string target, vector<string> wordBank) {
    unordered_map<string, int> memo;
    return countConstructUtil(target, wordBank, memo);
}

int countConstructUtil(string target, vector<string> wordBank, unordered_map<string, int> &memo) {
    if(memo.find(target) != memo.end()) {
        return memo[target];
    }

    if(target == "") {
        return 1;
    }

    int totalWays = 0;
    
    for(int i=0; i<wordBank.size(); ++i) {
        string word = wordBank[i];
        // check if prefix of target is word
        if(target.find(word) == 0) {
            // eg: target is "abcde" and word is "abc" then suffix will be "de"
            // substr(index, char_required) takes two arguments 1. starting index  2. no. of chars required
            string suffix = target.substr(word.size(), target.size()-word.size());
            totalWays += countConstructUtil(suffix, wordBank, memo);
        }
    }
    memo[target] = totalWays;
    return totalWays;
}
