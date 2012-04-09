/*
 * Copyright S.V. Paulauskas 2012
 * stanpaulauskas@gmail.com 
 * Distributed under GNU General Public Licence v3
 */

/** \file MotherWaveletGenerator.hpp
 * Class for generating different kinds of mother wavelets.
 * \author S.V. Paulauskas
 * \date 25 March 2012
 */
#include <string>
#include <vector>

#include <cstdlib>

class MotherWaveletGenerator {
 public:
   MotherWaveletGenerator() {};
   ~MotherWaveletGenerator() {};

   /*! Returns the value of the mother wavelet at the position of the vairables.
     This doesn't sit well with me. I'll make this void at some point.*/
   double GetValue(const double &t, const double &scale, const double &tau);

   /*! Sets the type of mother wavelet that you want to use. */
   void SetWaveletType (const std::string &sigType) {type_ = sigType;}
   
private:
   std::string type_;
   double time_, tau_, scale_, tempVariable_;

   /*! Example taken from (get reference) */
   double BookExample(void);
   /*! Harr Wavelet - still needs to be programmed */
   double Harr(void);
   /*! A Hermitian wavelet */
   double Hermitian(void);
   /*! A Lorentizian wavelet, it is the first derivative of a lorentz function */
   double Lorentzian(void);
   /*! The Mexican Hat wavelet, it is the first derivative of a 
     gaussian function */
   double MexicanHat(void);
   /*! The Morlet */
   double Morlet(void);
   
}; //class MotherWaveletGenerator
