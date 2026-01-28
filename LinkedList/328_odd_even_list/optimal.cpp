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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        if(!head->next->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even && even->next){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
            
        }
        odd->next = evenHead;
        return head;
        
    }
};

/*
Explanation:
First, check for 0, 1, or 2 nodes. You can return them normally.

Then, create three pointers: odd, even, and evenHead.
Odd starts at head, even starts at head->next, and evenHead stores the start of the even.
Even is the "iterator" for the entire node list.
Basically, we skip every other node, landing on even nodes only. 
This is how we connect the odd node to the next odd node.
We also connect the even node to the next even node, which is one further than the odd node.
Then, we move both of them to their next respective nodes.
But at all times, the even node is "ahead". This is why we check for even and even->next in the while loop.
When even or even->next is nullptr, we stop.

Finally, we connect the last odd node to the head of the even nodes, which we stored in evenHead.


Time complexity: O(n) where n is the length of the linked list.
Space complexity: O(1) because we're only using a few extra pointers.





*/