#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void PrintMatrix(int** Matrix, int Size) {
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            cout << setw(3) << setprecision(3) << Matrix[i][j];
            cout.flush();
            if (j != Size)
                cout << ' ';
        }
        cout << "\n";
    }
    Sleep(20);
}

void EmptyMatrix(int** Matrix, int Size) {
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            Matrix[i][j] = 0;
}

void SpiralMatrix(int** Matrix, int Size) {
    EmptyMatrix(Matrix, Size);
    int LineNumber = 0;
    for (int LineSize = 0; LineSize < Size / 2; LineSize++) {
        for (int i = LineNumber; i < Size - LineNumber; i++) {
            Matrix[LineNumber][i] = rand() % (Size * Size) + 1;
            system("cls");
            PrintMatrix(Matrix, Size);
        }
        for (int i = LineNumber + 1; i < Size - LineNumber; i++) {
            Matrix[i][Size - LineNumber - 1] = rand() % (Size * Size) + 1;
            system("cls");
            PrintMatrix(Matrix, Size);
        }
        for (int i = Size - LineNumber - 2; i >= LineNumber; i--) {
            Matrix[Size - LineNumber - 1][i] = rand() % (Size * Size) + 1;
            system("cls");
            PrintMatrix(Matrix, Size);
        }
        for (int i = Size - LineNumber - 2; i > LineNumber; i--) {
            Matrix[i][LineNumber] = rand() % (Size * Size) + 1;
            system("cls");
            PrintMatrix(Matrix, Size);
        }
        LineNumber++;
    }
}

void SnakeMatrix(int** Matrix, int Size) {
    EmptyMatrix(Matrix, Size);
    for (int LineNumber = 0; LineNumber < Size / 2; LineNumber++) {
        for (int** i = Matrix; i <= (Matrix + Size - 1); i++) {
            *(*i + LineNumber * 2) = rand() % (Size * Size) + 1;
            system("cls");
            PrintMatrix(Matrix, Size);
        }
        for (int** i = Matrix + Size - 1; i >= Matrix; i--) {
            *(*i + LineNumber * 2 + 1) = rand() % (Size * Size) + 1;
            system("cls");
            PrintMatrix(Matrix, Size);
        }
    }
}
void RotateMatrix(int** Matrix, int Size) {
    int** New_Matrix = new int* [Size];
    for (int i = 0; i < Size; i++)
        New_Matrix[i] = new int[Size];
    char permutation;
    cout << "Какую перестановвку выполнить ?(a или b или c или d)" << '\n';
    cin >> permutation;
    while (permutation != 'a' and permutation != 'b' and permutation != 'c' and permutation != 'd') {
        cout << "Неверно введён вид перестановки, попробуйте снова: ";
        cin >> permutation;
    }
    if (permutation == 'a') {
        for (int i = 0; i < Size / 2; i++)
            for (int j = 0; j < Size / 2; j++) {
                New_Matrix[i][j] = Matrix[i + Size / 2][j];
                New_Matrix[i][j + Size / 2] = Matrix[i][j];
                New_Matrix[i + Size / 2][j + Size / 2] = Matrix[i][j + Size / 2];
                New_Matrix[i + Size / 2][j] = Matrix[i + Size / 2][j + Size / 2];
            }
        Matrix = New_Matrix;
        PrintMatrix(Matrix, Size);
    }
    else if (permutation == 'b') {
        for (int i = 0; i < Size / 2; i++)
            for (int j = 0; j < Size / 2; j++) {
                New_Matrix[i][j] = Matrix[i + Size / 2][j + Size / 2];
                New_Matrix[i][j + Size / 2] = Matrix[i + Size / 2][j];
                New_Matrix[i + Size / 2][j + Size / 2] = Matrix[i][j];
                New_Matrix[i + Size / 2][j] = Matrix[i][j + Size / 2];
            }
        Matrix = New_Matrix;
        PrintMatrix(Matrix, Size);
    }
    else if (permutation == 'c') {
        for (int i = 0; i < Size / 2; i++)
            for (int j = 0; j < Size / 2; j++) {
                New_Matrix[i][j] = Matrix[i + Size / 2][j];
                New_Matrix[i][j + Size / 2] = Matrix[i + Size / 2][j + Size / 2];
                New_Matrix[i + Size / 2][j + Size / 2] = Matrix[i][j + Size / 2];
                New_Matrix[i + Size / 2][j] = Matrix[i][j];
            }
        Matrix = New_Matrix;
        PrintMatrix(Matrix, Size);
    }
    else {
        for (int i = 0; i < Size / 2; i++)
            for (int j = 0; j < Size / 2; j++) {
                New_Matrix[i][j] = Matrix[i][j + Size / 2];
                New_Matrix[i][j + Size / 2] = Matrix[i][j];
                New_Matrix[i + Size / 2][j + Size / 2] = Matrix[i + Size / 2][j];
                New_Matrix[i + Size / 2][j] = Matrix[i + Size / 2][j + Size / 2];
            }
        Matrix = New_Matrix;
        PrintMatrix(Matrix, Size);
    }
}

void SortMatrix(int** Matrix, int Size) {
    int ArrSize = Size * Size;
    int* Array = new int[ArrSize];
    int Array_i = 0;
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            Array[Array_i] = Matrix[i][j];
            Array_i++;
        }
    }

    bool Change = 1;
    while (Change) {
        Change = 0;
        for (int i = 0; i < ArrSize - 1; i++) {
            if (Array[i] > Array[i + 1]) {
                Change = 1;
                swap(Array[i], Array[i + 1]);
            }
        }
    }

    Array_i = 0;
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            Matrix[i][j] = Array[Array_i];
            Array_i++;
        }
    }
    PrintMatrix(Matrix, Size);
}

void MagnificationMatrix(int** Matrix, int Size) {
    int Number;
    cout << '\n' << "Введите число" << '\n';
    cin >> Number;
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            Matrix[i][j] += Number;
    PrintMatrix(Matrix, Size);
}

void ReducationMatrix(int** Matrix, int Size) {
    int Number;
    cout << '\n' << "Введите число" << '\n';
    cin >> Number;
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            Matrix[i][j] -= Number;
    PrintMatrix(Matrix, Size);
}

void MultiplicationMatrix(int** Matrix, int Size) {
    int Number;
    cout << '\n' << "Введите число" << '\n';
    cin >> Number;
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            Matrix[i][j] *= Number;
    PrintMatrix(Matrix, Size);
}
void DivisionMatrix(int** Matrix, int Size) {
    int Number;
    cout << '\n' << "Введите число" << '\n';
    cin >> Number;
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            Matrix[i][j] /= Number;
    PrintMatrix(Matrix, Size);
}

void PrintMenu() {
    system("cls");
    cout << "Что выхотите сделать?" << '\n';
    cout << "1. Заполнить матрицу новыми числами" << '\n';
    cout << "2. Переставить блоки матрицы" << '\n';
    cout << "3. Отсортировать матрицу" << '\n';
    cout << "4. Увеличить матрицу на число" << '\n';
    cout << "5. Уменьшить матрицу на число" << '\n';
    cout << "6. Умножить матрицу на число" << '\n';
    cout << "7. Поделить матрицу на число" << '\n';
    cout << "8. Выйти из программы" << '\n';
}

void Menu(int** Matrix, int Size) {
    int Variant;
    system("pause");
    do {
        PrintMenu();
        cin >> Variant;
        switch (Variant) {
        case 1:
            char perm;
            cout << "В каком виде вывести матрицу?(a или b)" << '\n';
            cin >> perm;
            while (perm != 'a' and perm != 'b') {
                cout << "Неверно введён вид вывода, попробуйте снова: ";
                cin >> perm;
            }
            if (perm == 'a')
                SpiralMatrix(Matrix, Size);
            else
                SnakeMatrix(Matrix, Size);
            break;
        case 2:
            PrintMatrix(Matrix, Size);
            cout << '\n' << "Смена блоков" << '\n';
            RotateMatrix(Matrix, Size);
            break;
        case 3:
            cout << '\n' << "Отсортированный массив" << '\n';
            SortMatrix(Matrix, Size);
            break;
        case 4:
            PrintMatrix(Matrix, Size);
            MagnificationMatrix(Matrix, Size);
            break;
        case 5:
            PrintMatrix(Matrix, Size);
            ReducationMatrix(Matrix, Size);
            break;
        case 6:
            PrintMatrix(Matrix, Size);
            MultiplicationMatrix(Matrix, Size);
            break;
        case 7:
            PrintMatrix(Matrix, Size);
            DivisionMatrix(Matrix, Size);
            break;
        }
        if (Variant != 8)
            system("pause");
    } while (Variant != 8);
}

int main() {
    setlocale(0, "");
    srand(time(0));
    int Size;
    cout << "Введите размер матрицы: 6 или 8 или 10:" << "\n";
    cin >> Size;
    while (Size != 6 and Size != 8 and Size != 10) {
        cout << "Неверно введён размер матрицы, попробуйте снова: ";
        cin >> Size;
    }
    int** Matrix = new int* [Size];
    for (int i = 0; i < Size; i++)
        Matrix[i] = new int[Size];
    Menu(Matrix, Size);
}

