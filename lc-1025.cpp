// https://leetcode.com/problems/divisor-game/

class Solution {
public:
    
    /**
    Logic : Alice will start the game.
    For an input even number Alice will always win the game and for odd input number Alice will loose.
    Evey odd numbers are composed of only odd factors. Hence Bob will always win incase of odd input number. Because Whoever plays at even number will win the game. And if input is odd number and Alice is starting the game then Alice will substract another odd number from the input odd number (because the factors of odd number are odd) so Alice will deduce an even number after subtraction and Since Bob will play this time with the even number hence Bob will win the game.
    Time Complexity - O(1) and Space Complexity - O(1)
    **/
    
    bool divisorGame(int n) {
        return !(n & 1);
    }
};