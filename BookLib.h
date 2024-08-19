#ifndef BookLib_H
#define BookLib_H

struct Book{
    int id;
    char title[51];
    char author[51];
    int publicationYear;
    struct Book* next;
};

void addBook(int id, char* title, char* author, int year);
void removeBook(int id);
void listBooks();
struct Book* searchBook(char* title);

#endif
