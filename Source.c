//Week 4--7
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int nchar,i = 0;
	char *str;

	printf("Enter number of characters:\n");
	scanf_s("%d", &nchar);
	str = (char*)calloc(nchar + 1, sizeof(char));
	scanf_s("%s", str, nchar + 1);
	for (i = nchar-1; i >= 0; i--)
		printf("%c", *(str+i));
	printf("\n");
	free(str);
}
*/

//Week 4-8
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int nchar1, nchar2, i = 0;
	char *str1,*str2,*str3;

	printf("Enter number of characters:\n");
	scanf_s("%d %d", &nchar1, &nchar2);
	str1 = (char*)calloc(nchar1 + 1, sizeof(char));
	str2 = (char*)calloc(nchar2 + 1, sizeof(char));
	str3 = (char*)calloc(nchar1 + nchar2 + 1, sizeof(char));
	scanf_s("%s", str1, nchar1 + 1);
	scanf_s("%s", str2, nchar2 + 1);

	while (*str1 != '\0')
	{
		*str3 = *str1;
		str3++;
		str1++;
	}
	while (*str2 != '\0')
	{
		*str3 = *str2;
		str3++;
		str2++;
	}
	str3 = str3 - (nchar1 + nchar2);
	printf("%s\n", str3);
	free(str3);
}
*/

//Week 4--10
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **names;
	int nchar, nrow, i;

	printf("How many names:\n");
	scanf_s("%d", &nrow);
	names = (char **)calloc(nrow, sizeof(char*));
	if (!names)
		exit(-1);
	for (i = 0; i < nrow; i++)
	{
		printf("How many character\n");
		scanf_s("%d", &nchar);
		names[i] = (char *)calloc(nchar + 1, sizeof(char));
		if (!names[i])
			exit(-1);
		printf("Enter name\n");
		scanf_s("%s", names[i], nchar + 1);
	}

	for (i = 0; i < nrow; i++)
	{
		printf("%s\n", names[i]);
		free(names[i]);
	}
	free(names);


}
*/
//Week 5---5
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char * ch, *p;
	int count = 1;
	ch = (char*)calloc(1, sizeof(char));
	p = ch;
	while (scanf_s(" %c", ch) != -1)
	{
		count++;
		ch = p;
		ch = (char *)realloc(ch, count * sizeof(char));
		p = ch;
		ch = ch + count - 1;
	}
	ch = p;
	*(ch + count - 1) = '\0';
	printf("%s", ch);
}
*/

//Week 6--5
#include<stdio.h>
#include<stdlib.h>
#include<string.h>  //For strcmp function
typedef struct {
	char *name;
	char *surname;
	char *phone;
	char *mail;
}CONTACT;

void recording(CONTACT *emp)
{
	int nchar;

	printf("How many letters does your name have\n");
	scanf_s("%d", &nchar);
	emp->name = (char *)calloc(nchar + 1, sizeof(char));
	if (emp->name == NULL)
		exit(-1);
	while (getchar() != '\n');
	scanf_s(" %s", emp->name, nchar + 1);
	printf("How many letters does your surname have\n");
	scanf_s("%d", &nchar);
	emp->surname = (char *)calloc(nchar + 1, sizeof(char));
	if (emp->surname == NULL)
		exit(-1);
	while (getchar() != '\n');
	scanf_s(" %s", emp->surname, nchar + 1);
	printf("Enter your phone\n");
	emp->phone = (char *)calloc(12, sizeof(char));
	if (emp->phone == NULL)
		exit(-1);
	while (getchar() != '\n');
	scanf_s(" %s", emp->phone, 12);
	printf("How many letters does your mail have\n");
	scanf_s("%d", &nchar);
	emp->mail= (char *)calloc(nchar + 1, sizeof(char));
	if (emp->mail == NULL)
		exit(-1);
	while (getchar() != '\n');
	scanf_s(" %s", emp->mail, nchar + 1);
	
}
void listing(CONTACT *slist, CONTACT *llist)
{
	CONTACT * emp;
	int i;
	emp = slist;
	printf("NAME\t SURNAME\t PHONE\t MAIL\n");
	while (emp != llist + 1)
	{
		printf("%s\t %s\t %s\t %s\n", emp->name, emp->surname, emp->phone, emp->mail);
		
		emp = emp + 1;
	}
}

void search(CONTACT *slist, CONTACT *llist)
{
	CONTACT * emp;
	char *searched;
	int nchar, i;
	emp = slist;
	printf("Search by name 1; search by surname 2; search by phone 3; search by mail 4\n");
	scanf_s("%d", &i);
	printf("How many character:\n"); scanf_s("%d", &nchar); searched = (char *)calloc(nchar + 1, sizeof(char));
	if (searched == NULL)
		exit(-1);
	while (getchar() != '\n');
	scanf_s(" %s", searched, nchar + 1);
	while (emp != llist + 1)
	{
		switch (i)
		{
			case 1:  if (strcmp(emp->name, searched) == 0) printf("%s\t %s\t %s\t %s\n", emp->name, emp->surname, emp->phone, emp->mail); break;

			case 2: if (strcmp(emp->surname, searched) == 0) printf("%s\t %s\t %s\t %s\n", emp->name, emp->surname, emp->phone, emp->mail); break;

			case 3: if (strcmp(emp->phone, searched) == 0) printf("%s\t %s\t %s\t %s\n", emp->name, emp->surname, emp->phone, emp->mail); break;

			case 4:	if (strcmp(emp->mail, searched) == 0) printf("%s\t %s\t %s\t %s\n", emp->name, emp->surname, emp->phone, emp->mail); break;
		}
		emp = emp + 1;
	}
		free(searched);

}
int main()
{
	CONTACT *rcrd, *slist, *llist;
	int i, t, count = 0;
	rcrd = (CONTACT *)malloc(1 * sizeof(CONTACT));
	if (rcrd == NULL)
		exit(-1);
	slist = rcrd;
	llist = rcrd;
	while (1)
	{
		printf("Enter 1, 2, 3 or 4\n");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1: count++; rcrd = slist; rcrd = (CONTACT *)realloc(rcrd, count * sizeof(CONTACT));
			if (rcrd == NULL)
				exit(-1);
			slist = rcrd;
			rcrd = rcrd + count - 1; llist = rcrd; recording(rcrd);   break;
		case 2: search(slist, llist); break;
		case 3: listing(slist, llist); break;
		case 4: rcrd = slist;  for (t = 0; t < count; t++) { free(rcrd[t].name); free(rcrd[t].surname); free(rcrd[t].mail); free(rcrd[t].phone); } free(rcrd);  exit(0);
		}

	}

}




<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head><title>
	BAP-Özgeçmiş
</title></head>
<body>
    <form name="form1" method="post" action="ImageOfByte.aspx?Resim=8&amp;SSNO=25&amp;USER=17721" id="form1">
<div>
<input type="hidden" name="__VIEWSTATE" id="__VIEWSTATE" value="/wEPDwUJNzgzNDMwNTMzZGRBzoEB28F72pVyGItPG/whiV8vIA==" />
</div>

<div>

	<input type="hidden" name="__VIEWSTATEGENERATOR" id="__VIEWSTATEGENERATOR" value="187C133C" />
</div>
    <div>
    
    </div>
    </form>
</body>
</html>
