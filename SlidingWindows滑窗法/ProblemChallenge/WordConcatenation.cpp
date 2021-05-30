using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordConcatenation {
public:
    static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
        vector<int> resultIndices;
        // TODO: Write your code here
        unordered_map<string,int> freqmap;
        int wordsize = words[0].size();
        int matches = 0;
        int vectorsize = words.size();
        int pinnedstart = 0;
        for (string word :words) {
            if (freqmap.count(word) == 0) {
                freqmap[word] = 1;
            }
            else {
                freqmap[word]++;
            }
        }
        int distinctwords = freqmap.size();
        for (int i = 0 ;  i < str.size() ; i = i + wordsize) {
            if (i - pinnedstart + 1 > vectorsize * wordsize) {
                if (freqmap.count(str.substr(pinnedstart,wordsize)) != 0) {
                    freqmap[str.substr(pinnedstart,wordsize)]++;
                    if (freqmap[str.substr(pinnedstart,wordsize)] == 1) {
                        matches--;
                    }
                    pinnedstart = pinnedstart + wordsize;
                }
            }
            if (freqmap.count(str.substr(i,wordsize)) != 0) {
                freqmap[str.substr(i,wordsize)]--;
                if (freqmap[str.substr(i,wordsize)] == 0) {
                    matches++;
                    if (matches == distinctwords) {
                        resultIndices.push_back(pinnedstart);
                    }
                }
            }
        }
        return resultIndices;
    }
};
