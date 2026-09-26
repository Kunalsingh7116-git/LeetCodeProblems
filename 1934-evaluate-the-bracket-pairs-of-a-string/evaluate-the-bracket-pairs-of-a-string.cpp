class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for (int i = 0; i < knowledge.size(); i++) {
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        int i = 0;
        string result = "";
        while(i < s.length()){
            if(s[i] != '(') result += s[i];
            else{
                i++;
                string temp = "";
                while(s[i] != ')'){
                    temp += s[i];
                    i++;
                }
                result += mpp.count(temp) ? mpp[temp] : "?";
            }
            i++;
        }
        return result;
    }
};