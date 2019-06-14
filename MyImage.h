#pragma once
#include "headers.h"

class MyImage
{
private:
	cv::Mat inputImage;
	cv::Mat thumbnail;
	cv::String path;

	cv::Size s;	//Default sizes

public:
	MyImage();
	MyImage(cv::Mat);	//inputImage
	MyImage(cv::String);	//path

	void SetPath(cv::String);
	void SetImg(cv::Mat);

	cv::Mat GetThumbnail();
	cv::Mat GetThumbnail(cv::Size);

	void ShowImage();
	void ShowThumbnail();

	~MyImage();
};

