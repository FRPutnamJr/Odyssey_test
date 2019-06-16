/****************************************************************************
* Title                 :   OSR Matrix Class
* Filename              :   OSR_matrix.h
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-08
* Version               :   0.5
* Compiler              :   Microsoft Visual Studio 2019 C30 v3.30c
* Target                :   PC
* Notes                 :   None
*****************************************************************************/
/************************* CHANGE LIST **************************************
*
*    Date      Software Version    Initials   Description
*  2019-06-11       0.1              FRP      Created.
*  2019/06/12       0.2              FRP      Implemented constructor, destructor, overloaded get_element, overloaded set_element.
*  2019/06/13       0.3              FRP      Reworked overloaded get_element, overloaded set_element.
*                                             Implemented overloaded operator=, overloaded operator+=, overloaded+.
*  2019/06/14       0.4              FRP      Implemented overloaded operator*= (Scaler Multiplication).
*  2019/06/15       0.5              FRP      Implemented overloaded Transpose.
*
*****************************************************************************/
/** @file OSR_matrix.h
 *  @brief This module contains.
 *
 *  This is the header file for the definition for tasks that are continuous
 *  and should be ran as often as possible.
 */
#ifndef MODULE_H_
#define MODULE_H_

 /******************************************************************************
 * Includes
 *******************************************************************************/


 /******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/
 /**
  * This constant is
  */


  /******************************************************************************
  * Configuration Constants
  *******************************************************************************/


  /******************************************************************************
  * Typedefs
  *******************************************************************************/

  /******************************************************************************
  * Constructors
  *******************************************************************************/

  /******************************************************************************
  * Variables
  *******************************************************************************/

  /******************************************************************************
  * Detructors
  *******************************************************************************/


  /******************************************************************************
  * Function Prototypes
  *******************************************************************************/


  #ifdef __cplusplus
extern "C" {
#endif

#pragma once
class OSR_matrix
{
public:
	typedef enum Element_types { BYTE_TYPE, SINT_TYPE, UINT_TYPE, FLOAT_TYPE } Element_types;

	
	OSR_matrix()
		: _Number_of_rows{ 1 }, _Number_of_columns{ 1 }, _Matrix_elements_type{ BYTE_TYPE }, Matrix_array{ new char[1][1] }
	{}

	OSR_matrix(unsigned initial_number_of_rows, unsigned initial_number_of_columns, OSR_matrix::Element_types initial_matrix_type)
		: _Number_of_rows{ initial_number_of_rows }, _Number_of_columns{ initial_number_of_columns }, _Matrix_elements_type{ initial_matrix_type }

	{
		_Matrix_size_in_bytes = initial_number_of_rows * initial_number_of_columns;
			
		switch (_Matrix_elements_type)
		{
			case BYTE_TYPE :
			{
				_Matrix_size_in_bytes *= sizeof(char);
				Matrix_array = new char[_Matrix_size_in_bytes];
				break;
			}
			
			case UINT_TYPE :
			{
				_Matrix_size_in_bytes *= sizeof(unsigned);
				Matrix_array = new unsigned[_Matrix_size_in_bytes];
				break;
			}
			
			case SINT_TYPE :
			{
				_Matrix_size_in_bytes *= sizeof(int);
				Matrix_array = new int[_Matrix_size_in_bytes];
				break;
			}

			case FLOAT_TYPE :
			{
				_Matrix_size_in_bytes *= sizeof(float);
				Matrix_array = new float[_Matrix_size_in_bytes];
				break;
			}

			default :
			{
				_Matrix_size_in_bytes = 0;
				Matrix_array = nullptr;
			}
		}
	}
	
	~OSR_matrix() {}

	unsigned get_number_of_rows(void)     { return _Number_of_rows; }
	unsigned get_number_of_columns(void)  { return _Number_of_columns; }
	unsigned get_number_of_elements(void) { return _Number_of_elements; }
	unsigned get_size_in_bytes(void)      { return _Matrix_size_in_bytes; }

	void* get_array(void) { return Matrix_array; }

	OSR_matrix::Element_types get_type_of_element(void) { return _Matrix_elements_type; }

	void get_element(unsigned Row, unsigned Column, unsigned* Element);			// Obtain the Unsinged_integer_element from the Unsigned_integer_matrix at Row and Column.
	
	void get_element(unsigned Row, unsigned Column, int* Element);				// Obtain the Singed_integer_element from the Signed_integer_matrix at Row and Column.
	
	void get_element(unsigned Row, unsigned Column, float* Element);			// Obtain the Float_element from the Float_matrix at Row and Column.
	
	void get_element(unsigned Row, unsigned Column, char* Element);				// Obtain the Byte_element from the Byte_matrix at Row and Column.
	
	
	
	void set_element(unsigned Row, unsigned Column, unsigned Data);				// Store the Unsinged_integer_value into the Unsigned_integer_matrix at Row and Column.
	
	void set_element(unsigned Row, unsigned Column, int Data);					// Store the Singed_integer_value into the Signed_integer_matrix at Row and Column.
	
	void set_element(unsigned Row, unsigned Column, float Data);				// Store the Float_value into the Float_matrix at Row and Column.
	
	void set_element(unsigned Row, unsigned Column, char Data);					// Store the Byte_value into the Byte_matrix at Row and Column.

	OSR_matrix& operator=  (OSR_matrix& Matrix_B);								// Matrix_C = Matrix_B
	OSR_matrix& operator+= (OSR_matrix& Matrix_B);								// Matrix_C = Matrix_C + Matrix_B 

	OSR_matrix& operator*= (int Scaler_value);									// Signed_integer_matrix   = Signed_integer_matrix * Signed_integer_scaler_value
	OSR_matrix& operator*= (unsigned Scaler_value);								// Unsigned_integer_matrix = Unsigned_integer_matrix * Unsigned_integer_scaler_value
	OSR_matrix& operator*= (float Scaler_value);								// Float_matrix = Float_matrix * Float_scaler_value
	OSR_matrix& operator*= (char Scaler_value);									// Byte_matrix = Byte_matrix * Byte_scaler_value


//	Expected Result : A = { a b }	B = { e f } 	C = { ae + bg  af + bh }
//	                      { c d }       { g h }         { ce + dg  cf + dh }
//
//	                      { 1 2 }       { 5 6 }         { 19 22 }
//	                      { 3 4 }       { 7 8 }         { 43 50 }

	OSR_matrix& operator*= (OSR_matrix& Matrix_B);								// Matrix_C = Matrix_C * Matrix_B 

	const OSR_matrix Transpose(int Dummy_type);									// Transpose a matrix of signed integer elements.
	
	const OSR_matrix Transpose(unsigned Dummy_type);							// Transpose a matrix of unsigned integer elements.
	
	const OSR_matrix Transpose(float Dummy_type);								// Transpose a matrix of float elements.
	
	const OSR_matrix Transpose(char Dummy_type);								// Transpose a matrix of byte elements.

	OSR_matrix  operator+  (OSR_matrix& Right);

private:
	
	unsigned _Number_of_rows     = 1;
	unsigned _Number_of_columns  = 1;
	unsigned _Number_of_elements = _Number_of_rows * _Number_of_columns;

	OSR_matrix::Element_types _Matrix_elements_type = BYTE_TYPE;

	unsigned _Matrix_size_in_bytes = 0;

	void* Matrix_array = nullptr;

};

#ifdef __cplusplus
} // extern "C"
#endif

#endif //  MODULE_H_
/*** End of File **************************************************************/
