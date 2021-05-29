using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
public:
    static int findLength(const vector<int>& arr, int k) {
        int  maxLength = 0;
        // TODO: Write your code here
        vector<int> zeroonecountvector;
        zeroonecountvector.push_back(0);
        zeroonecountvector.push_back(0);
        int maxonecount = 0;
        int pinnedstart = 0;
        int maxresult = 0;
        for (int i = 0; i < arr.size() ; i++) {
            zeroonecountvector[arr[i]]++;
            while (i - pinnedstart + 1 - zeroonecountvector[1] > k) {
                zeroonecountvector[arr[pinnedstart]]--;
                pinnedstart++;
            }
            maxresult = max(maxresult,i - pinnedstart + 1);
        }
        return maxresult;
    }
};