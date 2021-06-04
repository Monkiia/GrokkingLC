using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
public:
    static void sort(vector<int> &arr) {
        // TODO: Write your code here
        int low = 0;
        int high = arr.size() - 1;
        int i = 0;
        int j = arr.size() - 1;
        int count = 0;
        while (i <= high) {
            if (arr[i] == 0) {
                swap(arr,i,low);
                low++;
                i++;
            }
            else if (arr[i] == 1) {
                i++;
            }
            else {
                swap(arr,i,high);
                high--;
            }
        }

    }

    static void swap(vector<int> &arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};
