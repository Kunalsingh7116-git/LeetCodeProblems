class Solution {
public:
    bool isDigit(char s){
        return s >= '0' &&  s <= '9';
    }
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long long result = 0;
        int sign = 1;
        //ignore leading space
        while(i < n && s[i] == ' ') i++;


        //Signedness
        if(i < n){
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(s[i] == '+') i++;
        }
        //Conversion
        while(i < n && isDigit(s[i])){
            int digit = s[i] - '0';
            result =  result*10 + digit;
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
               
            i++;
        }

        return sign*result;
        
    }
};