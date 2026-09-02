class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x:nums)pq.push(x);
        while(true){
            if(pq.size()==0)return original;
            if(pq.top()==original)original*=2;
            else if(pq.top()<original){
                pq.pop();
            }
            else return original;
        }
        return original;
    }
};