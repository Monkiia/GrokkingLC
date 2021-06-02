using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
public:
    static vector<int> makeSquares(const vector<int>& arr) {
        int n = arr.size();
        vector<int> squares(n);
        // TODO: Write your code here
        int leftpointer = 0;
        int rightpointer = arr.size() -1;
        int squarespos = n - 1;
        while (leftpointer <= rightpointer) {
            if (arr[leftpointer] * arr[leftpointer] <= arr[rightpointer] * arr[rightpointer]) {
                squares[squarespos] = arr[rightpointer] * arr[rightpointer];
                rightpointer--;
            }
            else {
                squares[squarespos] = arr[leftpointer] * arr[leftpointer];
                leftpointer++;
            }
            squarespos--;
        }
        return squares;
    }
};
