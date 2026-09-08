class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int k=hand.size()%groupSize;
        if(k!=0)return false;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x:hand)pq.push(x);
        while(!pq.empty()){
            int k=pq.top();
            vector<int>temp;
            int prev=k;
            pq.pop();
           int count = 1;

        while(count < groupSize){
            if(pq.empty()) return false;

            int k = pq.top();
            pq.pop();

            if(k == prev){
                temp.push_back(k);
            }
            else if(k == prev + 1){
                prev = k;
                count++;
            }
            else{
                return false;
            }
        }
            if(temp.size()>0){
            for(int x:temp)pq.push(x);}
        }
        return true;
    }
};