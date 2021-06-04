using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class QuadrupleSumToTarget {
public:
    static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
        vector<vector<int>> quadruplets;
        sort(arr.begin(), arr.end());
        // TODO: Write your code here
        for (int i = 0; i < arr.size() ; i++) {
            int arrminusi = target - arr[i];
            vector<vector<int>> threesum = searchTriplets(arr,arrminusi,i+1);
            if (threesum.size() > 0) {
                printf("AM I seeing anything here \n");
                int threesumsize = threesum.size();
                for (int j = 0 ; j < threesumsize ; j++) {
                    vector<int> v = {arr[i],threesum[j][0],threesum[j][1],threesum[j][2]};
                    quadruplets.push_back(v);
                }
            }
        }
        return quadruplets;
    }

    static vector<vector<int>> searchTriplets(vector<int> &arr, int target, int pos) {
        vector<vector<int>> triplelets;
        for (int i = pos; i< arr.size() ; i++) {
            int arrminusi = target - arr[i];
            vector<vector<int>> twosum = serachtwosum(arr,arrminusi,i+1);
            if (twosum.size() > 0) {
                printf("AM I seeing anything here search triplets \n");
                int twosumsize = twosum.size();
                for (int j = 0 ; j < twosumsize ; j++) {
                    vector<int> v =  {arr[i],twosum[j][0],twosum[j][1]};
                    //printf("arr[i] %d twosun[0] %d twosum[1] %d",arr[i],twosum[j][0]);
                    triplelets.push_back(v);
                }
            }
        }
        return triplelets;
    }

    static vector<vector<int>> serachtwosum(vector<int> &arr, int target, int pos) {
        vector<vector<int>> twosums;
        int pinnedstart = pos;
        int pinnedend = arr.size() - 1;
        printf("AM I seeing anything here search twosum \n");
        while (pinnedstart < pinnedend) {
            if (arr[pinnedstart] + arr[pinnedend] == target) {
                vector<int> v = {arr[pinnedstart],arr[pinnedend]};
                twosums.push_back(v);
                pinnedend--;
                pinnedstart++;
            }
            else if (arr[pinnedstart] + arr[pinnedend] < target) {
                pinnedstart++;
            }
            else {
                pinnedend--;
            }
        }
        return twosums;
    }
};
