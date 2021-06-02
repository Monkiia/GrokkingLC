using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class SubarrayProductLessThanK {
public:
    static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
        vector<vector<int>> result;
        int count = 0;
        // TODO: Write your code here
        int arrsize = arr.size();
        for (int i = 0; i < arrsize; i++) {
            int product = 1;
            if (arr[i] < target) {
                count++;
                product = product * arr[i];
                vector<int> arri;
                arri.push_back(arr[i]);
                result.push_back(arri);
            }
            for (int j = i + 1; j < arrsize ; j++) {
                product = product * arr[j];
                if (product < target) {
                    vector<int> avector;
                    avector.push_back(arr[i]);
                    for (int k = i + 1; k <= j ; k++){
                        avector.push_back(arr[k]);
                    }
                    count++;
                    result.push_back(avector);
                }
            }
        }
        return result;
    }
};
