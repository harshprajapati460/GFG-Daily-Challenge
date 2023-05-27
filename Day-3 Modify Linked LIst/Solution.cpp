#include<bits/stdc++.h>
using namespace std;
// Link -> https://practice.geeksforgeeks.org/problems/modify-linked-list-1-0546/1
// Given a singly linked list containing N nodes. Modify the Linked list as follows:

// 1. Modify the value of the first half nodes such that 1st node's new value is equal 
// to the value of the last node minus the first node's current value, 2nd node's new value 
// is equal to the second last nodes value minus 2nd nodes current value, likewise for first half nodes.
// 2. Replace the second half of nodes with the initial values of the first half 
// nodes(values before modifying the nodes).
// 3. If N is odd then the value of the middle node remains unchanged.
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
//Method 1 :
// 1. MAKE A COPY OF THE LIST
// 2. REV THAT LINKED LIST
// 3. FIND MIDDLE FOR ONE OF THE LINKED LIST BY SLOW AND FAST METHOD
// 4. INTERATE FROM HEAD OF BOTH THE LL UPTO THE MIDDLE 
// 5. CHANGE THE VALUES OF CURR2->DATA = CURR2->DATA - CURR1->DATA
// 6. RETURN THE SECOND LIST AS ANSWER
// TIME COMPLEXIT O(N) AND SPACE COMPLEXITY IS O(N) SIZE OF LINKED LIST
  
struct Node * NewList(struct Node *head){
        struct Node *temp = head;
        struct Node *newhead = new Node(head->data);
        struct Node *curr = newhead;
        temp = temp->next;
        while(temp != nullptr){
            Node *n = new Node(temp->data);
            curr->next = n;
            curr = curr->next;
            temp = temp->next;
        }
        return newhead;
        
}
struct Node * Reverse(struct Node *head){
        struct Node *curr = head,*prev = nullptr,*Next = nullptr;
        while(curr != nullptr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
}
struct Node *Find_Middle(struct Node *head){
        struct Node *slow = head,*fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
}

struct Node* modifyTheList_1(struct Node *head)
    {  
       struct Node *newlist = NewList(head);
       newlist = Reverse(newlist);
       struct Node *curr1 = newlist,*curr2 = head;
       struct Node *middle = Find_Middle(newlist);
       while(curr1 != middle){
           curr1->data = curr1->data - curr2->data;
           curr1 = curr1->next;
           curr2 = curr2->next;
       }
       return newlist;
}
// METHOD 2 - OPTIMIZED:
// 1. FIND MIDDLE OF LINKED LIST BY SLOW AND FAST METHOD (CHANGE FAST = HEAD->NEXT FOR NOT LOSING THE MIDDLE WHEN PASSING)
// 2. REVERSE THE  LL FROM NEXT OF MIDDLE AND MAR MIDDLE->NEXT = NULL
// 3. ITERATE TO HEAD OF BOTH LL AND CHANGE THEIR VALUES ACCORDINGLY
// 4. AFTER CHANGING VALUES REV THE REV LIST AND JOIN IT i.e MIDDLE->NEXT = REV
// 5. RETURN THE LIST
// TIME COMPLEXITY O(N) SPACE COMPLEXITY O(1) WE ARE NOT USING ANOTHER LINKED LIST HERE

struct Node* modifyTheList_2(struct Node *head)
    {
         struct Node *middle = Find_Middle(head);
         struct Node *rev = Reverse(middle->next);
         middle->next = nullptr;
         struct Node *curr1 = rev,*curr2 = head;
         while(curr1 != nullptr){
             int a = curr1->data,b = curr2->data;
             curr2->data = a - b;
             curr1->data = b;
             curr1 = curr1->next;
             curr2 = curr2->next;
         }
         rev = Reverse(rev);
         middle->next = rev;
         return head;
    }
void printlist(struct Node *l){
    struct Node *curr = l;
    while(curr != nullptr){
         cout<<curr->data<<" ";
         curr = curr->next;
    }
    cout<<endl;
}
int main(){
//linked list = 10 -> 4 -> 5 -> 3 -> 6  // Odd size
struct Node *head = new Node(10);
head->next = new Node(4);
head->next->next = new Node(5); 
head->next->next->next = new Node(3);
head->next->next->next->next = new Node(6);

printlist(head);
printlist(modifyTheList_2(head));

//linked list = 11 -> 12 -> 13 -> 14 -> 15 -> 16 -> 17 -> 18 // Even size
struct Node *newhead = new Node(11);
newhead->next = new Node(12);
newhead->next->next = new Node(13);
newhead->next->next->next = new Node(14);
newhead->next->next->next->next = new Node(15);
newhead->next->next->next->next->next = new Node(16);
newhead->next->next->next->next->next->next = new Node(17);
newhead->next->next->next->next->next->next->next = new Node(18);

printlist(newhead);
printlist(modifyTheList_2(newhead));

return 0;
}