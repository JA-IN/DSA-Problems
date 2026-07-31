class Solution {
  public:
    void help( vector<string>&ans , string curr , int open , int close , int n ){
        if(curr.size() == n){
            ans.push_back(curr);
            return ;
        }

        if(open < n/2){
            help(ans , curr + '(' , open+1 ,close , n);
        }
        if(close < open){
            help(ans , curr + ')' , open , close + 1 , n);
        }
    }
    vector<string> generateParentheses(int n) {
        // code here
        vector<string>ans;
        string curr;
        help(ans , curr , 0 , 0 , n);

        return ans;
    }
};