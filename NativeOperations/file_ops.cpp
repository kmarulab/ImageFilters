#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include "image_ops.h"
#include "file_ops.h"
using namespace std;


int ppm_read_number(string filename, int index) {
    ifstream file;
    file.exceptions(iostream::failbit | iostream::badbit);
    file.open(filename);

    string s;
    file >> s;
    if (s != "P3") {
        throw runtime_error("Input file is not a P3 PPM file.");
    }

    int dim;
    for (int i = 0; i < index; i++) {
        file >> dim; // skip these numbers
    }
    file >> dim; // use this number
    file.close();
    return dim;
}

int ppm_width(string filename) {
    return ppm_read_number(filename, 0);
}

int ppm_height(string filename) {
    return ppm_read_number(filename, 1);
}

int* read_ppm(string filename) {
    ifstream file;
    file.exceptions(iostream::failbit | iostream::badbit);
    file.open(filename);

    string s;
    file >> s;
    if (s != "P3") {
        throw runtime_error("Input file is not a P3 PPM file.");
    }
    int width;
    file >> width;
    int height;
    file >> height;

    int ppmSize = width * height * 3;
    int* ppm = new int[ppmSize];

    file >> s;
    if (s != "255") {
        throw runtime_error("Input file does not contain 8-bit pixel samples.");
    }

    for (int i = 0; i < width * height * 3; i++) {
        file >> ppm[i];
    }
    file.close();

    return ppm;
}

void write_ppm(string filename, int width, int height, int* ppm) {
    ofstream file;
    file.exceptions(iostream::failbit | iostream::badbit);
    file.open(filename);

    file << "P3" << "\n";
    file << width << " " << height << "\n";
    file << "255" << "\n";
    for (int i = 0; i < width * height * 3; i++) {
        file << ppm[i] << "\n";
    }

    file.close();
}
