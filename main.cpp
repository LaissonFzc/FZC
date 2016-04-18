#include <opencv2\opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
 
/*
 int main()
	 {
		    Mat img1 = imread("lv.jpg"),img2;
			//Mat d = img.clone();
			//Mat e ;
		     if(img1.empty())
			     {
				         cout<<"error";
				         return -1;
				 }
			 cvtColor(img1,img2,COLOR_BGR2Lab);
			 //d.copyTo(e);
		     imshow("xx������",img2);
			 //imshow("aa", d);
			 //imshow("bb", e);
			 waitKey();
		 
			     return 0;
		 }
*/	

int main()
{
	Mat src = imread("dx.jpg");
	Mat src1 = src.clone();
	imshow("��src1��",src1);

	imshow("��ԭʼͼ��", src);
	Mat dst , edge, gray;

	dst.create(src1.size(), src1.type() );//����һ����ԭͼ���ʹ�С��ͬ��Ŀ���ļ�
	imshow("��dsst-1��",dst);
	
	cvtColor(src1, gray, COLOR_BGR2GRAY);//��ԭͼת�ɻҶ�ͼ
	imshow("��gray-1��",gray);
	
	blur(gray, edge, Size(3,3));//ʹ�� ��ֵ�˲� ���н���
	imshow("��edge-1��",edge);
	
	Canny(edge, edge, 3, 9, 3);//���� canny���� ���Ե
	imshow("��edge-2��",edge);

	dst = Scalar::all(0);//  ��Ŀ��Ԫ�� �������ص���ɫ��Ϊ ��ɫ
	imshow("��dsst-2��",dst);
	
	src1.copyTo(dst, edge);//  ��canny���õ��ı�Ե��Ϊ���룬��ԭͼ������Ŀ��ͼ�ϣ��õ���ɫ��Եͼ
	imshow("��dsst-3��",dst);

	waitKey(0);
	return 0;
	
}



/*

Mat g_srcimg , g_dstimg;
int g_elementShape = MORPH_RECT;

int g_nmaxiterationNum = 10;
int g_nopenclosenNum = 0;
int g_nerodedilateNum = 0;
int g_ntopblackhatNum = 0;
 static void on_Openclose(int ,void*);
 static void on_Erodedilate(int , void*);
 static void on_Topblackhat(int , void*);
 static void on_Showhelptext(int , void*);

int main()
{
	g_srcimg = imread("lv.jpg");
	imshow("��ԭʼͼ��" ,g_srcimg);

	namedWindow("��������/�����͡�",1);
	namedWindow("����ʴ/��",1);
	namedWindow("����ñ/��ñ��",1);

	g_nopenclosenNum = 9;
	g_nerodedilateNum = 9;
	g_ntopblackhatNum = 2;
	createTrackbar("����ֵ", "��������/�����͡�", &g_nmaxiterationNum, g_nmaxiterationNum*2+1, on_Openclose);
	createTrackbar("����ֵ", "����ʴ/��", &g_nerodedilateNum, g_nmaxiterationNum*2+1, on_Erodedilate);
	createTrackbar("����ֵ", "����ñ/��ñ��", &g_ntopblackhatNum, g_nmaxiterationNum*2+1, on_Topblackhat);

	on_Openclose(g_nopenclosenNum,0);
	on_Erodedilate(g_nerodedilateNum,0);
	on_Topblackhat(g_ntopblackhatNum,0);

	waitKey(0);
	return 0;
}

static void on_Openclose(int ,void*)
{

		int offset = g_nopenclosenNum - g_nmaxiterationNum;
		int Absolute_offset = offset > 0 ? offset : -offset;
		Mat element = getStructuringElement(g_elementShape, Size(Absolute_offset*2+1,Absolute_offset*2+1), Point(Absolute_offset,Absolute_offset));

		if (offset < 0)
			morphologyEx(g_srcimg, g_dstimg, MORPH_OPEN, element);
		else
			morphologyEx(g_srcimg, g_dstimg, MORPH_CLOSE, element);
		imshow("��������/�����͡�", g_dstimg);
		
}

static void on_Erodedilate(int ,void*)
{

	int offset = g_nopenclosenNum - g_nmaxiterationNum;
	int Absolute_offset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(g_elementShape, Size(Absolute_offset*2+1,Absolute_offset*2+1), Point(Absolute_offset,Absolute_offset));

	if (offset < 0)
		//morphologyEx(g_srcimg, g_dstimg, MORPH_ERODE, element);
		erode(g_srcimg, g_dstimg, element);
	else
		//morphologyEx(g_srcimg, g_dstimg, MORPH_DILATE, element);
		dilate(g_srcimg, g_dstimg, element);
	imshow("����ʴ/��", g_dstimg);
	
}

static void on_Topblackhat(int ,void*)
{

	int offset = g_nopenclosenNum - g_nmaxiterationNum;
	int Absolute_offset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(g_elementShape, Size(Absolute_offset*2+1,Absolute_offset*2+1), Point(Absolute_offset,Absolute_offset));

	if (offset < 0)
		morphologyEx(g_srcimg, g_dstimg, MORPH_TOPHAT, element);	
	else
		morphologyEx(g_srcimg, g_dstimg, MORPH_BLACKHAT, element);
	imshow("����ñ/��ñ��", g_dstimg);
}


*/
/*
void main()
{
	Mat img1 = imread("dx.jpg");
	//Mat img2 = imread("lv.jpg");
	//Mat Roi = img1(Rect(200, 250, img2.cols, img2.rows));
	//Mat mask = imread("img2");

	//img2.copyTo(Roi, mask);
	//namedWindow("aa");
	//imshow("aa",Roi);
 	
	
	imshow("��ԭͼ��",img1);
	
	
	Mat out1, out2, out3,out4;
	
	out2 = getStructuringElement(MORPH_RECT,Size(10,10));
	out1= dilate(erode(img1, out2));
	out3 = getStructuringElement(MORPH_RECT,Size(5,5));
	out4 = erode(dilate(img1, out2));
	//bilateralFilter(img1,out1,25,25*2,25/2);
	imshow("������ͼ1��",out1);
	imshow("������ͼ2��",out4);
	//bilateralFilter(img1,out2,25,25,50);
	//imshow("������ͼ2��",out2);
	
	//GaussianBlur(img1, out3, Size(3, 3), 0, 0);
	//imshow("������ͼ3��",out3);

	waitKey();
}
*/
/*
#define WINDOW_NAME "���Ի��ʵ��"

const int g_nMaxAlphaValue = 100;
int g_nAlphValueSlider;
double g_aAlphaValue;
double g_dBateValue;

Mat img1,img2,img3;

void on_Trackbar(int ,void* )
{
	g_aAlphaValue = (double) g_nAlphValueSlider/g_nMaxAlphaValue;
	g_dBateValue =(1.0 - g_aAlphaValue);
	addWeighted(img1, g_aAlphaValue, img2, g_dBateValue, 0.0, img3);
	imshow(WINDOW_NAME, img3);
}

int main()
{
	img1 = imread("lv.jpg");
	img2 = imread("lb.jpg");
	if (!img1.data)
	{
		printf("��һ��ͼ�д�");
			return -1;
	}
	if (!img2.data)
	{
		printf("�ڶ���ͼ�д�");
			return -1;
	}

	g_nAlphValueSlider = 70;
	namedWindow(WINDOW_NAME, 1);

	char TrackbarName[50];
	sprintf(TrackbarName, "͸����ֵ%d",g_aAlphaValue);
	on_Trackbar(g_nAlphValueSlider,0);
	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphValueSlider, g_nMaxAlphaValue, on_Trackbar);
	
	waitKey();
	return 0;
}
*/
