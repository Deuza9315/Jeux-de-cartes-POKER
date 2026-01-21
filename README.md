# Poker Game

Application de Poker minimaliste developpee en C++.

## Description

Ce programme simule la distribution de cartes pour une partie de poker. Il utilise un generateur de nombres aleatoires de haute qualite (Mersenne Twister avec random_device) pour assurer un melange equitable et securise du paquet de cartes.

## Fonctionnalites

- Creation d'un paquet de 52 cartes.
- Melange securise du paquet.
- Distribution automatique de 2 cartes pour 5 joueurs.
- Tirage de la table (Flop, Turn, River - 5 cartes).

## Prérequis

- Un compilateur C++ (comme g++ ou clang).

## Compilation et Lancement

### Compilation

Pour compiler le projet, utilisez la commande suivante dans votre terminal :

```bash
g++ poker.c -o poker
```

Note : Bien que le fichier soit nomme `poker.c`, il contient du code C++ et doit etre compile avec un compilateur C++.

### Lancement

Une fois compile, vous pouvez lancer l'application avec :

```bash
./poker
```
