class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        int dr[]={0,+1,0,-1};
        int dc[]={+1,0,-1,0};

        while(!q.empty()){
            auto[row,col]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && ans[nr][nc]==-1){
                    ans[nr][nc]=ans[row][col]+1;
                    q.push({nr,nc});                }
            }
        }
        return ans;
    }
};