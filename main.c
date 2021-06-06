#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

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
struct Node *head2 = NULL;

//insert node at the End of the linked list
void insert(Student data){
    struct Node* newnode=( struct Node*)malloc(sizeof(struct Node));
    newnode->item=data;
    newnode->next=NULL;
    struct Node *temp;
    if (head==NULL)
    {
        head=newnode;

    }
    else{
        temp=head;
        while (temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }

};
//delete item from the linked list
void Remove(int key){
    int i=0;
struct Node *temp1=head;
struct Node *temp2=head;
if(head ==NULL)
    {
        printf("\t\tList is Empty !!");
        return;
        if(temp1->item.id ==key)
        {
            printf("\tThe student Information you Deleted is\n");
            printf("\t*********************************************\n");
            printf("\tName is:%s\n",temp1->item.name);
            printf("\tAge :%d\n",temp1->item.age);
            printf("\tID :%d\n",temp1->item.id);
            printf("\tGrades : ");
            display_grades(temp1->item.grades);
            printf("\n\tLevel :%s\n",temp1->item.level);
            printf("\tEmail :%s\n",temp1->item.email);
            free(temp1);
            head=NULL;
            i=1;
        }
    }
if(temp1->next ==NULL){
        if(temp1->item.id ==key){
                printf("\tThe student Information you Deleted is\n");
                printf("\t*********************************************\n");
                printf("\tName is:%s\n",temp1->item.name);
                printf("\tAge :%d\n",temp1->item.age);
                printf("\tID :%d\n",temp1->item.id);
                printf("\tGrades : ");display_grades(temp1->item.grades);
                printf("\n\tLevel :%s\n",temp1->item.level);
                printf("\tEmail :%s\n",temp1->item.email);


 free(temp1);
 head=NULL;
 i=1;
        }
}else{
while(temp1->next !=NULL){
 temp2=temp1;

 temp1=temp1->next;
 if(temp1->item.id ==key){
            struct Node *temp;
               printf("\tThe student Information you Deleted is\n");
                printf("\t*********************************************\n");
                printf("\tName is:%s\n",temp1->item.name);
                printf("\tAge :%d\n",temp1->item.age);
                printf("\tID :%d\n",temp1->item.id);
                printf("\tGrades : ");display_grades(temp1->item.grades);
                printf("\n\tLevel :%s\n",temp1->item.level);
                printf("\tEmail :%s\n",temp1->item.email);
      temp=temp1;
      free(temp1);
      temp2->next=temp->next;
      i=1;
 }

}if(temp1->next ==NULL){
         if(temp2->item.id ==key){
           struct Node *temp;
                     printf("\tThe student Information you Deleted is\n");
                printf("\t*********************************************\n");
                printf("\tName is:%s\n",temp1->item.name);
                printf("\tAge :%d\n",temp1->item.age);
                printf("\tID :%d\n",temp1->item.id);
                printf("\tGrades : ");display_grades(temp1->item.grades);
                printf("\n\tLevel :%s\n",temp1->item.level);
                printf("\tEmail :%s\n",temp1->item.email);
      temp=temp1;
      free(temp1);
      temp2->next=NULL;
      i=1;
 }
}
}
if(i!=1){
    printf("\tPlease,Try again!Student ID not founded..........\n" );
}
};
//view linked list items
void display(){
   struct Node *ptr = head;
   if(ptr!=NULL)
    {   printf("\n\n\t\t\t\t\t\xB10\xB10\xB10\xB10\xB10\xB10\xB10 Enterd Data \xB11\xB11\xB11\xB11\xB11\xB11\xB11");
                    printf("\n----------------------------------------------------------------------------------------------------------");

        while(ptr!=NULL)
            {
                printf("\nName : %s\nId : %d\nAge : %d\nLevel : %s\nEmail : %s\nGrades : ",ptr->item.name,ptr->item.id,ptr->item.age,ptr->item.level,ptr->item.email);
                display_grades(ptr->item.grades);
                ptr=ptr->next;
                printf("\n----------------------------------------------------------------------------------------------------------");
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
bool search_List(int key)
{
     struct Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->item.id==key)return true;
            temp = temp->next;
        }
        return false;
}
//----------------------------------------------------------------------------
//functions prototype
void menu();
//to save linked list nodes in the file
void save_in_File();
//to sort the file in Alphabetical order
void sort_file(FILE *ptr);
//to add student to linked list then save it in the file
void Add_Student();
//search in files
bool search(int key);
//updates student info form the file
void Update_Student_Info();
//view student info form the file
void Display_Student_Info();
//delete student info from the file
void Remove_Student();
//view all student info from the files
void Display_All_Info();
//To delay nicely
void delay(char word[15]);
//Exit screen function
void Exit();
//save in file after sorting it
void save_in_File2();
//inserting the data into a linked list to sort it
void insert_node_from_file(Student);
//sorting the data
void sort_file_list();
//loading the data from the file to the linked list
void LoadFile();
//deleting student record
void delete_node_in_file();
//updating student record
void update_node_in_file();

void display_grades(float arr[6]);
//
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
        int choise=0;
    do{
    system("cls");
    system("color 9");
    system("title STUDENTS DATABASE MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t \xB10 STUDENTS DATABASE MANAGEMENT SYSTEM \xB11\n-----------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1. Add New Student\n\n\t\t2. Update Information Of Existing Student\n\n\t\t3. Check The Details Of Existing Student\n\n\t\t4. Removing Student\n\n\t\t5. View Students's list\n\n\t\t6. Exit\n\n\n\n\n\t\t\xB10 Enter your choice: ");
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
    }while(choise > 6 || choise < 1);

}
//to save linked list nodes in the file
void save_in_File()
{
    struct Node *testPtr = head;
    v1ptr=(fopen("student1.txt","a+"));
    v2ptr=(fopen("student2.txt","a+"));
    v2ptr=(fopen("student3.txt","a+"));
    v2ptr=(fopen("student4.txt","a+"));
    for (; testPtr != NULL; testPtr = testPtr->next)
    {
        if (strcmp (testPtr->item.level,"level_1") == 0)
        {
            if(v1ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v1ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5] );

        }
        else if( strcmp(testPtr->item.level,"level_2") == 0)
        {
            if(v2ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v2ptr,"%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5]);
            fclose(v2ptr);

            fprintf(v2ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5] );

        }

        else if ( strcmp(testPtr->item.level,"level_3") == 0)
        {
            if(v3ptr==NULL)
            {
                printf("\nError!\n");
            }

            fprintf(v3ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5] );


        }

        else if ( strcmp(testPtr->item.level,"level_4") == 0)
        {
            if(v4ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v4ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5] );

        }

    }
    head=NULL;

    fclose(v1ptr);
    fclose(v2ptr);
    fclose(v3ptr);
    fclose(v4ptr);
    return ;
}

//to sort the file in Alphabetical order
void sort_file(FILE *ptr){}
//to add student to linked list then save it in the file
void Add_Student()
{

    system("cls");
    system("color 6");
    system("title Adding New Student .........");

    Student add, cheek;
    int level_choise = 0;
    char fname[15],s_id[10];

     add:
    do{
       // system("cls");
        printf("\xB10 Choose The Student Level:\n\t\t 1- Level 1\n\t\t 2- Level 2\n\t\t 3- Level 3\n\t\t 4- Level 4\n\xB10 Enter Choise : ");
        scanf("%d",&level_choise);
        if(level_choise>4 || level_choise<1)printf("\n\t\t\t\tInvalide !!!!!!!!\n");
    }while(level_choise>4 || level_choise<1);

    if(level_choise==1)strcpy(add.level,"level_1");
    else if (level_choise==2)strcpy(add.level,"level_2");
    else if (level_choise==3)strcpy(add.level,"level_3");
    else strcpy(add.level,"level_4");;

    Id:
    printf("\nEnter Student Id :");
    scanf("%d",&add.id);
    if(search_List(add.id))
        {
        printf("\n\t Id Already in use!");
            goto Id;
        }

    if(search(add.id)) {
        printf("\n\t Id Already in use!");
            goto Id;
        }

    printf("\nEnter Student Name : ");
    fflush(stdin);
    scanf("%[^\n]s",&add.name);
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
     insert(add);
     sort();
      display();
        int k=0;
     do{
        here:
        printf("\n\n\t\t\t\t\xB10 Enter\n\t\t\t\t\t 1 To Add More Student\n\t\t\t\t\t 2 To Delete Student\n\t\t\t\t\t 3 To Save \n\t\t\t\t\t 4 TO Exit without Saving\n\t\t\t\t\xB10 Choise : ");
        scanf("%d",&k);
        if(k == 1)goto add;
        else if(k == 2)
        {
            int key;
            printf("\n\xB10 Enter Id To Delete :  ");
            scanf("%d",&key);
            Remove(key);
            goto here;
        }
        else if(k ==3)
        {
            save_in_File(level_choise);
            menu();
        }
        else if(k ==4)Exit();
        if(k>4 || k<1)printf("\n\t\t\t\tInvalide !!!!!!!!\n");
     }while(k >4 || k<0);


}

//to search in the files for a student info
bool search(int key)
{

    int id=0;

char buffer[1000];



if ((v1ptr=fopen("student1.txt","r")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {

        while(!feof(v1ptr))
        {
           fscanf(v1ptr,"%d",&id);
            fgets(buffer,1000,v1ptr);
            if(id==key)
            {
                return 1;
            }
        }
         fclose(v1ptr);

    }
    if ((v2ptr=fopen("student2.txt","r")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {

        while(!feof(v2ptr))
        {
           fscanf(v2ptr,"%d",&id);
            fgets(buffer,1000,v1ptr);
            if(id==key)
            {
                return 1;
            }
        }
         fclose(v2ptr);

    }

    if ((v3ptr=fopen("student3.txt","r")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {

        while(!feof(v3ptr))
        {
           fscanf(v3ptr,"%d",&id);
            fgets(buffer,1000,v1ptr);
                if(id==key)
            {
                return 1;
            }
        }
         fclose(v3ptr);

    }
    if ((v4ptr=fopen("student4.txt","r")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {

        while(!feof(v4ptr))
        {
           fscanf(v4ptr,"%d",&id);
            fgets(buffer,1000,v1ptr);
            if(id==key)
            {
                return 1;
            }
        }
        fclose(v4ptr);

    }


return false;

    }
//updates student info form the file
void Update_Student_Info(){}
//view student info form the file
void Display_Student_Info(){}
//delete student info from the file
void Remove_Student(){}
//view all student info from the files
void Display_All_Info(){}
//Exit screen function
void Exit()
{
    system("cls");
    system("color 4");
    system("title Program Ended");
    delay("Ending.");
    printf("\n\n\n\n\t\t\t\t This C Program Was developed  By :\n\n\n\t\t\t\t\t\xB10 AbdElrahman Khaled\n\n\t\t\t\t\t\xB10 Hager Mohamed\n\n\t\t\t\t\t\xB10 Karem Atef\n\n\t\t\t\t\t\xB10 Mohamed AbdElaziz\n\n\t\t\t\t\t\xB10 Mohamed Adel\n\n\n\n\n\n\n\n");
    sleep(5);
}
void display_grades(float arr[6])
{   printf("[");
    for(int i=0;i<6;i++){
        printf("%.1f,",arr[i]);
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



void insert_node_from_file(Student studentInsert)
{
   struct Node *newNode, *last;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->item=studentInsert;
    if (head2 == NULL)
    {
        head2 = newNode;
        newNode->next = NULL;
    }
    else
    {
        last = head2;
        while(last->next !=NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = NULL;
    }
}




/*function LoadFile*/
void LoadFile()
{
    Student stu;
    FILE *fPtr = fopen("student1.txt", "r");
while (!feof(fPtr))
    {
                    fscanf(fPtr, "%d", &(stu.id));
                    fscanf(fPtr, "%s", stu.level);
                    fgets(stu.name , 20 , fPtr );
                    fscanf(fPtr, "%d", &(stu.age));
                    fgets(stu.email , 29 , fPtr );
                    fscanf(fPtr, "%f", &(stu.grades[0]));
                    fscanf(fPtr, "%f", &(stu.grades[1]));
                    fscanf(fPtr, "%f", &(stu.grades[2]));
                    fscanf(fPtr, "%f", &(stu.grades[3]));
                    fscanf(fPtr, "%f", &(stu.grades[4]));
                    fscanf(fPtr, "%f", &(stu.grades[5]));
    insert_node_from_file(stu);
    }
fclose(fPtr);
}


void save_in_File2(void)
{
    struct Node *testPtr = head2;
    v1ptr=(fopen("student1.txt","w"));
    v2ptr=(fopen("student2.txt","w"));
    v3ptr=(fopen("student3.txt","w"));
    v4ptr=(fopen("student4.txt","w"));


    for (; testPtr != NULL; testPtr = testPtr->next)
    {
        if (strcmp (testPtr->item.level,"level_1") == 0)
        {
            if(v1ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v1ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5] );

        }
        else if( strcmp(testPtr->item.level,"level_2") == 0)
        {
            if(v2ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v2ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5] );

        }

        else if ( strcmp(testPtr->item.level,"level_3") == 0)
        {
            if(v3ptr==NULL)
            {
                printf("\nError!\n");
            }

            fprintf(v3ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5] );


        }

        else if ( strcmp(testPtr->item.level,"level_4") == 0)
        {
            if(v4ptr==NULL)
            {
                printf("\nError!\n");
            }
            fprintf(v4ptr, "%-15d%-10s%-20s%-5d%-29s%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", testPtr->item.id,testPtr->item.level,testPtr->item.name,testPtr->item.age, testPtr->item.email,testPtr->item.grades[0],testPtr->item.grades[1],testPtr->item.grades[2],testPtr->item.grades[3],testPtr->item.grades[4],testPtr->item.grades[5] );

        }

    }
    fclose(v1ptr);
    fclose(v2ptr);
    fclose(v3ptr);
    fclose(v4ptr);
    return ;
}

void sort_file_list(void)
{
    int i;
    Student temp;
   struct Node *ptr2=NULL;
   struct Node *ptr=NULL;
    for(ptr=head2; ptr!=NULL; ptr=ptr->next)
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
}

void delete_node_in_file(){

struct Node *current, *previous;
current = head2;
previous = head2;
int ID;

printf("\nplease enter the ID of the student to remove: ");
scanf("%d" , &ID);
int no_value = 1;
while(current != NULL){
    if (current->item.id == ID){
     no_value = 0;
     break;
    }
    current = current->next;
}
if (no_value == 1){
    printf("the Student not found! \n");
    return;
}
current = head2;
previous = head2;

if (current->item.id == ID){
    head = current->next;
    free(current);
    return;
}
while( current->item.id != ID){
    previous = current;
    current = current->next;
}
previous->next = current->next;
free(current);
printf("the student of ID: %d deleted successfully \n",ID);

sort_file_list();
}


void update_node_in_file(){

struct Node *current, *previous;
current = head2;
previous = head2;
Student s;
printf("\nenter the ID of the student to update the information: ");
scanf("%d", &s.id);


int no_value = 1;
while(current != NULL){
    if (current->item.id == s.id){
     no_value = 0;
     break;
    }
    current = current->next;
}
if (no_value == 1){
    printf("the Student not found! \n");
    return;
}
current = head2;
previous = head2;

printf("\nenter the new name: ");
scanf("\n%[^\n]s", s.name);
int level;
    do
    {
    printf("\nenter the new level: ");
    scanf("%d",&level);
    if(level>4 || level<1)printf("\n\t\t\t\tInvalide !!!!!!!!\n");
    }
    while(level>4 || level<1);

    if(level==1)strcpy(s.level,"level_1");
    else if (level==2)strcpy(s.level,"level_2");
    else if (level==3)strcpy(s.level,"level_3");
    else strcpy(s.level,"level_4");

printf("\nenter the new email: ");
scanf("\n%[^\n]s", s.email);
printf("\nenter the new age: ");
scanf("%d", &s.age);
for(int i=0;i<6;i++){
    printf("\nenter the new grade of subject[%d]: ",i);
    scanf("%f", &s.grades[i]);
}

if (current->item.id == s.id){
current->item = s;
    return;
}
while( current->item.id != s.id){
    previous = current;
    current = current->next;
}

printf("the student of ID: %d updated successfully \n",s.id);

sort_file_list();
}

