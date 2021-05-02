#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int choise;
//student struct
typedef struct Students{
    char name[30];
    int age;
    int id;
    float grades[6] ;
    char level[10];
    char email[30];

}Student;
//--------------------------------------------------------------------------
//Files name
FILE * v1ptr;
FILE * v2ptr;
FILE * v3ptr;
FILE * v4ptr;

//--------------------------------------------------------------------------
// linked list code

struct Node {
  Student item;
  struct Node* next;
};
struct Node *head = NULL;
struct Node *current = NULL;
//insert node at the End of the linked list
void insert(Student data){};
//delete item from the linked list
void Remove(int key){};
//view linked list items
void display(){};
//to sort the linked list in Alphabetical order
void sort(){};
//----------------------------------------------------------------------------
//main function

int main(void)
{
    menu();
    return 0;
}

//-----------------------------------------------------------------------------
//menu function
void menu()
{
    system("cls");
    system("color 9");
    system("title STUDENTS DATABASE MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t \xB10 STUDENTS DATABASE MANAGEMENT SYSTEM \xB11\n-----------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Add New Student\n\t\t2.Update Information Of Existing Student\n\t\t3.Check The Details Of Existing Student\n\t\t4.Removing Student\n\t\t5.View Students's list\n\t\t6.Exit\n\n\n\n\n\t\t\xB10 Enter your choice: ");
    scanf("%d",&choise);
    switch (choise)
    {
    case 1 :Add_Student();
    break;
    case 2 :Update_Student_Info();
    break;
    case 3 :Display_Student_Info();
    break;
    case 4 :Remove_Student();
    break;
    case 5 :Display_All_Info();
    break;
    case 6 : Exit();
    }


}
//to save linked list nodes in the file
void save_in_File(){};
//to sort the file in Alphabetical order
void sort_file(FILE *ptr){};
//to add student to linked list then save it in the file
void Add_Student()
{
    system("cls");
    system("color 6");
    system("title Adding New Student .........");

    Student add, cheek;
    int level_choise = 0;
    char fname[15],s_id[10];


    do{
        system("cls");
        printf("\xB10 Choose The Student Level:\n\t\t 1- Level 1\n\t\t 2- Level 2\n\t\t 3- Level 3\n\t\t 4- Level 4\n\xB10 Enter Choise : ");
        scanf("%d",&level_choise);
    }while(level_choise>4 || level_choise<1);

    printf("\nEnter Student Id :");
    scanf("%d",&add.id);
    /*
        if the id exists or not
    */
    printf("\nEnter Student Name : ");
    fflush(stdin);
    gets(add.name);
    printf("\nEnter Student Age :");
    scanf("%d",&add.age);

    printf("\nEnter The student Grades  (if there is no grades yet put Zeros ) :\nSubject 1: ");
    scanf("%f",&add.grades[0]);
    printf("Subject 2: ");
    scanf("%f",&add.grades[1]);
     printf("Subject 3: ");
    scanf("%f",&add.grades[2]);
     printf("Subject 4: ");
    scanf("%f",&add.grades[3]);
     printf("Subject 5: ");
    scanf("%f",&add.grades[4]);
     printf("Subject 6: ");
    scanf("%f",&add.grades[5]);


    for(int i=0;add.name[i]!=' ';i++)
    {
        fname[i]=add.name[i];
    }
     strcpy(add.email,fname);
     sprintf(s_id,"%d",add.id);
     strcat(add.email,s_id);
     strcat(add.email,"@winter.com");
     delay("Saving.");

};
//to search in the files for a student info
void search(FILE * ptr,int key){};
//updates student info form the file
void Update_Student_Info(){};
//view student info form the file
void Display_Student_Info(){};
//delete student info from the file
void Remove_Student(){};
//view all student info from the files
void Display_All_Info(){};
//Exit screen function
void Exit()
{
    system("cls");
    system("color 4");
    system("title Program Ended");
    delay("Ending.");
    printf("\n\n\n\n\t\t\t\t This C Program Was developed  By :\n\n\n\t\t\t\t\t\xB10 AbdElrahman Khaled\n\n\t\t\t\t\t\xB10 Hager Mohamed\n\n\t\t\t\t\t\xB10 Karem Atef\n\n\t\t\t\t\t\xB10 Mohamed AbdElaziz\n\n\t\t\t\t\t\xB10 Mohamed Adel\n\n\n\n\n\n\n\n");
    sleep(5);
};
//To delay nicely
void delay(char word[15])
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s",word);
    sleep(1);
    printf(".");
     sleep(1);
    printf(".");
     sleep(1);
    printf(".");
     sleep(1);
    printf(".");
     sleep(1);
    printf(".");
    system("cls");
}
