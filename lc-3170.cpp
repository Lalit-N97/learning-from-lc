/**
Medium - Lexicographically Minimum String After Removing Stars
https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars
Written By : LalitN97
**/

class comparison{
    public:
    bool operator()(pair<char, int> A, pair<char, int> B){
        if(A.first == B.first) return A.second < B.second;
        return A.first > B.first;
    }
};

class Solution {
public:

    /**
    Idea : for every *, to find the smallest letter which is closest in the left, we can use priority_queue of pair
    where smallest closest character will always be there at the top when iterating from left to right.
    Approach : iterate from left to right and keep all the non-star characters with their indices in a prioriy_queue of 
    pair<char, int>. Now whenever a star character is found remove the top pair from the priority_queue and mark that
    index to * in the original string.
    At the end traverse the string and create a new string with non-star characters in it.
    Time Complexity - O(N * log(N))
    Space Compelexity - O(N)
    where N is the size of input string
    **/

    string getRequiredStr(string s){
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '*') ans += s[i];
        }
        return ans;
    }

    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<char, int>, vector<pair<char, int>>, comparison> pq;
        for (int i = 0; i < n; i++) {
            if(s[i] == '*'){
                pair<char, int> top = pq.top(); pq.pop();
                s[top.second] = '*';
            }
            else{
                pq.push(make_pair(s[i], i));
            }
        }
        return getRequiredStr(s);
    }
};