#include "Sort.h"
#include <vector>

void swap(int* data1, int* data2)
{
	int tem = *data1;
	*data1 = *data2;
	*data2 = tem;
}

// 冒泡
void stu_sort::bubble_sort(int* data, int len)
{
	if( nullptr == data || len < 0 ) return;

	for(int i = 0; i < len; i++ )
	{
		for(int j = 0; j < len - 1 - i ; j++)
		{
			if( data[j] > data[j + 1])
			{
				swap( data + j, data + j + 1);
			}
		}
	}
}

// 选择
void stu_sort::selection_sort(int *data, int len)
{
	if( nullptr == data || len < 0 ) return;

	int minpos;
	for(int i = 0; i < len; i++)
	{
		minpos = i;
		for(int j = i + 1; j < len; j++)
		{
			if( data[minpos] > data[j])
			{
				minpos = j;
			}
		}
		if( minpos == i ) 
		{
			continue;
		}
		else
		{
			swap(data + i, data + minpos);
		}
	}
}

// 插入
void stu_sort::insertion_sort(int *data, int len)
{
	if( nullptr == data || len < 0 ) return;
	int tem , j;
	for(int i = 1; i < len; i++)
	{
		tem = data[i];
		j = i;
		for(; j > 0 ; j--)
		{
			if( tem < data[j - 1] )
			{
				data[j] = data[j-1];
			}
			else
			{
				break;
			}
		}
		data[j] = tem;
	}

}

// 希尔排序
void stu_sort::shell_sort(int *data, int len)
{}

// 归并
void stu_sort::merge_sort(int *data, int len)
{
	if( nullptr == data || len < 0 ) return;
	merge_sort(data, 0, len-1);

}

void stu_sort::merge_sort(int *data, int pos1, int pos2)
{
	if( pos1 >= pos2 ) return;
	if( pos2 - pos1 == 1)
	{
		if( data[ pos1] > data[pos2])
		{
			swap(data+pos1, data+pos2);
		}
		return;
	}

	merge_sort(data, pos1, (pos1 + pos2)/2 );
	merge_sort(data, (pos1 + pos2)/2 + 1, pos2);

	int i = pos1,j = (pos1 + pos2)/2 + 1;
	int pos = 0;
	int *tem = new int[pos2 - pos1 + 1];
	while( i <= (pos1 + pos2)/2 && j <= pos2)
	{
		if( data[ i ] <= data[ j ] )
		{
			tem[pos++] = data[i++];
		}
		else
		{
			tem[pos++] = data[j++];
		}
	}

	while( i <= ( pos1 + pos2 ) /2 )
	{
		tem[pos++] = data[i++];
	}

	while( j <= pos2 )
	{
		tem[pos++] = data[j++];
	}

	for( i = pos1, j = 0; i <= pos2; i++, j++)
	{
		data[i] = tem[j];
	}
	delete[] tem;
}


// 快速排序
void stu_sort::quick_sort(int *data, int len)
{
	if( nullptr == data || len < 0 ) return;
	quick_sort(data, 0, len-1);
}

void stu_sort::quick_sort(int *data, int pos1, int pos2)
{
	if( pos1 >= pos2 ) return;
	if( pos2 - pos1 == 1)
	{
		if( data[ pos1] > data[pos2])
		{
			swap(data+pos1, data+pos2);
		}
		return;
	}

	std::vector<int> data1,data2;
	int pivot = data[pos1];

	for(int i = pos1 + 1; i <= pos2; i++)
	{
		if( data[i] < pivot )
		{
			data1.push_back(data[i]);
		}
		else
		{
			data2.push_back(data[i]);
		}
	}
	int pos_pi = data1.size() + pos1;
	for(int i = pos1; i < pos_pi; i++)
	{
		data[i] = data1[i];
	}
	data[pos_pi] = pivot;
	for( int i = 0; i < data2.size(); i++)
	{
		data[pos_pi + 1 + i] = data2[i];
	}

	quick_sort(data, pos1, pos1+pos_pi-1);
	quick_sort(data, pos1+pos_pi+1,   pos2);

}


// 堆排序
void stu_sort::heap_sort(int *data, int len)
{}

// 计数排序
void stu_sort::counting_sort(int *data, int len)
{}

// 桶排序
void stu_sort::bucker_sort(int *data, int len)
{}

// 基数排序
void stu_sort::radix_sort(int *data, int len)
{}

void stu_sort::show(int *data, int len)
{
	if( nullptr != data && len > -1 )
	{
		for(int i = 0; i < len; i++)
		{
			std::cout << data[i] << " ";
		}
	}
	std::cout << std::endl;
}

