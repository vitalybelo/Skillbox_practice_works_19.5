#include <iostream>
#include <fstream>
using namespace std;

/**
 * Проверка основана на первых 4х символах из файла, если они сходятся
 * файл признается в формате PNG (как сказано в задании). При положительном
 * результате проверки файла, далее уточняется имеет ли файл расширение PNG
 * и если нет - в консоль отображается сообщение что расширение не PNG
 * В задании рекомендуется использовать функцию substr(), однако для нашего
 * случая она не подходит, для определения нужного расширения имени файла,
 * лучше всего подойдет rfind (const char* )
 */
int main() {
    setlocale(LC_ALL,"RUS");

    string fileName;
    cout << "Введите имя файла изображения: ";
    cin >> fileName;

    ifstream inFile(fileName, ios::binary);
    if (inFile.is_open()) {
        char in[5];
        inFile.read(in,4);
        if (!inFile.eof()) {
            if (in[0] == -119 && in[1] == 'P' && in[2] == 'N' && in[3] == 'G') {
                cout << "\nPNG structure detected by header of file: " << fileName << endl;
                if (fileName.rfind(".png") == string::npos)
                    cout << "Attention: extension of file '" << fileName << "' IS NOT PNG";
                cout << endl;
            } else {
                cerr << "PNG file not detected" << endl;
            }
        }
        inFile.close();

    } else {
        cerr << "File '" << fileName << "' was not found.\n";
    }

    return 0;
}
