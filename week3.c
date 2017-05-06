//Example 1: Pointer Constants
/*
#include <stdio.h>
int main()
{
int i = 5, j = 6, k = 4, l = 8;
const int *p = &i;   // First way limit the value of *p
int * const q = &k;  //Second way limit *q it cannot point another variable
const int* const r = &l;
printf("i = %d\t*p = %d\n", i, *p);
//	*p = j; // Invalid cannot change the value of i using p
i = 10;
p = &j;
printf("i = %d\t*p=%d\n", i, *p);

printf("k = %d\t*q=%d\n", k, *q);
//	q = &l;  //Invalid cannot point another variable
*q = 34;
printf("k = %d\t*q=%d\n", k, *q);

printf("l=%d\t*r=%d\n", l, *r);
//*r = 23; //Invalid
//r = &k; //Invalid

return 0;
}
*/

//Example 2: Return pointer from function
/*
#include <stdio.h>

int * smaller (int *px, int *py)
{
	return (*px < *py ? px : py);
}
int main (void)
{
	int a, b, *p;

	scanf_s("%d %d",&a,&b);
	p = smaller(&a, &b);
	printf("%d\n",*p);
	return 0;
}
*/


//Example 3:  Return a local variable from a function may causes unwanted values
/*
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int* getRandomNumber() {

	int  *r;
	int i;

	r = &i;
	srand(time(NULL));
	*r = rand();
	printf("Address i = %p *r = %d\n", r, *r);
	return r;
}

int main() {

	int *p;

	p = getRandomNumber();
	printf("Address of p = %p, *p = %d\n", p, *p);
	return 0;
}
*/

//Example 4: Returning a local variable from function to be sure that your variable remains at memory address
/*
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int* getRandomNumber() {

	static int  *r;
	int i;
	r = &i;
	srand(time(NULL));
	*r = rand();
	printf("Address i = %p *r = %d\n", r, *r);
	return r;
}
int main() {

	int *p;
	p = getRandomNumber();
	printf("Address of p = %p, *p = %d\n", p, *p);
	return 0;
}
*/

//Example 6: Static Variables
/*
#include <stdio.h>
void func()
{
	static int i = 5;
	i++;
	printf("%d\n", i);
}
int main()
{
	int j;
	for (j = 0; j < 3; j++)
		func();
	return 0;
}
*/

//Example 7: Returning Pointer from Function may lead to wrong results because arr is undefined when misguided() terminates
/*
#include <stdio.h>

int * returnMyNumbers()
{
	int  i;
	int arr [] = {0,100,1000};

	for (i = 0; i <3; i++){
		printf("Address of arr[%d] = %p, arr[%d] = %d\n",i,(arr+i),i,arr[i]);
	}

	return arr;
}
int main ()
{
	int *numbers;
	int i;
	numbers = returnMyNumbers();
	printf("\n\n");
	for (i = 0; i < 3; i++)
	{
		printf("numbers = %p -- arr[%d] = %d\n",numbers,i,*numbers);
		numbers ++;
	}
	return 0;
}
*/

//Example 8: Using static variables solves this problem
/*
#include <stdio.h>

int * returnMyNumbers()
{
	int  i;
	static int arr[] = { 0,100,1000 };

	for (i = 0; i <3; i++) {
		printf("Address arr[%d] =%p, arr[%d] = %d\n",i,(arr+i), i, arr[i]);
	}

	return arr;
}
int main()
{
	int *numbers;
	int i;

	numbers = returnMyNumbers();
	for (i = 0; i < 3; i++)
	{
		printf("numbers = %p -- arr[%d] = %d\n", numbers, i, *numbers);
		numbers++;
	}
	return 0;
}
*/
//Example 9: Pointers to pointer
/*
#include <stdio.h>

int main ()
{
	int a, *p, **q, ***r;

	p = &a;
	q = &p;
	r = &q;

	printf("p points to address of a = %p\n",p);
	printf("q points to address of p = %p\n",q);
	printf("r points to address of q = %p\n",r);

	printf("Enter a number-->a:\n");
	scanf_s("%d",&a);
	printf("a = %d\n",a);

	printf("Enter a number-->p:\n");
	scanf_s("%d",p);
	printf("a = %d\n",a);

	printf("Enter a number-->*q:\n");
	scanf_s("%d",*q);
	printf("a = %d\n",a);

	printf("Enter a number-->**r:\n");
	scanf_s("%d",**r);
	printf("a = %d\n",a);
	return 0;
}
*/

// Example 10: Char Arraylist --> Array of pointers  in this example array of 3 pointers (Multidimensional arrays: Array of arrays)
/*
#include <stdio.h>
int main()
{
	char * arr[ ] ={"CEN 116", "CEN 118 LAB", "CEN 102"};
	int i;
	for (i = 0; i< 3; i++)
	{
		printf("arr[%d] = %s\n",i,arr[i]);
	}
	return 0;
}
*/

//Example 11: Pointer to arrays vs array of pointers
/*
#include <stdio.h>
int main()
{
	double val = 9.7;
	double array[] = { 3.2, 4.3, 5.4 };
	double *pdbl[2];  //an array of double pointers
	int a[][4] = { {9, 8, 7, 6},{13, 15, 17, 19},{21, 23, 25, 27} };
	int *pa[3], (*pb)[4]; // pa array of integer pointers, pa is not a pointer just an array name, pb a pointer to an array of integers

	pdbl[0] = &val;
	pdbl[1] = array + 1;
	printf("*pdbl[0] = %lf,\t *pdbl[1] = %lf\n\n", *pdbl[0], *pdbl[1]);
	
	pa[0] = a[2]; // it is an integer pointer to a[2] array
	printf("*pa[0] = %d\t *(pa[0]+1) = %d\t pa[0][2] = %d\t (*pa)[2] = %d\t (*pa)[3]=%d\n\n", *pa[0],*(pa[0]+1), pa[0][2], (*pa)[2], (*pa)[3]);
    
	//print("*pa[1] = %d\n", *pa[1]); // YOU CANNOT ACCESS BECAUSE YOU DID NOT ASSIGN ANY ADDRESS

	pb = &a[1]; 
	printf("*pb[0]=%d\t *pb[1]=%d\t *(pb[0]+3)=%d\t *(pb[0]+6) = %d\t pb[0][2]=%d\n", *pb[0], *pb[1], *(pb[0]+3), *(pb[0]+6), pb[0][2]);
	

	return 0;
}

*/



<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head><title>
	BAP-Özgeçmiş
</title></head>
<body>
    <form name="form1" method="post" action="ImageOfByte.aspx?Resim=8&amp;SSNO=5&amp;USER=17721" id="form1">
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
