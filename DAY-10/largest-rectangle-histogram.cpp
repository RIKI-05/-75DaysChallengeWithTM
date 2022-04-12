    int ans=INT_MIN;
    
    for(int i=0;i<heights.size();i++){
        
        int l=i-1;
        int r=i+1;
        //int lIndex=0;
        while(l>=0){
            if(heights[i]<=heights[l])
                l--;
            else{
                break;
            }
        }
        while(r<=heights.size()-1){
            if(heights[i]<=heights[r])
                r++;
            else{
                break;
            }
        }
        
        
        int total_length=(r-i)+(i-l-1);
        
        ans=max(ans,total_length*heights[i]);
        
    }
    return ans;