#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include "Windows.h"
#include "Header.h"
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
bool checkGuess(char guess, const string& word, string& guessed, int& attempts)
{
    // Проверяем, была ли уже угадана буква
    for (char g : guessed)
    {
        if (g == guess)
        {
            cout << "Эта буква уже была угадана: " << guess << endl;
            return false;
        }
    }

    // Добавляем букву в строку угаданных букв
    guessed += guess;
    bool found = false;
    // Проверяем, есть ли буква в слове
    for (char c : word)
    {
        if (c == guess)
        {
            found = true;
            break;
        }
    }
    if (!found) // Если буква не найдена в слове
    {
        attempts++; // Увеличиваем кол-во попыток если буква не была угадана
    }
    return found;
}
bool isLetter(char c)
{
    return (c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я');  // Для русских букв
}