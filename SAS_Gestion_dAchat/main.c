#include <stdio.h>
#include "header.h"

void Ajout_Profil()
{
    printf(" le Nom  :");
    scanf("%s", Client.nom);
    printf(" le Prenom  :");
    scanf("%s", Client.prenom);
    sprintf(Client.email, "%s.%s@gmail.com", Client.prenom, Client.nom);
    Client.idClient = 1;
    Client.solde = 0.0;
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
void Tri_Prod_Prix()
{
    produit temp;
    int c;
    do {
        c = 0;
        for (int i = 0; i < 9; i++) { 
            if (listeProduits[i].prix > listeProduits[i + 1].prix) {
                temp = listeProduits[i];
                listeProduits[i] = listeProduits[i + 1];
                listeProduits[i + 1] = temp;
                c = 1;
            }
        }
    } while (c == 1);
}
void Tri_Prod_nom()
{
    produit temp;
    int c;
    do {
        c = 0;
        for (int i = 0; i < 9; i++) { 
            if (strcmp(listeProduits[i].nom, listeProduits[i + 1].nom) > 0) {
                temp = listeProduits[i];
                listeProduits[i] = listeProduits[i + 1];
                listeProduits[i + 1] = temp;
                c = 1;
            }
        }
    } while (c == 1);
}
int rech_Prod()
{
    char n[30];
    printf("entre le nom de produit :");
    scanf("%s",n);
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(listeProduits[i].nom, n) == 0)
        {
            return i;
        }
    }
    return -1;
}
void Affiche_catalog()
{
    for (int i = 0; i < 10; i++)
    {
        printf("ID: %d\n", listeProduits[i].idProduit);
        printf("Nom: %s\n", listeProduits[i].nom);
        printf("Categorie: %s\n", listeProduits[i].categorie);
        printf("Prix: %.2f MAD\n", listeProduits[i].prix);
        printf("Stock: %d\n", listeProduits[i].stock);
        printf("Description: %s\n\n", listeProduits[i].description);
    }
}
void Details_produit()
{
    for (int i = 0; i < 10; i++)
    {
        printf("la categorie  :", listeProduits[i].categorie);
        printf("le prix  :", listeProduits[i].prix);
        printf("le stock  :", listeProduits[i].stock);
    }
}
void Effectuer_Achat()
{
    int id, quantite, i;
    float total;

    printf("\n=== Effectuer un achat ===\n");
    printf("Entrez l'ID du produit : ");
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
void consulterSolde(){
    printf("le solde de Client est :%d",Client.solde);
}
void Gestion_client(){
    int ch;
    do{
        
        printf("\t1. Ajouter un profile .\n");
        printf("\t2. Affiche un profile .\n");
        printf("\t3. Modifier un profile .\n");
        printf("\t0. reteur le menu principle .\n ");
        printf("\t\tentre le choix :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Ajout_Profil();
            break;
        case 2:
             Affiche_client();
            break;
        case 3:
            Mod_Profil();
            break;
       
        }

    }while(ch!=0);
}
int main()
{
    int ch;
    do
    {
        printf("\t1. Gestion du profil client\n");
        printf("\t2. Gestion du solde virtuel\n");
        printf("\t3. Consultation des produits\n");
        printf("\t4. Effectuer un achat\n");
        printf("\t5. Mes statistiques\n");
        printf("\t0. Quitter l application\n ");
        printf("\t\tentre le choix :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
             Gestion_client();
            break;
        case 2:
            Depot_argent();
            break;
        case 3:
            Affiche_catalog();
            break;
        case 4:
            Effectuer_Achat();
            break;
        case 5:
        
            break;
        case 0:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide.\n");
        }

    } while (ch != 0);

    return 0;
}