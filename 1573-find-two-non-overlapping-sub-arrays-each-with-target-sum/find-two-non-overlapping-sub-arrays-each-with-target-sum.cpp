class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = shortest target-sum subarray
        // completely inside arr[0...i]
        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Since all elements are positive,
            // remove elements from left if sum becomes too large.
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Current window [left ... right] has sum = target
            if (sum == target) {

                int len = right - left + 1;

                // Need another subarray before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Store the shortest subarray found so far
                best[right] = min(best[right], len);
            }

            // Carry forward previous best
            if (right > 0) {
                best[right] = min(best[right], best[right - 1]);
            }
        }

        return ans == INF ? -1 : ans;
    }
};