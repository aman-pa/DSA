class Solution {
public:
    int fillCups(vector<int>& amount) {
        int n=amount.size();
        priority_queue<int>pq;
        int sum=0;
        for(int x:amount){
            if(x!=0)
            pq.push(x);
            sum+=x;
        }
        if(sum==0)return 0;
        int ans=0;
        while(pq.size()!=0){
            if(pq.size()>1){
                int k=pq.top();
                pq.pop();
                int l=pq.top();
                pq.pop();
                if(k>1)pq.push(k-1);
                if(l>1)pq.push(l-1);
                ans++;
            }
            else if(pq.size()==1){
                int s=pq.top();
                pq.pop();
                if(s>1)pq.push(s-1);
                ans++;
            }
            
           
       }

       return ans;
    }
};