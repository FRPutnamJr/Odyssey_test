/*******************************************************************************
* Title                 :   OSR Matrix Class Unit Tests for Scaler Multiplication
* Filename              :   Unit_test_scaler_multiplication.cpp
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-17
* Version               :   1.0
* Compiler              :   Microsoft Visual Studio 2019 C30 v3.30c
* Target                :   PC
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description
*  2019/06/17       1.0            FRP      Release.
*
*******************************************************************************/
/** @file Odeyssey_matrix.cpp
 *  @brief This module contains the 'main' function.
 *  Program execution begins and ends there.
*/
/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
/**
 * Doxygen tag for documenting variables and constants
 */
constexpr auto CONSTANT = 5;

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
/******************************************************************************
* Function : main()
*/
/*
* @section Description Description:
*
*  This function is used to
*
* @param  		None.
*
* @return 		None.
*
* @section Example Example:
* @code
*    main();
* @endcode
*
*
*  ----------------------
*  - HISTORY OF CHANGES -
*  ----------------------
*    Date      Software Version    Initials   Description
*  2019/06/17         1.0            FRP      Release.
*
*******************************************************************************/


#include <iostream>
#include "OSR_matrix.h"

int main(void)
{	// Test of scaler multiplication to float matrix.
	OSR_matrix Float_matrix = OSR_matrix(2, 2, OSR_matrix::FLOAT_TYPE);
	OSR_matrix Scaled_float_matrix = OSR_matrix(2, 2, OSR_matrix::FLOAT_TYPE);

	float Scaler_float_value = -5.0;

	float A11f = 1.1;
	float A12f = -1.2;
	float A21f = -2.1;
	float A22f = 2.2;

	Float_matrix.set_element(1, 1, A11f);
	Float_matrix.set_element(1, 2, A12f);
	Float_matrix.set_element(2, 1, A21f);
	Float_matrix.set_element(2, 2, A22f);

	A11f = 0.0;
	A12f = 0.0;
	A21f = 0.0;
	A22f = 0.0;

	Float_matrix.get_element(1, 1, &A11f);
	Float_matrix.get_element(1, 2, &A12f);
	Float_matrix.get_element(2, 1, &A21f);
	Float_matrix.get_element(2, 2, &A22f);

	std::cout << "Float matrix\n\t" << A11f << "\t" << A12f << "\n\t" << A21f << "\t" << A22f << "\n\n";


	Scaled_float_matrix = Float_matrix;

	A11f = 0.0;
	A12f = 0.0;
	A21f = 0.0;
	A22f = 0.0;

	Scaled_float_matrix.get_element(1, 1, &A11f);
	Scaled_float_matrix.get_element(1, 2, &A12f);
	Scaled_float_matrix.get_element(2, 1, &A21f);
	Scaled_float_matrix.get_element(2, 2, &A22f);

	std::cout << "Scaled matrix before\n\t" << A11f << "\t" << A12f << "\n\t" << A21f << "\t" << A22f << "\n\n";


	Scaled_float_matrix *= Scaler_float_value;


	A11f = 0.0;
	A12f = 0.0;
	A21f = 0.0;
	A22f = 0.0;

	Scaled_float_matrix.get_element(1, 1, &A11f);
	Scaled_float_matrix.get_element(1, 2, &A12f);
	Scaled_float_matrix.get_element(2, 1, &A21f);
	Scaled_float_matrix.get_element(2, 2, &A22f);

	std::cout << "Scaled matrix scaled by " << Scaler_float_value << "\n\t" << A11f << "\t" << A12f << "\n\t" << A21f << "\t" << A22f << "\n\n";



	// Test of scaler multiplication to unsigned integer matrix.
	OSR_matrix Unsigned_integer_matrix = OSR_matrix(2, 2, OSR_matrix::UINT_TYPE);
	OSR_matrix Scaled_uint_matrix = OSR_matrix(2, 2, OSR_matrix::UINT_TYPE);

	unsigned Scaler_uint_value = 5;

	unsigned A11u = 11;
	unsigned A12u = 12;
	unsigned A21u = 21;
	unsigned A22u = 22;

	Unsigned_integer_matrix.set_element(1, 1, A11u);
	Unsigned_integer_matrix.set_element(1, 2, A12u);
	Unsigned_integer_matrix.set_element(2, 1, A21u);
	Unsigned_integer_matrix.set_element(2, 2, A22u);

	A11u = 0u;
	A12u = 0u;
	A21u = 0u;
	A22u = 0u;

	Unsigned_integer_matrix.get_element(1, 1, &A11u);
	Unsigned_integer_matrix.get_element(1, 2, &A12u);
	Unsigned_integer_matrix.get_element(2, 1, &A21u);
	Unsigned_integer_matrix.get_element(2, 2, &A22u);

	std::cout << "Unsigned integer matrix\n\t" << A11u << "\t" << A12u << "\n" << "\t" << A21u << "\t" << A22u << "\n\n";


	Scaled_uint_matrix = Unsigned_integer_matrix;

	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Scaled_uint_matrix.get_element(1, 1, &A11u);
	Scaled_uint_matrix.get_element(1, 2, &A12u);
	Scaled_uint_matrix.get_element(2, 1, &A21u);
	Scaled_uint_matrix.get_element(2, 2, &A22u);

	std::cout << "Scaled matrix before\n\t" << A11u << "\t" << A12u << "\n\t" << A21u << "\t" << A22u << "\n\n";


	Scaled_uint_matrix *= Scaler_uint_value;


	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Scaled_uint_matrix.get_element(1, 1, &A11u);
	Scaled_uint_matrix.get_element(1, 2, &A12u);
	Scaled_uint_matrix.get_element(2, 1, &A21u);
	Scaled_uint_matrix.get_element(2, 2, &A22u);

	std::cout << "Scaled matrix scaled by " << Scaler_uint_value << "\n\t" << A11u << "\t" << A12u << "\n\t" << A21u << "\t" << A22u << "\n\n";



	// Test of scaler multiplication to signed integer matrix.
	OSR_matrix Signed_integer_matrix = OSR_matrix(2, 2, OSR_matrix::SINT_TYPE);
	OSR_matrix Scaled_sint_matrix = OSR_matrix(2, 2, OSR_matrix::SINT_TYPE);

	int Scaler_sint_value = -5;

	int A11s = 11;
	int A12s = -12;
	int A21s = 21;
	int A22s = -22;

	Signed_integer_matrix.set_element(1, 1, A11s);
	Signed_integer_matrix.set_element(1, 2, A12s);
	Signed_integer_matrix.set_element(2, 1, A21s);
	Signed_integer_matrix.set_element(2, 2, A22s);

	A11s = 0;
	A12s = 0;
	A21s = 0;
	A22s = 0;

	Signed_integer_matrix.get_element(1, 1, &A11s);
	Signed_integer_matrix.get_element(1, 2, &A12s);
	Signed_integer_matrix.get_element(2, 1, &A21s);
	Signed_integer_matrix.get_element(2, 2, &A22s);

	std::cout << "Signed integer matrix\n\t" << A11s << "\t" << A12s << "\n" << "\t" << A21s << "\t" << A22s << "\n\n";


	Scaled_sint_matrix = Signed_integer_matrix;

	A11s = 0;
	A12s = 0;
	A21s = 0;
	A22s = 0;

	Scaled_sint_matrix.get_element(1, 1, &A11s);
	Scaled_sint_matrix.get_element(1, 2, &A12s);
	Scaled_sint_matrix.get_element(2, 1, &A21s);
	Scaled_sint_matrix.get_element(2, 2, &A22s);

	std::cout << "Scaled matrix before\n\t" << A11s << "\t" << A12s << "\n\t" << A21s << "\t" << A22s << "\n\n";


	Scaled_sint_matrix *= Scaler_sint_value;


	A11s = 0;
	A12s = 0;
	A21s = 0;
	A22s = 0;

	Scaled_sint_matrix.get_element(1, 1, &A11s);
	Scaled_sint_matrix.get_element(1, 2, &A12s);
	Scaled_sint_matrix.get_element(2, 1, &A21s);
	Scaled_sint_matrix.get_element(2, 2, &A22s);

	std::cout << "Scaled matrix scaled by " << Scaler_sint_value << "\n\t" << A11s << "\t" << A12s << "\n\t" << A21s << "\t" << A22s << "\n\n";


	// Test of scaler multiplication to byte matrix.
	OSR_matrix Byte_matrix = OSR_matrix(2, 2, OSR_matrix::BYTE_TYPE);
	OSR_matrix Scaled_byte_matrix = OSR_matrix(2, 2, OSR_matrix::BYTE_TYPE);

	char Scaler_byte_value = 5;

	char A11b = 1;
	char A12b = 2;
	char A21b = 1;
	char A22b = 2;

	Byte_matrix.set_element(1, 1, A11b);
	Byte_matrix.set_element(1, 2, A12b);
	Byte_matrix.set_element(2, 1, A21b);
	Byte_matrix.set_element(2, 2, A22b);

	A11b = 0;
	A12b = 0;
	A21b = 0;
	A22b = 0;

	Byte_matrix.get_element(1, 1, &A11b);
	Byte_matrix.get_element(1, 2, &A12b);
	Byte_matrix.get_element(2, 1, &A21b);
	Byte_matrix.get_element(2, 2, &A22b);

	std::cout << "Byte matrix\n\t" << A11b << "\t" << A12b << "\n" << "\t" << A21b << "\t" << A22b << "\n\n";


	Scaled_byte_matrix = Byte_matrix;

	A11b = 0;
	A12b = 0;
	A21b = 0;
	A22b = 0;

	Scaled_byte_matrix.get_element(1, 1, &A11b);
	Scaled_byte_matrix.get_element(1, 2, &A12b);
	Scaled_byte_matrix.get_element(2, 1, &A21b);
	Scaled_byte_matrix.get_element(2, 2, &A22b);

	std::cout << "Scaled matrix before\n\t" << A11b << "\t" << A12b << "\n\t" << A21b << "\t" << A22b << "\n\n";


	Scaled_byte_matrix *= Scaler_byte_value;


	A11b = 0;
	A12b = 0;
	A21b = 0;
	A22b = 0;

	Scaled_byte_matrix.get_element(1, 1, &A11b);
	Scaled_byte_matrix.get_element(1, 2, &A12b);
	Scaled_byte_matrix.get_element(2, 1, &A21b);
	Scaled_byte_matrix.get_element(2, 2, &A22b);

	std::cout << "Scaled matrix scaled by " << Scaler_byte_value << "\n\t" << A11b << "\t" << A12b << "\n\t" << A21b << "\t" << A22b << "\n\n";
}
