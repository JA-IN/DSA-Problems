class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mp;
        for(int i = 0 ; i< paths.size() ; i++){
            string curr = paths[i];
            string directory = "";
            int j = 0 ;
            while(curr[j] != ' '){
                directory +=curr[j];
                j++;
            }
            j++;
        
            while(j < curr.size()){
                string file_name = "";
                while(curr[j] != '('){
                    file_name +=curr[j];
                    j++;
                }
                j++;
                string content = "";
                while(curr[j] != ')'){
                    content +=curr[j];
                    j++;
                }
                string file_path = directory+'/'+file_name;
                mp[content].push_back(file_path);
                j++;
                j++;
            }
        }
        vector<vector<string>>ans;
        for(auto it : mp){
            if(it.second.size() >1){
            ans.push_back(it.second);
            }
        }

        return ans;
    }
};