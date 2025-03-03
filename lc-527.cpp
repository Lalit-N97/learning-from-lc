/**
Medium - Complex Number Multiplication
https://leetcode.com/problems/complex-number-multiplication
Written By : LalitN97
**/

class Solution {
public:

    /**
    Idea : simulate the process.
    Time Complexity - O(N)
    Space Complexity - O(N)
    where N is the size of the input string
    **/

    string toString(int n){
        if(n == 0) return "0";
        string s = "";
        bool minus = false;
        if(n < 0) minus = true;
        n = abs(n);
        while(n){
            char ch = '0' + n%10;
            s = ch + s;
            n /= 10;
        }
        return minus ? '-' + s : s;
    }

    int getRealPart(string num){
        int real = 0;
        bool minus = false;
        int i = 0;
        if(num[i] == '-') {
            minus = true;
            i++;
        }
        while(num[i] != '+'){
            real = real * 10 + (num[i] - '0');
            i++;
        }
        return minus ? real * -1 : real;
    }

    int getImagPart(string num){
        int imag = 0;
        int i = 0;
        while(num[i] != '+') i++;
        i++;
        bool minus = false;
        if(num[i] == '-') {
            minus = true;
            i++;
        }
        while(num[i] != 'i'){
            imag = imag * 10 + (num[i] - '0');
            i++;
        }
        return minus ? -1 * imag : imag;
    }

    string getComplexNum(int real, int imag){
        return toString(real) + "+" + toString(imag) + "i";
    }

    string complexNumberMultiply(string num1, string num2) {
        int a = getRealPart(num1);
        int b = getImagPart(num1);
        int x = getRealPart(num2);
        int y = getImagPart(num2);
        int real = (a * x) - (b * y);
        int imag = (a * y) + (b * x);
        // printf("first-> %d + %d i \nsecond-> %d + %d i \nresult-> %d + %d i", a, b, x, y, real, imag);
        return getComplexNum(real, imag);
    }
};