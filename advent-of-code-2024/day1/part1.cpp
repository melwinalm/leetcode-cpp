#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 1000;
    
    priority_queue<int> left;
    priority_queue<int> right;
    
    int a, b;
    
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        
        left.push(a);
        right.push(b);
    }
    
    int output = 0;
    
    for(int i = 0; i < n; i++){
        int topLeft = left.top();
        int topRight = right.top();
        
        left.pop();
        right.pop();
        
        output += abs(topLeft - topRight);
    }
    
    cout << "Answer is: " <<output;

    return 0;
}
