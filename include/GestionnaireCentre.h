#ifndef GESTIONNAIRE_CENTRE_H
#define GESTIONNAIRE_CENTRE_H

#include "Groupe.h"
#include "Seance.h"
#include "Enseignant.h"
#include "Etudiant.h"
#include "Etudiant5eme.h"
#include "Etudiant6eme.h"
#include "EtudiantBac.h"
#include <vector>
#include <iostream>
#include <sstream>

class GestionnaireCentre {
private:
    std::vector<Enseignant> listeEnseignants;
    std::vector<Etudiant *> listeEtudiants;
    std::vector<Groupe > listeGroupes;
    std::vector<Seance > listeSeances;

public:
    void ajouterEtudiant(const std::string& nom, const std::string& prenom, int id, std::string niveau, std::string matiere,int nbrSeance);
    void afficherListeEtudiants() const;
    Etudiant* getEtudiantById(int id) ;
    void sInscrireEtudiantSeance(int idEtudiant, std::string matiere, int nbrSeance);

    void ajouterEnseignant(const Enseignant& enseignant);
    void modifierEnseignant(int index, const Enseignant& nouvelEnseignant);
    void supprimerEnseignant(int index);
    void afficherListeEnseignants() const;
    Enseignant* getEnseignantById(int id);

    void creerGroupe(const int id, const std::string& niveau);
    void afficherListeGroupes() const;
    void ajouterEtudiantInGroup(const int indexGroupe, const int idEtudiant ) ;
    void ajouterEnseignantInGroup(const int indexGroupe, const int idEnseignant ) ;
    Groupe* getGroupeById(int idGroupe);
    
    void affecterGroupeToSeance(int idGroupe, int idSeance, std::string matiere);
    void passerSeance(int idSeance);
    void afficherListeSeances() const ;
    Seance* getSeanceById(int idSeance);


};

#endif
