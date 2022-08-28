#include <iostream>
#include <fstream>
using namespace std;

double insertionSort(char arr[], int n)
{
	clock_t start = clock();
	int i, j;
	char key;
	for (i = n - 2; i >= 0; i--)
	{
		key = arr[i];
		j = i + 1;

		while (j < n && arr[j] < key)
		{
			arr[j - 1] = arr[j];
			j = j + 1;
		}
		arr[j - 1] = key;
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	return seconds;
}

double shellSort(char arr[], int n)
{
	clock_t start = clock();
	int itr = n;
	itr = itr / 2;
	while (itr > 0)
	{
		for (int i = 0; i < n - itr; i++)
		{
			for (int j = i; (j >= 0) && (arr[j] > arr[j + itr]); j--)
			{
				char buffer = arr[j];
				arr[j] = arr[j + itr];
				arr[j + itr] = buffer;
			}
		}
		itr = itr / 2;
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	return seconds;
}


void printArray(char arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


void fillArray(char arr[], int n, char a, char b)
{
	char c;
	int r, aNo, bNo;
	aNo = (int)a - 97;
	bNo = (int)b - 97;
	for (int i = 0; i < n; i++)
	{
		r = rand() % (bNo - aNo + 1) + aNo;
		arr[i] = (char)r + 97;
	}
}

int searchBinary(char arr[], int num, char find, double& s)
{
	int res = -1;
	clock_t start = clock();
	int beg = 0, end = num - 1;
	while (beg <= end)
	{
		int mid = (beg + end) / 2;
		if (find == arr[mid])
		{
			res = mid;
			break;
		}
		else if (find < arr[mid])
		{
			end = mid - 1;
		}
		else {
			beg = mid + 1;
		}
	}
	clock_t ends = clock();
	s = (double)(ends - start) / CLOCKS_PER_SEC;
	return res;
}

int searchLinear(char arr[], int n, char x, double& s)
{
	clock_t start = clock();
	int res = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x) 
		{
			res = i;
			break;
		}
	}
	clock_t end = clock();
	s = (double)(end - start) / CLOCKS_PER_SEC;
	return res;
}

void copy(char source[], char destination[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		destination[i] = source[i];
	}
}


int main()
{
	srand(time(NULL));
	ofstream myfile;
	myfile.open("result.txt");
	int n;
	char a, b, find;
	cout << "Enter the number of items:";
	cin >> n;
	cout << "Enter left limit (symbol): ";
	cin >> a;
	cout << "Enter right limit (symbol): ";
	cin >> b;
	cout << "Enter symbol to find: ";
	cin >> find;
	double seconds;
	cout << "NUM\t|" << "Insert\t|" << "Shell\t|" << "Linear\t|" << "Binary" << endl;
	myfile << "NUM\t|" << "Insert\t|" << "Shell\t|" << "Linear\t|" << "Binary" << endl;
	int step = n;
	while (n <= 100000)
	{
		char* arr1 = new char[n];
		char* arr2 = new char[n];
		fillArray(arr1, n, a, b);
		copy(arr1, arr2, n);
		cout << n << "\t|";
		myfile << n << "\t|";
		seconds = insertionSort(arr1, n);
		//cout << "Seconds (for insertion sort): " << seconds << endl; 
		cout << seconds << "\t|";
		myfile << seconds << "\t|";
		seconds = shellSort(arr2, n);
		//cout << "Seconds (for shell sort): " << seconds << endl << endl;
		cout << seconds << "\t|";
		myfile << seconds << "\t|";


		int result = searchLinear(arr1, n, find, seconds);
		/*(result == -1)
			? cout << "Linear. Element is not present in array" << endl
			: cout << "Linear. Element is present at index " << result << endl;
		cout << "Seconds (for linear search): " << seconds << endl;*/

		cout << seconds << "\t|";
		myfile << seconds << "\t|";


		result = searchBinary(arr1, n - 1, find, seconds);
		/*(result == -1)
			? cout << "Binary. Element is not present in array" << endl
			: cout << "Binary. Element is present at index " << result << endl;
		cout << "Seconds (for binary search): " << seconds  << endl;*/

		cout << seconds << endl;
		myfile << seconds << endl;
		n *= 2;
		delete[] arr1;
		delete[] arr2;
	}

	myfile.close();
	return 0;
}








