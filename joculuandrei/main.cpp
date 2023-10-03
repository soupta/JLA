#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;

int bani;

int Blackjack(int bani)
{
    cout<<"Bine ai venit la blackjack, trebuie sa ajungi cat mai aproape de 21 fara sa treci peste. Multiplicare este:"<<endl;
    cout<<"19(x2)"<<endl;
    cout<<"20(x4)"<<endl;
    cout<<"21(x6)"<<endl;
    srand((unsigned) time(NULL));
    int black=0,i;
    while(black<=21)
    {
        cout<<"Mai doresti o carte? Da(1) Nu(2)"<<endl<<"Esti la "<<black<<endl;
        cin>>i;
        if(i==1)
            black+=rand()%10+1;
        else
            break;

    }
    if(black>21)
        {cout<<"Coaie ai trecut peste:"<<black<<endl;
         return 0;}
    else
    {if(black==21)
            return 6;
    if(black==20)
            return 4;
    if(black==19)
            return 2;
}
}

int randnumber(int bani)
{
    int x;
    srand((unsigned) time(NULL));
    int random = rand()%10+1;
    cout<<"La ce numar ma gandesc? (1-10)"<<endl<<"Ai 3 incercari"<<endl;
    cin>>x;
    if(x==random)
    {
        cout<<endl<<"BRAVO!!!"<<endl;
        bani*=5;
        cout<<"Ai "<<bani<<" de lei. ";
        return 5;
    }
    else
        cout<<endl<<"sugi"<<endl;
    for(int i=1; i<3; i++)
    {
        cout<<"Mai ai "<<3-i<<" incercari"<<endl;
        cin>>x;
        if(x==random)
        {
            cout<<endl<<"BRAVO!!!, da esti muist ca nu iti iese din prima"<<endl;
            bani*=3;
            return 3;
        }
        else
            cout<<endl<<"sugi"<<endl;
    }
    cout<<"Ce prost esti. Era "<<random<<endl;
    bani=0;
    return 0;
}

int coinflip(int bani)
{
    srand((unsigned) time(NULL));
    int random = rand()%2+1;
    int coin;
    cout<<"Cap (1) sau pajura (2)"<<endl;
    cin>>coin;
    if(coin==1)
        cout<<"Ai ales cap!"<<endl;
    else
    {
        if(coin==2)
            cout<<"Ai ales pajura"<<endl;
        else
            cout<<"Ba da cat de prost sa fii?"<<endl;
    }
    if(random==1)
        cout<<"Banul este ... CAP"<<endl;
    else
        cout<<"Banul este ... PAJURA"<<endl;
    if(random==coin)
    {
        cout<<"BRAVO!"<<endl;
        bani*=2;
        return 2;
    }
    else
    {
        cout<<"Ce handicapat, ai pierdut toti banii. :("<<endl;
        return 0;
    }
}

int shop(int bani)
{
    int i;
    cout<<endl<<endl<<"-------SHOP-------"<<endl;
    cout<<"Ai "<<bani<<" de lei. "<<endl;
    cout<<"1.Apa minerala         (10)"<<endl;
    cout<<"2.Cafea                (30)"<<endl;
    cout<<"3.Milkshake            (100)"<<endl;
    cout<<"4.Pizza                (300)"<<endl;
    cout<<"5.FMS+9                (1000)"<<endl;
    cout<<"6.Lacrimile shamanului (2000)"<<endl;
    cout<<"7.Platosa de calugar   (3000)"<<endl;
    cout<<"8.Armora zodiac        (5000)"<<endl;
    cout<<"9.+1 green candy       (9999)"<<endl;
    cout<<"10.Inima lui DIMULESCU (50000)"<<endl;
    cin>>i;
    if(i==1&&bani>=10)
    {
        cout<<"Ai cumparat apa plata!";
        return 0;
    }

    if(i==2&&bani>=30)
    {
        cout<<"Ai cumparat Cafea!";
        return 0;
    }
    if(i==3&&bani>=100)
    {
        cout<<"Ai cumparat Milkshake!";
        return 0;
    }
    if(i==4&&bani>=300)
    {
        cout<<"Ai cumparat Pizza!";
        return 0;
    }
    if(i==5&&bani>=1000)
    {
        cout<<"Ai cumparat FMS+9!";
        return 0;
    }
    if(i==6&&bani>=2000)
    {
        cout<<"Ai cumparat Lacrimile shamanului!";
        return 0;
    }
    if(i==7&&bani>=3000)
    {
        cout<<"Ai cumparat Platosa de calugar!";
        return 0;
    }
    if(i==8&&bani>=5000)
    {
        cout<<"Ai cumparat Aroma zodiac!";
        return 0;
    }
    if(i==9&&bani>=9999)
    {
        cout<<"Ai cumparat +1 green candy!";
        return 0;
    }
    if(i==10&&bani>=50000)
    {
        cout<<"Ai cumparat Inima lui DIMULESCU!";
        return 0;
    }
    if(i>10||i<1)
    {
        cout<<"CUM DRACU SA FII ASA DE PROST?!?";
        return 0;
    }
    cout<<"Esti prea sarac :(";
}

int main()
{
    int u;
    srand((unsigned) time(NULL));
    bani = (rand()*3)%900+100;
    if(rand()%10000==987)
    {
        cout<<"Felicitari, ai primit binecuvantare lui DIMU!"<<endl;
        bani*=10000;
    }
    cout<<"Ai "<<bani<<" de lei. ";
    cout<<"Ce vrei sa joci domnule?"<<endl<<"(5x/3x)Randnumber (1), (2x)Coinflip (2), (3x-6x)Blackjack (3), Shop (0)"<<endl;
    while(u!=0&&bani!=0)
    {
        cin>>u;
        if(u==1)
        {
            bani*=randnumber(bani);
        }
        else
        {
            if(u==2)
            {
                bani*=coinflip(bani);
            }
            else if(u==0)
                cout<<"";
            else if(u==3)
                bani*=Blackjack(bani);
            else
                cout<<"Da sincer esti handicapat";
        }
        if(bani!=0)
            cout<<"Acum ce vrei sa faci? Randnumber(1), Coinflip(2), (3x-6x)Blackjack(3) , Shop(0)"<<endl<<"Ai "<<bani<<" de lei. "<<endl;;
    }
    if(bani==0)
        cout<<endl<<"Ce sarac esti :(";
    else
        shop(bani);
}
