#include <stdio.h>
#include "header.h"
void Ajout_Profil(){
    printf(" le Nom  :");
    scanf("%s",Client.nom);
    printf(" le Prenom  :");
    scanf("%s",Client.prenom);
    sprintf(Client.email, "%s.%s@gmail.com", Client.prenom, Client.nom);
}
void Mod_Profil(){
    char p[20];
    char n[20];
  printf(" le Nom  :");
    scanf("%s",&n); 
    strcpy(Client.nom,n); 
    printf(" le Prenom  :");
    scanf("%s",&p);  
    strcpy(Client.prenom,p); 
    sprintf(Client.email, "%s.%s@gmail.com", Client.prenom, Client.nom);  
}
void Affiche_cli(){
    printf("le Nom de Client :%s \n",Client.nom);
    printf("le prenom de Client :%s \n",Client.prenom);
    printf("le email de Client :%s \n",Client.email);
    printf("le solde de Client :%fMAD \n",Client.solde);
}
void Depot_argent(){
     printf("entre le solde :");
     scanf("%f",Client.solde);
}
void Tri_Prod_Prix(){
    float tab;
    int c;
    do{
        c=0;
        for(int i=0;i<10;i++){
            if(listeProduits[i].prix>listeProduits[i+1].prix){
                tab=listeProduits[i].prix;
               listeProduits[i].prix=listeProduits[i+1].prix;
               listeProduits[i+1].prix=tab;
               c=1;
            }
        }
    }while(c==0);

}
int rech_Prod(){
    char n[30];
    printf("entre le nom de produit :");
    scanf("%s",&n);
     for(int i=0;i<10;i++){
            if(strcmp(listeProduits[i].nom,n)==0){
                return i;
            }
        }
   return -1;
}
void AF_Prod(){
    for(int i=0;i<10;i++){
        printf("le produit  :",)
    }
}

int main(){
    int ch ;
   do{  
       printf("\t1.  Gestion du profil client\n");
       printf("\t2. Gestion du solde virtuel\n");
       printf("\t3. Consultation des produits\n");
       printf("\t4. Effectuer un achat\n");
       printf("\t5. Mes statistiques\n");
       printf("\t0. Quitter l application\n ");
       printf("\t\tentre le choix :");
       scanf("%d",&ch);
       switch(ch){
        cas :1;
        
        break;
        cas :2;
        break;
        cas :3;
        break;
        cas :4;
        break;
        cas :5;
        break;
       }
   }while(ch!=0);



    return 0;
}