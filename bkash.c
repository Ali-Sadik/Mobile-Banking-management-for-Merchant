#include <stdio.h>
#include<string.h>


void welcome(void); //Animated Welcome message 
void delay(void); //Delay loops
void line(void); //Line made with underscores
void wait(void); //Animated "PLease wait..." message
void cancel(void); //to print "cancelled" text

void run(void); //bKash for merchant account main menu

void balanceupdate(float *mainbalance, float *currentbalance); //to update balance after each transaction

void transactiontransfer(int m); //to do "Cash in", "Cash out" 
void flexiload(void); //to do flexiload
void mybkash(void); //contains the submenu of transaction transfer, change pin, check balance and profits

void cashinfile(char number[], float money); //stores the "cash in" datas to the file
void cashoutfile(char number[], float money); //stores the "cash out" datas to the file
void flexifile(char number[], char simcompany[], float money); //stores the "flexiload" datas to the file

void viewcashin(void); //shows the "cash in" datas to the console in tabular form
void viewcashout(void); //shows the "cash out" datas to the console in tabular form
void viewflexiload(void); //shows the "flexiload" datas to the console in tabular form

void updatefilebalance(void); 
void updatefileprofit(void);
void profitcalc(float money);

void filetobalance(void); //imports file data to balance variable
void filetoprofit(void); //imports file data to profit variable

void addmoney(void); //increases the balance
void changepin(void); 
void getpin(void); //imports PIN from the file


int menupin = 0 ; // Initializing PIN, profits and Account balance as global variable
float balance = 0.0 ;
float profit = 0.0 ;




int main()
{
    char str1[5];

    getpin();

    welcome();
    delay();
    delay();
    printf("\n\n\t\t (Developed By Sadik47)\n\t");
    delay();
    delay();
    printf("     Please enter *247# to continue\n\n");
    line();
    // Taking *247# as a string
    gets(str1);

    if (str1[0] == '*' && (str1[1] - '0') == 2 && (str1[2] - '0') == 4 && (str1[3] - '0') == 7 && str1[4] == '#')
    {
        int pin ;
        do
        {
            printf("\nEnter your Menu PIN: ");
            scanf("%d", &pin);
        } while (pin != menupin); //loop will continue untill the user puts authentic PIN

        run(); //main menu appears after authentication
        
    }

    else
        printf("Unfinished");
    return 0;
}




void welcome(void) //Welcome function
{
    delay();
    printf("\t\tW   ");
    delay();
    printf("E   ");
    delay();
    printf("L   ");
    delay();
    printf("C   ");
    delay();
    printf("O   ");
    delay();
    printf("M   ");
    delay();
    printf("E   \n");
    delay();
    printf("\n\n\t\t      To");
    delay();
    printf("\tb");
    delay();
    printf("K");
    delay();
    printf("a");
    delay();
    printf("s");
    delay();
    printf("h");
}

void delay(void) //Delay function
{
    for (int i = 0; i < 999999999; i++)
        ; // Using delay loops after each full stops to make it more animated
}

void line(void)
{

    printf("       _______________________________________\n\n");
    delay;
}

void wait(void) // This is function that shows the output Please wait... with animation

{
    printf("\n\n");
    printf("\t\tPlease wait");
    delay();
    printf(".");
    delay();
    printf(".");
    delay();
    printf(".");
    delay();
    printf("\n\n");
}

void cancel(void)
{
    printf("\nCancelled\n");
}




void run(void)
{
    wait();
    int menu1;
    printf("\nbkash for Merchant account\n");
    printf("1 Cash in\n");
    printf("2 Cash out\n");
    printf("3 Mobile Recharge\n");
    printf("4 My bKash\n");


    printf("Reply : ");
    scanf("%d", &menu1);
    wait();

    switch (menu1) // using switch statement to go through all of the possibilities
    {
    case 1:
    case 2:
        transactiontransfer(menu1); // The function will pass the menu number according to the user input
        break;
    case 3:
        flexiload();
        break;
    case 4:
        mybkash();
        break;


    default:
        break;
    }

    run(); // Using recursion to run program untill the user closes the program manually
}




void balanceupdate(float *mainbalance, float *currentbalance)
{
    *mainbalance = *currentbalance;
    updatefilebalance();
}





void transactiontransfer(int m) // This function is common for "Cash in" and "Cashout"
{

    filetobalance();
    filetoprofit();

    if (m == 1)
        printf("\nEnter Receiver bKash Account No:\n");
    if (m == 2)
        printf("\nEnter the bKash user's number:");
    printf("\n0 Cancel\n");
    printf("Reply :");

    char reply1[11];
    // Here reply1 is the account number to which the money will be transferred
    float amount, newbalancein, newbalanceout;
    scanf("%s", reply1); // taking account number as a string

    wait();
    if ((reply1[0] - '0' == 0) && (reply1[1] - '0' == 1)) // As the number must start with 0 and then 1

    {

        if (reply1[2] - '0' != 1)

        // As we know that in bangladesh there is no telecom company which has 011 series in their number

        {
            printf("\nEnter Amount :");
            scanf("%f", &amount);

            newbalancein = balance - amount;
            newbalanceout = balance + amount ;
            

            wait();

            if (amount != 0 && m == 1)
            {
                printf("\nCash in.\n");

                printf("To : %s\n", reply1);
                printf("Amount : %8.2f/- taka\n", amount);

                wait();

                        printf("\nCash in successful\nCurrent balance : %8.2f/- taka", newbalancein);
                        balanceupdate(&balance, &newbalancein);
                        cashinfile(reply1, amount);
                        profitcalc(amount);
        
            }

            else if (amount != 0 && m == 2)
            {
                printf("\nCash out.\n");
                printf("From : %s\n", reply1);
                printf("Amount : %8.2f/- taka\n", amount);

                wait();
                        printf("\nCash out successful\nCurrent balance : %8.2f/- taka", newbalanceout);
                        balanceupdate(&balance, &newbalanceout);
                        cashoutfile(reply1, amount);
                        profitcalc(amount);
                        
            }

            else
                printf("\nInvalid value");
        }
        else
            cancel();
    }

    else
        cancel();
}

void flexiload(void) //F L E X I L O A D Function
{
    int menu2;
    float amount;
    char number[11], simcompany[17];


    printf("\nbKash\n");
    printf("1 Robi\n");
    printf("2 Airtel\n");
    printf("3 Banglalink\n");
    printf("4 Grameenphone\n");
    printf("5 Teletalk\n");
    printf("6 Mainmenu\n");
    printf("0 Cancel\n\n");

    printf("Reply : ");
    scanf("%d", &menu2);

    int simcode = 0; // Simcode according to the telecom company
    if (menu2 == 1)
    {
        simcode = 8;
        strcpy(simcompany, "Robi");
    }
        
    else if (menu2 == 2)
    {
        simcode = 6;
        strcpy(simcompany, "Airtel");
    }  

    else if (menu2 == 3)
    {
        simcode = 9;
        strcpy(simcompany, "Banglalink");
    }
        
    else if (menu2 == 4)
    {
        simcode = 7;
        strcpy(simcompany, "Grameenphone");
    }
    else if (menu2 == 5)
    {
        simcode = 5;
        strcpy(simcompany, "Teletalk");
    }
    wait();

    switch (menu2)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("Enter Mobile No :");
        scanf("%s", number);
        wait();

            if ((number[0]) - '0' == 0 && (number[1]) - '0' == 1 && (number[2]) - '0' == simcode) // Simcode must match
            {
                printf("\nEnter Amount :");
                scanf("%f", &amount);
                wait();

                if (amount != 0)
                {
                        float newbalanceflexi = balance - amount;
                        printf("\nMobile recharge successful\nCurrent balance : %8.2f/- taka", newbalanceflexi);
                        balanceupdate(&balance, &newbalanceflexi);
                        flexifile(number, simcompany, amount);

                }
                    
                else if (amount < 20) // Minimum recharge is 20 taka
                {
                    printf("\nThe recharge amount is invalid\n");
                }
            }
            else
                printf("\nPlease check the number and try again\n");

            break;
        
    case 6:
        run();
        break;
    case 0:
        cancel();
        break;

    default:
        break;
    }

        
}


void mybkash(void) //M Y B K A S H function
{
    FILE *filein, *fileout ;
    char in ;
    int bkashmenu[2]; //taking as an array
    printf("1.Transaction history\n2.Check balance\n3.Add money\n4.Check profits\n5.Change PIN");
    printf("\n0 Cancel\n");
    printf("Reply : ");
    scanf("%d", &bkashmenu[0]);
    wait();

    if (bkashmenu[0] == 1)
    {
        printf("1.Cash in history\n2.Cash out history\n3.Mobile recharge history");
        printf("\n0 Cancel\n");
        printf("Reply :");
        scanf("%d", &bkashmenu[1]);
        wait();
        if (bkashmenu[1] == 1)
        {
            viewcashin();
        }
        else if (bkashmenu[1] == 2)
        {
            viewcashout();
        }
        else if (bkashmenu[1] == 3)
        {
            viewflexiload();
        }
        else
          cancel();
    }

    else if (bkashmenu[0] == 2)
    {
        filetobalance();
        printf("Your bKash balance is %8.2f/- taka", balance);
    }
    
    else if (bkashmenu[0] == 3)
    {
        addmoney();
    }
    else if (bkashmenu[0] == 4)
    {
        filetoprofit();
        printf("Your bKash profit is %8.2f/- taka", profit);
    }
    else if (bkashmenu[0] == 5)
    {
        changepin();

    }
    
    
    else
        cancel();
    


}




void cashinfile(char number[], float money)
{
    FILE *filein ;

    filein = fopen("Cash_in.txt", "a");
    if (filein == NULL)
    {
        printf("File doesn't exist");
    }
    else
    {
        fprintf(filein, "\n%s\t\t%8.2f\n", number, money);
        fclose(filein);
    }
    

}


void cashoutfile(char number[], float money)
{
    FILE *fileout ;

    fileout = fopen("Cash_out.txt", "a");
    if (fileout == NULL)
    {
        printf("File doesn't exist");
    }
    else
    {
        fprintf(fileout, "\n%s\t\t%8.2f\n", number, money);
        fclose(fileout);
    }
    

}

void flexifile(char number[], char simcompany[], float money)
{
    FILE *fileflexi ;

    printf("\n\n%s\n\n", simcompany);

    fileflexi = fopen("Flexiload.txt", "a");
    if (fileflexi == NULL)
    {
        printf("File doesn't exist");
    }
    else
    {
        fprintf(fileflexi, "\n%s\t%s\t\t%8.2f\n", number, simcompany, money);
        fclose(fileflexi);
    }
    

}




void viewcashin(void)
{
    FILE *filein ;

    filein = fopen("Cash_in.txt", "r");
    if (filein == NULL)
    {
        printf("File doesn't exist");
    }
    else
    {
        char ch;
        while ((ch = fgetc(filein)) != EOF)
        {
            putchar(ch);
        }
    }

    fclose(filein);   

}

void viewcashout(void)
{
    FILE *fileout ;

    fileout = fopen("Cash_out.txt", "r");
    if (fileout == NULL)
    {
        printf("File doesn't exist");
    }
    else
    {
        char ch;
        while ((ch = fgetc(fileout)) != EOF)
        {
            putchar(ch);
        }
    }

    fclose(fileout);   

}

void viewflexiload(void)
{
    FILE *fileflexi ;

    fileflexi = fopen("Flexiload.txt", "r");
    if (fileflexi == NULL)
    {
        printf("File doesn't exist");
    }
    else
    {
        char ch;
        while ((ch = fgetc(fileflexi)) != EOF)
        {
            putchar(ch);
        }
    }

    fclose(fileflexi);  
}




void updatefilebalance(void)
{
    FILE *filebalance;
    filebalance = fopen("balance.txt", "w");
    if (filebalance == NULL)
    {
         printf("File doesn't exist");
    }
    else
    {
        fprintf(filebalance, "%8.2f", balance);
    }
    fclose(filebalance);
    
}

void updatefileprofit(void)
{
    FILE *fileprofit;
    fileprofit = fopen("profits.txt", "w");
    if (fileprofit == NULL)
    {
         printf("File doesn't exist");
    }
    else
    {
        fprintf(fileprofit, "%8.2f", profit);
    }
    fclose(fileprofit);
}

void profitcalc(float money)
{
    profit += (money*4.1)/1000.0 ;
    updatefileprofit();
}




void filetobalance(void)
{
    FILE *filebalance;
    filebalance = fopen("balance.txt", "r");
    if (filebalance == NULL)
    {
         printf("File doesn't exist");
    }
    else
    {
        fscanf(filebalance, "%f", &balance);
    }
    fclose(filebalance);
}

void filetoprofit(void)
{
    FILE *fileprofit;
    fileprofit = fopen("profits.txt", "r");
    if (fileprofit == NULL)
    {
         printf("File doesn't exist");
    }
    else
    {
        fscanf(fileprofit, "%f", &profit);
    }
    fclose(fileprofit);
}




void addmoney(void)
{
    float add;
    printf("\nEnter the amount you want to add:");
    scanf("%f", &add);
    if (add != 0)
    {
        balance += add ;
        updatefilebalance();
        wait();
        printf("%8.2f/- taka has been added to your account", add);
        printf("\n\nCurrent balance is %8.2f/- taka", balance);

        
    }
}

void changepin(void)
{
    FILE *pinfile;
    int p1, p2, p3;
    printf("\n\nEnter your old PIN: ");
    scanf("%d", &p1);
    wait();
    if (menupin == p1)
    {
        printf("\nEnter new PIN: ");
        scanf("%d", &p2);
        printf("\nConfirm new PIN: ");
        scanf("%d", &p3);

        if (p2 == p3)
        {
            printf("\nYour PIN is successfully changed\n");
            menupin = p2 ;
            pinfile = fopen("pins.txt", "w");
            if (pinfile == NULL)
            {
                printf("File doesn't exist");
            }
            else
            {
                fprintf(pinfile, "%d", menupin);
            }
            fclose(pinfile);

            
        }
        else
        {
            printf("\nPIN doesn't match\n");
            changepin();
        }
            

        
    }
    else
    {
        printf("\n\nWrong PIN try again later\n\n");
        changepin();
    }
    

    
}

void getpin(void)
{
    FILE *pinfile;
    pinfile = fopen("pins.txt", "r");
    if (pinfile == NULL)
    {
         printf("File doesn't exist");
    }
    else
    {
        fscanf(pinfile, "%d", &menupin);
    }
    fclose(pinfile);
}



