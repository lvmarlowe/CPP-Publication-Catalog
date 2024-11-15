/*  LV Marlowe
    SDEV-240: C++ Programming I
    Week 6: Assignment 1 - Coding with Inheritance and Polymorphism
    30 Apr. 2022

------------------------ */

#include <iostream>                                                                     // Set inclusions
#include <string>

using namespace std;                                                                    // Use standard namespace

class Publication {                                                                     // Create publication class

private:                                                                                // Set private members
    struct Author {                                                                     // Create author structure
        string firstName;                                                               // Initialize components
        string lastName;                                                             
    };

    Author publicationAuthor[3];                                                        // Set author maximum limit to 3

protected:                                                                              // Create protected members
    string publicationName;                                                             // initialize variables
    int publicationPriceInDollars;                                                               

public:                                                                                 // Create public members
    void setPublicationPriceInDollars(int price) {                                      // Create method to set publication price
        publicationPriceInDollars = price;
    }

    int getPublicationPriceInDollars() {                                                         // Create method to get publication price
        return publicationPriceInDollars;
    }

    void setAuthors(string a, string b) {                                               // Create method to set one author
        publicationAuthor[0].firstName = a;
        publicationAuthor[0].lastName = b;
      }

    void setAuthors(string a, string b, string c, string d) {                           // Create method to set two authors
        publicationAuthor[0].firstName = a;
        publicationAuthor[0].lastName = b;
        publicationAuthor[1].firstName = c;
        publicationAuthor[1].lastName = d;
    }

    void setAuthors(string a, string b, string c, string d, string e, string f) {       // Create method to set three authors
        publicationAuthor[0].firstName = a;
        publicationAuthor[0].lastName = b;
        publicationAuthor[1].firstName = c;
        publicationAuthor[1].lastName = d;
        publicationAuthor[2].firstName = e;
        publicationAuthor[2].lastName = f;
    }

    string listAuthors() {                                                              // Create method to list authors
        string temp = "";                                                               // Create temporary string

        for (int i = 0; i < 3; i++) {                                                   // Loop 3 times, starting at zero and increasing by one each time,
            if (publicationAuthor[i].firstName != ""                                    // If the author string at i index is not blank
               && publicationAuthor[i].lastName != "") {
                temp =  temp                                                            // Add the author name to the temporary string in the specified format
                        + publicationAuthor[i].lastName
                        + ", "
                        + publicationAuthor[i].firstName[0]
                        + "., ";
            }
        }
        return temp;                                                                    // Return the temporary string
    }
};

class Book : public Publication {                                                       // Create book class as a subclass of publication
public:                                                                                 // Create public members
    string ISBN;                                                                        // Initialize variables
    int bookNumberPages;
    int bookPublishYear;

    void setPublicationName(string name) {                                              // Create method to set book name
        publicationName = name;
    }

    string getPublicationName() {                                                       // Create method to get book name
        return publicationName;
    }

    Book(int p) {                                                                       // Create constructor for book price
        publicationPriceInDollars = p;
    }

    Book() {                                                                            // Create default price constructor
        publicationPriceInDollars = 0;
    }
};

class Journal : public Publication {                                                    // Create journal as subclass of publication
public:                                                                                 // Create public members
    string ISSN;                                                                        // Initialize variable

    void setPublicationName(string name) {                                              // Create method to set journal name
        publicationName = name;
    }

    string getPublicationName() {                                                       // Create method to get journal name
        return publicationName;
    }
};

class Article : public Journal {                                                        // Create article as subclass of journal
public:
    Article(int p) {                                                                    // Create contructor for article price
        publicationPriceInDollars = p;
    }

    Article() {                                                                         // Create default price contructor
        publicationPriceInDollars = 0;
    }

    int articleVolume;                                                                  // Initialize variables
    int articleIssue;
    int articlePublishYear;
    int articleStartPage;
    int articleEndPage;
    string articleTitle;

    string citation() {                                                                 // Create method to cite article
        string temp = "";                                                               // Create temporary string
        string year = to_string(articlePublishYear);                                    // Convert nonstring variables to strings
        string volume =  to_string(articleVolume);
        string issue =  to_string (articleIssue);
        string start = to_string(articleStartPage);
        string end = to_string(articleEndPage);

        temp =  listAuthors()                                                           // Add variables to temporary string in specified format
                + "(" + year
                + "). "
                + articleTitle
                + ". "
                + getPublicationName()
                + ", "
                + volume
                + "("
                + issue
                + "), "
                + start
                + "-"
                + end;

        return temp;                                                                    // Return temporary string
    }
};

int main()                                                                              // Start main code block
{
    Publication firstPublication;                                                       // Create publication
    firstPublication.setPublicationPriceInDollars(24);                                  // Set publication price

    Book firstBook;                                                                     // Create book
    firstBook.setAuthors("Manuel", "Oliveira", "Julia", "Roberts");                     // Set book variables
    firstBook.setPublicationName("History of Cinematography");
    firstBook.ISBN = "9876543210";
    firstBook.bookNumberPages = 123;
    firstBook.bookPublishYear = 1995;
    firstBook.setPublicationPriceInDollars(12);

    Article firstArticle;                                                               // Create article
    firstArticle.setAuthors("Joan", "Rider");                                           // Set article variables
    firstArticle.setPublicationName("International Journal of Computation");
    firstArticle.ISSN = "1234567890";
    firstArticle.articleTitle = "A novel C++ program";
    firstArticle.articlePublishYear = 1996;
    firstArticle.articleVolume = 4;
    firstArticle.articleIssue = 2;
    firstArticle.articleStartPage = 45;
    firstArticle.articleEndPage = 99;
    firstArticle.setPublicationPriceInDollars(60);

    Publication publicationArray[20];                                                   // Create publication array with maximum of 20 publications

    publicationArray[0] = firstPublication;                                             // Set index 0 of the array to the first publication

    for (int i = 1; i < 20; i = i + 2) {                                                // Set the odd index numbers of the array to the first article
        publicationArray[i] = firstArticle;
        }

    for (int i = 2; i < 20; i = i + 2) {                                                // Set the even index numbers of the array, starting at 2, to the first book
        publicationArray[i] = firstBook;
    }

    for (int i = 0; i < 20; i++){                                                       // Starting at zero, looping through 20 times, and increasing by one for each loop
        cout << "$"                                                                     // Print the price of the publication at i index
             << publicationArray[i].getPublicationPriceInDollars()
             << endl;
     }

    cout                                                                                // Print the citation of the first article
        << endl
        << firstArticle.citation()
        << endl;

    return 0;                                                                           // Return zero
}                                                                                       // Pass C++ Programming I?   