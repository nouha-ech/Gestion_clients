#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CMAX 10

int choix, x;

typedef struct SClient
{
    int Code_cli;
    char Nom[CMAX];
    char Prenom[CMAX];
} SClient;

SClient clients[20];

void menu();
void sous_menu(int a);
void gerer_client(int a);
void afficher_clients();
void ajouter_client();
void modifier_client();
void supprimer_client();

int main()
{
    menu();
    return 0;
}

void menu()
{
    printf("1- Gestion des clients\n");
    printf("2- Quitter le programme\n");
    printf("Choisir le menu : ");
    scanf("%d", &choix);
    sous_menu(choix);
}

void sous_menu(int a)
{
    if (a == 1)
    {
        printf("1- Ajouter\n");
        printf("2- Modifier\n");
        printf("3- Supprimer\n");
        printf("4- Afficher\n");
        printf("5- Retour\n");
        printf("Choisir un sous menu : ");
        scanf("%d", &x);
        gerer_client(x);
    }
    else if (a == 2)
    {
        exit(0);
    }
    else
    {
        printf("Choix invalide!\n");
        exit(0);
    }
}

void gerer_client(int a)
{
    switch (a)
    {
    case 1:
        ajouter_client();
        break;
    case 2:
        modifier_client();
        break;
    case 3:
        supprimer_client();
        break;
    case 4:
        afficher_clients();
        break;
    case 5:
        menu();
        break;
    default:
        printf("Choix invalide.\n");
        menu();
        break;
    }
}

void ajouter_client()
{
    SClient client;
    FILE *file;

    printf("Code Client : ");
    scanf("%d", &client.Code_cli);
    printf("Nom : ");
    scanf("%s", client.Nom);
    printf("Prenom : ");
    scanf("%s", client.Prenom);

    file = fopen("client.txt", "a");
    fwrite(&client, sizeof(client), 1, file);

    if (fwrite != 0)
        printf("Client ajouté avec succès\n");
    else
        printf("Erreur\n");
    fclose(file);
}

void modifier_client()
{
    SClient client;
    SClient nvClient;
    FILE *file, *nf;

    printf("Code Client à modifier : ");
    scanf("%d", &nvClient.Code_cli);
    printf("Nouveau nom : ");
    scanf("%s", nvClient.Nom);
    printf("Nouveau prénom : ");
    scanf("%s", nvClient.Prenom);

    file = fopen("client.txt", "r");
    nf = fopen("nv.txt", "a");

    while (fread(&client, sizeof(SClient), 1, file))
    {
        if (client.Code_cli == nvClient.Code_cli)
            fwrite(&nvClient, sizeof(nvClient), 1, nf);
        else
            fwrite(&client, sizeof(client), 1, nf);
    }

    fclose(file);
    fclose(nf);
    remove("client.txt");
    rename("nv.txt", "client.txt");
}

void supprimer_client()
{
    SClient client;
    int code;
    FILE *file, *nf;

    printf("Code Client à supprimer : ");
    scanf("%d", &code);

    file = fopen("client.txt", "r");
    nf = fopen("nv.txt", "a");

    while (fread(&client, sizeof(SClient), 1, file))
    {
        if (client.Code_cli != code)
            fwrite(&client, sizeof(client), 1, nf);
    }

    fclose(file);
    fclose(nf);
    remove("client.txt");
    rename("nv.txt", "client.txt");
}

void afficher_clients()
{
    FILE *file;
    SClient client;
    file = fopen("client.txt", "r");

    while (fread(&client, sizeof(SClient), 1, file))
    {
        printf("\nCode client : %d", client.Code_cli);
        printf("\nNom: %s | %s", client.Nom, client.Prenom);
        printf("\n");
    }

    fclose(file);
}
