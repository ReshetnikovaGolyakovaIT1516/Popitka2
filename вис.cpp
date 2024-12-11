#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include "Windows.h"
#include "Header.h"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string words[] = { "программист", "алгоритм", "компьютер", "виселица", "разработка", "яблоко", "груша", "стол", "программа", "интернет", "телефон", "процессор", "ламинария" };
    srand(time(0));
    string word = words[rand() % (sizeof(words) / sizeof(words[0]))];

    int maxAttempts = 6; // Максимальное количество попыток
    int attempts = 0; // Количество неверных попыток
    string guessed; // Строка для хранения угаданных букв

    cout << "Добро пожаловать в игру Виселица!" << endl;

    // Основной цикл игры
    while (attempts < maxAttempts)
    {
        displayState(word, guessed); // Показываем текущее состояние слова

        cout << "Введите букву: ";
        char guess;
        cin >> guess;
        if (!isLetter(guess)) {
            cout << "Ошибка: Введите только буквы!" << endl;
            continue; // Запрос нового ввода
        }

        // Приводим введенный символ к нижнему регистру
        guess = tolower(guess);
        if (!checkGuess(guess, word, guessed, attempts)) // была ли буква угадана 
        {
            cout << "Неправильно! Осталось попыток: " << (maxAttempts - attempts) << endl;
        }
        else
        {
            cout << "Верно!" << endl;
        }

        // Проверка, угадано ли все слово
        bool wordGuessed = true;
        for (char c : word)
        {
            bool found = false;
            for (char g : guessed)
            {
                if (c == g)
                {
                    found = true; // Буква найдена в угаданных
                    break;
                }
            }
            if (!found)
            {
                wordGuessed = false; // Если хотя бы одна буква не найдена, слово не угадано
                break;
            }
        }

        if (wordGuessed)
        {
            cout << "Поздравляем! Вы угадали слово: " << word << endl;
            break;
        }
    }

    if (attempts == maxAttempts)
    {
        cout << "Вы проиграли! Загаданное слово было: " << word << endl;
    }

    return 0;
}

