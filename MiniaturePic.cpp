// MiniaturePic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "headers.h"
#include "MyImage.h"
int main()
{
	MyImage obj;
	cv::String p;
	unsigned int w, h;
	//for filename
	time_t t;
	tm timeinfo;
	char buff[256];

	std::cout << "Picture path (example: \"E:\\Folder1\\image.jpg\") ->";
	std::getline(std::cin, p);
	std::cout << "Output sizes (width, hight) ->";
	std::cin >> w >> h;

	obj.SetPath(p);

	t = time(NULL);
	localtime_s(&timeinfo, &t);
	strftime(buff, 256, "Thumbnail(%Y-%m-%d_%H-%M-%S).bmp", &timeinfo);
	
	cv::imwrite(buff, obj.GetThumbnail(cv::Size(w, h)));

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
