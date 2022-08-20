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
	setlocale(LC_ALL, "UKR");
	srand(time(NULL));
	ofstream myfile;
	int n;
	char a, b, find;
	cout << "Кiлькiсть елементiв масиву:";
	cin >> n;
	cout << "Лiва границя (символ): ";
	cin >> a;
	cout << "Права границя (символ): ";
	cin >> b;
	cout << endl;
	char option;
	bool exit = false;
	double seconds;


	char* arr1 = new char[n];
	fillArray(arr1, n, a, b);
	while (exit==false)
	{
		cout << "1. Вихiд" << endl;
		cout << "2. Вивiд несортованого масиву" << endl;
		cout << "3. Сортування вставками" << endl;
		cout << "4. Сортування Шелла" << endl;
		cout << "5. Лiнiйний пошук" << endl;
		cout << "6. Бiнарний пошук" << endl;
		cout << "Ваш вибiр:";
		cin >> option;
		char* arr2 = new char[n];
		int result;
		char find;

		switch (option)
		{
		case '1':
			exit = true;
			break;
		case '2':
			printArray(arr1, n);
			break;
		case '3':
			copy(arr1, arr2, n);
			insertionSort(arr2, n);
			cout << "Масив пiсля сортування вставками" << endl;
			printArray(arr2, n);
			break;

		case '4':
			copy(arr1, arr2, n);
			shellSort(arr2, n);
			cout << "Масив пiсля сортування методом Шелла" << endl;
			printArray(arr2, n);
			break;
		case '5':
			printArray(arr1, n);
			cout << "Введiть символ, який необхiдно знайти: ";
			cin >> find;
			result = searchLinear(arr1, n, find, seconds);
			(result == -1)
				? cout << "Лiнiйний пошук. Елемента немає у масивi" << endl
				: cout << "Лiнiйний пошук. Елемент знаходиться за iндексом " << result  << endl;
			break;
		case '6':
			copy(arr1, arr2, n);
			insertionSort(arr2, n);
			printArray(arr2, n);
			cout << "Введiть символ, який необхiдно знайти: ";
			cin >> find;
			result = searchBinary(arr2, n, find, seconds);
			(result == -1)
				? cout << "Бiнарний пошук. Елемента немає у масивi" << endl
				: cout << "Бiнарний пошук. Елемент знаходиться за iндексом " << result << endl;
			break;
		default:
			cout << "Невiрне введення!" << endl;
			break;
		}
	}

	return 0;
}








