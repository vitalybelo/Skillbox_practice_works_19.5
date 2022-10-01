#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/**
 * Это решение открывает текстовый файл как бинарный и считывает из него по
 * одному символу пока не закончится сам файл, далее выводит в консоль. Выводить
 * можно сразу по символьно (после считывания), а можно накопить все в буфер
 * и вывести потом целиком из буфера. (способ медленный но надежный))
  */
int main() {
    setlocale(LC_ALL,"RUS");

    ifstream inFile;
    string fileName;
    cout << "Введите имя файла для просмотра: ";
    cin >> fileName;
    inFile.open(fileName,ios::binary);

    if (inFile.is_open()) {
        vector<char> buffer;
        cout << "\nText file '" << fileName << "' is found:\n";
        cout << "----------------------------------------\n\n";
        char oneChar[2];
        if (inFile.is_open()) {
            while (true) {
                inFile.read(oneChar, 1);
                if (inFile.eof()) break;
                buffer.push_back(oneChar[0]);
            }
        }
        for (char i : buffer) cout << i;
        inFile.close();
    } else {
        cerr << "File '" << fileName << "' was not found.\n";
    }

    return 0;
}
