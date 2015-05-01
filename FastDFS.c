#include <stdio.h>
#include <complex.>
#include <math.h>
void FastDFS(double complex *x, double complex *y, double complex *w, double complex *Wp, int N, int skip)//The size of w is N
/*<cui>_<bingyu>_exer_3*/
{
    int n,m,s,mo,j; /*mo means the mod(j*k,N)*/
    if (N%2!=0)
     {
        for (m=0;m<N;m++)
            {
                x[m*skip]=0;
                for (s=0;s<N;s++)
                  {
                      mo=(m*s)%N;
                      w[s]=y[s*skip];
            x[m*skip]+=Wp[mo]*(w[s]);
                   }
            //printf("xtempor %g+i%g\n",creal(x[m*skip]),cimag(x[m*skip]));
            }
    }
    else
    {
        for (n=0;n<N/2;n++)
        {
            Wp[n]=(Wp[2*n]);
           /* printf("Wp[%d]=%g+i*%g\n",n,creal(Wp[n]),cimag(Wp[n]));
        printf("Wpp[%d]=%g+i*%g\n",n,creal(Wpp[n]),cimag(Wpp[n]));
        */
        }

    FastDFS(x, y, w, Wp, N/2, 2*skip);
  /*  for (s=0;s<N/2;s++)
        {
            printf("xe[%d]=%g+i*%g\n",s,creal(xe[s]),cimag(xe[s]));
        }
*/
    FastDFS(x+skip, y+skip, w, Wp, N/2, 2*skip);

 /*      for (s=0;s<N/2;s++)
        {
            printf("xo[%d]=%g+i*%g\n",s,creal(xo[s]),cimag(xo[s]));
        }
*/
    for (j=0;j<N/2;j++)
    {
 //       printf("xe[%d]=%g+i*%g\n",j,creal(x[j*2*skip]),cimag(x[j*2*skip]));
//        printf("xo[%d]=%g+i*%g\n",j,creal(x[skip*(j*2+1)]),cimag(x[skip*(j*2+1)]));
        w[j*2]=x[j*2*skip];
        w[j*2+1]=x[(j*2+1)*skip];
//        printf("w[%d]=%g+i*%g\n",j,creal(w[j*2]),cimag(w[j*2]));
//        printf("w[%d*2+1]=%g+i*%g\n",j,creal(w[(j*2+1)]),cimag(w[(j*2+1)]));
        Wp[j]=-Wp[j+N/2];
 //       printf("Wp[%d]=%g+i*%g\n",j,creal(Wp[j]),cimag(Wp[j]));
  //      printf("Wp[%d+N/2]=%g+i*%g\n",j,creal(Wp[j+N/2]),cimag(Wp[j+N/2]));
    }
    for (s=0;s<N/2;s++)
    {
        x[skip*s]=w[s*2]+w[s*2+1]*(Wp[s]);
        x[skip*(s+N/2)]=w[s*2]+w[s*2+1]*(Wp[s+N/2]); ////WN^(j+N/2)=-WN^(j)=Wp[j+N/2]=-Wp[j]
//       printf("w[%d]=%g+i*%g\n",s,creal(w[s*2]),cimag(w[s*2]));
//        printf("w[%d*2+1]=%g+i*%g\n",s,creal(w[(s*2+1)]),cimag(w[(s*2+1)]));
    }
   }
}
