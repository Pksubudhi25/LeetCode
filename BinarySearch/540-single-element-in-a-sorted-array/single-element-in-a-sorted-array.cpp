class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // Handle the edge cases for the smallest possible arrays
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n - 1];

        int low = 1, high = n - 2;  // Adjusted to avoid out-of-bounds access

        while(low <= high) {
            int mid = (low + high) / 2;

            // Check if the mid element is the single element
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Check which side to discard
            if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
               (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // We are in the left half, discard it
                low = mid + 1;
            } else {
                // We are in the right half, discard it
                high = mid - 1;
            }
        }

        // If we exit the loop, something went wrong
        return -1;  // This should never happen
    }
};
