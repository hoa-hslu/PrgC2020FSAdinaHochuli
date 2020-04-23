#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50


struct Student
{
	char name[MAX_NAME_LENGTH];
	int age;
};

//function prototypes
void printStudentPassByValue( struct Student inputStudent);
void printStudentPassByReference( struct Student *inputStudent);


int main( int argc, char *argv[])
{

	struct Student student1; // instantiate a Student

	printf("Enter name: ");
	fgets(student1.name, MAX_NAME_LENGTH, stdin);

	printf("Enter age: ");
	scanf("%d", &student1.age);

	printStudentPassByValue( student1 ); // pass by value

	printStudentPassByReference( &student1 ); // pass by reference


	printf("Name orig. Student: %s", student1.name);
	printf("\nAge orig. Student: %d\n", student1.age);


	return EXIT_SUCCESS;
}



void printStudentPassByValue( struct Student inputStudent)
{
	printf("\nStudent information (by value):\n");
	printf(	 "-------------------------------\n");
	printf("Name: %s", inputStudent.name);
	printf("\nAge: %d\n", inputStudent.age);
	inputStudent.age++;
	printf("\nHappy Birthday: %d", inputStudent.age);
}


void printStudentPassByReference( struct Student *inputStudent)
{
	printf("\nStudent information (by reference):\n");
	printf(	 "-------------------------------\n");
	printf("Name: %s", inputStudent->name);
	printf("\nAge: %d\n", inputStudent->age);
	inputStudent->age++;	
}





