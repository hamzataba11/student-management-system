#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Student{
  char name[50];
  int age;
  int ID;
};

struct Student students[100];


int studentcount=0;

void savestudent();
void backtomenu();

void addStudent(){
   system("cls");
   // int ID=0;
    printf("Enter your ID:\n");
    scanf("%d",&students[studentcount].ID);
    for(int i=0;i<studentcount;i++){
    if(students[i].ID==students[studentcount].ID){
      printf("Student is Already\n");
      backtomenu();
      return;
  
    }
  }
  printf("Enter student name:\n");
     scanf("%s",students[studentcount].name);
     system("cls");
  printf("Enter your Age:\n");
     scanf("%d",&students[studentcount].age);
     system("cls"); 


  studentcount++;
  savestudent();
  backtomenu();
  return;
}

void showstudent(){
  system("cls");
    if(studentcount==0){
      printf("No student available\n");
    }else{
      int i;
      for(i=0;i<studentcount;i++){

      printf("student:%d\n",i+1);
      printf("Name:%s\n",students[i].name);
      printf("Age:%d\n",students[i].age);
      printf("ID:%d\n",students[i].ID);
      printf("===========================\n");
    }
    

  }
 backtomenu();
}

void loadstudents(){
  FILE *file;
  int i=0;
  file=fopen("students.txt","r");
  if(file==(NULL)){
    printf("Cannot open student file.\n");
    return;
  }
  
  while(fscanf(file,"name:%s\nage:%d\nstudent_id:%d\n",students[i].name,&students[i].age,&students[i].ID)==3){
    i++;
    studentcount++;
  }
  fclose(file);
}

void savestudent(){
  FILE *file;
  int i=0;
  file=fopen("students.txt","w");
  for(i=0;i<studentcount;i++){
    fprintf(file,"name:%s\nage:%d\nstudent_id:%d\n",students[i].name,students[i].age,students[i].ID);
  }
  fclose(file);
  return;
}


void searchstudent(){
  system("cls");
  int id;
  int i;
  int found=0;
  printf("Enter student ID plaese\n");
  scanf("%d",&id);
  system("cls");
  for(i=0;i<studentcount;i++){
    if(students[i].ID==id){
      found=1;
      printf("name;%s,age;%d\n,ID:%d\n",students[i].name,students[i].age,students[i].ID);
      break;
    }
  }
  if(found!=1){
    printf("student Not Found\n");
    
  }
  backtomenu();
}

void deletestudent(){
  system("cls");
  int id;
  int i;
  int found=0;
  printf("Enter student ID:\n");
  scanf("%d",&id);

  for(i=0;i<studentcount;i++){
    if(students[i].ID==id){
      found=1;
      break;
    }
    
  }
  system("cls");
  if(found!=1){
    printf("student_ID Not Found\n");
  }else{
    for(int j=i;j<studentcount-1;j++){
       students[j]=students[j+1];
    }
   studentcount--;
   savestudent();
   printf("Student deleted successfully.\n");
  }
 backtomenu();
}


void backtomenu(){
  printf("Press Enter to return to the main menu...");
  getchar();
  getchar();
  system("cls");
}



int main(){

  loadstudents();
  int select;
  int run=1;
  while(run){
    printf("1.addStudent\n");
    printf("2.SHOW STUDENT\n");
    printf("3.SEARCH STUDENT\n");
    printf("4.DELETE STUDENT\n");
    printf("5.EXIT\n");
    printf("Enter your choice:");
    scanf("%d",&select);

    switch(select){
       case 1:
          addStudent();
        break;
       case 2:
         showstudent();
       break;
       case 3:
         searchstudent();
       break;
       case 4:
         deletestudent();
        break;
        case 5:
          run=0;
          printf("Goodbye\n");
          break;
        
       default:
        system("cls");
        printf("Invalid option!\n");
        break;
    }


  }

}