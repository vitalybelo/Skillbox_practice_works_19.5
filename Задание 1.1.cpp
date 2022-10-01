#include <iostream>
#include <fstream>
using namespace std;

int countWords (string &word, string &text);

/**
 * В этом варианте решения считывается весь файл с строку (ничего не мешает переделать
 * под анализ каждой считанной строки отдельно без накопления). Далее, происходит поиск
 * введенного слова как фрагмента входящего с состав слов строки, то есть если
 * ищем под/строку is - найдем ее в слове paradise и везде где она так нам попадется.
 * Именно это количество будет подсчитано - количество вхождений подстроки - в строку
 * в сравнениях не учитывается только регистр букв
 */
int main() {
    setlocale(LC_ALL,"RUS");
    ifstream inFile("..\\words.txt");

    string word, line, text;
    if (inFile.is_open()) {
        while (getline(inFile, line))
            text += line + "\n";
        inFile.close();
    }

    cout << "TEXT:\n\n" << text;
    cout << "Введите слово которое будем искать: ";
    cin >> word;

    cout << "\nFOUND matches '" << word << "' :: " << countWords(word, text) << endl;
    return 0;
}

int countWords (string &word, string &text) {

    int count = 0;
    int wSize = (int) word.size();
    int sSize = (int) text.size();
    int oSize = sSize - wSize + 1;

    for (int i = 0; i < oSize; ++i) {
        if (tolower(text[i]) == tolower(word[0])) {
            int j = 1;
            for (++i; j < wSize && i < sSize; ++i, ++j)
                if (tolower(text[i]) != tolower(word[j])) break;
            if (j == wSize) count++;
        }
    }
    return count;
}
