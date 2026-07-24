class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end() , [](vector<int>&a , vector<int>&b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] > b[0 ];
        });
        int n = people.size();
        vector<vector<int>>ans;

        for(int i = 0 ; i< n ; i++){
            int position = people[i][1];
           ans.insert(ans.begin()+ position , {people[i][0] , people[i][1]});
            
        }

        return ans;
    }
};