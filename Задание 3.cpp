#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/**
 * считываемая ведомость накапливается в вектор, хотя напрашивается
 * класс Employee с свойствами и методами для чтения, обработки и так далее.
 * можно было и без вектора обойтись (только для вывода имени в конце сделал)
 */
int main() {
    setlocale(LC_ALL,"RUS");

    string fileName = "../sheet.txt";
    ifstream inFile(fileName);
    vector<string> fName;   // first name
    vector<string> sName;   // second name
    vector<string> hDate;   // hiring date
    vector<int> salary;     // ZP
    int amount = 0;         // max ZP
    int indexV = 0;         // index of maximum salary
    int maxSalary = 0;

    if (inFile.is_open()) {
        cout << endl << "Ведомость сотрудников: \n\n";
        for (int i = 0; inFile.good(); i++) {
            int casing;
            string name1, name2, date;
            inFile >> name1 >> name2 >> casing >> date;
            if (inFile.eof()) break;
            fName.push_back(name1);
            sName.push_back(name2);
            hDate.push_back(date);
            salary.push_back(casing);
            if (casing > maxSalary) {
                maxSalary = casing;
                indexV = i;
            }
            amount += casing;
            cout << name1 << " " << name2 << " " << casing << " " << date << endl;
        }
    } else {
        cerr << "File '" << fileName << "' was not found.\n";
    }
    cout << endl;
    cout << "Сумма выплат сотрудникам: " << amount << endl;
    cout << "Максимальная сумма оклада: " << maxSalary << endl;
    cout << "Принадлежит сотруднику: ";
    cout << fName[indexV] << " " << sName[indexV] << endl;
    cout << "Принятому на работу: " << hDate[indexV] << endl;

    inFile.close();
    return 0;
}
