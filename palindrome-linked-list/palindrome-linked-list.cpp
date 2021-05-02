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
bool isPalindrome(ListNode* head) {
    ListNode* fastIndex = head;
    ListNode* slowIndex = head;
    ListNode* prevIndex = nullptr;
    while(fastIndex && fastIndex->next){
        prevIndex = slowIndex;
        slowIndex = slowIndex->next;
        fastIndex = fastIndex->next->next;
    }
    // at this time slowIndex will be in the middle of the linked list
    // let's reverse the half end of the linked list
    ListNode* currNode = slowIndex;
    ListNode* prevNode = nullptr;
    ListNode* nextNode = nullptr;
    while(currNode != nullptr){
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    // reverse node
    while(head != slowIndex){
        if(head->val != prevNode->val) return false;
        head = head->next;
        prevNode = prevNode->next;
    }
    return true;
}
};