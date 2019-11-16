
#include "pch.h"
#include <iostream>
using namespace std;

//排序合集，以int类型为例，可更换

class sort           
{
public:
	sort()
	{
		cout << "输入需要排序的个数：";
		cin>>n;
		a = new int[n];
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
	}
	void swap(int &x, int &y)   //交换位置
	{
		int t;
		t = x;
		x = y;
		y = t;
	}
	void getdata(int &y)
	{
		y = n;
	}
	void sorted1()                 //选择排序法:每次选择最小元素放在最前面。适用于数据规模比较小。
	{
		int min, i, j;
		for (i = 0;i < n - 1;i++)       								
		{
			min = i;
			for (j = i;j < n;j++)
			{
				if (a[j] < a[min])
					min = j;
			}
			if (a[i] != a[min])
			{
				swap(a[i], a[min]);
			}
		}
	}
	void sorted2()    //插入排序：每次循环找出数据正确的位置，适用于数据规模较小且数组基本有序
	{
		int i, j;
		for (i = 1;i < n;i++)
		{
			j = i;
			while (j > 0 && a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				j--;
			}
		}
	}
	void sorted3(int l,int r)   //快速排序：通常最好的应用选择(平均性能好)，每次选择一个基准元素，小于该元素放左边，递归重复直到需要划分的数组只有一个元素
	{
		if (l == r)
		{
			return;
		}
		int i = l, j = r, x = a[l];
		if (l < r)
		{
			
			while (i < j)
			{
				while (a[j] >= x && i<j)
				{
					j--;
				}
				if (i < j)
				{
					a[i] = a[j];
					i++;
				}
				while (a[i] < x&&i < j)
				{
					i++;
				}
				if (i < j)
				{
					a[j] = a[i];
					j--;
				}

			}
			a[i] = x;
			sorted3(l, i - 1);
			sorted3(i + 1, r);
		}
	}
	void sorted4(int *r,int start, int end)  //归并排序：分而治之，先让小部分有序，逐渐合并，但需要一个数组辅助用
	{
		if (start >= end)
		{
			return;
		}	
		int len = end - start, mid = len/2 + start;
		int start1 = start, end1 = mid;
		int start2 = mid + 1, end2 = end;
		sorted4(r, start1, end1);
		sorted4(r, start2, end2);
		int k = start;
		while (start1 <= end1 && start2 <= end2)
		{
			r[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
		}
		while (start1 <= end1)
		{
			r[k++] = a[start1++];
		}
		while (start2 <= end2)
		{
			r[k++] = a[start2++];
		}
		for (k = start;k <= end;k++)
		{
			a[k] = r[k];
		}
	}
	void usesorted4()
	{
		int *r = new int[n];
		sorted4(r, 0, n - 1);
		delete[] r;
	}
	void sorted5()//计数排序：适用于有具体范围且较小数据，如0~100。先找出最大最小的元素，统计每个值为i元素出现次数，
		          //存入数组C，对数组c所有计数累加，每一项和前一项相加，最后反向填充
	{
		int *b = new int[n], *c = new int[100];
		int i, j, k;
		for (k = 0;k < 100;k++)
		{
			c[k] = 0;
		}
		for (i = 0;i < n;i++)
		{
			c[a[i]]++;
		}
		for (k = 1;k < 100;k++)
		{
			c[k] += c[k - 1];
		}
		for (j = n;j > 0;j--)
		{
			b[--c[a[j - 1]]] = a[j - 1];
		}
		for (k = 0;k < n;k++)
		{
			a[k] = b[k];
		}
		delete[] c;
		delete[] b;
	}
	void sorted6()  //基数排序：比较位数大小
	{
		int i, *b = new int[n];
		int m = a[0], exp = 1;
		for (i = 1;i < n;i++)
		{
			if (a[i] > m)
				m = a[i];
		}
		while (m / exp > 0)
		{
			int bucket[10] = { 0 };
			for (i = 0;i < n;i++)
			{
				bucket[(a[i] / exp) % 10]++;
			}
			for (i = 1; i < 10; i++) 
			{
				bucket[i] += bucket[i - 1];
			}
			for (i = n - 1; i >= 0; i--) 
			{
				b[--bucket[(a[i] / exp) % 10]] = a[i];
			}

			for (i = 0; i < n; i++)
			{
				a[i] = b[i];
			}

			exp *= 10;
		}
		delete[] b;
			

	}
	~sort()
	{
		int i;
		cout << "排序结果:" << endl;
		for (i = 0;i < n;i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		delete[] a;
	}

private:
	int n;
	int *a;
};





int main()
{
	sort s;
	//s.sortsd1();
	//s.usesorted4();
	s.sorted6();
	return 0;
}


