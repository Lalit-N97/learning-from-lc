/**
Medium - MFind the Prefix Common Array of Two Arrays
https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/
Written By : LalitN97
**/

class Solution {
public:

    /**
    Brute Force : 
    Iterate over the second array and check from 0 to current index of the first array if there is current element 
    of second array present in first array using nested loop. Time Complexity - O(N^2)
    Other Way : 
    Will use of space, take a frequency array of elements from 0 to n. Intialise the array element with 0 freq.
    Iterate over both the array in parallel and track the frequency of elements upto current index. If for the 
    current index, the frequency of element in A or B become 2 then that element become common in both the arrays
    (because array elements are unique in both arrays and freq is 2 means the element's occurrence is twice) which
    means it is present in both the arrays.
    Time Complexity - O(N)
    Space Complexity - O(N)
    **/

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // int n = A.size();
        // vector<int> C(n, 0);
        // vector<int> freq(n + 1, 0);
        // for(int i = 0; i < n; i++){
        //     freq[A[i]]++;
        //     freq[B[i]]++;
        //     C[i] += (i == 0 ? 0 : C[i - 1]);
        //     if(A[i] == B[i]) C[i]++;
        //     else {
        //         if(freq[A[i]] == 2) C[i]++;
        //         if(freq[B[i]] == 2) C[i]++;
        //     }
        // }
        // return C;

        /**
        Since n <= 50 we can use bitmask to store the odd and even occurences of the integers
        i.e. if some bit is set in the bitmask then it means that bit(integers) appear 1 time upto now,
        and if the same bit appear two time then that bit will be 0.
        **/
        int n = A.size();
        vector<int> C(n, 0);
        long long bitMask = 0;
        long long one = 1;
        for(int i = 0; i < n; i++){
            bitMask ^= (one << A[i]);
            bitMask ^= (one << B[i]);
            C[i] += (i == 0 ? 0 : C[i - 1]); // accumulate all the previous common integers in both arrays
            if((bitMask & (one << A[i])) == 0) C[i]++;
            if(A[i] != B[i] && ((bitMask & (one << B[i])) == 0)) C[i]++;
        }
        return C;
    }
};