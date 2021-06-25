#include "gost.h"
#include "mars.h"
int main ()
{
    bool flag = true;
    string r;
    string f_in, f_out,f_IV,password;
    cout << "1- шифрование с использованием алгоритма Mars"<< endl;
    cout << "2- расшифрование с использованием алгоритма Mars"<< endl;
    cout << "3 - шифрование с использованием алгоритма Gost" << endl;
    cout << "4 - расшифрование с использованием алгоритма Gost"<< endl;
    cout << "exit - завершение программы"<< endl;
    do {
        cout << "Выберите режим работы: ";
        cin >> r;
        if (r == "1") {
            cout << "Путь до файла: ";
            cin >> f_in;
            cout << "Путь до файла для результата: ";
            cin >> f_out;
            cout << "Пароль: ";
            cin >> password;
            try {
                mars_al encode(f_in,f_out,password);
                encode.EncryptMars(encode);
            } catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
        if (r == "2") {
            cout << "Путь до файла: ";
            cin >> f_in;
            cout << "Путь до файла для результата: ";
            cin >> f_out;
            cout << "Путь до файла с вектором инициализации: ";
            cin >> f_IV;
            cout << "Пароль: ";
            cin >> password;
            try {
                mars_al decode(f_in,f_out,password,f_IV);
                decode.DecryptMars(decode);
            } catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
        if (r== "3") {
            cout << "Путь до файла: ";
            cin >> f_in;
            cout << "Путь до файла для результата: ";
            cin >> f_out;
            cout << "Пароль: ";
            cin >> password;
            try {
                gost_al encode(f_in,f_out,password);
                encode.EncryptGost(encode);
            } catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }

        if (r == "4") {
            cout << "Путь до файла: ";
            cin >> f_in;
            cout << "Путь до файла для результата: ";
            cin >> f_out;
            cout << "Путь до файла с вектором инициализации: ";
            cin >> f_IV;
            cout << "Пароль: ";
            cin >> password;
            try {
                gost_al decode(f_in,f_out, password, f_IV );
                decode.DecryptGost(decode);
            } catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
        if (r == "exit") {
            cout << "До новых встреч." << endl;
            flag = false;
            break;
        }
    } while (flag != false);

    return 0;
}