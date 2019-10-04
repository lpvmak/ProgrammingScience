#include <iostream>
#include "png_toolkit.h"

void fillRed(png_toolkit &studTool)
{
	image_data img = studTool.getPixelData();
	int lineSize = img.w * img.compPerPixel;
	for (int i = img.h/2; i < img.h; i++)
	{
		for (int j = 0; j < lineSize; j+=img.compPerPixel)
		{
			for (int k = 0; k < img.compPerPixel; k++)
			{
				if (k == 0)
					img.pixels[j + k + i * lineSize] = (unsigned char)255;
				else
					img.pixels[j + k + i * lineSize] = (unsigned char)0;
			}
		}
	}
}


int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
       if (argc != 3)
           throw "Not enough arguments";

        png_toolkit studTool;
        studTool.load(argv[1]);
		fillRed(studTool);
        studTool.save(argv[2]);

    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
