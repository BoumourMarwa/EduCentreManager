# EduCentreManager

EduCentreManager is a C++ console-based application designed to manage an educational center.
It provides an interactive command-line interface to manage teachers, students, groups, and sessions

## Packaging the app into an image via docker
```console
$ docker build -t gestion-centre .
```

## Start a container using the created docker image in interactive mode
```console
$ docker run -it gestion-centre
```
## Example Commands

ajouterEnseignant 1 ahmed math Bac
ajouterEnseignant 2 achraf math Bac
ajouterEnseignant 3 hicham physique Bac
afficherListeEnseignants

ajouterEtudiant mouad boumour 3 Bac math 2
ajouterEtudiant oussama boumour 1 Bac math 2
afficherListeEtudiants
sInscrireEtudiantSeance 3 math 1
sInscrireEtudiantSeance 3 physique 1
sInscrireEtudiantSeance 3 pque 1


CreerGroupe 1 Bac
afficherListeGroupes

ajouterEtudiantInGroupe 0 3
ajouterEtudiantInGroupe 0 1
// id du grp au lieu de l'index
// cet etudiant existe déja dans ce grp


ajouterEnseignantInGroupe 0 1
ajouterEnseignantInGroupe 0 2
ajouterEnseignantInGroupe 0 3

afficherListeGroupes


affecterGroupeToSeance 1 1 math
affecterGroupeToSeance 1 2 physique
affecterGroupeToSeance 1 2 pp
//tester si la matiére est définie pour ce groupe -> Done
//Verifier sile grp contient plus de 4 personnes -> todo

afficherListeSeances

passerSeance 1
// valide --> 0


Hypotheses
// chaque prof a un seul niveau

Rmqs:
// Ajouter Prenom au Enseignant
// les identifiants des étudiants, enseignants, séances , groupes, ... doivent étre uniques
