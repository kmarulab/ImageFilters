#include <iostream>
#include <string>

#include "image_ops.h"
#include "file_ops.h"

using namespace std;

int main(int argc, char** argv) {
    string file_name, instruction, new_image;
  
   if (argc==4){
        file_name = argv[1];
        instruction = argv[2];
        new_image = argv[3];
   } else if (argc<4){
    cout<<"Too few arguments."<<endl;
	cout<<"Usage: ./main <path to file> <filter> <new file name>"<<endl;
   } else{
    cout<<"Too many arguments"<<endl;
	cout<<"Usage: ./main <path to file> <filter> <new file name>"<<endl;
   }

  int *image = read_ppm(file_name);

  int width = ppm_width(file_name);
  int height = ppm_height(file_name);

  if(instruction=="noRed"){
    noRed(width, height, image);
  } else if(instruction=="noGreen"){
    noGreen(width, height, image);
  } else if(instruction=="noBlue"){
    noBlue(width, height, image);
  } else if(instruction=="invert"){
    invert(width, height, image);
  }  else if(instruction=="grayscale"){
    grayscale(width, height, image);
  } else if(instruction=="flipHorizontally"){
    flipHorizontally(width, height, image);
  }  else if(instruction=="flipVertically"){
    flipVertically(width, height,image);
  }
  else {
    cout<<"wrong instruction given"<<endl;
	cout<<"Usage: ./main <path to file> <filter> <new file name>"<<endl;
  }
  write_ppm(new_image, width, height, image);

  delete [] image;
  return 0;
}
