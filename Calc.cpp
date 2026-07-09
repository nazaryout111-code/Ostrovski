#include <iostream>
#include <limits>

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    setlocale(LC_ALL, "Russian");

    double total = 0;
    double nextNum;
    char operation;

    cout << "=== Калькулятор 1.0 BETA ===" << endl;
    cout << "Введите начальное число: ";
    while (!(cin >> total)) {
        cout << "Ошибка! Введите корректное число: ";
        clearInput();
    }

    while (true) {
        cout << "Введите операцию (+, -, *, /) или '=' для результата: ";
        cin >> operation;

        if (operation == '=') {
            cout << "-----------------------------------" << endl;
            cout << "Итоговый результат: " << total << endl;
            cout << "-----------------------------------" << endl;
            break;
        }

        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            cout << "Ошибка: Неизвестная операция!" << endl;
            continue;
        }

        cout << "Введите следующее число: ";
        while (!(cin >> nextNum)) {
            cout << "Ошибка! Введите корректное число: ";
            clearInput();
        }

        switch (operation) {
            case '+':
                total += nextNum;
                break;
            case '-':
                total -= nextNum;
                break;
            case '*':
                total *= nextNum;
                break;
            case '/':
                if (nextNum == 0) {
                    cout << "Ошибка: Деление на ноль! Число пропущено." << endl;
                } else {
                    total /= nextNum;
                }
                break;
        }
        
        cout << "[Текущий результат: " << total << "]" << endl;
    }

    return 0;
}