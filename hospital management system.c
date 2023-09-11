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
void welcomescreen()
{
	system("color 1 ");
	printf("\n\n\n\n\n\n\n\t\t***************************************************************************\n");
	printf("\t\t*\t\t\t\t     WELCOME TO\t\t\t\t  *\n");
	printf("\t\t*\t\t\t\tMETRO HOSPITAL NEPAL\t\t\t  *\n");
	printf("\t\t***************************************************************************\n");
	printf("\n\n\n\n\n\n\t\t\tpress any key to continue.....");
	getch();
	system("cls");
}
void title()
{
	system("color 4 ");
	printf("\n\n\n\n\n\n\n\t\t***************************************************************************\n");
	printf("\t\t*\t\t\t\t METRO HOSPITAL\t\t\t\t  *\n");
	printf("\t\t***************************************************************************\n");
}
void loginscreen()
{
	system("color 8 ");
	int i=0;
	char username[20];
	char password[15];
	char originalusername[12];
	char originalpassword[8];
	do{
		FILE *ptr, *pt;
		
		ptr=fopen("D:\\password.txt","r");
		fgets(originalpassword,8,ptr);
		pt=fopen("D:\\username.txt","r");
		fgets(originalusername,12,pt);
		
		
		printf("\n\n\n\t\t\t\tenter the username and password:");
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
			printf("\n\n\t\tpassword is incorrect.....");
			i++;
			printf("\n\n\n\t\tpress any key to cotinue......");
			getch();
			system("cls");
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
	system("color 5 ");
	system("cls");
	int choice;
	title();
	char press;
	while(1){
		label:	
		printf("\n\t\t\t\t1.Add record of  the patient");
		printf("\n\t\t\t\t2.Patient list");
		printf("\n\t\t\t\t3.Discharge the patient");
		printf("\n\t\t\t\t4.Search Patient record");
		printf("\n\t\t\t\t5.Add doctor record");
		printf("\n\t\t\t\t6.List doctor record");
		printf("\n\t\t\t\t7.Exit");
		printf("\n\n\n\tchoose any number that you want:");
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
		FILE *pk;
		system("cls");
		system("color 4 ");
		char myDate[12];
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
        strcpy(p.date, myDate);
		title();
		printf("\n\n\n\t\t\t********************************");
		printf("\n\n\t\t\t\tPATIENT RECORD");
		printf("\n\t\t\t********************************");
		pk=fopen("record.txt","ab");
		printf("\n\n\nenter the patient id:");
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
	    fwrite(&p,sizeof(p),1,pk);
	    fclose(pk);
	    system("cls");
	}
	void patientlist()
	{
		system("cls");
		title();
		system("color 6 ");
		printf("\n\n\n\n\t\t\t\t**********Patient List**********\n");
		printf("\n\n\n%-10s %-20s %-15s %-30s %-15s %s\n", "Id"," Name","gender","Address","Disease","Date");
        printf("------------------------------------------------------------------------------------------------------------------\n");
	    rewind(pk);
		pk=fopen("record.txt","rb");
	    while(fread(&p, sizeof(p), 1, pk) == 1)
	    {
			printf("\n%-10d %-20s %-15s %-30s %-15s %s\n", p.id,p.name,p.gender, p.address, p.disease, p.date);
	    	
		}
		fclose(pk);
		printf("\n\n\t\tPress any key to continue.......");
		getch();
		system("cls");
	}
	void dischargepatient()
	{
		
		system("cls");
		title();
		system("color 8 ");
		int id,k=0;
		FILE *s;
		printf("\n\n\n\t\t\tDISCHARGE PATIENT");
		printf("\n\n\nenter patient id to discharge:");
		scanf("%d",&id);
		pk=fopen("record.txt","rb");
		s=fopen("temp.txt","wb");
		while(fread(&p, sizeof(p), 1, pk) == 1)
		{

        if(id == p.id)
		{
            k=1;
           
		    continue;
        
		}
		
		else
		{
           
		    fwrite(&p, sizeof(p), 1, s);
        }
    }

    if(k==1)
	{
        printf("\n\nPatient Discharged Successfully...........");
        
    }
	else
	{
        printf("\n\nRecord Not Found !");
    }
	fclose(pk);
    fclose(s);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    getch();
    system("cls");
}
	void searchpatientrec()
	 {
		 system("cls");
		title();
		system("color 3 ");
	 	int id ;
	 	int c=0;
	 	printf("\n\t\t\tSearch Patient Record");
	 	printf("\n\t\t\t-------------------------------");
	 	printf("\n\n\nenter the id that you want to search the record:");
	 	scanf("%d",&id);
	 	rewind(pk);
		pk=fopen("record.txt","rb");
	 	printf("\n\n\n%-10s %-20s %-20s %-25s %-15s %s\n", "Id"," Name","gender","Address","Disease","Date");
        printf("-------------------------------------------------------------------------------------------------------------\n");
	 	while(fread(&p, sizeof(p), 1, pk) == 1)
		 {

            if(id == p.id)
		    {
               	printf("\n%-10d %-20s %-20s %-25s %-15s %s\n", p.id,p.name,p.gender, p.address, p.disease, p.date);
            	c=1;
			}
		    
		 }
		 if (c==0)
		 {
		 	printf("\n\n\t\tRecord not found..");
		 }
       
       getch();
       system("cls");
	 
    }
    void adddoctor()
    {
		system("cls");
    	title();
    	system("color 4 ");
    	FILE *pk;
	char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(d.date, myDate);
    printf("\n\n\n\t\t\t********************************");
	printf("\n\t\t\t\tDOCTOR RECORD");
	printf("\n\t\t\t********************************");
    pk=fopen("doctor.txt","ab");
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

    printf("\n\n\t\t\t\tDoctor Added Successfully....\n\n");
    getch();
    fwrite(&d,sizeof(d),1,pk);
    fclose(pk);
    system("cls");
	}
	void listdoctor()
	{
		system("cls");
		title();
		system("color 5 ");
		//printf("\n\n\n\t\t\t********************************");
	    printf("\n\t\t\t\tDOCTOR RECORD");
	    printf("\n\n\n\t\t\t********************************");
	    printf("\n\n\n\n%-10s %-30s %-30s %-30s %s\n", "id", "Name", "gender", "Specialize","Date");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        pk=fopen("doctor.txt","rb");
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

