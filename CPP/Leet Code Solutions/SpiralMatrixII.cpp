class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int fill=1,dir=0;
        vector<vector<int>> a(n,vector<int>(n));
        int t=0,r=n-1,b=n-1,l=0;
        while(l<=r && t<=b){
            if(dir==0){
                for(int i=l;i<=r;i++)
                    a[t][i]=fill++;
                t++;
            }
            else if(dir==1){
                for(int i=t;i<=b;i++)
                    a[i][r]=fill++;
                r--;
            }
            else if(dir==2){
                for(int i=r;i>=l;i--)
                    a[b][i]=fill++;
                b--;
            }
            else if(dir==3){
                for(int i=b;i>=t;i--)
                    a[i][l]=fill++;
                l++;
            }
            dir=(dir+1)%4;
        }
        return a;
    }
};
