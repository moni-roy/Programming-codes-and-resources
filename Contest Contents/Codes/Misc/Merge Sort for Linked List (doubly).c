/*
 * Merge sort for Doubly Linked List
 * */
typedef struct mk{
    int value;
  struct  mk *next, *prev;
}roy;
void divide(roy *source, roy **back){
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
    *back = slow->next;
    slow->next=NULL;
}
roy* mergeSorted(roy* first, roy* second){
    if (first==NULL) return second;
    if(second==NULL) return first;
    if(first->value <= second->value){
        first->next = mergeSorted(first->next,second);
        first->next->prev=first;
        first->prev=NULL;
        return first;
    }
    else {
        second->next = mergeSorted(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
void mergeSortForLinkedList(roy **headRef){
    roy *head = *headRef;
    roy *right;
    if(head==NULL || head->next==NULL) return;
    divide(head,&right);
    mergeSortForLinkedList(&head);
    mergeSortForLinkedList(&right);
    *headRef = mergeSorted(head,right);
}

