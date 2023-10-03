#include <stdio.h>
#include <stdlib.h>

//Reverse the linked list
struct node_t{

    int data;
    struct node_t* next;
};

typedef struct node_t node;

void printLL(node* head);
node* createNodeLL(int data);
node* addNodeToHead(node* head, node* newNode);
node* findNodeContaining(node* head, int data);
void deleteNodeFromPosition(node* head, int position);
node* deleteHead(node* head);
node* deleteNodeWithData(node* head, int data);
node* reverseLL(node* head);

int main(){

    node* tmp; // pointer to a temporary object
    node* head;//pointer to the first node

    head = NULL;

    for(int i=0; i<15; i++){

        tmp = createNodeLL(1 + i);
        head = addNodeToHead(head , tmp);
    }


    printf("\n");
    printLL(head);

    head = reverseLL(head);

    printf("\n");
    printLL(head);

    return 0;
}

void printLL(node* head){
    node* tmp = head;
    while(tmp != NULL){
        printf("\nNode a Addr: 0x%x, Data: %d, Next addr: 0x%x", tmp, tmp->data, tmp->next);
        tmp = tmp->next;

    }
}

node* createNodeLL(int data){

    node* nn;
    nn = (node*) malloc(sizeof(node));// create new node
    nn ->data = data;//populating node using the pointer
    nn->next = NULL;

    return nn;

}

node* addNodeToHead(node* head, node* newNode){

    newNode->next = head;
    return newNode;

}

node* findNodeContaining(node* head, int data){

    node* tmp = head;
    while(tmp != NULL){
        if(tmp->data == data){
            return tmp;
        }
        tmp = tmp->next; //move tmp to next node

    }
    return NULL;
}

void insertNodeInPosition(node* head, int position, int data){

    node* tmp = head;
    node* newNode;

    if(position == 0){

        printf("\nCannot insert in position 0");
    }
    else{
        for(int i=1; i<position; i++){
            if(tmp->next != NULL){
            tmp = tmp->next;//traverse the list position times
            }else{
                printf("\nYou are out of bounds, fail position!");
                return;
            }
        }
    }
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;

    //point new node to the next node
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void deleteNodeFromPosition(node* head, int position){//nth position from head, index starts at 0.

    node* tmp = head;
    node* nodeToDelete;

    if(position == 0){
        printf("\nCannot delete at position 0");
    }
    else if(position == 1){
        nodeToDelete = tmp->next;//point to the node that needs to be deleted
        tmp->next = nodeToDelete->next;
        free(nodeToDelete);
        return;
    }
    for(int i=1; i<position; i++){
        tmp = tmp->next;

        if(tmp->next != NULL){
            nodeToDelete = tmp->next;

            if(i == (position-1)){
                tmp->next = nodeToDelete->next;
                free(nodeToDelete);
            }
        }
            else{
                printf("\nCannot delete something beyond the end of the list");
                return;
            }
    }
}

node* deleteHead(node* head){
    node* tmp = head;
    node* nodeToDelete;

    head = head->next;//point head to the second point.
    //tmp still points to the original head
    free(tmp);
    return head;
}

node* deleteNodeWithData(node* head, int data){

    node* tmp = head;
    int indexCount = 0;

    while(tmp != NULL){

        if(tmp->data == data){
            break;
        }
        tmp = tmp->next;
        indexCount++;
    }
    if(indexCount == 0){
        head = deleteHead(head);
        return head;
    }
    else{
        deleteNodeFromPosition(head, indexCount);
        return head;
    }

}

node* reverseLL(node* head){

    node* previous;
    node* current;
    node* next;

    current = head;
    previous = NULL;

    while(current != NULL){

        //change connects
        next = current->next; //moved next.
        current->next = previous; //connect current node to the previous

        //move pointer to the next elements
        previous = current;
        current = next;
    }
    head = previous;
    return head;
}