// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
public:
    /**
      Logic : use an array to store stack elements and use another array to store upto which index increment happens
          Push() will be simple O(1)
          Increment() will be inc[i] += val - O(1)
          Pop() will also be O(1) but since we have to return the element while popping it from the stack.
          pop() happens one element at a time and inc[] arr will store the incremented value at a particular index.
          wheneve we'll pop the element we have to return its value + inc[i]. Also have to make the inc[i-1] += inc[i];
          to reflect the incremented values from top to bottom.
    **/    
    int *arr;
    int *inc;
    int curSize;
    int capacity;
    
    CustomStack(int maxSize) {
        curSize = 0;
        capacity = maxSize;
        arr = new int[capacity];
        inc = new int[capacity]{0};
    }
    
    void push(int x) {
        if(curSize != capacity){
            arr[curSize] = x;
            curSize++;
        }
    }
    
    int pop() {
        if(curSize == 0) return -1;
        --curSize;
        if(curSize > 0) inc[curSize - 1] += inc[curSize];
        int res = arr[curSize] + inc[curSize];
        inc[curSize] = 0; // reset the stack element's increment array value to 0
        return res;
    }
    
    void increment(int k, int val) {
        int i = min(k, curSize);
        if(i > 0) inc[i - 1] += val;
    }
    
    /**
    
    Logic : Brute force approach using array to increment all values from 0 to k whenever increment funciton is called
    TIme Complexity - O(N*N) Space Complexity - O(N)
    
    **/
    
//     int *arr;
//     int curSize;
//     int capacity;
    
//     CustomStack(int maxSize) {
//         arr = new int[maxSize];
//         curSize = 0;
//         capacity = maxSize;
//     }
    
//     void push(int x) {
//         if(curSize != capacity){
//             arr[curSize] = x;
//             curSize++;
//         }
//     }
    
//     int pop() {
//         if(curSize == 0) return -1;
//         return arr[--curSize];
//     }
    
//     void increment(int k, int val) {
//         for(int i = 0; i < min(k, curSize); i++){
//             arr[i] += val;
//         }
//     }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */