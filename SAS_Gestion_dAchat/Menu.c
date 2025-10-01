#include <stdio.h>
#include "Client.h"
#include "Produit.h"
#include "Menu.h"
#include "Historique.h"
void Menu_principale()
{ 
    int ch;
    do
    {
        printf("\n\t\t\t#Gestion d Achat#\n");
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
           Gestion_solde();
            break;
        case 3:
           Catalogue_Produits();
            break;
        case 4:
            Achat();
            break;
        case 5:
        statistiques();
            break;
    } 
    }while (ch != 0);
    
 }
void Catalogue_Produits()
    {
        int ch;
        do
        {
            printf("\n\t\t\t\t\t#Consultation des produits#\n");
            printf("\t\t1.Affichage catalogue .");
            printf("\t\t2.Recherche produits.\n");
            printf("\t\t3. Tri des produits Par prix .\n");
            printf("\t\t4. Tri des produits  Par nom .\n");
            printf("\t\t5.Details produit.\n");
            printf("\t\t0. reteur le menu principale\n");
            printf("\t\t\tentre un choix:");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                Affiche_catalog();
                break;
            case 2:
                affiche_prod();
                break;
            case 3:
                Tri_Prod_Prix();
                break;
            case 4:
                Tri_Prod_nom();
                break;
            case 5:
                Details_produits();
                break;
            }
        } while (ch != 0);
    }
void Gestion_client(){
    int ch;
    do{
        printf("\n\t\t\t# Gestion du profil client#\n");
        printf("\t\t1. Affiche un profile .\n");
        printf("\t\t2. Modifier un profile .\n");
        printf("\t\t0. reteur le menu principle .\n ");
        printf("\t\t\tentre le choix :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
             Affiche_client();
            break;
        case 2:
            Mod_Profil();
            break;
       
        }

    }while(ch!=0);
}
void Gestion_solde(){

    int ch;
    do
    {
        printf("\n\t\t\t#Gestion du Solde Virtuel# .\n");
        printf("\t\t1.Consultation du solde .\n");
        printf("\t\t2.Depot d argent .\n");
        printf("\t\t0. reteur a le menu principale .\n");
        printf("\t\t\t entre le choix :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            consulterSolde();
            break;
        case 2:
            Depot_argent();
            break;
        }
    }while(ch!=0);
}
void statistiques(){
     int ch;
    do
    {
        printf("\n\t\t\t#Menu Statistiques# .\n");
        printf("\t\t1.Voir les statistiques generales\n");
        printf("\t\t2.Consulter l historique des achats.\n");
        printf("\t\t0. reteur a le menu principale .\n");
        printf("\t\t\t entre le choix :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
           statique();;
            break;
        case 2:
           AfficherHistorique();
            break;
        }
    }while(ch!=0);
}