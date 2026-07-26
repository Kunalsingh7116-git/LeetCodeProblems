class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> mpp{{"M",1000},{"CM",900},{"D",500},{"CD",400},
                                      {"C",100},{"XC",90},{"L",50},{"XL",40},
                                      {"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
        int result = 0;
        int i = 0;
        while(i < s.length()){
            if(i < s.length() && mpp.find(s.substr(i,2)) != mpp.end()) {
                result += mpp[s.substr(i,2)];
                i += 2;
            }
            else {
                result += mpp[string(1,s[i])];
                i++;
            }
        }
        return result;
        
    }
};