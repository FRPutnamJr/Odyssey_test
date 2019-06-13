/*******************************************************************************
* Title                 :   OSR Matrix Class Unit Tests
* Filename              :   Odyssey_matrix.cpp
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-11
* Version               :   0.0.1
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
  *
  *******************************************************************************/




#include <iostream>
#include "OSR_matrix.h"

int main()
{
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


	
	
	
	
	/*
	
	
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

}

/*************** END OF FUNCTIONS ***************************************************************************/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages 
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
