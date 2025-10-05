//COMSC 210 | Lab 19| Toma Dimov
//TODO
//read review comments from external file
//movie class w/ private members: title, linked list of structs containing ratings and reviews.
//main() container of movie objects. can be array ,vector, linked list.
//Nodes can be added to head for ease
//write a driver/demo program that will have at least 4 movie objs with at least 3 reviews.

#include <iostream>
using namespace std;

//global variable
bool addToHeadMode = true;

struct Node{
    float rating;
    string comment;
    Node* next;
//constructors
    Node(){}
    Node(float rating,string comment){this->rating=rating;this->comment=comment;next=nullptr;}
};
//prototype functions
void promptMode();
Node * promptData();
void output(Node*);


int main(){
    promptMode();
    Node * head = promptData();
    output(head);
    return 0;
}

//prompts user on which mode to use: Append to head or append to tail
void promptMode(){
    int entry;
    cout<<"Which linked list method should we use?"<<endl;
    cout<<"\t[1] New nodes are added at the head of the linked list.\n";
    cout<<"\t[2] New nodes are added at the tail of the linked list.\n";
    cout<<"Choice:\t";
    cin>>entry;
    while(entry!=1 && entry!=2){
        cout<<"Invalid choice. Enter 1 or 2: ";
        cin>>entry;
    }
    if(entry==1)
        addToHeadMode=true;
    else
        addToHeadMode=false;
}
//prompts user to enter ratings / comments
Node * promptData(){
    float rating;
    string comment;
    char yesno;
    Node* head = nullptr;
    Node* nodePtr=head;
    while(true){
        cout<<"Enter review rating 0-5: ";
        cin>> rating;
        if(rating<0)
            rating=0;
        if(rating>5)
            rating=5;
        cout<<"Enter review comments: ";
        cin.ignore();
        getline(cin, comment);
//check mode here:
        Node * N = new Node(rating,comment);
        if(!head){
            head=N;
            N->next=nullptr;
            nodePtr=N;
        }
        else if(addToHeadMode){
            N->next = head;
            head=N;
        }
        else{
            nodePtr->next = N;
            nodePtr=nodePtr->next;
        }
        cout<<"Enter another review? Y/N: ";
        cin>>yesno;
        if(tolower(yesno) == 'y')
            continue;    
        return head;
    }
}
//Outputs data in order and outputs the average of ratings.
void output(Node* head){
    if(!head){
        cout<<"List is empty.\n";
        return;
    }
    cout<<"Outputting all reviews: \n";
    int count = 1;
    float sum = 0;
    Node *nodePtr = head;
    while(nodePtr){
        cout<<"Review #"<<count<<": "<<nodePtr->rating<<" :   \""<<nodePtr->comment<<"\"\n";
        sum+=nodePtr->rating;
        nodePtr=nodePtr->next;
        count++;
    }
    cout<<"Average: "<<  sum/(count-1); 
    cout<<endl;
}