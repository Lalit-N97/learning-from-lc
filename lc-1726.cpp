/**
Medium - Tuple with Same Product
https://leetcode.com/problems/tuple-with-same-product
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : we can brute force the solution with 4 nested loops considering each different element in each loop
    and count the no of equation satisifies the expression.
    We can take another approach to remove one of the innermost nested loop to find d element. instead we can
    take 3 elements (a, b, c) using 3 nested loop and check if the result of ((a * b)/c) is present in the array.
    Here the time complexity is O(N^3) and space complexity is O(N) to find d in O(1)

    You can think of this problem as to find all elements which satisfies (A = B) in the array of distinct pair 
    of products of input array. 
    So count all the elements with same values in product of distinct pairs array. store the count in the frequency
    array and for every resultant product which has more than 1 frequency. Take sum of count all those pairs.
    Time Complexity - O(N^2)
    Space Complexity - O(N^2)
    where N is the size of input array

    **/

    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // store all count of distinct pair of products in a frequency map
                freq[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for(unordered_map<int, int> :: iterator it = freq.begin(); it != freq.end(); it++){
            // cout << it->first << "->" << it->second << "\n";
            int x = it->second;
            count += ((x * (x - 1))/2) * 2 * 2 * 2; // mulitplication with 2s for further permutations
        }
        return count;

    }
};