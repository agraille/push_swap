# Push_Swap

## 📋 Description

Push Swap est un projet éducatif dont le but est de trier une liste d'entiers en utilisant deux piles et un ensemble limité d'opérations. Ce projet est conçu pour développer votre compréhension des algorithmes et améliorer vos compétences en optimisation et en gestion de la complexité.

## 🔍 Objectif

Le but est de trier les nombres donnés dans la pile A en un ordre croissant dans un nombre minimum de mouvements, en utilisant les opérations suivantes :

sa : Échange les deux premiers éléments de la pile A.

sb : Échange les deux premiers éléments de la pile B.

ss : Effectue sa et sb simultanément.

pa : Pousse le premier élément de la pile B vers la pile A.

pb : Pousse le premier élément de la pile A vers la pile B.

ra : Fait une rotation ascendante sur la pile A (le premier élément devient le dernier).

rb : Fait une rotation ascendante sur la pile B.

rr : Effectue ra et rb simultanément.

rra : Fait une rotation descendante sur la pile A (le dernier élément devient le premier).

rrb : Fait une rotation descendante sur la pile B.

rrr : Effectue rra et rrb simultanément.



## 🛠️ Installation

### Prérequis :
- C compiler (cc)

### Cloner le projet :
- Clonez le dépôt GitHub pour obtenir les fichiers :

```bash
git clone https://github.com/agraille/push_swap.git
```

### Compilation :
```bash
cd push_swap
make
```
Pour le checker bonus, compilez avec la commande suivante :
```bash
make bonus
```
### Exécution :

Exécutez le programme avec une liste d'entiers en argument :
```bash
./push_swap 3 2 1 6 5 4
```
### Exemple de Sortie :

Pour une liste 3 2 1 :
```bash
ra
sa
```
Pour vérifier que la liste est correctement triée, utilisez le checker bonus :
```bash
ARG="Liste de nombres"; ./push_swap $ARG | ./checker $ARG
```

Si la liste est triée, la sortie affichera : OK

Sinon, la sortie affichera : KO

Ou Error si la liste est invalide(doublon, > int max,...)

## 📏 Contraintes

- L’algorithme doit être optimal, en minimisant le nombre d’opérations.

- Gérez les cas d’erreur : entrées invalides, valeurs non entiers, doublons, etc.

## 🌟 Fonctionnalités

- Gestion dynamique de la taille des piles.

- Validation et gestion robuste des erreurs.

- Supporte des listes d’entiers de grande taille.

- Bonus : Un checker qui vérifie que la liste est bien triée.

## 💻 Contribuer
Les contributions sont les bienvenues ! Si vous souhaitez améliorer cette algo, ajouter de nouvelles fonctionnalités ou corriger des bugs, n’hésitez pas à faire un fork du projet et proposer une pull request.

Comment contribuer :
- 1 - Forkez le projet.
- 2 - Créez une branche pour vos modifications : git checkout -b feature/amélioration
- 3 - Committez vos changements : git commit -am 'Ajout d’une nouvelle fonctionnalité'
- 4 - Poussez la branche : git push origin feature/amélioration
- 5 - Ouvrez une Pull Request pour proposer vos changements.
