# ft_printf

`ft_printf` est une implémentation personnalisée de la fonction `printf` en C, réalisée dans le cadre du cursus de l'école 42. Ce projet a pour objectif de reproduire le comportement de `printf`, en offrant une compréhension approfondie des spécificateurs de format, de la gestion des arguments variadiques et de la manipulation de chaînes.

## Fonctionnalités

`ft_printf` prend en charge les spécificateurs suivants :

- `%c` : Affiche un caractère
- `%s` : Affiche une chaîne de caractères
- `%p` : Affiche un pointeur en notation hexadécimale
- `%d` / `%i` : Affiche un entier décimal (signé)
- `%u` : Affiche un entier non signé
- `%x` / `%X` : Affiche un entier en hexadécimal (respectivement en minuscules et majuscules)
- `%%` : Affiche le caractère `%`

La gestion des autres spécificateurs (`f`, `e`, etc.) n'est pas incluse dans ce projet.
