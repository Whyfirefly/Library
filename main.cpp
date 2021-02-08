/* Разработать программу по ведению библиотеки: список книг, список читателей, список выданных книг
 * Что должна уметь:
 * 1) выводить списки на экран
 * 2) искать информацию о читателе
 * 3) сохранять в файл при выходе и загружать из файла при входе
 * */

#include <iostream>
#include <map>
#include "Books.h"
#include "Readers.h"
#include "Export.h"
#include "Import.h"
#include "AddShowFind.h"

using namespace std;

int main() {
    map<string, Books> library;
    map<string, Readers> listReaders;
    int menu;
    string temp;
    string key;

    cout << "\n\n\t******Welcome to the Library*****\n\n";
    cout << "You can see the next data:\n";
    ImportFromFileBooks(library);
    ImportFromFileReaders(listReaders);
    do {
        cout << "\nTo add a Book press [1]" << endl;
        cout << "To show list of books press [2]" << endl;
        cout << "To find a book press [3]" << endl;
        cout << "To add a Reader press [4]" << endl;
        cout << "To show list of readers press [5]" << endl;
        cout << "To find a reader press [6]" << endl;
        cout << "To exit press [7]" << endl;
        cout << endl << "Choose the point, please - ";
        cin >> menu;

        switch (menu) {

            case 1:
                AddBook(library);
                break;

            case 2:
                ShowBooks(library);
                break;

            case 3: {
                string key;
                cout << "Enter the name of book - ";
                cin >> key;
                FindBook(library, key);
                break;
            }

            case 4:
                AddReader(listReaders);
                break;

            case 5:
                ShowReaders(listReaders);
                break;

            case 6: {
                string key;
                cout << "Enter the name of reader - ";
                cin >> key;
                FindReader(listReaders, key);
                break;
            }

            case 7: {
                ExportToFileBooks(library);
                ExportToFileReaders(listReaders);
                break;
            }
        }

    } while (menu != 7);
    return 0;
}
