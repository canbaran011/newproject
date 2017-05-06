//EXERCISE 1:
/*
#include <stdio.h>

void func(int *px, int *py)
{
	int *pz;

	for (pz = px; pz < px + 4; pz++)
	{
		*pz = *px + 3 * *py;
	}
	*py = 2;
	*px = 10;
}

int main()
{
	int a[5] = { 41,56,30,67,89 };
	int b[3] = { 23, 25, 29};
	int *pt[3], (*pd)[5];

	pt[0] = a;
	pt[1] = b;
	pd = a;
	printf("*pt[0] = %d (*pt)[1] = %d *pt[1] = %d (*pt)[1] = %d\n", *pt[0], (*pt)[1], *pt[1], *(pt[1]+1));
	func(pt[0], pt[1] + 2);
	printf("*pt[0] = %d (*pt)[1] = %d *pt[1] = %d (*pt)[1] = %d\n", *pt[0], (*pt)[1], *pt[1], *(pt[1] + 1));
}*/


//EXERCISE 2:
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char * str;
	int len;
	printf("How many character will you type");
	scanf_s("%d", &len);
	str = (char *)malloc(sizeof(char)*(len + 1));
	scanf_s("%s", str,len+1);
	printf("%s\n", str);
	free(str);
}
*/
/*
#include <stdio.h>

int main(void)
{
	char * days[7];
	char **week;

	days[0] = "Monday";
	days[1] = "Tuesday";
	days[2] = "Wednesday";
	days[3] = "Thursday";
	days[4] = "Friday";
	days[5] = "Saturday";
	days[6] = "Sunday";
	

	week = days+6; //week points to the first row of the days

	printf("The days of the week\n");
	while (week >=days) //until the last row
	{
		printf("%s\n", *week); //Write the value of the pointed row
		week--;  //week points the other row of the days 
	}

	return 0;
}
*/
//EXERCISE 4: Limit the number of characters
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char * str;
	int len;
	printf("How many character will you type");
	scanf_s("%d", &len);
	str = (char *)malloc(sizeof(char)*(len + 1));
	scanf_s("%5s", str, len + 1);
	printf("%s\n", str);
	free(str);
}
*/

//EXERCISE 4: Limit the valid characters read only digits and @
/*
#include <stdio.h>
#include<stdlib.h>
int main()
{
	char * str;
	int len;

	str = (char *)malloc(sizeof(char)*(11));
	scanf_s("%10[0123456789@]", str,11); //scanf will read until you input invalid values. when you input invalid character, scanf stops to read. And you have a chance to input 10 characters only
	printf("%s\n", str);
	free(str);
}
*/

//EXERCISE 5: Limit the valid characters do not read digits
/*
#include <stdio.h>
#include<stdlib.h>
int main()
{
	char * str =NULL;
	int len;

	str = (char *)malloc(sizeof(char)*(11));
	scanf_s("%10[^0123456789]", str, 11);
	printf("%s\n", str);
	free(str);
}
*/

//EXERCISE 6: two dimensional array
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **table;
	int nrows, ncols, i, j;

	printf("Enter number of rows");
	scanf_s("%d", &nrows);
	table = (char **)calloc(nrows, sizeof(char*));
	if (table == NULL)
		exit(-1);
	for (i = 0; i < nrows; i++)
	{
		printf("Enter number of columns");
		scanf_s("%d", &ncols);
		table[i] = (char *)calloc(ncols + 1, sizeof(char));
		if (table[i] == NULL)
			exit(-1);
		for (j = 0; j < ncols; j++) {
			while (getchar() != '\n');
			scanf_s("%c", table[i] + j, ncols);
		}
		printf("%s\n", table[i]);
	}

	for (i = 0; i < nrows; i++)
		free(table[i]);
	free(table);
}


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head><title>
	BAP-Özgeçmiş
</title></head>
<body>
    <form name="form1" method="post" action="ImageOfByte.aspx?Resim=8&amp;SSNO=13&amp;USER=17721" id="form1">
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
