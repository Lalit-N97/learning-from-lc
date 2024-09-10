// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

/**
Logic : Simulation + gcd worst to best time complexity

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    // Time Complexity - O(N), Space Complexity - O(1)
    int gcd(int a, int b){
        int one = min(a, b);
        int other = a ^ b ^ one; // to find the other number quickly
        for(int i = one; i > 1; i--){
            if(one%i == 0){
                if(other%i == 0) return i;
            }
        }
        return 1;
    }
    
    // Time Complexity - O(sqrt(N)), Space Complexity - O(1)
    int gcdOptimized(int a, int b){
        int first = min(a, b);
        int second = a ^ b ^ first; // to find the other number quickly
        int ans = 1;
        for(int i = 1; i*i <= first; i++){
            if(first%i == 0){
                int firstsFactor = first/i;
                if(second%i == 0) ans = max(ans, i);
                if(second%firstsFactor == 0) ans = max(ans, firstsFactor);
            }
        }
        return ans;
    }
    
    // Time Complexity - O(logN), Space Complexity - O(logN)
    int gcdEuclid(int a, int b){
        if(b == 0) return a;
        return gcdEuclid(b, a%b);
    }
    
    //Time Complexity - O(logN), Space Complexity - O(1)
    int gcdEuclidIterative(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL) return NULL;
        
        // whenever there are adjacent pair of nodes while traversing one by one we can insert a new node with the gcd value
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(cur != NULL){
            int d = gcdEuclidIterative(prev->val, cur->val);
            ListNode* temp = new ListNode(d);
            temp->next = cur;
            prev->next = temp;
            prev = cur;
            cur = cur->next;
        }
        
        return head;
    }
};