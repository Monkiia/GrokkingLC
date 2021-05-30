using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
public:
    static vector<int> findStringAnagrams(const string &str, const string &pattern) {
        vector<int> resultIndices;
        int pinnedstart = 0;
        unordered_map<char,int> patternmap;
        unordered_map<char,int> windowmap;
        for (int pi = 0; pi < pattern.size(); pi++) {
            if (patternmap.count(pattern[pi]) == 0) {
                patternmap[pattern[pi]] = 1;
            }
            else {
                patternmap[pattern[pi]]++;
            }
            windowmap[pattern[pi]] = 0;
        }
        int distinctchar = patternmap.size();
        int match = 0;
        for (int i = 0; i < str.size() ; i++) {
            if (i < pattern.size()) {
                windowmap[str[i]]++;
            }
            else {
                windowmap[str[pinnedstart]]--;
                if (windowmap[str[pinnedstart]] + 1 == patternmap[str[pinnedstart]]) {
                    match--;
                }
                windowmap[str[i]]++;
                pinnedstart++;
            }
            if (windowmap[str[i]] == patternmap[str[i]]) {
                match++;
                if (match == distinctchar) {
                    resultIndices.push_back(pinnedstart);
                }
            }
        }
        // TODO: Write your code here
        return resultIndices;
    }
};
