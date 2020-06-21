/*
给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。

示例 1:

输入: [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:

输入: [3,3,7,7,10,11,11]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
如果while中就要用<=，结果会超时?
为什么2不需要判断数组下标溢出？
*/
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		bool odd = false;
		while (left < right) {
			int mid = left + (right - left) / 2;
			odd = (right - mid) % 2 != 0;//不包括mid 


			if (mid + 1 <= nums.size() - 1 && nums[mid] == nums[mid + 1]) {
				if (odd) {//1122
					right = mid - 1;
				}
				else {//112
					left = mid + 2;
				}
			}
			else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
				if (odd) {//1122334
					left = mid + 1;
				}
				else {//12233 4455
					right = mid - 2;
				}
			}
			else if (mid - 1 >= 0 && mid + 1 <= nums.size() - 1 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
				return nums[mid];
			}

		}
		return nums[left];
	}
};
//标准的答案
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int l = 0, r = nums.size() - 1, mid = 0;
		bool odd = false;
		while (l < r)
		{
			mid = l + (r - l) / 2;
			odd = (r - mid) % 2 != 0;
			if (nums[mid - 1] == nums[mid])
			{
				if (odd) l = mid + 1;
				else r = mid - 2;
			}
			else if (nums[mid + 1] == nums[mid])
			{
				if (odd) r = mid - 1;
				else l = mid + 2;
			}
			else
				return nums[mid];

		}

		return nums[l];
	}
};
