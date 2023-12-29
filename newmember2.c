#include <stdio.h>
#include <string.h>
#include <conio.h>

// defining structure
struct Details
{
    int mem_ID;
    char f_Name[20];
    char l_Name[20];
    char email[30];
};
// function to get details from the member to create new account
void newAccount(struct Details *mem_ptr)
{
    // used pointers instead of structure variables
    printf("\nEnter your first name: \n");
    gets(mem_ptr->f_Name);
    printf("Enter your last name: \n");
    gets(mem_ptr->l_Name);
    printf("Enter your email address:\n");
    gets(mem_ptr->email);

    // ID needs to be assign
    // YE DEKHLO KESAY KARNA HAY
}
// function for storing details which member entered into a file
int storingdetails(struct Details *mem_ptr)
{
    FILE *fileptr;
    fileptr = fopen("members_details.txt", "a+");
    if (fileptr == NULL)
    {
        printf("File can't be opened");
        return 1;
    }
    // needs to be upgraded with the Member ID
    fprintf(fileptr, "%s %s %s\n", mem_ptr->f_Name, mem_ptr->l_Name, mem_ptr->email);
    fclose(fileptr);
    return 0;
}
int main()
{
    struct Details member;
    printf("Do you want to become a member(y/n)?");
    char ch = getch();
    if (ch == 'y' || ch == 'Y')
    {
        newAccount(&member);
        storingdetails(&member);
    }
}