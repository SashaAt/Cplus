#include <iostream>;
#include <ctime>;
#include <cstdlib>
#include <iso646.h>;

const int N = 10;
const int Big = 1000;

template <typename T1>
void bubbleSort(T1 arr[],int size) {
	T1 tmp;
	bool is_sorted = false;
	while (not(is_sorted)) {
		is_sorted = true;
		for (int i = 0; i < size - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				is_sorted = false;
			}
		}
	}
}

template <typename T2>
void selectSort(T2 arr[], int size) {
	T2 tmp, min;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[min])
				min = j;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}

template <typename T3>
void insertSort(T3 arr[], int size) {
	T3 tmp;
	for (int i = 1; i < size; ++i) {
		for (int j = i; j > 0 and arr[j - 1] > arr[j]; --j) {
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
		}
	}
}

template <typename T4>
void shellSort(T4 arr[], int size) {
	for (int s = size / 2; s > 0; s /= 2) {
		for (int i = s; i < size; ++i) {
			for (int j = i - s; j >= 0 and arr[j] > arr[j + s]; j -= s) {
				T4 tmp = arr[j];
				arr[j] = arr[j + s];
				arr[j + s] = tmp;
			}
		}
	}
}

template <typename T5>
void quickSort(T5 arr[], int left, int right)
{
  T5 pivot;														// ����������� �������
  int l_hold = left;												//����� �������
  int r_hold = right;												// ������ �������
  int size = right + 1;
  pivot = arr[left];
  while (left < right)												// ���� ������� �� ���������
  {
    while ((arr[right] >= pivot) and (left < right))
      right--;												// �������� ������ ������� ���� ������� [right] ������ [pivot]
    if (left != right)											// ���� ������� �� ����������
    {
      arr[left] = arr[right];												 // ���������� ������� [right] �� ����� ������������
      left++;														// �������� ����� ������� ������
    }
    while ((arr[left] <= pivot) and (left < right))
      left++;														// �������� ����� ������� ���� ������� [left] ������ [pivot]
    if (left != right)															// ���� ������� �� ����������
    {
      arr[right] = arr[left];													// ���������� ������� [left] �� ����� [right]
      right--;													// �������� ������ ������� ������
    }
  }
  arr[left] = pivot;														// ������ ����������� ������� �� �����
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)													// ���������� �������� ���������� ��� ����� � ������ ����� �������
    quickSort(arr, left, pivot - 1);
  if (right > pivot)
    quickSort(arr, pivot + 1, right);
}

template <typename T6>
void siftDown(T6 arr[], int root, int bottom)
{
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // ���� �� � ��������� ����,
			maxChild = root * 2;    // ���������� ����� �������
		  // ����� ���������� ������� ������� �� ����
		else if (arr[root * 2] > arr[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (arr[root] < arr[maxChild])
		{
			T6 temp = arr[root]; // ������ �� �������
			arr[root] = arr[maxChild];
			arr[maxChild] = temp;
			root = maxChild;
		}
		else // �����
			done = 1; // �������� ������������
	}
}
// ������� ���������� �� ����
template <typename T6>
void heapSort(T6 arr[], int array_size)
{
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2); i >= 0; i--)
		siftDown(arr, i, array_size - 1);
	// ���������� ����� �������� ��������� ��������
	for (int i = array_size - 1; i >= 1; i--)
	{
		T6 temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		siftDown(arr, 0, i - 1);
	}
}

template <typename T7>
// ������� ���������� ����������� ��������
void mergeSort(T7 arr[], int l, int r)
{
	if (l == r) return; // ������� ����������
	int mid = (l + r) / 2; // ���������� �������� ������������������
	// � ���������� �������� ������� ���������� ��� ������ ��������
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	int i = l;  // ������ ������� ����
	int j = mid + 1; // ������ ������� ����
	T7* tmp = (T7*)malloc(r * sizeof(T7)); // �������������� ������
	for (int step = 0; step < r - l + 1; step++) // ��� ���� ��������� ��������������� �������
	{
		// ���������� � ����������� ������������������ ������� �� ��������� ���� �����
		// ��� ������� ������� ���� ���� j > r
		if ((j > r) || ((i <= mid) && (arr[i] < arr[j])))
		{
			tmp[step] = arr[i];
			i++;
		}
		else
		{
			tmp[step] = arr[j];
			j++;
		}
	}
	// ������������ �������������� ������������������ � �������� ������
	for (int step = 0; step < r - l + 1; step++)
		arr[l + step] = tmp[step];
}

void init_arr(int* arr) {					// ������������� �������� �������� �������
	for (int i = 0; i < Big; ++i) {
		arr[i] = rand()%10000;
	}
}

void init_swap_arr(int* arr) {
	for (int i = Big - 1 ; i >= 0; --i)		// ������������ �������, ���������������� �� ��������
		arr[i] = i;
}

void init_other_arr(int* arr) {				// ������������� ����� ���������������� �������
	for (int i = 0; i < Big - 10; ++i)
		arr[i] = i;
	for (int i = Big - 10; i < Big; ++i)
		arr[i] = 350000 - rand() % 100;
}

int main()
{
	using namespace std;
	int int_arr[N] = { 5,3,1,2,4,6,9,8,7,10 };
	double double_arr[N] = { 5.2,3.6,1.4,2.5,4.0,6.8,9.4,8.123,7.9,10.345};
	//bubbleSort(int_arr,N);													// ���������� ��������� ��������
	//bubbleSort(double_arr,N);
	//selectSort(int_arr, N);
	//selectSort(double_arr, N);
	//insertSort(int_arr, N);
	//insertSort(double_arr, N);
	//shellSort(int_arr, N);
	//shellSort(double_arr, N);
	//quickSort(int_arr, 0, N - 1);
	//quickSort(double_arr, 0, N - 1);
	//heapSort(int_arr, N);
	//heapSort(double_arr, N);
	//mergeSort(int_arr,0, N-1);
	//mergeSort(double_arr, 0, N-1);
	/*
	for (int i = 0; i < N; ++i)
		cout << int_arr[i] << endl;
	for (int i = 0; i < N; ++i)
		cout << double_arr[i] << endl;
	*/
	int big_arr[Big];
	cout << "������ ���������� ������� ��������" << endl;
	cout << "-------------------------------------" << endl;
	init_arr(big_arr);
	unsigned int start_time;
	unsigned int end_time;
	unsigned int search_time; 
	start_time = clock(); 
	bubbleSort(big_arr, Big);
	end_time = clock(); 
	search_time = end_time - start_time; 
	std::cout << "bubbleSort = " << search_time<< endl; 

	init_arr(big_arr);
	start_time = clock();
	selectSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "selectSort = " << search_time << endl;

	init_arr(big_arr);
	start_time = clock();
	insertSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "insertSort = " << search_time << endl;

	init_arr(big_arr);
	start_time = clock();
	shellSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "shellSort = " << search_time << endl;

	init_arr(big_arr);
	start_time = clock();
	quickSort(big_arr, 0, Big-1);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "quickSort = " << search_time << endl;
	
	init_arr(big_arr);
	start_time = clock();
	heapSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "heapSort = " << search_time << endl;

	init_arr(big_arr);
	start_time = clock();
	mergeSort(big_arr, 0, Big-1);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "mergeSort = " << search_time << endl;

	cout << "C��������� ��������, ��������������� �� ��������" << endl;
	cout << "-------------------------------------" << endl;
	init_swap_arr(big_arr);
	start_time = clock();
	bubbleSort(big_arr, Big );
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "bubbleSort = " << search_time << endl;

	init_swap_arr(big_arr);
	start_time = clock();
	selectSort(big_arr,Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "selectSort = " << search_time << endl;

	init_swap_arr(big_arr);
	start_time = clock();
	insertSort(big_arr,Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "insertSort = " << search_time << endl;

	init_swap_arr(big_arr);
	start_time = clock();
	shellSort(big_arr,Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "shellSort = " << search_time << endl;

	init_swap_arr(big_arr);
	start_time = clock();
	quickSort(big_arr, 0, Big - 1);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "quickSort = " << search_time << endl;

	init_swap_arr(big_arr);
	start_time = clock();
	heapSort(big_arr,Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "heapSort = " << search_time << endl;

	init_swap_arr(big_arr);
	start_time = clock();
	mergeSort(big_arr, 0, Big - 1);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "mergeSort = " << search_time << endl;

	cout << "������������ ��������" << endl;
	cout << "-----------------------" << endl;

	init_other_arr(big_arr);
	start_time = clock();
	bubbleSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "bubbleSort = " << search_time << endl;

	init_other_arr(big_arr);
	start_time = clock();
	selectSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "selectSort = " << search_time << endl;

	init_other_arr(big_arr);
	start_time = clock();
	insertSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "insertSort = " << search_time << endl;

	init_other_arr(big_arr);
	start_time = clock();
	shellSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "shellSort = " << search_time << endl;

	init_other_arr(big_arr);
	start_time = clock();
	quickSort(big_arr, 0, Big - 1);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "quickSort = " << search_time << endl;

	init_other_arr(big_arr);
	start_time = clock();
	heapSort(big_arr, Big);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "heapSort = " << search_time << endl;

	init_other_arr(big_arr);
	start_time = clock();
	mergeSort(big_arr, 0, Big -1);
	end_time = clock();
	search_time = end_time - start_time;
	std::cout << "mergeSort = " << search_time << endl;
	return 0;
}
