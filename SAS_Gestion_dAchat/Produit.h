#ifndef PRODUIT_H
#define PRODUIT_H
typedef struct {
    int idProduit;
    char nom[30];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
} produit;
extern produit listeProduits[10];
void Catalogue_Produits();
void Tri_Prod_Prix();
void Tri_Prod_nom();
int rech_Prod();
void affiche_prod();
void Affiche_catalog();
void Details_produits();
void statique();
#endif