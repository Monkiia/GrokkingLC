using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
public:
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        // TODO: Write your code here
        int maxfrequencyletter = 0;
        unordered_map<char,int> freqmap;
        int pinnedstart = 0;
        int maxresult = 0;
        for (int i = 0; i < str.size() ; i++) {
            if (freqmap.count(str[i]) == 0) {
                freqmap[str[i]] = 1;
            }
            else {
                freqmap[str[i]]++;
            }
            maxfrequencyletter = max(maxfrequencyletter,freqmap[str[i]]);
            while (i - pinnedstart + 1 - maxfrequencyletter > k) {
                freqmap[str[pinnedstart]]--;
                pinnedstart++;
            }
            maxresult = max(maxresult,i-pinnedstart+1);
        }
        return maxresult;
    }
};
