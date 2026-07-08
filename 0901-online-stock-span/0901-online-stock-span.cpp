class StockSpanner {
public:
    vector<int> span;
    stack<int> s;

    StockSpanner() {}

    int next(int price) {
        span.push_back(price);
        int ans = 0;
        int n = span.size();
        int curr_idx = n - 1;
        while (!s.empty() && span[curr_idx] >= span[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            ans = n;
        } else {
            ans = curr_idx - s.top();
        }
        s.push(curr_idx);

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */