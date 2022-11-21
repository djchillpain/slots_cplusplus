#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;

int a[10] = {1, 2, 4, 6, 11, 15, 18, 20, 30, 36}, cr_spin[3], money=100, suits[2] = {3, 5};

void init(){
    srand(time(0));
}

void spin(){
    time_t tm;
    time(&tm);
    while(time(0) < tm+2){
        for(int i=0;i<3;i++)
            cout << (char)a[rand()%10] << " ";
        cout << "\r";
    }
}

int sol(){
    int freq[10] = {0}, i, castig;
    for(i=0;i<3;i++)
        freq[cr_spin[i]]++;
    for(i=0;i<10;i++){
        if(freq[i] == 3){
            castig += (i+1)*3;
            cout << "\nai castigat " << castig;
            return castig;
        }else if(freq[i] == 2){
            castig += (i+1)*2;
            cout << "\nai castigat " << castig;
            return castig;
        }
    }
    return 0;
}

void dublaj(int &cs){
    int ok=1, pip, ch;
    cout << "\n";
    while(ok){
        pip = rand()%2;
        ch = getch();
        switch(ch){
        case 'a':
            if(!pip){
                cs *= 2;

            }else{
                cs = 0;
                ok = 0;
            }
            break;
        case 'd':
            if(pip){
                cs *= 2;
            }else{
                cs = 0;
                ok = 0;
            }
            break;
        case 'x':
            ok = 0;
        }
        cout << (char)suits[pip] << " ";

    }
}

int main(){
    init();
    int i, cs;
    char ch;
    while(true){
        if(money <= 0)return 1;
        ch = getch();
        switch(ch){
        case 'x':
            return 1;
        case 's':
            system("cls");
            money -= 5;
            cout << "BANI: " << money << "\n";
            spin();
            cout << "\r";
            for(i=0;i<3;i++){
                cr_spin[i] = rand()%10;
                cout << (char)a[cr_spin[i]] << " ";
            }
            cs = sol();
            if(cs)dublaj(cs);
            money += cs;
        }
    }

}
