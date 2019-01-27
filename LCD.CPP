#include <iostream.h>
#include <vector>

using namespace std;

int  max(int,vector<int>);
void multiplier(int,vector<int>*);
int	 prime(int);
void factor(int,vector<int>* );

int main()
{
	int biggest, index, nums, term; 

	vector<int> numbers;
	vector<int> store;

	//get number of numbers from user

	cout<<"Please enter number of terms for LCD ";

	cin>>nums;

	//resize nums vector
	numbers.resize (nums); 

	//get numbers from user

	for(index = 0; index<nums; ++index)
	{
		cout<<"#"<<index+1<<":";		
		cin>>numbers[index];
	}

	//get biggest number from the set of numbers
	biggest=max(nums,numbers); 

	//resize store vector to hold factors to size +1 because you need to fit in the number itself
	store.resize(biggest+1);

	//start populating store array with factors of the numbers from user
	for(index=0;index<nums;++index)
	{
		term=numbers[index];
		factor(term,&store);
	}

    multiplier(biggest,&store);

	return 0;

}

//picks biggest number out of vector
int max(int n,vector<int> arr)
{

  int i,j, spot, compare;
	
	vector<int> temp_arr;

  //resize temp_arr vector
	temp_arr.resize (n);

	for(i=0;i<n;i++)
	{
		//setting up number to compare to the rest of vector
		compare=arr[i];

		//reset place counter for next number to check
		spot=0;	
		
		//the number to compare gets compared to the rest of the numbers in the array from the beginning
		for(j=0;j<n;j++)
		{
			if(compare!=arr[j])	//if the numbers are equal you skip that array spot i.e. the number is the one in the array
				if(compare<arr[j])//if the number you're checking is less than the next one in vector, the number gets an incresed place number
					spot++;	
		}

		//store number in it's rightful sorted spot in vector 
		temp_arr[spot]=compare;			
	}

	//return the biggest number
	return temp_arr[0];

}

void multiplier(int big,vector<int>* temp)
{
	int j,i,indicator,lcd=1;

	for(i=2;i<big+1;++i)
	{
		indicator=prime(i);
		if(indicator==1)
			for(j=0;j<(*temp)[i];++j)
				lcd*=i;
	}

	cout<<lcd;

}

//using pointers for vectors since its much faster to pass - see html file "resizing vector via a pointer to the vector - C++"
void factor(int number, vector<int>* temp)	
{
	int	indicator, den=2, q, r, temporary;

	vector<int> temp2;

	temp2.resize(number+1);

	//check if number to be factored is prime
	indicator=prime(number);

	//if number to be factored is prime, store it 
	if(indicator==1)
		temp2[number]=1;
	
	else
	{
		//while divisor is less than biggest num +1
		while(den < number+1)
		{
			//reset dividend to orig number to be factored  
			q=number;
			r=q%den; //remainder of current number divided by current divisor

			//check if the quotient still has some more factors of divisor in it
			while(r==0)
			{
				++temp2[den]; //add 1 in divisor slot in vector if current divisor is a factor
			
				q=(q/den);//divide quotient again by current divisor to get new quotient
			
				if (q<2) //break loop if dividend is less than 2
					r=1;

				r=q%den;//check if new quotient has that same factor
			}
			
			++den; //increment old divisor by 1
			indicator=prime(den); //check if new divisor is prime

			//find next prime by keep incrementing until you get to next prime
			while(indicator==2)
			{
				++den;
				indicator=prime(den);
			}
		}
	}	

	//minimize the factors going into store vector
	for(int i=2;i<number+1;++i)
		if(temp2[i]>(*temp)[i])
			(*temp)[i]=temp2[i];
		
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