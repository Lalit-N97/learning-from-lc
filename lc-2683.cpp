// https://leetcode.com/problems/neighboring-bitwise-xor/

class Solution {
public:
    
    /**
    Logic : 
    d[i] = o[i] ^ o[i + 1]
    taking xor both sides with o[i], 
    => d[i] ^ o[i] = o[i + 1]
    So next element of orignal array will be the xor of cur derived element and current original element
    Also, o[1] = o[0] ^ d[0]
    o[2] = o[1] ^ d[1] => o[2] = o[0] ^ d[0] ^ d[1]
    o[3] = o[2] ^ d[2] => o[3] = o[0] ^ d[0] ^ d[1] ^ d[2]
    o[4] = o[3] ^ d[3] => o[4] = o[0] ^ d[0] ^ d[1] ^ d[2] ^ d[3]
    similarly, o[n - 1] = o[0] ^ xor of all elements upto d[n - 2] - (1)
    Now, in case i = n - 1, o[0] = o[n - 1] ^ d[n - 1];   - (2)
    putting value of o[n - 1] from equation (1) into the equation (2), we get
    => o[0] = o[0] ^ d[0] ^ d[1] ^ d[2] ^ d[3] ^ ... ^ d[n - 1] - (3)
    Since the orginal array is a binary array, we can pick first element as 1 or 0 only.
    We need to check if picking the first element(o or 1) satisfies the equation (3)
    if statifies return true, othewise return false
    
    Time Complexity - O(N), Space Complexity - O(1)
    
    OR  you can say that XOR sum of all the elements in the derived array should be 0.
    As you can see from this examples that xor sum of derived elements contains duplicates of orinal elements
        derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
        derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
        derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
    
    **/
    
    bool doesValidArrayExist(vector<int>& derived) {
        int allXor = 0;
        for(int i = 0; i < derived.size(); i++) allXor ^= derived[i];
        int firstEle = 1; // pick first element as 1
        if(firstEle == (firstEle ^ allXor)) return true;
        firstEle = 0; // if equation not statisfies pick first element as 0
        return firstEle == (firstEle ^ allXor);
    }
};
