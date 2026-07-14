class Solution{
    public:
    void dfs(int sr,int sc,vector<vector<int>> &ans,vector<vector<int>> &image,int newColor,int inicolor,int delrow[],int delcol[]){
        ans[sr][sc]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==inicolor && ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,ans,image,newColor,inicolor,delrow,delcol);
            }

        }
    }


    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {
                                    vector<vector<int>> ans=image;
                                    int inicolor=image[sr][sc];
                                    int delrow[]={0,+1,0,-1};
                                    int delcol[]={+1,0,-1,0};
                                    dfs(sr,sc,ans,image,newColor,inicolor,delrow,delcol);
                                    return ans;

    }
};
