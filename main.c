#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>
double complex *MakeWpowers(int);
void free_Vector(double complex *M);
double complex **makeCn(int);
void FastDFS(double complex *v1, double complex *v2, double complex *v3, double complex *v4, int, int);
void FastDFT(double complex *v1, double complex *v2, double complex *v3, double complex *v4, int, int);
double complex *Makeyn(int N);
double complex *Makeran(int N);
int main(void)
{
    int N=1,s,i,k1,loop;
    double complex *Wp,*x,*y,*w;
    double now1,then1,diff1,diff2,diff,now2,then2,k2,rate;
    for (i=1;i<=1;i++)
    {
        N*=4;
        Wp=MakeWpowers(N);
//if the array is 1D，then skip=1
// in high dimensional case,skip=the number of columns
//Do a Fourier transform of an array of N ecomplex numbers separated by steps of (ecomplex) size skip.
//Here for a case of 2D DFT, I the matrix to be transformed will be writen as (Y0,Y1,..Y(skip-1)),namely, i transfom columns separately
    /*    switch(i)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:loop=100000000;
            case 7:
            case 8:
            case 9:
            case 10:loop=10000;
            default:loop=1000;
        }
        now1=(double) clock()/(double)CLOCKS_PER_SEC;
        for (k1=1;k1<=loop;k1++)
        {
            y=Makeyn(N);//the size of y and x should be N*skip while the size of w is N
            x=Makeran(N);
            w=Makeran(N);
            FastDFS5(x,y,w,Wp,N,2);//when use FastDFT, x also changes
            free_Vector(x);
            free_Vector(y);
            free_Vector(w);
        }
        then1=(double) clock()/(double)CLOCKS_PER_SEC;
        diff1=(then1-now1);
        now2=(double) clock()/(double)CLOCKS_PER_SEC;
        for (k2=1;k2<=loop;k2++)
        {
            y=Makeyn(N);//the size of y and x should be N*skip while the size of w is N
            x=Makeran(N);
            w=Makeran(N);
            free_Vector(x);
            free_Vector(y);
            free_Vector(w);
        }
        then2=(double) clock()/(double)CLOCKS_PER_SEC;
        diff2=(then2-now2);
        diff=(diff1-diff2)/((double)loop);
        rate=(((double)(N*28))+8.0*((double)N)*log((double)N)/log(2.0))/(1e6*diff);
        printf("%d  %18.12g\n",N,rate);*/
        y=Makeyn(N);
        x=Makeran(N);
        w=Makeran(N);
        FastDFS(x,y,w,Wp,N,1);
        for (s=0;s<N;s++)
        {
            printf("x[%d]=%g+i*%g\n",s,creal(x[s]),cimag(x[s]));
        }
    }

 /*       for (s=0;s<N;s++)
        {
            printf("y[%d]=%g+i*%g\n",s,creal(y[s]),cimag(y[s])); //注意skip不等于1输出的x的值！
        }
*/
    return(0);
}

double complex *MakeWpowers(int N)
{
    int n;
    double complex *v;
    double PI;
    PI=atan(1.0)*4.0;
    v=(double complex *)malloc((N)*sizeof(double complex));
    for (n=0;n<N;n++)
    {
        v[n]=cos((double)(n)*PI*2.0/((double)N))+sin((double)(n)*2.0*PI/((double)N))*I;
    }
    return(v);
}

double complex **makeCn(int N)
{
    double complex **M1;
    double PI;
    int n1,j,k;
    PI=atan(1)*4.0;
    M1= (double complex **)malloc(N*sizeof(double complex *));
    for (n1=0;n1<N;n1++)
        M1[n1]=(double complex *)malloc(N*sizeof(double complex));
    for (j=0;j<N;j++)
            for (k=0;k<N;k++)
            M1[j][k]=cexp(2.0*I*PI*j*k/N);
    return(M1);
}

double complex *Makeyn(int N)
{
    int n;
    double complex *v;
    v=(double complex *)malloc((N)*sizeof(double complex));
    for (n=0;n<N;n++)
    {
        v[n]=2*n+1;
    }
    return(v);
}

double complex *Makeran(int N)
{
    double complex *v;
    v=(double complex *)malloc((N)*sizeof(double complex));
    return(v);
}

void free_Vector(double complex *M)
{
    free(M);
}
