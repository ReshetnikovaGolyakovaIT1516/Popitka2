#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include "Windows.h"
#include "Header.h"
using namespace std;

// ������� ��� ����������� ��������� ����
void displayState(const string& word, const string& guessed)
{
    for (char c : word)
    {
        bool found = false;
        for (char g : guessed)
        {
            if (c == g)
            {
                found = true; // ����� ������� ����� ���������
                break;
            }
        }
        if (found)
        {
            cout << c << " "; // ���� ����� �������, ���������� �
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}
// ������� ��� �������� �����
bool checkGuess(char guess, const string& word, string& guessed, int& attempts)
{
    // ���������, ���� �� ��� ������� �����
    for (char g : guessed)
    {
        if (g == guess)
        {
            cout << "��� ����� ��� ���� �������: " << guess << endl;
            return false;
        }
    }

    // ��������� ����� � ������ ��������� ����
    guessed += guess;
    bool found = false;
    // ���������, ���� �� ����� � �����
    for (char c : word)
    {
        if (c == guess)
        {
            found = true;
            break;
        }
    }
    if (!found) // ���� ����� �� ������� � �����
    {
        attempts++; // ����������� ���-�� ������� ���� ����� �� ���� �������
    }
    return found;
}
bool isLetter(char c)
{
    return (c >= '�' && c <= '�') || (c >= '�' && c <= '�');  // ��� ������� ����
}