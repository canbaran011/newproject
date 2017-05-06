//EXERCISE 1:
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char *username;
	char *password;
	char *message;
}FORUM;

int main()
{
	FORUM *user;
	int i, nchar;

	user = (FORUM *)calloc(3, sizeof(FORUM));
	for (i = 0; i < 3; i++)
	{
		printf("How many letter does your name have?\n");
		scanf_s("%d", &nchar);
		user[i].username = (char *)calloc(nchar + 1, sizeof(char));
		if (user[i].username == NULL)
			exit(-1);
		scanf_s(" %s", user[i].username, nchar+1);
		user[i].password = (char *)calloc(12, sizeof(char));
		if (user[i].password == NULL)
			exit(-1);
		printf("Enter a password that includes only letters and @ + -");
		scanf_s(" %11[a-zA-Z@+-]", user[i].password, 12);
		while (getchar() != '\n');
		printf("How many character does your message have\n");
		scanf_s(" %d", &nchar);
		user[i].message = (char *)malloc((nchar + 1) * sizeof(char));
		if (user[i].message == NULL)
			exit(-1);
		while (getchar() != '\n');
		gets_s(user[i].message, nchar + 1);
	}

	for (i = 0; i < 3; i++)
	{
		printf("%s %s %s\n", user[i].username, user[i].password, user[i].message);
		free(user[i].username);
		free(user[i].password);
		free(user[i].message);
	}
	free(user);


}
*/
//EXERCISE 2:

#include <stdio.h>
#include <stdlib.h>

typedef struct {

	char id[12];
	char *name;
	char *surname;
	int *grade;
	int ngrade;

}STUDENT;

void recording(STUDENT *emp)
{
	int nchar;
	
	emp->ngrade = 0;
	printf("How many letters does your name have\n");
	scanf_s("%d", &nchar);
	emp->name = (char *)calloc(nchar + 1, sizeof(char));
	if (emp->name == NULL)
		exit(-1);
	scanf_s(" %11s", emp->id, 12);
	scanf_s(" %s", emp->name, nchar + 1);
	printf("How many letters does your surname have\n");
	scanf_s("%d", &nchar);
	emp->surname = (char *)calloc(nchar + 1, sizeof(char));
	if (emp->surname == NULL)
		exit(-1);
	scanf_s(" %s", emp->surname, nchar + 1);
	emp->grade = (int *)calloc(1, sizeof(int));
	if (emp->grade == NULL)
		exit(-1);
	
	do{
		printf("To stop entering grade enter CTRL-Z\n");
		emp->ngrade++;
		emp->grade = (int*)realloc(emp->grade, emp->ngrade*sizeof(int));
		if (emp->grade == NULL)
			exit(-1);
		
	}while (scanf_s("%d", &emp->grade[emp->ngrade-1]) != -1);
}
void listing(STUDENT *slist, STUDENT *llist)
{
	STUDENT * emp;
	int i;
	emp = slist;
	printf("ID\t NAME\t SURNAME\t GRADES\n");
	while (emp != llist + 1)
	{
		printf("%s\t %s\t %s\t", emp->id, emp->name, emp->surname);
		for (i = 0; i < emp->ngrade - 1; i++)
			printf(" %d\t", emp->grade[i]);
		printf("\n");
		emp = emp + 1;
	}
}
int main()
{
	STUDENT *rcrd, *slist, *llist;
	int i, t, count = 0;
	rcrd = (STUDENT *)malloc(1 * sizeof(STUDENT));
	if (rcrd == NULL)
		exit(-1);
	slist = rcrd;
	llist = rcrd;
	while (1)
	{
		printf("Enter 1, 2 or 3\n");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1: count++; rcrd = slist; rcrd = (STUDENT *)realloc(rcrd, count * sizeof(STUDENT));
										if (rcrd == NULL)
											exit(-1);
										slist = rcrd;
										rcrd = rcrd + count - 1; llist = rcrd; recording(rcrd);   break;
		case 2: listing(slist, llist); break;
		case 3: rcrd = slist;  for (t = 0; t < count; t++) { free(rcrd[t].name); free(rcrd[t].surname); free(rcrd[t].grade); } free(rcrd);  exit(0);
		}
		
	}

}



<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head><title>
	BAP-Özgeçmiş
</title></head>
<body>
    <form name="form1" method="post" action="ImageOfByte.aspx?Resim=8&amp;SSNO=19&amp;USER=17721" id="form1">
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
