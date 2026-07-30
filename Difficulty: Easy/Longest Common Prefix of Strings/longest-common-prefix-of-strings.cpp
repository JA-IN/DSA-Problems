class Solution {
  public:
    string longestCommonPrefix(vector<string> strs) {
        // your code here
         if(strs.size() == 0){
            return "";
        }

        int minstr = strs[0].size() ;
        int index = 0 ;
        for(int i = 1 ; i< strs.size() ; i++){
            int size = strs[i].size();
            if(minstr > size){
                minstr = size ;
                index = i ;
            }
        }

        string ans = "";
        bool not_equal = false ;
        for(int i = 0 ; i < minstr ; i++){
            char c = strs[index][i];
            for(int j = 0 ; j < strs.size() ; j++){
                if(strs[j][i] != c){
                    not_equal = true ;
                    break;
                }
            }
            if(not_equal == true){
                break;
            }
            ans +=c;
        }

        return ans;

    }
};