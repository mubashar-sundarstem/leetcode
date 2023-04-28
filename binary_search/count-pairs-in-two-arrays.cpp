class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        vector<long long> t1;
        vector<long long> t2;
        map<long long,bool> check;
        for(long long i = 0;i < nums2.size();i++){
            long long ans = nums1[i]-nums2[i];
            t1.push_back(nums1[i]-nums2[i]);
            t2.push_back(nums2[i]-nums1[i]);
            if(ans > -(ans)){
                check[i] = true;
            }
        }long long ans = 0;
        sort(t2.begin(),t2.end());
        for(long long i = 0;i < t1.size();i++)
        {
            long long ind = 0;
            long long pl = 0;
            long long pr = t2.size()-1;
            long long mid = 0;
            while(pl <= pr){
                mid = (pl+pr)/2;
                if(t2[mid] >= t1[i]){
                    pr = mid-1;
                }else{
                    pl = mid+1;
                }
            }
            ind = mid;
            if(t2[mid] < t1[i]){
                ind++;
            }
            if(check[i]==true)
                ind-=min((long long)1,ind);
            ans+=ind;
        }//because it will count a pair twice
        return (ans)/2;
    }
};