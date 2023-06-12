class Solution {
public:
    int shipWithinDays(vector<int>& weight, int days) {
        int weight_sz = weight.size();
        int Asum = 0;
        int maxe = 0;
        for(int i = 0;i < weight_sz;i++){
            int h = weight[i];
            maxe = max(maxe,h);
            Asum+=h;
        }Asum+=1;
        int leftp = maxe;//left pointer
        int rightp = Asum;//right pointer
        int sumcheck = 0;
        int daycheck = 0;
        int ans = INT_MAX;
        int mid = (leftp+rightp)/2;
        while(leftp <= rightp){
            mid = (leftp+rightp)/2;
            sumcheck = 0;
            daycheck = 0;
            for(int i = 0;i < weight_sz;i++){
                if(sumcheck+weight[i] > mid){
                    daycheck++;
                    sumcheck = 0;
                }
                sumcheck+=weight[i];
            }if(sumcheck > 0){
                daycheck++;
            }
            if(daycheck > days){
                leftp = mid+1;
            }else{
                ans = min(ans,mid);
                rightp = mid-1;
            }
        }return ans;
    }
};
