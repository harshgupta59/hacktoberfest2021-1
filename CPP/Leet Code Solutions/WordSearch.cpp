class Solution {
public:
    
    bool dfs(int x,int y,vector<vector<char>> &board,int ind,string s,int n,int m, vector<vector<int>> &vis){
        vis[x][y]=1;
        if(ind==s.size())return true;
        //cout<<board[x][y]<<" ";
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int rr=x+dx[i],cc=y+dy[i];
            if(rr>=0 && cc>=0 && rr<n && cc<m && !vis[rr][cc] && s[ind]==board[rr][cc] ){
                if(dfs(rr,cc,board,ind+1,s,n,m,vis))return true;
            }
        }
        vis[x][y]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string s) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==s[0]){
                    vector<vector<int>> vis(n+1,vector<int>(m+1,0));
                    if(dfs(i,j,board,1,s,n,m,vis) || s.size()==1)return true;
                   // cout<<endl;
                }
            }
        }
        return false;
    }
};
