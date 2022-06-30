class Solution {
public:
    int memo[10000004];
    vector <int> vec;
    int N;
    
    int solve(int n){
        int ans, i = 1, a1, a2;
        
        if(memo[n] != -1)
            ans = memo[n];
        else{
            if(n >= N - 1)
                ans = 0;
            else{
                ans = INT_MAX;
                while(i <= vec[n]){
                    a1 = solve(n + i);
                    if(a1 != INT_MAX)
                        ans = min(ans, a1 + 1);
                    i++;
                }
            }
            memo[n] = ans;
        }
        
        return ans; 
    }
    
    int jump(vector<int>& nums) {
        N = nums.size();
        for(int i = 0; i < N; i++){
            memo[i] = -1;
            vec.push_back(nums[i]);
        }
        
        return solve(0);
    }
};