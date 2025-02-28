#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

//Write List::remove() here

void List::remove(int idx) {
    // Handle empty list case
    if (root == NULL) return;
    
    Node *toDelete = NULL;
    
    // Case: removing the first node (root)
    if (idx == 0) {
        toDelete = root;
        root = root->next;
        delete toDelete;
        size--;
        return;
    }
    
    // Case: removing a node somewhere in the list
    Node *current = root;
    
    // Navigate to the node just before the one we want to delete
    for (int i = 0; i < idx - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    // If we reached the end or the list is shorter than expected
    if (current == NULL || current->next == NULL) return;
    
    // Set up the deletion
    toDelete = current->next;          // Node to be deleted
    current->next = toDelete->next;    // Connect the list around the removed node
    
    // Perform the deletion (this will trigger the destructor)
    delete toDelete;
    size--;
}
