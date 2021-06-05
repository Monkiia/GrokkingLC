using namespace std;

#include <iostream>
#include <string>
#include <vector>

class BackspaceCompare {
public:
    static bool compare(const string &str1, const string &str2) {
        // TODO: Write your code here
        int realpointer1 = 0;
        vector<char> vector_str1(str1.size());
        for (int i = 0 ; i < str1.size() ; i++) {
            if (str1[i] != '#') {
                vector_str1[realpointer1] = str1[i];
                realpointer1++;
            }
            else {
                realpointer1--;
            }
        }
        vector<char> vector_str2(str2.size());
        int realpointer2 = 0;
        for (int j = 0 ; j < str2.size() ; j++) {
            if (str2[j] != '#') {
                vector_str2[realpointer2] = str2[j];
                realpointer2++;
            }
            else {
                realpointer2--;
            }
        }
        if (realpointer1 != realpointer2) {
            return false;
        }
        for (int k = 0; k < realpointer1; k++) {
            if (vector_str1[k] != vector_str2[k]) {
                return false;
            }
        }
        return true;
    }
};
