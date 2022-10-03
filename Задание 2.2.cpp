#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
using namespace std;

/**
 * Это решение открывает текстовый файл как бинарный и считывает из него по
 * одному символу пока не закончится сам файл, далее выводит в консоль. Выводить
 * можно сразу по символьно (после считывания), а можно накопить все в буфер
 * и вывести потом целиком из буфера. (способ медленный но надежный))
  */
int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"RUS");

    ifstream inFile;
    string fileName;
    cout << "Введите имя файла для просмотра: ";
    cin >> fileName;
    inFile.open(fileName,ios::binary);

    //string buffer;
    if (inFile.is_open()) {
        cout << "\nText file '" << fileName << "' is found:\n";
        cout << "----------------------------------------\n\n";
        char buff[33];
        while (!inFile.eof()) {
            inFile.read(buff, sizeof (buff) - 1);
            buff[inFile.gcount()] = 0;
            cout << buff;
            //buffer += buff;
        }
        //cout << buffer << endl;
        cout << endl;
        inFile.close();
    } else {
        cerr << "File '" << fileName << "' was not found.\n";
    }

    return 0;
}
