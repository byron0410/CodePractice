/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *fast =head, *slow=head;
        ListNode *middle = findMiddle(fast, slow);
        return mergeList(sortList(head), sortList(middle));
    }
    
private:
    ListNode* findMiddle(ListNode *fast, ListNode *slow)
    {
        ListNode *cut = fast;
        while (fast && fast->next)
        {
            cut = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        cut->next = nullptr;
        return slow;
    }

    ListNode* mergeList(ListNode *listLeft, ListNode *listRight)
    {
        ListNode *ahead = new ListNode(0);
        ListNode *pos = ahead;
        while (listLeft && listRight)
        {
            if (listLeft->val < listRight->val)
            {
                pos->next = listLeft;
                listLeft = listLeft->next;
            }
            else
            {
                pos->next = listRight;
                listRight = listRight->next;
            }
            pos = pos->next;
        }
        if (listLeft == nullptr)
            pos->next = listRight;
        else
            pos->next = listLeft;
        return ahead->next;
    }
};