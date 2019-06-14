#pragma once
#include "MyImage.h"




MyImage::MyImage()
{

	s = cv::Size(192, 108);
}

MyImage::MyImage(cv::Mat m)
{
	inputImage = m;
}

MyImage::MyImage(cv::String p)
{
	if (IsPathExist(p))
	{
		path = p;
		inputImage = cv::imread(path);
	}
	else
		std::cerr << "Wrong path! (Example: \"E:\\Folder1\\Folder2\\Folder3\\image.jpg\")\n";
}

void MyImage::SetPath(cv::String p)
{
	if (IsPathExist(p))
	{
		path = p;
		inputImage = cv::imread(path);
	}
	else
		std::cerr << "Wrong path! (Example: \"E:\\Folder1\\Folder2\\Folder3\\image.jpg\")\n";
}

void MyImage::SetImg(cv::Mat m)
{
	inputImage = m;
}

cv::Mat MyImage::GetThumbnail()
{
	if (thumbnail.empty()) {
		if (inputImage.empty()) {
			if (path == "") {
				std::cerr << "No image and no path!\n";
				throw;
			}
			else {
				inputImage = cv::imread(path);
			}
		}
	}
	cv::resize(inputImage, thumbnail, s);
	return thumbnail;
}

cv::Mat MyImage::GetThumbnail(cv::Size size)
{
	if (thumbnail.empty()) {
		if (inputImage.empty()) {
			if (path == "") {
				std::cerr << "No image and no path!\n";
				throw;
			}
			else {
				inputImage = cv::imread(path);
			}
		}
	}
	cv::resize(inputImage, thumbnail, size);
	return thumbnail;
}

void MyImage::ShowImage()
{
	if (inputImage.empty()) {
		std::cerr << "No image!\n";
		return;
	}

	cv::namedWindow("Show window", cv::WINDOW_AUTOSIZE);
	cv::imshow("Show window", inputImage);
	cv::waitKey(0);
}

void MyImage::ShowThumbnail()
{
	if (thumbnail.empty()) {
		std::cerr << "No thumbnail!\n";
		return;
	}

	cv::namedWindow("Show window", cv::WINDOW_AUTOSIZE);
	cv::imshow("Show window", thumbnail);
	cv::waitKey(0);
}


MyImage::~MyImage()
{
}
