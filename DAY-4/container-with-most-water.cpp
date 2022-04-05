class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int s = 0,e = height.size()-1;
        int area = INT_MIN;
        
        while(s<e){
            int tot = (e-s)*min(height[s],height[e]);
            area = max(area,tot);
            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
            
        }
        
        return area;
    }
};
