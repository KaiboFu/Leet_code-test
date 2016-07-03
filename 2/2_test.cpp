# include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}

 }node;

class List{
public:
    List():head(NULL) {};
    ListNode* addNode_back(const int&d);
    void printList();
    void printList(List& L);
    void printList(ListNode* p);
    ListNode* Insert(const int pos, const int e);
private:
   ListNode* head;
 };
 # add testting
ListNode* List::addNode_back(const int& d){
    ListNode* p = new ListNode(d);
    if (!head){
        head = p;
    }
    else{
        ListNode* q = head;
        ListNode* q1 = head->next;
        while(q1){
            q = q->next;
            q1 = q->next;
        }
        q->next = p;
    }
     return head;
}

void List::printList(){
    ListNode* p = head;
	while (p->next){
		cout << p->val << "->";
		p = p->next;
	}
	cout<<p->val;
	cout <<endl;
}
void List::printList(List& L){
    ListNode* p = L.head;
	while (p->next){
		cout << p->val << "->";
		p = p->next;
	}
	cout<<p->val;
	cout <<endl;
}
void List::printList(ListNode* p){
	while (p->next){
		cout << p->val << "->";
		p = p->next;
	}
	cout<<p->val;
	cout <<endl;
}

ListNode* List::Insert(const int pos, const int e){
    if(pos == 1){
        ListNode* p = new ListNode(e);
        p->next = head;
        head = p;
        return head;
    }
    else{
        int i = 1;
        ListNode* ele = new ListNode(e);
        ListNode* p = head;
        for(; i < pos - 1 && (p->next); i++ ){
             p = p->next;
        }
        ListNode* temp = p->next;
        p->next = ele;
        ele->next = temp;
        return head;
    }
}

void printList( ListNode* p ){
	while (p->next){
		cout << p->val << "->";
		p = p->next;
	}
	cout << p->val;
	cout << endl;
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
        ListNode* q = head;
        ListNode* q1 = head->next;
        while(q1){
            q = q->next;
            q1 = q->next;
        }
        q->next = p;
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

	List L2;
	ListNode* head2 = NULL;
	head2 = addNode_back(a[0], head2);
	//printList(head1);
	head2 = addNode_back(a[1], head2);
	L2.Insert(1,a[2]);
	L2.printList();
	L2.addNode_back(a[0]);
	L2.addNode_back(a[1]);
	L2.Insert(1,9);
	L2.printList();
    L2.Insert(3,5);
	L2.printList();
	cout<<"------------"<<endl;
	L2.printList(L2);
	L2.printList(L2.head);
	return 0;

}
