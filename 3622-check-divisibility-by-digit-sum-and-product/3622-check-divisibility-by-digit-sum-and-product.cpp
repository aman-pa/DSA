class Solution {
public:
    bool checkDivisibility(int n) {
        int p=1;
        int s=0;
        int k=n;
        while(n!=0){
            int r=n%10;
            s+=r;
            p*=r;
            n/=10;
        }
        return (k%(p+s)==0);
    }
};