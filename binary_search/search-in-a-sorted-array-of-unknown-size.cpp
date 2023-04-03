class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int pl = 0;
        int pr = pow(10,4);
        int mid = (pr+pl)/2;
        while(pl<=pr){
            mid = (pr+pl)/2;
            cout << mid << ' ';
            if(reader.get(mid)==target){
                return mid;
            }
            if(reader.get(mid) > target){
                pr = mid-1;
            }else{
                pl = mid+1;
            }
        }cout << endl;
        if(reader.get(mid)==target)
            return mid;
        else
            return -1;
    }
};