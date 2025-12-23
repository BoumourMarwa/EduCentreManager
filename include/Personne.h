#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne {
private:
    int id;
    std::string nom;
    std::string prenom;

public:
    Personne(std::string nom, std::string prenom);
    // Getters, setters, etc.
};

#endif