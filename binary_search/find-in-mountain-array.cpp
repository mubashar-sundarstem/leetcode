class Solution {
public:
    int findInMountainArray(int target, MountainArray &ma) {
        int pl = 1;
        int pr = ma.length()-2;
        int bs = 0;
        while(pl <= pr){
            int mid = (pl+pr)/2;
            int first = ma.get(mid);
            int prev = ma.get(mid-1);
            int last = ma.get(mid+1);
            if(first > prev && first > last){
                bs = mid;
                break;
            }
            if(first > prev && first < last){
                pl = mid+1;
            }else{
                pr = mid-1;
            }
        }
        pl = 0;
        pr = bs;
        while(pl <= pr){
            int mid = (pl+pr)/2;
            int first = ma.get(mid);
            if(first == target){
                return mid;
            }
            if(first > target){
                pr = mid-1;
            }else{
                pl = mid+1;
            }
        }
        pl = bs+1;
        pr = ma.length()-1;
        while(pl <= pr){
            int mid = (pl+pr)/2;
            int first = ma.get(mid);
            if(first == target){
                return mid;
            }
            if(first < target){
                pr = mid-1;
            }else{
                pl = mid+1;
            }
        }
        return -1;
    }
};