class Solution {
public:
    int reverseDegree(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
        c+= (123-(s[i]))*(i+1);
    }
    return c;
    }
};