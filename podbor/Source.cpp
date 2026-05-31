#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string sogl;
    int code = 0;
    int codeT = 0;

    cout << "=== НАСТРОЙКА ИГРЫ ===" << endl;
    cout << "Введите секретный код (число): ";
    cin >> code;
    cout << "Код принят. Теперь я запишу его в файл qqwe.txt..." << endl;

    ofstream outFile("qqwe.txt");

    if (!outFile.is_open()) {
        cout << "Ошибка: не удалось создать файл!" << endl;
        return 1;
    }

    outFile << code << endl;

    for (int i = 0; i < 10; i++) {
        outFile << "fake_data_" << i << " ";
    }

    outFile.close();
    cout << "Файл сохранен и закрыт." << endl;
    cout << "=======================" << endl << endl;

    for (int i = 1; i <= 100; i++)
    {
        cout << "Попытка № " << i << endl;
        cout << "Guess the code: ";

        if (!(cin >> codeT)) {
            cout << "Ошибка: нужно вводить числа!" << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            continue;
        }

        if (codeT == code)
        {
            cout << endl;
            cout << "You guess the code!" << endl;
            return 0; 
        }
        else
        {
            cout << "Неверно." << endl;
        }

        cout << "Do you want cheating? (yes/no): ";
        cin >> sogl;

        if (sogl == "yes")
        {
            cout << "I'll start cheating! Читаю из файла..." << endl;
            ifstream inp1("qqwe.txt");
            if (inp1.is_open()) {
                int secretFromFile;
                inp1 >> secretFromFile;

                cout << ">>> ПОДСКАЗКА ИЗ ФАЙЛА: Код равен " << secretFromFile << " <<<" << endl;

                inp1.close();
            }
            else {
                cout << "Ошибка: не удалось открыть файл для чтения." << endl;
            }
        }
        else if (sogl == "no")
        {
            cout << "Ok, playing fair." << endl;
        }
        else
        {
            cout << "Не понял ответ. Считаем, что нет." << endl;
        }

        cout << "-------------------" << endl;
    }

    cout << "Попытки закончились." << endl;
    return 0;
}