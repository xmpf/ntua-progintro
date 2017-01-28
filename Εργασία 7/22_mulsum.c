#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N,M,*a,*s,i,j,max=0;

  scanf("%d %d",&N,&M);
  a=malloc(N*sizeof(int));
  s=malloc(N*sizeof(int));
  s[0]=0;
  for(i=1;i<=N;i++){
    scanf("%d",&a[i]);
    s[i]=s[i-1]+a[i];
  }
  for (j=N;j>0;j--){
      for(i=1;i<=j;i++){
        int t=s[j]-s[i-1];
        if(t<max) break;
        else if(t%M==0 && t>max) {
        max=t;
        break;
        }

      }
    }
  printf("%d\n",max);
}