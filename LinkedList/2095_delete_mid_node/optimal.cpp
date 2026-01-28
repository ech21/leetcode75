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
    ListNode* deleteMiddle(ListNode* head) {

        
        ListNode* current = head;
        int length = 1;
        while(current->next != nullptr){
            current = current->next;
            length++;
        }
        if(length == 1){return nullptr;}
        int middle = length / 2;
        int count = 0;
        current = head;
        while(count < middle - 1){
            current = current->next;
            count++;
        }
        ListNode* target = current->next;
        current->next = target->next;
        
        return head;
    }
};
/*
Start by counting the length of the linked list. If it's 1, return nullptr.
Otherwise, find the middle index by length / 2, forcing truncation by making it an integer.
Then traverse to the node right before the middle node, and set its next pointer to skip
the target middle node. Return head.

Note that count starts at 0 because the problem states that the middle index is 0-indexed, but
the length of course starts at 1.

The reason we need to do middle - 1 is because the ith loop gets us to index i + 1.
For example, when count = 0; we're at index 1 after the first loop.

Time complexity: O(n) where n is the length of the linked list.
Space complexity: O(1) because we're only using a few extra pointers and integers.




Below is a cool, alternate solution.
Basically, fast moves at 2x speed, and slow moves at regular speed. 
It stands to reason that when fast reaches the end, slow is at the middle.
It works for both odd and even lengths because when even, fast will be nullptr, and when odd, fast->next will be nullptr.
It hurts my head to think about it, but it works! 

*/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = slow->next;  // Remove middle node
        delete slow;  // Free memory

        return head;
    }
};