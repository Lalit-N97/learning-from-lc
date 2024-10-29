// https://leetcode.com/problems/decode-xored-array/

class Solution {
public:
    
    /**
    
    Logic : e[i] = a[i] ^ a[i + 1]
    taking xor with a[i] both side
    e[i] ^ a[i] = a[i + 1]
    this represent that every next element (i + 1) in the original array can be expressed
    in terms of xor of current e[i] and current a[i](first element of original array in case of first element)
    
    Iterate over the encoded array taking xor with the first element and update this first element (array element) to the result of current xor, Do this until you reach the end of the encoded array.
    
    Time Complexity - O(N), Space Complexity - O(1)
    
    **/
    
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> original(n + 1);
        original[0] = first;
        for(int i = 0; i < n; i++){
            original[i + 1] = original[i] ^ encoded[i];
        }
        return original;
    }
};