#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

// thErE      are a nUmbEr                 of traditions.. For423 weDDiNgs,,,,,,,,, tHat hAve7567 sUrvIved Into tHe 21st cEntury......

void StrInput(string& str) {

    ifstream File(R"(C:\Программирование\4_прак\Test.txt)");
    if (!File.is_open()) {
        cout << "Файл не открыт";
    }
    string str2;
    while (!File.eof())
        getline(File, str);
    cout << "Введённая строка:" << '\n';
    cout << str << '\n';
    File.close();
}

void StrCin(string& str) {
    getline(cin, str);
}

void DeleteSymbols(string& str, char Symbol) {
    int Len = str.length();
    for (int i = 0; i < Len; i++)
    {
        int cnt = 0;
        if (str[i] == Symbol)
        {
            while (str[i + cnt] == Symbol)
            {
                ++cnt;
                --Len;
            }
            if (cnt > 0)
                str = str.erase(i + 1, cnt - 1);
        }
    }
}

void DeletePoints(string& str) {
    char Symbol = '.';
    int Len = str.length();
    if (str.find(Symbol) >= 0) {
        for (int i = str.find(Symbol); i < Len; i++) {
            int cntPoints = 0;
            int cntEllipsis = 0;
            while (str[i + cntPoints] == Symbol)
                ++cntPoints;
            cntEllipsis = cntPoints / 3;
            if (cntEllipsis != 0) {
                str = str.erase(i + 3, cntPoints - 3);
                Len -= cntPoints - 3;
                i += 3;
            }
            if (cntPoints == 2) {
                str = str.erase(i + 1, 1);
                Len--;
            }
            if (cntEllipsis > 1) {
                str = str.erase(i, 3);
                Len -= 3;
            }
        }
    }
}

void DeleteNumbers(string& str, int& i) {
    int Len = str.length();
    string str2;
    bool Number = false;
    while (((str[i] != ' ') and (str[i] != ',')
        and (str[i] != '!') and (str[i] != '?')
        and (str[i] != ';') and (str[i] != ':')
        and (str[i] != ')') and (str[i] != '.')
        and (str[i] != '/')) and (i != Len))
    {
        if (str[i] >= 48 and str[i] <= 57)
            Number = true;
        str2 += str[i];
        ++i;
    }
    if (Number == false)
        cout << str2 << ' ';
}

void UppercaseLetters(string str) {
    int Len = str.length();
    bool space = false;
    for (int i = 0; i < Len - 1; i++) {
        if (str[i] == ' ')
            str[i + 1] = toupper(str[i + 1]);
    }
    str[0] = toupper(str[0]);
    cout << str << '\n';
}

void LinearSearch(string str) {
    string Substring;
    cout << "Исходная строка:" << '\n';
    cout << str << '\n';
    getline(cin, Substring);
    cout << '\n' << "Введите подстроку для её поиска:" << '\n';
    cin >> Substring;
    int Len = str.length();
    int LenSub = Substring.length();
    string str2;
    bool flag = false;
    for (int i = 0; i < Len - LenSub + 1; i++) {
        int j = i, cnt = 0;
        str2.clear();
        while (cnt != LenSub) {
            str2 += str[j];
            j++;
            cnt++;
        }
        if (str2 == Substring) {
            for (int k = i; k < j; k++)
                str[k] = toupper(str[k]);
            flag = true;
        }
    }
    if (flag == false)
        cout << '\n' << "Данная подстрака не найдена" << '\n';
    else
        cout << '\n' << str << '\n';
}


void Task2(string& str) {
    string Symbols = " ,/)(!;:?";
    for (int i = 0; i < Symbols.length(); i++)
    {
        char Symbol = Symbols[i];
        DeleteSymbols(str, Symbol);
    }
    DeletePoints(str);
    int Len = str.length();
    for (int i = 0; i < Len; i++)
        str[i] = tolower(str[i]);
}

void Task3(string& str) {
    cout << "Исходная строка:" << '\n';
    cout << str << '\n';
    cout << "Слова из строки, не содержащие цифры:" << '\n';
    for (int i = 0; i < str.length(); i++) {
        DeleteNumbers(str, i);
    }
    cout << '\n';
}

void Task4(string& str) {
    cout << "Исходная строчка:" << '\n';
    cout << str << '\n';
    cout << "Строчка со словами с заглавной буквы:" << '\n';
    str[0] = tolower(str[0]);
    UppercaseLetters(str);
}


void PrintMenu4() {
    system("cls");
    cout << "Что выхотите сделать?" << '\n';
    cout << "2. Отформатировать строку" << '\n';
    cout << "3. Слова не содержащие цифры" << '\n';
    cout << "4. Строка со словами с заглавной буквы" << '\n';
    cout << "5. Найти подстроку" << '\n';
    cout << "6. Выйти из программы" << '\n';
}

void Menu4(string& str) {
    int Variant;
    do {
        PrintMenu4();
        cin >> Variant;
        switch (Variant) {
        case 2:
            cout << "Исходная строка:" << '\n';
            cout << str;
            Task2(str);
            cout << '\n' << "Отформатированная строка" << '\n';
            cout << str << '\n';
            break;
        case 3:
            Task3(str);
            break;
        case 4:
            Task4(str);
            break;
        case 5:
            LinearSearch(str);
            break;
        }
        if (Variant != 6)
            system("pause");
    } while (Variant != 6);
}


int main() {
    setlocale(0, "");
    string str;
    string perm;
    cout << "Ввести строку с файла или с клавиатуры(a или b)" << '\n';
    getline(cin, perm);
    while (perm != "a" and perm != "b") {
        cout << "Неверно введён вид вывода, попробуйте снова: ";
        getline(cin, perm);
    }
    if (perm == "a")
        StrInput(str);
    else {
        cout << "Введите строку:" << '\n';
        getline(cin, str);
    }
    system("pause");
    Menu4(str);
}
