class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        string st=to_string(n);
        int s=st.size();
        if(s<3)return 0;
        if(s>=4&&s<=6){
            return n-999;
        }
        if(s>=7&&s<=9){
            return n-999999+n-999;
        }
        if(s>=10&&s<=12)return n-999999999+n-999999+n-999;
       if(s>=13&&s<=15)return n-999999999999+n-999999999+n-999999+n-999;
       if(s>15)return n-999999999999999+n-999999999999+n-999999999+n-999999+n-999;
       return 0;
        
    }
};