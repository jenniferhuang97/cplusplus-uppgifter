#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
 
using namespace std; 
 
int main() 
{
    int const min = 1, max = 36; //min och max intervall vid val av nummerspel
    int nummer; //det nummer spelaren väljer
    int random; //slumpar tal 
    int insats; //spelarens valda insats
    int summa = 1000; //balansen som spelaren har, där vi har satt 1000 för start
    string spel;  //speltyp 
    string färg; //vilken färg användaren vill spela 
    string fortsätta; // om man vill fortsätta

    while(true) {
        srand(time(0));
        random = rand() % (max - min + 1) + min;  // så att random slumpar mellan talen 1 - 36
        
        //spelar börjar med spelarens startsumma 
        cout << "Du har " << ((int)summa) << " att spela med. " << endl;    
        
        //spelaren väljer insats 
        cout << "Vilket av insättningen 100kr, 300kr eller 500kr vill ni sätta in?" << endl;
        cin >> insats;

        //systemet kontrollerar att insats endast är 100, 300 eller 500 
        while(insats != 100 && insats != 300 && insats != 500) {
            cout << "OBS!!! Du kan endast göra en insats på 100kr, 300kr eller 500kr. Prova igen " << endl;
            cout << "Vilket av insättningen 100kr, 300kr eller 500kr vill ni sätta in?" << endl;
            cin >> insats;
        }

        //systemet drar pengar från bankkonto när insats är gjord
        cout << "Ditt bankkonto har dragit med " << ((int)insats) << " kr" << endl; 


        //spelaren väljer speltyp 
        cout << "Skulle ni vilja välja ett nummer (N) eller en färg (F)? " << endl; 
        cin >> spel;

        //kod för spel för specifikt nummer
        if (spel == "N" || spel == "n") {
            cout << "Vilket nummer vill du spela på? " << endl; 
            cin >> nummer;
            
            //systemet kontrollerar att numret valt är mellan 1 - 36
            while (nummer > max || nummer < min){
                cout << "Numret måste vara mellan 1 - 36? " << endl;         
                cout << "Prova igen: " << endl; 
                cin >> nummer;
            }

            //systemet skriver ut vilket nummer bollen landade 
            cout << "Bollen landade på nummer " << random << endl;

            //if sats om spelaren gissade rätt eller ej 
            if(nummer == random) {
                cout << "Grattis, du har vunnit " << insats * 10 << endl;
                summa = summa + (insats * 10);
            } else {
                cout << "Tyvärr, du har förlorat " << insats << endl;
                summa = summa - insats;
            }
        }
        
        //kod för spel för färg 
        if(spel == "F" || spel == "f") {
            cout << "Färgen svart representerar jämna nummer" << endl;
            cout << "Färgen röd representerar udda nummer" << endl;
            cout << "Välj färgen svart(S) eller färgen röd(R):" << endl; 
            cin >> färg;
            cout << "Bollen landade på " << random << endl;
            
            //om spelaren väljer färgen svart vinner den vid jämna nummer 
            if(färg == "S" || färg == "s") {
                if(random % 2 == 0) {
                    cout << "Du vinner " << insats << " kr" << endl;
                    summa = summa + insats;
                } //spelaren förlorar vid insats på jämna nummer 
                else {
                    cout << "Du förlorade " << insats << " kr" << endl;
                    summa = summa - insats;
                }
            } //spelaren vinner vid insats på färgen röd vid udda tal och förlorar vid jämna tal
            else if(färg == "R" || färg == "r") {
                if(random%2 == 0) {
                    cout << "Du förlorade " << insats << " kr" << endl;
                    summa = summa - insats;
                } else {
                    cout << "Du vann " << insats << " kr" << endl;
                    summa = summa + insats;
                }
            }
        }

        //systemet skriver ut spelarens totala balans 
        cout << "Din totala balans är " << summa << " kr" << endl; 


        //i en if loop kollas om balansen räcker för en insättning att spela igen 
        if(summa < 100) {
            cout << "Du har tyvärr för lite pengar. Spelet avslutas..." << endl;
            break;
        }

        //spelar får välja om den vill spela eller avsluta spelet, detta ifall spelaren har pengar 
        cout << "Vill du fortsätta spela? Skriv N för att avsluta, annars tryck skriv valfritt: "; 
        cin >> fortsätta;

        if(fortsätta == "N") {
            cout << "Spelet avslutas...";
            break;
        }
    }

}