#include <algorithm>
#include <iostream>
#include <string>


int main()
{
    using namespace std;

    string PlayerInput;

    cout << "Put your string and press <Enter>\n";

    getline(cin, PlayerInput);
    transform(PlayerInput.begin(), PlayerInput.end(), PlayerInput.begin(), ::tolower);

    int const CountOfIteration = PlayerInput.length();

    for (int i = 0; i <= CountOfIteration; i++)
    {
        if (PlayerInput[i] == ')')
        {
            continue;
        }

        char const CurrentCharacter = PlayerInput[i];

        for (int subi = i + 1; subi <= CountOfIteration; subi++)
        {
            if (CurrentCharacter == PlayerInput[subi])
            {
                PlayerInput[i] = ')';
                PlayerInput[subi] = ')';
            }
        }

        if (PlayerInput[i] == ')')
        {
            continue;
        }

        PlayerInput[i] = '(';
    }

    cout << PlayerInput;
}

