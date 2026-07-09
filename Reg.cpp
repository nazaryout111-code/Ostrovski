#include <iostream>

using namespace std;

struct Login {
     string login;
     string password;
};

int paswword() {
    setlocale(LC_ALL, "RU");
    
    string a, b, c, d;
    Login player;
    
    cout << "Введіть логін для реєстрації: ";
    cin >> a;
    player.login = a;
    
    cout << "Введіть пароль для реєстрації: ";
    cin >> b;
    player.password = b;
    
    cout << "Дякуємо за реєстрацію акаунта! Будь ласка, увійдіть в нього." << endl;
    
    Login proverka;
    
    cout << "Введіть логін для входу: ";
    cin >> c;
    proverka.login = c;
    
    cout << "Введіть пароль для входу: ";
    cin >> d;
    proverka.password = d;
    
    try {
        if (player.login == proverka.login && player.password == proverka.password) {
            cout << "Успішний вхід! Вітаємо в системі." << endl;
        } else {
            throw 404; 
        }
    }
    catch (int error) {
        cout << "КРИТИЧНА ПОМИЛКА " << error << ": Невірний логін або пароль! Спроба зламу!" << endl;
    }
    
    return 0;
}
