class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        int dr[]={0,+1,0,-1};
        int dc[]={+1,0,-1,0};

        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int row=curr.first;
            int col=curr.second;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && dis[nr][nc]==-1){
                    dis[nr][nc]=dis[row][col]+1;
                    q.push({nr,nc});
                }
            }
        }
        return dis;
    }
};