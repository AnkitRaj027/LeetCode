class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lMax=0;
        int RMax=0;
        int total=0;
        int l=0;
        int r=n-1;
        while(l<r){
            if(height[l]<height[r]){
                if(lMax>height[l]){
                    total+=(lMax-height[l]);
                }else{
                    lMax=height[l];
                }
                l++;
            }else{
                if(RMax>height[r]){
                    total+=(RMax-height[r]);
                }else{
                    RMax=height[r];
                }
                r--;
            }
        }
        return total;
    }
};