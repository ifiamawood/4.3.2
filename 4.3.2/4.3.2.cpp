// 4.3.2.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<opencv.hpp>
#include<iostream>

using namespace cv;

int main() 
{
	cv::Mat out;
    cv:Mat src = imread("D:\\lena.jpg", 0);
	if (src.empty()) return -1;
	const cv::Point2f pts1[] = { cv::Point2f(150,150),cv::Point2f(150,300),cv::Point2f(350,300),cv::Point2f(350,150) };
	const cv::Point2f pts2[] = { cv::Point2f(200,150),cv::Point2f(200,300),cv::Point2f(340,270),cv::Point2f(340,180) };
	cv::Mat per = cv::getPerspectiveTransform(pts1, pts2);
	cv::warpPerspective(src, out, per, src.size());
	imshow("src", src);
	imshow("out", out);
	waitKey(0);
}

