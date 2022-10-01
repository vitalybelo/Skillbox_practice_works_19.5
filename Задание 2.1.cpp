#include <iostream>
#include <fstream>
using namespace std;

/**
 * Для решения Задания №2 идеально подходит функция getLine с которой
 * все считывание и отображение умещается на 2 строки, НО .... там еще
 * упоминаются функции read() и ?count(?), поэтому несмотря на то что
 * getLine значительно лучше, следующий вариант решения будет бинарный
 */
int main() {
    setlocale(LC_ALL,"RUS");

    ifstream inFile;
    string fileName;
    cout << "Введите имя файла для просмотра: ";
    cin >> fileName;
    inFile.open(fileName);

    if (inFile.is_open()) {
        cout << "\nText file '" << fileName << "' is found:\n";
        cout << "----------------------------------------\n\n";
        string line;
        while (getline(inFile, line))
            cout << line << endl;
        inFile.close();
    } else {
        cerr << "File '" << fileName << "' was not found.\n";
    }

    return 0;
}
