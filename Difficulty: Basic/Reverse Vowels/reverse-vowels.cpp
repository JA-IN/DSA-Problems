class Solution {
  public:
  bool isvowel(char c){
        if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o'  || tolower(c) == 'u' ){
            return true;
        }
        return false;
    }
    string modify(string& s) {
        // code here
                vector<char>vow;
        for(int i = 0 ; i< s.size() ; i++){

            if(isvowel(s[i])){
                vow.push_back(s[i]);
            }
        }

        reverse(vow.begin() , vow.end());
        int idx = 0 ;
        for(int i = 0 ; i< s.size() ; i++){
            if(isvowel(s[i])){
                s[i] = vow[idx];
                idx++;
            }
        }

        return s;
    }
};
