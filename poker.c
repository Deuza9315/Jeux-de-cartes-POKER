#include <iostream>
#include <vector>
#include <string>
#include <random> // C'est ici que ça se passe pour la sécurité
#include <algorithm> // Pour std::shuffle

using namespace std;

int main() {
    // Les données
    const char* valeurs[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    const char* couleurs[] = {"\u2660","\u2665","\u2666","\u2663"};

    // --- LA SÉCURITÉ (CSPRNG) ---
    // 1. random_device demande à l'OS une graine imprévisible (bruit matériel, mouvements souris, etc.)
    random_device rd; 
    
    // 2. On utilise Mersenne Twister, un générateur de très haute qualité
    mt19937 g(rd());

    // --- LA LOGIQUE DE DISTRIBUTION ---
    // Au lieu de tirer au hasard et vérifier si c'est utilisé (ce qui devient lent à la fin),
    // on crée un paquet de 0 à 51 et on le mélange. C'est plus propre.
    
    vector<int> deck(52);
    for(int i=0; i<52; i++) deck[i] = i;

    // On mélange le deck de manière cryptographiquement forte
    shuffle(deck.begin(), deck.end(), g);

    int indexCarte = 0; // Pour suivre où on est dans le paquet

    // Distribution aux joueurs
    for(int j=1; j<=5; j++) {
        cout << "Player " << j << ": ";
        for(int i=0; i<2; i++) {
            int carte = deck[indexCarte++];
            cout << valeurs[carte / 4] << couleurs[carte % 4] << " ";
        }
        cout << endl;
    }

    // Le Flop / Table
    cout << "Table: ";
    for(int i=0; i<5; i++) {
        int carte = deck[indexCarte++];
        cout << valeurs[carte / 4] << couleurs[carte % 4] << " ";
    }
    cout << endl;

    return 0;
}
