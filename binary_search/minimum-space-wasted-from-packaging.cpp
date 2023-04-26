class Solution {
public:
    long long minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        long long mod = 1e9+7;
        long long ans = 1e12;
        long long sum = 0;
        long long maxn = 0;
        for(long long i = 0;i < packages.size();i++){
            sum+=packages[i];
        }
        
        
        
        sort(packages.begin(),packages.end());
        for(long long j = 0;j < boxes.size();j++){
            long long init = 0;
            long long temp = 0;
            sort(boxes[j].begin(),boxes[j].end());
            for(long long i = 0;i < boxes[j].size();i++){
                long long o = upper_bound(packages.begin(),packages.end(),boxes[j][i])-packages.begin();
                cout << o << ' ';
                temp+=(o-init)*boxes[j][i];
                init = o;
            }
            if(init >= packages.size())
                ans = min(ans,temp-sum);
        }
        
        if(ans==1e12){
            return -1;
        }
        ans%=mod;
        return ans;
    }
};