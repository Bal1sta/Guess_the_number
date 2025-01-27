#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// функция, которая дает подсказки пользователю
void giveHint(int guess, int secretNumber) {
    if(guess < secretNumber) {
        std::cout << "Число меньше случайного числа. Попробуй еще раз" << std::endl;
    }

    else if(guess > secretNumber) {
        std::cout << "Число больше случайного числа. Попробуй еще раз" << std::endl;
    }
}

// функция, которая запускает игру
void startGame(int maxAttemps) {
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int attempt = 0;
    
    std::cout << "Я загадал число от 1 до 100. Попробуйте угадать его!" << std::endl;
    while(guess != secretNumber and attempt < maxAttemps) {
        std::cout << "Введите любое целое число: " << std::endl;
        std::cin >> guess;

        attempt++;

        giveHint(guess, secretNumber);
    }

    if(guess == secretNumber) {
        std::cout << "Поздравляю, вы угадали число: " << secretNumber << " за " << attempt << " попыток." << std::endl;
    }
    else {
        std::cout << "Вы проиграли!" << std::endl;
    }
}

int main(){
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    int maxAttemps = 5;

    do{
        std::cout << "Выберите уровень сложности:\n1. Легкий (10 попыток)\n2. Средний (5 попыток)\n3. Сложный (3 попытки)\n4. Выход\n";
        int difficulty;
        std::cin >> difficulty;

        switch (difficulty)
        {
        case 1:
            maxAttemps = 10;
            break;
        case 2:
            maxAttemps = 5;
            break;
        case 3:
            maxAttemps = 3;
            break;
        case 4:
            return 0;
        default:
            std::cout << "Неверный выбор, установлены стандартные 5 попыток." << std::endl;
            break;
        }

        startGame(maxAttemps);

    } while (true);
    
    return 0;
}