#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>  
#include <stdio.h>  
#include<iostream>
#include<vector>
using namespace std;
int getmid(vector<int>& vec, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (vec[mid] > vec[left])
	{
		if (vec[mid] < vec[right]) return mid;
		if (vec[left] > vec[right]) return left;
		else return right;
	}
	if (vec[right] < vec[mid]) return mid;
	if (vec[right] > vec[right]) return left;
	return right;
}
int QuitSortPocess(vector<int>& vec, int left, int right)
{
	int mid = getmid(vec, left, right);
	swap(vec[mid], vec[left]);
	int tmp = vec[left];
	while (left < right)
	{
		while (left < right&&vec[right] >= tmp)
		{
			right--;
		}
		vec[left] = vec[right];
		while (left < right&&vec[left] <= tmp)
		{
			left++;
		}
		vec[right] = vec[left];
	}
	vec[left] = tmp;
	return left;
}
void QuitSort(vector<int>& vec, int left, int right)
{
	if (left >= right) return;
	int index = QuitSortPocess(vec, left, right);
	QuitSort(vec, left, index - 1);
	QuitSort(vec, index + 1, right);
}



int main()
{
	vector<int> vec = { 5, 6, 3, 1, 2 };
	QuitSort(vec, 0, vec.size() - 1);
	for (auto &ch : vec)
	{
		cout << ch << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}