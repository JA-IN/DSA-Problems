class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>last_place;
        for(int i = 0 ; i< s.size();i++){
            last_place[s[i]] = i ;
        }
        int curr_partition = 0 , curr_start = 0 ;
        vector<int>ans ;
        for(int i = 0 ; i< s.size() ;i++){
            curr_partition = max(curr_partition , last_place[s[i]]);

            if(i == curr_partition){
                ans.push_back(curr_partition - curr_start +1);
                curr_start = curr_partition + 1;

            }
        }
        return ans ;
    }
};