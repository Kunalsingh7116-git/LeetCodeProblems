class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() <= k) return "0";
        
        stack<char> st;
        
        // 1. Process left-to-right to maintain a monotonic increasing stack
        for (char c : num) {
            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        // 2. If k remains, remove digits from the top (right side of the number)
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // 3. Extract elements from stack (this reverses the order)
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // 4. Reverse it back to the correct order
        reverse(result.begin(), result.end());
        
        // 5. Strip leading zeros
        int startIdx = 0;
        while (startIdx < result.length() && result[startIdx] == '0') {
            startIdx++;
        }
        
        result = result.substr(startIdx);
        return result.empty() ? "0" : result;
    }
};
