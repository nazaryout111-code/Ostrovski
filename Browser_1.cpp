#include <iostream>
#include <string>

int browser() {
    std::string command;

    while (true) {
        std::cout << "Введіть команду: ";
        std::cin >> command;

        if (command == "open.browser") {
            std::system("firefox &");
        } else if (command == "exit") {
            break;
        }
    }
    return 0;
}