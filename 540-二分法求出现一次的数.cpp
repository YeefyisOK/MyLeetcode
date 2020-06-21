/*
����һ��ֻ�����������������飬ÿ��Ԫ�ض���������Σ�Ψ��һ����ֻ�����һ�Σ��ҳ��������

ʾ�� 1:

����: [1,1,2,3,3,4,4,8,8]
���: 2
ʾ�� 2:

����: [3,3,7,7,10,11,11]
���: 10

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/single-element-in-a-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
/*
���while�о�Ҫ��<=������ᳬʱ?
Ϊʲô2����Ҫ�ж������±������
*/
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		bool odd = false;
		while (left < right) {
			int mid = left + (right - left) / 2;
			odd = (right - mid) % 2 != 0;//������mid 


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
//��׼�Ĵ�
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
