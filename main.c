#include <stdio.h>
#include "utilities/utilities.h"
#include "utilities/structure.h"
int i;
char viewer();
char manager();
int main()
{
start:
    cls();
    int choice;
    printf("================================================================================\n");
    printf("\n\t\t----Password Manager----\n");
    printf("\n 1. Add Crediential");
    printf("\n 2. View All Crediential");
    printf("\n Enter Your Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        manager();
        goto start;
        break;
    case 2:
        viewer();

        break;
    default:
        printf("Your Choice is Invalid");
        break;
    }

    return 0;
}
char manager()
{
    crediential r1;
    cls();
    printf("================================================================================\n");
    printf("\t\t----Store Your Credential----\n");

    FILE *fp;
    fp = fopen("utilities/cred.bin", "ab");

    getchar();
    printf("\n Enter Account type:");
    fgets(r1.acc, sizeof(r1.acc), stdin);
    printf("\n Enter User Id:");
    fgets(r1.userid, sizeof(r1.userid), stdin);
    printf("\n Enter Email Id:");
    fgets(r1.mail, sizeof(r1.mail), stdin);
    printf("\n Enter Password:");
    fgets(r1.password, sizeof(r1.password), stdin);
    fwrite(&r1, sizeof(r1), 1, fp);
    i++;
    fclose(fp);
}
char viewer()
{
    crediential r2;
    cls();
    printf("================================================================================\n");
    printf("\t\t----All Your Credential----\n");
    FILE *fp;
    fp = fopen("utilities/cred.bin", "rb");
    while (fread(&r2, sizeof(r2), 1, fp))
        printf(" \n\nUser Id: %s Account Type: %s Mail Id: %s Password: %s\n\n", r2.acc, r2.userid, r2.mail, r2.password);
    fclose(fp);
    printf("\n================================================================================\n");
}