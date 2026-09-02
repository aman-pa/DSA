class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<m;i++){
            int sol=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)sol++;
            }
            pq.push({sol,i});
        }
        int c=0;
        while(c!=k){
            c++;
            ans.push_back(pq.top().second);
            pq.pop();

        }

    return ans;

    }
};