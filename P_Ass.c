void updatepatient(){
    char patientname[10];
    
    struct patient patient_record;
    printf("<-- Update Record -->");
    
    printf("Enter Name Of Patient To Update");
    fflush(stdin);
    gets(patientname);
    
    fp = fopen("patient.txt","rb+");
    if(fp==NULL){
        printf("error opening file");
        exit(1);
    }
     rewind(fp);
     fflush(stdin);
      while(fread(&patient_record,sizeof(patient_record),1,fp)==1)
   {
       if(strcmp(patientname,patient_record.patient_name)==0)
       {
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
     
     fseek(fp,sizeof(patient_record),SEEK_CUR);
     fwrite(&patient_record,sizeof(patient_record),1,fp);
     break;
       }
   }
    fclose(fp);
    printf("Press Any Key To Continue...");
    getch();
    menu();
}


void searchpatient(){
 
 struct patient patient_record;
 char patientname[10];
 system("cls");
 
 printf("<-- Search Patient Record : -->");
 
 printf("Enter name of patient:");
 fflush(stdin);
 gets(patientname);
  fp = fopen("search.txt","rb+");
  if(!fp )
  {
      printf("error opening file ");
      exit(1);
  }
   while(fread(&patient_record,sizeof(patient_record),1,fp)==1)
   {
       if(strcmp(patientname,patient_record.patient_name)==0)
       {
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
   fclose(fp);
   printf("Press Any Key To Continue ...");
   getch();
   menu();
}