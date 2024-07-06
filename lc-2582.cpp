// https://leetcode.com/problems/pass-the-pillow/


// Logic : one whole round (starting from 1st person and back to the same 1st person) 
// corresponds to (n - 1) * 2 time. 
// Now if time <= n - 1 then we are in the first half of one full round.
// and if time >= n - 1 and time <= (n - 1) * 2, then we are in the second half of one full round.
// calculated val1 
// calculated val2
// if they are same which means first case and if different which means second case and answering accordingly.


int passThePillow(int n, int time) {
    int val1 = time % (n - 1);
    int val2 = time % ((n - 1) * 2);
    if(val1 == val2) return 1 + val1;
    else return n - val1;
}

// Time Complexity - O(1)
// Space Complexity - O(1)
