class Solution {
public:
    bool checkPartitioning(string s) {
        int n=s.size();
        bool ispal[2000][2000];
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0)
                    ispal[i][j]=1;
                else if(g==1){
                    ispal[i][j]=s[i]==s[j]?1:0;
                }
                else {
                    ispal[i][j]=(s[i]==s[j] && ispal[i+1][j-1])?1:0;
                }
            }
        }
        for(int i=0;i<n-2;i++){
            if(ispal[0][i]){
                for(int j=i+1;j<n-1;j++){
                    if(ispal[i+1][j] && ispal[j+1][n-1])
                        return true;
                }
            }
        }
        return false;
    }
};
