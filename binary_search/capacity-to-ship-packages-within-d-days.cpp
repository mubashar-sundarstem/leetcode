#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    int weight_sz,days;//input of weight array size and days
    cin >> weight_sz >> days;
    vector<int> weight;
    int Asum = 0;//array sum
    int maxe = 0;//max element
    for(int i = 0;i < weight_sz;i++){//input of array
        int h;
        cin >> h;
        maxe = max(maxe,h);
        Asum+=h;
        weight.push_back(h);
    }Asum+=10;
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
    }cout << ans << endl;
}