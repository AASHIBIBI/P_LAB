#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void addpatient();
void deletepatient();
void updatepatient();
void searchpatient();
void menu();

struct patient{
  int patient_id;
  char patient_name[10];
  int CNIC;
  int phonenumber;
  char disease[10];
  char isAdmitted[10];
}patient_record;

   FILE * fp;
int main() {
  
  while(1){
     
      system("cls");
      printf("<== Hospital Mangment System ==> \n");
      printf("Press Any Key  To Continue");
      getch();
    menu();
    return 0;
    
    
void menu(){
    system("cls");
    int ch;
    printf("<-- Menu -->");
    printf("enter any number to perform a task");
     printf("1. ADD PATIENT \n");
      printf("2. DELETE PATIENT \n");
      printf("3. UPDATE PATIENT \n");
      printf("4. SEARCH PATIENT \n");
      printf("0. Exit \n\n");
      printf("Enter your choice \n:");
      scanf("%d",&ch);

      switch(ch){
            
            case 1:
                 addpatient();
                 break;
            case 2:
                 deletepatient();
                 break;
            case 3:
                 updatepatient();
                 break;
            case 4:
                 searchpatient();   
                 break;
            case 5:
                 exit(1);
                 break;
            default:
             printf("invalid choice ... \n");
      } 
      printf("\n\n Press Any Key To Continue ..");
      getch();
}

void addpatient()
{
    
    struct patient patient_record;
    char var='y';
    system("cls");
    fp= fopen("patient.txt","ab+");
    if(!fp )
    {
        printf("error file opening ");
        exit(1);
    }
    else{
        fflush(stdin);
    while(var =='y')
    {
      printf("<-- Add patient Record -->");
      printf("enter details of patient:");
    
        printf("Enter Patient ID :");
        scanf("%d",&patient_record.patient_id);
    
        printf("Enter patient name :");
        fflush(stdin);
        gets(patient_record.patient_name);
    
        printf("Enter patient CNIC :");
        fflush(stdin);
        scanf("%d",&patient_record.CNIC);
    
        printf("Enter patient phonenumber :");
        fflush(stdin);
        scanf("%d",&patient_record.phonenumber);
    
        printf("Enter patient disease :");
        fflush(stdin);
        gets(patient_record.disease);
    
        printf("Enter patient is added Successfully :");
        fflush(stdin);
        gets(patient_record.isAdmitted);
       }
   }
       fwrite(&patient_record, sizeof(patient_record),1,fp);
       
       printf("add another function ...");
       fflush(stdin);
       
       var = getch();
       system("cls");
       fflush(stdin); 
}
       fclose(fp);
       printf("press any key to continue");
       getch();
       menu();
 }   
void deletepatient()
{ 
    char patientname[10];
  FILE * ft;
  struct patient patient_record;
  system("cls");
  
  printf("<-- delete patient record-->");
  printf("Enter name of patient to delete record :");
  fflush(stdin);
  gets(patientname);
   fp=fopen("patient.txt","rb+");
   if(!fp)
   {
       printf("error opening file");
       exit(1);
   }
   ft=fopen("delete2.txt","wb+");
   if(!ft)
   {
       printf("error opening file");
       exit(1);
   }
   while(fread(&patient_record,sizeof(patient_record),1,fp)==1)
   {
       if(strcmp(patientname,patient_record.patient_name)!=0)
          fwrite(&patient_record,sizeof(patient_record),1,ft);
   }
    
    fclose(fp);
    fclose(ft);
    remove("patient.txt");
    rename("patient.txt","delete1.txt");
    
    printf("Press Any key To Continue ...");
    getch();
    menu();
   }
   
 }