#include <iostream>
#include <fstream>
using namespace std;

string toLowerCase (string &s);
bool equalIgnoreCase (string &a, string &b);
bool charIsPunctuation (char c);
string deletePunctuation (string &s);

/**
 * В этом варианте из файла считывается по одному слову для проверки
 * считанное слово проверяется на полное совпадение искомому слову.
 * (если нужно можно легко переделать под поиск подстроки в строке)
 * Ищется полное совпадение, не частичное вхождение подстроки в строку.
 * При сравнении не учитывается регистр и знаки препинания / пунктуации
 * которые могут прилипать к слову типа запятых, кавычек, точек и т.п.
 * Проверка окончания файла ведется в теле цикла считывания, так как
 * функция inFile.eof() срабатывает только когда уже произошла ошибка
 * считывания, и если ее поставить как было продемонстрировано в курсе
 * последняя строка будет считываться дважды, после ошибки - из буфера
 */
int main() {
    setlocale(LC_ALL,"RUS");
    ifstream inFile("..\\words.txt");

    string seekWord, readWord;
    cout << "Введите слово которое будем искать: ";
    cin >> seekWord;
    seekWord = deletePunctuation(seekWord);

    int count = 0;
    cout << "\nTEXT:\n\n";
    if (inFile.is_open()) {
        while (true) {
            inFile >> readWord;
            if (inFile.eof()) break;
            string cleanWord = deletePunctuation(readWord);
            if (equalIgnoreCase(seekWord,cleanWord))
                count++;
            cout << readWord << endl;
        }
        inFile.close();
        cout << "\nFOUND whole matches '" << seekWord << "' :: " << count << endl;

    } else {
        cerr << "File not found";
    }

    return 0;
}

string toLowerCase (string &s) {
    string sLowerCase;
    for (char i : s)
        sLowerCase += (char)tolower(i);
    return sLowerCase;
}

bool equalIgnoreCase (string &a, string &b) {
    if (toLowerCase(a) == toLowerCase(b)) return true;
    return false;
}

bool charIsPunctuation (char c) {
    string punctuation = ",.;:'\"*?^!%";
    for (char i : punctuation)
        if (c == i) return true;
    return false;
}

string deletePunctuation (string &s) {
    string cleanString;
    for (char i : s)
        if (!charIsPunctuation(i)) cleanString += i;
    return cleanString;
}
