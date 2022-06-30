class Solution {
public:
    int memo[10005];
    vector <int> vec;
    int N;
    
    int solve(int n){
        int ans, i = 1;
        
        if(memo[n] != -1)
            ans = memo[n];
        else{
            if(n >= N - 1)
                ans = 1;
            else{
                ans = 0;
                while(i <= vec[n] && !ans){
                    ans = solve(n + i);
                    i++;
                }
            }
            memo[n] = ans;
        }
       return ans; 
    }
    
    bool canJump(vector<int>& nums) {
        N = nums.size();
        for(int i = 0; i < N; i++){
            vec.push_back(nums[i]);
            memo[i] = -1;
        }
        
        return solve(0);
    }
};