#include <stdio.h>
#include <stdlib.h>

//never forget stdlib, okay!
//abc

int choise;
//student struct
typedef struct Students{
    char name[30];
    int age;
    int id;
    float grades[6];
    char level[10];
    char email[20];

}Student;
//--------------------------------------------------------------------------
// linked list code

struct Node {
  Student item;
  struct Node* next;
};
struct node *head = NULL;
struct node *current = NULL;
//insert node at the End of the linkedlist
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
void Add_Student(){};
//to search in the files for a student info
void search(){};
//updates student info form the file
void Update_Student_Info(){};
//view student info form the file
void Display_Student_Info(){};
//delete student info from the file
void Remove_Student(){};
//view all student info from the files
void Display_All_Info(){};
//Exit screen function
void Exit(){};
