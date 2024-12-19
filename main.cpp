#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// Structure pour repr�senter un contact
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
        std::cin.ignore(); // Pour nettoyer le tampon d'entr�e

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
void afficherMenu() {
    std::cout << "\n--- Gestion de Contacts ---\n";
    std::cout << "1. Ajouter un contact\n";
    std::cout << "2. Afficher les contacts\n";
    std::cout << "3. Mettre � jour un contact\n";
    std::cout << "4. Supprimer un contact\n";
    std::cout << "5. Quitter et sauvegarder\n";
    std::cout << "Votre choix : ";
}

void ajouterContact(std::vector<Contact>& contacts) {
    Contact nouveauContact;
    std::cout << "Entrez le nom : ";
    std::getline(std::cin, nouveauContact.nom);
    std::cout << "Entrez le pr�nom : ";
    std::getline(std::cin, nouveauContact.prenom);
    std::cout << "Entrez le num�ro de t�l�phone : ";
    std::getline(std::cin, nouveauContact.numero_telephone);
    std::cout << "Entrez l'adresse e-mail : ";
    std::getline(std::cin, nouveauContact.email);

    contacts.push_back(nouveauContact);
    std::cout << "Contact ajout� avec succ�s !\n";
}

void afficherContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "Aucun contact � afficher.\n";
        return;
    }

    std::cout << "\n--- Liste des Contacts ---\n";
    for (const auto& contact : contacts) {
        std::cout << "Nom : " << contact.nom << "\n";
        std::cout << "Pr�nom : " << contact.prenom << "\n";
        std::cout << "T�l�phone : " << contact.numero_telephone << "\n";
        std::cout << "E-mail : " << contact.email << "\n";
        std::cout << "-------------------------\n";
    }
}

void mettreAJourContact(std::vector<Contact>& contacts) {
    std::string numero;
    std::cout << "Entrez le num�ro de t�l�phone du contact � mettre � jour : ";
    std::getline(std::cin, numero);

    for (auto& contact : contacts) {
        if (contact.numero_telephone == numero) {
            std::cout << "Entrez le nouveau nom : ";
            std::getline(std::cin, contact.nom);
            std::cout << "Entrez le nouveau pr�nom : ";
            std::getline(std::cin, contact.prenom);
            std::cout << "Entrez le nouveau num�ro de t�l�phone : ";
            std::getline(std::cin, contact.numero_telephone);
            std::cout << "Entrez le nouvel e-mail : ";
            std::getline(std::cin, contact.email);
            std::cout << "Contact mis � jour avec succ�s !\n";
            return;
        }
    }
    std::cout << "Contact non trouv�.\n";
}

