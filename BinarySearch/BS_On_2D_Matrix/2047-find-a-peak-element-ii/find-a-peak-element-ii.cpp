class Solution {
public:
    int findMaxRowIndex(vector<vector<int>>& mat,int n,int m,int col){
        int maxElement = -1;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxElement){
                maxElement = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int  low = 0,high=m-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int col = mid;
            int row = findMaxRowIndex( mat, n, m,  col);
            int left = (col - 1 >= 0) ? mat[row][col - 1] : -1;
            int right = (col + 1 < m) ? mat[row][col + 1] : -1;
            if(mat[row][col] >left && mat[row][col]>right)
                return {row,col};
            else if(mat[row][col] < left) high = mid-1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};