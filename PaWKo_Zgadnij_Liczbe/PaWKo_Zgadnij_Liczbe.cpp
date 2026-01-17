// Zgadnij_Liczbe_by_PaWKo.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

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
        cout << "Nowa gra (1)  Instrukcja (2)  TOP 5 (3)\n";
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

            
            char trybZakladu;
            cout << "Czy chcesz grac w trybie zakladu? (t/n): ";
            cin >> trybZakladu;

            int maxProby = 1000000; 
            if (trybZakladu == 't' || trybZakladu == 'T') {
                cout << "Podaj maksymalna liczbe prob: ";
                cin >> maxProby;
            }

            int liczba = rand() % maxLiczba + 1;
            int strzal = 0;
            int proby = 0;

            while (strzal != liczba) {
                proby++;
                cout << "Proba #" << proby << ": " << komunikat; 
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

               
                if (proby >= maxProby) {
                    cout << "Przekroczyles limit prob! Przegrales!\n";
                    break;
                }
            }

            if (strzal == liczba) {
                cout << "Brawo! Zgadles liczbe w " << proby << " probach!\n";

                string nazwa;
                cout << "Podaj swoje imie: ";
                cin >> nazwa;

                if (poziom == 1) { wynikiNoob[liczbaGierNoob] = proby; nazwyNoob[liczbaGierNoob] = nazwa; liczbaGierNoob++; }
                else if (poziom == 2) { wynikiMedium[liczbaGierMedium] = proby; nazwyMedium[liczbaGierMedium] = nazwa; liczbaGierMedium++; }
                else if (poziom == 3) { wynikiPro[liczbaGierPro] = proby; nazwyPro[liczbaGierPro] = nazwa; liczbaGierPro++; }
            }
        }
        else if (click == 2) {
            cout << "Witaj w grze!\n";
            cout << "Aby zobaczyc instrukcje, musisz najpierw zgadnac liczbe od 1 do 10.\n";

            int liczba = rand() % 10 + 1;
            int strzal = 0;
            int proby = 0;

            while (strzal != liczba) {
                proby++;
                cout << "Proba #" << proby << ": Jaka to liczba?: "; 
                cin >> strzal;
                if (strzal != liczba) cout << "Zle! Sprobuj ponownie.\n";
            }

            cout << "Brawo! Zgadles liczbe w " << proby << " probach!\n\n";

            cout << "***** JAK GRAC *****\n";
            cout << "- Wybierasz poziom trudnosci: Noob = 1-50, Medium = 1-100, Pro = 1-250.\n";
            cout << "- Twoim zadaniem jest zgadnac wylosowana liczbe.\n";
            cout << "- Program podpowiada czy Twoja liczba jest za duza czy za mala.\n";
            cout << "- W trybie zakladu mozesz ograniczyc liczbe prob.\n";
            cout << "- Gra konczy sie, gdy zgadniesz liczbe lub przekroczyles limit prob.\n";
            cout << "Nacisnij 1 aby wrocic do menu...\n";
            int tmp;
            cin >> tmp;
        }
        else if (click == 3) {
            if (liczbaGierNoob == 0 && liczbaGierMedium == 0 && liczbaGierPro == 0) {
                cout << "Brak wynikow! Zagraj najpierw przynajmniej jedna gre.\n";
                continue;
            }

            cout << "===== TOP 5 NAJLEPSZYCH WYNIKOW =====\n";

            auto pokazTop5 = [](int wyniki[], string nazwy[], int liczbaGier) {
                if (liczbaGier == 0) {
                    cout << "Brak wynikow.\n";
                    return;
                }

                int tmpWyniki[100];
                string tmpNazwy[100];

                for (int i = 0; i < liczbaGier; i++) {
                    tmpWyniki[i] = wyniki[i];
                    tmpNazwy[i] = nazwy[i];
                }

                for (int i = 0; i < liczbaGier - 1; i++) {
                    for (int j = 0; j < liczbaGier - i - 1; j++) {
                        if (tmpWyniki[j] > tmpWyniki[j + 1]) {
                            swap(tmpWyniki[j], tmpWyniki[j + 1]);
                            swap(tmpNazwy[j], tmpNazwy[j + 1]);
                        }
                    }
                }

                int limit = (liczbaGier < 5) ? liczbaGier : 5;

                for (int i = 0; i < limit; i++) {
                    cout << i + 1 << ". " << tmpNazwy[i]
                        << " - " << tmpWyniki[i] << " prob\n";
                }
                };

            cout << "\nPoziom Noob:\n";
            pokazTop5(wynikiNoob, nazwyNoob, liczbaGierNoob);

            cout << "\nPoziom Medium:\n";
            pokazTop5(wynikiMedium, nazwyMedium, liczbaGierMedium);

            cout << "\nPoziom Pro:\n";
            pokazTop5(wynikiPro, nazwyPro, liczbaGierPro);

            cout << "\nNacisnij 1 aby wrocic do menu...\n";
            int tmp;
            cin >> tmp;
        }
    }

    return 0;
}

}
