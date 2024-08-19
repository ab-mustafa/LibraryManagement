
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <BookLib.h>

int main() {


    addBook(1, "Code Complete","Steve McConnell",2004);
    addBook(2, "Clean Code","Robert C. Martin",2012);
    addBook(3, "Refactoring","Paul Becker",1999);
    addBook(4, "Machine Learning Yearning","Andrew Ng",2016);
    addBook(5, "Artificial Intelligence","Melanie Mitchell",2023);
    addBook(6, "Between the World and Me","Ta-Nehisi Coates",2015);
    listBooks();
    
    struct Book* book1=searchBook("Clean Code12");
    if(book1==NULL)
        printf("Book not Exisit in the list \n");
    else
        printf("Book ID:%id\n", book1->id);
    
    
    printf("Remove Book at the start of the ledger Id=1\n");
    removeBook(1);
    listBooks();
    
    
    printf("Remove Book at the end of the ledger Id=6\n");
    removeBook(6);
    listBooks();
    
    printf("Remove Book at the middle of the ledger Id=2\n");
    removeBook(3);
    listBooks();
    
    return 0;
}
