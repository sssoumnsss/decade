#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//Ĭ�������nΪ����

int sort(int *a, int n)   //ð������
{
	int q, w;
	int t;
	for (q = 0;q < n;q++)
	{
		for (w = 0;w < n-1-q;w++)
		{
			if (a[w+1] < a[w])
			{
				t = a[w];
				a[w] = a[w+1];
				a[w+1] = t;
			}
		}
	}
	
	return a[(n-1) / 2];//�����м�ֵ
	
}


void M(Mat &img, Mat &dst, int n) //�Զ�����ֵ�˲�
{
	const int N = n * n;   //ȷ������Ԫ��
	int  i, j, x, y, z=0;
	int *a= new int[N], *b = new int[N], *c = new int[N];     //�������飬Ԫ�ظ���Ϊ����Ԫ�ظ���
	for (i = 0;i < img.cols;i++)
	{
		for (j = 0;j < img.rows;j++)
		{
			if ((i >= (n - 1) / 2) && ((i + (n - 1) / 2) < img.cols) && (j >= (n - 1) / 2) && ((j + (n - 1) / 2) < img.rows))//�������Ե
			{
				for (x = i - (n - 1) / 2;x <= i + (n - 1) / 2 ;x++)
				{
					for (y = j - (n - 1) / 2;y <= j + (n - 1) / 2;y++)
					{
						
						
						a[z] = img.at<Vec3b>(y, x)[0];
						b[z] = img.at<Vec3b>(y, x)[1];
						c[z] = img.at<Vec3b>(y, x)[2];
						z++;
						
						
					}
					
				}
				dst.at<Vec3b>(j, i)[0] = sort(a, N);
				dst.at<Vec3b>(j, i)[1] = sort(b, N);
				dst.at<Vec3b>(j, i)[2] = sort(c, N);
				z = 0;
				              //����Ԫ�����򣬷�����ֵ
			}
			else//��Ե���ظ�ֵ
			{
				dst.at<Vec3b>(j, i) = img.at<Vec3b>(j, i);
			}
		}
	}
	delete[] a;
	delete[] b;
	delete[] c;//�ͷ��ڴ�
}


int main()
{
	Mat img = imread("2.jpg"); //����luna
	Mat dst1;
	Mat dst2(img.size(),img.type());
    medianBlur(img, dst1 ,3);
	imshow("�Դ���ֵ�˲�", dst1);
	M(img, dst2,3);
	imshow("�Զ�����ֵ�˲�", dst2);
	
	waitKey(0);
	return 0;
}