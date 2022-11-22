#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>

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
    int freq[10] = {0}, i, castig=0;
    for(i=0;i<3;i++)
        freq[cr_spin[i]]++;
    for(i=0;i<10;i++){
        if(freq[i] == 3){
            castig += (i+1)*3;
            return castig;
        }else if(freq[i] == 2){
            castig += (i+1)*2;
            return castig;
        }
    }
    return 0;
}

void dublaj(int &cs){
    int ok=1, pip, ch, i, istoric[20] = {0}, n=7;
    for(i=0;i<n;i++)istoric[i] = suits[rand()%2];
    while(ok){
        system("cls");
        cout << "CASTIG: " << cs << "\n";
        for(i=0;i<n;i++)cout << (char)istoric[i] << " ";
        cout << "\n---------------\n";
        pip = rand()%2;
        ch = getch();
        switch(ch){
        case 'a':
            cout << (char)suits[pip] << " ";
            if(!pip){
                istoric[n++] = 3;
                cs *= 2;

            }else{
                cs = 0;
                ok = 0;
            }
            break;
        case 'd':
            cout << (char)suits[pip] << " ";
            if(pip){
                istoric[n++] = 5;
                cs *= 2;
            }else{
                cs = 0;
                ok = 0;
            }
            break;
        case 'x':
            ok = 0;
        }

    }
}

void spin_screen(int w){
    int i;
    system("cls");
    cout << "BANI: " << money << "\n";
    if(w)spin();
    for(i=0;i<3;i++)
          cout << (char)a[cr_spin[i]] << " ";
}

int main(){
    init();
    int i, cs;
    char ch;
    while(true){
        if(money < 5)return 1;
        ch = getch();
        switch(ch){
        case 'x':
            return 1;
        case 's':
            money -= 5;
            for(i=0;i<3;i++)
                cr_spin[i] = rand()%10;
            spin_screen(1);
            cs = sol();
            if(cs){
                cout << "\nCASTIG: " << cs;
                cout << "\ndublaj? (e/orice alta tasta)";
                ch = getch();
                if(cs && ch == 'e'){
                    dublaj(cs);
                    Sleep(1000);
                    spin_screen(0);
                    cout << "\nCASTIG: " << cs;
                }
                money += cs;
            }
        }
    }

}
