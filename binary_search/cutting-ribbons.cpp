class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
		int pl = 1;
		int pr = *max_element(ribbons.begin(),ribbons.end());
		int sz = ribbons.size();
		int mid = 0;
		int ans = 0;
		while(pl <= pr){
			mid = (pl+pr)/2;
			int check = 0;
			for(int i = 0;i < sz;i++){
					check+=ribbons[i]/mid;
			}
			if(check >= k){
				ans = max(ans,mid);
				pl = mid+1;
			}else{
				pr = mid-1;
			}
		}return ans;
	}
};