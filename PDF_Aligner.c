#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

char *enter_file();
int end();
int get_pg_no();
int split_pdf(char pdfname_fun2[], int pagecount_fun2);
int merge_pdf(int pagecount_fun3);

char *enter_file()
{
	int x;
	x=1;
	int choice;
	
	char *pdfname = malloc(300 * sizeof(char));
	char pdf_i_str[300];
	
	while(x != 0)
	{
		printf("\nEnter the name of the PDF file: \n");
		scanf("%s",pdfname);
		
		strcpy(pdf_i_str,"pdfinfo ");
		strcat(pdf_i_str,pdfname);
		strcat(pdf_i_str," > file.txt");
		x = system(pdf_i_str);
		
		if(x != 0)
			x = 1;
		if(x == 1)
		{
			printf("\nDo you want to enter filename again or quit? \n\n1. Enter Again \n2. Quit\n");
			scanf("%d",&choice);
			if(choice == 2)
			{
				x = 0;
				printf("\nExiting...\nThank you!\n");
				end();
			}
		}
	}
	
	return pdfname;
}

int end()
{
	exit(0);
	return 0;
}

int get_pg_no()
{
	FILE *fp;
	
	int j = 0;
	int c;
	int pagecount_fun1;
	char pageno[5]="0";
		
	fp = fopen("file.txt","r");
	system("grep Pages: file.txt > pageno.txt");
	fclose(fp);
	
	fp = fopen("pageno.txt","r");
	while((c = fgetc(fp)) != EOF)
	{
		if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c =='7' || c == '8' || c == '9' || c == '0')
		{
			pageno[j] = c;
			j++;
		}
		if(c == '\0' || c == '\n')
			break;
	}
	fclose(fp);
	pagecount_fun1 = atoi(pageno);
	
	return pagecount_fun1;
}

int split_pdf(char pdfname_fun2[300], int pagecount_fun2)
{
	char file[300];
	char renamer[30];
	char y[]="0001";
	char name1[30];
	char name2[30];
	char name3[30];
	char name4[30];
	char extpg[5];
	char splitpg[30];
	
	int counter = 1;	
	int extrapgcounter;
	int modpages;
	int extrapages;
	
	strcpy(file,"pdftk ");
	strcat(file,pdfname_fun2);	
	strcat(file," burst output %04d.pdf");
	system(file);
	sleep(5);
	
	extrapgcounter = pagecount_fun2;
	
	modpages = extrapgcounter % 4;
	if(modpages == 3)
		extrapages = 1;
	else if(modpages == 2)
		extrapages = 2;
	else if(modpages == 1)
		extrapages = 3;
	else
		extrapages = 0;	
	
	switch(extrapages)
	{
		case 0:
			break;
		case 1:
		{
			extrapgcounter++;
			sprintf(extpg,"%d", extrapgcounter);			
			if(extrapgcounter < 10)	
				strcpy(splitpg,"ps2pdf 000");
			else if(extrapgcounter < 100)	
				strcpy(splitpg,"ps2pdf 00");
			else
				strcpy(splitpg,"ps2pdf 0");
			strcat(splitpg,extpg);
			system(splitpg);
			pagecount_fun2 = pagecount_fun2+1;
			break;
		}
		case 2:
		{
			extrapgcounter++;
			sprintf(extpg,"%d", extrapgcounter);
			if(extrapgcounter < 10)	
				strcpy(splitpg,"ps2pdf 000");
			else if(extrapgcounter < 100)	
				strcpy(splitpg,"ps2pdf 00");
			else
				strcpy(splitpg,"ps2pdf 0");
			strcat(splitpg,extpg);
			system(splitpg);
			
			extrapgcounter++;
			sprintf(extpg,"%d", extrapgcounter);
			if(extrapgcounter < 10)	
				strcpy(splitpg,"ps2pdf 000");
			else if(extrapgcounter < 100)	
				strcpy(splitpg,"ps2pdf 00");
			else
				strcpy(splitpg,"ps2pdf 0");
			strcat(splitpg,extpg);
			system(splitpg);
			pagecount_fun2 = pagecount_fun2+2;
			break;
		}
		case 3:
		{
			extrapgcounter++;
			sprintf(extpg,"%d", extrapgcounter);			
			if(extrapgcounter < 10)	
				strcpy(splitpg,"ps2pdf 000");
			else if(extrapgcounter < 100)	
				strcpy(splitpg,"ps2pdf 00");
			else
				strcpy(splitpg,"ps2pdf 0");
			strcat(splitpg,extpg);
			system(splitpg);
			
			extrapgcounter++;
			sprintf(extpg,"%d", extrapgcounter);						
			if(extrapgcounter < 10)	
				strcpy(splitpg,"ps2pdf 000");
			else if(extrapgcounter < 100)	
				strcpy(splitpg,"ps2pdf 00");
			else
				strcpy(splitpg,"ps2pdf 0");
			strcat(splitpg,extpg);
			system(splitpg);
			
			extrapgcounter++;
			sprintf(extpg,"%d", extrapgcounter);
			if(extrapgcounter < 10)	
				strcpy(splitpg,"ps2pdf 000");
			else if(extrapgcounter < 100)	
				strcpy(splitpg,"ps2pdf 00");
			else
				strcpy(splitpg,"ps2pdf 0");
			strcat(splitpg,extpg);
			system(splitpg);
			pagecount_fun2 = pagecount_fun2+3;
			break;		
		}
		default:
			break;
	}
	sleep(5);
	while(counter != pagecount_fun2+1)	
	{
		if(counter % 4 == 1)
		{
			if(y[3]== ':')
			{
				y[3]='0';
				y[2]++;
			}
			if(y[3] == '0' && y[2] == ':')
			{
				y[2]='0';
				y[1]++;
			}
			renamer[0]=y[1];
			renamer[1]=y[2];
			renamer[2]=y[3];
			
			strcpy(name1,"mv ");
			strcat(name1,y);

			strcat(name1,".pdf ");
			strcat(name1,renamer);
			strcat(name1,".pdf");
//			printf("%s\n",name1);
			system(name1);
						
			y[3]++;	
		}

		if(counter % 4 == 2)
		{
			if(y[3]== ':')
			{
				y[3]='0';
				y[2]++;
			}
			if(y[3] == '0' && y[2] == ':')
			{
				y[2]='0';
				y[1]++;
			}
			renamer[0]=y[1];
			renamer[1]=y[2];
			renamer[2]=y[3];
			renamer[2]=renamer[2]+2;
	
			if(renamer[2]== ':')
			{
				renamer[2]='0';
				renamer[1]++;
			}
			if(renamer[2] == '0' && renamer[1] == ':')
			{
				renamer[1]='0';
				renamer[0]++;
			}
			
			strcpy(name2,"mv ");
			strcat(name2,y);		
			strcat(name2,".pdf ");
			strcat(name2,renamer);
			strcat(name2,".pdf ");
//			printf("%s\n",name2);
			system(name2);
			y[3]++;
			
		}
	
		if(counter % 4 == 3)
		{
			if(y[3]== ':')
			{
				y[3]='0';
				y[2]++;
			}
			if(y[3] == '0' && y[2] == ':')
			{
				y[2]='0';
				y[1]++;
			}
			renamer[0]=y[1];
			renamer[1]=y[2];
			renamer[2]=y[3];
			renamer[2]--;
			if(renamer[2]== '/')
			{
				renamer[2]='9';
				renamer[1]--;
			}
			if(renamer[2] == '9' && renamer[1] == '/')
			{
				renamer[1]='0';
				renamer[0]--;
			}
		
			strcpy(name3,"mv ");
			strcat(name3,y);
			strcat(name3,".pdf ");
			strcat(name3,renamer);
			strcat(name3,".pdf");
//			printf("%s\n",name3);
			system(name3);		
			y[3]++;
		}
	
		if(counter % 4 == 0)
		{
			if(y[3]== ':')
			{
				y[3]='0';
				y[2]++;
			}
			if(y[3] == '0' && y[2] == ':')
			{
				y[2]='0';
				y[1]++;
			}
			renamer[0]=y[1];
			renamer[1]=y[2];
			renamer[2]=y[3];
			renamer[2]--;
			if(renamer[2]== '/')
			{
				renamer[2]='9';
				renamer[1]--;
			}
			if(renamer[2] == '9' && renamer[1] == '/')
			{
				renamer[1]='0';
				renamer[0]--;
			}
//100th iteration case here.
			if(renamer[2] == '9' && renamer[1] == '0')
				renamer[1] = '9';
			
			strcpy(name4,"mv ");
			strcat(name4,y);
			strcat(name4,".pdf ");
			strcat(name4,renamer);
			strcat(name4,".pdf");
//			printf("%s\n",name4);
			system(name4);		
			y[3]++;
		}	

		counter++;
	}
		
	return pagecount_fun2;
}

int merge_pdf(int pagecount_fun3)
{
	char merge[20000] = "pdftk ";
	char mergeloop[] = "001";
	
	char remove[20000] = "rm ";
	char remover[30] = "001";	

	sleep(5);
	for(int i = 0; i<pagecount_fun3;i++)
	{
		strcat(merge,mergeloop);
		strcat(merge,".pdf ");
		
		mergeloop[2]++;
		
		if(mergeloop[2]== ':')
		{
			mergeloop[2]='0';
			mergeloop[1]++;
		}
		if(mergeloop[2] == '0' && mergeloop[1] == ':')
		{
			mergeloop[1]='0';
			mergeloop[0]++;
		}
	}
	strcat(merge,"cat output output.pdf");
	system(merge);

	sleep(5);
	for(int i = 0; i<pagecount_fun3;i++)
	{
		strcat(remove,remover);
		strcat(remove,".pdf ");
		
		remover[2]++;
		
		if(remover[2]== ':')
		{
			remover[2]='0';
			remover[1]++;
		}
		if(remover[2] == '0' && remover[1] == ':')
		{
			remover[1]='0';
			remover[0]++;
		}
	}
	system(remove);
	system("rm doc_data.txt file.txt pageno.txt");
	printf("Processing complete!\nOutput file is: output.pdf\n");
	return 0;
}

int main()
{

	char *pdfname;
	int pgcnt_split;
	int pgcnt_merge;

	pdfname = enter_file();
	pgcnt_split = get_pg_no();
	pgcnt_merge = split_pdf(pdfname,pgcnt_split);
	merge_pdf(pgcnt_merge);

	return 0;
}















