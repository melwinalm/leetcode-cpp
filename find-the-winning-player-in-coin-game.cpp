/*
Title: Find the Winning Player in a Coin Game
Link: https://leetcode.com/problems/find-the-winning-player-in-coin-game
*/

// Recursive Solution
class Solution {
public:
    string losingPlayer(int x, int y) {
        bool isAliceTurn = true;

        while(x >= 1 && y >= 4){
            x -= 1;
            y -= 4;
            isAliceTurn = !isAliceTurn;
        }

        return isAliceTurn ? "Bob" : "Alice";
    }
};
