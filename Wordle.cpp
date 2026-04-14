#include<macros.hpp>

class wordle
{
    string word;

    void ran()
    {
        ifstream f{"data.csv"};
        if (!f)
        {
            cerr << "File could not be loaded\n";
            exit(1);
        }
        srand(time(0));

        int randomNumber = (rand() % NumberOfWords) + 1;
        int i = randomNumber;
        string randomWord;
        while (f >> randomWord && i--)
        {
        }
        word = randomWord;
    }

    string numberToString(int num)
    {
        if (num == 1)
            return "first";
        if (num == 2)
            return "second";
        if (num == 3)
            return "third";
        if (num == 4)
            return "fourth";
        if (num == 5)
            return "fifth";
        return "unknown";
    }

    // bool operator==(char l, char r){
    //     if(!((l >= 'A' && l <= 'Z')||(l >= 'a' && l <= 'z'))) return 0;
    //     if(l == r) return 1;
    //     if(l+'A'-'a' == r) return 1;
    //     if(l-'A'+'a' == r) return 1;
    //     return 0;
    // }

    bool equal(char l, char r)
    {
        if (!((l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z')))
            return 0;
        if (l == r)
            return 1;
        if (l + 'A' - 'a' == r)
            return 1;
        if (l - 'A' + 'a' == r)
            return 1;
        return 0;
    }

public:
    void gameInterface()
    {
        cout << "Welcome to Wordle!\n";
        cout << "\n\nEnter 'y' if you want to play Wordle and 'n' to exit: ";

        char resp;
        cin >> resp;
        if (resp == 'n' || resp == 'N')
        exit(0);
        cout << "Rules are:"
                "\n1. You have 5 lives to guess the word."
                "\n2. After each guess, you will receive feedback.\n"
                "   if your entered alphabet appears to be green it is in word and at correct position.\n"
                "   And if it is yellow it is in word but not at this position"
                "\n3. Good luck!\n";
        while (true)
        {
            cout << word;
            int i;
            ran(); // to make word

            for (i = 1; i <= tries; i++)
            {
                string guess;

                cout << setw(20) << "This is your " << numberToString(i) << " try at guessing\n";
                cout << "Enter your guess: ";
                cin >> guess;
                if (guess == word)
                {
                    cout << "Congratulations! You guessed the word: " << "\033[32m" << word << "\033[0m" << endl; break;
                }
                else
                {
                    int i, j;
                    for (j = 0; j < wordSize; j++)
                    {
                        for (i = 0; i < wordSize; i++)
                        {
                            if (equal(guess[j], word[i]))
                            {
                                break;
                            }
                        }
                        if(i < wordSize && j < wordSize){
                            if (equal(guess[j], word[i]))
                            {
                                if (i == j)
                                    cout << "\033[32m" << word[i] << "\033[0m";
                                else
                                    cout << "\033[33m" << word[i] << "\033[0m";
                            }
                        }
                        else
                        {
                            cout << guess[j];
                        }
                    }
                    cout << '\n';
                    continue;
                }
            }
            if(i == tries + 1){
                cout << "You've run out of tries! The word was: " << "\033[31m" << word << "\033[0m" << endl;
            }
            cout << "Do you wish to play again?\n"
                    "Press 'y' to play again\n"
                    "Press 'n' to exit\n"
                    "Press 'r' to display rules again\n";
            cin >> resp;
            if (resp == 'n' || resp == 'N')
            {
                cout << "Exiting\n";
                exit(0);
            }
            if (resp == 'r' || resp == 'R')
            {
                cout << "Rules are:"
                        "\n1. You have 5 lives to guess the word."
                        "\n2. After each guess, you will receive feedback.\n"
                        "if your entered alphabet appears to be green it is in word and at correct position.\n"
                        "And if it is yellow it is in word but not at this position\n"
                        "\n3. Good luck!\n";
            }
        }
    }
    wordle()
    {
        gameInterface();
    }
};

int main()
{
    wordle w;
    return 0;
}