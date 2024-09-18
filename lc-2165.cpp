// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

/**
Logic : store the elements (digits) in a vector or a string or any other container
sort the digits in ascending order if original number is positive or else sort it in descending order
once sorted, for negative number just return form the number from the container elemment's order and return it with -1 sign
for postive number find the first number which is not zero from beginning and store the arranged digits in the answer such 
that the first non-zero digit from beginning will appear in the start and all the zeros before that non-zero numbers should
appear immediately after the first non-zero then comes the rest of the ascending order arranged numbers.
Time Complexity - O(N), Space Complexity - O(16) -> no of digits(15) + sign(1)
**/

class Solution {
public:
    long long smallestNumber(long long num) {
        long long positiveNum = abs(num);
        vector<int> v;
        while(positiveNum){
            int d = positiveNum % 10;
            positiveNum /= 10;
            v.push_back(d);
        }
        long long ans = 0;
        if(num >= 0){
            bool firstTimeFlag = false;
            sort(v.begin(), v.end());
            for(int i = 0; i < v.size(); i++){
                if(v[i] != 0 && firstTimeFlag == false){
                    ans = v[i];
                    ans = ans * pow(10, i);
                    firstTimeFlag = true;
                }
                else if(v[i] != 0){
                    ans = ans * 10 + v[i];
                }
            }
        }
        else{
            sort(v.begin(), v.end(), greater<int>());
            for(int i = 0; i < v.size(); i++){
                ans = ans*10 + v[i];
            }
            ans = ans * -1;
        }
        return ans;
    }
};