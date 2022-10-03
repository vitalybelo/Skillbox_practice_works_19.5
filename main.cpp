#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
using namespace std;

/**
 * ��� ������� ��������� ��������� ���� ��� �������� � ��������� �� ���� ��
 * ������ ������� ���� �� ���������� ��� ����, ����� ������� � �������. ��������
 * ����� ����� �� ��������� (����� ����������), � ����� �������� ��� � �����
 * � ������� ����� ������� �� ������. (������ ��������� �� ��������))
  */
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"RUS");

    ifstream inFile;
    string fileName;
    cout << "������� ��� ����� ��� ���������: ";
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
