#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include "Windows.h"
using namespace std;
// Функция для отображения состояния игры
void displayState(const string& word, const string& guessed)
{
    for (char c : word)
    {
        bool found = false;
        for (char g : guessed)
        {
            if (c == g)
            {
                found = true; // Буква найдена среди угаданных
                break;
            }
        }
        if (found)
        {
            cout << c << " "; // Если буква угадана, показываем её
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}
// Функция для проверки буквы
bool checkGuess(char guess, const string& word, string& guessed)
{
    // Проверяем, была ли уже угадана буква
    for (char g : guessed)
    {
        if (g == guess)
        {
            return false; // Буква уже угадана
        }
    }

    // Добавляем букву в строку угаданных букв
    guessed += guess;

    // Проверяем, есть ли буква в слове
    for (char c : word)
    {
        if (c == guess)
        {
            return true;
        }
    }

    return false;
}
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
        if (!isalpha(guess)) {
            cout << "Ошибка: Введите только буквы!" << endl;
            continue; // Запрос нового ввода
        }

        // Приводим введенный символ к нижнему регистру
        guess = tolower(guess);

        // Проверяем, была ли буква угадана
        if (!checkGuess(guess, word, guessed))
        {
            attempts++;
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

