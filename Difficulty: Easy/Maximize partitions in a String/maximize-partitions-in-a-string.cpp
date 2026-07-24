class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char,int>last_place;
        for(int i = 0 ; i< s.size();i++){
            last_place[s[i]] = i ;
        }
        int curr_partition = 0 ;
        int partitions = 0 ;
        for(int i = 0 ; i< s.size() ;i++){
            curr_partition = max(curr_partition , last_place[s[i]]);

            if(i == curr_partition){
                partitions++;
                

            }
        }
        return partitions ;
    }
};