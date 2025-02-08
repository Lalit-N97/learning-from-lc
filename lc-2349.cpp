/**
Medium - Design a Number Container System
https://leetcode.com/problems/design-a-number-container-system
Written By : LalitN97
**/

/**
Idea : need to take a map<int, int> which store index with updated number
another map<int, set<int>> which stores for each number how many indices are associated with it 
(these are distinct). 
Change operation will update the second map by removing idx of the old number(existing in the map) and insert
new index into the new number.
Find operation will return the minimum index of a number from the second map if set is not empty.
Time Complexity - O(NLogN)
change : logN
find : O(1) time if the .begin() method get the first element in constant time
Space Complexity - O(N)
where N is the no of call in totals made to the change and find functions 
**/
class NumberContainers {
public:

    unordered_map<int, int> idxNum;
    unordered_map<int, set<int>> idxSet;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int oldNum = idxNum[index];
        if(oldNum != 0){
            idxSet[oldNum].erase(index);
        }
        idxNum[index] = number; 
        idxSet[number].insert(index);
    }
    
    int find(int number) {
        if(!idxSet[number].empty()){
            set<int> :: iterator it = idxSet[number].begin();
            return *it;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */