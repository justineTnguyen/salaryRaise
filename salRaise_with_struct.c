#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 6


struct Employee
{
	char name[20];
	float sal, rate, raise;
	float newSal;
};


//function prototype
void load (struct Employee e[], int n);
void ARate(struct Employee e[], int n);
void calcRaise(struct Employee e[], int n);
void sort(struct Employee e[], int n);
void total(struct Employee e[], int n,float *ts,float *tr,float *tn );
void title();
void print(struct Employee e[], int n);
void printTotals(float ts,float tr, float tn);
void savetext(struct Employee e[], int n);
void gettext(struct Employee e[], int n);
void savebn(struct Employee e[], int n);
void getbn(struct Employee e[], int n);

int main()
{
	//declaration
	struct Employee e[SIZE];
	float ts,tr,tn;

	//load data into struct, calculate raises, salaries and new salaries and print the //original array of struct
	load(e,SIZE);
	ARate(e,SIZE);
	calcRaise(e,SIZE);
    total(e,SIZE,&ts,&tr,&tn);
	printf("Original Array of Structure before Sorting\n\n");
	title();
	print(e,SIZE);
	printTotals(ts,tr,tn);

	//sort the struct of array and print the sorted struct of array
	sort(e,SIZE);
	total(e,SIZE,&ts,&tr,&tn);
	printf("Array of Structure after Sorting\n\n");
	title();
	print(e,SIZE);
	printTotals(ts,tr,tn);

	//**************Section for text files*****************
	printf("\n\n");
	printf("From Save Text file\n\n");
	title();

	//save the struct of array to a text file
	savetext(e,SIZE);

	//retrieve the text file and print the data
	gettext(e,SIZE);
	print(e,SIZE);
	total(e,SIZE,&ts,&tr,&tn);
	printTotals(ts,tr,tn);

	//**************Section for binary files*****************
	printf("\n\n");
	printf("From Save Binary file\n\n");
	title();

	//save struct of array to a binary file
	savebn(e,SIZE);

	//retrieve data from binary file and print the data
	getbn(e,SIZE);
	print(e,SIZE);
	total(e,SIZE,&ts,&tr,&tn);
	printTotals(ts,tr,tn);

	return 0;
}


void load (struct Employee e[], int n)
{
	//write the codes to let user enter employee’s name and salary
	for(int i = 0; i < n; i++)
    {
        printf("Enter the Employee's name: ");
        gets(e[i].name);

        printf("Enter salary : ");
        scanf("%f", &e[i].sal);

        getchar();
    }

}


void ARate(struct Employee e[], int n)

{
	//assign each employee rate to the struct’s rate data member here by checking salary range
	for(int i = 0; i < n; i++)
    {
        if(e[i].sal >= 0 && e[i].sal < 30000.00)
        {
            e[i].rate = 7.00;
        }
        else if(e[i].sal >= 30000.00 && e[i].sal <= 40000.00)
        {
            e[i].rate = 5.50;
        }
        else //if salary > $40000
        {
            e[i].rate = 4.00;
        }
    }
}


void calcRaise(struct Employee e[], int n)
{
	//calculate the raise and new salary for each employee and store into the
	//struct’s raise and new salary data members
	for(int i = 0; i < n; i++)
    {
        e[i].raise = e[i].sal * e[i].rate/100;
        e[i].newSal = e[i].sal + e[i].raise;
    }
}


void sort(struct Employee e[], int n)
{
	//sort the struct in ascending order
	struct Employee t;

	for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(strcmp(e[j].name, e[j+1].name) > 0)
            {
                t = e[j];
                e[j] = e[j+1];
                e[j+1] = t;
            }
        }
    }
}



void total(struct Employee e[], int n,float *ts,float *tr,float *tn )

{
    *tr = 0.0;
    *tn = 0.0;

	for(int i = 0; i < n; i++)
    {
        *ts += e[i].sal;
        *tr += e[i].raise;
        *tn += e[i].newSal;
    }
}

void title()
{
	printf("\t\t\tCalculation of Salary Raises\n\n");

	printf("Employee\t");     printf("Salary\t\t"); printf("Rate %\t"); printf("  Raise\t\t"); printf("New Salary\n\n");
}


void print(struct Employee e[], int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("%s\t\t", e[i].name); printf("%10.2f\t", e[i].sal); printf("%4.2f\t", e[i].rate);
		printf("%8.2f\t", e[i].raise); printf("%8.2f\t\n", e[i].newSal);
	}
}


void printTotals(float ts,float tr, float tn)
{
	printf("Total\t\t"); printf("%10.2f\t\t", ts); printf("%8.2f\t", tr); printf("%8.2f\n\n", tn);
}


void savetext(struct Employee e[], int n)
{
	//save the struct to text file employees.txt
	FILE *f;
	f = fopen("employees.txt", "w");

	for(int i = 0; i < n; i++)
    {
        fprintf(f, "%s %.2f %.2f %.2f %.2f\n", e[i].name, e[i].sal, e[i].rate, e[i].raise, e[i].newSal);
    }

    fclose(f);
}


void gettext(struct Employee e[], int n)
{
	//retrieve the data from employees.txt file
	FILE *f;
	f = fopen("employees.txt", "r");

	for(int i = 0; i < n; i++)
    {
        fprintf(f, "%s %.2f %.2f %.2f %.2f\n", e[i].name, e[i].sal, e[i].rate, e[i].raise, e[i].newSal);
    }

    fclose(f);
}


void savebn(struct Employee e[], int n)
{
	//save the struct to a binary file employees.bin
	FILE *f;
	f = fopen("employees.bin", "wb");
	fwrite(&e[0], sizeof(e[0]), n, f);

	fclose(f);
}


void getbn(struct Employee e[], int n)
{
	//retrieve the data from the employees.bin file
	FILE *f;
	f = fopen("employees.bin", "rb");
	fread(&e[0], sizeof(e[1]), n, f);

	fclose(f);
}
