using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
public:
    static pair<int, int> search(const vector<int>& arr, int targetSum) {
        // TODO: Write your code here
        int leftpointer = 0;
        int rightpointer = arr.size() - 1;
        while (leftpointer < rightpointer) {
            if (arr[leftpointer] + arr[rightpointer] > targetSum) {
                rightpointer--;
            }
            else if (arr[leftpointer] + arr[rightpointer] < targetSum) {
                leftpointer++;
            }
            else {
                return make_pair(leftpointer,rightpointer);
            }
        }
        return make_pair(-1, -1);
    }
};
