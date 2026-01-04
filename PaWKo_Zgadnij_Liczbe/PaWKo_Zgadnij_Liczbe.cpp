// Zgadnij_Liczbe_by_PaWKo.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(NULL)); 

    int wynikiNoob[100];   
    int wynikiMedium[100];
    int wynikiPro[100];

    string nazwyNoob[100];   
    string nazwyMedium[100];
    string nazwyPro[100];

    int liczbaGierNoob = 0;
    int liczbaGierMedium = 0;
    int liczbaGierPro = 0;

    while (true) {
        cout << "---------------------------------------\n";
        cout << "Nowa gra (1)  Instrukcja (2)  Wyniki (3)\n";
        int click;
        cin >> click;

        if (click == 1) { 
            int poziom;
            cout << "Wybierz poziom trudnosci:\n";
            cout << "Noob (1)  Medium (2)  Pro (3)\n";
            cin >> poziom;

            int maxLiczba;
            string komunikat;

            
            if (poziom == 1) { maxLiczba = 50; komunikat = "Dawaj liczbe Noobie: "; }
            else if (poziom == 2) { maxLiczba = 100; komunikat = "Dawaj liczbe Sredniaku: "; }
            else if (poziom == 3) { maxLiczba = 250; komunikat = "Czujesz sie jak Pro? To zgaduj: "; }
            else { cout << "Niepoprawny wybor poziomu!\n"; continue; }

            int liczba = rand() % maxLiczba + 1;
            int strzal = 0;
            int proby = 0;

            while (strzal != liczba) {
                proby++;
                cout << komunikat;
                cin >> strzal;

                if (strzal > liczba) {
                    int los = rand() % 5; 
                    if (los == 0) cout << "Oj, za duzo!\n";
                    else if (los == 1) cout << "Ups! Za wysoko!\n";
                    else if (los == 2) cout << "Spokojnie, nie wchodzimy na Mount Everest!\n";
                    else if (los == 3) cout << "Twoja liczba lata jak rakieta!\n";
                    else cout << "Nieee, za duzo!\n";
                }
                else if (strzal < liczba) {
                    int los = rand() % 5; 
                    if (los == 0) cout << "Oj, za malo!\n";
                    else if (los == 1) cout << "Podnies liczbe, to za malutko!\n";
                    else if (los == 2) cout << "Ej, liczba jest jak krasnal!\n";
                    else if (los == 3) cout << "Za nisko, sprobuj wieksza!\n";
                    else cout << "Twoja liczba wciaz spi, podnies ja!\n";
                }
            }

            cout << "Brawo! Zgadles liczbe w " << proby << " probach!\n";

           
            string nazwa;
            cout << "Podaj swoje imie: ";
            cin >> nazwa;

            if (poziom == 1) { wynikiNoob[liczbaGierNoob] = proby; nazwyNoob[liczbaGierNoob] = nazwa; liczbaGierNoob++; }
            else if (poziom == 2) { wynikiMedium[liczbaGierMedium] = proby; nazwyMedium[liczbaGierMedium] = nazwa; liczbaGierMedium++; }
            else if (poziom == 3) { wynikiPro[liczbaGierPro] = proby; nazwyPro[liczbaGierPro] = nazwa; liczbaGierPro++; }

        }
        else if (click == 2) { 
            cout << "Witaj w grze!\n";
            cout << "Aby zobaczyc instrukcje, musisz najpierw zgadnac liczbe od 1 do 10.\n";

            int liczba = rand() % 10 + 1;
            int strzal = 0;
            int proby = 0;

            while (strzal != liczba) {
                proby++;
                cout << "Jaka to liczba?: ";
                cin >> strzal;
                if (strzal != liczba) cout << "Zle! Sprobuj ponownie.\n";
            }

            cout << "Brawo! Zgadles liczbe w " << proby << " probach!\n\n";

            cout << "***** JAK GRAC *****\n";
            cout << "- Wybierasz poziom trudnosci: Noob = 1-50, Medium = 1-100, Pro = 1-250.\n";
            cout << "- Twoim zadaniem jest zgadnac wylosowana liczbe.\n";
            cout << "- Program podpowiada czy Twoja liczba jest za duza czy za mala.\n";
            cout << "- Gra konczy sie, gdy zgadniesz liczbe.\n";
            cout << "Nacisnij 1 aby wrocic do menu...\n";
            int tmp;
            cin >> tmp;
        }
        else if (click == 3) { 
            cout << "===== WYNIKI =====\n";

            
            auto pokazWyniki = [](int wyniki[], string nazwy[], int liczbaGier) {
                int tmpWyniki[100];
                string tmpNazwy[100];
                for (int i = 0; i < liczbaGier; i++) {
                    tmpWyniki[i] = wyniki[i];
                    tmpNazwy[i] = nazwy[i];
                }

                
                for (int i = 0; i < liczbaGier - 1; i++) {
                    for (int j = 0; j < liczbaGier - i - 1; j++) {
                        if (tmpWyniki[j] > tmpWyniki[j + 1]) {
                            int temp = tmpWyniki[j];
                            tmpWyniki[j] = tmpWyniki[j + 1];
                            tmpWyniki[j + 1] = temp;

                            string tempName = tmpNazwy[j];
                            tmpNazwy[j] = tmpNazwy[j + 1];
                            tmpNazwy[j + 1] = tempName;
                        }
                    }
                }

                for (int i = 0; i < liczbaGier; i++)
                    cout << tmpNazwy[i] << " - " << tmpWyniki[i] << " prob\n";
                };

            cout << "Poziom Noob:\n";
            pokazWyniki(wynikiNoob, nazwyNoob, liczbaGierNoob);

            cout << "Poziom Medium:\n";
            pokazWyniki(wynikiMedium, nazwyMedium, liczbaGierMedium);

            cout << "Poziom Pro:\n";
            pokazWyniki(wynikiPro, nazwyPro, liczbaGierPro);

            cout << "Nacisnij 1 aby wrocic do menu...\n";
            int tmp;
            cin >> tmp;
        }
        else { 
            cout << "Niepoprawny wybor!\n";
        }
    }

    return 0;
}