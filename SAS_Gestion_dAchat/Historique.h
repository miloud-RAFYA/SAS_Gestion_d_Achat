#ifndef HISTORIQUE_H
#define HISTORIQUE_H

typedef struct {
    char nom_produit[40];
    int quantite;
    float totale;
    char date[30];
} histor;

extern histor historique[100];
extern int nb_historique;

void AjouterHistorique(char *nom, int quantite, float totale);
void AfficherHistorique();

#endif
