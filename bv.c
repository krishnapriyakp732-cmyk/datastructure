#include<stdio.h>
#include<ctype.h>

char univ_set[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

char set1[26], set2[26];
int bit_vec1[26], bit_vec2[26], result[26];

void initializeSet(char ary[26])
{
    for(int i = 0; i < 26; i++)
    {
        bit_vec1[i] = 0;
        bit_vec2[i] = 0;
        result[i] = 0;
    }
}

void bitVector(char ary[], int num, int bit[])
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            char c = tolower(ary[i]);
            if(c == univ_set[j])
                bit[j] = 1;
        }
    }
}

void setUnion(int bit1[26], int bit2[26])
{
    for(int i = 0; i < 26; i++)
    {
        result[i] = bit1[i] | bit2[i];
    }
}

void setintersection(int bit1[26], int bit2[26])
{
    for(int i = 0; i < 26; i++)
    {
        result[i] = bit1[i] & bit2[i];
    }
}

void setComplement(int bit[26])
{
    for(int i = 0; i < 26; i++)
    {
        if(bit[i] == 0)
            result[i] = 1;
        else
            result[i] = 0;
    }
}

// Corrected setDifference using temp array
void setDifference(int bit1[26], int bit2[26])
{
    int temp[26];
    for(int i=0;i<26;i++)
        temp[i] = bit2[i];

    setComplement(temp);            // complement of set2 in temp
    setintersection(bit1, temp);    // intersection of set1 and complement
}

void printResult()
{
    printf("\nResult Set: ");
    for(int i = 0; i < 26; i++)
    {
        if(result[i] == 1)
            printf("%c ", univ_set[i]);
    }
    printf("\n");
}

int main()
{
    int num1, num2, choice;

    initializeSet(set1);

    printf("Enter the number of elements in Set1: ");
    scanf("%d", &num1);

    printf("Enter the Set1 elements: ");
    for(int i = 0; i < num1; i++)
        scanf(" %c", &set1[i]);

    printf("Enter the number of elements in Set2: ");
    scanf("%d", &num2);

    printf("Enter the Set2 elements: ");
    for(int i = 0; i < num2; i++)
        scanf(" %c", &set2[i]);

    bitVector(set1, num1, bit_vec1);
    bitVector(set2, num2, bit_vec2);

    while(1)
    {
        printf("\n---- MENU ----");
        printf("\n1. Union");
        printf("\n2. Intersection");
        printf("\n3. Complement of Set1");
        printf("\n4. Difference (Set1 - Set2)");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            setUnion(bit_vec1, bit_vec2);
            printResult();
        }
        else if(choice == 2)
        {
            setintersection(bit_vec1, bit_vec2);
            printResult();
        }
        else if(choice == 3)
        {
            setComplement(bit_vec1);
            printResult();
        }
        else if(choice == 4)
        {
            setDifference(bit_vec1, bit_vec2); 
            printResult();
        }
        else if(choice == 5)
        {
            printf("\nExiting...\n");
            break;
        }
        else
        {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}

