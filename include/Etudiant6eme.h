#ifndef ETUDIANT6EME_H
#define ETUDIANT6EME_H

#include "Etudiant.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Etudiant6eme : public Etudiant {
    private:
        std::vector<std::string> matiere_inscrits;

    public:
        const std::string matieres_disponibles[7] = {"math", "physique", "svt", "arabe", "français", "islamique", "histoire_geo"};

        Etudiant6eme(const std::string& nom, const std::string& prenom, int id)
            : Etudiant(nom, prenom, id) {}

        void inscrire_matiere(const std::string& matiere, int nombre_seance) override;
        void afficherMatiereDisponible() const override;
        const std::string& afficherNiveau() const override;
        // void afficherEtudiant() const override;

            // Méthodes d'accès aux attributs
        std::string getNiveau() const { return "6eme"; }

};

#endif
