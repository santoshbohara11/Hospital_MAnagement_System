#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

void welcomescreen();
void title();
void loginscreen();
void mainmenu();
void addpatientrec();
void patientlist();
void dischargepatient();
void searchpatientrec();
void adddoctor();
void listdoctor();

struct patient
{
	int id;
	char gender[20];
	char name[50];
	char disease[50];
	char address[50];
	char date[50];
}p;

struct doctor{
    int id;
    char gender[20];
    char name[50];
    char address[50];
    char specialize[50];
    char date[12];
}d;


FILE *pk;
int main()
{
	welcomescreen();
	title();
	loginscreen();
	return 0;
}
void welcomescreen(){
	printf("\n\n\n\n\n\n\n\n***********************************************************************************************************************************************************\n");
	printf("\t \t\t\t\t\t     WELCOME TO\n");
	printf("\t\t\t\t\t\tGRANDI HOSPITAL NEPAL\t\t\t\t\t\t\n");
	printf("************************************************************************************************************************************************************\n");
	printf("\n\n\n\npres any key to continue.....");
	getch();
	system("cls");
}
void title(){
	printf("\n########################################################################################################################\n");
	printf("\n\t\t\t\t\t\tGRANDI HOSPITAL\n");
	printf("\n########################################################################################################################\n");
}
void loginscreen()
{
	int i=0;
	char username[20];
	char password[15];
	char originalusername[12]="admin@11";
	char originalpassword[8]="admin";
	do{
		printf("\n\n\t\t\t\tenter the username and password:");
	    printf("\n\n\t\t\t\tusername:");
	    scanf("%s",&username);
	    printf("\n\t\t\t\tpassword:");
	    scanf("%s",&password);
	    if((strcmp(username,originalusername)==0)&& (strcmp(password,originalpassword)==0))
	    {
	    	printf("\n\n\t\t\tlogin successfully......");
	    	printf("\n\n\n\n\n\t\t\t\tWelcome to the GRANDI HOSPITAL MANAGEMNET SYSTEM..........");
	    	//printf("\n\n\npress any key to cotinue......");
			getch();
	    	mainmenu();//call main menu
	    	break;
		}
		else{
			system("cls");
			printf("\npassword is incorrect.....");
			i++;
			printf("\npress any key to cotinue......");
			getch();
		}
	}while(i<=2);
		
		if(i>2)
		{
			printf("\nyou have cross the limit.you cannot login");
			getch();
			exit(0);
	    }  
}
void mainmenu()
{
	system("cls");
	int choice;
	title();
	char press;
	while(1){
		label:	
		printf("\n\t\t1.Add record of  the patient");
		printf("\n\t\t2.Patient list");
		printf("\n\t\t3.Discharge the patient");
		printf("\n\t\t4.Search Patient record");
		printf("\n\t\t5.Add doctor record");
		printf("\n\t\t6.List doctor record");
		printf("\n\t\t7.Exit");
		printf("\n\nchoose any number that you want:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				addpatientrec();
				break;
				
			case 2:
				patientlist();
				break;

			case 3:
				dischargepatient();
				break;
				
			case 4:
				searchpatientrec();
				break;
				
			case 5:
				adddoctor();
				break;
			
			case 6:
				listdoctor();
				break;
				
			case 7:
				exit(0);
				break;
				
			default:
				printf("\nThe choice is not valid......\n");
				goto label;
			
		}
		printf("\nDo you want to continue?..Press Y to continue.");
		scanf("%c",&press);
		if(press=='y'||press=='Y')
		{
			goto label;
		}
		system("cls");
	}
}
	void addpatientrec()
	{
		FILE *ptr;
		system("cls");
		ptr=fopen("D:\\record.txt","a+");
		char myDate[12];
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
		strcpy(p.date, myDate);
		title();
		printf("\n\n\n\t\t\t********************************");
		printf("\n\t\t\t\tPATIENT RECORD");
		printf("\n\t\t\t********************************");
		printf("\nenter the patient id:");
	    scanf("%d",&p.id);
	    printf("\nenter the name of patient:");
	    fflush(stdin);
	    gets(p.name);
	    printf("enter the gender: ");
	    fflush(stdin);	
	    gets(p.gender);
	    printf("\nenter the address of patient:");
	    fflush(stdin);
	    gets(p.address);
	    printf("\nenter the disease of patient:");
	    fflush(stdin);
	    gets(p.disease);
	    /*printf("\nenter the date:");
	    fflush(stdin);
	    gets(p.date);*/
	    printf("\n\n\t\t\t\tpatient detail added successfully......");
	    getch();
	    fwrite(&p,sizeof(p),1,ptr);
	    fclose(ptr);
	    system("cls");
	}
	void patientlist()
	{
		system("cls");
		title();
		printf("\n\n\n\n\t\t**********Patient List**********\n");
		printf("\n\n\n%-10s %-20s %-30s %-30s %-20s %s\n", "Id"," Name","gender","Address","Disease","Date");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
	    rewind(pk);
		pk=fopen("D:\\record.txt","r+");
	    while(fread(&p, sizeof(p), 1, pk) == 1)
	    {
			printf("\n%-10d %-2 %-19s %-30s %-30s %s\n", p.id,p.name,p.gender, p.address, p.disease, p.date);
	    	
		}
		fclose(pk);
		printf("\n\n\t\tPress any key to continue.......");
		getch();
		system("cls");
	}
	void dischargepatient()
	{
		int id,k=0;
		system("cls");
		title();
		FILE *s;
		printf("\n\t\t\tDISCHARGE PATIENT");
		printf("\nenter patient id to discharge:");
		scanf("%d",&id);
		pk=fopen("D:\\record.txt","r+");
		s=fopen("D:\\temp.txt","w+");
		while(fread(&p, sizeof(p), 1, pk) == 1)
		{

        if(id == p.id)
		{
            k=1;
        }
		
		else
		{
            fwrite(&p, sizeof(p), 1, s);
        }
    }

    if(k==1)
	{
        printf("\n\nPatient Discharged Successfully.");
    }
	else
	{
        printf("\n\nRecord Not Found !");
    }

    fclose(pk);
    fclose(s);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");
    system("cls");
}
	 void searchpatientrec()
	 {
	 	system("cls");
		title();
	 	int id ;
	 	printf("\n\t\t\tSearch Patient Record");
	 	printf("\n\t\t\t-------------------------------");
	 	printf("\n\n\nenter the id that you want to search the record:");
	 	scanf("%d",&id);
	 	printf("\n\n%-10s %-20s %-30s %-30s %-20s %s\n", "Id"," Name","gender","Address","Disease","Date");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
	    rewind(pk);
	 	pk=fopen("D:\\patient.txt","r+");
	 	while(fread(&p, sizeof(p), 1, pk) == 1)
		 {

            if(id == p.id)
		    {
               printf("%-10d %-30s %-30s %-30s %s\n", p.id, p.name,p.gender,p.disease, p.date);
            }
		
		  else
		   {
              printf("\npatient id did not match so ther is no any patient that you want to search");
           }
       }
       system("cls");
	 
    }
    void adddoctor()
    {
    	system("cls");
    	title();
    	FILE *pk;
	char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(d.date, myDate);
    printf("\n\n\n\t\t\t********************************");
	printf("\n\t\t\t\tDOCTOR RECORD");
	printf("\n\t\t\t********************************");
    pk=fopen("d:\\doctor.txt","a+");
    printf("\n\nEnter Doctor id: ");
    scanf("%d", &d.id);

    printf("\nEnter Doctor Name: ");
    fflush(stdin); 
    gets(d.name);

    printf("\nEnter Doctor gender: ");
    fflush(stdin);
    gets(d.gender);

    printf("\nDoctor Specialize in: ");
    fflush(stdin);
    gets(d.specialize);
    
    /*printf("\nDate:");
    fflush(stdin);
    gets(d.date);*/

    printf("Doctor Added Successfully\n\n");
    getch();
    fwrite(&d,sizeof(d),1,pk);
    fclose(pk);
    system("cls");
	}
	void listdoctor()
	{
		system("cls");
		title();
		//printf("\n\n\n\t\t\t********************************");
	    printf("\n\t\t\t\tDOCTOR RECORD");
	    printf("\n\n\n\t\t\t********************************");
	    printf("\n\n\n\n%-10s %-30s %-30s %-30s %s\n", "id", "Name", "gender", "Specialize","Date");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        pk=fopen("D:\\doctor.txt","r+");
        rewind(pk);
		while(fread(&d, sizeof(d), 1, pk) == 1)
		{
			 printf("%-10d %-30s %-30s %-30s %s\n", d.id, d.name,d.gender, d.specialize, d.date);
			 
		}
		fclose(pk);
		printf("\n\n\t\tPress any key to continue.......");
		getch();
		system("cls");
	}

