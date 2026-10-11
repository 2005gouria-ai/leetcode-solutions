class Solution {
public:

    // Find the row having maximum element in column 'col'
    int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
        int maxRow = 0;

        for (int i = 1; i < n; i++) {
            if (mat[i][col] > mat[maxRow][col]) {
                maxRow = i;
            }
        }

        return maxRow;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();        // number of rows
        int m = mat[0].size();     // number of columns

        int low = 0;
        int high = m - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Find maximum element's row in column mid
            int maxRowIndex = findMaxIndex(mat, n, m, mid);

            int left = (mid > 0) ? mat[maxRowIndex][mid - 1] : -1;
            int right = (mid < m - 1) ? mat[maxRowIndex][mid + 1] : -1;

            // Current element is a peak
            if (mat[maxRowIndex][mid] > left &&
                mat[maxRowIndex][mid] > right) {

                return {maxRowIndex, mid};
            }

            // Move towards the larger side
            if (right > mat[maxRowIndex][mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};