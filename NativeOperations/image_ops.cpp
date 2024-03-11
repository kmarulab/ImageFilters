#include "image_ops.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
    // TODO: implement this function correctly
    return 3*width*y + x*3; // dummy value so that the code compiles at first
}

void noRed(int width, int height, int* ppm) {
  // TODO: this image transformation
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      ppm[pixelToIndex(width,j,i)] = 0;
    }
  }
}

void noGreen(int width, int height, int* ppm) {
    // TODO: this image transformation
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      ppm[pixelToIndex(width,j,i)+1] = 0;
    }
  }
}
void noBlue(int width, int height, int* ppm) {
    // TODO: this image transformation
  for(int i=2;i<width*height*3;i+=3){
    ppm[i] = 0;
  }
}
void invert(int width, int height, int* ppm) {
    // TODO: this image transformation
  for(int i=0;i<width*height*3;i++){
    int temp = ppm[i];
    ppm[i] =255-temp;
  }
}

void grayscale(int width, int height, int* ppm) {
    // TODO: this image transformation   
  for(int i=0;i<width*height*3;i+=3){
    int avg = (ppm[i]+ppm[i+1]+ppm[i+2])/3;
    ppm[i] = avg;
    ppm[i+1] = avg;
    ppm[i+2] = avg;
  }
}

void flipHorizontally(int width, int height, int *ppm){
    //use pixel to index
  for(int y = 0; y<height;y++){
    for(int x = 0;x<=width/2-1;x++){
      for(int pos=0;pos<3;pos++){
        int temp = ppm[pixelToIndex(width,x,y)+pos];
        ppm[pixelToIndex(width,x,y)+pos] = 
        ppm[(pixelToIndex(width,width-x-1,y)+pos)];

        ppm[(pixelToIndex(width,width-x-1,y)+pos)] = temp;
      }
    }
  }
}

void flipVertically(int width, int height, int *ppm){
  
  for(int x = 0; x<width;x++){
    for(int y = 0;y<height/2;y++){
      for(int pos= 0; pos<3;pos++){
        //initialize variable to temporarily store the initial value
        int temp = ppm[pixelToIndex(width,x,y)+pos];
        ppm[pixelToIndex(width,x,y)+pos] = 
        ppm[(pixelToIndex(width,x,height-y-1)+pos)];

        ppm[(pixelToIndex(width,x,height-y-1)+pos)] = temp;
      }
    }
  }
}