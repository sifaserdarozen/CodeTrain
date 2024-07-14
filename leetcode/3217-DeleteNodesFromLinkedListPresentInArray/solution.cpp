// Compute Complexity O(N)
// Space Complexity O(N)

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numMap;
        for (const auto& n : nums) {
            numMap.insert(n);
        }

        ListNode* modHead = nullptr;
        ListNode* backPtr = nullptr;

        for (auto tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (numMap.end() != numMap.find(tmp->val)) {
                continue;
            }

            if (backPtr != nullptr) {
                backPtr->next = new ListNode(tmp->val);
                backPtr = backPtr->next;
            } else {
                backPtr = new ListNode(tmp->val);
                modHead = backPtr;
            }
        }

        return modHead;
    }
};