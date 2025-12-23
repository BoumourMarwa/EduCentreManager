#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include <string>
#include <iostream>

class Enseignant {
private:
    int id;
    std::string nom;
    std::string matiere;
    std::string niveau;

public:
    Enseignant(int _id, const std::string& _nom, const std::string& _matiere, const std::string& _niveau)
        : id(_id), nom(_nom), matiere(_matiere), niveau(_niveau) {}

    Enseignant()
        : id(-1), nom(""), matiere(""), niveau("") {}

    void afficherEnseignant() const;

    // Méthodes d'accès aux attributs
    int getID() const { return id; }
    std::string getNom() const { return nom; }
    std::string getMatiere() const { return matiere; }
    std::string getNiveau() const { return niveau; }
};

#endif
