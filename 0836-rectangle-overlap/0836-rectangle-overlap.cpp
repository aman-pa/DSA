class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x11=rec1[0],y11=rec1[1],x21=rec1[2],y21=rec1[3];
        int x12=rec2[0],y12=rec2[1],x22=rec2[2],y22=rec2[3];
        if(x12>=x21&&x22>=x21)return false;
        if (x21 <= x12 || x22 <= x11)
    return false;
    if (y21 <= y12 || y22 <= y11)
    return false;
        return true;
       
       
    }
};