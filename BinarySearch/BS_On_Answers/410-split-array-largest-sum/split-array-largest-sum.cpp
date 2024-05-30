class Solution {
public:
    int countPartitions(vector<int> &nums,int maxSum){
        int n = nums.size();
        int partitions = 1,subarraySum = 0;
        for(int i = 0;i<n;i++){
            if(subarraySum + nums[i] <= maxSum)
                subarraySum += nums[i];
            else{
                partitions ++;
                subarraySum = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans;
        if(k > n) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = (low+high)/2;
            int noOfPartitions = countPartitions(nums,mid);
            if(noOfPartitions > k) //mid is smaller than desired
                low = mid + 1;
            else  //mid is one of our answers but we want minimum possible
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};