class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
		int maxn = INT_MAX;
		nums.push_back(maxn);
		vector<int> diff_array;
		for(int i = 1;i <nums.size();i++){
			diff_array.push_back(nums[i]-nums[i-1]);
		}
		int ans = nums[0]+1;
		int diff_index = 0;
		int sz = diff_array.size();
		for(int i = 0;i < sz;i++){
			if(k-diff_array[i] < 0){
				ans = nums[i]+k;
				break;
			}k-=diff_array[i]-1;
		}
		return ans;
	}
};