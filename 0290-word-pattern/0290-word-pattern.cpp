class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>charto_word;
        unordered_map<string,char>wordto_char;

        int n = pattern.size();
        int idx = 0 ; 
        
        for(int i = 0 ; i<n;i++){

            if(idx >= s.size()) return false ;  // check for words less than char

            char c = pattern[i];
            string word = "";
            while(idx < s.size() && s[idx] != ' '){
            word +=s[idx];
            idx++;
            }
            idx++;
            
            if((charto_word.find(c) != charto_word.end()) && (charto_word[c] !=word)){
                return false;
            }
             if((wordto_char.find(word) != wordto_char.end())&& (wordto_char[word] != c)){
                return false;
            }
            charto_word[c] = word;
            wordto_char[word] = c;
        }
         if(idx < s.size()) return false ;  // check for wrods more than char

        return true;
    }
};