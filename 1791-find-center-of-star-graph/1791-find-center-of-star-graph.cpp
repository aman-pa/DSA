class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // map<int,int>mpp;
        // for(int i=0;i<edges.size();i++){
        //     mpp[edges[i][0]]++;
        //     mpp[edges[i][1]]++;
        // }
        // for(auto it :mpp){
        //     if(it.second==edges.size())return it.first;
        // }
        // return -1;
        if(edges[0][0]==edges[1][0])return edges[0][0];
        if(edges[0][0]==edges[1][1])return edges[0][0];
        return edges[0][1];
    }
};