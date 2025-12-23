#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include <iostream>
#include "Etudiant.h"
#include "Enseignant.h"

class Groupe {
private:
    int idGroupe;
    std::string niveau;
    std::vector<Etudiant*> etudiants;
    std::vector<Enseignant*> enseignants;
    //Enseignant professeur;    

public:
    Groupe() : niveau("") {}

    Groupe(const int id ,const std::string& niv) : idGroupe(id), niveau(niv) {}

    void ajouterEtudiant(Etudiant* etudiant);
    bool isExist(std::string matiere);
    void assignerEnseignant(Enseignant *enseignant);
    void afficherGroupe() const;
    void afficherEnseignantsDuGroupe() const;

    // Méthodes d'accès aux attributs
    int getID() const { return idGroupe; }
    std::string getNiveau() const { return niveau; }
    const std::vector<Etudiant*>& getEtudiants() const { return etudiants; }
    const std::vector<Enseignant*>& getEnseignants() const { return enseignants; }

};

#endif