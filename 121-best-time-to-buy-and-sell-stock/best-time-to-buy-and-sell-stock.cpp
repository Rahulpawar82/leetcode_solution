class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;  //smallest price seen so far
        int maxprofit = 0;       //best profit so far 


        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<minprice){
                minprice = prices[i];                 //found a new lower buy point 
            }
            else if (prices[i]-minprice>maxprofit){
                maxprofit = prices[i] - minprice; //selling today beats our best profit 
            }
        }

        return maxprofit;


    }
};