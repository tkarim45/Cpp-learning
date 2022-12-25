#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
    if (printTop)
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();

    if (printBottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}
void DrawHangman(int guessCount = 0)
{
    if (guessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 4)
        PrintMessage("/  ", false, false);

    if (guessCount == 5)
        PrintMessage("/| ", false, false);

    if (guessCount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 7)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 8)
        PrintMessage("/", false, false);

    if (guessCount >= 9)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);
}
void PrintLetters(string input, char from, char to)
{
    string s;
    for (char i = from; i <= to; i++)
    {
        if (input.find(i) == string::npos)
        {
            s += i;
            s += " ";
        }
        else
            s += "  ";
    }
    PrintMessage(s, false, false);
}
void PrintAvailableLetters(string taken)
{
    PrintMessage("Available letters");
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}
bool PrintWordAndCheckWin(string word, string guessed)
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}
string LoadRandomWord(string path)
{
    int lineCount = 0;
    string word;
    vector<string> v;
    ifstream reader(path);
    if (reader.is_open())
    {
        while (std::getline(reader, word))
            v.push_back(word);

        int randomLine = rand() % v.size();

        word = v.at(randomLine);
        reader.close();
    }
    return word;
}
int TriesLeft(string word, string guessed)
{
    int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}
int main()
{
    srand(time(0));
    string guesses;
    string wordToGuess;
    wordToGuess = LoadRandomWord("words.txt");
    int tries = 0;
    bool win = false;
    do
    {
        system("cls"); //replace this line with system("clear"); if you run Linux or MacOS
        PrintMessage("HANGMAN");
        DrawHangman(tries);
        PrintAvailableLetters(guesses);
        PrintMessage("Guess the word");
        win = PrintWordAndCheckWin(wordToGuess, guesses);

        if (win)
            break;

        char x;
        cout << ">"; cin >> x;

        if (guesses.find(x) == string::npos)
            guesses += x;

        tries = TriesLeft(wordToGuess, guesses);

    } while (tries < 10);

    if (win)
        PrintMessage("YOU WON!");
    else
        PrintMessage("GAME OVER");

    system("pause"); //this line wont work on Linux or MacOS so remove it
    getchar();
    return 0;
}
/*
+---------------------------------+
|             HANG MAN            |
+---------------------------------+
|               |                 |
|               |                 |
|               O                 |
|              /|\                |
|               |                 |
|              / \                |
|         +----------+            |
|         |          |            |
+---------------------------------+
|        Available letters        |
+---------------------------------+
|     A B C D E F G H I J K L M   |
|     N O P Q R S T U V W X Y Z   |
+---------------------------------+
|         Guess the word          |
+---------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+---------------------------------+
>
*/