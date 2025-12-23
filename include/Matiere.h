#ifndef MATIERE_H
#define MATIERE_H

#include <string>

class Matiere {
private:
    std::string nom;
    std::string niveauAssocie;

public:
    Matiere(std::string nom, std::string niveauAssocie);
    // Getters, setters, etc.
};

#endif
