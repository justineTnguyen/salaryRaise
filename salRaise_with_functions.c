#include <stdio.h>

//Function prototypes
void load(char* name, double *salary);
double calcRate(double salary);
double calcRaise(double salary, double rate);
double calcNewSalary(double salary, double raise);
void calcTotalSalaries(double *totalSalary, double *totalRaise, double *totalNewSalary,
                       double salary, double raise, double newSalary);
void salaryOutput(char *name, double salary, double rate, double raise, double newSalary);
void totalOutput(double totalSalary, double totalRaise, double totalNewSalary);

int main()
{
    //Declaration
    int numEmployees;
    char name[20];
    double salary, rate, raise;
    double newSalary;
    double totalSalary, totalRaise, totalNewSalary;

    totalNewSalary = 0.0;
    totalSalary = 0.0;
    totalRaise = 0.0;

    printf("How many employees : ");
    scanf("%d", &numEmployees);
    printf("\n");

    for(int i = 0; i < numEmployees; i++)
    {

        getchar(); //clears previous
        load(name, &salary);

        rate = calcRate(salary);
        raise = calcRaise(salary, rate);
        newSalary = calcNewSalary(salary, raise);
        salaryOutput(name, salary, rate, raise, newSalary);
        calcTotalSalaries(&totalSalary, &totalRaise, &totalNewSalary,
                          salary, raise, newSalary);
        printf("\n\n");

    }

    totalOutput(totalSalary, totalRaise, totalNewSalary);

    return 0;
}


//load() let's user input the employee's name and current salary
//and return the name and salary to main()
void load(char *name, double *salary)
{

    printf("Enter the Employee's name: ");
    gets(name);

    printf("Enter salary : ");
    scanf("%lf", salary);

}


//calcRate() finds the rate for the salary and returns rate to main()
double calcRate(double salary)
{

    if(salary > 0 && salary < 30000.00)
    {
        return 0.07;
    }
    else if(salary >= 30000.00 && salary <= 40000.00)
    {
        return 0.055;
    }
    else //if salary > $40000
    {
        return 0.04;
    }

}


//calcRaise() calculates the raise and returns raise
double calcRaise(double salary, double rate)
{

    return salary * rate;

}


//calcNewSalary() calculates the new salary and returns the new salary
double calcNewSalary(double salary, double raise)
{

    return salary + raise;

}


//calcTotalSalaries() calculates the total for the salary, raise, and new salary
//and pass the total salary, total raise, total new salary back to calling function
void calcTotalSalaries(double *totalSalary, double *totalRaise, double *totalNewSalary,
                       double salary, double raise, double newSalary)
{

    *totalSalary += salary;
    *totalRaise += raise;
    *totalNewSalary += newSalary;

}


//salaryOutput() prints the name, salary, rate, raise, and new salary
void salaryOutput(char *name, double salary, double rate, double raise, double newSalary)
{

    printf("\nEmployee's Name   :         %17s\n", name);
    printf("Salary            :         %17.2lf\n", salary);
    printf("Rate              :         %16.1lf%%\n", (rate*100));
    printf("Raise             :         %17.2lf\n", raise);
    printf("New salary        :         %17.2lf\n", newSalary);

}


//totalOutput() prints the total salary, total raise, and total new salary
void totalOutput(double totalSalary, double totalRaise, double totalNewSalary)
{

    printf("Total salary      :         %17.2lf\n", totalSalary);
    printf("Total Raise       :         %17.2lf\n", totalRaise);
    printf("Total New Salary  :         %17.2lf\n", totalNewSalary);

}
