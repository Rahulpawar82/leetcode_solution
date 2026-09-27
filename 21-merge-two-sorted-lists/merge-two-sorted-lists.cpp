ListNode* solve(ListNode* list1, ListNode* list2)
{
    // Make sure list1 starts with the smaller value
    if (list1->val > list2->val)
    {
        swap(list1, list2);
    }

    ListNode* curr1 = list1;
    ListNode* next1 = curr1->next;

    ListNode* curr2 = list2;
    ListNode* next2 = curr2->next;

    while (curr2 != NULL)
    {
        // Insert curr2 between curr1 and next1
        if (next1 == NULL || curr2->val <= next1->val)
        {
            curr1->next = curr2;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;

            if (curr2 != NULL)
                next2 = curr2->next;
        }
        else
        {
            // Move in list1
            curr1 = next1;
            next1 = next1->next;
        }
    }

    return list1;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        return solve(list1, list2);
    }
};