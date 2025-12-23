#ifndef ETUDIANTBAC_H
#define ETUDIANTBAC_H

#include "Etudiant.h"
#include <iostream>
#include <vector>
#include <algorithm>

class EtudiantBac : public Etudiant {
private:
    std::vector<std::string> matiere_inscrits;

public:
    const std::string matieres_disponibles[5] = {"math", "physique", "svt", "philosophie", "anglais"};

    EtudiantBac(const std::string& nom, const std::string& prenom, int id)
        : Etudiant(nom, prenom, id) {}

    void afficherMatiereDisponible() const override;
    const std::string& afficherNiveau() const override;
    void inscrire_matiere(const std::string& matiere, int nombre_seance) override;
    // void afficherEtudiant() const override;

    // Méthodes d'accès aux attributs
    std::string getNiveau() const { return "Bac"; }
};

#endif
