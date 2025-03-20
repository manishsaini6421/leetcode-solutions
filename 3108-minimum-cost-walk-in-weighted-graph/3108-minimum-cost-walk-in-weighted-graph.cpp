class DSU{
        public:
        vector<int> Parent,Rank, minWalk;
    
        DSU(int n){
            Parent.resize(n+1);
            Rank.resize(n+1,0);
            minWalk.resize(n+1,-1);

            for(int i=0; i<=n; i++){
                Parent[i]=i;
            }
        }    

        int find(int u){
            if(Parent[u]==u)
                return u;
            return Parent[u]=find(Parent[u]);    
        }

        void unionByRank(int u,int v,int w){
            int ulp_u=find(u);
            int ulp_v=find(v);
            if(ulp_u==ulp_v){
                minWalk[ulp_u]&=w;
                return;
            }
            
            if(Rank[ulp_u]<Rank[ulp_v]){

                Parent[ulp_u]=ulp_v;
                if(minWalk[ulp_u]==-1){
                    minWalk[ulp_v]&=w;
                }
                else{
                    minWalk[ulp_v]&=(minWalk[ulp_u]&w);
                }
                
            }
            else if(Rank[ulp_u]>Rank[ulp_v]){
                Parent[ulp_v]=ulp_u;
                if(minWalk[ulp_v]==-1){
                    minWalk[ulp_u]&=w;
                }
                else{
                    minWalk[ulp_u]&=(minWalk[ulp_v]&w);
                }
                
            }
            else{
                Parent[ulp_v]=ulp_u;
                Rank[ulp_u]++;
                if(minWalk[ulp_v]==-1){
                    minWalk[ulp_u]=w;
                }
                else{
                    minWalk[ulp_u]&=(minWalk[ulp_v]&w);
                }
            }
        }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       DSU ds(n);

       for(auto edge:edges){
            ds.unionByRank(edge[0],edge[1],edge[2]);
       }
       vector<int> ans;
       for(int i=0; i<query.size(); i++){
        int ulp_1=ds.find(query[i][0]);
        int ulp_2=ds.find(query[i][1]);
        if(ulp_1==ulp_2){
            ans.push_back(ds.minWalk[ulp_1]);
        }
        else ans.push_back(-1);
       }
       return ans;
    }
};