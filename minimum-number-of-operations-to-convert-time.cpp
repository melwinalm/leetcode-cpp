/*
Title: Minimum Number of Operations to Convert Time
Link: https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/description/
*/

class Solution {
public:

    vector<string> split(string str, char delim){
        vector<string> output;

        int len = str.size();
        int start = 0;
        int end = str.find(delim);
        while(end != -1){
            output.push_back(str.substr(start, end - start));

            start = end + 1;
            end = str.find(delim, start);
        }

        output.push_back(str.substr(start));

        return output;
    }

    int convertTime(string current, string correct) {
        vector<string> curr = split(current, ':');
        vector<string> corr = split(correct, ':');

        int currMins = (60 * stoi(curr[0])) + stoi(curr[1]);
        int corrMins = (60 * stoi(corr[0])) + stoi(corr[1]); 

        int minMins = abs(currMins - corrMins);

        int output = 0;

        output += minMins / 60;
        minMins = minMins % 60;

        output += minMins / 15;
        minMins = minMins % 15;

        output += minMins / 5;
        minMins = minMins % 5;

        output += minMins;

        return output;
    }
};
