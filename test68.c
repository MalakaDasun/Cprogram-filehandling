# include <stdio.h>

int main(void)
{
    FILE *cfptr;
    char name[10],type;
    int count[3] = {0};

    cfptr = fopen("appointment.dat","w+");

    if(cfptr == NULL)
    {
        printf("The file creataion is not successfull!");
        return 0;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("Plz enter the name >> ");
        scanf("%s", &name);

        printf("Plz enter the appointmet type >> ");
        scanf(" %c", &type);

        fprintf(cfptr,"%s    %c\n", name,type);
    }

    fclose(cfptr);

    cfptr = fopen("appointment.dat","r");

    if(cfptr == NULL)
    {
        printf("file doesnt exist!");
        return 0;
    }

    fscanf(cfptr,"%s   %c",&name,&type);

    while(!feof(cfptr))
    {
        if(type == 'C' || type == 'c')
        {
            count[0]++;
        }
        else if(type == 'T' || type == 't')
        {
            count[1]++;
        }
        else if(type == 'S' || type == 's')
        {
            count[2]++;
        }

        fscanf(cfptr,"%s   %c",&name,&type);
    }

    fclose(cfptr);

        printf("Consultant >> %d\n",count[0]);
        printf("test >> %d\n", count[1]);
        printf("scan >> %d\n", count[2]);


    return 0;
}