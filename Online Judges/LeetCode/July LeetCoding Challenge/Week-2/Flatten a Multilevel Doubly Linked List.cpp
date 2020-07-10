/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *root = head;
        while (root)
        {
            if (root->child)
            {
                Node *next = root->next;
                root->next = root->child;
                root->next->prev = root;
                root->child = NULL;
                Node *childNext = root->next;
                while (childNext->next)
                    childNext = childNext->next;
                childNext->next = next;
                if (next)
                    next->prev = childNext;
            }
            root = root->next;
        }
        return head;
    }
};