#include <stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	int h;
    long maxi=0;
    long i,inj=1,j,count=0;
    long max=1000000;
    
    //for checking all maximum defeat
    for(i=2;i<argc;i++)
    {
	count=0;
	
	h=2000;
	inj=1;
	//for check individual
	for(j=i;j<argc;j++)
	{
	    h=h-atoi(argv[j]);
	    inj=inj * atoi(argv[j]);
		
	    //condition
	    if(h>0 && inj< max)
	    {
		count++;
	    }
	    else {
		//storing max defeat in array b
		if(maxi<count)
		{
		maxi=count;
		}
		break;
		}
    }
	}

    printf("%ld",maxi);


    return 0;
}
