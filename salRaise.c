#include<stdio.h>

int main()
{
    //Declaration
    float sal, rate, raise;
    float NewSal, totSal=0.00, totRaise=0.00;
    float totNewSal=0.00;

    //Data/input
        printf("                    Salary      Rate      Raise      New Salary\n");
        printf("-----------------------------------------------------------------\n");
    do
    {
        printf("Salary: ");
        scanf("%f", &sal);

        //Processing/calculations
        if(sal > 0 && sal < 30000)
        {
            rate = 0.07;
        }
        else if(sal >= 30000 && sal <= 40000)
        {
            rate = 0.055;
        }
        else if (sal > 40000)
        {
            rate = 0.04;
        }
        else
        {
            printf("Invalid.");
            return 0;
        }

        raise = sal*rate;
        NewSal = raise + sal;

        totSal = totSal + sal;
        totRaise = totRaise + raise;
        totNewSal = totNewSal + NewSal;

        printf("                 %10.2f%10.2f %10.2f   %10.2f\n",sal,rate*100,raise,NewSal);
    }while(sal != -1);

    //output
    printf("-----------------------------------------------------------------\n");
    printf("Total              %10.2f       %10.2f       %10.2f\n",totSal,totRaise,totNewSal);

    return 0;
}
