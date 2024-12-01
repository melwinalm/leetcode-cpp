#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 1000;
    
    vector<int> left;
    map<int, int> rightMap;
    
    int a, b;
    
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        
        left.push_back(a);
        rightMap[b]++;
    }
    
    int output = 0;
    
    for(int i = 0; i < n; i++){
        int num = left[i];
        
        if(rightMap.find(num) != rightMap.end()){
            output += (num * rightMap[num]);
        }
    }
    
    cout << "Answer is: " << output;

    return 0;
}
