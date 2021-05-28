using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
public:
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        // TODO: Write your code here
        unordered_map<char,int> hashmap;
        int distinctcount = 0;
        int pinstart = 0;
        int maxcount = 0;
        for (int i = 0; i < str.size(); i++) {
            while (distinctcount == k) {
                maxcount = max(maxcount, i - pinstart + 1);
                hashmap[str[pinstart]]--;
                if (hashmap[str[pinstart]]==0) {
                    distinctcount--;
                    pinstart++;
                    break;
                }
                pinstart++;
            }
            if (hashmap.count(str[i]) == 0) {
                hashmap[str[i]] = 1;
                distinctcount++;
            }
            else {
                if (hashmap[str[i]] == 0) {
                    distinctcount++;
                }
                hashmap[str[i]]++;
            }
        }
        return maxcount;
    }
};
