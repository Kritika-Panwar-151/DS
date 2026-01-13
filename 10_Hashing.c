#include <stdio.h>
int HT[20];
int m;


int hashFunction(int key)
{
    return key % m;
}

void insert(int key)
{
    int index = hashFunction(key);

    while (HT[index]!=-1)
    {
        index = (index + 1) % m;
    }

    HT[index] = key;
}

void display()
{

    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++)
    {
        if (HT[i] !=-1)
            printf("Address %d : %d\n", i, HT[i]);
        else
            printf("Address %d : EMPTY\n", i);
    }
}

void main()
{


    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        HT[i] =-1;

    int n;
    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    int key;
    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
