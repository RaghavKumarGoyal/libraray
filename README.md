Struct and Constants:

Defines a Book structure to store details of each book, including ISBN, title, author, price, and genres.
Defines a maximum limit for books (MAX_BOOKS) and genres (MAX_GENRES).


Global Variables:

library_db is an array to store the books.
book_count keeps track of the number of books added.

Helper Functions:

isbn_unique: Checks if the given ISBN is unique.
add_genre: Adds a genre to a book if the maximum genre limit (2) is not reached.


Main Functions:

new_book: Adds new books to the library, ensuring unique ISBNs and validating inputs.
display_books: Displays all books in the library.
search_genres: Searches and lists books based on specified genres.
list_books_by_author: Lists all books by a given author.
list_book_count: Displays the total number of books in the library.
free_library: Placeholder function for future implementation of freeing memory if needed.


Main Program Loop:

Continuously presents a menu to the user to add books, display books, search by genre, list books by author, and display the book count.
Handles user input to perform the corresponding actions or exit the program.
