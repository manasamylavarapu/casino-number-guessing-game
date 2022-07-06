//CASINO NUMBER GUESSING GAME
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

void rules()
{
    cout << "*****CASINO NUMBER GUESSING RULES!*****\n";
    cout << "Choose a number between 1 to 10\n";
    cout << "Winner gets 10 times of the money bet\n";
    cout << "If wrong bet, you lose the amount you bet\n";
}

int main()
{
    string PlayerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;
    srand(time(0));

    cout << "*****WELCOME TO THE CASINO WORLD!*****";
    cout << "Enter your name: ";
    getline(cin, PlayerName);
    cout << "Enter the starting balance you want to play the game with: $\n\n";
    cin >> balance;

    do
    {

        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";

        do
        {
            cout << "Hi! " << PlayerName << ", enter the amount to bet: $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
            {
                cout << "Betting amount can not be more than the current balance!\n"
                  << "\n RE-ENTER THE BALANCE\n";
        }while(bettingAmount > balance);

        do
        {
        cout << "Guess any number between 1 to 10: ";
        cin >> guess;
        if(guess <= 0 || guess > 10)
        {
            cout << "\nNumber should be between 1 to 10\n"
                 << "RE-ENTER THE NUMBER\n";
        }
        }while(guess <=0 || guess > 10);

        dice = (rand()%10)+1;

        if(guess == dice)
        {
            cout << "\nWHOO!!! You have won $"<< bettingAmount*10;
            balance = balance + bettingAmount*10;

        }
        else
        {
            cout << "OOPS, Better luck nexttime!! You have lost $" << bettingAmount;
            balance = balance - bettingAmount;
        }

        cout << "\nThe winning number was : "<< dice<<"\n";
        cout << "\n"<<PlayerName<< ", You have a balance amount of $"<< balance<< "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
        }

        cout << "\nDo you want to play again (y/n)? ";
        cin >> choice;
    }while(choice == 'Y' || choice =='y');

    cout << "\n\n\nThanks for playing the game. Your balance is $ "<< balance<<"\n\n";
    return 0;

}
