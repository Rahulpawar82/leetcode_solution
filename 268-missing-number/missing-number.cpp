class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i;
        int n =nums.size();

        //sum of all element in the array
        int sum =0;
        for(i=0; i<nums.size();i++)
        {
            sum = sum+nums[i];
        }

        //sum of n numbers

        int sumn;
        sumn=n*(n+1)/2;

        int remn = sumn-sum;
        return remn;
    }
};