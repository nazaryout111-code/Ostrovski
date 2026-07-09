#ifndef GAMES_H
#define GAMES_H

// Глобальні константи для Сапера
const int S = 10; // Розмір поля (S x S)
const int M = 15; // Кількість мін

/**
 * @brief Запускає гру "Сапер" (Minesweeper) у консолі.
 */
void playMinesweeper();

/**
 * @brief Запускає гру "Камінь, Ножиці, Папір" (RPS).
 */
void playRPS();

/**
 * @brief Головне меню для вибору ігор.
 * @return Повертає 0 при успішному завершенні.
 */
int games();

#endif // GAMES_H
