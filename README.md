# get_next_line

## Introduction

Ce projet a été réalisé dans le cadre du cursus à l'école 42. L'objectif est d'implémenter une fonction nommée "get_next_line" permettant de lire une ligne à partir d'un descripteur de fichier, que ce soit un fichier ou l'entrée standard.

<br>

## Description

La fonction get_next_line doit lire une ligne à partir d'un descripteur de fichier, stocker cette ligne dans un buffer, et la renvoyer à chaque appel de la fonction. Le projet met en pratique la gestion dynamique de la mémoire et la manipulation des descripteurs de fichiers en programmation C.

<br>

## Fonctionnalités

- Lecture d'une ligne à partir d'un descripteur de fichier.
- Gestion de plusieurs descripteurs de fichiers simultanément.
- Gestion dynamique de la mémoire pour éviter les fuites.

<br>

## Implémentation

L'implémentation de get_next_line nécessite la gestion du buffer de lecture, la gestion des retours de ligne, et la gestion dynamique de la mémoire. La fonction doit être capable de gérer des fichiers de taille arbitraire et de gérer plusieurs descripteurs de fichiers simultanément.

<br>

## Utilisation

1. **Clonage du dépôt :**

    ```bash
    git clone https://github.com/Wemubis/get_next_line.git
    ```

2. **Compilation :**

    ```bash
    make
    ```

3. **Utilisation dans votre programme :**

    ```c
    #include "get_next_line.h"

    int main() {
        int fd = open("exemple.txt", O_RDONLY);
        char *line;

        while (get_next_line(fd, &line) > 0) {
            printf("%s\n", line);
            free(line);
        }

        close(fd);
        return 0;
    }
    ```
    
