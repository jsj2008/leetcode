/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?
 */
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; ++i){
            int l = i+1, r = n-1;
            while(l<r){
                if(nums[l]+nums[r]+nums[i]<target){
                    //printf("%d %d %d\n",i,l,r);
                    cnt = cnt + (r-l);
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return cnt;
    }
};