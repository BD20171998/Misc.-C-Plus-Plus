#include <iostream.h>

int prime(int);

int main() 
    {
       char x='y';

	   while(x=='y')
	   {
		   
		int num,
			indicator;

        cout <<"Enter number to be checked: ";
        cin >> num; 

		indicator=prime(num);		

		if(indicator==1)
		{
			cout<<"\n"
			    <<"Prime"
				<<"\n"
				<<"\n";
		}

		if(indicator==2)
		{
			cout<<"\n"
			    <<"Not Prime"
				<<"\n"
				<<"\n";
		}

	   }

        return 0; 
    }

int prime(int d)
{

	int i=2,r;

	while(i<d)
	{
		r = d%i;
		
		if(r==0)
		{
			return 2;
			break;
		}

		i++;

	}

	return 1;

}