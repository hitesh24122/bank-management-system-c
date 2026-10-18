#include <stdio.h>
struct bankmangement
{
    char name[100];
    int id;
    float amount;
};
int main()
{
    int add_account_limit;
    printf("enter number of account you add all time:");
    scanf("%d", &add_account_limit);
    if (add_account_limit <= 0)
    {
        printf("invaid limit\n");
    }
    else
    {
        struct bankmangement n[add_account_limit], i[add_account_limit], f[add_account_limit];
        int count = 0;
        while (1)
        {
            int choice;
            printf("1. Create Account\n2. Display All Accounts\n3. Deposit Money\n4. Withdraw Money\n5. Search Account\n6. Find Richest Customer\n7. Total Bank Balance\n8. Exit\n\n");
            printf("enter your choice:");
            scanf("%d", &choice);
            printf("\n");
            if (choice == 1)
            {
                if (add_account_limit <= count)
                {
                    printf("Account limit reached!\n");
                }
                else
                {
                    printf("enter id:");
                    scanf("%d", &i[count].id);
                    if (count == 0)
                    {
                        printf("enter name:");
                        scanf("%s", &n[count].name);
                        printf("enter amount:");
                        scanf("%f", &f[count].amount);
                        if (f[count].amount < 0)
                        {
                            f[count].amount = 0;
                            printf("you intial amount is invaid now you account balance is 0;\n\n");
                        }
                        count++;
                    }
                    else
                    {
                        int duplicate = 0;
                        for (int j = 0; j < count; j++)
                        {
                            if (i[count].id == i[j].id)
                            {
                                printf("duplicate id found\n");
                                duplicate = 1;
                            }
                        }
                        if (duplicate == 0)
                        {
                            printf("enter name:");
                            scanf("%s", &n[count].name);
                            printf("enter amount:");
                            scanf("%f", &f[count].amount);
                            if (f[count].amount < 0)
                            {
                               f[count].amount = 0;
                               printf("you intial amount is invaid now you account balance is 0;\n\n");
                            }
                            count++;
                        }
                    }
                }
            }
            else if (choice == 2)
            {
                if (count == 0)
                {
                    printf("not data\n\n");
                }
                else
                {
                    for (int j = 0; j < count; j++)
                    {
                        printf("name : %s\nid : %d\namount : %.2f\n\n", n[j].name, i[j].id, f[j].amount);
                    }
                }
            }
            else if (choice == 3)
            {
                int id_no, found = 0;
                float add_amount;
                printf("enter id you want to deposit money:");
                scanf("%d", &id_no);
                for (int j = 0; j < count; j++)
                {
                    if (id_no == i[j].id)
                    {
                        found = 1;
                        printf("enter amount you want to add:");
                        scanf("%f", &add_amount);
                        if (add_amount <= 0)
                        {
                            printf("invaid amount deposit\n\n");
                        }
                        else
                        {
                            f[j].amount = f[j].amount + add_amount;

                            printf("amount successfully add\n");
                            int show;
                            printf("you want to show our account amount Yes(1)/no(0):");
                            scanf("%d", &show);
                            if (show == 1)
                            {
                                printf("name : %s\nid :%d\namount : %.2f\n", n[j].name, i[j].id, f[j].amount);
                                printf("Thank you\n\n");
                            }
                            else
                            {
                                printf("Thank you\n\n");
                            }
                        }
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("your data not found\n\n");
                }
            }
            else if (choice == 4)
            {
                int id_no, found = 0;
                float amount;
                printf("enter id you want to withdrow:");
                scanf("%d", &id_no);
                for (int j = 0; j < count; j++)
                {
                    if (id_no == i[j].id)
                    {
                        printf("enter amouont you want to withdrow:");
                        scanf("%f", &amount);
                        found = 1;
                        if (amount <= 0)
                        {
                            printf("invaid withdrow\n\n");
                        }
                        else if (f[j].amount < amount)
                        {
                            printf("you back account not money to withdrow\n");
                            printf("Thank you\n\n");
                        }
                        else
                        {
                            f[j].amount = f[j].amount - amount;
                            printf("amount withdrow successfully\n");
                            int show;
                            printf("you want to show account yes(1)/no(0):");
                            scanf("%d", &show);
                            if (show == 1)
                            {
                                printf("name : %s\nid : %d\namount : %.2f\n", n[j].name, i[j].id, f[j].amount);
                                printf("Thank you\n\n");
                            }
                            else
                            {
                                printf("Thank you\n\n");
                            }
                        }
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("no data found\n");
                }
            }
            else if (choice == 5)
            {
                int id_no, found = 0;
                printf("enter id you want to search:");
                scanf("%d", &id_no);
                for (int j = 0; j < count; j++)
                {
                    if (i[j].id == id_no)
                    {
                        printf("name : %s\nid : %d\namount : %.2f\n", n[j].name, i[j].id, f[j].amount);
                        found = 1;
                        printf("Thank you\n\n");
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("data not found\n\n");
                }
            }
            else if (choice == 6)
            {
                if (count == 0)
                {
                    printf("not data \n\n");
                }
                else
                {
                    float richest;
                    int counter = 0;
                    richest = f[0].amount;
                    for (int j = 0; j < count; j++)
                    {
                        if (f[j].amount > richest)
                        {
                            richest = f[j].amount;
                            counter = j;
                        }
                    }
                    printf("Name : %s\nid : %d\namount : %.2f\n\n", n[counter].name, i[counter].id, f[counter].amount);
                }
            }
            else if (choice == 7)
            {
                if (count == 0)
                {
                    printf("not data\n\n");
                }
                else
                {
                    float bank_balance = 0;
                    for (int j = 0; j < count; j++)
                    {
                        bank_balance = bank_balance + f[j].amount;
                    }
                    printf("Total bank balance %.2f\n\n", bank_balance);
                }
            }
            else if (choice == 8)
            {
                printf("thank you for visiting\n");
                printf("Exiting.......\n\n");
                break;
            }
            else
            {
                printf("you enter wrong choice\n\n");
            }
        }
    }
    return 0;
}