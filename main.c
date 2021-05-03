#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
void insert(Student data){
    struct Node* newnode=( struct Node*)malloc(sizeof(newnode));
newnode->item=data;
if (head==NULL)
{
    head=newnode;
    newnode->next=NULL;
}
else{
    current=head;
    while (current->next !=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
}

};
//delete item from the linked list
void Remove(int key){
struct Node *temp1=head;
struct Node *temp2=head;
if(temp1->next ==NULL){
                                            printf("\tThe student information you deleted is\n");
                                                printf("\t*********************************************\n");
                                          printf("\tThe student Name is:%s\n",temp1->item.name);
                                             printf("\tThe Age Email is:%d\n",temp1->item.age);
                                          printf("\tThe student ID is:%d\n",temp1->item.id);
                                         printf("\tThe student grades is:%f\n",temp1->item.grades);
                                        printf("\tThe student level is:%s\n",temp1->item.level);
                                        printf("\tThe student Email is:%s\n",temp1->item.email);


 free(temp1);
 head=NULL;
}else{
while(temp1->next !=NULL){
 temp2=temp1;

 temp1=temp1->next;
 if(temp1->item.id ==key){
            struct Node *temp;
                                         printf("\tThe student information you deleted is\n");
                                             printf("\t*********************************************\n");
                                          printf("\tThe student Name is:%s\n",temp1->item.name);
                                             printf("\tThe Age Email is:%d\n",temp1->item.age);
                                          printf("\tThe student ID is:%d\n",temp1->item.id);
                                         printf("\tThe student grades is:%f\n",temp1->item.grades);
                                        printf("\tThe student level is:%s\n",temp1->item.level);
                                        printf("\tThe student Email is:%s\n",temp1->item.email);
      temp=temp1;
      free(temp1);
      temp2->next=temp->next;
 }

}if(temp1->next ==NULL){
         if(temp2->item.id ==key){
           struct Node *temp;
                     printf("\tThe student information you deleted is\n");
                     printf("\t*********************************************\n");
                                          printf("\tThe student Name is:%s\n",temp2->item.name);
                                             printf("\tThe Age Email is:%d\n",temp2->item.age);
                                          printf("\tThe student ID is:%d\n",temp2->item.id);
                                         printf("\tThe student grades is:%f\n",temp2->item.grades);
                                        printf("\tThe student level is:%s\n",temp2->item.level);
                                        printf("\tThe student Email is:%s\n",temp2->item.email);
      temp=temp1;
      free(temp1);
      temp2->next=NULL;
 }
}
}
};
//view linked list items
void display(){

   current = head;
   if(current!=NULL)
    {
    printf("Name\t\t\tId\t\tAge\t\tLevel\t\tEmail");
        while(current!=NULL)
            {
                printf("\n%s\t%d\t%d\t%s\t%s\t",current->item.name,current->item.id,current->item.age,current->item.level,current->item.email);
                display_grades(current->item.grades);
                current=current->next;
            }
        }
   else
    {
        printf("There is no list yet\n");
    }

};
//to sort the linked list in Alphabetical order
void sort(){
    int i;
    Student temp;
    struct Node *ptr2=NULL;
    struct Node *ptr=NULL;
    for(ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        for(ptr2=ptr->next; ptr2!=NULL; ptr2=ptr2->next)
        {
            i=strcmp(ptr->item.name,ptr2->item.name);
            if(i==1)
            {
                //***************************swapping the data************
                strcpy(temp.name,ptr->item.name);
                strcpy(temp.email,ptr->item.email);
                strcpy(temp.level,ptr->item.level);
                temp.age=ptr->item.age;
                for (int x=0; x<=5; x++)
                {
                    temp.grades[x]=ptr->item.grades[x];
                }
                temp.id=ptr->item.id;
                //-------------------------------------
                strcpy(ptr->item.name,ptr2->item.name);
                strcpy(ptr->item.email,ptr2->item.email);
                strcpy(ptr->item.level,ptr2->item.level);
                ptr->item.age=ptr2->item.age;
                for (int x=0; x<=5; x++)
                {
                    ptr->item.grades[x]=ptr2->item.grades[x];
                }
                ptr->item.id=ptr2->item.id;
                //-------------------------------------
                strcpy(ptr2->item.name,temp.name);
                strcpy(ptr2->item.email,temp.email);
                strcpy(ptr2->item.level,temp.level);
                ptr2->item.age=temp.age;
                for (int x=0; x<=5; x++)
                {
                    ptr2->item.grades[x]=temp.grades[x];
                }
                ptr2->item.id=temp.id;

            }
        }
    }
    ptr2=NULL;
    ptr=NULL;
};
//to check if the linked list is empty or not
bool isEmpty()
{
    if (head ==NULL)return true;
    return false;
}
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

add_student:
    do{
        system("cls");
        printf("\xB10 Choose The Student Level:\n\t\t 1- Level 1\n\t\t 2- Level 2\n\t\t 3- Level 3\n\t\t 4- Level 4\n\xB10 Enter Choise : ");
        scanf("%d",&level_choise);
    }while(level_choise>4 || level_choise<1);

    if(level_choise==1)strcpy(add.level,"level_1");
    else if (level_choise==2)strcpy(add.level,"level_2");
    else if (level_choise==3)strcpy(add.level,"level_3");
    else strcpy(add.level,"level_4");;

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
     head->item = add;
     head->next = NULL;
     display();
     printf("\n\nEnter\n\t\t 1 To Add More Student\n\t\t 2 To Delete Student\n\t\t 3 To Save \n\t\t 4 TO Exit without Saving");
     sleep(3);
    goto add_student;
};
//to search in the files for a student info
bool search(FILE * ptr,int key){};
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
void display_grades(float arr[6])
{   printf("[");
    for(int i=0;i<6;i++){
        printf("%d,",arr[i]);
    }
    printf("]");
}

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
    system("cls");
}
