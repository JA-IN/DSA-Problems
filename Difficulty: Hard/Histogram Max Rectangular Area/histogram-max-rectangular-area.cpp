class Solution {
  public:
    void next_smaller(vector<int>&arr , vector<int>&right_limit){
        stack<int>s;
        int n = arr.size();
        for(int i = 0 ; i< n ; i++){

            while(!s.empty() && arr[s.top()] > arr[i]){
                right_limit[s.top()] = i-1;
                s.pop();
            }
            s.push(i);
        }
    }
    void prev_smaller(vector<int>&arr , vector<int>&left_limit){
        stack<int>s;
        int n = arr.size();
        for(int i = n-1 ; i >=0 ; i--){

            while(!s.empty() && arr[s.top()] > arr[i]){
                left_limit[s.top()] = i + 1;
                s.pop();
            }
            s.push(i);
        }
    }
    int getMaxArea(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>right_limit(n,n-1);
        vector<int>left_limit(n,0);

        next_smaller(arr , right_limit);
        prev_smaller(arr, left_limit);
        int area = 0 ;

        for(int i = 0 ; i< n ; i++){
            int r = right_limit[i];
            int l = left_limit[i];
            int a = arr[i] * (r-l+1);
            area = max(area , a);
        }
        return area;
    }
};
