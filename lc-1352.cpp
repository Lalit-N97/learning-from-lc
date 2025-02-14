/**
Medium - Product of the Last K Numbers
https://leetcode.com/problems/product-of-the-last-k-numbers
Written By : LalitN97
**/



/**
Idea : store the elements in an prefixed array with ith element corresponds to the products of elements
from 0 to ith elements. Also track the latest index of 0 integer. This idx will help us to find if the last k 
products has 0 in it or not, if it has 0 then result will be 0 otherwise result will be pp[n]/pp[n - k]
Time Complexity - O(N)
add() - O(1)
getProduct() - O(1)
Space Complexity - O(N)
where N is the size of the input stream
**/

class ProductOfNumbers {
public:

    long long prefixProduct[40001];
    int latestZeroIdx;
    int idx;
    long long prevProd;

    ProductOfNumbers() {
        memset(prefixProduct, 0, sizeof prefixProduct);
        idx = 0;
        prevProd = 1;
        prefixProduct[idx] = prevProd;
        latestZeroIdx = -1;
    }
    
    void add(int num) {
        prefixProduct[++idx] = num * prevProd;
        prevProd = prefixProduct[idx];
        if(num == 0) {
            latestZeroIdx = idx;
            prevProd = 1; // reset the prevProd
        }
    }
    
    int getProduct(int k) {
        int lastIdx = idx - k;
        if(lastIdx < latestZeroIdx) return 0;
        else if(lastIdx == latestZeroIdx) return prefixProduct[idx];
        else return prefixProduct[idx]/prefixProduct[lastIdx];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */