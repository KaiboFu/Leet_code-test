# include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}

 }node;

class List{
public:
    List();
    ListNode* Creat();
private:
   ListNode* head;

 };



void printList( ListNode* p ){
	while (p){
		cout << p->val << "->";
		p = p->next;
	}
	cout <<endl;
}
ListNode* addNode_front(const int& d, ListNode* head){
    ListNode* p = new ListNode(d);
    p->next = head;
    return p;
}

ListNode* addNode_back(const int& d, ListNode* head){
    ListNode* p = new ListNode(d);
    if (!head){
        head = p;
    }
    else{
        head->next = p;
        head = p;
    }
     return head;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode * pCurrent, * pNext, * pHead = NULL;
    int carry  = 0;

    while(l1 || l2)
    {
        pNext = new ListNode(0);
        if(pHead == NULL)
        {
            pHead = pNext;
        }
        else
        {
            pCurrent->next = pNext;
        }
        pCurrent = pNext;

        int op1 = l1 ? l1->val : 0;
        int op2 = l2 ? l2->val : 0;
        int k = carry  + op1 + op2;

        carry  = k / 10;
        pCurrent->val = k % 10;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(carry  != 0)
    {
        pNext = new ListNode(carry );
        pCurrent->next = pNext;
    }
    return pHead;
}


int main(){
	int a[3] = {2,6,4};
	ListNode l1(0);
	ListNode* head = NULL;
    head = addNode_front(a[0], head);
    head = addNode_front(a[1], head);
    head = addNode_front(a[2], head);
    printList(head);

    ListNode* head1 = NULL, *pcurrent;
    pcurrent = addNode_back(a[0], head1);
    head1 = pcurrent;
    head1 = addNode_back(a[1],head1);
    head1 = addNode_back(a[2],head1);
    printList(pcurrent);
	return 0;

}
