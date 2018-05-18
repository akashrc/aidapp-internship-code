#include<stdio.h>
#include<malloc.h>

int main()
{
	//file pointer to read input.txt
	FILE * fp;
	//pointer for dynamically allocation of array
	int *p;
	//h is the varriable for health  
	int h;
	//maxi is the varriable for find out maximum number of monkey that can be defeat
    long maxi=0,n;
    long i,inj=1,j,count=0;
    long max=1000000;
	//opening "input.txt"
	fp=fopen("input.txt","r");
	//storing total monkeys in n varriable
	fscanf(fp,"%ld",&n);
	//dynmically allocating array and store the values of input.txt
	p=malloc(max*sizeof(int));
	for(i=0;i<n;i++)
	{
	fscanf(fp,"%d",(p+i));
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
	//printing the maximum monkey which will defeat
    printf("\n%ld",maxi);
	//deallocating the array p
	free(p);
	//closing the opened file of input.txt
	close(fp);
	    return 0;
}

