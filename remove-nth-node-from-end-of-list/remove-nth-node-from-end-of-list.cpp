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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // adding dummy node at the head
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        // length of the linked list
        int listLength = 0;
        ListNode* iterator = head;
        while(iterator != nullptr){
            listLength++;
            iterator = iterator->next;
        }
        // pointing iterator to dummy
        iterator = dummy;
        listLength -= n;
        while(listLength > 0){
            listLength--;
            iterator = iterator->next;
        }
        iterator->next = iterator->next->next;
        return dummy->next;
    }
};