class KthLargest {
public:
    int p;
    vector<int>ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
     p=k;
     ans=nums;
    for(int x:nums)pq.push(x);
    
    }
    int add(int val) {
        ans.push_back(val);
        pq.push(val);
        vector<int>temp;
        int c=0;
        while(pq.size()!=p){
            pq.pop();
        }
        return pq.top();
        }
   
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */