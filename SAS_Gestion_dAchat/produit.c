
#include <stdio.h>
#include <string.h>
#include "Produit.h"

produit listeProduits[10] = {
    {1, "Stylo", "Papeterie", 2.5, 100, "Stylo a bille bleu"},
    {2, "Cle USB", "Electronique", 15.99, 50, "Cle USB 32 Go haute vitesse"},
    {3, "Cahier", "Papeterie", 3.0, 200, "Cahier 100 pages format A4"},
    {4, "Souris", "Informatique", 25.75, 75, "Souris optique sans fil"},
    {5, "Casque audio", "Electronique", 49.90, 30, "Casque avec reduction de bruit"},
    {6, "Agenda", "Papeterie", 9.99, 120, "Agenda annuel 2025 couverture rigide"},
    {7, "Chargeur", "Electronique", 18.5, 60, "Chargeur USB-C rapide 20W"},
    {8, "Imprimante", "Informatique", 120.0, 15, "Imprimante multifonction jet encre"},
    {9, "Tablette graphique", "Electronique", 89.99, 20, "Tablette pour dessin numerique"},
    {10, "Sac a dos", "Accessoires", 35.0, 40, "Sac a dos etanche avec compartiment PC"}
};
void Tri_Prod_Prix(){
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
void affiche_prod(){
    int id=rech_Prod();
    if(id!=-1){
        printf("ID: %d\n", listeProduits[id].idProduit);
        printf("Nom: %s\n", listeProduits[id].nom);
        printf("Categorie: %s\n", listeProduits[id].categorie);
        printf("Prix: %.2f MAD\n", listeProduits[id].prix);
        printf("Stock: %d\n", listeProduits[id].stock);
        printf("Description: %s\n\n", listeProduits[id].description);
    }else{
        printf("le produit introuvable .");
    }
    
}
void Affiche_catalog()
{
    for (int i = 0; i < 10; i++)
    {

        printf("la categorie %s\n :", listeProduits[i].categorie);
        printf("le prix  :%.2fMAD", listeProduits[i].prix);
        printf("le stock  :%d\n", listeProduits[i].stock);
    }
}
void Details_produits()
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
void statique(){
    for(int i=0;i<10;i++){
        if(listeProduits[i].stock>=0){
            printf("le produit :%.30s est disponible .\n",listeProduits[i].nom);
        }else{
            printf("le produit :%s est indisponible .\n",listeProduits[i].nom);
        }
    }
}
