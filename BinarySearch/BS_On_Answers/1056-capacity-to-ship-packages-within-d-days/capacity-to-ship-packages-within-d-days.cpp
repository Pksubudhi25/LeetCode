class Solution {
public:
    int findDays(vector<int>& weights, int mid){
        int day = 1, load=0;
        int n = weights.size();
        for(int i = 0;i<n;i++){
            if(load+weights[i] > mid){
                day+=1;
                load = weights[i];
            }
            else
                load += weights[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for(int i = 0 ;i<weights.size();i++)
             sum += weights[i];
        int low = maxi, high = sum;
        while(low <= high){
            int mid = (low + high) / 2;
            int noOfDays = findDays(weights, mid);
            if(noOfDays <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
        
    }
};