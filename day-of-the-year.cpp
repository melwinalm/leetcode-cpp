// Link: https://leetcode.com/problems/day-of-the-year

class Solution {
private:
    int isLeapYear(int year){
        if(year % 400 == 0){
            return true;
        }
        else if(year % 100 == 0){
            return false;
        }
        else if(year % 4 == 0){
            return true;
        }
        else{
            return false;
        }
    }


public:
    int dayOfYear(string date) {
        int yy = stoi(date.substr(0, 4));
        int mm = stoi(date.substr(5, 2));
        int dd = stoi(date.substr(8, 2));

        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int output = 0;

        for(int i = 0; i < mm; i++){
            if(i == mm-1){// if it is the current month
                output += dd;
                break;
            }

            if(i == 1){
                output += isLeapYear(yy) ? 29 : 28;
            }
            else{
                output += days[i];
            }
        }

        return output;
    }
};
