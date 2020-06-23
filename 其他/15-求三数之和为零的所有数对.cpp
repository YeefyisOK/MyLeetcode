/*
����һ������ n ������������?nums���ж�?nums?���Ƿ��������Ԫ�� a��b��c ��ʹ��?a + b + c = 0 �������ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣

?

ʾ����

�������� nums = [-1, 0, 1, 2, -1, -4]��

����Ҫ�����Ԫ�鼯��Ϊ��
[
  [-1, 0, 1],
  [-1, -1, 2]
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/3sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
/*
˼·��
�������Ƚ� lo �� hi ָ��������β����Ԫ�ء�Ȼ����ж������������������ռ���루����������Ҫ��֤��������Ԫ�أ� 
ֱ���ҵ���һԪ�ػ��߽�ʣһ��Ԫ��Ϊֹ���������ռ�ֻʣһ��Ԫ�أ����Ԫ�ؾ��ǵ���Ԫ�ء�
ͨ�����mid�Ҳ�Ԫ��������mid�Ƿ����mid+1��mid-1�ж� 

*/
/*
ע��ijk��Ҫȥ��
ע�⵱�����ǿ������������������size�Ƕ��٣� devC++����Ϊ0��leetcode��ת��Ϊint����������Ǳ�������ͬ�� 
ѭ��ȥ��ʱע�ⲻҪԽ�磨��Ҫ�������i�ϣ�������Ϊ0000ʱ�� 
�Լ�д�Ĵ��� 
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
       
        vector<vector<int>> res;
        for(int i=0;i<int(nums.size()-2);i++){
            while(i-1>=0&&i<nums.size()-2&&nums[i]==nums[i-1]) i++;//iȥ���ҷ�ֹԽ��
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
