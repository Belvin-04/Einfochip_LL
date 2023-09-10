#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node *next;
};

struct Node* insertFirst(struct Node*,int);
struct Node* insertLast(struct Node*,int);
struct Node* insertAt(struct Node*,int,int);
struct Node* deleteFirst(struct Node*);
struct Node* deleteLast(struct Node*);
struct Node* deleteAt(struct Node*,int);

int getSize(struct Node*);
void printList(struct Node*);
void destroyList(struct Node*);

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    head = insertFirst(head,10);
    head = insertFirst(head,20);
    head = insertFirst(head,30);

    head = insertLast(head,40);

    head = insertAt(head,5,2);

    head = deleteFirst(head);
    

    head = deleteLast(head);
    head = deleteAt(head,1);
    

    printList(head);
    


    destroyList(head);
    return 0;
}

struct Node* insertFirst(struct Node* head,int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
    return head;
}

struct Node* insertLast(struct Node* head,int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        struct Node* first = head;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = temp;
    }
    return head;
}

struct Node* insertAt(struct Node* head,int data,int pos){
    int size = getSize(head);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(pos > size || pos < 0){
        printf("Invalid Position\n");
        return head;
    }
    else if(pos == 0){
        return insertFirst(head,data);
    }
    else if(pos == size){
        return insertLast(head,data);
    }
    else{
        struct Node* first = head;
        while(pos-1 != 0){
            first = first->next;
            pos--;
        }
        temp->next = first->next;
        first->next = temp;
        return head;
    }
    
}

struct Node* deleteFirst(struct Node* head){
    if(head == NULL){
        printf("Empty List");
        return head;
    }
    else{
        struct Node* temp;
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

struct Node* deleteLast(struct Node* head){
    if(head == NULL){
        printf("Empty List");
        return head;
    }
    else{
        struct Node* first = head;

        while(first->next->next != NULL){
            first = first->next;    
        }
        struct Node* temp = first->next;
        first->next = NULL;
        free(temp);

        return head;
    }
}

struct Node* deleteAt(struct Node* head, int pos){
    int size = getSize(head);
    if(pos >= size || pos < 0){
        printf("Invalid Position");
        return head;
    }
    else if(pos == 0){
        return deleteFirst(head);
    }
    else if(pos == (size-1)){
        return deleteLast(head);
    }
    else{
        struct Node* first = head;
        struct Node *temp;
        while(pos - 1 != 0){
            first = first->next;
            pos--;
        }
        temp = first->next;
        first->next = temp->next;
        free(temp);
        return head;
    }
}

int getSize(struct Node* head){
    int cnt = 0;
    struct Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

void printList(struct Node *head){
    if(head == NULL){
        printf("Empty List...\n");
    }
    else{
        struct Node *temp = head;
        while(temp != NULL){
            if(temp->next == NULL){
                printf("%d",temp->data);
            }
            else{
                printf("%d -> ",temp->data);
            }
            temp = temp->next;
        }
    }
}

void destroyList(struct Node *head){
    if(head != NULL){
        struct Node* temp;
        while(head != NULL){
            temp = head;
            head = head->next;
            free(temp);
        }
    }
}