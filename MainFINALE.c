#include <stdio.h>
#include <stdlib.h>
#include "Automate.h"

int main() {
    char nomFichier[25];
    char mot[100];  // Taille du mot à tester
    int continuer;

    do {
        printf("Entrez 0 pour quitter ou 1 pour tester un automate : ");
        scanf("%d", &continuer);
        if (continuer == 0) {
            printf("Fin du programme.\n");
            break;
        }

        printf("Quel automate voulez-vous utiliser ? ");
        scanf("%s", nomFichier);

        Automate *automate = chargerAutomate(nomFichier);

        testAutomate(automate);

        char*** notreAutomate = creationAutomate(*automate);

        afficherAutomate(notreAutomate, automate->nbEtats, automate->nbSymboles);

        printf("\nVoulez-vous standardiser l'automate ? (1 = Oui, 2 = Non) : ");
        int choix;
        scanf("%d", &choix);

        if (choix == 1) {
            printf("Standardisation en cours...\n");
            StandardiserAutomate(automate);
            testAutomate(automate);

            notreAutomate = creationAutomate(*automate);

            afficherAutomate(notreAutomate, automate->nbEtats, automate->nbSymboles);
        }

        printf("\nVoulez-vous voir si l'automate est determiniser? (1 = Oui, 2 = Non) : ");
        scanf("%d", &choix);
        if (choix == 1) {
            bool isDeter = false;
            printf("Determiniser en cours...\n");
            isDeter = isDeterminiser(automate);
            printf("%s", isDeter ? "Determiniser" : "pas determiniser");
            testAutomate(automate);
        }

        printf("Voulez-vous voir si l'automate est complet ? (1 = Oui, 2 = Non) :  ");
        scanf("%d", &choix);
        if (choix == 1) {
            bool isComp = false;
            printf("Traitement en cours...\n");
            isComp = isComplet(automate);
            printf("%s", isComp ? "Complet" : "pas complet");
            testAutomate(automate);
        }

        printf("voulez-vous determiniser l'automate ? (1 = Oui, 2 = Non) : ");
        scanf("%d", &choix);
        if (choix == 1) {
            Automate AD = Determiniser(automate);
            for (int i = 0; i < AD.tailleEntrees; i++) {
                printf("la valeur est %s", *AD.entrees);
            }
            testAutomate(&AD);

            notreAutomate = creationAutomate(AD);

            afficherAutomate(notreAutomate, AD.nbEtats, AD.nbSymboles);
        }

        printf("Entrez un mot à tester : ");
        scanf("%s", mot);
        testerMot(automate, mot);


        // Libération de la mémoire
        int choix2;
        printf("Voulez vous afficher l'automate complémentaire ? (1 = Oui, 2 = Non) : ");
        scanf("%d", &choix2);
        if (choix2 == 1)
        {
            Automate *complementaire = Automate_complementaire(automate);
            printf("\n--- Automate Complémentaire ---\n");
            testAutomate(complementaire);

            notreAutomate = creationAutomate(*complementaire);
            afficherAutomate(notreAutomate, complementaire->nbEtats, complementaire->nbSymboles);
        }
        



    } while (continuer != 0);

    return 0;
}
