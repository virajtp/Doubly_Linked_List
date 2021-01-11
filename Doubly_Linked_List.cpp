#include<iostream>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};


class LinkedList{
        private:
            Node* start=NULL;
        public:
            void insertBeg(int X);	//Insert a new node at the beginning
            void insertEnd(int x);	//Insert a node at the end
            void deleteBeg();      //Delete a node from the beginning
            void deleteEnd();      //Delete a node from the end
            void deleteItem(int D);     //Delete a node with a given value
            void print();          //Print current list
            Node* search(int F);   //Search an existing element
            int sum();             //Add list values to get sum
    };

    void LinkedList::insertBeg(int x)
    {
		struct Node* newNode;
		newNode = new Node;
		if (start == NULL)
		{
			start = newNode;
			newNode->data = x;
			newNode->next = NULL;
			newNode->prev = NULL;
		}
		else
		{
			newNode->data = x;
			newNode->prev = NULL;
			start->prev = newNode;
			newNode->next = start;
			start = newNode;
		}	
    }

	void LinkedList::insertEnd(int x)
	{
		struct Node* newNode;
		newNode = new Node;
		
		if (start == NULL)
		{
			newNode->data = x;
			newNode->next = NULL;
			newNode->prev = NULL;
			start = newNode;
		}
		else
		{
			struct Node* temp = start;
			newNode->data = x;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			newNode->prev = temp;
			newNode->next = NULL;
			temp->next = newNode;
			return;
		}
	}

	void LinkedList::deleteBeg()
	{
		if (start == NULL)
		{
			return;
		}
		if (start->prev==NULL && start->next==NULL)
		{  
			struct Node* now;
			now = start;
			start = NULL;
			delete now;
			return;
		}
		else
		{
			struct Node* temp;
			temp = start;
			start = start->next;
			start->prev = NULL;
			delete temp;
			return;
		}

	}

	void LinkedList::deleteEnd()
	{
		if (start == NULL)
		{
			cout << "Linked List is empty";
			return;
		}
			struct Node* temp = start;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->prev->next = NULL;
			delete temp;
	}

	void LinkedList::deleteItem(int D)
	{
		struct Node* temp = start;
		if (temp->next == NULL)  
		{
			if (temp->data != D)
			{
				cout << "Item is not exist in the list!" << endl;
				return;
			}
			start = NULL;
			delete temp;
			return;
		}

		while (temp->data != D)
		{
			temp = temp->next;
			if (temp == NULL) 
			{
				cout << "Item is not exist in the list!" << endl;
				return;
			}
		}
		if (temp->next == NULL)
		{
			temp->prev->next = NULL;
			delete temp;
			return;
		}
		if (temp->prev == NULL)
		{
			temp->next->prev = NULL;
			start = temp->next;
			delete temp;
			return;
		}
		else
		{
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			return;
		}

	}
	
	
	void LinkedList::print()
	{
		struct Node* tempNode = start;
		cout << "Linked List ";
		while (tempNode != NULL)
		{
			cout <<" "<< tempNode->data;
			tempNode=tempNode->next;
		}
	}

	int LinkedList::sum()
	{
		int sum=0;
		struct Node* temp = start;
		while (temp!= NULL)
		{
			sum += temp->data;
			temp = temp->next;
		}
		return sum;
	}

	Node* LinkedList::search(int F)
	{
		struct Node* tempNode = start;
		cout << "\t";
		while (tempNode != NULL)
		{
			if (tempNode->data == F)
			{
				return tempNode;
				break;
			}
			tempNode = tempNode->next;
		}
		return NULL;
	}

int main()
{
		//declare variables
		int n=5, choice, nodeValue, newItem, delItem, findItem;
		LinkedList list;
		cout << "Enter Number of Nodes : ";		//user is asked to enter number of nodes
		cin>>n;								//getting the user input

		cout << "Enter List Values : ";
		//creating the linked list
		for (int i = n-1; i >= 0; i--)
		{
			cin >> nodeValue;
			list.insertBeg(nodeValue);
		}
		cout<<"\n\t";
		list.print();		//print initial list
		cout << endl;

		while (1) {
			//print choices
		cout << "\n\t1 - Insert Beginning\n";
		cout << "\t2 - Insert End\n";
		cout << "\t3 - Delete Beginning\n";
		cout << "\t4 - Delete End\n";
		cout << "\t5 - Delete Value\n";
		cout << "\t6 - Print\n";
		cout << "\t7 - Search\n";
		cout << "\t8 - Sum\n";
		cout << "\t0 - Exit\n";
		cout << "\nEnter your choice : ";
		cin >> choice;
		cout << endl ;

		switch (choice)		//selecting choices
		{
		case 1: {
			cout << "Enter New Item : ";
			cin >> newItem;
			list.insertBeg(newItem);
			cout << "\n\tUpdated ";
			list.print();
			break;
		}
		case 2: {
			cout << "Enter New Item : ";
			cin >> newItem;
			list.insertEnd(newItem);
			cout << "\n\tUpdated ";
			list.print();
			break;
		}
		case 3: {
			list.deleteBeg();
			cout << "\n\tUpdated ";
			list.print();
			break;
		}
		case 4: {
			list.deleteEnd();
			cout << "\n\tUpdated ";
			list.print();
			break;
		}
		case 5: {
			cout << "Enter Item for Delete : ";
			cin >> delItem;
			list.deleteItem(delItem);
			cout << "\n\tUpdated ";
			list.print();
			break;
		}
		case 6: {
			list.print();
			break;
		}
		case 7: {
			cout << "Enter Item for Search : ";
			cin >> findItem;
			struct Node* ans = list.search(findItem);
			if (ans != NULL)
			{
				cout << "Found " << ans->data << endl;
				cout << "\tValue address : " << ans; 
			}
			else cout << "Not Found" << endl;
			break;
		}
		case 8: {
			cout << "\n\tSum of Values = " << list.sum();
			break;
		}
		case 0: {
			return 0;
		}
		}
		cout << endl << endl;
	}
		system("pause");
	
}
