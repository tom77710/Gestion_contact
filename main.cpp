#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// Structure pour représenter un contact
struct Contact {
    std::string nom;
    std::string prenom;
    std::string numero_telephone;
    std::string email;
};

// Prototype des fonctions
void afficherMenu();
void ajouterContact(std::vector<Contact>& contacts);
void afficherContacts(const std::vector<Contact>& contacts);
void mettreAJourContact(std::vector<Contact>& contacts);
void supprimerContact(std::vector<Contact>& contacts);
void sauvegarderContacts(const std::vector<Contact>& contacts, const std::string& fichier);
void chargerContacts(std::vector<Contact>& contacts, const std::string& fichier);

int main() {
    std::vector<Contact> contacts;
    std::string fichier = "contacts.txt";

    // Charger les contacts depuis le fichier
    chargerContacts(contacts, fichier);

    int choix;
    do {
        afficherMenu();
        std::cin >> choix;
        std::cin.ignore(); // Pour nettoyer le tampon d'entrée

        switch (choix) {
            case 1:
                ajouterContact(contacts);
                break;
            case 2:
                afficherContacts(contacts);
                break;
            case 3:
                mettreAJourContact(contacts);
                break;
            case 4:
                supprimerContact(contacts);
                break;
            case 5:
                sauvegarderContacts(contacts, fichier);
                std::cout << "Contacts sauvegardes. Au revoir !\n";
                break;
            default:
                std::cout << "Choix invalide, veuillez reessayer.\n";
        }
    } while (choix != 5);

    return 0;
}
