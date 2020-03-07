/*
 * For singly linked list
 * */
typedef struct mk{
    int value;
    struct  mk *next;
}roy;
void divide(roy *source,roy **front, roy **back){
    roy *fast;
    roy *slow;
    slow = source;
    fast = source->next;
    while (fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next=NULL;
}
roy* mergeSorted(roy* first, roy* second){
    roy* result = NULL;
    if (first==NULL) return second;
    if(second==NULL) return first;
    if(first->value <= second->value){
        result = first;
        result->next = mergeSorted(first->next,second);
    }
    else {
        result = second;
        result->next = mergeSorted(first,second->next);
    }
    return result;
}
void mergeSortForLinkedList(roy **headRef){
    roy *head = *headRef;
    roy *left;
    roy *right;
    if(head==NULL || head->next==NULL) return;
    divide(head,&left,&right);
    mergeSortForLinkedList(&left);
    mergeSortForLinkedList(&right);
    *headRef = mergeSorted(left,right);
}
