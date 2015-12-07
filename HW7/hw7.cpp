/*
Homework_7
Jiming Ye
N16566270
jy1769@nyu.edu
Mac OSX
*/

#include <iostream>
#include <sstream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::queue;

int counter = 0;

void merge_A(int data[], int leftSize, int rightSize, int &counter)
{
	int *temp;
	size_t copiedLeft = 0;
	size_t copiedRight = 0;
	size_t copied = 0;
	temp = new int[leftSize + rightSize];
	while((copiedLeft < leftSize) && (copiedRight < rightSize))
  	{
    	if(data[copiedLeft] < (data+leftSize)[copiedRight])
			{
				temp[copied] = data[copiedLeft];
				++copied, ++copiedLeft;
				++counter;
			}
    	else
			{
				temp[copied] = (data+leftSize)[copiedRight];
				++copied, ++copiedRight;
				++counter;
			}
    }
	while(copiedLeft < leftSize)
    	{
    		temp[copied] = data[copiedLeft];
    		++copied, ++copiedLeft; 
    		++counter;
    	}
  
  	while(copiedRight < rightSize)
    	{
    		temp[copied] = (data+copiedLeft)[copiedRight];
    		++copied, ++copiedRight;
  			++counter;
  		}
  	for(size_t i = 0; i < leftSize+rightSize; i++)
    	data[i] = temp[i];
  	delete [] temp;
}

void mergeSort_A(int data[], int arraySize)
{
  	size_t leftSize;
  	size_t rightSize;
  	if(arraySize > 1)
    {
    	leftSize = arraySize/2;
    	rightSize = arraySize - leftSize;
    	mergeSort_A(data, leftSize);
     	mergeSort_A((data+leftSize), rightSize);
     	merge_A(data, leftSize, rightSize, counter);
    }
}

void merge_D(int data[], int leftSize, int rightSize, int &counter)
{
	int *temp;
	size_t copiedLeft = 0;
	size_t copiedRight = 0;
	size_t copied = 0;
	temp = new int[leftSize + rightSize];
	while((copiedLeft < leftSize) && (copiedRight < rightSize))
  	{
    	if(data[copiedLeft] > (data+leftSize)[copiedRight])
			{
				temp[copied] = data[copiedLeft];
				++copied, ++copiedLeft;
				++counter;
			}
    	else
			{
				temp[copied] = (data+leftSize)[copiedRight];
				++copied, ++copiedRight;
				++counter;
			}
    }
	while(copiedLeft < leftSize)
    	{
    		temp[copied] = data[copiedLeft];
    		++copied, ++copiedLeft;
    		++counter;
    	}
  
  	while(copiedRight < rightSize)
    	{
    		temp[copied] = (data+copiedLeft)[copiedRight];
    		++copied, ++copiedRight;
  			++counter;
  		}
  	for(size_t i = 0; i < leftSize+rightSize; i++)
    	data[i] = temp[i];
  	delete [] temp;
}
void mergeSort_D(int data[], int arraySize)
{
  	size_t leftSize;
  	size_t rightSize;
  	if(arraySize > 1)
    {
    	leftSize = arraySize/2;
    	rightSize = arraySize - leftSize;
    	mergeSort_D(data, leftSize);
     	mergeSort_D((data+leftSize), rightSize);
     	merge_D(data, leftSize, rightSize, counter);
    }
}

int String_to_Number(string str)
{
	istringstream iss(str);
	int num;
	iss >> num;
	return num;
}

int main()
{
	queue<string> sque;
	string str1, str2;
	int array[100];
	int m = -1;
	cout << "please enter the number and sorting mode:" << endl;
	getline(cin, str1);
	istringstream iss(str1);
	while(iss >> str1)
	{
		sque.push(str1);
		++m;
	}
	str2 = sque.front();
	sque.pop();
	for (int n = 0; n != m; ++n)
	{
		array[n] = String_to_Number(sque.front());
		sque.pop();
	}
	if(str2 == "A" || str2 == "a")
	{
		mergeSort_A(array, m);
		cout << "The result is: " << endl;
		for(int i = 0; i != m; ++i)
			cout << array[i] << " ";
		cout << endl;
	}
	else if(str2 == "D" || str2 == "d")
	{
		mergeSort_D(array, m);
		cout << "The result is: " << endl;
		for(int i = 0; i != m; ++i)
			cout << array[i] << " ";
		cout << endl;
	}
	cout << "An item is copied from data array to temp array " << counter << " times." << endl;
	return 0;
}