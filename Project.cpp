#include <limits>
#include <iostream>
#include <string>
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
 
void drawLine(int, char);
void rules();
 
int main()
{
    string playerName;
    float balance; // hold player's balance
    float bettingAmount; 
    int guess;
    int dice; // hold computer generated number
    char choice;
 
    srand(time(0)); // "Seed" the random generator

    drawLine(105,'_');
    cout << "\n\n\n\n\t\t\t\t\t\tCASINO GAME\n\n\n\n";
    drawLine(105,'_');
 
    cout << "\n\nEnter Your Name : ";
    cin >> playerName;
 
    cout << "\n\nEnter Deposit Balance to Play Game : $";
    cin >> balance;
    
    do
    {
        rules();
        cout << "\n\nYour Current Balance is $" << balance << "\n";
		
		// Get player's betting amount
        GetAmount:
            do
            {
                cout <<playerName<<", Enter Money to Bet : $";
                cin >> bettingAmount;
                
                if(bettingAmount > balance)
                    cout << "Your Betting Amount is More Than Your Current Balance\n"
                         <<"\nRE-ENTER DATA:\n";
            } while(bettingAmount > balance);
            
            if (bettingAmount == 0)
            {
                cout << "Betting Amount Should Not be ZERO."
                <<"\nRE-ENTER DATA:\n";
                goto GetAmount;
            }
        
 
		// Get player's guess
        do
        {
            cout << "Guess Your Number to Bet Between 1 and 10 : ";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please Check The Number!! It Should be Between 1 and 10\n"
                     <<"\nRE-ENTER DATA:\n";
        } while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1; // Will hold the computer generated integer between 1 and 10
    
        if(dice == guess)
        {
            cout << "\n\nCONGRATULATIONS!! You Won $" << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else if(dice == guess + 1 || dice == guess - 1)
        {
            balance = balance  - bettingAmount;
            cout << "\n\nIt was a Close Guess. Half of The Betting Amount is Refunded.";
            balance = balance + bettingAmount / 2;
        }
        else
        {
            cout << "\n\nBad Luck This Time !! You Lost $"<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
 
        cout << "\nTHE Winning Number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", Your New Balance is $" << balance << "\n";
        if(balance == 0)
        {
            cout << "You Have No Money to Play ";
            break;
        }
        cout << "\n\n-->Press \"Y\" if you want to play again! ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(105,'=');
    cout << "\n\n\t\t\tThanks for Playing Game. Your Balance is $" << balance << "\n\n\n";
    drawLine(105,'=');
 
    return 0;
}
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
        cout << "\n" ;
}
 
void rules()
{
    cout << "\n\n";
    drawLine(105,'-');
    cout << "\t\t\t\t\tRULES OF THE GAME\n";
    drawLine(105,'-');
    cout<<"\n";
    cout << " 1. Choose any number between 1 to 10\n";
    cout << " 2. If you guess the exact number, you will get 10 times of money you bet\n";
    cout << " 3. If you guess the number that is close to the exact number, you will get half money back\n";
    cout << " 4. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(105,'-');
}
 
// END OF PROGRAM