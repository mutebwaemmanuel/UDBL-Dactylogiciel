

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define motbb "motbbd.txt"
#define max longueur 100

void afficherMenuPrincipal()
{
    int choix;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tUDBL - DACTYLOGICIEL\n\n\n");
    printf("\t\t\t\t\t\tMUTEBWA MALU%BA EMMANUEL\n\n");
    printf("\t\t\t\t\t\tMWAPE MUTANGA CHANELLE\n\n");
    printf("\t\t\t\t\t\tTSHIMANGA KADIMA MERVEDI\n\n");
    printf("\t\t\t\t\t\tMWEMA MPATA JENOVIC\n\n");
    sleep(8);

    printf("\n\t1. Demarrer\n");
    printf("\n\t2. Configurer\n");
    printf("\n\t3. Aide\n");
    printf("\n\t4. Quitter\n");
    printf("\n\tVotre choix: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        demarrerJeu();
        break;
    case 2:
        configurerJeu();
        break;
    case 3:
        afficherAide();
        break;

    }

}



void afficherAide()
{
    printf("UDBL - DACTYLOGICIEL - Aide\n");
    printf("\nDescription: UDBL-DACTYLOGICIEL est un jeu qui permet de s'entralner à la saisie rapide au clavier.\n");
    printf("\nVersion: 1.0\n");
    printf("\nConcepteurs: MUTEBWA MALUMBA EMMANUEL\n\t\t MWAPE MUTANGA CHANNELLE\n\t\t TSHIMANGA KADIMA MERVEDI\n\t\t MWEMA MPATA JENOVIC\n");
    printf("\nDate de conception: JUIN 2024\n");
    printf("\nAppuyez sur une touche pour revenir au menu principal...");
    getchar();

}
  void Facile()
    {
        printf("Bienvenu dans le niveau facile\n");

    }
    void Difficile()
    {
        printf("Bienvenu dans le niveau difficile\n");
    }
    void Aleatoire()
    {
        printf("Bienvenu dans le niveau aleatoire\n");
    }
void configurerJeu()
{
      FILE *f =NULL;
      f=fopen("mots.txt","w");
      if(f!=NULL);
      {
          fprintf(f,"monsieur\nmadame\nmaman\nsalle\nmoment\nvoiture\courant\nmaison\nfemme\nhomme\nfillette\n");
          fclose(f);
        }
}
void lecture_du_fichier()
{
    FILE *f=fopen("mots.txt","r");
    signed char texte[256];
    if(f==NULL)
    {
        exit(1);
    }
    while(fgets(texte,225,f) !=NULL)
    {
        printf("%s",texte);
    }
    fclose(f);
}


void demarrerJeu()
{

    struct Joueur
    {
        char pseudo[50];
        int score;
        int temps;

    };
    struct Joueur j[2];
    int nombreMots, i;
    char mot[100], motSaisi[100];
    clock_t tempsDebut, tempsFin;
    int niveau;

    // Initialisation des joueurs
    printf("UDBL - DACTYLOGICIEL - Jeu\n");

    printf("Pseudo joueur 1: ");
    scanf("%s", j[0].pseudo);
    printf("Pseudo joueur 2: ");
    scanf("%s", j[1].pseudo);
    printf("Nombre de mots à saisir: ");
    scanf("%d", &nombreMots);
    printf("choisissez le niveau du jeu\n: ");
    printf("1. Facile\n: ");
    printf("2. Difficile\n: ");
    printf("3. Aleatoire\n: ");
    printf("Votre choix: ");
    scanf("%d", &niveau);
        switch (niveau)
    {
    case 1:
        Facile();
        break;
    case 2:
        Difficile();
        break;
    case 3:
        Aleatoire();
        break;
    default:
        printf("Choix invalide\n");

    }


    // Initialisation des scores et des temps

    // Génération aléatoire des mots
    srand(time(NULL));
    for (i = 0; i < nombreMots; i++)
    {
        // TODO: Générer un mot aléatoire et le stocker dans la variable "mot"
        printf("Mot %d: %s\n", i + 1, mot);

        // Saisie des mots par le joueur 1
        tempsDebut = clock();
        printf("%s: ", j[0].pseudo);
        scanf("%s", motSaisi);
        tempsFin = clock();
        j[0].temps += (tempsFin - tempsDebut);

        // Vérification de la saisie du joueur 1
        if (strcmp(mot, motSaisi) == 0)
        {
            j[0].score++;
            printf("%s: Correct!\n", j[0].pseudo);
        }
        else
        {
            printf("%s: Incorrect! Le mot correct est: %s\n", j[0].pseudo, mot);
        }

        // Saisie des mots par le joueur 2
        tempsDebut = clock();

        scanf("%s", motSaisi);
        tempsFin = clock();

        // Vérification de la saisie du joueur 2
        if (strcmp(mot, motSaisi) == 0)
        {
            j[1].score++;
            printf("%s: Correct!\n", j[1].pseudo);
        }
        else
        {
            printf("%s: Incorrect! Le mot correct est: %s\n", j[1].pseudo, mot);
        }

    }
}
int main()

{
    afficherMenuPrincipal();
    signed char texte[100];
    configurerJeu();
    lecture_du_fichier();



    return 0;
}

