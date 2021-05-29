using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
public:
    static int findLength(const string& str) {
        int maxLength = 0;
        // TODO: Write your code here
        unordered_map<char,int> hashmap;
        int distinctcount = 0;
        int maximumdistinctcount = 0;
        int pinnedstart = 0;
        for (int i = 0; i < str.size(); i++) {
            if (hashmap.count(str[i]) == 0) {
                hashmap[str[i]]++;
                distinctcount++;
                maximumdistinctcount = max(maximumdistinctcount,distinctcount);
            }
            else {
                if (hashmap[str[i]] == 0) {
                    hashmap[str[i]]++;
                    distinctcount++;
                    maximumdistinctcount = max(maximumdistinctcount,distinctcount);
                }
                else {
                    while (hashmap[str[i]] != 0) {
                        hashmap[str[pinnedstart]]--;
                        pinnedstart++;
                        distinctcount--;
                    }
                    hashmap[str[i]]++;
                    distinctcount++;
                }
            }
        }
        return maximumdistinctcount;
    }
};
