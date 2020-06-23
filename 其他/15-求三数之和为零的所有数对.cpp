/*
给你一个包含 n 个整数的数组?nums，判断?nums?中是否存在三个元素 a，b，c ，使得?a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

?

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
思路：
我们首先将 lo 和 hi 指向数组首尾两个元素。然后进行二分搜索将数组搜索空间减半（搜索过程中要保证是奇数个元素） 
直到找到单一元素或者仅剩一个元素为止。当搜索空间只剩一个元素，则该元素就是单个元素。
通过检查mid右侧元素数量和mid是否等于mid+1及mid-1判断 

*/
/*
注意ijk都要去重
注意当输入是空数组的情况，空数组的size是多少？ devC++测试为0，leetcode不转化为int会出错，可能是编译器不同？ 
循环去重时注意不要越界（主要问题出在i上，当输入为0000时） 
自己写的代码 
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
       
        vector<vector<int>> res;
        for(int i=0;i<int(nums.size()-2);i++){
            while(i-1>=0&&i<nums.size()-2&&nums[i]==nums[i-1]) i++;//i去重且防止越界
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==sum){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<sum){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>sum){
                    k--;
                }
            }
        }
        return res;
    }
};
