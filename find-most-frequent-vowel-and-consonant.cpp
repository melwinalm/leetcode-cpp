class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowelFreq;
        unordered_map<char, int> consonantFreq;

        for(char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelFreq[c]++;
            } else {
                consonantFreq[c]++;
            }
        }

        int output = 0;
        int maxSoFar = 0;

        for (auto item : vowelFreq) {
            maxSoFar = max(maxSoFar, item.second);
        }

        output += maxSoFar;
        maxSoFar = 0;

        for (auto item : consonantFreq) {
            maxSoFar = max(maxSoFar, item.second);
        }

        return output + maxSoFar;
    }
};
