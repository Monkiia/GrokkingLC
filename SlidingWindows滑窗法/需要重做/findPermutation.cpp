// 不是最优解，复杂度 O(MN),  最优解复杂度 O(M+N)
using namespace std;

#include <iostream>
#include <string>
#include <map>

class StringPermutation {
public:
    static bool findPermutation(const string &str, const string &pattern) {
        // TODO: Write your code here
        printf("New Test \n");
        map<char,int> patternmap;
        map<char,int> windowmap;
        int pinnedstart = 0;
        for (int patterniter = 0; patterniter < pattern.size() ; patterniter++) {
            if (patternmap.count(pattern[patterniter])==0) {
                patternmap[pattern[patterniter]] = 1;
            }
            else {
                patternmap[pattern[patterniter]]++;
            }
            windowmap[pattern[patterniter]] = 0;
        }
        for (int i = 0 ; i < str.size() ; i++) {
            if (i < pattern.size()) {
                windowmap[str[i]]++;
            }
            else {
                windowmap[str[i]]++;
                windowmap[str[pinnedstart]]--;
                pinnedstart++;
            }
            if (i - pinnedstart + 1 == pattern.size()) {
                bool result = true;
                for (const auto mypair : patternmap) {
                    result = result && (patternmap[mypair.first] == windowmap[mypair.first]);
                    //printf("character %c, patternmap count %d, windowmap count %d \n",mypair.first,patternmap[mypair.first],windowmap[mypair.first]);
                }
                if (result == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
