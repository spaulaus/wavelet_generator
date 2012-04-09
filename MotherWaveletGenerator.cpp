/*
 * Copyright S.V. Paulauskas 2012
 * stanpaulauskas@gmail.com 
 * Distributed under GNU General Public Licence v3
 */

/**
 * \file MotherWaveletGenerator.cpp
 * Class that can be used to generate mother wavelets for various types of
 * transformations. At the moment it simply returns values, but that might 
 * change sometime in the future.
 *
 * \author S.V. Paulauskas
 * \date 07 April 2012
 */
#include <iostream>
#include <limits>
#include <vector>

#include <cmath>

#include "MotherWaveletGenerator.hpp"

using namespace std;

//********** GetValue **********
double MotherWaveletGenerator::GetValue(const double &t, const double &scale, 
					const double &tau) {
   time_ = t; 
   scale_ = scale; 
   tau_ = tau;
   tempVariable_ = (t - tau) / scale;
   
   if(type_ == "book")
      return(BookExample());
   else if(type_ == "harr")
      return(Harr());
   else if(type_ == "hermitian")
      return(Hermitian());
   else if(type_ == "lorentz")
      return(Lorentzian());
   else if(type_ == "mexicanhat")
      return(MexicanHat());
   else if(type_ == "morlet")
      return(Morlet());
   else
      return(numeric_limits<double>::signaling_NaN());
}

//********** BookExample **********     
double MotherWaveletGenerator::BookExample(void) {
   return( sin(8*tempVariable_) * exp(-tempVariable_*tempVariable_/2) );
}

//********** Harr *********
double MotherWaveletGenerator::Harr(void) {
   return(0.0);
}

//********** Hermitian **********
double MotherWaveletGenerator::Hermitian(void) {
   return (-1/(pow(2*M_PI, 2)*pow(scale_,3))*tempVariable_ * 
	   exp(-tempVariable_*tempVariable_/2) );
}

//********** Lorentzian **********
double MotherWaveletGenerator::Lorentzian(void) {
   return(0.0);
}

//********** MexicanHat **********
double MotherWaveletGenerator::MexicanHat(void) {
   return ( (2/(sqrt(3*scale_)*pow(M_PI, 0.25)))*
	    (1-(tempVariable_*tempVariable_))* 
	    exp(-tempVariable_*tempVariable_/2) ) ;
}

//********** Morlet **********
double MotherWaveletGenerator::Morlet(void) {
   return ( cos(2*M_PI*tempVariable_)*exp(-tempVariable_*tempVariable_/2) );
}
