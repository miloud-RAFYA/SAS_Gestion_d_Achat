
#include <stdio.h>
#include <string.h>
#include "produit.h"
#include "Client.h"
client Client;
void Ajout_Profil()
{
    printf("\t\t# Ceation de profile #\n");
    printf(" le Nom  :");
    scanf("%s", Client.nom);
    printf(" le Prenom  :");
    scanf("%s", Client.prenom);
    sprintf(Client.email, "%s.%s@gmail.com", Client.prenom, Client.nom);
    Client.idClient = 1;
    Client.solde = 0.0;
}
void Achat()
{
    int id, quantite, i;
    float total;
    printf("Entrez  ID du produit : ");
    scanf("%d", &id);
    int pos = -1;
    for (i = 0; i < 10; i++)
    {
        if (listeProduits[i].idProduit == id)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("Produit introuvable.\n");
        return;
    }

    printf("Vous avez choisi : %s (%.2f MAD)\n", listeProduits[pos].nom, listeProduits[pos].prix);
    printf("Entrez la quantite : ");
    scanf("%d", &quantite);

    if (quantite <= 0)
    {
        printf("Quantite invalide.\n");
        return;
    }

    if (quantite > listeProduits[pos].stock)
    {
        printf("Stock insuffisant. Disponible : %d\n", listeProduits[pos].stock);
        return;
    }

    total = quantite * listeProduits[pos].prix;

    if (total > Client.solde)
    {
        printf("Solde insuffisant. Votre solde actuel est de %.2f MAD\n", Client.solde);
        return;
    }
    Client.solde -= total;
    listeProduits[pos].stock -= quantite;

    printf("Achat reussi !\n");
    printf("Montant depense : %.2f MAD\n", total);
    printf("Nouveau solde : %.2f MAD\n", Client.solde);
}
void Mod_Profil()
{
    char p[20];
    char n[20];
    printf(" le Nom  :");
    scanf("%s",n);
    strcpy(Client.nom, n);
    printf(" le Prenom  :");
    scanf("%s",p);
    strcpy(Client.prenom, p);
    sprintf(Client.email, "%s.%s@gmail.com", Client.prenom, Client.nom);
}
void Affiche_client()
{
    printf("le Nom de Client :%s \n", Client.nom);
    printf("le prenom de Client :%s \n", Client.prenom);
    printf("le email de Client :%s \n", Client.email);
    printf("le solde de Client :%fMAD \n", Client.solde);
}
void Depot_argent()
{
    float montant;
    printf("Entrez le montant a deposer : ");
    scanf("%f", &montant);
    if (montant > 0) {
        Client.solde += montant;
        printf("Depot reussi ! Nouveau solde : %.2f MAD\n", Client.solde);
    } else {
        printf("Montant invalide.\n");
    }
}
void consulterSolde(){
    printf("le solde de Client est :%.2f",Client.solde);
}
