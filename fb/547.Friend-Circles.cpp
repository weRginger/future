// Ziqi: small optimization - only need to traverse up-right corner instead of the whole matrix
// Time O(n^2)
// Space O(n)
class Solution {
    class DS{
        vector<int> parent;
        vector<int> rank;
        int count;
        
    public:
        DS(int n){
            parent.resize(n);
            fill(parent.begin(),parent.end(),-1);
            
            rank.resize(n);
            fill(rank.begin(),rank.end(),0);
            
            count = n;
        }
        
        int find(int n){
            if(parent[n] == -1) return n;
            return parent[n] = find(parent[n]);
        }
        
        void merge(int a, int b){
            int pa = find(a);
            int pb = find(b);
            
            if(pa == pb) return;
            
            if(rank[pa] > rank[pb]){
                parent[pb] = pa; 
            }else if(rank[pa] < rank[pb]){
                parent[pa] = pb;
            }else{
                parent[pa] = pb;
                rank[pb]++;
            }
            
            count--;
        }
        
        int getCount(){
            return count;
        }
        
    };
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        DS ds(M.size());
        for(int r=0; r<M.size(); r++){
            for(int c=r+1; c<M.size(); c++){
                if(M[r][c]){
                    ds.merge(r,c);
                }
            }
        }
        
        return ds.getCount();
    }
};
