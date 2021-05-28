using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
public:
    static int findMaxSumSubArray(int k, const vector<int>& arr) {
        int maxSum = 0;
        int currentsum = 0;
        int pinnedposstart = 0;
        int arrlength = arr.size();
        int pinnedposend = 0;
        int windowstart = 0;
        int windowend = 0;
        while (windowend <= k -1) {
            currentsum = currentsum + arr[windowend];
            windowend = windowend + 1;
        }
        maxSum = currentsum;
        while (windowend < arrlength) {
            currentsum = currentsum + arr[windowend] - arr[windowstart];
            if (currentsum > maxSum) {
                maxSum = currentsum;
                pinnedposstart = windowstart + 1;
                pinnedposend = windowend;
            }
            windowstart++;
            windowend++;
        }
        return maxSum;
    }
};
