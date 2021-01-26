// can construct  Memoization
// m = target.size(), n = wordBank.size()
// brute force --> time complexity = O((n^m) * m), space complexity = O(m*m)
// memoized --> time complexity = O(m*n*m), space complexity = O(m*m)

#include <bits/stdc++.h>
using namespace std;

// function declarations
bool canConstruct(string, vector<string>);
bool canConstructUtil(string, vector<string>, unordered_map<string, bool>&);

// main function
int main() {
    cout << canConstruct("abcdef", {"ab", "abc", "cd", "ef", "abcd"}) << endl;                            // 1 (1 is true)
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;            // 0 (0 is false)
    cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;          // 1 
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}); // 0
}

// function definitions
bool canConstruct(string target, vector<string> wordBank) {
    unordered_map<string, bool> memo;
    return canConstructUtil(target, wordBank, memo);
}

bool canConstructUtil(string target, vector<string> wordBank, unordered_map<string, bool> &memo) {
    if(memo.find(target) != memo.end()) {
        return memo[target];
    }

    if(target == "") {
        return true;
    }

    for(int i=0; i<wordBank.size(); ++i) {
        string word = wordBank[i];
        // check if prefix of target is word
        if(target.find(word) == 0) {
            // eg: target is "abcde" and word is "abc" then suffix will be "de"
            // substr(index, char_required) takes two arguments 1. starting index  2. no. of chars required
            string suffix = target.substr(word.size(), target.size()-word.size());
            if(canConstructUtil(suffix, wordBank, memo)) {
                memo[target] = true;
                return true;
            }
        }
    }
    memo[target] = false;
    return false;
}
