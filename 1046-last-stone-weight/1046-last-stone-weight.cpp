class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int x:stones)pq.push(x);
        while(!pq.empty()){
            if(pq.size()==1)return pq.top();
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            if(f!=s)pq.push(abs(f-s));
            
        }
        return 0;
    }
};