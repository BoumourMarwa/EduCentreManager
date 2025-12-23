#include "Enseignant.h"

void Enseignant::afficherEnseignant() const {
    std::cout << "Test" << "\n";
    std::cout << "ID: " << getID() << ", Nom: " << getNom() << ", Niveau: " << getNiveau() << "\n";
}

