#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool isIncreasing(vector<int> &arr){
    for(int i = 1; i < arr.size(); i++){
       if(1 <= arr[i] - arr[i-1] && arr[i] - arr[i-1] <= 3){
            continue;
        }
        else{
            return false;
        }
    }
    
    return true;
}

int main()
{
    int n = 1000;
    int output = 0;
    
    for(int i = 0; i < n; i++){
        vector<int> arr;
        
        while(true){
            int num;
            scanf("%d", &num);
            arr.push_back(num);
            char c;
            scanf("%c", &c);
            if(c == '\n'){
                break;
            }
            
        }
        
        if(isIncreasing(arr)){
            output++;
            continue;
        }
        
        reverse(arr.begin(), arr.end());
        if(isIncreasing(arr)){
            output++;
            continue;
        }
    }
    
    cout << "Answer is " << output;

    return 0;
}
