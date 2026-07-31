class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        reverse(s.begin() , s.end());
        string ans = "";
        int i = 0 ;
        while(i < s.size()){
            string word = "";
            
            while( i < s.size() && s[i] != '.'){
                word +=s[i];
                i++;
            }
            if(word.size() >0){
                reverse(word.begin() , word.end());
                ans +='.'+word;
            }
            
            
            while( i < s.size() && s[i] == '.'){
                i++;
            }
            
        }
        
        return ans.substr(1);
    }
};