/*
    34. Find First and Last Position of Element in Sorted Array

    Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
    If target is not found in the array, return [-1, -1].

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
    Example 2:

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
*/

// Solution :

class Solution {
public:
    int firstOccurance(vector<int>& nums, int n, int target) {
        int low = 0 , high = n - 1;
        int first = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return first;
    }
    
    int lastOccurance(vector<int>& nums, int n, int target) {
        int low = 0 , high = n - 1;
        int last = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = firstOccurance(nums, nums.size(), target);
        ans.push_back(first);
        if(first == -1) {
            ans.push_back(first);
            return ans;
        }
        else {
            int last = lastOccurance(nums, nums.size(), target);
            ans.push_back(last);
        }

        return ans;
    }
};

/*
    Time Complexity: 2 * O(log n), n = size of array
*/