// all construct  Memoization
// time and space complexity of this is quite tricky
// one case is target = "aaaaaaaaaaaaaaaaaaa" and wordBank = {"a", "aa", "aaa", "aaaa"}
// worst case time complexity remains exponential after memoization also i.e (O(n^m)) 
// n being wordBank.size() and m being target.size()
// we can include other factors like making result 
// matrix for every recursive call and copying it
// for space complexity this is O(m) for exponential complexity we usually don,t take output size in space complexity

#include <bits/stdc++.h>
using namespace std;

// function declarations
vector<vector<string>> allConstructUtil(string, vector<string>, unordered_map<string, vector<vector<string>>>&);
vector<vector<string>> allConstruct(string, vector<string>);
void printAns(vector<vector<string>>);



int main() {
    // allConstruct returns vector of vectors of string i.e vector<vector<string>> 
    // which is passed as an argument for printAns for printing the output

    printAns(allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}));  
        // [
        //     [purp, le]
        //     [p, ur, p, le]
        // ]       

    printAns(allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"})); 
        // [
        //     [abc, def]
        // ]

    printAns(allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}));    
        //     []

    printAns(allConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}));        
        // [
        //     [enter, a, p, ot, ent, p, ot]
        //     [enter, a, p, ot, ent, p, o, t]
        //     [enter, a, p, o, t, ent, p, ot]
        //     [enter, a, p, o, t, ent, p, o, t]
        // ]

    printAns(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}));
        //     []

    
    return 0;
}

vector<vector<string>> allConstruct(string target, vector<string> wordBank) {
    unordered_map<string, vector<vector<string>>> memo;
    return allConstructUtil(target, wordBank, memo);
}

vector<vector<string>> allConstructUtil(string target, vector<string> wordBank, unordered_map<string, vector<vector<string>>> &memo) {
    if(memo.find(target) != memo.end()) {
        return memo[target];
    }

    if(target == "") {
        return {{}};
    }

    vector<vector<string>> result;
    for(int i=0; i<wordBank.size(); ++i) {
        string word = wordBank[i];
        // check if prefix of target is word
        if(target.find(word) == 0) {
            string suffix = target.substr(word.size(), target.size()-word.size());
            vector<vector<string>> suffixWays = allConstructUtil(suffix, wordBank, memo);
            // if suffix has ways then at base case {{}} of size 1  will be return else {} of size 0
            for(int i=0; i<suffixWays.size(); ++i) {
                suffixWays[i].push_back(word);
                // also push all the ways of target(in particular instance of recursive call) into result
                result.push_back(suffixWays[i]);
            }
        }
    }
    memo[target] = result;
    return result;
}

void printAns(vector<vector<string>> allCombination) {
    cout << "[" << endl;
    for(int i=0; i<allCombination.size(); ++i) {
        cout << "  [";
        
        for(int j=allCombination[i].size()-1; j>=0; --j) {
            cout << allCombination[i][j] << "  ";
        }
        cout << "]";
        cout << endl;
    }
    cout << "]";
    cout << endl << endl << endl;
}
