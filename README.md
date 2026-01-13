*This project has been created as part of the 42 curriculum by mben-mer.*

## Description
L'objectif de ce projet est de trier une pile de nombres entiers en utilisant le moins d'instructions possible. Le programme manipule deux piles (**a** et **b**) à l'aide d'un ensemble d'opérations spécifiques (swaps, pushes et rotations). 

Ce projet permet d'explorer la complexité algorithmique et de choisir la stratégie de tri la plus optimisée pour atteindre les coups maximum imposés.

## Instructions

### Installation
Clonez le dépôt :
```bash
git clone <url_de_ton_depot>
cd <url_de_ton_depot>
```
### Compilation
Le projet utilise un `Makefile` pour automatiser la compilation. Les fichiers sources `.c` sont compilés en objets `.o` pour générer l'exécutable final.
Pour compiler, lancez simplement la commande :
```bash
make 
```
### Execution 
Lancez le programme avec une liste d'entiers en arguments :
```bash
./push_swap 5 4 3 2 1 
```
## Resources
Documentation de l'école 42.
Utilisation du test de gemartin.

## Utilisation de l'IA
Conformément aux consignes, voici comment l'IA a été utilisée pour ce projet :

Traduction : 
    Aide à la traduction des consignes et des benchmarks du sujet.

Architecture & Parsing : 
    Discussion sur l'utilisation de ft_split pour gérer correctement les arguments envoyés entre guillemets.

Optimisation algorithmique :
    Confirmation de la logique d'indexation des valeurs.
    Introduction au concept de tri par "paquets" (Chunks) pour descendre sous la barre des 700 coups pour 100 nombres.
    Conseil sur le réglage des paramètres de tri pour optimiser les performances sur les listes de 500 nombres.

## Algorithme choisi : Les Chunks
    Pour optimiser le nombre d'opérations, j'ai implémenté un algorithme de pré-tri par groupes.

    Indexation : 
        Avant de commencer, chaque nombre reçoit un index (sa position s'il était trié).

    Découpage : 
        On définit une taille de groupe (par exemple 15 nombres pour une liste de 100).

    Transfert vers B : 
        On parcourt la pile A. Si l'index d'un nombre appartient au groupe actuel (ex: entre 0 et 15), on le pousse dans la pile B. Une fois le groupe vide dans A, on passe au suivant (15 à 30, etc.).

    Optimisation des rotations : 
        Pour gagner des coups, on vérifie si l'élément à pousser doit aller en haut ou en bas de la pile B en utilisant rb, ce qui permet de dégrossir le tri dès le transfert.

    Tri final vers A : 
        Une fois la pile A vide, on recherche le plus grand index dans B pour le replacer dans A. Comme les nombres sont déjà regroupés par valeurs proches, le nombre de rotations nécessaires est drastiquement réduit.

## Performances
    100 nombres : 634 coups.
    500 nombres : 5413 coups.