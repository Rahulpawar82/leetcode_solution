class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        if (n == 1)
            return nums;

        ans.push_back(nums[0]);

        for (int i = 1; i < n - 1; i++) {

            bool left = true;
            bool right = true;

            // Check if nums[i] is greater than EVERYTHING on left
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) {
                    left = false;
                    break;
                }
            }

            // Check if nums[i] is greater than EVERYTHING on right
            for (int j = i + 1; j < n; j++) {
                if (nums[i] <= nums[j]) {
                    right = false;
                    break;
                }
            }

            if (left || right) {
                ans.push_back(nums[i]);
            }
        }

        ans.push_back(nums[n - 1]);

        return ans;
    }
};