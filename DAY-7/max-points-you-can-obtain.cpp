class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int totalsum = 0;
        for(int i=0;i<cardPoints.size();i++)
            totalsum += cardPoints[i];
        int tempsum = 0;
        for(int i=0;i<cardPoints.size()-k;i++)
        {
            tempsum += cardPoints[i];
        }
        int idxfirst = 0;
        int idxlast = cardPoints.size()-k;
        int maxsum = tempsum;
        while(idxlast!=cardPoints.size())
        {
            tempsum = tempsum - cardPoints[idxfirst] + cardPoints[idxlast];
            idxlast++;
            idxfirst++;
            maxsum = min(maxsum, tempsum);
        }
        return totalsum - maxsum;
    }
};