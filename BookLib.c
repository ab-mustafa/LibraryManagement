
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



struct Book{
    int id;
    char title[51];
    char author[51];
    int publicationYear;
    struct Book* next;
};

struct Book* ledger = NULL;


void addBook(int id, char* title, char* author, int year){
    // Create Book Struct
    struct Book *newBook=(struct Book*)malloc(sizeof(struct Book));
    newBook->id=id;
    newBook->publicationYear=year;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    
    // Check if ledger is Null
    if(ledger==NULL){
        ledger=newBook;        
        return;
    }
    // If ledger contain books, then we should 
    // access the lase element in the ledger
    struct Book *ptr=ledger;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newBook;
    return;
}


void listBooks(){
    if(ledger==NULL){
        printf("The Ledger is Empty");
        return;
    }
    
    struct Book* ptr = ledger;
    while(ptr!=NULL){
        printf("Id:%d Title:%s Author:%s Publication Year:%d \n", ptr->id,ptr->title,ptr->author,ptr->publicationYear);
        ptr=ptr->next;
    }
}

struct Book* searchBook(char* title){
    if(ledger==NULL) return NULL;
    struct Book* ptr= ledger;
    while(ptr!=NULL){
        
        if(strcasecmp(ptr->title, title) == 0){
            return ptr;    
        }
        ptr=ptr->next;
    }
    return NULL;
}


void removeBook(int id){
    if (ledger==NULL) return;
    if (id==ledger->id){
        struct Book *ptr = ledger;
        ledger=ledger->next;
        free(ptr);
        ptr=NULL;
        return;
    }
    struct Book *ptr1 = ledger;
    struct Book *ptr2 = ledger->next;
    while(ptr2!=NULL){
        if(ptr2->id==id){
            ptr1->next=ptr2->next;
            free(ptr2);
            return;
        }
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }
    return;
    
}

