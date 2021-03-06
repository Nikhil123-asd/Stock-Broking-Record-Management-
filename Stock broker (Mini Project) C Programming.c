//             Header Files               //  


#include <stdio.h>     //  scanf() , printf()
#include <string.h>     // strcmpi(a,b) ->  for comparing strings
#include <stdlib.h>    //  rename() and remove() Functions (FILES) 
#include <time.h>      //   time_t t=time(NULL)          
#include <conio.h>     //   getch() , system("CLS")


//         Functions  Declaration          //


void login();
void loading();
void add_client();
void show_all_clients();
void search_client();
void delete_client();
void update_client_detail();
void order();
void order_details();
void total_tax_calculator();
void contract_note();
void exit_program();


//        Define Required  Structures       //


struct client_detail
{   char s_no[10];
	char client_id[25];
	char name[30];
	char phone[15];
	char email[100];
	char address[1000];
	char aadhar_number[15];
	char pan_number[15];
	char bank_name[50];
	char ifsc_code[15];
	char account_number[35];
	
}det;

struct order_details
{
	char client_i[25];
    char client_name[20];
    char phone[15];
    char pan_number[15];
	char stock_name[50];
	char  quantity[25];
	char exchange_name[5];
	char limit_price[100];
	double Total_Amount;
	char Date_And_Time[50];
	 
}ordet;




//                 Main Functon           //

void main()
{
   int opt;
   system("CLS");
   login();
   loading();
do{ 
    system("CLS");
printf("\n\n\t\t\t*************************************************\n\t\t\t*************************************************\n\n");
printf("\t\t\t\t------------ Hello ------------\n\n\n");
printf("\t\t\t*************************************************\n\t\t\t*************************************************\n\n");
printf("\t\t\tMini Project For Stocks Trading\n");
 printf("\t\t\tChoose The Operation\n\n"); 
 printf("\t\t\t1. Add Client\n");
 printf("\t\t\t2. Show Clients\n");
 printf("\t\t\t3. Search Client\n");
 printf("\t\t\t4. Delete Client\n");
 printf("\t\t\t5. Update Client Details\n");
 printf("\t\t\t6. Total Tax Calculator\n");
 printf("\t\t\t7. Place order\n");
 printf("\t\t\t8. Order Details\n"); 
 printf("\t\t\t9. Contract Note\n");
 printf("\t\t\t10. Exit\n");
 scanf("\t\t\t %d",&opt);
 switch(opt)
{ case 1: system("CLS");
          add_client();break;
  case 2: system("CLS");
          show_all_clients();break;
  case 3: system("CLS");
          search_client();break;
  case 4: system("CLS");
          delete_client();break;
  case 5: system("CLS");
          update_client_detail();break;
  case 6: system("CLS");
          total_tax_calculator();break;
  case 7: system("CLS");
          order();break;
  case 8: system("CLS");
          order_details();break;
  case 9:  system("CLS");
           contract_note();break;
  case 10:system("CLS");  
          exit_program();break;
          }
		  }while(opt!=10);	  
}







//           User Defined Functions               //

void login()
{

char pass[20],password[20]="pps";
      login_try:
    printf("\n\n\t\t\tEnter the password to login:\t");

    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\n\t\t\t\t\tPassword Match!");
        sleep(1);
        }
    else
        {   printf("\n\n\t\t\t\t\a\a\a**Wrong password!!**\a\a\a\n\n\t\t\t\t**Try Again!!*\a\a\a\t\t\a\a\a");
           
            goto login_try;
        }
}


void loading()
{ int i=0;
for(i=1;i<=10;i++)
{   sleep(1);
    system("CLS");
    printf("\n\n\n\n\t\t\t\t\tloading...........");
    
    printf("\n\n\n\n\n\t\t\t\t\t %d percent complete",10*i);
    if(i>=1 && i<=3)
   {
   printf("\n\n\n\t\t\t\t\t\t \\\// \n");
   printf("\n\n\t\t\t\t .............Hold on Buddy...........") ;
   }
   else if(i>3 && i<=7)
   {
	printf("\n\n\n\t\t\t\t\t\t || ");
   printf("\n\n\n\t\t\t\t .........Reaching To Stock Menu.......") ;
   }
   else if(i>7)
   {  
   printf("\n\n\n\t\t\t\t\t\t //\\ \n");
   printf("\n\n\n\t\t\t Just Seconds Away From The World of Stocks & Trading.....\n\n ") ;
   } 
}
}




void add_client()
    {
	printf("\t\t\t You Chose 1. Add Client\n\n\n");
    printf("\t\t\t Enter Client Information\n");
    
	FILE *sb;
	sb=fopen("client_details.txt","ab+");
	
	if(sb==NULL)
	{
		printf("\n\t Error : Cannot open the file!!!");
		getch();
	}
	else {
	
	printf("\t\t\t S.NO :");
	scanf("%s",det.s_no);
	 
	printf("\n\t\t\t Client ID :");
	scanf("%s",det.client_id);
	
	 printf("\n\t\t\t Client Name :");
	scanf("%s",det.name);
	
	 printf("\n\t\t\t Client Phone :");
	scanf("%s",det.phone);
	
	 printf("\n\t\t\t Client e-mail :");
	scanf("%s",det.email);
	
	printf("\n\t\t\t Client Address :");
	scanf("%s",det.address);
	
    printf("\n\t\t\t Client Aadhar Number :");
    scanf("%s",det.aadhar_number);
    
    printf("\n\t\t\t Client PAN Number :");
    scanf("%s",det.pan_number);
    
	printf("\n\n\n\t\t\t Client Bank Details\n\n");
	
    printf("\n\t\t\t Client Bank Name :");
	scanf("\t\t\t%s",det.bank_name);
	
	printf("\n\t\t\t Client Account Number :");
	scanf("\t\t\t%s",det.account_number);
	
	printf("\n\t\t\t Client IFSC CODE :");
	scanf("\t\t\t%s",det.ifsc_code);
	
	fwrite(&det,sizeof(det),1,sb);  //   write the input into the file   //
	
	printf("\n\n\n\t\t\t***********Client Account Successfully Opened************\n\n");
    getch();
	fclose(sb);
	}}
	




void update_client_detail()
{   system("CLS");
    char clid[20];
	char clientid[25];
	char nam[30];
	char phon[15];
	char e_mail[100];
	char addres[1000];
	char aadharnumber[15];
	char pannumber[15];
	char bankname[50];
	char ifsccode[15];
	char accountnumber[35];
    int flag=0;
    
	FILE *sb;
	sb=fopen("client_details.txt","rb+");  //   Open file for reading and writing in binary mode   //
	
	if(sb==NULL)
	{
		printf("\n\t Error : Cannot open the file!!!");
		getch();
	}
	else
	{
	printf("\n\n\t\t\t Enter Client Id Whose Information You Want To Update : ");
	scanf("%s",clid);
		
	while(fread(&det,sizeof(det),1,sb)==1)
	{
	    if(strcmpi(clid,det.client_id)==0)
			{    system("CLS");
				flag=1;
				
	printf("=================================================================\n\n");
	printf("\ns_no : %s \n\n",det.s_no);
	printf("client_id : %s\n\n",det.client_id);
	printf("name : %s \n\n",det.name);
    printf("phone : %s \n\n",det.phone);
	printf("E-mail : %s \n\n",det.email);
	printf("Address : %s \n\n",det.address);
	printf("Aadhar_number : %s \n\n",det.aadhar_number);
	printf("Pan_number : %s \n\n",det.pan_number);
	printf("Bank_name : %s \n\n",det.bank_name);
	printf("Ifsc_code : %s \n\n",det.ifsc_code);
	printf("Account_number : %s \n\n",det.account_number);
	printf("=================================================================\n\n\n");
	
	printf("\n\t\t\t Enter 'R' for retain that detail");      
	printf("\n\n\t\t\t Now Enter The New Info \n\n");
	    fflush(stdin);
	    
		printf("\n\t\t\t Updated Client Id :");
	    gets(clientid);
	    
	    if(strcmpi(clientid,"R")!=0)
	    {
	      strcpy(det.client_id,clientid);	
		}
       
        printf("\n\t\t\t Updated Client Name :");
        gets(nam);
        
        if(strcmpi(nam,"R")!=0)
        
        { 
         strcpy(det.name,nam);
		}
       
	    printf("\n\t\t\t Updated Client Phone :");
        gets(phon);
       
       if(strcmpi(phon,"R")!=0)
       {
       	strcpy(det.phone,phon);
	   }
	   
	    printf("\n\t\t\t Updated Client E-mail :");
        gets(e_mail);
        
        if(strcmpi(e_mail,"R")!=0)
       {
       	strcpy(det.email,e_mail);
	   }
		
		printf("\n\t\t\t Updated Client Address :");
        gets(addres);
        
		
		if(strcmpi(addres,"R")!=0)
       {
       	strcpy(det.address,addres);
	   }
	   
		printf("\n\t\t\t Updated Client Aadhar Number :");
        gets(aadharnumber);
        
        if(strcmpi(aadharnumber,"R")!=0)
       {
         strcpy(det.aadhar_number,aadharnumber);
	   }
		
		printf("\n\t\t\t Updated Client PAN Number :");
        gets(pannumber);
       
       if(strcmpi(pannumber,"R")!=0)
       {
       	strcpy(det.pan_number,pannumber);
	   }
	    
		printf("\n\t\t\t Updated Client Bank Details\n");
       
	    printf("\n\n\t\t\t Updated Client Bank Name :");
        gets(bankname);
       
       if(strcmpi(bankname,"R")!=0)
       {
       	strcpy(det.bank_name,bankname);
	   }
	    
		printf("\n\t\t\t Updated Client Account Number :");
        gets(accountnumber);
       
       if(strcmpi(accountnumber,"R")!=0)
       {
       	strcpy(det.account_number,accountnumber);
	   }
	   
	    printf("\n\t\t\t Updated Client IFSC CODE :");
        gets(ifsccode);
       
       if(strcmpi(ifsccode,"R")!=0)
       {
       	strcpy(det.ifsc_code,ifsccode);
	   }
        
       
       	system("CLS");
	    printf("\t\t\t***********Client Account Successfully Updated************\n\n");
	    getch();
	    
	   // break;
       }
	}
	
	   fseek(sb,-(long)sizeof(det),1);     //            Moves The File Pointer              // 
       
       fwrite(&det,sizeof(det),1,sb);       //       To Write the New data in the file        // 
       
    if(flag==0)
	{
	  	printf("\n\t Error : Cannot Update the file!!!");	
	 	
	}
	fclose(sb);
	}}
	
	


void show_all_clients()

{   printf("\t\t\t You Chose 2. Show Clients\n\n\n");

	FILE *sb;
	sb=fopen("client_details.txt","rb");
	
	if(sb==NULL)
	{
	 printf("\n\t\t\t Error : Cannot open the file!!!");
	 getch();
	}
	else {
	
	printf("\t\t\t##########################################################\n\n");
	printf("\t\t\t******************* Clients Detais Are *******************\n\n");
	printf("\t\t\t##########################################################\n\n\n\n\n\n\n\n");
	
	while(fread(&det,sizeof(det),1,sb)==1)
	{
	printf("=================================================================\n\n");
	printf("\ns_no : %s \n\n",det.s_no);
	printf("client_id : %s\n\n",det.client_id);
	printf("name : %s \n\n",det.name);
    printf("phone : %s \n\n",det.phone);
	printf("E-mail : %s \n\n",det.email);
	printf("Address : %s \n\n",det.address);
	printf("Aadhar_number : %s \n\n",det.aadhar_number);
	printf("Pan_number : %s \n\n",det.pan_number);
	printf("Bank_name : %s \n\n",det.bank_name);
	printf("Ifsc_code : %s \n\n",det.ifsc_code);
	printf("Account_number : %s \n\n",det.account_number);
	printf("=================================================================\n");
	getch();
    }
    {
	printf("\n\n\n\t\t################################ END OF FILE ###############################\n\n");
    }
	getch();
    fclose(sb);
    }
	}
	
	
	void search_client()
	{ 
	  char clid[15];
	  int flag=0;
	   FILE *sb;
	   sb=fopen("client_details.txt","rb");
	   
	   	if(sb==NULL)
	{
		printf("\n\t\t\t Error : Cannot open the Client!!!");
		getch();
	}
		printf("\t\t\t# Enter Client ID : ");
		scanf("%s",clid);
	   
	   while(fread(&det,sizeof(det),1,sb)==1 && flag==0)
	   {
	   	if(strcmpi(clid,det.client_id)==0)
	   	{flag=1;
	   	 printf("\n\n\n*************** Search Successful Client Found ***************\n\n");
	   	 printf("s_no : %s \n",det.s_no);
	     printf("client_id : %s\n",det.client_id);
	     printf("name : %s \n",det.name);
         printf("phone : %s \n",det.phone);
	     printf("E-mail : %s \n",det.email);
	     printf("Address : %s \n",det.address);
	     printf("Aadhar_number : %s \n",det.aadhar_number);
	     printf("Pan_number : %s \n",det.pan_number);
	     printf("Bank_name : %s \n",det.bank_name);
	     printf("Ifsc_code : %s \n",det.ifsc_code);
	     printf("Account_number : %s \n",det.account_number);
	     getch();system("CLS");
	   	}}
	   	if(flag==0) 
	   	{ 
	   		printf("\n\n\t\t\t*************** OOPS!!!! Client Not Found. :/ ***************");
	   		getch();
	   	}
	   	fclose(sb);	
		}
	   


   void delete_client()
   {
     char clid[20];
     int flag=0;
   
     FILE *sb,*eb;
	
	sb=fopen("client_details.txt","rb");
	
	eb=fopen("temp.txt","ab+");
	
	if(sb==NULL || eb==NULL)
	{
		printf("\n\t\t\t Error : Cannot open the Details!!!");
		getch();
	}
	else 
	{
	
	printf("\n\n\t\t\t Enter Client Id Which You Want To Delete \n");
	printf("\t\t\t Client Id :");
	scanf("%s",clid);
	
	while(fread(&det,sizeof(det),1,sb)==1)
	   {
		if(strcmpi(clid,det.client_id)!=0)
		{
		 fwrite(&det,sizeof(det),1,eb);
	    
		}
		else 
		flag=1;
	   }
		fclose(sb);
		fclose(eb);
	    if(flag==0)
	    {
	    printf("\n\n\t\t\t*************** OOPS!!!! Client Not Found. :/ ***************");
	    remove("temp.txt");
		}
		else
			{
			remove("client_details.txt");
			rename("temp.txt","client_details.txt");
			printf("\n\t\t\t Client Deleted Sucessfully \n");
	        }
			system("CLS");
			printf("\t\t################### Done =' ###################");
		    getch();
	}}
	
	
	
void order()
{ 
  int choice;
  int brokerage = 25;
  time_t t=time(NULL);
   
  
  FILE *tb;
  tb=fopen("client_order_details.txt","ab+");
  
   	if(tb==NULL)
	{
		printf("\n\t\t\t Error : Cannot Order!!!  ");
		getch();
	}
	else 
	{

        printf("\n\t\t\tEnter Client ID :");
        scanf("%s",ordet.client_i);

        printf("\n\t\t\tEnter Client Name :");
        scanf("%s",ordet.client_name);
        
         printf("\n\t\t\tEnter Client Phone :");
        scanf("%s",ordet.phone);

        printf("\n\t\t\tEnter PAN No :");
        scanf("%s",ordet.pan_number);

        printf("\n\t\t\tEnter Stock Name :");
        scanf("%s",ordet.stock_name);
         
        printf("\n\t\t\tEnter Exchange Name :");
		scanf("%s",ordet.exchange_name); 

        printf("\n\t\t\tEnter Stock Quantity :");
        scanf("%s",ordet.quantity);
   
        printf("\n\t\t\tEnter Stock Price :");
        scanf("%s",ordet.limit_price);
        
        
		option:
        printf("\n\t\t\tEnter your choice '1' for Buy & '2' for Sell : ");
        scanf("%d",&choice);
        
         if(choice==1 || choice==2)
         {
         		printf("\n\n\n\t\t\t###########************* Order Successfully Placed **************###########\n\n");
    
           
         }
         
         else
         {
         	printf("\n\n"); 
           printf("\t\t\t\t Wrong Input\n\n\t\t\t Try Again \n");
           goto option;
		 }
        
         
        double a=atof(ordet.limit_price);
        double b=atof(ordet.quantity);
        ordet.Total_Amount=a*b+brokerage;
        printf("\n\t\t\t\tTotal Amount : %lf",ordet.Total_Amount);
        
        getch();
        
        
        {
         printf("\n\n\t\t\tOrder Date and Time : %s",ctime(&t));
         strcpy(ordet.Date_And_Time,ctime(&t));
         printf("\n\n\t\t\tCollect Your Bill Under Contract Note Section...\n");
         getch();
        }  
        fwrite(&ordet,sizeof(ordet),1,tb);
        fclose(tb);
	  
	}}



void contract_note()
{   char clid[20];
    int flag=0;
	FILE *tb;
	tb=fopen("client_order_details.txt","rb");  //     Open file for reading mode     //
	
	if(tb==NULL)
	{
		printf("\n\t\t\t Error : Cannot open the Contract Note!!!");
		getch();
	}
	else
	{
	    system("CLS");
	    printf("\n\t\t\t Enter the Client Id : ");
	    scanf("%s",clid);
	    
	    while(fread(&ordet,sizeof(ordet),1,tb)==1)
	    { 
		if(strcmpi(clid,ordet.client_i)==0) 
		  { flag=1;
		    system("CLS");
	        printf("\n\t\t\t ################### Contract Note ################### \n\n");
	    	printf("\n\n=================================================================\n\n");
		    
		    printf("\n\n\t\t\tOrder Date and Time :%s",ordet.Date_And_Time);
		    
	    	printf("\n\t\t\tClient ID : %s",ordet.client_i);
	    	
	    	printf("\n\t\t\tClient Name : %s",ordet.client_name);
	    	 
	    	printf("\n\t\t\tStock Name : %s",ordet.stock_name);
	    	 
	    	printf("\n\t\t\tExchange Name : %s",ordet.exchange_name);
	    	 
	        printf("\n\t\t\tStock Quantity : %s",ordet.quantity);
	    	  
	        printf("\n\t\t\tStock Price : %s",ordet.limit_price);
	        
	        printf("\n\t\t\tTotal Amount Required: %lf",ordet.Total_Amount);
	        
	    printf("\n\n=================================================================\n\n");  
		getch();  
	    }}
	    if(flag==0)
	    {
	    printf("\n\n\t\t\t*************** OOPS!!!! Contract Note Not Found :/ ***************");	
	    getch();	
	    }
	
	}
	      fclose(tb);
}
   	
	    
	    
	    

void order_details()

{
	FILE *tb;
	tb=fopen("client_order_details.txt","rb");
	
	if(tb==NULL)
	{
	 printf("\n\t\t\t Error : Cannot found Order!!!");
	 getch();
	}
	else {
	
	printf("\t\t\t##########################################################\n\n");
	printf("\t\t\t******************* Order Detais Are *******************\n\n");
	printf("\t\t\t##########################################################\n\n\n\n\n\n\n\n");
	
	while(fread(&ordet,sizeof(ordet),1,tb)==1)
	{
	printf("=================================================================\n\n");
	printf("Client_Id : %s\n\n",ordet.client_i);
	printf("Name : %s \n\n",ordet.client_name);
    printf("Phone : %s \n\n",ordet.phone);
	printf("Pan_number : %s \n\n",ordet.pan_number);
	printf("Stock Name : %s",ordet.stock_name);
	printf("\n\nExchange Name : %s",ordet.exchange_name);
	printf("\n\nStock Quantity : %s",ordet.quantity);
	printf("\n\nStock Price : %s\n",ordet.limit_price);
	
	printf("=================================================================\n\n");
	getch();
    }
    {
	printf("\n\n\n\t\t################################ END OF Details!!! ###############################\n\n");
    }
	getch();
    fclose(tb);
    }
	
	
}


void total_tax_calculator()
{   fflush(stdin);
    float Amount;
    float base_charge_per_strip=20.00;        //   For Other Segments Other than equity Delivery Order      //
   
    
    
    printf("\t\t\t##########################################################\n\n");
	printf("\t\t\t******************* Tax Calculator *******************\n\n");
	printf("\t\t\t##########################################################\n\n\n\n\n\n\n\n");
	
	printf("\t\t\t Enter the Amount of Order : ");
	scanf("%f",&Amount);
    
    float brokerage=Amount*0.005;                 //                0.5% of the Total Amount                    //
    float gst=brokerage*0.09;                  //                9% of the Brokerage Amount                    //
    
    float sgst=gst;                            //                9% of the Brokerage Amount                    //    
	
	float Exchange_Tax=Amount*0.000035;      //                0.0035% of the Total Amount                    //  
	
	float SEBI_Turnover_Fees=Amount*0.0000015;   //                0.00015% of the Total Amount                    //
	
	float Total_tax;
	
	Total_tax=brokerage+gst+sgst+Exchange_Tax+SEBI_Turnover_Fees;
    
    
    printf("\n\n\t\t\tYOUR TOTAL TAX IS : %.5f",Total_tax);	
	
	
	
	
	
	getch();
	
	
	
}

  
  


void exit_program()
{ 
	system("CLS");
	printf("\t\t\t-------------------!!!---------------------\n");
    printf("\t\t\t-----Thank you for using Our Broking Service!!!-----\n");
    printf("\t\t\t-------BROUGHT TO YOU BY Nikhil Securities-------\n");
    getch();
}







 
