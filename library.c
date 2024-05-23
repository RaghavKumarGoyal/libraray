#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 100
#define MAX_GENRES 15

struct Book {
    int ISBN;
    char Title[100];
    char Author[100];
    float Price;
    char Genres[2][50];
    int NumGenres;
};
struct Book library_db[MAX_BOOKS]; 
int book_count = 0;


const char* genres_list[MAX_GENRES] = {
    "Mystery", "Thriller", "Romance", "Fantasy", "Science Fiction",
    "Horror", "Historical Fiction", "Biography", "Memoir", "Self-Help",
    "Cookbook", "Travel", "Science", "Business", "Art"
};


int isbn_unique(int isbn) {
    for (int i = 0; i < book_count; i++) {
        if (library_db[i].ISBN == isbn) {
            return 0; 
        }}
    return 1; 
}


void add_genre(struct Book* book, int genre_index) {
    if (book->NumGenres >= 2) { 
        printf("Maximum number of genres reached for this book.\n");
        return;
    }
    strcpy(book->Genres[book->NumGenres], genres_list[genre_index]);
    book->NumGenres++;
}

void new_book() {
    printf("\nEnter the number of books you want to add: ");
    int num_books;
    scanf("%d", &num_books);

    for (int n = 0; n < num_books; n++) {
        printf("\nEnter ISBN for Book %d: ", n + 1);
        int isbn;
        scanf("%d", &isbn);

        if (!isbn_unique(isbn)) {
            printf("\nA book with this ISBN already exists. Please enter a new ISBN.\n");
            n--; 
            continue;
        }

        struct Book newBook;
        newBook.ISBN = isbn;

        printf("Enter Title for Book %d: ", n + 1);
        scanf(" %[^\n]s", newBook.Title);

        printf("Enter Author Name for Book %d: ", n + 1);
        scanf(" %[^\n]s", newBook.Author);

        printf("Enter Price for Book %d: ", n + 1);
        scanf("%f", &newBook.Price);

        newBook.NumGenres = 0;
        printf("\nSelect genres for Book %d by number:\n", n + 1);
        for (int i = 0; i < MAX_GENRES; i++) {
            printf("%d. %s\n", i + 1, genres_list[i]);
        }
        printf("Enter genre numbers (separate multiple genres with spaces) for Book %d: ", n + 1);
        int genre_index;
        while (scanf("%d", &genre_index) == 1) {
            if (genre_index < 1 || genre_index > MAX_GENRES) {
                printf("Invalid genre number. Please select again.\n");
                continue;
            }
            add_genre(&newBook, genre_index - 1);
            if (newBook.NumGenres >= 2) {
                break; 
            }}

        library_db[book_count++] = newBook;
        printf("Book %d added successfully.\n", n + 1);
    }
    while (getchar() != '\n');}

void display_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
    } else {
        printf("List of all books:\n\n");
        for (int i = 0; i < book_count; i++) {
            printf("ISBN: %d\n", library_db[i].ISBN);
            printf("Title: %s\n", library_db[i].Title);
            printf("Author: %s\n", library_db[i].Author);
            printf("Price: %.2f\n", library_db[i].Price);
            printf("Genres: ");
            for (int j = 0; j < library_db[i].NumGenres; j++) {
                printf("%s", library_db[i].Genres[j]);
                if (j < library_db[i].NumGenres - 1) {
                    printf(", ");
                }}
            printf("\n\n");
        }}}

void search_genres() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nSelect genres to search by name:\n");
    for (int i = 0; i < MAX_GENRES; i++) {
        printf("%d. %s\n", i + 1, genres_list[i]);
    }

    printf("Enter genre numbers (separate multiple genres with spaces): ");
    char search_genre[200];
    scanf(" %[^\n]s", search_genre);

    printf("\nBooks found with the specified genre(s):\n");
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        for (int j = 0; j < library_db[i].NumGenres; j++) {
            if (strstr(search_genre, library_db[i].Genres[j]) != NULL) {
                printf("ISBN: %d\n", library_db[i].ISBN);
                printf("Title: %s\n", library_db[i].Title);
                printf("Author: %s\n", library_db[i].Author);
                printf("Price: %.2f\n", library_db[i].Price);
                printf("Genres: ");
                for (int k = 0; k < library_db[i].NumGenres; k++) {
                    printf("%s", library_db[i].Genres[k]);
                    if (k < library_db[i].NumGenres - 1) {
                        printf(", ");
                    }}
                printf("\n\n");
                found = 1;
                break;
            }}}
    if (!found) {
        printf("No books found with the specified genre(s).\n");
    }}

void list_books_by_author() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    char search_author[100];
    printf("Enter the author name to search books: ");
    scanf(" %[^\n]s", search_author);

    printf("\nBooks by %s:\n", search_author);
    int count = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(search_author, library_db[i].Author) == 0) {
            printf("ISBN: %d\n", library_db[i].ISBN);
            printf("Title: %s\n", library_db[i].Title);
            printf("Price: %.2f\n", library_db[i].Price);
            printf("Genres: ");
            for (int j = 0; j < library_db[i].NumGenres; j++) {
                printf("%s", library_db[i].Genres[j]);
                if (j < library_db[i].NumGenres - 1) {
                    printf(", ");
                }}
            printf("\n\n");
            count++;
        }}

    if (count == 0) {
        printf("No books found by %s.\n", search_author);
    } else {
        printf("Total books by %s: %d\n", search_author, count);
    }}

void list_book_count() {
    printf("Total books in the library: %d\n", book_count);
}
void free_library() {
    for (int i = 0; i < book_count; i++) {
        for (int j = 0; j < library_db[i].NumGenres; j++) {
           
        }}}

int main() {
    while (1) {
        printf("\n1. Add new book\n2. Display all books\n3. Search for books by genre\n");
        printf("4. List all books of a given author\n5. List the count of books in the library\n6. EXIT\n");
        int choice;
        printf("Enter your choice (1/2/3/4/5/6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                new_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                search_genres();
                break;
            case 4:
                list_books_by_author();
                break;
            case 5:
                list_book_count();
                break;
            case 6:
                free_library();
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }}

    return 0;
}
