class Solution {
public:
    int sumByD(vector<int>& nums, int divisor){
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++)
            sum += ceil((double)(nums[i])/(double)(divisor));
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi  = *max_element(nums.begin(), nums.end());
        int low = 1;
        int high = maxi;
        while(low <= high){
            int mid = (low + high)/2;
            int sum = sumByD(nums, mid);
            if(sum<=threshold) //It is possible answer
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
        
    }
};