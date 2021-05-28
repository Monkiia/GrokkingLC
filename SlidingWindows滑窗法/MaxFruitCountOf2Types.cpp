using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
public:
    static int findLength(const vector<char>& arr) {
        int maxLength = 0;
        // TODO: Write your code here
        unordered_map<char,int> hashmap;
        int maxcount = 0;
        int distinctcount = 0;
        int pinnedstart = 0;
        for (int i = 0; i < arr.size() ; i++) {
            if (hashmap.count(arr[i])== 0) {
                hashmap[arr[i]] = 1;
                distinctcount++;
            }
            else {
                if (hashmap[arr[i]]== 0) {
                    distinctcount++;
                }
                hashmap[arr[i]]++;
            }
            while (distinctcount > 2) {
                hashmap[arr[pinnedstart]]--;
                if (hashmap[arr[pinnedstart]]==0) {
                    distinctcount--;
                }
                pinnedstart++;
            }
            maxcount = max(maxcount, i - pinnedstart + 1);
        }
        return maxcount;
    }
};
