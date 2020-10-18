#include<stdio.h>   //for standard input and output
#include<time.h>
#include<stdlib.h>


//prototypes
void method1(int [],int [],int);
void method2(int [],int [],int);

int main()
{
int X[100000],A[100000];
long int n=50;
FILE *fptr;
fptr=fopen("time_data.txt","w");
while(n<100000)
{
srand(time(0));

for(int i=0;i<n;i++)
X[i]=rand();

clock_t t;//object to record time
t=clock();
method1(X,A,n);
t=clock()-t;
double t1=((double)t)/CLK_TCK;
t=clock();
method2(X,A,n);
t=clock()-t;
double t2=((double)t)/CLK_TCK;

printf("%d\t%lf\t%lf\n",n,t1,t2);
//fprintf(fptr,"%s\t%s\t%s\n","N","method1","method2");
fprintf(fptr,"%d\t%lf\t%lf\n",n,t1,t2);


n*=2;

}
fclose(fptr);
return 0;
}

void method1(int X[],int A[],int n)
{
double sum;
int i,j;
for(i=0;i<n;i++)
 {
 sum=0;
 for(j=0;j<=i;j++)
  sum+=X[j];
 A[i]=sum/(i+1);
 }
}


void method2(int X[],int A[],int n)
{
double sum=0;
int i,j;
for(i=0;i<n;i++)
 {
 sum+=X[i];
 A[i]=sum/(i+1);
 }
}
