#ifndef SEANCE_H
#define SEANCE_H

#include <vector>
#include "Matiere.h"
#include "Groupe.h"

class Seance {
private:
    int idSeance;
    std::string matiere;
    Groupe* grp;
    // std::vector<Etudiant*> etudiantsParticipants;
    bool valide;

public:
    Seance(Matiere matiere);
    Seance(const int _id ,const std::string& _matiere, Groupe* _grp) : idSeance(_id), matiere(_matiere), grp(_grp), valide(true) {}

    // Méthodes d'accès aux attributs
    int getID() const { return idSeance; }
    std::string getMatiere() const { return matiere; }
    bool getIsValide() const { return valide; }
    Groupe* getGroupe() const { return grp; }
    
};

#endif
