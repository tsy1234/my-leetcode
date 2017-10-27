#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode* tail = head;
        int num = 1;
        while (tail->next) {
            tail = tail->next;
            num++;
        }
        k %= num;
        int start = num - k - 1;
        ListNode* newTail = head;
        while (start > 0) {
            newTail = newTail->next;
            start--;
        }
        ListNode* res = newTail->next;
        newTail->next = tail->next;
        tail->next = head;
        return res;
    }
};

int main() {
}