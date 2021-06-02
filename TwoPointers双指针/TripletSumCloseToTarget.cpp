using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
// My Max_int use is not good should use limits.h library
class TripletSumCloseToTarget {
public:
    static int searchTriplet(vector<int>& arr, int targetSum) {
        // TODO: Write your code here
        printf("New \n");
        sort(arr.begin(),arr.end());
        int endpos = arr.size() -1;
        int smallestdifference = abs(targetSum - (arr[0] + arr[1] + arr[2]));
        int finalresult = 2147483647;
        for (int i  = 0 ; i < arr.size() - 2; i++) {
            int targetsum_minus_arr_i = targetSum - arr[i];
            int result_arr_i = twosumfindclosest(arr, targetsum_minus_arr_i,i+1,endpos);
            int result = arr[i] + result_arr_i;
            //smallestdifference = min(smallestdifference,abs(targetSum - result));
            if (smallestdifference > abs(targetSum - result)) {
                smallestdifference = abs(targetSum - result);
                finalresult = result;
                printf("final result %d %d \n",arr[i], result_arr_i);
            }
            else if (smallestdifference == abs(targetSum - result)) {
                finalresult = min(finalresult,result);
            }
        }
        return finalresult;
    }

    static int twosumfindclosest(vector<int>& arr, int targetSum,int startpos, int endpos) {
        int smallestdiff = abs(targetSum - (arr[startpos] + arr[endpos]));
        int returnresult = arr[startpos] + arr[endpos];
        while (startpos < endpos) {
            if (abs(targetSum - (arr[startpos] + arr[endpos])) < smallestdiff) {
                smallestdiff = abs(targetSum - (arr[startpos] + arr[endpos]));
                returnresult = arr[startpos] + arr[endpos];
                //printf("arr[strtpos] %d, arr[endpos] %d \n" , arr[startpos],arr[endpos]);
            }
            if (arr[startpos] + arr[endpos] < targetSum) {
                startpos++;
            }
            if (arr[startpos] + arr[endpos] > targetSum) {
                endpos--;
            }
        }
        return returnresult;
    }
};
