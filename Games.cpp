#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int S = 10, M = 15;

void playMinesweeper() {
    std::vector<std::vector<char>> b(S, std::vector<char>(S, '-'));
    std::vector<std::vector<bool>> m(S, std::vector<bool>(S, false));
    int pm = 0, r, c;

    while (pm < M) {
        r = std::rand() % S; c = std::rand() % S;
        if (!m[r][c]) { m[r][c] = true; pm++; }
    }

    while (true) {
        std::cout << "   ";
        for (int i = 0; i < S; i++) std::cout << i << " ";
        std::cout << "\n";
        for (int i = 0; i < S; i++) {
            std::cout << i << " | ";
            for (int j = 0; j < S; j++) std::cout << b[i][j] << " ";
            std::cout << "|\n";
        }

        std::cout << "Введіть рядок і стовпець: ";
        if (!(std::cin >> r >> c) || r < 0 || r >= S || c < 0 || c >= S) {
            std::cin.clear(); std::cin.ignore(10000, '\n'); continue;
        }

        if (m[r][c]) {
            std::cout << "БУМ! Гра закінчена.\n"; break;
        }

        int count = 0;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (r+i >= 0 && r+i < S && c+j >= 0 && c+j < S && m[r+i][c+j]) count++;
        
        b[r][c] = count + '0';

        bool win = true;
        for (int i = 0; i < S; i++)
            for (int j = 0; j < S; j++)
                if (!m[i][j] && b[i][j] == '-') win = false;

        if (win) { std::cout << "Перемога!\n"; break; }
    }
}

void playRPS() {
    std::cout << "--- Гра: Камінь, Ножиці, Папір ---\n";
    std::cout << "Введіть ваш вибір (1 - Камінь, 2 - Ножиці, 3 - Папір): ";
    int p;
    if (!(std::cin >> p) || p < 1 || p > 3) {
        std::cout << "Неправильний вибір! Будь ласка, виберіть 1, 2 або 3.\n";
        std::cin.clear(); std::cin.ignore(10000, '\n');
        return;
    }

    int cc = std::rand() % 3 + 1;
    std::cout << "Комп'ютер вибрав: " << (cc == 1 ? "Камінь" : cc == 2 ? "Ножиці" : "Папір") << "\n";

    if (p == cc) std::cout << "Нічия!\n";
    else if ((p == 1 && cc == 2) || (p == 2 && cc == 3) || (p == 3 && cc == 1)) 
        std::cout << "Ви перемогли! Здається, фортуна на вашому боці. 🎉\n";
    else 
        std::cout << "Ви програли. Комп'ютер виявився хитрішим! 🤖\n";
}

int games() {
    std::setlocale(LC_ALL, "Ukrainian");
    std::srand(std::time(0));
    int choice;

    while (true) {
        std::cout << "\n1.Сапер 2.КНП 3.Вихід: ";
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
        if (choice == 1) playMinesweeper();
        else if (choice == 2) playRPS();
        else if (choice == 3) break;
    }
    return 0;
}