// Author   : Gabriel Duarte
// Date     : 01/30/2018
// Lab #    : 02 exercise 1
// Description : We are making a check board.

// Include the library
#include "EasyBMP.h"

using namespace std;

int main()
{
  // Create an image
  BMP AnImage;

  // Set the image size
  AnImage.SetSize(256,256);
  // Set the bit depth
  AnImage.SetBitDepth(8);

  // The for loop for the rows
  for (int i = 0; i < 256; ++i)
    { // The for loop for the cols
      for (int j = 0; j < 256; ++j)
	{
	  // Make it a red square
	  if ((i/32)%2 == 0 && (j/32)%2 == 0)
	    {
	      AnImage (i,j)->Red = 255;
	      AnImage (i,j)->Green = 0;
	      AnImage (i,j)->Blue = 0;
	    }
	  else  if ((j/32)%2 == 1 && (i/32)%2 == 1)
	    {
	      AnImage (i,j)->Red = 255;
	      AnImage (i,j)->Green = 0;
	      AnImage (i,j)->Blue = 0;
	    }

	  // Make it a black square
	  else
	    {
	      AnImage (i,j)->Red = 0;
	      AnImage (i,j)->Green = 0;
	      AnImage (i,j)->Blue = 0;
	    }	  
	}
    }

  // Output the image to a "file" 
  AnImage.WriteToFile("board.bmp");

  return 0;
}
