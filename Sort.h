#pragma once
#include <iostream>
class stu_sort
{
public:
	// 冒泡
	void bubble_sort(int* data, int len);

	// 选择
	void selection_sort(int *data, int len);

	// 插入
	void insertion_sort(int *data, int len);

	// 希尔排序
	void shell_sort(int *data, int len);

	// 归并
	void merge_sort(int *data, int len);

	// 快速排序
	void quick_sort(int *data, int len);

	// 堆排序
	void heap_sort(int *data, int len);

	// 计数排序
	void counting_sort(int *data, int len);

	// 桶排序
	void bucker_sort(int *data, int len);

	// 基数排序
	void radix_sort(int *data, int len);

	void show(int *data, int len);
private:
	void merge_sort(int *data, int pos1, int pos2);
	void quick_sort(int *data, int pos1, int pos2);
	void heap_init(int *data, int len);
};
