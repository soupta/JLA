#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;

int money;

int bani;

int Blackjack(int money)
{
    cout << "Welcome to blackjack, you need to get as close to 21 as possible without going over. Multipliers are:" << endl;
    cout << "19(x2)" << endl;
    cout << "20(x4)" << endl;
    cout << "21(x6)" << endl;
    srand((unsigned) time(NULL));
    int black = 0, choice;
    while (black <= 21)
    {
        cout << "Do you want another card? Yes(1) No(2)" << endl << "You are at " << black << endl;
        cin >> choice;
        if (choice == 1)
            black += rand() % 10 + 1;
        else
            break;
    }
    if (black > 21)
    {
        cout << "Oops, you went over: " << black << endl;
        return 0;
    }
    else
    {
        if (black == 21)
            return 6;
        if (black == 20)
            return 4;
        if (black == 19)
            return 2;
    }
}

int randnumber(int bani)
{
    int guess;
    srand((unsigned) time(NULL));
    int random = rand() % 10 + 1;
    cout << "What number am I thinking of? (1-10)" << endl << "You have 3 tries" << endl;
    cin >> guess;
    if (guess == random)
    {
        cout << endl << "Congratulations!!!" << endl;
        money *= 5;
        cout << "You now have " << money << " $. ";
        return 5;
    }
    else
        cout << endl << "Wrong guess, try again." << endl;
    for (int i = 1; i < 3; i++)
    {
        cout << "You have " << 3 - i << " tries left" << endl;
        cin >> guess;
        if (guess == random)
        {
            cout << endl << "Congratulations! But you're not very lucky since you didn't get it on the first try." << endl;
            money *= 3;
            return 3;
        }
        else
            cout << endl << "Wrong guess, try again." << endl;
    }
    cout << "You're not very good at this. The number was " << random << endl;
    money = 0;
    return 0;
}

int coinFlip(int money)
{
    srand((unsigned) time(NULL));
    int random = rand() % 2 + 1;
    int choice;
    cout << "Heads (1) or Tails (2)" << endl;
    cin >> choice;
    if (choice == 1)
        cout << "You chose Heads!" << endl;
    else
    {
        if (choice == 2)
            cout << "You chose Tails" << endl;
        else
            cout << "Why would you do that?" << endl;
    }
    if (random == 1)
        cout << "The coin landed on ... Heads" << endl;
    else
        cout << "The coin landed on ... Tails" << endl;
    if (random == choice)
    {
        cout << "Congratulations!" << endl;
        money *= 2;
        return 2;
    }
    else
    {
        cout << "You lost all your money. :(" << endl;
        return 0;
    }
}

int shop(int money)
{
    int choice;
    cout << endl << endl << "-------SHOP-------" << endl;
    cout << "You have " << money << " $. " << endl;
    cout << "1. Mineral Water         (10)" << endl;
    cout << "2. Coffee                (30)" << endl;
    cout << "3. Milkshake             (100)" << endl;
    cout << "4. Pizza                 (300)" << endl;
    cout << "5. FMS+9                 (1000)" << endl;
    cout << "6. Shaman's Tears        (2000)" << endl;
    cout << "7. Monk's Plate          (3000)" << endl;
    cout << "8. Zodiac Armor          (5000)" << endl;
    cout << "9. +1 Green Candy        (9999)" << endl;
    cout << "10. DIMULESCU's Heart    (50000)" << endl;
    cin >> choice;
    if (choice == 1 && money >= 10)
    {
        cout << "You bought mineral water!";
        return 0;
    }
    if (choice == 2 && money >= 30)
    {
        cout << "You bought coffee!";
        return 0;
    }
    if (choice == 3 && money >= 100)
    {
        cout << "You bought milkshake!";
        return 0;
    }
    if (choice == 4 && money >= 300)
    {
        cout << "You bought pizza!";
        return 0;
    }
    if (choice == 5 && money >= 1000)
    {
        cout << "You bought FMS+9!";
        return 0;
    }
    if (choice == 6 && money >= 2000)
    {
        cout << "You bought Shaman's Tears!";
        return 0;
    }
    if (choice == 7 && money >= 3000)
    {
        cout << "You bought Monk's Plate!";
        return 0;
    }
    if (choice == 8 && money >= 5000)
    {
        cout << "You bought Zodiac Armor!";
        return 0;
    }
    if (choice == 9 && money >= 9999)
    {
        cout << "You bought +1 Green Candy!";
        return 0;
    }
    if (choice == 10 && money >= 50000)
    {
        cout << "You bought DIMULESCU's Heart!";
        return 0;
    }
    if (choice > 10 || choice < 1)
    {
        cout << "HOW CAN YOU BE SO STUPID?!?";
        return 0;
    }
    cout << "You're too poor :(";
}

int main()
{
    int u;
    srand((unsigned) time(NULL));
    money = (rand() * 3) % 900 + 100;
    if (rand() % 10000 == 987)
    {
        cout << "Congratulations, you received DIMU's blessing!" << endl;
        money *= 10000;
    }
    cout << "You have " << money << " $. ";
    cout << "What do you want to play, sir?" << endl << "(5x/3x) Random Number (1), (2x) Coinflip (2), (3x-6x) Blackjack (3), Shop (0)" << endl;
    while(u != 0 && bani != 0)
    {
    cin >> u;
    if(u == 1)
    {
        bani *= randnumber(bani);
    }
    else
    {
        if(u == 2)
        {
            bani *= coinflip(bani);
        }
        else if(u == 0)
            cout << "";
        else if(u == 3)
            bani *= Blackjack(bani);
        else
            cout << "Seriously, you're handicapped.";
    }
    if(bani != 0)
        cout << "Now, what do you want to do? Randnumber(1), Coinflip(2), (3x-6x)Blackjack(3), Shop(0)" << endl << "You have " << bani << " lei." << endl;
}

if(bani == 0)
    cout << endl << "You're so poor :(";
else
    shop(bani);
}
