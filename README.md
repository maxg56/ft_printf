# ft_printf

## Description

**ft_printf** est une implémentation personnalisée de la fonction `printf` de la librairie standard C. Ce projet fait partie du cursus de l'école 42 et vise à recoder entièrement la fonction printf avec ses principaux spécificateurs de format.

Cette implémentation gère les conversions de base suivantes :
- `%c` - Caractère
- `%s` - Chaîne de caractères  
- `%p` - Pointeur (format hexadécimal)
- `%d` - Entier décimal
- `%i` - Entier (base 10)
- `%u` - Entier non signé
- `%x` - Hexadécimal minuscule
- `%X` - Hexadécimal majuscule
- `%%` - Caractère littéral '%'

## Structure du projet

```
ft_printf/
├── Makefile                  # Fichier de compilation
├── README.md                 # Ce fichier
├── include/
│   ├── ft_printf.h          # Header principal de ft_printf
│   └── libft.h              # Header de la libft
├── src/
│   ├── ft_printf.c          # Fonction principale ft_printf
│   └── printers/            # Fonctions d'impression par type
│       ├── ft_print_c_fd.c  # Impression de caractères
│       ├── ft_print_d_fd.c  # Impression d'entiers
│       ├── ft_print_p_fd.c  # Impression de pointeurs
│       ├── ft_print_pct_fd.c # Impression du caractère %
│       ├── ft_print_s_fd.c  # Impression de chaînes
│       ├── ft_print_u_fd.c  # Impression d'entiers non signés
│       └── ft_print_x_fd.c  # Impression hexadécimale
├── libft/                   # Bibliothèque libft (dépendance)
│   ├── Makefile
│   ├── include/
│   └── src/
└── .tests/                  # Tests unitaires
    ├── Makefile
    └── main.c
```

## Compilation

### Prérequis
- GCC ou un compilateur C compatible
- Make

### Instructions

1. **Compilation de la bibliothèque :**
```bash
make
```

2. **Nettoyage des fichiers objets :**
```bash
make clean
```

3. **Nettoyage complet :**
```bash
make fclean
```

4. **Recompilation complète :**
```bash
make re
```

La compilation génère `libftprintf.a`, une bibliothèque statique contenant ft_printf et libft.

## Utilisation

### Inclusion dans votre projet

```c
#include "ft_printf.h"
```

### Liaison
```bash
gcc your_file.c libftprintf.a -o your_program
```

### Exemples d'utilisation

```c
#include "ft_printf.h"

int main(void)
{
    int nombre = 42;
    char *texte = "Hello World";
    void *ptr = &nombre;
    
    // Affichage de base
    ft_printf("Bonjour le monde !\n");
    
    // Différents types de données
    ft_printf("Nombre : %d\n", nombre);
    ft_printf("Texte : %s\n", texte);
    ft_printf("Caractère : %c\n", 'A');
    ft_printf("Hexadécimal : %x\n", nombre);
    ft_printf("Pointeur : %p\n", ptr);
    ft_printf("Pourcentage : %%\n");
    
    // Combinaison de formats
    ft_printf("L'entier %d en hexadécimal est %x\n", nombre, nombre);
    
    return (0);
}
```

## Tests

Le projet inclut une suite de tests complète pour vérifier le bon fonctionnement de toutes les conversions.

### Lancer les tests

```bash
cd .tests
make
```

Les tests comparent la sortie de `ft_printf` avec celle de `printf` standard pour s'assurer de la conformité.

### Tests disponibles

- **Tests obligatoires** : Tous les spécificateurs de base
- **Tests bonus** : Gestion avancée des formats (largeur, précision, drapeaux)
- **Tests de cas limites** : NULL, valeurs extrêmes, etc.

## Fonctionnalités

### Spécificateurs gérés

| Spécificateur | Description | Exemple |
|---------------|-------------|---------|
| `%c` | Caractère unique | `ft_printf("%c", 'A')` → `A` |
| `%s` | Chaîne de caractères | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | Adresse de pointeur | `ft_printf("%p", ptr)` → `0x7fff...` |
| `%d` | Entier décimal signé | `ft_printf("%d", -42)` → `-42` |
| `%i` | Entier (identique à %d) | `ft_printf("%i", 42)` → `42` |
| `%u` | Entier non signé | `ft_printf("%u", 42U)` → `42` |
| `%x` | Hexadécimal minuscule | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadécimal majuscule | `ft_printf("%X", 255)` → `FF` |
| `%%` | Caractère % littéral | `ft_printf("%%")` → `%` |

### Gestion des cas spéciaux

- **Chaînes NULL** : Affiche `(null)` comme printf standard
- **Pointeurs NULL** : Affiche `(nil)`
- **Valeurs limites** : INT_MAX, INT_MIN, UINT_MAX correctement gérées

## Architecture

### Fonction principale : `ft_printf`

```c
int ft_printf(const char *format, ...);
```

- **Paramètres** : Format string + arguments variables
- **Retour** : Nombre de caractères imprimés
- **Utilise** : `stdarg.h` pour les arguments variables

### Fonctions utilitaires

Chaque type de données a sa propre fonction d'impression :

- `ft_print_c_fd()` : Caractères
- `ft_print_s_fd()` : Chaînes
- `ft_print_d_fd()` : Entiers signés
- `ft_print_u_fd()` : Entiers non signés
- `ft_print_x_fd()` : Hexadécimal
- `ft_print_p_fd()` : Pointeurs
- `ft_print_pct_fd()` : Caractère %

### Dépendances

Le projet utilise **libft**, une bibliothèque de fonctions C utilitaires incluant :
- Fonctions de manipulation de chaînes (`ft_strlen`, `ft_strchr`, etc.)
- Fonctions de manipulation de mémoire (`ft_memcpy`, `ft_memset`, etc.)
- Fonctions de conversion (`ft_itoa`, `ft_atoi`, etc.)
- Fonctions d'affichage (`ft_putchar_fd`, `ft_putstr_fd`, etc.)

## Normes

Le code respecte la **Norme 42** :
- 25 lignes maximum par fonction
- 5 fonctions maximum par fichier
- Pas de variables globales
- Gestion d'erreur appropriée
- Documentation et commentaires selon les standards

## Performances

- **Optimisé** pour la lisibilité et la maintenabilité
- **Récursivité** utilisée pour les conversions numériques
- **Gestion de mémoire** sûre (pas de fuites)
- **Compatible** avec les standards POSIX

## Auteur

**mgendrot** - École 42

## Licence

Ce projet est réalisé dans le cadre du cursus de l'école 42. Il est destiné à des fins éducatives.

---

*Ce README fournit une vue d'ensemble complète du projet ft_printf. Pour plus de détails sur l'implémentation, consultez le code source dans les répertoires correspondants.*
