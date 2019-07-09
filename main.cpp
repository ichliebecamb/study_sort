#include "Sort.h"

int main()
{
	int data[] = { 100, 90, 80, 70, 60, 50, 40, 30 ,20 ,10};
	stu_sort test;
	test.counting_sort(data, 10);
	test.show(data, 10);
	return 0;
}
