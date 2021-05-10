#include "ppm_image.h"
#include <string>
#include <fstream>
#include<iostream>
#include<sstream>
#include <list>
#include <cmath>
#include <algorithm> 

using namespace agl;
using namespace std;

ppm_image::ppm_image()
{
    int allWidth = 0;
    int allHeight = 0;
    allPixels = nullptr;
}

ppm_image::ppm_image(int w, int h) 
{
    allWidth = w;
    allHeight = h;
    allPixels = new ppm_pixel * [allHeight];
    for (int f = 0; f <= h - 1; f++) {
        allPixels[f] = new ppm_pixel[allWidth];
    }

}

ppm_image::ppm_image(const ppm_image& orig)
{
    //allWidth = 0;
    //allHeight = 0;
    this->allHeight = orig.allHeight;
    this->allWidth = orig.allWidth;
    //std::list<list<ppm_pixel>> allPixels = { {} };
    for (int f = 0; f <= allHeight - 1; f++) {
        allPixels[f] = orig.allPixels[f];
    }
}

ppm_image& ppm_image::operator=(const ppm_image& orig)
{
   if (&orig == this) // protect against self-assignment
   {
      return *this;
   }
 //  std::list<list<ppm_pixel>> temp = allPixels;


  // for (int i = 0; i < width(); i++) {
   //    for (int j = 1; j < height(); j++) {
  //         ppm_pixel temp = allPixels[i][j];
  //         if (this->allPixels[i][j] == orig[i][j]) {

   //        }
   //    }
   // }
   this->allHeight = orig.allHeight;
   this->allWidth = orig.allWidth;
   //std::list<list<ppm_pixel>> allPixels = { {} };
   for (int f = 0; f <= allHeight - 1; f++) {
       allPixels[f] = orig.allPixels[f];
   }

   return *this;   
}

ppm_image::~ppm_image()
{
    int allWidth = 0;
    int allHeight = 0;
}

bool ppm_image::load(const std::string& filename)
{
    ifstream file(filename);
   // int width = 0;
    //int height = 0;
   // infile.open(filename.c_str());
    //cout << "filename" << filename << endl;
    string line;
  //  int lineNum = 0;
   // int columnNum = 0;
  //  int count = 0;
    int inputVal = 0;
    //check to see if we can even open the file:
    if (!file) {
        cout << "File not opening" << endl;
        return false;
    }
    file >> line;
    file >> inputVal;
    allWidth = inputVal;
    //generating the 2d structure in a way where I can individually address each pixel 
    for (int m = 0; m <= allHeight - 1; m++) {
        allPixels[m] = new ppm_pixel[allWidth];
    }
    file >> inputVal;
    allHeight = inputVal;
    //allPixels = new ppm_pixel**;
    //giving up on this structure and taking on the simpler input standard in the c++ documentation because of stoi errors that I couldnt fitgure out 
    /*  while (getline(infile, line)) {
        if (count < 2) {
            count++;
        }
        if (count = 2) {
            allWidth = stoi(line.substr(0, 1));
            allHeight = stoi(line.substr(1, 2));
           // ppm_pixel tempList[allWidth][allHeight];
            allPixels = new ppm_pixel*[allHeight];
            for (int i = 1; i <= allWidth - 1; i++) {
                allPixels[i] = new ppm_pixel[allWidth];
            }
            count++;

        }
        else {
            while (line.substr(0, 1) != " ") {
                int colors[3];
                stringstream str_strm;
                str_strm << line;
                string temp;
                int temp_int;
                int i = 0;
                while(!str_strm.eof()) {
                    str_strm >> temp;
                    if (stringstream(temp) >> temp_int) {
                        colors[i] = temp_int;
                        i++;
                    }
                }
                ppm_pixel thisPixel;
                thisPixel.r = colors[0];
                thisPixel.g = colors[1];
                thisPixel.b = colors[2];
                if (columnNum >= width()) {

                    lineNum++;
                }
                allPixels[lineNum][columnNum] = thisPixel;
                

            }
        }
    }
    */
    //while we are still in the file 
    while (file) {
        for (int k = 0; k <= allHeight - 1; k++) {
            for (int j = 0; j <= allWidth - 1; j++) {
                ppm_pixel currPixel = { 0, 0, 0 };
                file >> inputVal;
                //ppm pixels need unsigned chars so casting input ints into chars 
                currPixel.r = (unsigned char)inputVal;
                file >> inputVal;
                //ppm pixels need unsigned chars so casting input ints into chars 
                currPixel.g = (unsigned char)inputVal;
                file >> inputVal;
                //ppm pixels need unsigned chars so casting input ints into chars 
                currPixel.b = (unsigned char)inputVal;
                allPixels[k][j] = currPixel;
            }
        }
    }
   file.close();
   return false;
}

bool ppm_image::save(const std::string& filename) const
{
    //we are just gong to repeat the process above but in reverse 
    ofstream file(filename);
    if (!file) {
        cout << "File not opening" << endl;
        return false;
    }
    //for the unique ppm header 
    file << "P3 \n";
    file << allWidth;
    file << allHeight;
    file << "225 \n";

    //now we will interate through all the pixels to output them 
    for (int i = 0; i <= allHeight - 1; i++) {
        for (int j = 0; j <= allWidth - 1; j++) {
            file << allPixels[i][j].r;
            file << allPixels[i][j].g;
            file << allPixels[i][j].b;
        }
    }
    file.close();
    return false;
}

 ppm_image ppm_image::resize(int w, int h) const
{
    ppm_image result;
    return result;
}

ppm_image ppm_image::flip_horizontal() const
{
    ppm_image result;
    return result;
}

ppm_image ppm_image::subimage(int startx, int starty, int w, int h) const
{
    ppm_image result;
    return result;
}

void ppm_image::replace(const ppm_image& image, int startx, int starty)
{
}

ppm_image ppm_image::alpha_blend(const ppm_image& other, float alpha) const
{
   ppm_image result;
   return result;
}

ppm_image ppm_image::gammaCorrect(float gamma) const
{
   ppm_image result;
   return result;
}

ppm_image ppm_image::grayscale() const
{
   ppm_image result;
   return result;
}

ppm_pixel ppm_image::get(int row, int col) const
{
   
   ppm_pixel getting = allPixels[1][1];
   return getting;
}

void ppm_image::set(int row, int col, const ppm_pixel& c)
{

}
int ppm_image::height() const
{
   return allHeight;
}

int ppm_image::width() const
{
   return allWidth;
}
