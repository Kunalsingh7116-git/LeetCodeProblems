class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        if (nums.size() <= 2) return nums;

        vector<int> result1;
        vector<int> result2;

        result1.push_back(nums[0]);
        result2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (result1.back() > result2.back()) {
                result1.push_back(nums[i]);
            } else {
                result2.push_back(nums[i]);
            }
        }

        result1.insert(result1.end(), result2.begin(), result2.end());

        return result1;
    }
};
