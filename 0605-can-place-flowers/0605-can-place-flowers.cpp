class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k=flowerbed.size();
        if(n==0)return true;
        for(int i=0;i<k;i++){
            if(i==0&&k==1&&flowerbed[i]==0){n--;}
            if(i==0&&k>1&&flowerbed[i]==0&&flowerbed[i+1]!=1){flowerbed[i]=1;n--;}
            if(i==k-1&&i>=1){
                if(flowerbed[i-1]==0&&flowerbed[i]!=1){flowerbed[i]=1;n--;}
            }
            if(k>2&&i>0&&i!=k-1){
                if(flowerbed[i]!=1&&flowerbed[i+1]!=1&&flowerbed[i-1]!=1){
                    flowerbed[i]=1;n--;}

            }
            if(n==0)return true;
        }
        return false;
    }
};