#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>

// Structure pour representer un contact
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

bool validerNumeroTelephone(const std::string& numero);

int main() {
    std::vector<Contact> contacts;
    std::string fichier = "contacts.txt";

    // Charger les contacts depuis le fichier
    chargerContacts(contacts, fichier);

    int choix;
    do {
        afficherMenu();
        std::cin >> choix;
        std::cin.ignore(); // Pour nettoyer le tampon d'entree

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
    std::cout << "3. Mettre a jour un contact\n";
    std::cout << "4. Supprimer un contact\n";
    std::cout << "5. Quitter et sauvegarder\n";
    std::cout << "Votre choix : ";
}

void ajouterContact(std::vector<Contact>& contacts) {
    Contact nouveauContact;
    std::cout << "Entrez le nom : ";
    std::getline(std::cin, nouveauContact.nom);
    std::cout << "Entrez le prenom : ";
    std::getline(std::cin, nouveauContact.prenom);

    do // Tant que la que le numéro est pas de 10 caractere numérique, elle boucle.
    {
        std::cout << "Entrez le numero de telephone (10 chiffres) : ";
        std::getline(std::cin, nouveauContact.numero_telephone);
        if (!validerNumeroTelephone(nouveauContact.numero_telephone)) {
            std::cout << "Numero de telephone invalide. Veuillez reessayer.\n";
        }
    } while (!validerNumeroTelephone(nouveauContact.numero_telephone));

    std::cout << "Entrez l'adresse e-mail : ";
    std::getline(std::cin, nouveauContact.email);

    contacts.push_back(nouveauContact);
    std::cout << "Contact ajoute avec succes !\n";
}

bool validerNumeroTelephone(const std::string& numero) {
    // Verifie si le numero contient exactement 10 chiffres
    std::regex modele("^[0-9]{10}$");                           // std::regex : Une classe val de chaînes de caractères
    // ^ : La chaîne doit commencer ici
    // [0-9] : Accepte uniquement des chiffres de 0 à 9
    // {10} : Exige exactement 10 occurrences du motif précédent
    //$ : La chaîne doit se terminer ici.

    return std::regex_match(numero, modele);
    //std::regex_match : Vérifie si la chaîne fournie (numero) correspond exactement au motif défini dans modele
    // Renvoie true si la chaîne correspond au motif, sinon false.
}

void afficherContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "Aucun contact a afficher.\n";
        return;
    }

    std::cout << "\n--- Liste des Contacts ---\n";
    for (const auto& contact : contacts) {
        std::cout << "Nom : " << contact.nom << "\n";
        std::cout << "Prenom : " << contact.prenom << "\n";
        std::cout << "Telephone : " << contact.numero_telephone << "\n";
        std::cout << "E-mail : " << contact.email << "\n";
        std::cout << "-------------------------\n";
    }
}

void mettreAJourContact(std::vector<Contact>& contacts) {
    std::string numero;
    std::cout << "Entrez le numero de telephone du contact a mettre a jour : ";
    std::getline(std::cin, numero);

    for (auto& contact : contacts) {
        if (contact.numero_telephone == numero) {
            std::cout << "Entrez le nouveau nom : ";
            std::getline(std::cin, contact.nom);
            std::cout << "Entrez le nouveau prenom : ";
            std::getline(std::cin, contact.prenom);

            do {
                std::cout << "Entrez le nouveau numero de telephone (10 chiffres) : ";
                std::getline(std::cin, contact.numero_telephone);
                if (!validerNumeroTelephone(contact.numero_telephone)) {
                    std::cout << "Numero de telephone invalide. Veuillez reessayer.\n";
                }
            } while (!validerNumeroTelephone(contact.numero_telephone));

            std::cout << "Entrez le nouvel e-mail : ";
            std::getline(std::cin, contact.email);
            std::cout << "Contact mis a jour avec succes !\n";
            return;
        }
    }
    std::cout << "Contact non trouve.\n";
}

void supprimerContact(std::vector<Contact>& contacts) {
    std::string numero;
    std::cout << "Entrez le numero de telephone du contact a supprimer : ";
    std::getline(std::cin, numero);

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->numero_telephone == numero) {
            contacts.erase(it);
            std::cout << "Contact supprime avec succes !\n";
            return;
        }
    }
    std::cout << "Contact non trouve.\n";
}

void sauvegarderContacts(const std::vector<Contact>& contacts, const std::string& fichier) {
    std::ofstream sortie(fichier);
    if (!sortie) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour la sauvegarde.\n";
        return;
    }

    for (const auto& contact : contacts) {
        sortie << contact.nom << "\n"
               << contact.prenom << "\n"
               << contact.numero_telephone << "\n"
               << contact.email << "\n";
    }
    sortie.close();
}

void chargerContacts(std::vector<Contact>& contacts, const std::string& fichier) {
    std::ifstream entree(fichier);
    if (!entree) {
        std::cout << "Aucun fichier de sauvegarde trouve.\n";
        return;
    }

    Contact contact;
    while (std::getline(entree, contact.nom) &&
           std::getline(entree, contact.prenom) &&
           std::getline(entree, contact.numero_telephone) &&
           std::getline(entree, contact.email)) {
        contacts.push_back(contact);
    }
    entree.close();
}
