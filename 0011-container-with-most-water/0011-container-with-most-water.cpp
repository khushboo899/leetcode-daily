class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxWater=0;

        while(l<r){
            int width=r-l;
            int h=min(height[l],height[r]);
            int area=width*h;
            maxWater=max(area,maxWater);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxWater;
    }
};