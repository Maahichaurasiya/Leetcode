class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>s;
        vector<int> ans;
        int n=grid.size();
        int a,b;
        int expSum=0;
        int actSum=0;

        // finding a that is reapeating value 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actSum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        // finding missing value(b)
        expSum=(n*n)*(n*n+1)/2;
        b=expSum+a-actSum;
        ans.push_back(b);
        return ans;

    }
};