class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int bill_5 = 0 , bill_10 = 0 , bill_20 = 0;
        bool ans = true;

        for(int i = 0 ; i<arr.size();i++){
            if(arr[i] == 5){
                bill_5++;
            }
            else if(arr[i] == 10){
                bill_10++;
                if(bill_5 == 0){
                    ans = false ;
                    break;
                }
                bill_5--;
            }
            else if(arr[i] == 20){
                bill_20++;
               if(bill_5 >0 && bill_10 > 0){
                bill_5-- , bill_10--;
               }
               else if(bill_10 == 0 && bill_5 >=3){
                bill_5 -=3;
               }
               else{
                ans = false ;
                break;
               }
            }
        }

        return ans;
    }
};