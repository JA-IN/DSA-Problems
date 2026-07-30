class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int max_profit= 0 ;
        int Min = prices[0];
        for(int i = 0 ; i< prices.size();i++){
                Min = min(Min , prices[i]);
                int profit =  prices[i] - Min;

            max_profit = max(max_profit , profit);
        }
        return max_profit;
    }
};
