#pragma once


void AddBook(map<string, Books>& library) {
    Books book;
	string bookName;
	cout << "\n\n\n1. Enter the book - "; cin >> bookName;
	book.book = bookName;
	cout << "2. Enter the Lastname of autor - "; cin >> book.author;

    library.insert(make_pair(bookName, book));

}

void AddReader(map<string, Readers>& listReaders) {
    Readers reader;
    string lastName;
    cout << "\n\n\n1. Enter last name of reader - "; cin >> lastName;
    reader.lastName = lastName;
    cout << "2. Enter the name of reader - "; cin >> reader.name;

    listReaders.insert(make_pair(lastName, reader));

}

void ShowBooks(map<string, Books> library) {
	cout << "\t+++BOOK LIST+++";
	int i = 1;
	for (auto item : library) {
		cout << "\nThe Book # " << i << "." << endl;
		cout << "Book - " << item.first << endl;
		cout << "Author - " << item.second.author << endl;
		i++;
	}
}

void ShowReaders(map<string, Readers> listReaders) {
    cout << "\t+++List of Readers+++\n";
    int i = 1;
    for (auto item : listReaders) {
        cout << "\nThe Reader # " << i << "." << endl;
        cout << "Name - " << item.first << endl;
        cout << "Last name - " << item.second.name << endl;
        i++;
    }
}

void FindBook(map<string, Books> library, string key) {

	auto iterator = library.find(key);
	if (iterator != library.end()) {
		cout << iterator->second.book << " "
			<< iterator->second.author << endl;
	}
	else {
		cout << "No one book found (" << endl;
	}
}

void FindReader(map<string, Readers> listReaders, string key) {

    auto iterator = listReaders.find(key);
    if (iterator != listReaders.end()) {
        cout << iterator->second.name << " "
             << iterator->second.lastName << endl;
    }
    else {
        cout << "No one reader found (" << endl;
    }
}

