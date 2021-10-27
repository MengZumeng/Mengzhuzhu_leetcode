class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vRet(n,vector<int>(n));
        int iStartx=0,iStarty=0,iOffset=1;
        int iLoop = n/2;
        int counter = 1;
        while(iLoop--){
            int i=0,j=0;
            for(j =iStarty;j<n-iOffset;j++){
                vRet[iStartx][j]=counter++;
            }

            for(i =iStartx;i<n-iOffset;i++){
                vRet[i][j]=counter++;
            }

            for(;j>iStarty;j--){
                vRet[i][j]=counter++;
            }

            for(;i>iStartx;i--){
                vRet[i][j]=counter++;
            }

            iStartx += 1;
            iStarty +=1;
            iOffset +=1;

        }
        if(n %2 ==1) vRet[iStartx][iStarty] = n*n;


        return vRet;
    }
};