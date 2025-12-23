#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <string>
#include <map>
#include <iostream>

class Etudiant {
protected:
    int id;
    std::string nom;
    std::string prenom;
    int absences=0; //tmp
    std::map<std::string, int> seancesParMatiere;

public:
    virtual ~Etudiant() {}
    Etudiant(const std::string& nom, const std::string& prenom, int id)
        : nom(nom), prenom(prenom), id(id), absences(0) {}

    virtual void inscrire_matiere(const std::string& matiere, int nbrSeance) = 0;
    virtual void afficherMatiereDisponible() const = 0;
    virtual const std::string& afficherNiveau() const = 0;
    void afficherEtudiant() const;
    void sInscrireSeance(const std::string& matiere, int nombre_seance);
    int GetnombreSeance(const std::map<std::string, int>& seancesParMatiere);
    // void getSeancesParMatiere(const std::string& matiere) const;
    int getSeancesParMatiere(const std::string& matiere) const;
    void marquerAbsence(const std::string& matiere);
    void marquerPresence(const std::string& matiere);


    // Méthodes d'accès aux attributs
    int getID() const { return id; }
    std::string getNom() const { return nom; }
    std::string getPrenom() const { return prenom; }
    virtual std::string getNiveau() const =0;
    int getAbsences() const { return absences; }

};

#endif
