#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void account();
void admin();
float billing();
void search();
void searchbyfood();
void searchbyhotel();
void alterhoteldetails();
void alterfooddetails();
//Global variables
struct user    //struct to store the username and password
{
    char u[20];
}y;
struct pass
{
   char pwd[20];
}v;

struct bfr      //struct for buffer values used to store the choice entered by user
{
    char fname[20];
    char hname[20];
    int qty;
    float cost;
    float amt;
}b[20];
//2D arrays used to initialize food and hotel names
char d1[20][20]={"idli","dosa","poori","vada","","","","","","","","","","","","","","","",""};
char d2[20][20]={"chole bature","pav bhaji","stuffed parotta","vada pav","","","","","","","","","","","","","","","",""};
char d3[20][20]={"Hakka noodles","Manchurian","Fired rice","china noodles","","","","","","","","","","","","","","","",""};
char d4[20][20]={"veg sandwich","Burger","pizza","veg nuggets","","","","","","","","","","","","","","","",""};
char h1[20][20]={"South express","A2B restaurant","AAA hotel","ABCD restaurant","","","","","","","","","","","","","","","",""};
char h2[20][20]={"AB restaurant","KG foods","XYZ restaurant","Bombay restaurant","","","","","","","","","","","","","","","",""};
char h3[20][20]={"chopsticks","GS foods","Shahi grills","HSN restaurant","","","","","","","","","","","","","","","",""};
char h4[20][20]={"KFC","Mc Donalds","pizza hut","Burger king","","","","","","","","","","","","","","","",""};
char u1[20],pwd1[20];
int i,j,posit=0,tkey=1,posi=0;
float total1;


int dlen1=4,dlen2=4,dlen3=4,dlen4=4,hlen1=4,hlen2=4,hlen3=4,hlen4=4; //variables for array length & initialized with a value but we can change the size if needed

float c1[20]={30.00,30.00,30.00,30.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
float c2[20]={40.00,40.00,40.00,40.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
float c3[20]={50.00,50.00,50.00,50.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
float c4[20]={60.00,60.00,60.00,60.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00}; //cost of the dishes in each cuisine...here we have taken same cost for all 4 cuisines

float total=0.0; //variable for calculating the total amount to be paid.


int main()
{
    int rat;
    char user[20],ch,c[20]="customer",ad[20]="admin";
    //flag variable to proceed for cart

//Storing the details of the cuisine/dish names in different files
 FILE *ptr1=fopen("d1.txt","wb");
 fwrite(d1,sizeof(char),400,ptr1);
 fclose(ptr1);
 FILE *ptr2=fopen("d2.txt","wb");
 fwrite(d2,sizeof(char),400,ptr2);
 fclose(ptr1);
 FILE *ptr3=fopen("d3.txt","wb");
 fwrite(d3,sizeof(char),400,ptr3);
 fclose(ptr1);
 FILE *ptr4=fopen("d4.txt","wb");
 fwrite(d4,sizeof(char),400,ptr4);
 fclose(ptr1);
 //Storing the details of the hotel to corresponding cuisine
 FILE *ptr5=fopen("h1.txt","wb");
 fwrite(h1,sizeof(char),400,ptr5);
 fclose(ptr1);
 FILE *ptr6=fopen("h2.txt","wb");
 fwrite(h2,sizeof(char),400,ptr6);
 fclose(ptr1);
 FILE *ptr7=fopen("h3.txt","wb");
 fwrite(h3,sizeof(char),400,ptr7);
 fclose(ptr1);
 FILE *ptr8=fopen("h4.txt","wb");
 fwrite(h4,sizeof(char),400,ptr8);
 fclose(ptr1);

      do
      {
          printf("\t\t\t\t\t=====WELCOME TO TASTY FOODS=====\n \n");
          do{
             printf("Are you Admin or customer?\n");
              scanf("%s",user);
          }while((strcmp(user,ad))&&(strcmp(user,c)));

          if(!(strcmp(user,c)))
          {
            account();
            do
            {
                search();
                total=billing();
            }while(tkey==0);
            printf("\nOrder placed successfully");
            printf("\nNet amount to be paid : %.2f",total);
            total1=0.0;
          }
          else
          {
              admin();
          }

          total=0.0;
          do{
             printf("\nPlease provide your valid feedback rating (out of 5*):\n");
             scanf("%d",&rat);
          }while(rat<1||rat>5);
          printf("\n===Thanks for your valuable feedback===\n");
          printf("\n\n---You have successfully been logged out---\n");
      printf("\nDo you want to continue(Y/N)");
      scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
    exit(0);
}
void account()
{
   int flag=1,z=0,a=0,b=0,login,chk;
   char ch;
   printf("\n\tCustomer\n\t===========\n\t 1.Login\n\t 2.Sign up");
   do {
       printf("\nPlease enter a Valid option :");
        scanf("%d",&login);
      }while(login!=1&&login!=2);
   if(login==2)
   {
     char mail[20],pwd2[20],mobile[20];
     int age;
      FILE *pt,*pt1;
      pt=fopen("reg_u.txt","a");
     printf("\nSign Up\n=========");
     printf("\nEnter ur username:");
    scanf("%s",&y.u);
     fwrite(&y,sizeof(y),1,pt);
     fclose(pt);
     do
     {
         printf("\nEnter valid age:");
         scanf("%d",&age);
     }while(age<=0);
     do
     {
         printf("\nEnter Valid mail address:");
         scanf("%s",mail);
         for(j=0;j<strlen(mail);j++)
         {
             if(mail[j]=="@")
                chk=0;
         }
     }while((strlen(mail)<=5)||(chk==1));
     do
     {
         pt1=fopen("reg_pwd.txt","a");
          printf("\nEnter ur password:");
       scanf("%s",v.pwd);
     }while((strlen(v.pwd)<=8)||(strlen(v.pwd)>=12));
     fwrite(&v,sizeof(v),1,pt1);
     fclose(pt1);
     do
     {
         printf("\nRe-enter ur password:");
         scanf("%s",pwd2);
     }while((strcmp(pwd2,v.pwd)));
     int f=0;
     do
     {
         printf("\nEnter mobile number :");
        scanf("%s",mobile);
        for(j=0;j<10;j++)
        {
           if(mobile[j]>=0||mobile[j]<=9)
        {
            f=1;
        }
        }
     }while(f!=0&&(strlen(mobile)!=10));
     printf("\nAccount created successfully :)");
   }
   if(login==1)
   {
       printf("\nLOGIN\n=========");
       FILE *pt,*pt1;
       pt=fopen("reg_u.txt","r");
       pt1=fopen("reg_pwd.txt","r");
        printf("\nEnter username:");
        scanf("%s",u1);
        printf("\nEnter ur password:");
        scanf("%s",pwd1);
        while(fread(&y,sizeof(y),1,pt)&&fread(&v,sizeof(v),1,pt1))
        {
            if(strcmp(u1,y.u)==0&&strcmp(pwd1,v.pwd)==0)
            {
                 printf("\nYou have logged in successfully!!");
                 printf("\n Have a wonderful day!!\n");
            }
            else{
                printf("\n Username and password does not match!!");
                printf("\n Please enter correct Username and Password\n");
                account();
            }
        }
        fclose(pt);
        fclose(pt1);
   }
}
void search()
{
    int t; //flag variable
    do
    {
        printf("\nSearch by :\n 1.Food\n 2.Hotel");
        printf("\nEnter a valid option :(1 or 2)");
        scanf("%d",&t);
    }while(t!=1&&t!=2);
    if(t==1)
    {
        searchbyfood();
    }
    else{searchbyhotel();}
}
void admin()
{
    int alter;
    printf("\n\tADMIN\n\t=======\n 1.Alter Food details\n 2.Alter Hotel details");
    do
    {
        printf("\nEnter a valid option (1 or 2)");
        scanf("%d",&alter);
    }while(alter!=1&&alter!=2);
    if(alter==1)
    {
       alterfooddetails();
    }
    else{alterhoteldetails();}
}
void cart(char hname1[],float cost1,char dname1[],int *qt)
{
   strcpy(b[posi].fname,dname1);
    strcpy(b[posi].hname,hname1);
   b[posi].cost=cost1;
   b[posi].qty=*qt;
   b[posi].amt=(*qt)*cost1;
   posi=posi+1;
}
float billing()
{
   FILE *out;
   int choi;
   out=fopen("bill.txt","w");
   if(out==NULL)
   {
       printf("\n error!");
   }
   fwrite(&b[posit],sizeof(struct bfr),1,out);
   fclose(out);
   total1=total1+b[posit].amt;
   do{
     printf("\n 1.Place your order\n");
     printf("\n 2.Add items to your cart\n");
     printf("\nEnter your choice :\n");
     scanf("%d",&choi);
   }while((choi<=0)||(choi>2));

   if(choi==1)
   {
      printf("\nS.no\t Dishname \t Hotelname\tQuantity\t Costper \t NetAmount\n");
      for(i=0;i<(posit+1);i++)
      {
          printf("\n %d\t %s\t \t %s \t  %d \t \t %.2f \t \t %.2f \n",i+1,b[i].fname,b[i].hname,b[i].qty,b[i].cost,b[i].amt);
      }
      tkey=1;
   }
   if(choi==2){
      posit=posit+1;
      tkey=0;
   }
   return total1;
}

void searchbyfood()
{
	int qty,*q;
	q=(int*)malloc(sizeof(int));
	 if(q==NULL) {
    printf("Error! memory not allocated.");
    searchbyfood();
  }
	int i,s;

	s=1;

	int cuisine,choice;
	do{
		printf("Variety of food available are:\n");
		printf("___________\n");
		printf("1.South Indian\n2.North Indian\n3.Chinese or Italian\n4.Fast foods and Beverages\n");
		printf("Enter valid choice\n");
		scanf("%d",&cuisine);
		switch(cuisine){

		case(1):{

		for(i=0;(i<dlen1)&&s==1;i++){
                   if(d1[i]==""){
				s=0;
			}
			else{
				printf("%d.%s-%.2f\n",i+1,d1[i],c1[i]);
			}
                }

		do{
			printf("enter valid choice\n");
			scanf("%d",&choice);
		}while((choice<=0)||(choice>dlen1));
	s=1;
	for(i=0;(i<hlen1)&&s==1;i++){
               if(h1[i]==""){
			s=0;
		}
		else{
			printf("\n%d-%s",i+1,h1[i]);
            }

		}
	do{
		printf("enter hotel number:\n");
		scanf("%d",&i);
	}while(i>(hlen1));
	do{
		printf("enter the quantity:\n");
		scanf("%d",q);
	}while(*q<=0);

	/*q->q1[choice-1]=(q->q1[choice-1])-qty;*/

	cart(h1[i-1],c1[choice-1],d1[choice-1],q);
    break;
}

case(2):{
	for(i=0;(i<dlen2)&&s==1;i++){
		if(d2[i]==""){
			s=0;
		}
		else{
			printf("\n%d.%s-%.2f",i+1,d2[i],c2[i]);
		}
	}
	do{
		printf("\nenter valid choice:");
		scanf("%d",&choice);
	}while((choice<=0)||(choice>dlen2));
	s=1;
	for(i=0;(i<hlen2)&&s==1;i++){
		if(h2[i]==""){
			s=0;
		}
		else{
			printf("\n%d.%s",i+1,h2[i]);
		}
	}
	do{
		printf("enter hotel number:\n");
scanf("%d",&i);
	}while(i>(hlen2));
	do{
		printf("enter quantity\n");
		scanf("%d",q);
	}while(*q<=0);
	//q->q2[choice-1]=(q->q2[choice-1])-qty;
cart(h2[i-1],c2[choice-1],d2[choice-1],q);
break;
}
case(3):{
	for(i=0;(i<dlen3)&&s==1;i++){
		if(d3[i]==""){
			s=0;
		}
		else{
			printf("%d.%s-%.2f\n",i+1,d3[i],c3[i]);
		}
	}
	do{
		printf("enter valid choice\n");
		scanf("%d",&choice);
	}while((choice<=0)||(choice>dlen3));
s=1;
for(i=0;(i<hlen3)&&s==1;i++){
	if(h3[i]==""){
		s=0;
	}
	else{
		printf("%d.%s\n",i+1,h3[i]);
	}
}
do{
	printf("enter hotel number\n");
	scanf("%d",&i);
}while(i>(hlen3));
do{
	printf("enter quantity\n");
	scanf("%d",q);
}while(*q<=0);
//q->q3[choice-1]=q->q3[choice-1]-qty;
cart(h3[i-1],c3[choice-1],d3[choice-1],q);
break;
}
case(4):{


	for(i=0;(i<dlen4)&&s==1;i++){
		if(d4[i]==""){
			s=0;
		}
		else{
			printf("%d.%s-%.2f\n",i+1,d4[i],c4[i]);
		}
	}
	do{
		printf("enter valid choice\n");
		scanf("%d",&choice);
	}while((choice<=0)||(choice>dlen4));
s=1;
for(i=0;(i<hlen4)&&s==1;i++){
	if(h4[i]==""){
		s=0;
	}
	else{
		printf("%d.%s\n",i+1,h4[i]);
	}
}
do{
	printf("enter hotel number\n");
	scanf("%d",&i);
}while(i>(hlen4));
do{
	printf("enter quantity\n");
	scanf("%d",q);
}while(*q<=0);
//q->q4[choice-1]=q->q4[choice-1]-qty;
cart(h4[i-1],c4[choice-1],d4[choice-1],q);


break;
}}
	}while(cuisine>4||cuisine<=0);

}
void searchbyhotel()
{
  int qty,*q;
	q=(int*)malloc(sizeof(int));
   int cuisine,choice,s,i;

   s=1;
   do{
   	printf("types of hotels available are\n1.South Indian Hotel\n2.North Indian Restaurant\n3.Chopsticks\n4.ZZ Fast Foods\n");
   	scanf("%d",&cuisine);
   	switch(cuisine){
   		case(1):{
   			for(i=0;(i<hlen1)&&s==1;i++){
   				if(h1[i]==""){
   					s=1;
				   }
				   else{
				   	printf("%d.%s\n",i+1,h1[i]);
				   }
			   }
			   do{

			   printf("enter hotel number:\n");
			   scanf("%d",&i);
		}while(i>hlen1);
	        s=1;
	        for(choice=0;(choice<dlen1)&&s==1;choice++){
	        	if(d1[choice]==""){
	        		s=0;
				}
				else{
					printf("%d.%s-%.2f\n",choice+1,d1[choice],c1[choice]);
				}
			}
			do{
		printf("enter valid choice\n");
		scanf("%d",&choice);
	}while((choice<=0)||(choice>dlen4));
			do{
				printf("enter quantity\n");
				scanf("%d",q);
			}while(*q<=0);
			//q->q1[choice-1]=q->q1[choice-1]-qty;
			cart(h1[i-1],c1[choice-1],d1[choice-1],q);
			cuisine=1;
			break;
			}
		case(2):{
			for(i=0;(i<hlen2)&&s==1;i++){
   				if(h2[i]==""){
   					s=1;
				   }
				   else{
				   	printf("%d.%s\n",i+1,h2[i]);
				   }
			   }
			   do{

			   printf("enter hotel number:\n");
			   scanf("%d",&i);
		}while(i>hlen2);
	        s=1;
	        for(choice=0;(choice<dlen2)&&s==1;choice++){
	        	if(d2[choice]==""){
	        		s=0;
				}
				else{
					printf("%d.%s-%.2f\n",choice+1,d2[choice],c2[choice]);
				}
			}
			do{
		printf("enter valid choice\n");
		scanf("%d",&choice);
	}while((choice<=0)||(choice>dlen4));
			do{
				printf("enter quantity\n");
				scanf("%d",q);
			}while(*q<=0);
			//q->q2[choice-1]=q->q2[choice-1]-qty;
			cart(h2[i-1],c2[choice-1],d2[choice-1],q);
			cuisine=2;

			break;
		}
		case(3):{
			for(i=0;(i<hlen3)&&s==1;i++){
   				if(h3[i]==""){
   					s=1;
				   }
				   else{
				   	printf("%d.%s\n",i+1,h3[i]);
				   }
			   }
			   do{

			   printf("enter hotel number:\n");
			   scanf("%d",&i);
		}while(i>hlen3);
	        s=1;
	        for(choice=0;(choice<dlen3)&&s==1;choice++){
	        	if(d3[choice]==""){
	        		s=0;
				}
				else{
					printf("%d.%s-%.2f\n",choice+1,d3[choice],c3[choice]);
				}
			}
			do{
		printf("enter valid choice\n");
		scanf("%d",&choice);
	}while((choice<=0)||(choice>dlen4));
			do{
				printf("enter quantity\n");
				scanf("%d",q);
			}while(*q<=0);
			//q->q3[choice-1]=q->q3[choice-1]-qty;
			cart(h3[i-1],c3[choice-1],d3[choice-1],q);
			cuisine=3;
			break;
		}
		case(4):{
			for(i=0;(i<hlen4)&&s==1;i++){
   				if(h4[i]==""){
   					s=1;
				   }
				   else{
				   	printf("%d.%s\n",i+1,h4[i]);
				   }
			   }
			   do{

			   printf("enter hotel number:\n");
			   scanf("%d",&i);
		}while(i>hlen4);
	        s=1;
	        for(choice=0;(choice<dlen4)&&s==1;choice++){
	        	if(d4[choice]==""){
	        		s=0;
				}
				else{
					printf("%d.%s-%.2f\n",choice+1,d4[choice],c4[choice]);
				}
			}
			do{
		printf("enter valid choice\n");
		scanf("%d",&choice);
	}while((choice<=0)||(choice>dlen4));
			do{
				printf("enter quantity\n");
				scanf("%d",q);
			}while(*q<=0);
			//q->q4[choice-1]=q->q4[choice-1]-qty;
			cart(h4[i-1],c4[choice-1],d4[choice-1],q);
			cuisine=4;
			break;
		}
	   }
   	   }while(cuisine>4||cuisine<=0);
}
struct food1{
	char name[40];
	float cost;
	//char cuisine[50];
};
struct food2{
	char name[40];
	float cost;
	//char cuisine[50];
}f2[20];
struct food3{
	char name[40];
	float cost;
	//char cuisine[50];
}f3[20];
struct food4{
	char name[40];
	float cost;
	//char cuisine[50];
}f4[20];
int t1=4;
void add1(struct food1 *a){
	FILE *fp;
	t1=t1+1;
	int p=0;
	//char dish[20];
	dlen1=dlen1+1;
	fp=fopen("d1.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
       printf("\nEnter the dish name:");
       fflush(stdin);
	          gets(a->name);
       fflush(stdin);

//	fprintf(fp,"%s",a->name);
       printf("\nEnter the cost:");
       scanf("%f",&a->cost);
  //     fprintf(fp,"\t%.2f",a->cost);
       for(i=0;i<20;i++){
       	    if(!(strcmp(d1[i],""))){
       	    	strcpy(d1[i],a->name);
       	    	c1[i]=a->cost;
       	    	break;
			   }
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d1[i]);
		fprintf(fp,"\t\t%.2f",c1[i]);

	}

       fclose(fp);
   }
void add2(struct food2 *x){
	FILE *fp;
	//char dish[20];
	t1=t1+1;
	dlen2=dlen2+1;
	fp=fopen("d2.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
       printf("\nEnter the dish name:");
       fflush(stdin);
	          gets(x->name);
       fflush(stdin);

//	fprintf(fp,"%d. %s",x->name);
       printf("\nEnter the cost:");
       scanf("%f",&x->cost);
      // fprintf(fp,"\t%.2f",x->cost);
       for(i=0;i<20;i++){
       	    if(!(strcmp(d2[i],""))){
       	    	strcpy(d2[i],x->name);
       	    	c2[i]=x->cost;
       	    	break;
			   }
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d2[i]);
		fprintf(fp,"\t\t%.2f",c2[i]);

	}

       fclose(fp);
   }
void add3(struct food3 *c){
	FILE *fp;
	//char dish[20];
	t1=t1+1;
	dlen3=dlen3+1;
	fp=fopen("d3.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
       printf("\nEnter the dish name:");
       fflush(stdin);
	          gets(c->name);
       fflush(stdin);

//	fprintf(fp,"%s",c->name);
       printf("\nEnter the cost:");
       scanf("%f",&c->cost);
  //     fprintf(fp,"\t%.2f",c->cost);
       for(i=0;i<20;i++){
       	    if(!(strcmp(d3[i],""))){
       	    	strcpy(d3[i],c->name);
       	    	c3[i]=c->cost;
       	    	break;
			   }
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d3[i]);
		fprintf(fp,"\t\t%.2f",c3[i]);

	}

       fclose(fp);
   }
void add4(struct food4 *d){
	FILE *fp;
	//char dish[20];
	t1=t1+1;
	dlen4=dlen4+1;
	fp=fopen("d4.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
       printf("\nEnter the dish name:");
       fflush(stdin);
	          gets(d->name);
       fflush(stdin);

//	fprintf(fp,"%s",d->name);
       printf("\nEnter the cost:");
       scanf("%f",&d->cost);
  //     fprintf(fp,"\t%.2f",d->cost);
       for(i=0;i<20;i++){
       	    if(!(strcmp(d4[i],""))){
       	    	strcpy(d4[i],d->name);
       	    	c4[i]=d->cost;
       	    	break;
			   }
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d4[i]);
		fprintf(fp,"\t\t%.2f",c4[i]);

	}

       fclose(fp);
   }
void alter1(struct food1 *a){
	FILE *fp;
	int p=0;
	int ed,y=0,t;
	//char dish[20];
	fp=fopen("d1.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
	printf("\nWhat would you like to edit?\n1.Food Name\n2.Cost\n");
	scanf("%d",&ed);
	if(ed==1){
       printf("\nEnter the dish name to be edited: ");
       int j;
       for( j=0;j<20;j++){
       	if((strcmp(d1[j],""))){
       	printf("\n%d.%s",j+1,d1[j]);
       }
	   }
	   fflush(stdin);
	   printf("\nChoice:");
	   scanf("%d",&t);
       printf("\nEnter the correct food name: ");
       char nm[20];
       fflush(stdin);
       gets(nm);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	strcpy(d1[i],nm);
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}

   if(y==0){
   	printf("\nName not found!");
   }

   }

	//fprintf(fp,"%s",a->name);
	else{
			char nam[20];
       printf("\nEnter the food name:");
       for( j=0;j<20;j++){
       	if((strcmp(d1[j],""))){
       	printf("\n%d.%s",j+1,d1[j]);
       }
   }
       //scanf("%f",&a->cost);
       printf("\nChoice:");
       scanf("%d",&t);
       printf("\nEnter the correct cost:");
       float ct;
       scanf("%f",&ct);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	c1[i]=ct;
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
   	printf("\nName not found!");
   }
}

       //fprintf(fp,"\t%.2f",a->cost);
	   for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d1[i]);
		fprintf(fp,"\t\t%.2f",c1[i]);

	}

       fclose(fp);
   }
void alter2(struct food2 *x){
	FILE *fp;
	int p=0,t;
	int ed,y=0;
	//char dish[20];
	fp=fopen("d2.txt","w");

	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
	printf("\nWhat would you like to edit?\n1.Food Name\n2.Cost\n");
	scanf("%d",&ed);
	if(ed==1){
       printf("\nEnter the dish name to be edited: ");
       int j;
       for( j=0;j<20;j++){
       	if((strcmp(d2[j],""))){
       	printf("\n%d.%s",j+1,d2[j]);
       }
	   }
	   printf("\nChoice:");
       scanf("%d",&t);
       printf("\nEnter the correct food name: ");
       char nm[20];
       fflush(stdin);
       gets(nm);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	strcpy(d2[i],nm);
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
   	printf("\nName not found!");
   }
   }


	//fprintf(fp,"%s",a->name);
	else{
			char nam[20];
       printf("\nEnter the food name:");
       for( j=0;j<20;j++){
       	if((strcmp(d2[j],""))){
       	printf("\n%d.%s",j+1,d2[j]);
       }
   }
       //scanf("%f",&a->cost);
       printf("\nChoice:");
       scanf("%d",&t);
       printf("\nEnter the correct cost:");
       float ct;
       scanf("%f",&ct);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	c2[i]=ct;
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
   	printf("\nName not found!");
   }
   }
       //fprintf(fp,"\t%.2f",a->cost);
	   for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d2[i]);
		fprintf(fp,"\t\t%.2f",c2[i]);

	}

       fclose(fp);
   }
void alter3(struct food3 *c){
	FILE *fp;
	int p=0,t;
	int ed,y=0;
	//char dish[20];
	fp=fopen("d3.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
	printf("\nWhat would you like to edit?\n1.Food Name\n2.Cost\n");
	scanf("%d",&ed);
	if(ed==1){
       printf("\nEnter the dish name to be edited: ");
       int j;
       for( j=0;j<20;j++){
       	if((strcmp(d3[j],""))){
       	printf("\n%d.%s",j+1,d3[j]);
       }
	   }
	   printf("\nChoice:");
	   scanf("%d",&t);
       printf("\nEnter the correct food name: ");
       char nm[20];
       fflush(stdin);
       gets(nm);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	strcpy(d3[i],nm);
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
   	printf("\nName not found!");
   }
   }


	//fprintf(fp,"%s",a->name);
	else{
			char nam[20];
       printf("\nEnter the food name:");
       for( j=0;j<20;j++){
       	if((strcmp(d3[j],""))){
       	printf("\n%d.%s",j+1,d3[j]);
       }
   }
       //scanf("%f",&a->cost);
       printf("\nChoice:");
       scanf("%d",&t);
       printf("\nEnter the correct cost:");
       float ct;
       scanf("%f",&ct);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	c3[i]=ct;
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
		printf("\nName not found!");
	}
   }
       //fprintf(fp,"\t%.2f",a->cost);
	   for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d3[i]);
		fprintf(fp,"\t\t%.2f",c3[i]);

	}

       fclose(fp);
   }
void alter4(struct food4 *d){
	FILE *fp;
	int p=0,t;
	int ed,y=0;
	//char dish[20];
	fp=fopen("d4.txt","w");

	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
	printf("\nWhat would you like to edit?\n1.Food Name\n2.Cost\n");
	scanf("%d",&ed);
	if(ed==1){
       printf("\nEnter the dish name to be edited: ");
       int j;
       for( j=0;j<20;j++){
       	if((strcmp(d4[j],""))){
       	printf("\n%d.%s",j+1,d4[j]);
       }
	   }
	   printf("\nChoice:");
       scanf("%d",&t);
       printf("\nEnter the correct food name: ");
       char nm[20];
       fflush(stdin);
       gets(nm);
       for(i=0;i<20;i++){
       	    if(i+1==t){

				strcpy(d4[i],nm);
				y=1;
				printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}
	 if(y==0){
   	printf("\nName not found!");
   }
   }


	//fprintf(fp,"%s",a->name);
	else{
			char nam[20];
       printf("\nEnter the food name:");
       for( j=0;j<20;j++){
       	if((strcmp(d4[j],""))){
       	printf("\n%d.%s",j+1,d4[j]);
       }
   }
       //scanf("%f",&a->cost);
       printf("\nChoice:");
       scanf("%d",&t);
       printf("\nEnter the correct cost:");
       float ct;
       scanf("%f",&ct);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	c4[i]=ct;
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}
	 if(y==0){
   	printf("\nName not found!");
   }
   }
   for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d4[i]);
		fprintf(fp,"\t\t%.2f",c4[i]);

	}
       //fprintf(fp,"\t%.2f",a->cost);



       fclose(fp);
   }

void del1(struct food1 *a){
	FILE *fp;
	int p=0;
	int y=0;
	int s;
	//char dish[20];
	fp=fopen("d1.txt","w");
	//fp =(struct food1 *)malloc(100*sizeof(struct food1));
       printf("\nEnter the dish name:");
       for( j=0;j<20;j++){
       	if((strcmp(d1[j],""))){
       	printf("\n%d.%s",j+1,d1[j]);
       }
	   }
	   printf("\nChoice:");
       scanf("\n%d",&s);

	//fprintf(fp,"%s",a->name);
       //printf("\nEnter the cost:");
      // scanf("%f",&a->cost);
       //fprintf(fp,"\t%.2f",a->cost);
       for(i=0;i<20;i++){
       	    if(i+1==s){
       	    	strcpy(d1[i],"--deleted--");
       	    	//fprintf(fp,d1[i]);
       	    	c1[i]=0.00;
       	    	y=1;
       	    	printf("\n\t\tREMOVED SUCCESSFULLY!");
       	    	break;
			   }
	}if(y==0){
		printf("\nName not found!");
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d1[i]);
	//	while(c1[i]!=0.00){
		fprintf(fp,"\t\t");
		fprintf(fp,"%.2f",c1[i]);
//	}
	}


       fclose(fp);
   }
void del2(struct food2 *x){
	FILE *fp;
	int p=0;
	int s;
	//char dish[20];
	fp=fopen("d2.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
       printf("\nEnter the dish name:");
       for( j=0;j<20;j++){
       	if((strcmp(d2[j],""))){
       	printf("\n%d.%s",j+1,d2[j]);
       }
	   }
       printf("\nChoice:");
       scanf("%d",&s);

	//fprintf(fp,"%s",a->name);
       //printf("\nEnter the cost:");
      // scanf("%f",&a->cost);
       //fprintf(fp,"\t%.2f",a->cost);
       int y=0;
       for(i=0;i<20;i++){
       	    if(i+1==s){
       	    	strcpy(d2[i],"--deleted--");
       	    	//fprintf(fp,d1[i]);
       	    	c2[i]=0.00;
       	    	y=1;
       	    	printf("\n\t\tREMOVED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
		printf("\nName not found!");
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d2[i]);
	//	while(c1[i]!=0.00){
		fprintf(fp,"\t\t");
		fprintf(fp,"%.2f",c2[i]);
//	}
	}


       fclose(fp);
   }
void del3(struct food3 *c){
	FILE *fp;
	int p=0,y=0;
	int s;
	//char dish[20];
	fp=fopen("d3.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
       printf("\nEnter the dish name:");
       for( j=0;j<20;j++){
       	if((strcmp(d3[j],""))){
       	printf("\n%d.%s",j+1,d3[j]);
       }
	   }
	   printf("\nChoice:");
	   scanf("%d",&s);

	//fprintf(fp,"%s",a->name);
       //printf("\nEnter the cost:");
      // scanf("%f",&a->cost);
       //fprintf(fp,"\t%.2f",a->cost);
       for(i=0;i<20;i++){
       	    if(i+1==s){
       	    	strcpy(d3[i],"--deleted--");
       	    	//fprintf(fp,d1[i]);
       	    	c3[i]=0.00;
       	    	y=1;
       	    	printf("\n\t\tREMOVED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
		printf("\nName not found!");
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d3[i]);
	//	while(c1[i]!=0.00){
		fprintf(fp,"\t\t");
		fprintf(fp,"%.2f",c3[i]);
//	}
	}


       fclose(fp);
   }
void del4(struct food4 *d){
	FILE *fp;
	int p=0,y=0;
	int s;
	//char dish[20];
	fp=fopen("d4.txt","w");
	//fp = (struct food1 *)malloc(100*sizeof(struct food1));
       printf("\nEnter the dish name:");
       for( j=0;j<20;j++){
       	if((strcmp(d4[j],""))){
       	printf("\n%d.%s",j+1,d4[j]);
       }
	   }
	   printf("\nChoice:");
	   scanf("%d",&s);

	//fprintf(fp,"%s",a->name);
       //printf("\nEnter the cost:");
      // scanf("%f",&a->cost);
       //fprintf(fp,"\t%.2f",a->cost);
       for(i=0;i<20;i++){
       	    if(i+1==s){
       	    	strcpy(d4[i],"--deleted--");
       	    	//fprintf(fp,d1[i]);
       	    	y=1;
       	    	c4[i]=0.00;
       	    	printf("\n\t\tREMOVED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
		printf("\nName not found!");
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,d4[i]);
	//	while(c1[i]!=0.00){
		fprintf(fp,"\t\t");
		fprintf(fp,"%.2f",c4[i]);
//	}
	}


       fclose(fp);
   }

void alterfooddetails(){
	struct food1 f1[20];
	int ans,an1;
	do{
	int an,p;
	printf("\nEnter your choice:\n1.Add\n2.Alter\n3.Delete\n");
	printf("Choice : ");
	scanf("%d",&an);
	switch(an){

		case(1):{
				do{
				printf("\nEnter the cuisine:-");
	             printf("\n1.South Indian\n2.North Indian\n3.Chinese or Italian\n4.Fast food and Beverages");
	             printf("\nChoice:");
	             scanf("\n%d",&an1);
			switch(an1){
				case(1):{
					add1(f1);
					printf("\n\t\t\tSUCCESSFULLY ADDED!");
					break;
				}
				case(2):{
					add2(f2);
					printf("\n\t\t\tSUCCESSFULLY ADDED!");
					break;
				}
				case(3):{
					add3(f3);
					printf("\n\t\t\tSUCCESSFULLY ADDED!");
					break;
				}
				case(4):{
					add4(f4);
					printf("\n\t\t\tSUCCESSFULLY ADDED!");
					break;
				}
				}
					printf("\nAdd another item?(1/0) : ");
       scanf("%d",&p);

   }while(p==1);
				break;
			}

		case(2):{
			p=0;
			do{
				printf("\nEnter the cuisine:-");
	             printf("\n1.South Indian\n2.North Indian\n3.Chinese or Italian\n4.Fast food and Beverages");
	             printf("\nChoice:");
	             scanf("\n%d",&an1);
			switch(an1){
				case(1):{
					alter1(f1);
					break;
				}
				case(2):{
					alter2(f2);
					break;
				}
				case(3):{
					alter3(f3);
					break;
				}
				case(4):{
					alter4(f4);
					break;
				}
				}
					printf("\nAlter another item?(1/0) : ");
       scanf("%d",&p);

   }while(p==1);
			break;
		}
		case(3):{
			p=0;
			do{
				printf("\nEnter the cuisine:-");
	             printf("\n1.South Indian\n2.North Indian\n3.Chinese or Italian\n4.Fast food and Beverages");
	             printf("\nChoice:");
	             scanf("\n%d",&an1);
			switch(an1){
				case(1):{
					del1(f1);
					break;
				}
				case(2):{
					del2(f2);
					break;
				}
				case(3):{
					del3(f3);
					break;
				}
				case(4):{
					del4(f4);
					break;
				}
				}
					printf("\nRemove another item?(1/0) : ");
       scanf("%d",&p);

   }while(p==1);
			break;
		}
		default:{
			printf("\nEnter a valid choice");
			break;
		}
	}
	printf("\nDo you want to change anything further?(1/0)");
	scanf("%d",&ans);
}while(ans==1);
}
  void addh1(){
	FILE *fp;
	int p=0;
	t1=t1+1;
	char name[20];
	fp=fopen("h1.txt","w");
       printf("\nEnter the hotel name:");
       fflush(stdin);
	          gets(name);
       fflush(stdin);

       for(i=0;i<20;i++){
       	    if(!(strcmp(h1[i],""))){
       	    	strcpy(h1[i],name);
       	    	break;
			   }
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h1[i]);

	}

       fclose(fp);
   }
void addh2(){
	FILE *fp;
	char name[20];
	fp=fopen("h2.txt","w");
	t1=t1+1;
       printf("\nEnter the hotel name:");
       fflush(stdin);
	          gets(name);
       fflush(stdin);
       for(i=0;i<20;i++){
       	    if(!(strcmp(h2[i],""))){
       	    	strcpy(h2[i],name);
       	    	break;
			   }
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h2[i]);

	}

       fclose(fp);
   }
void addh3(){
	FILE *fp;
	char name[20];
	fp=fopen("h3.txt","w");
	t1=t1+1;
       printf("\nEnter the hotel name:");
       fflush(stdin);
	          gets(name);
       fflush(stdin);

       for(i=0;i<20;i++){
       	    if(!(strcmp(h3[i],""))){
       	    	strcpy(h3[i],name);
       	    	break;
			   }
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h3[i]);

	}

       fclose(fp);
   }
void addh4(){
	FILE *fp;
	char name[20];
	fp=fopen("h4.txt","w");
	t1=t1+1;
       printf("\nEnter the hotel name:");
       fflush(stdin);
	          gets(name);
       fflush(stdin);

       for(i=0;i<20;i++){
       	    if(!(strcmp(h4[i],""))){
       	    	strcpy(h4[i],name);
       	    	break;
			   }
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h4[i]);

	}

       fclose(fp);
   }
void alterh1(){
	FILE *fp;
	int p=0;
	int y=0,t;
	fp=fopen("h1.txt","w");
       printf("\nEnter the hotel name to be edited: ");
       int j;
       for( j=0;j<20;j++){
       	if((strcmp(h1[j],""))){
       	printf("\n%d.%s",j+1,h1[j]);
       }
	   }
	   fflush(stdin);
	   printf("\nChoice:");
	   scanf("%d",&t);
       printf("\nEnter the correct hotel name: ");
       char nm[20];
       fflush(stdin);
       gets(nm);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	strcpy(h1[i],nm);
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}

   if(y==0){
   	printf("\nName not found!");
   }




	   for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h1[i]);

	}

       fclose(fp);
   }
void alterh2(){
	FILE *fp;
	int p=0;
	int y=0,t;
	fp=fopen("h2.txt","w");
       printf("\nEnter the hotel name to be edited: ");
       int j;
       for( j=0;j<20;j++){
       	if((strcmp(h2[j],""))){
       	printf("\n%d.%s",j+1,h2[j]);
       }
	   }
	   fflush(stdin);
	   printf("\nChoice:");
	   scanf("%d",&t);
       printf("\nEnter the correct hotel name: ");
       char nm[20];
       fflush(stdin);
       gets(nm);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	strcpy(h2[i],nm);
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}

   if(y==0){
   	printf("\nName not found!");
   }




	   for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h2[i]);

	}

       fclose(fp);
   }
void alterh3(){
	FILE *fp;
	int p=0;
	int y=0,t;
	fp=fopen("h3.txt","w");
       printf("\nEnter the hotel name to be edited: ");
       int j;
       for( j=0;j<20;j++){
       	if((strcmp(h3[j],""))){
       	printf("\n%d.%s",j+1,h3[j]);
       }
	   }
	   fflush(stdin);
	   printf("\nChoice:");
	   scanf("%d",&t);
       printf("\nEnter the correct hotel name: ");
       char nm[20];
       fflush(stdin);
       gets(nm);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	strcpy(h3[i],nm);
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}

   if(y==0){
   	printf("\nName not found!");
   }




	   for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h3[i]);

	}

       fclose(fp);
   }
void alterh4(){
	FILE *fp;
	int p=0;
	int y=0,t;
	fp=fopen("h4.txt","w");
       printf("\nEnter the hotel name to be edited: ");
       int j;
       for( j=0;j<20;j++){
       	if((strcmp(h4[j],""))){
       	printf("\n%d.%s",j+1,h4[j]);
       }
	   }
	   fflush(stdin);
	   printf("\nChoice:");
	   scanf("%d",&t);
       printf("\nEnter the correct hotel name: ");
       char nm[20];
       fflush(stdin);
       gets(nm);
       for(i=0;i<20;i++){
       	    if(i+1==t){
       	    	strcpy(h4[i],nm);
       	    	y=1;
       	    	printf("\n\t\tALTERED SUCCESSFULLY!");
       	    	break;
			   }
	}

   if(y==0){
   	printf("\nName not found!");
   }




	   for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h4[i]);

	}

       fclose(fp);
   }

void delh1(){
	FILE *fp;
	int p=0;
	int y=0;
	int s;
	fp=fopen("h1.txt","w");
       printf("\nEnter the hotel name:");
       for( j=0;j<20;j++){
       	if((strcmp(h1[j],""))){
       	printf("\n%d.%s",j+1,h1[j]);
       }
	   }
	   printf("\nChoice:");
       scanf("\n%d",&s);
       for(i=0;i<20;i++){
       	    if(i+1==s){
       	    	strcpy(h1[i],"--deleted--");
       	    	y=1;
       	    	printf("\n\t\tREMOVED SUCCESSFULLY!");
       	    	break;
			   }
	}if(y==0){
		printf("\nName not found!");
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h1[i]);

	}
       fclose(fp);
   }
void delh2(){
	FILE *fp;
	int p=0;
	int s;
	fp=fopen("h2.txt","w");
       printf("\nEnter the hotel name:");
       for( j=0;j<20;j++){
       	if((strcmp(h2[j],""))){
       	printf("\n%d.%s",j+1,h2[j]);
       }
	   }
       printf("\nChoice:");
       scanf("%d",&s);
       int y=0;
       for(i=0;i<20;i++){
       	    if(i+1==s){
       	    	strcpy(h2[i],"--deleted--");
       	    	y=1;
       	    	printf("\n\t\tREMOVED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
		printf("\nName not found!");
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h2[i]);
	}


       fclose(fp);
   }
void delh3(){
	FILE *fp;
	int p=0,y=0;
	int s;
	fp=fopen("h3.txt","w");
       printf("\nEnter the hotel name:");
       for( j=0;j<20;j++){
       	if((strcmp(h3[j],""))){
       	printf("\n%d.%s",j+1,h3[j]);
       }
	   }
	   printf("\nChoice:");
	   scanf("%d",&s);

       for(i=0;i<20;i++){
       	    if(i+1==s){
       	    	strcpy(h3[i],"--deleted--");
       	    	y=1;
       	    	printf("\n\t\tREMOVED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
		printf("\nName not found!");
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h3[i]);
	}
       fclose(fp);
   }
void delh4(){
	FILE *fp;
	int p=0,y=0;
	int s;
	fp=fopen("h4.txt","w");
       printf("\nEnter the hotel name:");
       for( j=0;j<20;j++){
       	if((strcmp(h4[j],""))){
       	printf("\n%d.%s",j+1,h4[j]);
       }
	   }
	   printf("\nChoice:");
	   scanf("%d",&s);

       for(i=0;i<20;i++){
       	    if(i+1==s){
       	    	strcpy(h4[i],"--deleted--");
       	    	y=1;
       	    	printf("\n\t\tREMOVED SUCCESSFULLY!");
       	    	break;
			   }
	}
	if(y==0){
		printf("\nName not found!");
	}
	for(i=0;i<t1;i++){
		fprintf(fp,"\n%d. ",i+1);
		fprintf(fp,h4[i]);
	}


       fclose(fp);
   }
void alterhoteldetails()
{
    int ans,an1;
	do{
	int an,p;
	printf("\nEnter your choice:\n1.Add\n2.Alter\n3.Delete\n");
	printf("Choice : ");
	scanf("%d",&an);
	switch(an){

		case(1):{
				do{
				printf("\nEnter the cuisine:-");
	             printf("\n1.South Indian\n2.North Indian\n3.Chinese or Italian\n4.Fast food and Beverages");
	             printf("\nChoice:");
	             scanf("\n%d",&an1);
			switch(an1){
				case(1):{
					addh1();
					printf("\n\t\t\tSUCCESSFULLY ADDED!");
					break;
				}
				case(2):{
					addh2();
					printf("\n\t\t\tSUCCESSFULLY ADDED!");
					break;
				}
				case(3):{
					addh3();
					printf("\n\t\t\tSUCCESSFULLY ADDED!");
					break;
				}
				case(4):{
					addh4();
					printf("\n\t\t\tSUCCESSFULLY ADDED!");
					break;
				}
				}
					printf("\nAdd another item?(1/0) : ");
       scanf("%d",&p);

   }while(p==1);
				break;
			}

		case(2):{
			p=0;
			do{
				printf("\nEnter the cuisine:-");
	             printf("\n1.South Indian\n2.North Indian\n3.Chinese or Italian\n4.Fast food and Beverages");
	             printf("\nChoice:");
	             scanf("\n%d",&an1);
			switch(an1){
				case(1):{
					alterh1();
					break;
				}
				case(2):{
					alterh2();
					break;
				}
				case(3):{
					alterh3();
					break;
				}
				case(4):{
					alterh4();
					break;
				}
				}
					printf("\nAlter another item?(1/0) : ");
       scanf("%d",&p);

   }while(p==1);
			break;
		}
		case(3):{
			p=0;
			do{
				printf("\nEnter the cuisine:-");
	             printf("\n1.South Indian\n2.North Indian\n3.Chinese or Italian\n4.Fast food and Beverages");
	             printf("\nChoice:");
	             scanf("\n%d",&an1);
			switch(an1){
				case(1):{
					delh1();
					break;
				}
				case(2):{
					delh2();
					break;
				}
				case(3):{
					delh3();
					break;
				}
				case(4):{
					delh4();
					break;
				}
				}
					printf("\nRemove another item?(1/0) : ");
       scanf("%d",&p);

   }while(p==1);
			break;
		}
		default:{
			printf("\nEnter a valid choice");
			break;
		}
		
	}
	printf("\nDo you want to change anything further?(1/0)");
	scanf("%d",&ans);
}while(ans==1);
}




