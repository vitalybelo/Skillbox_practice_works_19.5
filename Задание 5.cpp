#include <iostream>
#include <fstream>
#include <random>
#include <windows.h>
using namespace std;

void readQuestion (int index);
string toLowerCase (string &s);
bool getAnswer (int index);

/**
 * Честно говоря ничего не понял про то как вводить смещение от смещения барабана
 * поэтому номер сектора определяется по старинке - случайное число от 1 до 13, чтобы
 * сделать шоу более комфортным без аналогового барабана.
 *
 * В моем Clion путь к EXE файлу по умолчанию: cmake-build-debug/
 * поэтому чтобы добраться до каталога с *.cpp и тестовыми файлами используется "../"
 *
 * Да простят меня боги за глобальную переменную. Выберите нужную вам, плиз ...
 * string path = "../connoisseurs_club/utf_8/";
 */
string path = "../connoisseurs_club/win_1251/";

int main() {
//    SetConsoleCP ( 1251 ) ;
//    SetConsoleOutputCP ( 1251 ) ;
    setlocale(LC_ALL,"RUS");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,12);

    bool guessDrum[13];
    int scholarWins = 0;
    int viewersWins = 0;
    int roulette, gameRound = 1;
    for (bool & i : guessDrum) i = false;

    do {
        cout << "\nСЧЕТ: знатоки = " << scholarWins << " :: зрители = " << viewersWins << endl;
        cout << "-------------------------------------------\n";
        cout << "Внимание раунд номер: " << gameRound++ << endl;
        roulette = dist(gen);
        cout << "На барабане выпал сектор: " << (roulette + 1) << endl;

        if (!guessDrum[roulette]) {
            guessDrum[roulette] = true;
            cout << "Играет вопрос под номером: " << roulette + 1<< endl;
        } else {
            cout << "Сектор № " << (roulette + 1) << " уже играл, переход по стрелке..." << endl;
            do {
                if (roulette >= 12)
                    roulette = 0; else roulette++;
            } while (guessDrum[roulette]);
            guessDrum[roulette] = true;
            cout << "Играет вопрос под номером: " << (roulette + 1) << endl;
        }

        readQuestion(roulette);
        if (getAnswer(roulette))
            scholarWins++; else viewersWins++;

    } while (scholarWins < 6 && viewersWins < 6 && gameRound <= 13);

    cout << "\nИГРА ЗАКОНЧЕНА: ";
    if (scholarWins == 6) {
        cout << "победили знатоки\n";
    } else {
        cout << "победили зрители\n";
    }
    return 0;
}

void readQuestion (int index) {
    string fileName = path + "question_" + to_string(index + 1) + ".txt";
    ifstream questionFile(fileName);

    cout << "\nВнимание вопрос:\n";
    if (questionFile.is_open()) {
        string line;
        while (getline(questionFile, line))
            cout << line << endl;
        questionFile.close();
    } else {
        cerr << "Ошибка чтения файла " + fileName << endl;
    }
}

string toLowerCase (string &s) {
    string sLowerCase;
    for (char i : s)
        sLowerCase += (char)tolower(i);
    return sLowerCase;
}

bool getAnswer (int index) {

    bool result = false;
    string fileName = path + "answer_" + to_string(index + 1) + ".txt";
    ifstream answerFile(fileName);

    if (answerFile.is_open()) {
        string answer;
        cout << "\nВведите ваш ответ: ";
        getline(cin,answer);

        string line;
        getline(answerFile, line);

        if (toLowerCase(answer) == toLowerCase(line)) {
            cout << "Ваш ответ правильный: " << line << " (очко знатокам)" << endl;
            result = true;
        } else {
            cout << "Неправильно. Правильный ответ: " << line << " (очко зрителям)"<< endl;
        }
        answerFile.close();
    } else {
        cerr << "Ошибка чтения файла " + fileName << endl;
    }
    return result;
}
