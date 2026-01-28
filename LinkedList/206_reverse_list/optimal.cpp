/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;
        while(head){
            ListNode* temp = head->next;
            head->next = node;
            node = head;
            head = temp;
        }
        return node;
        
    }
};



/*
Three pointers: node, head, and temp.
Node is the "left" side of the regular list, 
Head is the "middle" of the regular list,
temp is the "right" side of the regular list.

temp store head->next to iterate,
head then points to node to reverse the link,
then node moves to head and head moves to temp.

Time complexity: O(n) where n is the length of the linked list.
Space complexity: O(1) because we're only using a few extra pointers.

Below is a recursive solution, requested by leetcode.

Explanation: 
Recursively find the end of the list, the new head.
After we reach the base case and start returning, we reverse the list:
head->next->next = head flips the link, 
and head->next = nullptr severs the old link.
Realize that newHead will return the head of the reversed list all the way.


*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;        
    }
};