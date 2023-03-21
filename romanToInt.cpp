#include <string>
#include <iostream>

using namespace std;

bool numeralToBeSubtracted(char c, char r) {
    if (c == 'I')
        return (r == 'V') || (r == 'X');
    else if (c == 'X')
        return (r == 'L') || (r == 'C');
    else if (c == 'C')
        return (r == 'D') || (r == 'M');

    return false;
}

int romanCharToInt(char c)
{
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else if (c == 'M')
        return 1000;

    return 0;        
}

int romanToInt(string s) {
    int intForm = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (numeralToBeSubtracted(s[i], s[i+1]))
            intForm -= romanCharToInt(s[i]);
        else
            intForm += romanCharToInt(s[i]);
    }

    return intForm;
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        cout << "Usage: RomanToInt <Roman Numeral>\n"
             << "Does not perform sanity check\n";

        return EXIT_FAILURE;
    }

    string romanNumber = string(argv[1]);
    int val = romanToInt(romanNumber);

    cout << val << endl;

    return EXIT_SUCCESS;
}
