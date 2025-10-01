#ifndef CLIENT_H
#define  CLIENT_H
typedef struct
{
    int idClient;
    char nom[20];
    char prenom[20];
    char email[50];
    float solde;
} client;
extern client Client;
void Gestion_client();
void Gestion_solde();
void Ajout_Profil();
void Mod_Profil();
void Affiche_client();
void Depot_argent();
void consulterSolde();
void Achat();
#endif