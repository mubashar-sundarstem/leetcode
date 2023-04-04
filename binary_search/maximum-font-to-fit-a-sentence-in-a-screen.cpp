class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo)
    {
        long long pl = 0;
        long long pr = fonts.size()-1;
        long long mid;
        long long ans = -1;
        while(pl <= pr){
            mid = (pl+pr)/2;
            long long temph = fontInfo.getHeight(fonts[mid]);
            long long sum = 0;
            for(int i = 0;i < text.size();i++){
                sum+=fontInfo.getWidth(fonts[mid],text[i]);
            }
            if(sum <= w && temph <= h){
                ans = max(ans,(long long)fonts[mid]);
                pl = mid+1;
            }else{
                pr = mid-1;
            }
        }return ans;
    }
};