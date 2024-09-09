#include <stdio.h>

typedef struct {
    char t_nom[20];
    char a_livre[20];
    int prix;
    int quantite;
}livre;

livre T[99];
int taille = 0;
void ajouter(){
    printf("entrer le titre : ");
    scanf("%s",T[taille].t_nom);
    printf("entrer le titre : ");
    scanf("%s",T[taille].t_nom);
    printf("entrer le prix :");
    scanf("%d",T[taille].prix);
    printf("entrer la quantite :");
    scanf("%d",T[taille].quantite);
    taille++;

}
void ajouter_plus(){
    int cont;
    printf("entrer combien de livre vous voulez ajouter : ");
    scanf("%d",&cont);
    for(int i = 0 ; i < cont ; i++){
        printf("entrer le titre : ");
    scanf("%s",T[taille + i].t_nom);
    printf("entrer le titre : ");
    scanf("%s",T[taille + i].t_nom);
    printf("entrer le prix :");
    scanf("%d",&T[taille + i].prix);
    printf("entrer la quantite :");
    scanf("%d",&T[taille + i].quantite);

    }
    taille += cont;

}
void trier(){
    for(int i = 0 ; i < taille ; i++){//dont forget to add strupr or strlwr
        int temp;

        if(strcmp(T[i].t_nom,T[i+1].t_nom)>0){
            livre temp;
            temp = T[i];
            T[i] = T[i+1];
            T[i+1] = temp;
        }
    }

}
int cherche_el(){
    char nom[20];
    int t = -1;
    printf("entrer lelement que vous voulez  : ");
    scanf("%s",nom);
    for(int i = 0 ;i < taille ; i++){
        if(strcmp(T[i].t_nom,nom)==0){
            t = i;
            break;
        }

    }
    return t;
}
void modifier(){
    int i = cherche_el();
    int choice;
    printf("1=>titre 2=>quantite 3=>prix 4=>change tout \n choix : ");
    switch(choice){
        case 1:
        char nouveau_titre[20];
        printf("entrer le nouveau titre : ");
        scanf("%s",nouveau_titre);
        strcpy(T[i].t_nom,nouveau_titre);
        case 2:
        int nouveau_quantite;
        printf("entrer le nouveau titre : ");
        scanf("%s",nouveau_quantite);
        T[i].quantite = nouveau_quantite;
        case 3:
        int nouveau_prix;
        printf("entrer le nouveau titre : ");
        scanf("%s",nouveau_prix);
        T[i].quantite = nouveau_prix;


    }
        
    
    
    
    
}
void recherche(){
    char nom_cherche[20];
    printf("entrer le nom du livre que vous voulez chercher : ");
    scanf("%s",nom_cherche);
    int inf = 0;
    int sup = taille - 1;
    while(inf<=sup){
        int mil = (inf + sup)/2;
        if(strcmp(T[mil].t_nom,nom_cherche)==0){
            printf("le nom %s existe",nom_cherche);

        }
        else if(strcmp(T[mil].t_nom,nom_cherche)<0){
            inf = mil +1;
        }
        else sup = mil - 1;
    
    }
    

    }
    int main(){
        int choix;
        do {
            printf("------------------------------------------------------------");
            printf("*****************************menu***************************");
            printf("------------------------------------------------------------");
            printf("\n");
            printf("----------  ---------- ----------- ------------- -------- ----------- ----------");
            printf("1=>ajouter 2=>modifier 3=>suprimer 4=>rechercher 5=>trier 6=>statique 7=>quitter");
            printf("---------- ----------- ----------- ------------- -------- ----------- ----------");
            printf("\n");
            printf("entrer votre choix de 1 a 7 : ");
            scanf("%d",&choix);
            switch(choix){
                case 1:
                int choice;
                printf("--------------------- ----------------------------");
                printf("1=>ajouter un element 2=>ajouter plusieurs element");
                printf("--------------------- ----------------------------");
                scanf("%d",choix);
                if(choix == 1) ajouter();
                else if(choix == 2) ajouter_plus() ;
                break
                case 2:

                

            }

        }while(choix != 7);
    }
