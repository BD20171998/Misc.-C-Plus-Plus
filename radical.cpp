#include <iostream.h>
#include <vector>

using namespace std; 

int prime(int);

int main()
{
	char x='y';

	while(x=='y')
	{

	int den=2,
		index,
		outside=1,
		inside=1,
		num,
		k,
		q,
		r,
		size,
		indicator; 
		
	vector<int> array;

	cout<<"Please enter number under radical to simplify: ";

	cin>>num;

	cout<<"\n"
		<<"Please enter index number: ";

	cin>>index;

	size=(num+1);
	cout<<"\n"
		<<"\n"
		<<"\n";
      
	array.resize(size); 

	for(int i = 0; i<array.size(); ++i)
		array[i] = 0;

	indicator=prime(num);

	if(indicator==1)
	{

	cout<<"\n";
	cout<<"	";
	cout<<indicator;
	}
	
	else
	{
	while(den < num+1)
	{
		q=num;
		r=q%den;

		while(r==0)
		{
			++array[den];
			
			q=(q/den);
			
			if (q<2)
				r=1;

			r=q%den;
		}
			

		++den;
		indicator=prime(den);

		while(indicator==2)
		{
			++den;
			indicator=prime(den);
		}
	}

}
	for(int t=2;t<(num+1);t++)
	{
		
		indicator=prime(t);

		if(indicator==2)
			continue;

		if(array[t]<index)
		{
			for(k=0; k<array[t]; ++k)
				inside=inside*t;
		}

		if(array[t]==index)
			outside=outside*t;

		if(array[t]>index)
		{
			q= array[t]/index;
			r=array[t]%index;

			for(k=0; k<q; ++k)
				outside=outside*t;

			for(k=0; k<r; ++k)
				inside=inside*t;
		}

	}	



	cout<<"\n"
		<<outside
		<<" radical "
		<<inside;

	cout<<"\n"
		<<"\n"
		<<"\n";

	}

	return 0;

}

int prime(int d)
{

	int i=2, r;

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