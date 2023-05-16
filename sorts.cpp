#include "sorts.h"
using namespace std;

FILE* fLog = fopen("test1.txt", "a");
void (*funcAr[11])(int*, int) = {
	insertionSort,
	TimSort,
	BubbleSort,
	modifiedQuicksort,
	quickSort,
	SelectionSort,
	CountingSort,
	mergeSort,
	ShellSort,
	GnomeSort,
	HeapSort };

//ANIIIIAAOAEUIUA OOIEOEE

void insertionSort(int* arr, int leng) {
	InsertionSort(arr, 0, leng - 1);
}

void modifiedQuicksort(int* arr, int leng) {
	ModifiedQuicksort(arr, 0, leng - 1);
}
void quickSort(int* arr, int leng) {
	QuickSort(arr, leng - 1, 0);
}

void mergeSort(int* arr, int leng) {
	MergeSort(arr, leng - 1, 0);
}

void Heapify(int* arr, int b, int i) {
	int long_leng = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < b && arr[l] > arr[long_leng])
		long_leng = l;

	if (r < b && arr[r] > arr[long_leng])
		long_leng = r;

	if (long_leng != i) {
		swap(arr[i], arr[long_leng]);
		Heapify(arr, b, long_leng);
	}
}

void Merge(int* arr, int l, int m, int r) {
	int leng1 = m - l + 1, leng2 = r - m;
	int* left = new int[leng1];
	int* right = new int[leng2];
	for (int i = 0; i < leng1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < leng2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int q = l;

	while (i < leng1 && j < leng2) {
		if (left[i] <= right[j]) {
			arr[q] = left[i];
			i++;
		}
		else {
			arr[q] = right[j];
			j++;
		}
		q++;
	}

	while (i < leng1) {
		arr[q] = left[i];
		q++;
		i++;
	}

	while (j < leng2) {
		arr[q] = right[j];
		q++;
		j++;
	}
	delete[] left;
	delete[] right;
}

int ModifiedPartition(int* arr, int last, int first) {
	int piv = arr[first];
	int Index = last;
	for (int i = last; i < first; i++) {
		if (arr[i] <= piv) {
			swap(arr[i], arr[Index]);
			Index++;
		}
	}
	swap(arr[Index], arr[first]);
	return Index;
}

int Partition(int* arr, int first, int last) {
	int piv = arr[(first + last) / 2];
	int i = first, j = last;
	while (true) {
		while (arr[i] < piv)
			i++;
		while (arr[j] > piv)
			j--;
		if (i >= j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	return j;
}

int GetMax(int* arr, int siz) {
	int max = 0;
	int i = 1;
	while (i < siz) {
		if (arr[max] < arr[i])
			max = i;
		i++;
	}
	return max;
}

//OOIEOEE NI?OE?IAIE

void InsertionSort(int* arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int p = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > p) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = p;
	}
}

void TimSort(int* arr, int len)
{
	for (int i = 0; i < len; i += 32)
		InsertionSort(arr, i, min((i + 32 - 1), (len - 1)));
	for (int size = 32; size < len; size = 2 * size) {
		for (int left = 0; left < len; left += 2 * size) {
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (len - 1));
			if (mid < right)
				Merge(arr, left, mid, right);
		}
	}
}

void BubbleSort(int* arr, int len) {
	for (int k = len - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}

void ModifiedQuicksort(int* arr, int low, int high) {
	while (low < high) {
		if (high - low < 10) {
			InsertionSort(arr, low, high);
			break;
		}
		else {
			int pivot = ModifiedPartition(arr, low, high);
			if (pivot - low < high - pivot) {
				ModifiedQuicksort(arr, low, pivot - 1);
				low = pivot + 1;
			}
			else {
				ModifiedQuicksort(arr, pivot + 1, high);
				high = pivot - 1;
			}
		}
	}
}

void QuickSort(int* arr, int last, int first) {
	if (first < last) {
		int p = Partition(arr, first, last);
		QuickSort(arr, p, first);
		QuickSort(arr, last, p + 1);
	}
}

void SelectionSort(int* arr, int size) {
	while (size) {
		int indMax = GetMax(&arr[0], size);
		swap(arr[indMax], arr[size - 1]);
		size--;
	}
}

void CountingSort(int* arr, int len) {
	int i, max = -1;
	int* chek;
	for (i = 0; i < len; i++)
		if (abs(arr[i]) > max)
			max = abs(arr[i]);
	chek = new int[max * 2 + 1];
	for (i = 0; i < max * 2 + 1; i++)
		chek[i] = 0;
	for (i = 0; i < len; i++)
		chek[arr[i] + max]++;
	for (int i = 0, j, k = 0; i < max * 2 + 1; i++) {
		if (chek[i] > 0) {
			j = chek[i];
			for (; j > 0; j--) {
				arr[k] = i - max;
				k++;
			}
		}
	}
	delete[] chek;
}

void MergeSort(int* arr, int right, int left) {
	if (left < right)
		if (right - left == 1) {
			if (arr[right] < arr[left]) {
				swap(arr[right], arr[left]);
			}
		}
		else {
			MergeSort(arr, left + (right - left) / 2, left);
			MergeSort(arr, right, left + (right - left) / 2 + 1);
			Merge(arr, left, left + (right - left) / 2, right);
		}
}

void ShellSort(int* arr, int len) {
	for (int r = len / 2; r > 0; r /= 2)
		for (int i = r; i < len; i += r)
			for (int j = i; j > 0; j -= r)
				if (arr[j] < arr[j - r])
					swap(arr[j], arr[j - r]);
}

void GnomeSort(int* arr, int len) {
	for (int i = 0; i < len;) {
		if (i == 0)
			i++;
		if (arr[i] >= arr[i - 1])
			i++;
		else {
			swap(arr[i], arr[i - 1]);
			i--;
		}
	}
}

void HeapSort(int* arr, int len) {
	for (int i = len / 2 - 1; i >= 0; i--)
		Heapify(arr, len, i);
	for (int i = len - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

//I?I?EA OOIEOEE

int GetRandomNumber(int min, int max) {
	int num = min + rand() % (max - min + 1);
	return num;
}

void MashUp(int* arr, int len) {
	for (int i = 0; i < len; i++)
		arr[i] = GetRandomNumber(-1000, 1000);
}

void Sort(int index, int* arr, int len) {
	funcAr[index](arr, len);
}

void ResPrep() {
	cout << "Progress:" << endl;
	fprintf(fLog, "%10s", "\0");
	fprintf(fLog, "%10s", "Insertion");
	fprintf(fLog, "%10s", "Tim");
	fprintf(fLog, "%10s", "Bubble");
	fprintf(fLog, "%10s", "ModQuick");
	fprintf(fLog, "%10s", "Quick");
	fprintf(fLog, "%10s", "Selection");
	fprintf(fLog, "%10s", "Counting");
	fprintf(fLog, "%10s", "Merge");
	fprintf(fLog, "%10s", "Shell");
	fprintf(fLog, "%10s", "Gnome");
	fprintf(fLog, "%10s", "Heap");
}

void Test() {
	ResPrep();
	srand(static_cast<unsigned int>(time(NULL)));
	int* arr = new int[10000000];
	int* functuinOut = new int[11];
	for (int i = 0; i < 11; i++) {
		functuinOut[i] = 0;
	}
	for (int len = 100, step = 100, chek = 1;; len += step, chek++) {
		if (len == 1000) {
			step = 250;
			cout << "0%" << endl;
		}
		if (len == 5000) {
			step = 500;
		}
		if (len == 10000) {
			step = 1000;
			cout << "10%" << endl;
		}
		if (len == 40000) {
			step = 10000;
			cout << "15%" << endl;
		}
		if (len == 200000) {
			step = 50000;
			cout << "30%" << endl;
		}
		if (len == 500000) {
			step = 100000;
			cout << "50%" << endl;
		}
		if (len == 3000000) {
			step = 1000000;
			cout << "70%" << endl;
		}
		if (len > 10000000) {
			cout << "100%" << endl;
			break;
		}
		fprintf(fLog, "\n");
		fprintf(fLog, "%10d", len);

		for (int i = 0; i < 11; i++) {
			for (int j = 0; functuinOut[i] == 0 && j < 21; j++) {
				int times[21];
				MashUp(arr, len);
				auto begin = std::chrono::steady_clock::now();
				Sort(i, arr, len);
				auto end = std::chrono::steady_clock::now();
				auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
				int Time = elapsed_ms.count();
				if (Time > 2000) {
					functuinOut[i] = 1;
					break;
				}
				times[j] = Time;
				if (j == 20) {
					BubbleSort(times, 21);
					Time = (times[7] + times[8] + times[9] + times[10] + times[11] + times[12] + times[13]) / 7;
					fprintf(fLog, "%10d", Time);
				}
			}
			if (functuinOut[i] == 1) {
				fprintf(fLog, "%10s", "STOPPED");
			}
		}
	}
	delete[] arr;
	fclose(fLog);
}

