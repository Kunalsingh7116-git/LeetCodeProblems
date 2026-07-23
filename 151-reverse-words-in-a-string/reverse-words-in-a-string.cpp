class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stringstream ss(s);
        string token = "";
        string result = "";
        while(ss >> token){
            result = token + " " + result;
        }

        return result.empty() ? "" : result.substr(0, result.length() - 1);

    }
};