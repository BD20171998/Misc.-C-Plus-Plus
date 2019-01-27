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
		num,
		q,
		r,
		size,
		indicator; 
		
	vector<int> array;

	cout<<"Please enter number to factor: ";

	cin>>num;
	size=(num+1);
	cout<<"\n"
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

	cout<<"\n "
		<<"Prime factorization is:  ";

	for(int t=2;t<(num+1);t++)
	{
		indicator=prime(t);
		
		if(indicator==2 || array[t]==0)
			continue;

		for(int j=0; j<array[t]; ++j)
		{
			cout<<t
			    <<" x ";
		}

	}

	cout<<"1"
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