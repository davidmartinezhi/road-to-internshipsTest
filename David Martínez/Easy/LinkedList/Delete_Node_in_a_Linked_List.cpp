
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr){
            return;
        }
        
        ListNode * aux = node->next;
        if(aux != nullptr){
            node->val = aux->val;
            node->next = aux->next;
            delete aux;
        }
        else{
            delete node;
        }
        
    }
};

/*
Nota:
    -Solución optima con O(1) memoria y O(1) tiempo
    -Muy util para problemas sobre linked lists, que me he topado luego
*/