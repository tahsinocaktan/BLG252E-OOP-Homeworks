#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

using namespace std;

class Book{ //book class from hw3.pdf
public:
    int book_id;
    int publication_year;
    int author_ID;
    int publisher_ID;
    string book_title;

    Book() {}; //book parameterless constructor
    Book(int,int,int,int,string); //book parameterized constructor
    void print();

};

map<int,string> publishers; //for storing publisher.txt
map<int,string>::iterator publishers_iter; //iteration number variable
int publisher_id; // first field of publisher
string publisher_name; //second field of publisher

map<int,string> authors; //for storing authors.txt
map<int, string>::iterator authors_iter; //iteration number variable
int author_id; // first field of authors
string author_fullname; //second field of authors

map<int, Book> books; //for storing Book.txt
map<int, Book>::iterator val_of_books; //iteration number variable
int book_id; // first field of books
int public_Year; //store publication year
int author_id_; //store author_id
int publisher_id_; //store publisher_id_
string book_title; //store book_title 

Book::Book(int book_id, int publication_year, int author_ID, int publisher_ID, string book_title): book_id(book_id), publication_year(publication_year), author_ID(author_ID),publisher_ID(publisher_ID),book_title(book_title) {}

void Book::print() {	 
				cout << "LISTS OF ALL BOOKS GROUPED BY PUBLISHERS" << endl;
			    cout << "========================================" << endl;
			
			    int sum_book = 0;
			
			    for (map<int, string>::iterator value_of_pub = publishers.begin(); value_of_pub != publishers.end(); ++value_of_pub) {
			        int publisher_id = value_of_pub->first; // assign first value
			        string publisher_name = value_of_pub->second; // assign second value
			        int cal_book = 0; //number of books
			
			        cout << "PUBLISHER ID    : " << publisher_id << endl; //from hw3.pdf
			        cout << "PUBLISHER NAME  : " << publisher_name << endl;//from hw3.pdf
			
			        for (map<int, Book>::iterator value_of_book = books.begin(); value_of_book != books.end(); ++value_of_book) {
			            const Book &book = value_of_book->second; //assign second value
			            if (book.publisher_ID == publisher_id) {
			                if (cal_book == 0) {
			                    cout <<left <<setw(10)<< "BOOK_ID" <<setw(20) << "PUBLICATION_YEAR" << setw(20) << "AUTHOR_FULLNAME" << setw(20) << "BOOK_TITLE" << endl; //from hw3.pdf
			                }
			                cout << setw(10) << book.book_id << setw(18) << book.publication_year << left << setw(20) << authors[book.author_ID] << book.book_title << endl; //print value
			                cal_book++; //increase value
			                sum_book++; //increase value
			            }
			        }
			
			        cout << "NUMBER OF BOOKS : " << cal_book << endl; //from hw3.pdf
			        cout << "--------------------------------------------------------------------------------------------------" << endl; //from hw3.pdf
			    }
			
			    cout << "TOTAL NUMBER OF ALL BOOKS : " << sum_book << endl; //from hw3.pdf
			    cout << endl; 
			    cout << "Program finished." << endl;//from hw3.pdf		  	
}

int main() {
	
	ifstream publisherFile; // input file stream
    publisherFile.open("PUBLISHERS.txt"); // open file

    if (!publisherFile.is_open()) { //error can not open file 
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    while (!publisherFile.eof())
    { 
        publisherFile >> publisher_id ; // get publisher_id
        getline(publisherFile, publisher_name ); // get all line
        publishers[publisher_id]=publisher_name; //store map<> variable
    }
    publisherFile.close();
 // for (publishers_iter = publishers.begin(); publishers_iter != publishers.end();++publishers_iter) {
 //       cout << publishers_iter->first << publishers_iter->second << '\n'; 
 //   }
 
	
    ifstream authorFile; // input file stream
    authorFile.open("AUTHORS.txt");    // open file

    if (!authorFile.is_open()) { //error can not open file 
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    while (!authorFile.eof())
    {
        authorFile >> author_id ; // get author_id
        getline(authorFile,author_fullname); // get string
        authors[author_id]=author_fullname; //store map<> variable
    }
    authorFile.close();
// for (authors_iter = authors.begin(); authors_iter != authors.end();++authors_iter) {
//        cout << authors_iter->first << authors_iter->second << '\n'; 
//    }

    ifstream bookFile;
    bookFile.open("BOOKS.txt");    // open file

    if (!bookFile.is_open()) { //error can not open file 
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    while (!bookFile.eof())
    {
        bookFile >> book_id >> public_Year>>author_id_>>publisher_id_; // get book_id public_Year author_id_ publisher_id_
        getline(bookFile, book_title); // get string
        
		Book book_lib (book_id,public_Year,author_id_,publisher_id_,book_title); //call parameterized constructor
		books[book_id] = book_lib; //store map<> variable
		//book_lib.print(); //print all 
    }
    val_of_books = books.begin();
    val_of_books->second.print();
    return 0;
}

