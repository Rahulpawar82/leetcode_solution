class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        
        x = float("inf")
        count =0
        for n in nums:
            if count == 0: a = n
            if n == a:
                count  = count + 1
            else:
                count = count -1
                x= n

        return  a if count > 0 else n
            