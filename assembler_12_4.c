#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

void display(char *);
char* compare(char *);	//Prototype
char* toBinary(char *);
void hexDisp(int a);
int countHex = 0;
int symCount = 0;
char bin[MAX];
char final[MAX];		//to store the final output before printing
char ret[MAX];
char tempRet[] = {'\0'};		//To re-initialize ret[] to an empty array.

typedef struct symbol
{
	char sym[MAX];
	char value[MAX];
	char address[MAX];	
} symbol;

symbol symArr[MAX];
void firstPass();
char NEG[] = {'0','0','0','0','0','0','\0'};		//spacing of the output 4 bits at a time => insane idea xD Put ' ' after every fourth character
char AND[] = {'0','0','0','0','0','1','\0'};
char XOR[] = {'0','0','0','0','1','0','\0'};
char OR[] = {'0','0','0','0','1','1','\0'};
char LSR[] = {'0','0','0','1','0','0','\0'};
char LSL[] = {'0','0','0','1','0','1','\0'};
char HLT[] = {'0','0','1','0','1','0','0','0','0','0','0','0','0','0','0','0','\0'};
char MOV[] = {'0','0','1','1','0','1','\0'};
char JMP[] = {'0','0','1','1','1','1','0','0','0','0','0','0','0','0','0','0','\0'};
char ADD[] = {'0','1','0','0','0','0','\0'};
char SUB[] = {'0','1','0','0','0','1','\0'};
char zero[] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','\0'};

char R1[]={'0','0','1','0','0','\0'};
char R2[]={'0','1','0','0','0','\0'};
char R3[]={'0','1','1','0','0','\0'};
char R4[]={'1','0','0','0','0','\0'};
char R5[]={'1','0','1','0','0','\0'};
char R6[]={'1','1','0','0','0','\0'};
char R7[]={'1','1','1','0','0','\0'};


char starR1[]={'0','0','1','0','1','\0'};
char starR2[]={'0','1','0','0','1','\0'};
char starR3[]={'0','1','1','0','1','\0'};
char starR4[]={'1','0','0','0','1','\0'};
char starR5[]={'1','0','1','0','1','\0'};
char starR6[]={'1','1','0','0','1','\0'};
char starR7[]={'1','1','1','0','1','\0'};

char* compare(char *a)
{
	char hex[MAX];		//hex contains the last word without "#".
	hex[0] = '\0';
	
	char comp2[]={'\0'};
	char hexFin[MAX];
	hexFin[0]='\0';
	int i = 0, c = 0, c1 = 0, z = 0;	

	if(strcmp((a),"NEG")==0)		// Can we use switch condition??
		return NEG;
	else if(strcmp((a),"AND")==0)
		return AND;
	else if(strcmp((a),"XOR")==0)
		return XOR;
	else if(strcmp((a),"OR")==0)
		return OR;
	else if(strcmp((a),"LSR")==0)
		return LSR;
	else if(strcmp((a),"LSL")==0)
		return LSL;
	else if(strcmp((a),"HLT")==0)
		return HLT;
	else if(strcmp((a),"MOV")==0)
		return MOV;
	else if(strcmp((a),"JMP")==0)
		return JMP;
	else if(strcmp((a),"ADD")==0)
		return ADD;
	else if(strcmp((a),"SUB")==0)
		return SUB;

	else if(strcmp((a),"R1")==0)
		return R1;
	else if(strcmp((a),"R2")==0)
		return R2;
	else if(strcmp((a),"R3")==0)
		return R3;
	else if(strcmp((a),"R4")==0)
		return R4;
	else if(strcmp((a),"R5")==0)
		return R5;
	else if(strcmp((a),"R6")==0)
		return R6;
	else if(strcmp((a),"R7")==0)
		return R7;
	else if(strcmp((a),"*R1")==0)
		return starR1;
	else if(strcmp((a),"*R2")==0)
		return starR2;
	else if(strcmp((a),"*R3")==0)
		return starR3;
	else if(strcmp((a),"*R4")==0)
		return starR4;
	else if(strcmp((a),"*R5")==0)
		return starR5;
	else if(strcmp((a),"*R6")==0)
		return starR6;
	else if(strcmp((a),"*R7")==0)
		return starR7;
	
	else if(a[0]=='#')
	{		

		for(i = 1; i<5; i++)
		{
			hex[c] = a[i];
			c++;
		}

        	strcat(ret,"00010");
        	strcat(ret,toBinary(hex));
		return ret;
	}
	else if(a[0]=='&')
	{
		
			char comp1[]={'\0'};
			comp1[0]=a[1];
			int searchStruct;
			for(searchStruct=0;searchStruct<symCount;searchStruct++)
			{	
						
				if(strcmp(symArr[searchStruct].sym, comp1)==0)
				{
					strcpy(a,symArr[searchStruct].address);
					strcat(ret,"00010");
					strcat(ret,toBinary(a));
					return ret;
				}
					
			}
		}
		
	
	else 
	{
		comp2[1]=a[0];
		int searchStruct;
		for(searchStruct=0;searchStruct<symCount;searchStruct++)
		{
			if(strcmp(symArr[searchStruct].sym, comp2)==0)
				{	
					strcpy(a,symArr[searchStruct].value);
					//printf("A's Value\n");
					strcat(ret,"00010");
					strcat(ret,toBinary(a));
					return ret;
				}
			
			else if (strcmp(symArr[searchStruct].sym, a)==0)
			{
				strcpy(a,symArr[searchStruct].address);
				//strcat(ret,"00010");
				strcat(ret,toBinary(a));
				return ret;
			}
		}
	}
	
}

char * toBinary(char *b)
{
    char c[MAX];
    c[0] = '\0';
    char one[]={'0','0','0','\0'};
    char two[]={'0','0','\0'};
    char three[]={'0','\0'};
    bin[0] = '\0';
    

    if(strlen(b)==1)
    {
      strcat(c,one);
      strcat(c,b);
    }
    
    else if(strlen(b)==2)
    {
      strcat(c,two);
      strcat(c,b);      
    }
    
    else if(strlen(b)==3)
    {
      strcat(c,three);
      strcat(c,b);
    }
    
    else 
      strcat(c,b);
    
    long int i=0;
    while(c[i]!='\0')
    {
         switch(c[i])
         {
             case '0': strcat(bin,"0000"); break;
             case '1': strcat(bin,"0001"); break;
             case '2': strcat(bin,"0010"); break;
             case '3': strcat(bin,"0011"); break;
             case '4': strcat(bin,"0100"); break;
             case '5': strcat(bin,"0101"); break;
             case '6': strcat(bin,"0110"); break;
             case '7': strcat(bin,"0111"); break;
             case '8': strcat(bin,"1000"); break;
             case '9': strcat(bin,"1001"); break;
             case 'A': strcat(bin,"1010"); break;
             case 'B': strcat(bin,"1011"); break;
             case 'C': strcat(bin,"1100"); break;
             case 'D': strcat(bin,"1101"); break;
             case 'E': strcat(bin,"1110"); break;
             case 'F': strcat(bin,"1111"); break;
             default:  printf("\nInvalid hexadecimal register %c ",c[i]);
         }
         i++;
    }   
	return bin;
}

void hexDisp(int decimalNumber)
{
    int i=1, j, temp, quotient;
    char hexadecimalNumber[100];
    quotient = decimalNumber;	
    hexadecimalNumber[0]='\0';
    while(quotient != 0)
    {
         temp = quotient % 16;

      	//To convert integer into character
      	if( temp < 10)
           temp =temp + 48;
      	else
           temp = temp + 55;

      	hexadecimalNumber[i++]= temp;
      	quotient = quotient / 16;
     }
     
     if(decimalNumber == 0)
     	printf("%d",0);
     
     else
	for(j = i -1 ;j> 0;j--)
	
     	   printf("%c",hexadecimalNumber[j]);
     	         
}


int main()
{

	char fname[128];
	printf("Enter the .txt file name\n");  
	FILE *fp1;
	char *line1 = NULL;
	size_t len1 = 0;
	ssize_t read1;
	int searchStruct=0;
	scanf("%123s",fname);
	strcat(fname,".txt");
	fp1 = fopen(fname,"r");
	if(fp1 == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	int i1=0, j1=0, c1=0, m1=0, space1,flp1=0;				//counter; to store the location of space (i value)
	char tok1 [MAX][MAX];
	char hexAddress[MAX];
	
	while((read1 = getline(&line1, &len1, fp1)) != -1)
	{
		
			
		c1 = 0;		// For every new line, the count of the words in that line should be 0.
						
		space1 = 0; 
		for(i1=0; i1<read1-1; i1++)		//read => array length with '\0'
		{
			int c11 = 0;	//Number of letters in each word. Starts from 0 with every word.
			
			if(line1[i1]==',' && line1[i1+1]==' ')
				space1++;
			

			if(line1[i1] == ' ' || line1[i1] == ',' || i1 == read1-2)
			{
				if(line1[i1] == ' ' && line1[i1-1] == ',')
				{
					space1+=2;
					continue;
				}
				
				if(i1 == read1-2)
				{
					for(j1=space1; j1<=i1; j1++)
					{
						tok1[c1][c11] = line1[j1];
						c11++;
					}			
					
					tok1[c1][c11]='\0';						
					
					break;
				}					
				
				for(j1=space1; j1<i1; j1++)
				{
					tok1[c1][c11] = line1[j1];
					c11++;
				}

				tok1[c1][c11]='\0';
				c1++;		//next word
				space1 = i1;
			}
			
			//printf("%s \n", tok1[c1]); 
		}		
		int space11;	
		for(space11 = 0;space11 <= 5;space11++)
		{
			if(tok1[space11][0]==' ')
			{
				tok1[space11][0]=tok1[space11][1];
				tok1[space11][1]=tok1[space11][2];
				tok1[space11][2]=tok1[space11][3];
				tok1[space11][3]=tok1[space11][4];
				tok1[space11][4]=tok1[space11][5];
				tok1[space11][5]='\0';
			}
		}
		
		
		
		for(searchStruct=0;searchStruct<symCount;searchStruct++)
		{

			if(strcmp(symArr[searchStruct].sym, tok1[0])==0)
			{	flp1+=2;
				printf("Entered Great ,Increased flp1");
			}
			
		}
 
		
		 int i=1, j, temp1, quotient;
   		 char hexadecimalNumber1[100];
   		 quotient = flp1;	
  		  hexadecimalNumber1[0]='\0';
  		  
  		  while(quotient != 0)
    		{
         		temp1 = quotient % 16;

      			//To convert integer into character
      			if( temp1 < 10)
           		temp1 =temp1 + 48;
      			else
           		temp1 = temp1 + 55;

      			hexadecimalNumber1[i++]= temp1;
      			quotient = quotient / 16;
    		 }
    		 
		char reverse[]={'\0'};
     		int n=0;
     		if(flp1 == 0)
     		reverse[0]='0';
     		
     		else
			for(j = i-1 ;j>0;j--,n++)
				reverse[n]=hexadecimalNumber1[j];

		int revCount = 0;	
		while(revCount<n)
		{
			if(reverse[revCount]==reverse[revCount+1])
			{
				reverse[revCount+1]='\0';
				break;
			}
			revCount++;
		}
	
     	   	int colon1 = 0;
		while(tok1[0][colon1]!='\0')
		{
			if(tok1[0][colon1]==':')
			{
				tok1[0][colon1]='\0';
				break;
			}
			colon1 ++;
		}
			
		
	
     	   	
		if((strcmp(tok1[0],"AND")!=0) || (strcmp(tok1[0],"XOR")!=0)||(strcmp(tok1[0],"OR")!=0)||(strcmp(tok1[0],"LSR")!=0)||(strcmp(tok1[0],"LSL")!=0)||(strcmp(tok1[0],"HLT")!=0)||(strcmp(tok1[0],"MOV")!=0)||(strcmp(tok1[0],"ADD")!=0)||(strcmp(tok1[0],"SUB")!=0)||(strcmp(tok1[0],"NEG")!=0))
		{
						
			if(strcmp(tok1[1], "DC")==0)
			{	strcpy(symArr[symCount].sym, tok1[0]);
				strcpy(symArr[symCount].value, tok1[2]); 
				strcpy(symArr[symCount].address,reverse );
			
				symCount++;
			}
			if(strcmp(tok1[1], "DS")==0)
			{	strcpy(symArr[symCount].sym, tok1[0]);
				strcpy(symArr[symCount].value ,tok1[2]);
				strcpy(symArr[symCount].address, reverse);
				symCount++;
			}
			if(strcmp(tok1[0], "JMP")==0)
			{
				strcpy(symArr[symCount].sym, tok1[1]);
				symCount++;
			}
			
			
		}
	
		for(searchStruct=0;searchStruct<symCount;searchStruct++)
		{

			if(strcmp(symArr[searchStruct].sym, tok1[0])==0)
			{	strcpy(symArr[searchStruct].address,reverse);
				
			}
			
		}
		
			
		if(tok1[2][0]=='#')
		flp1+=2;
		if(strcmp(tok1[0],"JMP")==0)
		flp1+=2;
		if(tok1[2][0]=='&')
		flp1+=2;
		else if(strcmp(tok1[1],"DS")==0)
		{
		
			int dsflp =0,dsplace =0,sum=0,app=0,conv,flp11=0;
			while(tok1[2][flp11]!='\0')
			flp11++;
			
			dsplace=flp11-1;
			while(dsflp<flp11)
			{	int power,sum1,k=1;
				for(power=0;power<=dsflp;power++)
				{
					sum1 = 10*k;
					k*=10;
					sum1/=10;
				}
				conv =(((int)tok1[2][dsplace])-48)*sum1;
				sum+=conv;
				dsflp++;
				dsplace--;
				
			}
			if(sum>1)
				flp1=flp1+2*sum;
				
		}
		
		
		
		flp1+=2;
		
	}
	int display1;
	printf("\tSymbol Table \n");
	printf("Symbol \tAddress\tValue \n");

	for(display1=0;display1<symCount;display1++)
	{
		printf("%s \t", symArr[display1].sym);
		printf("%s \t", symArr[display1].address);
		printf("%s \n", symArr[display1].value);
	}
	
	 
	FILE *fp;
	char *line = NULL;
	char *med;
	size_t len = 0;
	ssize_t read;
	fp = fopen("assemblerCode_6_4.txt","r");	
	searchStruct =0;

	if(fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	/*
	
	if(strcmptok[0],"
	
	*/
	
	int i2=0, j2=0, c2=0, m=0, space2=0;				//counter; to store the location of space (i value)
	char tok [MAX][MAX];
	while((read = getline(&line, &len, fp)) != -1)
	{	
		strcpy(final,tempRet);
		c2 = 0;		// For every new line, the count of the words in that line should be 0.

		space2 = 0; 
		for(i2=0; i2<read-1; i2++)		//read => array length with '\0'
		{	
			int c12 = 0;	//Number of letters in each word. Starts from 0 with every word.
			
			if(line[i2]==',' && line[i2+1]==' ')
				space2++;
			

			if(line[i2] == ' ' || line[i2] == ',' || i2 == read-2)
			{
				if(line[i2] == ' ' && line[i2-1] == ',')
				{
					space2+=2;
					continue;
				}
				
				if(i2 == read-2)
				{
					for(j2=space2; j2<=i2; j2++)
					{
						tok[c2][c12] = line[j2];
						c12++;
					}			
					
					tok[c2][c12]='\0';						
					
					break;
				}					
				
				for(j2=space2; j2<i2; j2++)
				{
					tok[c2][c12] = line[j2];
					c12++;
				}

				tok[c2][c12]='\0';
				c2++;		//next word
				space2 = i2;
			}
		}
		
		int e;	
		for(e = 0;e <= 5;e++)
		{
			if(tok[e][0]==' ')
			{
				tok[e][0]=tok[e][1];
				tok[e][1]=tok[e][2];
				tok[e][2]=tok[e][3];
				tok[e][3]=tok[e][4];
				tok[e][4]=tok[e][5];
				tok[e][5]='\0';
			}
		}	
		
		int colon = 0;
		while(tok[0][colon]!='\0')
		{
			if(tok[0][colon]==':')
			{
				tok[0][colon]='\0';
				break;
			}
			colon ++;
		}
			
		
		if(strcmp(tok[1],"DS")==0)
		{
			int dsflp =0,dsplace =0,sum=0,app=0,conv,flp1=0;
			while(tok[2][flp1]!='\0')
			flp1++;
			dsplace=flp1-1;
			while(dsflp<flp1)
			{
				int power,sum1,k=1;
				for(power=0;power<=dsflp;power++)
				{
					sum1 = 10*k;
					k*=10;
					sum1/=10;
				}
				conv =(((int)tok[2][dsplace])-48)*sum1;
				sum+=conv;
				dsflp++;
				dsplace--;
			}
			//printf("%d\n",sum);
			int zero_ds;
			for(zero_ds=0;zero_ds<sum;zero_ds++)
				strcat(final,zero);
				
			display(final);
			continue;
			
		}
		
		if(strcmp(tok[1],"DC")==0)
		{
			strcat(final,toBinary(tok[2]));
			display(final);
			continue;
			
		}	
		
			for(m=0; m<=c2; m++)	//Loop => To display the machine code of each line => passing word by word of the line to display fn
			{	//	printf("%s\n",tok[m]);
				med =  compare(tok[m]);
				strcat(final,med);		//CHECK to pass full line consisting of separate words.				
			}
		
		display(final);		
					
		printf("\n");
		
		strcpy(ret,tempRet);
		strcpy(final,tempRet);
		strcpy(med,tempRet);
		
	}
	
	
	free (line1);
	fclose(fp1);
	free (line);
	fclose(fp);
	exit(EXIT_SUCCESS);

	return 0;
}


void display(char *x)
{
	int i, count = 0;
	
	for(i = 0; x[i]!='\0'; i++)
	{
		count++;
		
		printf("%c",x[i]);
		
		if (count %16 == 0)
		{
			printf("\t\t (");
			hexDisp(countHex);
			countHex+=2;
			printf(") \n");
		}
					
		else if(count%4 == 0)
			printf(" ");
	}	
	printf("\n");	
}
