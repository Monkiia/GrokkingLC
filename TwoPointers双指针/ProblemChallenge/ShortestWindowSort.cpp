using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ShortestWindowSort {
public:
    static int sort(const vector<int>& arr) {
        // TODO: Write your code here
        int left = 0;
        int right = arr.size() - 1;
        int i = 0;
        bool leftcannotfurther = false;
        bool rightcannotfurther = false;
        while (i < arr.size() - 1) {
            i++;
            if (arr[i] >= arr[left] && leftcannotfurther == false) {
                left++;
            }
            else if (arr[i] < arr[left] && leftcannotfurther == false) {
                left--;
                leftcannotfurther = true;
            }
            else if (leftcannotfurther == true) {
                while (arr[left] > arr[i] && left >= 0) {
                    printf("left got minus from arr[left] %d  arr[i] %d\n",arr[left],arr[i]);
                    left--;
                }
            }
            if (arr[arr.size() -1 - i] <= arr[right] && rightcannotfurther == false) {
                right--;
            }
            else if (arr[arr.size() -1 - i] > arr[right] && rightcannotfurther == false) {
                right++;
                rightcannotfurther = true;
            }
            else if (rightcannotfurther == true) {
                while (arr[arr.size() -1 - i] > arr[right] && right < arr.size() - 1) {
                    right++;
                }
            }
        }
        if (leftcannotfurther && rightcannotfurther) {
            printf("right %d \n",right);
            printf("left %d \n",left);
            return right -1 - (left + 1) + 1;
        }
        return 0;
    }
};
