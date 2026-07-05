class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n1 = s.size() , n2 = p.size();
        unordered_map<char,int>window;
        unordered_map<char,int>need;
        int left = 0 , right = 0 ;
        int required = n2 , ans = INT_MAX , start , end;
        for(int i = 0; i< n2 ; i++){
            window[p[i]] = 0 ;
            need[p[i]]++;
        }
        
        while(right< n1){
            if(need.find(s[right]) != need.end()){
                
                // adding element and update required variable
                window[s[right]]++;
                if(window[s[right]] <= need[s[right]]){
                    required--;
                }
                
                while(required == 0){
                    
                    if(ans > right - left +1){
                        ans = right - left +1;
                        start = left ;
                        end = right;
                    } 
                // removing element and update required variable
                    if(need.find(s[left]) != need.end() ){
                        window[s[left]]--;
                        
                        if(window[s[left]] < need[s[left]] ){
                            required++;
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        
        
        if(ans == INT_MAX){
           return ""; 
        }
        string result = "";
        for(int i = start ; i <= end ; i++){
            result +=s[i];
        }
        return result;
    }
};