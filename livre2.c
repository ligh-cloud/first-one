#include <stdio.h>
#include <string.h>
typedef struct
{
    char t_nom[20];
    char a_livre[20];
    int prix;
    int quantite;
} livre;

livre T[99];
int taille = 0;
void ajouter()
{
    printf("entrer le titre : ");
    scanf("%s", T[taille].t_nom);
    printf("entrer lauteur : ");
    scanf("%s", T[taille].a_livre);
    printf("entrer le prix :");
    scanf("%d", &T[taille].prix);
    printf("entrer la quantite :");
    scanf("%d", &T[taille].quantite);
    taille++;
}
void ajouter_plus()
{
    int cont;
    printf("entrer combien de livre vous voulez ajouter : ");
    scanf("%d", &cont);
    for (int i = 0; i < cont; i++)
    {
        printf("entrer le titre %d: ", i + 1);
        scanf("%s", T[taille + i].t_nom);
        printf("entrer le lauteur %d : ", i + 1);
        scanf("%s", T[taille + i].a_livre);
        printf("entrer le prix %d : ", i + 1);
        scanf("%d", &T[taille + i].prix);
        printf("entrer la quantite %d : ", i + 1);
        scanf("%d", &T[taille + i].quantite);
    }
    taille += cont;
}
void afficher()
{
    for (int i = 0; i < taille; i++)
    {
        printf("|T[%d] = %s   | T[%d] = %s   | T[%d] = %d   | T[%d] = %d   |\n", i + 1, T[i].t_nom, i + 1, T[i].a_livre, i + 1, T[i].prix, i + 1, T[i].quantite);
    }
}
void trier_A_to_Z()
{
    livre temp;
    for (int i = 0; i < taille - 1; i++)
    { // dont forget to add strupr or strlwr

        if (strcmp(T[i].t_nom, T[i + 1].t_nom) > 0)
        {

            temp = T[i];
            T[i] = T[i + 1];
            T[i + 1] = temp;
        }
    }
}
void trier_Z_to_A()
{
    livre temp;
    for (int i = 0; i < taille - 1; i++)
    { // dont forget to add strupr or strlwr

        if (strcmp(T[i].t_nom, T[i + 1].t_nom) < 0)
        {

            temp = T[i];
            T[i] = T[i + 1];
            T[i + 1] = temp;
        }
    }
}

int cherche_el(char nom[20])
{

    int t = -1;
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(T[i].t_nom, nom) == 0)
        {
            t = i;
            break;
        }
    }
    return t;
}

void modifier()
{
    char nom[20];
    printf("entrer lelement que vous vouler modifier : ");
    scanf("%s", nom);
    int i = cherche_el(nom);
    if (i == -1)
    {
        printf("element not found\n");
    }
    else
    {
        int choice;
        printf("1=>Titre 2=>Quantité 3=>Prix 4=>Changer tout \nChoix : ");
        scanf("%d", &choice); // Lire le choix de l'utilisateur

        char nouveau_titre[20];
        int nouveau_quantite;
        int nouveau_prix;

        switch (choice)
        {
        case 1:
            printf("Entrer le nouveau titre : ");
            scanf("%s", nouveau_titre);
            strcpy(T[i].t_nom, nouveau_titre);
            break;

        case 2:
            printf("Entrer la nouvelle quantité : ");
            scanf("%d", &nouveau_quantite);
            T[i].quantite = nouveau_quantite;
            break;

        case 3:
            printf("Entrer le nouveau prix : ");
            scanf("%d", &nouveau_prix);
            T[i].prix = nouveau_prix;
            break;

        case 4:
            printf("Entrer le nouveau titre : ");
            scanf("%s", nouveau_titre);
            strcpy(T[i].t_nom, nouveau_titre);
            printf("Entrer la nouvelle quantité : ");
            scanf("%d", &nouveau_quantite);
            T[i].quantite = nouveau_quantite;
            printf("Entrer le nouveau prix : ");
            scanf("%d", &nouveau_prix);
            T[i].prix = nouveau_prix;
            break;

        default:
            printf("Choix non valide\n");
            break;
        }
    }
}

void recherche()
{
    char nom_cherche[20];
    printf("Entrer le nom du livre que vous voulez chercher : ");
    scanf("%s", nom_cherche);
    trier_A_to_Z();
    int inf = 0;
    int sup = taille - 1;
    int trouve = 0; // verifier si trouver

    while (inf <= sup)
    {
        int mil = (inf + sup) / 2;
        if (strcmp(T[mil].t_nom, nom_cherche) == 0)
        {
            printf("Le livre %s existe dans la bibliothèque.\n", nom_cherche);
            trouve = 1;
            break;
        }
        else if (strcmp(T[mil].t_nom, nom_cherche) < 0)
        {
            inf = mil + 1;
        }
        else
        {
            sup = mil - 1;
        }
    }

    if (!trouve)
    {
        printf("Le livre %s n'existe pas dans la bibliothèque.\n", nom_cherche);
    }
}
void suprimer()
{
    char titre_a_sup[20];
    printf("entrer le titre du livre que vous voulez suprimer");
    scanf("%s", titre_a_sup);
    int i = cherche_el(titre_a_sup);
    if (i == -1)
        printf("not found");
    else
    {
        for (int j = i; j < taille - 1; j++)
        {
            T[j] = T[j + 1];
        }
        taille--;
    }
}
int main()
{
    int choix;
    int num2;
    int s = 0, moy = 0; // somme de prix et la moyenne des prix
    do
    {
        printf("------------------------------------------------------------------------------\n");
        printf("**************************************menu************************************\n");
        printf("------------------------------------------------------------------------------\n");
        printf("\n");
        printf("----------  ---------- ----------- -------- -------------  ----------- ----------- ----------\n");
        printf("1=>ajouter 2=>modifier 3=>suprimer 4=>trier 5=>rechercher  6=>statique 7=>afficher 8=>quitter\n");
        printf("---------- ----------- ----------- -------- -------------  ----------- ----------- ----------\n");
        printf("\n");
        printf("entrer votre choix de 1 a 7 : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            printf("--------------------- ----------------------------\n");
            printf("1=>ajouter un element 2=>ajouter plusieurs element\n");
            printf("--------------------- ----------------------------\n");
            scanf("%d", &choix);
            if (choix == 1)
            {
                ajouter();
            }
            else if (choix == 2)
            {
                ajouter_plus();
            }
            break;
        case 2:
            modifier();
            break;
        case 3:
            suprimer();
            break;
        case 4:
            printf("1=>trier A a Z  |  2=>trier Z a A : ");
            scanf("%d", &num2);
            if (num2 == 1)
                trier_A_to_Z();
            else if (num2 == 2)
                trier_Z_to_A();
            break;

        case 5:

            recherche();
            break;
        case 6:

            for (int i = 0; i < taille; i++)
            {
                s += T[i].prix;
                moy = s / taille;
            }
            printf("la moyenne de prix des livre est : %d ", moy);
            break;
        case 7:
            afficher();
            break;
        default:
            printf("choisi de 1 a 8");
        }

    } while (choix != 8);
}
