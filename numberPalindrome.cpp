#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int x) {
    int log10Approx = (int)log10((double)x);
    int num = x;

    int div, res;
    int reversed = 0;

    while (log10Approx >= 0) {
        res = num % 10;
        num = num / 10;
        reversed += pow(10, log10Approx) * res;
        log10Approx--;
    }

    return x == reversed;
}

int main()
{
    if(isPalindrome(818))
        cout << "Palindrome\n";
    else
        cout << "Not a palindrome\n";

    return 0;
}
