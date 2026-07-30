class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ss = s+s;
        string result = "";
        k = k % s.length();
        for(int i = 0;i < s.length();i++){
            result.push_back(s[(i+k) % s.length()]);
        }
        return result;
        
    }
};