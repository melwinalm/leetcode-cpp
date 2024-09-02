/*
Title: Find Median from Data Stream
Link: https://leetcode.com/problems/find-median-from-data-stream
*/

// Using Two Priority Queues
class MedianFinder {
private:
    priority_queue<int> leftPQ; // Max Heap
    priority_queue<int, vector<int>, greater<int>> rightPQ; // Min Heap
public:
    MedianFinder() {}
    
    void addNum(int num) {
        // When a new number needs to be pushed, push it to left heap and then pop the top number from left and push it to right
        // If right heap is greater then pop top number from right and put it to left
        // Basically left heap will always be equal to right heap or left heap will be one greater than the right heap
        leftPQ.push(num);
        rightPQ.push(leftPQ.top());
        leftPQ.pop();

        if(rightPQ.size() > leftPQ.size()){
            leftPQ.push(rightPQ.top());
            rightPQ.pop();
        }
    }
    
    double findMedian() {
        if(leftPQ.size() > rightPQ.size()){
            return leftPQ.top();
        }
        else{
            return ((leftPQ.top() + rightPQ.top())/ 2.0);
        }
    }
};
