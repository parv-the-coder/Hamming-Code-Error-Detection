#include <stdio.h>
#include <math.h>

void seven_bit()
{
    int ham[12], i, c, c1, c2, c3, c4, rec[12]; 
    printf("\nEnter the data bits:\n");
    for (i = 1; i <= 11; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 8)
        {
            continue;
        }
        else
        {
            scanf("%d", &ham[i]);
        }
    }
    
    ham[1] = ham[3] ^ ham[5] ^ ham[7] ^ ham[9] ^ ham[11];

    ham[2] = ham[3] ^ ham[6] ^ ham[7] ^ ham[10] ^ ham[11];

    ham[4] = ham[5] ^ ham[6] ^ ham[7];

    ham[8] = ham[9] ^ ham[10] ^ ham[11];

    printf("\nHamming code is: ");

    for (i = 1; i <= 11; i++)
    {
        printf("%d ", ham[i]);
    }
    printf("\nParity bits are: ");

    for (i = 1; i <= 11; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 8)
        {
            printf("%d ", ham[i]);
        }
    }

    printf("\nEnter data on receiver side:\n");

    for (i = 1; i <= 11; i++)
    {
        scanf("%d", &rec[i]);
    }

    c1 = rec[1] ^ rec[3] ^ rec[5] ^ rec[7] ^ rec[9] ^ rec[11];

    c2 = rec[2] ^ rec[3] ^ rec[6] ^ rec[7] ^ rec[10] ^ rec[11];

    c3 = rec[4] ^ rec[5] ^ rec[6] ^ rec[7];

    c4 = rec[8] ^ rec[9] ^ rec[10] ^ rec[11];

    c = c4 * 8 + c3 * 4 + c2 * 2 + c1 * 1;

    if (c == 0)
    {
        printf("Congratulations!\nData Transmission is succesfull without any error.\n");
    }
    else
    {
        printf("\nError on the postion: %d\nThe correct message is: ", 12 - c);
        if (rec[c] == 0)
        {
            rec[c] = 1;
        }
        else
        {
            rec[c] = 0;
        }

        for (i = 1; i <= 11; i++)
        {
            printf("%d ", rec[i]);
        }
    }
}
void four_bit()
{
    int ham[8], i, c, c1, c2, c3, c4, rec[8]; 
    printf("\nEnter the data bits:\n");
    for (i = 1; i <= 7; i++)
    {
        if (i == 1 || i == 2 || i == 4)
        {
            continue;
        }
        else
        {
            scanf("%d", &ham[i]);
        }
    }
    
    ham[1] = ham[3] ^ ham[5] ^ ham[7];

    ham[2] = ham[3] ^ ham[6] ^ ham[7];

    ham[4] = ham[5] ^ ham[6] ^ ham[7];

    printf("\nHamming code is: ");

    for (i = 1; i <= 7; i++)
    {
        printf("%d ", ham[i]);
    }
    printf("\nParity bits are: ");

    for (i = 1; i <= 7; i++)
    {
        if (i == 1 || i == 2 || i == 4)
        {
            printf("%d ", ham[i]);
        }
    }

    printf("\nEnter data on receiver side:\n");

    for (i = 1; i <= 7; i++)
    {
        scanf("%d", &rec[i]);
    }

    c1 = rec[1] ^ rec[3] ^ rec[5] ^ rec[7];

    c2 = rec[2] ^ rec[3] ^ rec[6] ^ rec[7];

    c3 = rec[4] ^ rec[5] ^ rec[6] ^ rec[7];

    c = c3 * 4 + c2 * 2 + c1 * 1;

    if (c == 0)
    {
        printf("Congratulations!\nData Transmission is succesfull without any error.\n");
    }
    else
    {
        printf("\nError on the postion: %d\nThe correct message is: ", 8 - c );
        if (rec[c] == 0)
        {
            rec[c] = 1;
        }
        else
        {
            rec[c] = 0;
        }

        for (i = 1; i <= 7; i++)
        {
            printf("%d ", rec[i]);
        }
    }
}

int main()
{
    int k;
    printf("\nEnter your choice for data transmission:\n 1)4-bit\n 2)7-bit \n ");
    scanf("%d", &k);
    switch (k)
    {
    case 1:
        four_bit();
        break;
    case 2:
        seven_bit();
        break;
    default:
        printf("Invalid Input");
        return;
        break;
    }
    getch();
    return 0;
}
