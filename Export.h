#pragma once
#include <fstream>

void WriteToFileBooks(map<string, Books> library, ofstream& file) {

	for (auto iter : library)
	{
		file << iter.second.book << ";";
		file << iter.second.author << endl;
	}
}


void ExportToFileBooks(map<string, Books> library) {
	ofstream file;

	file.open("ListOfBooks.csv", ios_base::out);
	if (library.empty()) {
		cout << "The library is empty. Please, add some positions at first." << endl;
	}
	else if (file.is_open()) {
		WriteToFileBooks(library, file);
		cout << "Recording is successful" << endl;
	}
	else {
		cout << "There is no such file. Please try again" << endl;
	}
	file.close();
}

void WriteToFileReaders(map<string, Readers> listReaders, ofstream& file) {

    for (auto iter : listReaders)
    {
        file << iter.second.name << ";";
        file << iter.second.lastName << endl;
    }
}


void ExportToFileReaders(map<string, Readers> listReaders) {
    ofstream file;

    file.open("ListOfReaders.csv", ios_base::out);
    if (listReaders.empty()) {
        cout << "The library is empty. Please, add some positions at first." << endl;
    }
    else if (file.is_open()) {
        WriteToFileReaders(listReaders, file);
        cout << "Recording is successful" << endl;
    }
    else {
        cout << "There is no such file. Please try again" << endl;
    }
    file.close();
}
