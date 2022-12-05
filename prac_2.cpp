#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <chrono>
using namespace std;


void Output(int* array, int N){
    cout << '[';
    for (int i = 0; i < N; i++) {
        if (i != N - 1)
            cout << array[i] << ", ";
        else
            cout << array[i];
    }
    cout << ']'<<'\n';
}

void Fill(int N, int* array, int* arraySorted) {
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 199 - 99;
        arraySorted[i] = array[i];
    }
    Output(array, N);
}

void Quicksort(int* array, int begin, int end){
    int mid;
    int start = begin;
    int finish = end;
    mid = array[(start + finish) / 2];
    while (start < finish)
    {
        while (array[start] < mid) start++;
        while (array[finish] > mid) finish--;
        if (start <= finish)
        {
            swap(array[start], array[finish]);
            start++;
            finish--;
        }
    }
    if (begin < finish) Quicksort(array, begin, finish);
    if (start < end) Quicksort(array, start, end);
}

void OutSort(int* array, int begin, int end, int N) {
    auto StartTime = chrono::high_resolution_clock::now();
    Quicksort(array, begin, end);
    auto EndTime = chrono::high_resolution_clock::now();
    Output(array, N);
    cout << "Время, потраченное на быструю сортировку = " << chrono::duration_cast<chrono::nanoseconds>(EndTime - StartTime).count() << "нс." << '\n';
}

void SearchMinMax(int* arraySorted, int* array, int N) {
    auto StartTime = chrono::high_resolution_clock::now();
    int minimal = array[0];
    int maximal = array[N - 1];
    auto EndTime = chrono::high_resolution_clock::now();
    cout << "Минимальный элмемент массива = " << minimal << '\n';
    cout << "Максимальный элемент массива = " << maximal << '\n';
    cout << "Время, потраченное на поиск в остортированном массиве = " << chrono::duration_cast<chrono::nanoseconds>(EndTime - StartTime).count() << "нс." << '\n';

    int min = array[0];
    int max = array[0];
    auto StartTime1 = chrono::high_resolution_clock::now();
    for (int i = 1; i < N; i++) {
        if (array[i] < min)
            min = array[i];
        if (array[i] > max)
            max = array[i];
    }
    auto EndTime1 = chrono::high_resolution_clock::now();
    cout << "Время, потраченное на поиск в неостортированном массиве = " << chrono::duration_cast<chrono::nanoseconds>(EndTime1 - StartTime1).count() << "нс." << '\n';
}

void SearchMiddle(int* array, int N) {
    int middle = round(array[0] + array[N - 1]);
    cout << "Среднее значение = " << middle << '\n';
    cout << "Индексы элементов равных среднему значению: ";
    int cnt = 0;
    auto StartTime = chrono::high_resolution_clock::now();
    for (int i = 0; ((array[i] <= middle) && (i < N)); i++) {
        if (array[i] == middle)
            cnt++;
    }
    auto EndTime = chrono::high_resolution_clock::now();
    if (cnt == 0)
        cout << "элементов, равных среднему значению нет" << '\n';
    else {
        for (int i = 0; array[i] <= middle; i++) {
            if (array[i] == middle)
                cout << i << ' ';
        }
        cout << '\n' << "Количество элементов равных среднему = " << cnt << '\n';
    }
    cout << "Время, потраченное на поиск: " << chrono::duration_cast<chrono::nanoseconds>(EndTime - StartTime).count() << "нс." << '\n';
}

void SearchLessA(int* array, int N) {
    int a, cnt=0;
    cout << "Введите число а: ";
    cin >> a;
    for (int i = 0; ((array[i] < a) && (i<N)); i++) {
        cnt++;
    }
    cout << '\n' << "Количество элементов меньше чем a = " << cnt << '\n';
}

void SearchMoreB(int* array, int N) {
    int b, cnt = 0;
    cout << "Введите число b: ";
    cin >> b;
    for (int i = N-1; (array[i]>b && i>=0); i--) {
        cnt++;
    }
    cout << '\n' << "Количество элементов больше чем b = " << cnt << '\n';
}

int BinSearch(int* array, int left, int right, int N) {
    bool flag = false;
    int chislo;
    cout << "Введите число для поиска: ";
    cin >> chislo;
    int medium;
    auto StartTime = chrono::high_resolution_clock::now();
    while ((left <= right) && (flag != true)) {
        medium = (left + right) / 2;
        if (chislo == array[medium]) {
            flag = true;
        }
        if (array[medium] > chislo)
            right = medium - 1;
        else
            left = medium + 1;
    }
    auto EndTime = chrono::high_resolution_clock::now();
    if (flag)
        cout << "Число " << chislo << " есть в массиве." << '\n';
    else
        cout << "Числа " << chislo << " нет в массиве." << '\n';
    cout << "Бинарный поиск по массиву занял = " << chrono::duration_cast<chrono::nanoseconds>(EndTime - StartTime).count() << "нс." << '\n';
    return N + 1;
    flag = false;
    auto StartTime1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        if (array[i] == chislo)
            flag = true;
        if (flag)
            break;
    }
    auto EndTime1 = chrono::high_resolution_clock::now();
    cout << "Поиск перебором занял = " << chrono::duration_cast<chrono::nanoseconds>(EndTime1 - StartTime1).count() << "нс." << '\n';
}

void ChangeLoc(int* array, int N){ 
    int First, Second;
    cout << "Введите номера двух элементов, которые хотите поменять местами: ";
    cin >> First >> Second;
    auto StartTime = chrono::high_resolution_clock::now();
    if (First >= 0 && Second >= 0 && First < N && Second < N) {
        swap(array[First], array[Second]);
        auto EndTime = chrono::high_resolution_clock::now();
        Output(array, N);
        cout<< "Время обмена элементов местами = " << chrono::duration_cast<chrono::nanoseconds>(EndTime - StartTime).count() << "нс." << '\n';
    }
    else {
        cout << "Вы неверно ввели номера элементов, попройте снова" << '\n';
        return ChangeLoc(array, N);
    }
    
}

void PrintMenu() {
    system("cls");
    cout << "Что выхотите сделать?" << '\n';
    cout << "1. Выполнить 1 задание" << '\n';
    cout << "2. Выполнить 2 задание" << '\n';
    cout << "3. Выполнить 3 задание" << '\n';
    cout << "4. Выполнить 4 задание" << '\n';
    cout << "5. Выполнить 5 задание" << '\n';
    cout << "6. Выполнить 6 задание" << '\n';
    cout << "7. Выполнить 7 задание" << '\n';
    cout << "8. Выполнить 8 задание" << '\n';
    cout << "9. Выйти из программы" << '\n';

}

void Menu(int* array, int* arraySorted, int N) {
    int Variant;
    system("pause");
    do {
        PrintMenu();
        cin >> Variant;
        switch (Variant) {
        case 1:
            Fill(N, array, arraySorted);
            break;
        case 2:
            Output(array, N);
            OutSort(arraySorted, 0, N - 1, N);
            break;
        case 3:
            Output(arraySorted, N);
            SearchMinMax(arraySorted, array, N);
            break;
        case 4:
            Output(arraySorted, N);
            SearchMiddle(arraySorted, N);
            break;
        case 5:
            Output(arraySorted, N);
            SearchLessA(arraySorted, N);
            break;
        case 6:
            Output(arraySorted, N);
            SearchMoreB(arraySorted, N);
            break;
        case 7:
            Output(arraySorted, N);
            BinSearch(arraySorted, 0, N - 1, N);
            break;
        case 8:
            Output(arraySorted, N);
            ChangeLoc(arraySorted, N);
            Quicksort(arraySorted, 0, N - 1);
            break;
        }
        if (Variant != 9)
            system("pause");
    } while (Variant != 9);
}

int main()
{
    const int N = 100;
    setlocale(0, "");
    int array[N];
    int arraySorted[N];
    srand(time(0));

    Fill(N, array, arraySorted);

    OutSort(arraySorted, 0, N-1, N);
    
    SearchMinMax(arraySorted, array, N);

    SearchMiddle(arraySorted, N);

    SearchLessA(arraySorted, N);

    SearchMoreB(arraySorted, N);

    BinSearch(arraySorted, 0, N - 1, N);

    ChangeLoc(arraySorted, N);

    Quicksort(arraySorted, 0, N - 1);

    Menu(array, arraySorted, N);
}