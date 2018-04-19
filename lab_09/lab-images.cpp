/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab 09

Image processing
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width, string file) {
	ofstream ostr;
	ostr.open(file);
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}


void invert(int image[MAX_H][MAX_W], int &h, int &w){
	int out[MAX_H][MAX_W];
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row][col] = 255 - image[row][col];
		}
	}
	writeImage(out, h, w, "task-a.pgm");
}

void invert_half(int image[MAX_H][MAX_W], int &h, int &w){
	int out[MAX_H][MAX_W];
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			if(col > w/2){
				out[row][col] = 255 - image[row][col];
			}
			else{
				out[row][col] = image[row][col];
			}
		}
	}
	writeImage(out, h, w, "task-b.pgm");
}

void box(int image[MAX_H][MAX_W], int &h, int &w){
	int out[MAX_H][MAX_W];
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			if(col > w/4 && col < w - w/4  && row > h/4 && row < h - h/4){
				out[row][col] = 255;
			}
			else{
				out[row][col] = image[row][col];
			}
		}
	}
	writeImage(out, h, w, "task-c.pgm");
}

void frame(int image[MAX_H][MAX_W], int &h, int &w){
	int out[MAX_H][MAX_W];
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row][col] = image[row][col];
		}
	}
	for(int col = w/4; col < w-w/4; col++){
		out[h/4][col] = 255;
	}
	for(int col = w/4; col < w-w/4; col++){
		out[h-h/4][col] = 255;
	}
	for(int row = h/4; row < h-h/4; row++){
		out[row][w/4] = 255;
	}
	for(int row = h/4; row < h-h/4; row++){
		out[row][w-w/4] = 255;
	}
	writeImage(out, h, w, "task-d.pgm");
}

void scale(int image[MAX_H][MAX_W], int &h, int &w){
	int out[MAX_H][MAX_W];
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row*2][col*2] = image[row][col];
			out[row*2+1][col*2] = image[row][col];
			out[row*2][col*2+1] = image[row][col];
			out[row*2+1][col*2+1] = image[row][col];
		}
	}
	writeImage(out, h*2, w*2, "task-e.pgm");
}

void pixelate(int image[MAX_H][MAX_W], int &h, int &w){
	int out[MAX_H][MAX_W];
	for(int row = 0; row < h; row+=2) {
		for(int col = 0; col < w; col+=2) {
			int sum = 0;
			sum += image[row][col];
			sum += image[row+1][col];
			sum += image[row][col+1];
			sum += image[row+1][col+1];
			int avg = sum/4;
			out[row][col] = avg;
			out[row+1][col] = avg;
			out[row][col+1] = avg;
			out[row+1][col+1] = avg;
		}
	}
	writeImage(out, h, w, "task-f.pgm");
}
