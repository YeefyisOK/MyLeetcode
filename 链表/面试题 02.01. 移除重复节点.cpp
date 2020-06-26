/*
��д���룬�Ƴ�δ���������е��ظ��ڵ㡣�����ʼ���ֵĽڵ㡣

ʾ��1:

 ���룺[1, 2, 3, 3, 2, 1]
 �����[1, 2, 3]
ʾ��2:

 ���룺[1, 1, 1, 1, 2]
 �����[1, 2]
��ʾ��

��������[0, 20000]��Χ�ڡ�
����Ԫ����[0, 20000]��Χ�ڡ�
���ף�

�������ʹ����ʱ������������ô�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicate-node-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 
/*
˼·�򵥣��ù�ϣ��unordered_set�����������Ҫ��ϰ������û�ҵ�Ԫ�ط���end 

������ʱ�������Ļ�ֻ��ʱ�任�ռ� 
 
*/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> hash;
        ListNode* res=new ListNode(0);
        ListNode* cur=res;
        while(head!=NULL){
            int temp=head->val;
            if(hash.find(temp)==hash.end()){ 
                cur->next=new ListNode(temp);
                cur=cur->next;
                hash.insert(temp);
            }
            head = head->next;
        }
        return res->next;
    }
};
