#include <iostream>
#include <string>

using namespace std;

class Node {

public:

	int value;
	Node* next;

	Node(int value, Node* node) {
	    this -> value = value;
	    this -> next = node;
	}
	Node(){

	}
};

class LinkedList {

private:

	Node* head, * tail;

public:
	LinkedList() {

		head = tail = NULL;

	}

	void AddtoHead(int val);
	void AddtoTail(int val);
	void AddatLocation(int location, int val);
	void DeleteNode(int val);
	void Display();
	int CountList();

};

void LinkedList::AddtoHead(int val) {

	Node* newNode = new Node;
    newNode->value = val;
    newNode->next = NULL;

		if (!head) {

			head = newNode;
		}

		else {

			newNode->next = head;
			head = newNode;

		}

}

void LinkedList::AddtoTail(int val){


    Node*newNode=new Node;
    newNode->value=val;
    newNode->next=NULL;


    tail=head;

    if(tail == NULL)
       tail=newNode;
    else
    {
        while(tail->next!=NULL)
            tail=tail->next;

        tail->next=newNode;
}
}

void LinkedList::AddatLocation(int location, int val){

    Node* nodeptr = head,*previous;
    int temp=0;
    if (head!=0){
        while(nodeptr->next!=0 && temp!=location){
            previous = nodeptr;
            nodeptr = nodeptr->next;
            temp++;
        }
        if (location == temp+1){
            LinkedList::AddtoTail(val);}
        else if (location > temp+1){
            cout<<"Out of bounds"<<endl;
        }
        else{
            nodeptr=new Node(val,nodeptr);
            previous->next = nodeptr;

        }
        }
    else{
        cout<<"Inserting a head due to empty list."<<endl;
        LinkedList::AddtoHead(val);
    }
    }

void LinkedList::DeleteNode(int val) {

	Node* nodeptr, * previous;

	if (!head) {
		return;
	}

	if (head->value == val) {

		nodeptr = head->next;
		delete head;
		head = nodeptr;
	}

	else {

		nodeptr = head;

		while ((nodeptr != NULL) && (nodeptr->value != val)) {

			previous = nodeptr;
			nodeptr = nodeptr->next;
		}

		previous->next = nodeptr->next;
		delete nodeptr;

	}

}

void LinkedList::Display() {

Node* nodeptr;
nodeptr = head;
while (nodeptr){
cout << nodeptr->value << endl;
nodeptr = nodeptr->next;
}
}

int LinkedList::CountList() {

	int temp = 0;

	Node* nodeptr;
	nodeptr = head;

	while (nodeptr) {

		nodeptr = nodeptr->next;
		temp++;
	}

	return temp;

}

int main()
{
	LinkedList l;

	while (1)
	{
		char a = NULL; //drawing menu
		cout << " Select from one of the following\n A.Create a node or Insert at HEAD \n B.Display Linked list entries \n C.Insert at location \n D.Delete from location" << endl;
		cin >> a;
		switch (a) {
		case 'A':
			cout << "\nInsert any value to Create a node\n" << endl;
			int a1;
			cin >> a1;
			l.AddtoHead(a1);
			break;
		case 'B':
			cout << "\nDisplay Linked list entries\n" << endl;
			l.Display();
			break;
		case 'C':

			cout << "\nChoose which location to enter the value\n" << endl;
			cout << "\n" << endl;
			int b1, b2;
			cin >> b1;
			cout << "\nChoose the value to be entered\n" << endl;
			cin >> b2;
			cout << "\n\n" << endl;
			l.AddatLocation(b1, b2);

			break;
		case 'D':
			cout << "Delete from entry location" << endl;
			int d1;
			cin >> d1;
			l.DeleteNode(d1);
			break;
		default:
			cout << "Invalid choice" << endl;
		}

}	}

