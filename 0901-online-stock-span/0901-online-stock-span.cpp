class StockSpanner {
public:
        
    vector<int>span;
    int maxspan(vector<int>&span , int price){
        stack<int>s;
        int ans = 0 ;
        int n = span.size();
        if(n==1){
            return 1;
        }
        int curr = n-1;

       while(curr >=0 && price >= span[curr]){
        curr--;
        ans++;
       }
        return ans;
    }
    StockSpanner() {

    }
    
    int next(int price) {
        span.push_back(price);
        int ans = maxspan(span , price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */