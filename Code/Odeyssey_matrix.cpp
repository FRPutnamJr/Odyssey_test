/*******************************************************************************
* Title                 :   OSR Matrix Class Unit Tests
* Filename              :   Odyssey_matrix.cpp
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-11
* Version               :   0.5
* Compiler              :   Microsoft Visual Studio 2019 C30 v3.30c
* Target                :   PC
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description
*  2019/06/11       0.1            FRP      Created.
*  2019/06/12       0.2            FRP      Added test for constructor, destructor, overloaded get_element, overloaded set_element.
*  2019/06/13       0.3            FRP      Added test for overloaded operator=, overloaded operator+=, overloaded+.
*  2019/06/14       0.4            FRP      Added test for overloaded operator*=  (Scaler Multiplication).
*  2019/06/15       0.5            FRP      Implemented overloaded Transpose.
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
  *  2019/06/11         0.1            FRP      Function Created.
  *  2019/06/12         0.2            FRP      Added test for constructor, destructor, overloaded get_element, overloaded set_element.
  *  2019/06/13         0.3            FRP      Added test for overloaded operator=, overloaded operator+=, overloaded+.
  *  2019/06/14         0.4            FRP      Added test for overloaded operator*=  (Scaler Multiplication).
  *  2019/06/15         0.5            FRP      Implemented overloaded Transpose.
  *
  *******************************************************************************/




#include <iostream>
#include "OSR_matrix.h"

int main()
{
	// Test of byte matrix transpose.
	OSR_matrix Byte_matrix = OSR_matrix(4, 5, OSR_matrix::BYTE_TYPE);
	OSR_matrix* Transposed_byte_matrix = nullptr;

	char The_element = 0;

	unsigned _Ix = 0;
	unsigned _Iy = 0;

	unsigned Element_row = 0;
	unsigned Element_column = 0;


	char Type_selector = (char)Byte_matrix.get_type_of_element();			// Dummy variable to select overloaded function.

	// Initialize elements of original matrix.
	char Initial_elements[4][5] = { {11, 12, 13, 14, 15},
									{21, 22, 23, 24, 25},
									{31, 32, 33, 34, 35},
									{41, 42, 43, 44, 45}
	};

	for (_Ix = 0; _Ix < Byte_matrix.get_number_of_rows(); _Ix++)
	{
		Element_row = _Ix + 1;

		for (_Iy = 0; _Iy < Byte_matrix.get_number_of_columns(); _Iy++)
		{
			Element_column = _Iy + 1;

			The_element = Initial_elements[_Ix][_Iy];

			Byte_matrix.set_element(Element_row, Element_column, The_element);
		}
	}

	// Print out original matrix
	std::cout << "Byte matrix\n";

	for (_Ix = 1; _Ix <= Byte_matrix.get_number_of_rows(); _Ix++)
	{
		for (_Iy = 1; _Iy <= Byte_matrix.get_number_of_columns(); _Iy++)
		{
			Byte_matrix.get_element(_Ix, _Iy, &The_element);

			std::cout << std::dec << "\t" << (unsigned)The_element;
		}

		std::cout << "\n";
	}

	std::cout << "\n";


	// Perform the transpose.
	Transposed_byte_matrix = (OSR_matrix*)& Byte_matrix.Transpose(Type_selector);


	// Print out transposed matrix.
	std::cout << "Transposed matrix\n";

	unsigned Max_rows = Transposed_byte_matrix->get_number_of_rows();
	unsigned Max_columns = Transposed_byte_matrix->get_number_of_columns();

	for (_Ix = 0; _Ix < Max_rows; _Ix++)
	{
		Element_row = _Ix + 1;

		for (_Iy = 0; _Iy < Max_columns; _Iy++)
		{
			Element_column = _Iy + 1;

			Transposed_byte_matrix->get_element(Element_row, Element_column, &The_element);

			std::cout << std::dec << "\t" << (unsigned)The_element;
		}

		std::cout << "\n";
	}

	std::cout << "\n";
}

/*
	// Test of float matrix transpose.
	OSR_matrix Float_matrix = OSR_matrix(4, 5, OSR_matrix::FLOAT_TYPE);
	OSR_matrix* Transposed_float_matrix = nullptr;

	float The_element = 0.0;

	unsigned _Ix = 0;
	unsigned _Iy = 0;

	unsigned Element_row = 0;
	unsigned Element_column = 0;


	float Type_selector = (float)Float_matrix.get_type_of_element();			// Dummy variable to select overloaded function.

	// Initialize elements of original matrix.
	float Initial_elements[4][5] = { { 1.1, -1.2,  1.3, -1.4,  1.5},
								     {-2.1,  2.2, -2.3,  2.4, -2.5},
								     { 3.1, -3.2,  3.3, -3.4,  3.5},
								     {-4.1,  4.2, -4.3,  4.4, -4.5}
	};

	for (_Ix = 0; _Ix < Float_matrix.get_number_of_rows(); _Ix++)
	{
		Element_row = _Ix + 1;

		for (_Iy = 0; _Iy < Float_matrix.get_number_of_columns(); _Iy++)
		{
			Element_column = _Iy + 1;

			The_element = Initial_elements[_Ix][_Iy];

			Float_matrix.set_element(Element_row, Element_column, The_element);
		}
	}

	// Print out original matrix
	std::cout.precision(2);
	std::cout << std::showpoint << "Float matrix\n";
	

	for (_Ix = 1; _Ix <= Float_matrix.get_number_of_rows(); _Ix++)
	{
		for (_Iy = 1; _Iy <= Float_matrix.get_number_of_columns(); _Iy++)
		{
			Float_matrix.get_element(_Ix, _Iy, &The_element);

			std::cout << "\t" << (double)The_element;
		}

		std::cout << "\n";
	}

	std::cout << "\n";


	// Perform the transpose.
	Transposed_float_matrix = (OSR_matrix*)& Float_matrix.Transpose(Type_selector);


	// Print out transposed matrix.
	std::cout << "Transposed matrix\n";

	unsigned Max_rows = Transposed_float_matrix->get_number_of_rows();
	unsigned Max_columns = Transposed_float_matrix->get_number_of_columns();

	for (_Ix = 0; _Ix < Max_rows; _Ix++)
	{
		Element_row = _Ix + 1;

		for (_Iy = 0; _Iy < Max_columns; _Iy++)
		{
			Element_column = _Iy + 1;

			Transposed_float_matrix->get_element(Element_row, Element_column, &The_element);

			std::cout << "\t" << The_element;
		}

		std::cout << "\n";
	}

	std::cout << "\n";
}
*/

/*  // Test of unsigned integer matrix transpose.
	OSR_matrix Unsigned_integer_matrix = OSR_matrix(4, 5, OSR_matrix::SINT_TYPE);
	OSR_matrix* Transposed_unsigned_integer_matrix = nullptr;

	int The_element = 0;

	unsigned _Ix = 0;
	unsigned _Iy = 0;

	unsigned Element_row    = 0;
	unsigned Element_column = 0;


	unsigned Type_selector = (unsigned)Unsigned_integer_matrix.get_type_of_element();			// Dummy variable to select overloaded function.

	// Initialize elements of original matrix. 
	int Initial_elements[4][5] = { { 1,  2,  3,  4,  5},
								   { 6,  7,  8,  9, 10},
								   {11, 12, 13, 14, 15},
								   {16, 17, 18, 19, 20}
								 };

	for (_Ix = 0; _Ix < Unsigned_integer_matrix.get_number_of_rows(); _Ix++)
	{
		Element_row = _Ix + 1;

		for (_Iy = 0; _Iy < Unsigned_integer_matrix.get_number_of_columns(); _Iy++)
		{
			Element_column = _Iy + 1;

			The_element = Initial_elements[_Ix][_Iy];

			Unsigned_integer_matrix.set_element(Element_row, Element_column, The_element);
		}
	}

	// Print out original matrix.
	std::cout << "Unsigned integer matrix\n";

	for (_Ix = 1; _Ix <= Unsigned_integer_matrix.get_number_of_rows(); _Ix++)
	{
		for (_Iy = 1; _Iy <= Unsigned_integer_matrix.get_number_of_columns(); _Iy++)
		{
			Unsigned_integer_matrix.get_element(_Ix, _Iy, &The_element);

			std::cout << "\t" << The_element;
		}

		std::cout << "\n";
	}

	std::cout << "\n";


	// Perform the transpose.
	Transposed_unsigned_integer_matrix = (OSR_matrix*)& Unsigned_integer_matrix.Transpose(Type_selector);

	
	// Print out transposed matrix.
	std::cout << "Transposed matrix\n";

	unsigned Max_rows    = Transposed_unsigned_integer_matrix->get_number_of_rows();
	unsigned Max_columns = Transposed_unsigned_integer_matrix->get_number_of_columns();

	for (_Ix = 0; _Ix < Max_rows; _Ix++)
	{
		Element_row = _Ix + 1;

		for (_Iy = 0; _Iy < Max_columns; _Iy++)
		{
			Element_column = _Iy + 1; 
			
			Transposed_unsigned_integer_matrix->get_element(Element_row, Element_column, &The_element);

			std::cout << "\t" << The_element;
		}

		std::cout << "\n";
	}

	std::cout << "\n";
}

*/
/*
// Test of signed integer matrix transpose.
OSR_matrix Signed_integer_matrix = OSR_matrix(4, 5, OSR_matrix::SINT_TYPE);
OSR_matrix* Transposed_signed_integer_matrix = nullptr;

int The_element = 0;

unsigned _Ix = 0;
unsigned _Iy = 0;

unsigned Element_row = 0;
unsigned Element_column = 0;


int Type_selector = (int)Signed_integer_matrix.get_type_of_element();			// Dummy variable to select overloaded function.

// Initialize elements of original matrix.
int Initial_elements[4][5] = { {  1,  -2,   3,  -4,   5},
							   { -6,   7,  -8,   9, -10},
							   { 11, -12,  13, -14,  15},
							   {-16,  17, -18,  19, -20}
};

for (_Ix = 0; _Ix < Signed_integer_matrix.get_number_of_rows(); _Ix++)
{
	Element_row = _Ix + 1;

	for (_Iy = 0; _Iy < Signed_integer_matrix.get_number_of_columns(); _Iy++)
	{
		Element_column = _Iy + 1;

		The_element = Initial_elements[_Ix][_Iy];

		Signed_integer_matrix.set_element(Element_row, Element_column, The_element);
	}
}

// Print out original matrix.
std::cout << "Signed integer matrix\n";

for (_Ix = 1; _Ix <= Signed_integer_matrix.get_number_of_rows(); _Ix++)
{
	for (_Iy = 1; _Iy <= Signed_integer_matrix.get_number_of_columns(); _Iy++)
	{
		Signed_integer_matrix.get_element(_Ix, _Iy, &The_element);

		std::cout << "\t" << The_element;
	}

	std::cout << "\n";
}

std::cout << "\n";


// Perform the transpose.
Transposed_signed_integer_matrix = (OSR_matrix*)& Signed_integer_matrix.Transpose(Type_selector);


// Print out transposed matrix.
std::cout << "Transposed matrix\n";

unsigned Max_rows = Transposed_signed_integer_matrix->get_number_of_rows();
unsigned Max_columns = Transposed_signed_integer_matrix->get_number_of_columns();

for (_Ix = 0; _Ix < Max_rows; _Ix++)
{
	Element_row = _Ix + 1;

	for (_Iy = 0; _Iy < Max_columns; _Iy++)
	{
		Element_column = _Iy + 1;

		Transposed_signed_integer_matrix->get_element(Element_row, Element_column, &The_element);

		std::cout << "\t" << The_element;
	}

	std::cout << "\n";
}

std::cout << "\n";
}
*/
/*	// Test of scaler multiplication to float matrix.
	OSR_matrix Float_matrix  = OSR_matrix(2, 2, OSR_matrix::FLOAT_TYPE);
	OSR_matrix Scaled_matrix = OSR_matrix(2, 2, OSR_matrix::FLOAT_TYPE);

	float Scaler_value = -5.0;

	float A11u = 1.1;
	float A12u = -1.2;
	float A21u = -2.1;
	float A22u = 2.2;

	Float_matrix.set_element(1, 1, A11u);
	Float_matrix.set_element(1, 2, A12u);
	Float_matrix.set_element(2, 1, A21u);
	Float_matrix.set_element(2, 2, A22u);

	A11u = 0u;
	A12u = 0u;
	A21u = 0u;
	A22u = 0u;

	Float_matrix.get_element(1, 1, &A11u);
	Float_matrix.get_element(1, 2, &A12u);
	Float_matrix.get_element(2, 1, &A21u);
	Float_matrix.get_element(2, 2, &A22u);

	std::cout << "Float matrix\n\t" << A11u << "\t" << A12u << "\n" << "\t" << A21u << "\t" << A22u << "\n\n";


	Scaled_matrix = Float_matrix;

	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Scaled_matrix.get_element(1, 1, &A11u);
	Scaled_matrix.get_element(1, 2, &A12u);
	Scaled_matrix.get_element(2, 1, &A21u);
	Scaled_matrix.get_element(2, 2, &A22u);

	std::cout << "Scaled matrix before\n\t" << A11u << "\t" << A12u << "\n\t" << A21u << "\t" << A22u << "\n\n";


	Scaled_matrix *= Scaler_value;


	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Scaled_matrix.get_element(1, 1, &A11u);
	Scaled_matrix.get_element(1, 2, &A12u);
	Scaled_matrix.get_element(2, 1, &A21u);
	Scaled_matrix.get_element(2, 2, &A22u);

	std::cout << "Scaled matrix scaled by " << Scaler_value << "\n\t" << A11u << "\t" << A12u << "\n\t" << A21u << "\t" << A22u << "\n\n";
*/


/*	// Test of scaler multiplication to unsigned integer matrix.
	OSR_matrix Unsigned_integer_matrix = OSR_matrix(2, 2, OSR_matrix::UINT_TYPE);
	OSR_matrix Scaled_matrix           = OSR_matrix(2, 2, OSR_matrix::UINT_TYPE);

	unsigned Scaler_value = 5;

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


	Scaled_matrix = Unsigned_integer_matrix;

	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Scaled_matrix.get_element(1, 1, &A11u);
	Scaled_matrix.get_element(1, 2, &A12u);
	Scaled_matrix.get_element(2, 1, &A21u);
	Scaled_matrix.get_element(2, 2, &A22u);

	std::cout << "Scaled matrix before\n\t" << A11u << "\t" << A12u << "\n\t" << A21u << "\t" << A22u << "\n\n";


	Scaled_matrix *= Scaler_value;


	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Scaled_matrix.get_element(1, 1, &A11u);
	Scaled_matrix.get_element(1, 2, &A12u);
	Scaled_matrix.get_element(2, 1, &A21u);
	Scaled_matrix.get_element(2, 2, &A22u);

	std::cout << "Scaled matrix scaled by " << Scaler_value << "\n\t" << A11u << "\t" << A12u << "\n\t" << A21u << "\t" << A22u << "\n\n";



	// Test of scaler multiplication to signed integer matrix.
	OSR_matrix Signed_integer_matrix = OSR_matrix(2, 2, OSR_matrix::SINT_TYPE);
	OSR_matrix Scaled_matrix         = OSR_matrix(2, 2, OSR_matrix::SINT_TYPE);

	int Scaler_value = -5;

	int A11u =  11;
	int A12u = -12;
	int A21u =  21;
	int A22u = -22;

	Signed_integer_matrix.set_element(1, 1, A11u);
	Signed_integer_matrix.set_element(1, 2, A12u);
	Signed_integer_matrix.set_element(2, 1, A21u);
	Signed_integer_matrix.set_element(2, 2, A22u);

	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Signed_integer_matrix.get_element(1, 1, &A11u);
	Signed_integer_matrix.get_element(1, 2, &A12u);
	Signed_integer_matrix.get_element(2, 1, &A21u);
	Signed_integer_matrix.get_element(2, 2, &A22u);

	std::cout << "Signed integer matrix\n\t" << A11u << "\t" << A12u << "\n" << "\t" << A21u << "\t" << A22u << "\n\n";


	Scaled_matrix = Signed_integer_matrix;

	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Scaled_matrix.get_element(1, 1, &A11u);
	Scaled_matrix.get_element(1, 2, &A12u);
	Scaled_matrix.get_element(2, 1, &A21u);
	Scaled_matrix.get_element(2, 2, &A22u);

	std::cout << "Scaled matrix before\n\t" << A11u << "\t" << A12u << "\n\t" << A21u << "\t" << A22u << "\n\n";

	
	Scaled_matrix *= Scaler_value;


	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Scaled_matrix.get_element(1, 1, &A11u);
	Scaled_matrix.get_element(1, 2, &A12u);
	Scaled_matrix.get_element(2, 1, &A21u);
	Scaled_matrix.get_element(2, 2, &A22u);

	std::cout << "Scaled matrix scaled by " << Scaler_value << "\n\t" << A11u << "\t" << A12u << "\n\t" << A21u << "\t" << A22u << "\n\n";
*/


/*
	unsigned Row_count    = 0;
	unsigned Column_count = 0;
	unsigned Matrix_size  = 0;

	OSR_matrix Signed_integer_matrix_A = OSR_matrix(2, 2, OSR_matrix::SINT_TYPE);
	OSR_matrix Signed_integer_matrix_B = OSR_matrix(2, 2, OSR_matrix::SINT_TYPE);
	OSR_matrix Signed_integer_matrix_C = OSR_matrix(2, 2, OSR_matrix::SINT_TYPE);

	int A11u = 0;
	int A12u = 0;
	int A21u = 0;
	int A22u = 0; 
	
	Signed_integer_matrix_C.set_element(1, 1, A11u);
	Signed_integer_matrix_C.set_element(1, 2, A12u);
	Signed_integer_matrix_C.set_element(2, 1, A21u);
	Signed_integer_matrix_C.set_element(2, 2, A22u);

	A11u = 11;
	A12u = 12;
	A21u = 21;
	A22u = 22;

	Signed_integer_matrix_A.set_element(1, 1, A11u);
	Signed_integer_matrix_A.set_element(1, 2, A12u);
	Signed_integer_matrix_A.set_element(2, 1, A21u);
	Signed_integer_matrix_A.set_element(2, 2, A22u);

	Signed_integer_matrix_B.set_element(1, 1, A11u);
	Signed_integer_matrix_B.set_element(1, 2, A12u);
	Signed_integer_matrix_B.set_element(2, 1, A21u);
	Signed_integer_matrix_B.set_element(2, 2, A22u);

	Signed_integer_matrix_C  = Signed_integer_matrix_A;

	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Signed_integer_matrix_C.get_element(1, 1, &A11u);
	Signed_integer_matrix_C.get_element(1, 2, &A12u);
	Signed_integer_matrix_C.get_element(2, 1, &A21u);
	Signed_integer_matrix_C.get_element(2, 2, &A22u);

	std::cout << "   " << A11u << "   " << A12u << "\n" << "   " << A21u << "   " << A22u << "\n\n";

	
	Signed_integer_matrix_C += Signed_integer_matrix_B;

	A11u = 0;
	A12u = 0;
	A21u = 0;
	A22u = 0;

	Signed_integer_matrix_C.get_element(1, 1, &A11u);
	Signed_integer_matrix_C.get_element(1, 2, &A12u);
	Signed_integer_matrix_C.get_element(2, 1, &A21u);
	Signed_integer_matrix_C.get_element(2, 2, &A22u);

	std::cout << "   " << A11u << "   " << A12u << "\n" << "   " << A21u << "   " << A22u << "\n\n";


	
	
	
	
	
	
	OSR_matrix* Byte_matrix = new OSR_matrix(2,2,OSR_matrix::BYTE_TYPE);

	Row_count    = Byte_matrix->get_number_of_rows();
	Column_count = Byte_matrix->get_number_of_columns();
	Matrix_size  = Byte_matrix->get_size_in_bytes();

	std::cout << "Byte Matrix   Rows " << Row_count << "   Columns " << Column_count << "   Size " << Matrix_size << "\n";

	char A11b = 'A';
	char A12b = 'B';
	char A21b = 'C';
	char A22b = 'D';

	Byte_matrix->set_element(1, 1, A11b);
	Byte_matrix->set_element(1, 2, A12b);
	Byte_matrix->set_element(2, 1, A21b);
	Byte_matrix->set_element(2, 2, A22b);

	A11b = '0';
	A12b = '0';
	A21b = '0';
	A22b = '0';

	Byte_matrix->get_element(1, 1, &A11b); 
	Byte_matrix->get_element(1, 2, &A12b);
	Byte_matrix->get_element(2, 1, &A21b);
	Byte_matrix->get_element(2, 2, &A22b);

	std::cout << "   " << A11b << "   " << A12b << "\n" << "   " << A21b << "   " << A22b << "\n\n";
	
	
	
	
	OSR_matrix* Unsigned_integer_matrix = new OSR_matrix(2, 2, OSR_matrix::UINT_TYPE);

	Row_count    = Unsigned_integer_matrix->get_number_of_rows();
	Column_count = Unsigned_integer_matrix->get_number_of_columns();
	Matrix_size  = Unsigned_integer_matrix->get_size_in_bytes();

	std::cout << "Unsigned Interger Matrix   Rows " << Row_count << "   Columns " << Column_count << "   Size " << Matrix_size << "\n";

	unsigned A11u = 11u;
	unsigned A12u = 12u;
	unsigned A21u = 21u;
	unsigned A22u = 22u;

	Unsigned_integer_matrix->set_element(1, 1, A11u);
	Unsigned_integer_matrix->set_element(1, 2, A12u);
	Unsigned_integer_matrix->set_element(2, 1, A21u);
	Unsigned_integer_matrix->set_element(2, 2, A22u);

	A11u = 0u;
	A12u = 0u;
	A21u = 0u;
	A22u = 0u;

	Unsigned_integer_matrix->get_element(1, 1, &A11u);
	Unsigned_integer_matrix->get_element(1, 2, &A12u);
	Unsigned_integer_matrix->get_element(2, 1, &A21u);
	Unsigned_integer_matrix->get_element(2, 2, &A22u);

	std::cout << "   " << A11u << "   " << A12u << "\n" << "   " << A21u << "   " << A22u << "\n\n";

//	delete Unsigned_integer_matrix;

	OSR_matrix* Signed_integer_matrix = new OSR_matrix(2, 2, OSR_matrix::SINT_TYPE);

	Row_count    = Signed_integer_matrix->get_number_of_rows();
	Column_count = Signed_integer_matrix->get_number_of_columns();
	Matrix_size  = Signed_integer_matrix->get_size_in_bytes();

	std::cout << "Signed Integer Matrix   Rows " << Row_count << "   Columns " << Column_count << "   Size " << Matrix_size << "\n";

	int A11i =  11;
	int A12i = -12;
	int A21i = -21;
	int A22i =  22;

	Signed_integer_matrix->set_element(1, 1, A11i);
	Signed_integer_matrix->set_element(1, 2, A12i);
	Signed_integer_matrix->set_element(2, 1, A21i);
	Signed_integer_matrix->set_element(2, 2, A22i);

	A11i = 0;
	A12i = 0;
	A21i = 0;
	A22i = 0;

	Signed_integer_matrix->get_element(1, 1, &A11i);
	Signed_integer_matrix->get_element(1, 2, &A12i);
	Signed_integer_matrix->get_element(2, 1, &A21i);
	Signed_integer_matrix->get_element(2, 2, &A22i);

	std::cout << "   " << A11i << "   " << A12i << "\n" << "   " << A21i << "   " << A22i << "\n\n";



	OSR_matrix* Float_matrix = new OSR_matrix(2, 2, OSR_matrix::FLOAT_TYPE);

	Row_count    = Float_matrix->get_number_of_rows();
	Column_count = Float_matrix->get_number_of_columns();
	Matrix_size  = Float_matrix->get_size_in_bytes();

	std::cout << "Float Matrix   Rows " << Row_count << "   Columns " << Column_count << "   Size " << Matrix_size << "\n";

	float A11f = -1.1;
	float A12f =  1.2;
	float A21f =  2.1;
	float A22f = -2.2;

	Float_matrix->set_element(1, 1, A11f);
	Float_matrix->set_element(1, 2, A12f);
	Float_matrix->set_element(2, 1, A21f);
	Float_matrix->set_element(2, 2, A22f);

	A11f = 0.0;
	A12f = 0.0;
	A21f = 0.0;
	A22f = 0.0;

	Float_matrix->get_element(1, 1, &A11f);
	Float_matrix->get_element(1, 2, &A12f);
	Float_matrix->get_element(2, 1, &A21f);
	Float_matrix->get_element(2, 2, &A22f);

	std::cout << "   " << A11f << "   " << A12f << "\n" << "   " << A21f << "   " << A22f << "\n\n";
*/

/*
std::cout << "Signed integer matrix elments\n";

for (_Ix = 0; _Ix < Signed_integer_matrix.get_number_of_rows(); _Ix++)
{
	Element_row = _Ix + 1;

	for (_Iy = 0; _Iy < Signed_integer_matrix.get_number_of_columns(); _Iy++)
	{
		Element_column = _Iy + 1;

		The_element = Initial_elements[_Ix][_Iy];

		std::cout << "\t" << The_element;

		Signed_integer_matrix.set_element(Element_row, _Iy + 1, The_element);

		The_element = 0;

		Signed_integer_matrix.get_element(Element_row, _Iy + 1, &The_element);

		std::cout << "\t" << The_element << "\n";
	}
}
*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages 
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
