#pragma once
#include <fstream>
#include "AddShowFind.h"

void ReadFromFileBooks(map<string, Books>& library, ifstream& file) {
    Books book;
	string key;

 do {
		getline(file, book.book, ';');
		getline(file, book.author);
           // cout << "Book - " << book.book << " and " << "Author - " << book.author << endl;

            key = book.book;
        library.insert(make_pair(key, book));
	} while (!file.eof());

    ShowBooks(library);

}


void ImportFromFileBooks(map<string, Books>& library) {
    ifstream file ("ListOfBooks.csv");

	if (file.is_open() && file.peek() == -1) {
		cout << "File is empty. Please, try again" << endl;
	}
	else if (file.is_open() && file.peek() != -1) {
		ReadFromFileBooks(library, file);
		cout << "List of books from the file is above.\n" << endl;
	}
	else {
		cout << "There is no such file with books. Please try again" << endl;
	}

	file.close();

}

void ReadFromFileReaders(map<string, Readers>& listReaders, ifstream& file) {
    Readers reader;
    string key;

    do {
        getline(file, reader.name, ';');
        getline(file, reader.lastName);

        key = reader.name;
        listReaders.insert(make_pair(key, reader));
    } while (!file.eof());

    ShowReaders(listReaders);
}


void ImportFromFileReaders(map<string, Readers>& listReaders) {

    ifstream file ("ListOfReaders.csv");
    if (file.is_open() && file.peek() == -1) {
        cout << "File is empty. Please, try again" << endl;
    }
    else if (file.is_open() && file.peek() != -1) {
        ReadFromFileReaders(listReaders, file);
        cout << "List of readers from file is above.\n" << endl;
    }
    else {
        cout << "There is no such file with readers. Please try again" << endl;
    }

    file.close();

}