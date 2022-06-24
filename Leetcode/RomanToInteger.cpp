class Solution {
public:
    int romanToInt(string s) {
        map <char, int> rnums;
        vector <int> nums;
        int n, ans = 0;
        
        rnums['I'] = 1;
        rnums['V'] = 5;
        rnums['X'] = 10;
        rnums['L'] = 50;
        rnums['C'] = 100;
        rnums['D'] = 500;
        rnums['M'] = 1000;
        n = s.size();

        for(int i = 0; i < n; i++)
            nums.push_back(rnums[s[i]]);

        for(int i = 0; i < n - 1; i++){
            if (nums[i] < nums[i + 1])
                ans -= nums[i];
            else
                ans += nums[i];
        }
        ans += nums[n - 1];
    
        return ans;
    }
};