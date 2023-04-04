class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int start = 0;
        int end = reader.length()-1;
        int mid;
        int ans = 0;
        int check;
        while(start <= end){
            mid = (start+end)/2;
            if((end-start)%2==0){
                check = reader.compareSub(start,max(mid-1,start),min(mid+1,end),end);
            }else{
                check = reader.compareSub(start,mid,min(mid+1,end),end);
            }
            if(check==0){
                ans = mid;
                break;
            }else if(check==1){
                end = mid;
            }else{
                start = mid+1;
            }
        }return ans;
    }
};