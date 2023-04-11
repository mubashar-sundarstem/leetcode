class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
		int n = mat[0].size();
		for(int i = 0;i < mat[0].size();i++){
			int target = mat[0][i];
			int ans = 0;
			for(int j = 1;j < mat.size();j++){
				int pl= 0;
				int pr =n-1;
				while(pl <= pr){
					int mid = (pl+pr)/2;
					if(mat[j][mid]==target){
						ans++;
						break;
					}else if(mat[j][mid] > target){
						pr = mid-1;
					}else{
						pl = mid+1;
					}
				}
			}if(ans==mat.size()-1){
				return target;
			}
		}return -1;
    }
};