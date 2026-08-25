class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int count = 0;

        while (start < end) {

            if (nums[start] != 0) {
                start++;
            }
            else if (nums[end] == 0) {
                end--;
            }
            else {
                swap(nums[start], nums[end]);
                count++;
                start++;
                end--;
            }
        }

        return count;
    }
};