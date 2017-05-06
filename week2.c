// Example 1: Printing the address of a variable
/*
#include <stdio.h>

int main ()
{
	char b;		
	char c;   
	int a;		

	printf("&a is %p\t &b is %p\t and &c is %p\n", &a,&b,&c);
return 0;
}
*/

// Example 2: pointer declaration 

#include<stdio.h>

int main()
{
	int a;
	int *p;

	a = 14;
	p = &a;

	printf("The value of variable a = %d\t the address of the variable a = %p\n", a, &a);
	printf("The value of variable a = %d\t the address of the variable a = %p\n", *p, p);
	return 0;
}

//Example 3: Scanf with pointers
/*
#include < stdio.h>

int main()
{
	float a, b, r;
	float *pa = &a, *pb = &b;  // when you don't assign any variable you get error
	float *pr = &r;



	scanf_s("%f",pa);
	scanf_s("%f",pb);

	*pr = *pa + *pb;

	printf("%f\n",*pr);

	return 0;
}
*/


// Example 6: Pointer operations
/*
#include <stdio.h>
int main()
{
	char c = 'A';
	char *pc = &c;
	double d = 5.43;
	double *pd1, *pd2;
	
	printf("c is %c\nd is %f\n", c, d);
	printf("*pc is %c\n", *pc);
	
	pd1 = &d;
	*pc = 'B';
	pd2 = pd1;
	*pd1 = *pd2 * 0.2;
	printf("After\n");
	printf("c is %c\nd is %lf\n*pd1 is %lf\n*pd2 is %lf\n", c, d, *pd1, *pd2);
	printf("pd1 and pd2 %p %p\n", pd1, pd2);
	return 0;
}
*/

// Example 7: Changing the values
/*
#include < stdio.h>
int main()
{
	int a,b,c;
	int *p, *r, *q;

	a = 6;
	b = 2;

	p = &b;
	q = p;

	r = &c;
	p = &a;
	*q = 8;

	*r = *p;
	*r = a+ *q + *&c;

	printf("%d %d %d\n",a,b,c);
	printf("%d %d %d\n",*p,*q,*r);

	return 0;
}
*/


// EXAMPLE 8: Why do we use Pointers in Function Communication ( WE USE POINTERS WHEN WE WANT TO RETURN MORE THAN ONE VARIABLE) (UNWORKABLE EXAMPLE)
/*
#include <stdio.h>

void exchange(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int a = 5, b= 7;

	exchange(a,b);
	printf(" a= %d b =%d\n", a,b);
	return 0;
}
*/

// EXAMPLE 8':  WE USE POINTERS WHEN WE WANT TO RETURN MORE THAN ONE VARIABLE) (SOLUTION TO EXAMPLE 8)
/*
#include <stdio.h>

void exchange(int * x, int * y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a = 5, b= 7;

	exchange(&a,&b);
	printf("a =%d b= %d\n", a,b);
	return 0;
}
*/

// EXAMPLE 9: Arrays and Pointers
/*
#include <stdio.h>

int main()
{
	int buffer[3] = { 3,4,5 }, buffer2[3];
	int *pbuffer1, *pbuffer2, *p, *p2;

	char letters[8] = "CEN 111";
	char *pc1, *pc2, *pc3;

	pbuffer1 = buffer;
	pbuffer2 = buffer + 2;
	printf("buffer[0] is %d\t buffer[2] is %d\n", buffer[0], buffer[2]);
	printf("*pbuffer is %d\t *pbuffer2 is %d\n\n\n", *pbuffer1, *pbuffer2);

	//The name of the array, the address of the array and the address of the first element in the array are the same
	pc1 = letters;
	pc2 = &letters;
	pc3 = &letters[0];

	printf("*pc1 = %c *pc2 = %c *pc3 = %c\n", *pc1, *pc2, *pc3);

	printf("letters[4] = %c\n", letters[4]);
	printf("pc1[4] = %c\n", pc1[4]);
	printf("*(pc2 + 4) = %c\n", *(pc2 + 4));
	printf("*(letters + 4) = %c\n", *(letters + 4));

	pc3 = &letters[2];
	printf("*pc3 = %c\n", *pc3);
	pc3 = &pc1[2];
	printf("*pc3 = %c\n", *pc3);
	pc3 = letters + 2;
	printf("*pc3 = %c\n", *pc3);
	pc3 = pc2 + 2;
	printf("*pc3 = %c\n", *pc3);
	printf("pc3[-1] = %c\n\n\n\n", pc3[-1]);

	// DIFFERENCES BETWEEN ARRAYS AND POINTERS
	p = buffer;
	p2 = p;
	printf("*p = %d\t *p2 = %d\n", *p, *p2);
	//buffer2 = buffer; // !!!!!!!!!!!!!!!1POINTERS CAN BE ASSIGNED BUT ARRAYS CANNOT BE

	//printf("*(buffer++) = %d", *(buffer++));  // YOU CANNOT INCREMENT ARRAY because it is not a variable
	printf("*(p++) = %d\n", *(p++));
	return 0;
}
*/

//EXAMPLE -10 Pointer Arithmetic !!!!!!!!!!!!!!!!! IMPORTANT
/*
#include <stdio.h>

int main()
{
	int array1[] = {1,2,3,4,5,6,7,8,9 };
	int array2[] = {78,45,69};
	int *p1, *p2, *p3 = array1;
	char *p4 = array1;   // Wrong assignment
	double *p5 = array1; // Wrong assignment

	printf("char type pointer gives wrong value with increment : %d\n", *(++p4));   // YOU WILL SEE 0
	printf("double type pointer gives wrong value with increment : %d\n", *(++p5));
	printf("The pointer type must match with the variable type that it points: %d\n", *(++p3));  // YOU WILL SEE 2

	p2 = p3;
	printf("*p2 = %d\n", *p2);
//	*&p2 = *p3; // It will give ERROR
//	printf("p2 = %p, *p2 = %d\n", p2, *p2);

	 p1 = (array1 + 5);
	*p2 = *p1 + 23;
	printf("array1[1] = %d\n", *(array1 + 1));


	return 0;
}

*/
