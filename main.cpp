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
