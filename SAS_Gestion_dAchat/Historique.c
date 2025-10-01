#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Historique.h"

histor historique[100];
int nb_historique = 0;

void AjouterHistorique(char *nom, int quantite, float totale) {
    if (nb_historique < 100) {
        strcpy(historique[nb_historique].nom_produit, nom);
        historique[nb_historique].quantite = quantite;
        historique[nb_historique].totale = totale;

        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        strftime(historique[nb_historique].date, sizeof(historique[nb_historique].date),
                 "%d/%m/%Y %H:%M:%S", t);

        nb_historique++;
    } else {
        printf("Historique plein !\n");
    }
}
void AfficherHistorique() {
    if (nb_historique == 0) {
        printf("Aucun achat enregistre.\n");
        return;
    }
    for (int i = 0; i < nb_historique; i++) {
        printf("\t%d. Produit: %s | Quantite: %d | Total: %.2f MAD | Date: %s\n",
               i + 1,
               historique[i].nom_produit,
               historique[i].quantite,
               historique[i].totale,
               historique[i].date);
    }
}
