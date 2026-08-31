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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = 0, i = 0, last = -1, mini = 123456, maxi = 0, d = 123456;
        for (ListNode* t = head; t->next; t = t->next, ++i) {
            if (i && ((prev < t->val && t->next->val < t->val) || (prev > t->val && t->next->val > t->val))) {
                maxi = max(maxi, i);
                mini = min(mini, i);
                if (last >= 0) {
                    d = min(d, i - last);
                }
                last = i;
            }
            prev = t->val;
        }
        return d < 123456 ? vector<int>({d, maxi - mini}) : vector<int>({-1, -1});
        
    }
};