/*
��������?�ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ���?����?�ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢?һλ?���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0?��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-two-numbers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 
/*
�Ƚ����׵�����ӷ��� 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur=head;
        int carry=0;
        while(l1!=NULL||l2!=NULL){
            int a1=(NULL==l1?0:l1->val);
            int a2=(NULL==l2?0:l2->val);
            int sum=a1 + a2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            cur->next=new ListNode(sum);

            cur=cur->next;
            if(l1!=NULL) l1=l1->next;//ע���ж������ 
            if(l2!=NULL) l2=l2->next;

        }
        if(1==carry){
            cur->next=new ListNode(1);
        }
        return head->next;
    }
};
