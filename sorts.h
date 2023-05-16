#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <time.h>
#include <chrono>
#include <fstream>
#include <stdio.h>
#include <string>

void Heapify(int* arr, int b, int i);
void Merge(int* arr, int l, int m, int r);
int ModifiedPartition(int* arr, int last, int first);
int Partition(int* arr, int first, int last);
int GetMax(int* arr, int siz);

void InsertionSort(int* arr, int left, int right);
void TimSort(int* arr, int len);
void BubbleSort(int* arr, int len);
void ModifiedQuicksort(int* arr, int low, int high);
void QuickSort(int* arr, int last, int first);
void SelectionSort(int* arr, int size);
void CountingSort(int* arr, int len);
void MergeSort(int* arr, int right, int left);
void ShellSort(int* arr, int len);
void GnomeSort(int* arr, int len);
void HeapSort(int* arr, int len);

void insertionSort(int* arr, int len);
void modifiedQuicksort(int* arr, int len);
void quickSort(int* arr, int len);
void mergeSort(int* arr, int len);

int GetRandomNumber(int min, int max);
void MashUp(int* arr, int len);
void Sort(int index, int* arr, int len);
void ResPrep();
void Test();

