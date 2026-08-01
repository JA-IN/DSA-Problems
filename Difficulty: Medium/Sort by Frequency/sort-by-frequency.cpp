class Solution {
  public:
    string frequencySort(string &s) {
        // code here
          vector<vector<char>>bucket(s.size()+1);

        unordered_map<char,int>mp;
        for(int i = 0 ; i< s.size() ; i++){
            mp[s[i]]++;
        }
        
      priority_queue<pair<int , char> , vector<pair<int , char>> , greater<pair<int , char>>>pq;
      
      for(auto x : mp ){
          pq.push({x.second , x.first});
      }
      
      string ans = "";
      while(!pq.empty()){
          pair<int,char>element = pq.top();
          pq.pop();
          char c = element.second;
          int val = element.first;
          while(val--){
              ans +=c;
          }
      }

        return ans;
    }
};