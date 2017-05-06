//EXERCISE 1: TYPEDEF
/*
#include <stdio.h>
#include <stdlib.h>

typedef int INTEGER;
typedef char * STRING;

int main()
{
	INTEGER x,i;
	STRING list[10];

	for (i = 0; i < 10; i++) {

		printf("How many character will you input\n");
		scanf_s("%d", &x);
		list[i] = (STRING)calloc((x + 1), sizeof(char));
		if (list[i] == NULL)
			exit(-1);
		scanf_s(" %s", list[i], x + 1);
	}
	i = 0;
	while (i < 10)
	{
		printf("%s\n", list[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		free(list[i]);
		i++;
	}
	
}
*/

//EXERCISE 2: STRUCTS definition 1)
/*
#include <stdio.h>

struct STUDENT
{
	char id[10];
	char name[26];
	int	 gradePts;
};


int main()
{
	struct STUDENT cen116 = { "123456789","Jack",90 }; //initialization

	printf("ID: %s	NAME:%s	GRADE:%d\n", cen116.id, cen116.name, cen116.gradePts);

	printf("Enter Name:\n");
	scanf_s("%25s", cen116.name,26);
	printf("Enter id:\n");
	scanf_s("%9s", cen116.id,10);
	printf("Grade:\n");
	scanf_s("%d", &cen116.gradePts);
	printf("ID: %s	NAME:%s	GRADE:%d\n", cen116.id, cen116.name, cen116.gradePts);

	return 0;
}
*/

//EXAMPLE 3: STRUCT Definition 2) with typedef
/*
#include <stdio.h>

typedef struct
{
	char id[10];
	char name[26];
	int	 gradePts;
}STUDENT;


int main(void)
{
	STUDENT cen116={"123456789","Jack",90}; //initialization

	printf("ID: %s	NAME:%s	GRADE:%d\n",cen116.id,cen116.name,cen116.gradePts);
	
	cen116.gradePts = 80;
	printf("ID: %s	NAME:%s	GRADE:%d\n", cen116.id, cen116.name, cen116.gradePts);
	printf("Enter Name:\n");
	scanf_s("%25s",cen116.name,26);

	printf("Enter id:\n");
	scanf_s("%9s",cen116.id,10);

	printf("Grade:\n");
	scanf_s("%d",&cen116.gradePts);

	printf("ID: %s	NAME:%s	GRADE:%d\n",cen116.id,cen116.name,cen116.gradePts);

return 0;
}
*/

//EXERCISE 4: Record List
/*
#include <stdio.h>

#define NSTUDENTS 3

typedef struct
{
	char id[10];
	char name[26];
	int grd;
}STUDENT;

void printRecord(STUDENT record)
{
	
	printf("%s\t%s\t%d\n", record.name, record.id, record.grd);
}
int main()
{
	STUDENT list[NSTUDENTS];
	int i;

	for (i = 0; i < NSTUDENTS; i++)
	{
		printf("Enter %dth student name\n", (i + 1));
		scanf_s("%25s", list[i].name,26);
		printf("Enter %dth student id\n", (i + 1));
		scanf_s("%9s", list[i].id, 10);
		printf("Enter %dth student grd\n", (i + 1));
		scanf_s("%d", &list[i].grd);
	}
	printf("Name\tID\tGrade\n");
	for (i = 0; i < NSTUDENTS; i++)
		printRecord(list[i]);
	return 0;
}
*/

//EXERCISE 5: pointers to structures
/*
#include <stdio.h>
typedef struct
{
	char id[10];
	char name[26];
	char surname[50];
	int	 gradePts;
} STUDENT;


int main(void)
{
	STUDENT cen116, *bil116; //initialization

	bil116 = &cen116;

	printf("Enter Name:\n");
	scanf_s("%25s", (*bil116).name,26);
	printf("Enter surname:\n");
	scanf_s("%49s", cen116.surname,50);
	printf("Enter id:\n");
	scanf_s("%9s", bil116->id,10);
	printf("Grade:\n");
	scanf_s("%d", &bil116->gradePts);
	printf("Loading information with cen116 variable\n");
	printf("ID: %s	NAME:%s	GRADE:%d\n", cen116.id, cen116.name, cen116.gradePts);
	printf("Loading information with bil116 pointer\n");
	printf("ID: %s	NAME:%s	GRADE:%d\n", (*bil116).id, bil116->name, (*bil116).gradePts);

	return 0;
}
*/
//EXERCISE 6: Dynamic lists
#include <stdio.h>
typedef struct
{
	char id[10];
	char name[26];
	char surname[50];
	int	 gradePts;
} STUDENT;

void recording(STUDENT *record)
{
	printf("Enter Name:\n");
	scanf_s("%25s", record->name, 26);
	printf("Enter surname:\n");
	scanf_s("%49s", record->surname, 50);
	printf("Enter id:\n");
	scanf_s("%9s", record->id, 10);
	printf("Grade:\n");
	scanf_s("%d", &record->gradePts);
}

void listing(STUDENT * record, STUDENT *plast)
{
	while (record != plast)
	{
		printf("ID: %s	NAME:%s	GRADE:%d\n", record->id, record->name, record->gradePts);
		record++;
	}
	printf("ID: %s	NAME:%s	GRADE:%d\n", record->id, record->name, record->gradePts);
}

int main(void)
{
	STUDENT *list, *plist, *last; 
	int i, count = 0;
	list = (STUDENT *)calloc(1, sizeof(STUDENT));
	plist = list;
	last = list;
	
	while (1)
	{
		printf("Enter 1 for RECORD 2 for LIST 3 for EXIT\n");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:	count++; if (count > 1) {
			list = plist; list = (STUDENT *)realloc(list, count * sizeof(STUDENT));
										if (list == NULL) exit(-1); 
											plist = list; list = list + count-1; last = list; } 
										recording(list); break;
		case 2: listing(plist,last); break;
		case 3: list = plist; free(list); exit(0);
		}
	}

	return 0;
}

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head><title>
	BAP-Özgeçmiş
</title></head>
<body>
    <form name="form1" method="post" action="ImageOfByte.aspx?Resim=8&amp;SSNO=15&amp;USER=17721" id="form1">
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
