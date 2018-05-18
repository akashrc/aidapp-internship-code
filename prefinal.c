#include<stdio.h>
#include<malloc.h>

int main()
{
	FILE * fp;
	FILE * wp;
	int *p;
	
	int h;
    long maxi=0,n;
    long i,inj=1,j,count=0;
    long max=1000000;
	fp=fopen("input.txt","r");
	wp=fopen("output.txt","w");
	fscanf(fp,"%ld",&n);
	
	p=malloc(max*sizeof(int));
	for(i=0;i<n;i++)
	{
	fscanf(fp,"%d",(p+i));
	}
	for(i=0;i<n;i++)
	{
		fprintf(wp,"%d\n",*(p+i));
	}
    
    //for checking all maximum defeat
    for(i=2;i<n;i++)
    {
	count=0;
	
	h=2000;
	inj=1;
	//for check individual
	for(j=i;j<n;j++)
	{
	    h=h- *(p+i);
	    inj=inj * *(p+i);
		
	    //condition
	    if(h>0 && inj<=max)
	    {
		count++;
	    }
	    else {
		//storing max defeat in array b
		if(maxi<count)
		{
		maxi=count;
		//printf("%ld\t",count);
		}
		break;
		}
    }
	}

    printf("\n %ld",maxi);
	free(p);
	close(fp);
	close(wp);

    return 0;
}

