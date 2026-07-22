class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 0){
            return false;
        }
        bool leftEmpty , rightEmpty ;
        for(int i = 0 ; i<flowerbed.size();i++){
           leftEmpty  = (i==0 || flowerbed[i-1]==0);
           rightEmpty = (i==flowerbed.size()-1 || flowerbed[i+1]==0);

           if(flowerbed[i] == 0 && leftEmpty && rightEmpty){
            flowerbed[i] = 1 ;
            n--;
           }
        }
        if(n >0){
            return false ;
        }
        return true;
    }
};