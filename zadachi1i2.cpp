#include <iostream>
using namespace std;


static void revString() //функция за обърщане на string
{
    string str = "It's lights out and away we go";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
}
static void isPalindrome() { //функция за проверка дали думата е палиндром
    string strP;
    cout << "Enter a string: ";
    cin >> strP;
    bool is_palindrome = true;
    int n = strP.length();
    for (int i = 0; i < n / 2; i++) {
        if (strP[i] != strP[n - i - 1]) {
            is_palindrome = false;
            continue;
        }
    }
    if (is_palindrome) {
        cout << "The string is a palindrome." << endl;
    }
    else {
        cout << "The string is not a palindrome." << endl;
    }
}


int main()
{
    int choice = 0;
    while (true) { //предотвраява програмата от затваряне след избрана функция
        cout << "Select a function by typing its number:\n 1. Reverse the string\n 2. Check if palindrome\n 3. Exit\n";
        cin >> choice;
        try {
            if (choice == 1) {
                revString();
            }
            else if (choice == 2) {
                isPalindrome();
            }
            else if (choice == 3) {
                break;
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // предотвратява безкраен loop при въведен грешен тип данни
            }
        }
        catch (exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
        
    }
    return 0;
    
}
