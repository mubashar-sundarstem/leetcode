class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &a) {
        int n,m;
        n=a.dimensions()[0];
        m=a.dimensions()[1];
        int ans = INT_MAX; 
        for(int i = 0;i < n;i++){
            int pl = 0;
            int pr = m-1;
            int temp = INT_MAX;
            int mid = 0;
            while(pl<=pr){
                mid = (pl+pr)/2;
                if(a.get(i,mid)==1){
                    temp = min(mid,temp);
                    pr = mid-1;
                }else{
                    pl = mid+1;
                }
            }ans = min(ans,temp);
        }
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};