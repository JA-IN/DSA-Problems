class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int>s;
        int area = 0 ;
        for(int i = 0 ; i< n ; i++){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                int curr_h = s.top();
                s.pop();
                
                if(s.empty()){
                    continue;
                }
                else{     // right height - left height
                    int h = min(arr[i] , arr[s.top()]);
                    int exact_h = h - arr[curr_h];
                    int w = i - s.top() -1;
                    
                    area += exact_h * w;
                }
            }
            s.push(i);
        }
        return area ;
    }
};