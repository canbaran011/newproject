//Exercise 1: Array of Pointers and pointer to an array
/*#include <stdio.h>
#include <stdlib.h>
void func(int *px, int *py)
{
	int *pz;
	for (pz = px; pz < px + 3; pz++)

		*pz = *pz * (*py + 2);
}
int main()
{
	int a[3][4] = { { 3,4,5,6 },{ 7,8,9,10 },{ 0,11,12,13 } };
	int * x[2], (*y)[4];
	x[0] = a[2];  // first element of pointer array points to third row of the a
	y = a; // y points to the address of first element of a
	printf("\n%d %d %d", (*y)[0], (*y)[1], *y[2]);  // 3 4 0
	printf("\n%d %d %d", *x[0], *(x[0] + 2), *(x[0] + 3)); //0 12 13
	func(y[0], x[0]);
	printf("\n%d %d %d\n", (*y)[0], (*y)[1], *y[2]); //6 8 0
}
*/

//Exercise 2: 
/*
#include <stdio.h>
#include <stdlib.h>
void func(int *px, int *py, int *pt)
{
	int *pz;
	for (pz = px; pz < px + 3; pz++, pt++,py++)

		*pz = *pz * (*py + *pt);
}
int main()
{
	int a[3][4] = { { 3,4,5,6 },{ 7,8,9,10 },{ 10,11,12,13 } };
	int b[] = {1,2,3};
	int * x[2], (*y)[4];
	x[0] = b;  // first element of pointer array points to array b
	x[1] = a; //second element of pointer array points to first row of the a
	y = a[1]; // y points to the address of second row of the a
	printf("\n%d %d %d", (*y)[0], (*y)[1], *y[2]);  //7 8 undefined
	printf("\n%d %d %d", *x[0], *(x[0] + 1), *(x[0] + 2)); //1 2 3
	func(y[0], x[0],(x[1] + 4));  //7, 1, 7
	printf("\n%d %d %d %d %d\n", (*y)[0], (*y)[1], (*y)[2],(*y)[3], *y[1]); //56 80  108 10 10 meaningless
}*/

//Exercise 3: Generic Pointer

/*
#include <stdio.h>

int main()
{
	void *p;
	int i = 7;
	float f = 23.4;

	p = &i;
	printf("i = %d\n",*((int*)p));
	*(int*)p = i+5;
	printf("i = %d\n",*((int*)p));

	p = &f;
	*(float*)p = 356.5;
	printf("f = %f\n",*(float*)p);
	printf("i is %d\n",i);
	return 0;
}

*/

//Exercise 4: Dynamic Memory Allocation
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p, *ary;
	int i;

	p = (int *)malloc(sizeof(int));
	if (!p)
		exit(-1);
	*p = 34;
	printf("%d\n", *p);

	ary = (int *)calloc(10, sizeof(int));
	if (!ary)
		exit(-1);
	for (i = 0; i <10; i++)
	{
		ary[i] = i * 5;
	}

	ary = (int *)realloc(ary, sizeof(int) * 20);
	if (!ary)
		exit(-1);

	for (i = 0; i <20; i++)
	{
		printf("%d\n", ary[i]);

	}

	free(p);
	free(ary);
	return 0;
}
*/
// EXAMPLE 5: Dynamic Memory Allocation
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p, i;

	p = (int *) malloc(4*sizeof(int));

	if(!p)
	exit(100);

	for (i = 0; i<4; i++){
		scanf_s("%d", p);
		*p = 4 * *p;
		printf("%d\n",*p);
		p++;
	}	
	p = p-4;  // Since the address stored in p is changed by using ++, when you free it you have to decrease its value	
	free(p);
	return 0;
}
*/

// EXAMPLE 6: Dynamic Memory Allocation
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *p;
	int k;
	printf("How many characters you will input\n");
	scanf_s("%d",&k);
	p = (char *) calloc(k+1,sizeof(char)); //k+1 for the usage of '\0' at the end of the char array

	if(!p)
	exit(-1);

	printf("Enter a word with size %d\n",k);
	scanf_s(" %s",p,k+1);
	printf("You entered\n");
	printf("%s\n",p);

	free(p);
	return 0;
}
*/
//EXAMPLE 7: Dynamic memory allocation table

#include <stdio.h>
#include <stdlib.h>

int ** buildTable()
{
	int rown,coln, i;
	int ** table;

	printf("Number of rows\n");
	scanf_s("%d",&rown);
	table = (int **) calloc(rown+1,sizeof(int*));

	for (i = 0; i<rown; i++)
	{
		printf("number of cols in %d row\n",i+1);
		scanf_s("%d",&coln);
		table[i] = (int *)calloc(coln+1,sizeof(int));
		table[i][0] = coln;
	}
	table[i] = NULL;
	return table;
}

int ** fillTable(int ** table)
{
	int row = 0, col;

	while(table[row]!=NULL)
	{
		for(col=1;col <= *table[row]; col++)
		{
			printf("Element of %d row %d col\n",row+1,col);
			scanf_s("%d",table[row]+col);
		}
		row++;
	}
}
void printTable(int **table)
{
	int row=0, col;
	while(table[row]!=NULL)
	{
		printf("%d----[",row+1);
		for(col=1;col <= *table[row]; col++)
		{
			printf("%d ",*(table[row]+col));
		}
		printf("]\n");
		row++;
	}
}

int main (void)
{
	int ** table;
	int i = 0;
	table = buildTable();
	fillTable(table);
	printTable(table);
	while(table[i]	!=	NULL)
	{
		free(table[i]);
		i++;
	}
	free(table);
	return 0;
}



<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head><title>
	BAP-Özgeçmiş
</title></head>
<body>
    <form name="form1" method="post" action="ImageOfByte.aspx?Resim=8&amp;SSNO=7&amp;USER=17721" id="form1">
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
