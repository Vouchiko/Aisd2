#include <stdio.h>
#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <complex>




int get_key() {
    int key = _getch();
    if ((key == 0) || (key == 224))
        key = _getch();
    return key;
}

int menu1() {
    std::cout << "\nMatrix Class.\n\n"
        "1 - View/edit the studied matrices.\n"
        "2 - Matrix Addition(+)\n"
        "3 - Matrix difference(-)\n"
        "4 - multiplication matrix(*)\n"
        "5 - Multiplying a matrix by a scalar\n"
        "6 - Dividing a matrix by a scalar\n"
        "7 - Calculating the trace of the matrix\n"
        "8 - Matrix Comparison\n"
        "9 - Access to an element in matrix A by index\n\n"
        "0 - Solution_of_the_equation A*x = B\n\n"
        "Exit: Esc";


    while (true) {
        int key = get_key();
        if ((key == 27) || (key >= '0' && key <= '9'))
            return key;
    }
}

int menu2() {
    std::cout << "\n\n";
    std::cout << "Resume: Enter";
    while (true) {
        int key = get_key();
        if (key == 13) return key;
    }
}

int menu3() {
    std::cout << "1 - Yes\n2 - No";
    while (true) {
        int key = get_key();
        if (key == '1' || key == '2') return key;
    }
}

bool double_control(char* xn)
{
    char* tmp = xn;
    int zap_p = 0;
    const char mask[] = ".-1234567890";
    int checker = 0;
    while (*tmp) {
        if (strchr(mask, *tmp)) checker++;
        tmp++;
    }
    if (checker != strlen(xn))
        return false;
    if (checker == 0)
        return false;

    if (*xn == '-' && *(xn + 1) == '\0')
        return false;
    if ((*xn == ','))
        return false;

    tmp = xn;
    while (*tmp) {
        if ((*tmp == ','))
            zap_p++;
        if ((*(tmp + 1) == '-') || (*tmp == '\0'))
            return false;
        tmp++;
    }
    if (zap_p > 1) return false;
    return true;
}

double double_checker() {
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = double_control(n_data);
        if (check == true) break;
        else {
            cout << "  Invalid sitax! Try again: ";
        }
    }
    double data = (double)atof(n_data);
    return data;
}


double zero_checker() {
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = double_control(n_data);
        if (check == true and (double)atof(n_data) != 0) break;
        else {
            cout << "  Invalid sitax! Division by zero is not possible. Try again: ";
        }
    }
    double data = (double)atof(n_data);
    return data;
}
bool int_control(char* xn)
{
    char* tmp = xn;
    int zap_p = 0;
    const char mask[] = "-1234567890";
    int checker = 0;
    while (*tmp) {
        if (strchr(mask, *tmp)) checker++;
        tmp++;
    }
    if (checker != strlen(xn))
        return false;
    if (checker == 0)
        return false;

    if (*xn == '-' && *(xn + 1) == '\0') {
        return false;
    }
    if ((*xn == ','))
        return false;

    tmp = xn;
    while (*tmp) {
        if ((*tmp == ',')) {
            zap_p++;
        }
        if ((*(tmp + 1) == '-') || (*tmp == '\0')) {
            return false;
        }
        tmp++;
    }
    if (zap_p > 1) return false;
    return true;
}

int int_checker() {
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = int_control(n_data);
        if (check == true) break;
        else {
            printf("  Invalid sitax! Try again: ");
        }
    }
    int data = (int)atoi(n_data);
    return data;
}

template <class T>
int menu()
{
    Matrix<T> A(3, 3), B(3, 3), b(3, 1), D(3, 3);
    //Matrix A
    A(0, 0) = 3;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 2;
    A(1, 2) = 4;
    A(2, 0) = 1;
    A(2, 1) = 2;
    A(2, 2) = 3;
    //Matrix B
    B(0, 0) = 3;
    B(0, 1) = 2;
    B(0, 2) = 3;
    B(1, 0) = 4;
    B(1, 1) = 2;
    B(1, 2) = 4;
    B(2, 0) = 1;
    B(2, 1) = 6;
    B(2, 2) = 3;
    // Vector b
    b(0, 0) = 1;
    b(1, 0) = 2;
    b(2, 0) = 3;
    while (true)
    {
        system("cls");
        int m1 = menu1();
        switch (m1) {
        case 27: return 0;
        case '1': {
            system("cls");
            std::cout << "\tInvestigated matrices:\n\n";
            std::cout << "A:\n" << A << endl;
            std::cout << "B:\n" << B;
            std::cout << "\n\nDo you want to change the matrices?" << endl;
            int m3 = menu3();
            switch (m3) {
            case '1': {
                try {
                    system("cls");
                    std::cout << "\n--------Setting the matrix A--------" << endl;
                    A.EnterMatrix();

                    std::cout << "\n--------Setting the matrix B--------" << endl;
                    B.EnterMatrix();

                    break;
                }
                catch (const char* message) {
                    std::cout << message;
                }
            }
            case 50: {
                break;
            }
            }
            break;
        }
        case '2': {
            system("cls");
            std::cout << "\tMatrix Addition.\n\n";
            bool check = 0;
            try {
                D = A + B;
                check = 1;
            }
            catch (const char* message) {
                std::cout << message;
            }
            if (check) {
                std::cout << "A + B:\n\n" << endl;
                std::cout << A << "\n +\n\n" << B << "\n = \n\n";
                std::cout << A + B;
            }
            break;
        }
        case '3': {
            system("cls");
            std::cout << "\tMatrix difference.\n\n";
            bool check = 0;
            try {
                D = A - B;
                check = 1;
            }
            catch (const char* message) {
                std::cout << message;
            }
            if (check) {
                D = A - B;
                std::cout << "A - B:\n\n" << endl;
                std::cout << A << "\n -\n\n" << B << "\n = \n\n";
                std::cout << D;
            }
            break;
        }
        case '4': {
            system("cls");
            std::cout << "\tmultiplication matrix.\n\n";
            bool check = 0;
            try {
                D = A * B;
                check = 1;
            }
            catch (const char* message) {
                std::cout << message;
            }
            if (check) {
                D = A * B;
                std::cout << "A * B:\n\n" << endl;
                std::cout << A << "\n *\n\n" << B << "\n = \n\n";
                std::cout << D;
            }
            break;
        }
        case '5': {
            system("cls");
            std::cout << "\tMultiplying a matrix by a scalar.\n\n";
            double a;
            std::cout << "Enter a value (scalar): ";
            std::cin >> a;
            std::cout << "A * a:\n\n" << endl;
            std::cout << A << "\n *\n\n " << a << "\n\n = \n\n";
            D = a * A;
            std::cout << D;
            break;
        }
        case '6': {
            system("cls");
            std::cout << "\tDividing a matrix by a scalar.\n\n";
            double a;
            std::cout << "Enter a value (scalar): ";
            std::cin >> a;
            std::cout << "A \ a:\n\n" << endl;
            std::cout << A << "\n /\n\n " << a << "\n\n = \n\n";
            if (a == 0)
                std::cout << "invalid syntax, division by zero is not possible" << endl;
            else {
                D = A / a;
                std::cout << D;
            }
            break;
        }
        case '7': {
            system("cls");
            std::cout << "\tCalculating the trace of the matrix.\n\n";
            std::cout << "Tr(A) = " << A.tr();
            break;
        }
        case '8':
        {
            system("cls");
            std::cout << "Matrix Comparison.\n Enter epsilon: " << endl;
            std::cin >> A.epsilon;
            if (A == B) {
                std::cout << "A == B\n";
            }
            else {
                std::cout << "A!=B\n";
            }
            break;
        }

        case '9':
        {
            try {
                system("cls");
                std::cout << "Access to an element in matrix A by index." << endl;
                std::cout << "enter the row: ";
                int x = int_checker();
                std::cout << "\nenter the column: ";
                int y = int_checker();
                std::cout << "\nthe value of the element: " << A(x, y);
                std::cout << "\nDo you want to change ellement?\n";


                int m3 = menu3();
                switch (m3) {
                case 49: {
                    system("cls");
                    cout << "Enter the value: ";
                    A(x, y) = double_checker();
                    break;
                }
                case 50: {
                    break;
                }
                       break;
                }

            }
            catch (const char* message) {
                std::cout << message;
            }
            break;
        }

        case'0': {
            system("cls");
            std::cout << "Solution_of_the_equation A*x = B" << endl;
            std::cout << "X = " << endl;
            std::cout << A.Solution_of_the_equation(B);
        }
        }
        while (true) {
            int m2 = menu2();
            if (m2 == 13) break;
        }
    }
    return 0;
}

int main()
{

    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool exit = true;
    while (exit) {
        cout << "Здравствуйте! Вас приветствует программа \"МНОГО МАТРИЦ\"\n" << endl;
        cout << "Нажмите:" << endl;
        cout << "1 - чтобы работать с типом int" << endl;
        cout << "2 - чтобы работать с типом double" << endl;
        cout << "3 - чтобы работать с типом float" << endl;
        cout << "4 - чтобы работать с типом complex-double" << endl;
        cout << "5 - чтобы работать с типом complex-float" << endl;
        cout << "0 - чтобы завершить работу" << endl;

        int key = get_key();

        switch (key)
        {
        case 49:
            menu<int>();
            break;
        case 50:
            menu<double>();
            break;
        case 51:
            menu<float>();
            break;
        case 52:
            menu<complex<double>>();
            break;
        case 53:
            menu<complex<float>>();
            break;
        case 48:
            exit = false;
            break;
        default:
            break;
        }

    }

    return 0;
}