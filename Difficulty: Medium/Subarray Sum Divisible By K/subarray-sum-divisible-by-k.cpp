class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& arr, int k) {
        // Your code goes here
        
        long long ans = 0 , curr_sum = 0 ;
        unordered_map<int,long long>mp;
        mp[0]=1;
        for(int i = 0 ; i< arr.size() ; i++){
            curr_sum +=arr[i];
            int remainder = ((curr_sum % k)+k) % k; // important condition for negative remainder case
            
            if(mp.find(remainder) != mp.end()){
                ans +=mp[remainder];
            }
            mp[remainder]++;
            
        }
        
        return ans;
    }
};
