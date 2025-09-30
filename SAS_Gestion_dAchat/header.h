#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <string.h>
typedef struct
{
    int idClient;
    char nom[20];
    char prenom[20];
    char email[50];
    float solde;
} client;
client Client;
typedef struct {
    int idProduit;
    char nom[30];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
} produit;
produit listeProduits[10] = {
    {1, "Stylo", "Papeterie", 2.5, 100, "Stylo a bille bleu"},
    {2, "Cle USB", "Electronique", 15.99, 50, "Cle USB 32 Go haute vitesse"},
    {3, "Cahier", "Papeterie", 3.0, 200, "Cahier 100 pages format A4"},
    {4, "Souris", "Informatique", 25.75, 75, "Souris optique sans fil"},
    {5, "Casque audio", "Electronique", 49.90, 30, "Casque avec reduction de bruit"},
    {6, "Agenda", "Papeterie", 9.99, 120, "Agenda annuel 2025 couverture rigide"},
    {7, "Chargeur", "Electronique", 18.5, 60, "Chargeur USB-C rapide 20W"},
    {8, "Imprimante", "Informatique", 120.0, 15, "Imprimante multifonction jet d'encre"},
    {9, "Tablette graphique", "Electronique", 89.99, 20, "Tablette pour dessin numerique"},
    {10, "Sac a dos", "Accessoires", 35.0, 40, "Sac a dos etanche avec compartiment PC"}
};

#endif