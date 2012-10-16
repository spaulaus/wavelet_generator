#include <iostream>

#include "MotherWaveletGenerator.hpp"

int main(int argc, char* argv[]) {
   MotherWaveletGenerator mother;

   mother.SetWaveletType("mexicanhat");

   for(double i = -40; i < 40; i++)
      std::cout << i << " " << mother.GetValue(i, 10., 1.) << std::endl;
}
