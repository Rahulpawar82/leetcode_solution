class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // XOR all the elements in the vector
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
};
