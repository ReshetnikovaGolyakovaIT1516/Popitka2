#include <string>
void displayState(const string & word, const string & guessed);
bool checkGuess(char guess, const string& word, string& guessed, int& attempts);
bool isLetter(char c);
