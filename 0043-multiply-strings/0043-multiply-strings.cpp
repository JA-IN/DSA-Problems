class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>product(num1.size() + num2.size() , 0);
        

        int carry = 0 ;
        for(int i = num1.size()-1; i >=0 ;  i--){
            int val1 = num1[i] - '0';
            for(int j = num2.size() -1 ; j >=0 ; j--){
               int val2 = num2[j] -'0';
               int p1 =  i+j;
               int p2 = i + j + 1;

               int result =product[p2]+ val1 * val2;

               int val = result % 10 ;
               int carry = result / 10 ;

                product[p2] = val;
                product[p1] += carry;

            }
        }

        string ans = "";
        int idx = 0 ;
        while(idx < product.size() && product[idx] == 0){
            idx++;
        }
        if (idx == product.size())
            return "0";


        for(int i = idx ; i< product.size() ; i++){
            ans += product[i] +'0';
        }

        return ans;
    }
};