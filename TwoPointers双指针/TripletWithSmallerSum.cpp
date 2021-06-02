using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletWithSmallerSum {
public:
    static int searchTriplets(vector<int> &arr, int target) {
        int count = -1;
        // TODO: Write your code here
        sort(arr.begin(),arr.end());
        int arrsize = arr.size();
        int sumover = 0;
        for (int i = 0; i < arrsize - 2 ; i++) {
            int targetminusi = target - arr[i];
            printf("arr_i %d \n",arr[i]);
            int counti = searchtwosum(arr,i+1,arrsize-1,targetminusi);
            sumover += counti;
        }
        return sumover;
    }

    static int searchtwosum(vector<int> &arr, int startpos, int endpos, int target) {
        int count = 0;
        while (startpos < endpos) {
            if (arr[startpos] + arr[endpos] >= target) {
                endpos--;
            }
            else if (arr[startpos] + arr[endpos] < target) {
                count = count + endpos - startpos;
                startpos++;
                printf("%d %d \n",arr[startpos],arr[endpos]);
            }
        }
        return count;
    }
};
