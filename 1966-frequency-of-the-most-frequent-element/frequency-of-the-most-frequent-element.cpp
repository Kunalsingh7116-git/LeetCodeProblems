class Solution {
public: 
    int bSearch(int targetIdx,int k,vector<int>& nums,vector <long> &prefixSum){
        int l = 0;
        int r = targetIdx;
        int target = nums[targetIdx];
        int bestIdx = targetIdx; // basically result
        while(l<=r){
            int mid = l +(r-l)/2;

            long count = targetIdx-mid+1;
            long windowSum = count*target;

            long originalSum = prefixSum[targetIdx]-prefixSum[mid]+ nums[mid];

            int ops = windowSum - originalSum;

            if(ops > k){
                l = mid+1;
            }
            else{
                 bestIdx = mid;
                r = mid-1;
            }
        }
        return targetIdx - bestIdx + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector <long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size();i++){
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }

        int result = 0;
        for(int i = 0; i < nums.size();i++){
            result = max(result,bSearch(i,k,nums,prefixSum));
        }

        return result;
    }
};