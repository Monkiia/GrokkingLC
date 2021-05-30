using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubstring {
public:
    static string findSubstring(const string &str, const string &pattern) {
        // TODO: Write your code here
        printf("New Test \n");
        unordered_map<char,int> patternmap;
        unordered_map<char,int> windowmap;
        int matches = 0;
        int minsize = 9999;
        int pinnedstart = 0;
        string result = "";
        for (int i = 0; i < pattern.size() ; i++) {
            if (patternmap.count(pattern[i]) ==  0) {
                patternmap[pattern[i]] = 1;
            }
            else {
                patternmap[pattern[i]]++;
            }
            windowmap[pattern[i]] = 0;
        }
        int distinctcount = patternmap.size();
        for (int i = 0; i < str.size() ; i++) {
            if (patternmap.count(str[i]) != 0) {
                windowmap[str[i]]++;
                if (windowmap[str[i]] == patternmap[str[i]]) {
                    matches++;
                }
                while (matches == distinctcount) {
                    printf("AM I HERE \n");
                    minsize = min(minsize, i - pinnedstart + 1);
                    printf("minsize is %d \n",minsize);
                    if (minsize == i - pinnedstart + 1) {
                        result = str.substr(pinnedstart, i - pinnedstart + 1);
                    }
                    printf("result: %s \n",result.c_str());
                    if (patternmap.count(str[pinnedstart]) != 0) {
                        windowmap[str[pinnedstart]]--;
                        if (windowmap[str[pinnedstart]] + 1 == patternmap[str[pinnedstart]]) {
                            matches--;
                        }
                    }
                    pinnedstart++;
                }
            }
        }
        return result;
    }
};
