/**
Easy - Final Prices With a Special Discount in a Shop
https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Idea : 
    
    Brute Force : for each element in the array find its next immediate index which is less than the current
    element using two nested for loops. Time Complexity - O(N*N), Space Complexity - O(1)
    
    Using Stack : Looking at any element, the element to its immediate left will 
    (i) greater than or equal to current element : In thase case the current element will be answer for the 
    immediate left element
    (ii) less than current element : In that case the answer to the immediate left element will be found in the
    montonicly decreasing sequence formed by considering left to right element using stack.
    Implementation : Contruct the stack by Iterating over the Array from right to left and push them into the  
    stack such that the stack will contain montonically decareasing element from top to bottom 
    with max at the top.
    Time Complexity - O(N) as in the worst case every element of the array is pushed and poped only one time
    into and out of the stack respectively.
    Space Complexity - O(N)
    
    **/
    
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        for(int i = prices.size() - 1; i >= 0; i--){
            while(!stk.empty() && prices[i] < stk.top()){
                stk.pop();
            }
            int temp = prices[i];
            if(!stk.empty()) prices[i] -= stk.top();
            stk.push(temp);
        }
        return prices;
    }
};