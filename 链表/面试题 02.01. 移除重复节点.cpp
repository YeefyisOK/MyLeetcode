/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：

如果不得使用临时缓冲区，该怎么解决？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 
/*
思路简单，用哈希表，unordered_set和链表操作需要复习，比如没找到元素返回end 

不用临时缓冲区的话只能时间换空间 
 
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
