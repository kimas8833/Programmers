#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_set<string> used_words;
    
    used_words.insert(words[0]);
    
    for(int i=1;i<words.size();++i)
    {
        string prev_word = words[i-1];
        string current_word = words[i];
        
        if(prev_word.back() != current_word.front() || used_words.count(current_word))
        {
            int played_num = (i % n) + 1;
            int turn_num = (i / n) + 1;
            
            return {played_num, turn_num};
        }
        used_words.insert(current_word);
    }


    return {0, 0};
}