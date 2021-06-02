using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
public:
    static vector<vector<int>> searchTriplets(vector<int> &arr) {
        vector<vector<int>> triplets;
        // TODO: Write your code here
        // To sort arr
        printf("Start the array \n");
        sort(arr.begin(),arr.end());
        for (int i = 0 ; i < arr.size() ; i++) {
            int twosumresult = 0 - arr[i];
            vector<vector<int>> special_triplets = serachtwosum(arr, i + 1, arr.size() -1, twosumresult,i);
            for (vector<int> i : special_triplets) {
                triplets.push_back(i);
            }
        }
        return triplets;
    }

    static vector<vector<int>> serachtwosum(vector<int> &arr, int leftpos, int rightpos, int sumvalue, int pivot) {
        vector<vector<int>> triplets;
        if (leftpos >= rightpos) {
            return triplets;
        }
        else {
            while (leftpos < rightpos) {
                if (arr[leftpos] + arr[rightpos] < sumvalue) {
                    leftpos++;
                }
                else if (arr[leftpos] + arr[rightpos] > sumvalue) {
                    rightpos--;
                }
                else {
                    vector<int> toreturn;
                    toreturn.push_back(arr[pivot]);
                    toreturn.push_back(arr[leftpos]);
                    toreturn.push_back(arr[rightpos]);
                    triplets.push_back(toreturn);
                    leftpos++;
                    rightpos--;
                }
            }
            return triplets;
        }
    }

};
