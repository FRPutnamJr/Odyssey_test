/****************************************************************************
* Title                 :   OSR Matrix Class
* Filename              :   OSR_matrix.h
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-08
* Version               :   0.0.3
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
  * Macros
  *******************************************************************************/



  /******************************************************************************
  * Typedefs
  *******************************************************************************/


  /******************************************************************************
  * Variables
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

	unsigned get_number_of_rows(void)    { return _Number_of_rows; }
	unsigned get_number_of_columns(void) { return _Number_of_columns; }
	unsigned get_size_in_bytes(void)     { return _Matrix_size_in_bytes; }

	OSR_matrix::Element_types get_type_of_element(void) { return _Matrix_elements_type; }

	void Transpose(void);

	void get_element(unsigned Row, unsigned Column, unsigned* Element);
	
	void get_element(unsigned Row, unsigned Column, int* Element);
	
	void get_element(unsigned Row, unsigned Column, float* Element);
	
	void get_element(unsigned Row, unsigned Column, char* Element);
	
	void set_element(unsigned Row, unsigned Column, unsigned Data);
	
	void set_element(unsigned Row, unsigned Column, int Data);
	
	void set_element(unsigned Row, unsigned Column, float Data);
	
	void set_element(unsigned Row, unsigned Column, char Data);

	OSR_matrix& operator= (OSR_matrix& Matrix_B);
	OSR_matrix& operator+=(OSR_matrix& Matrix_B);
	OSR_matrix  operator+ (OSR_matrix& Right);

private:
	
	unsigned _Number_of_rows    = 1;
	unsigned _Number_of_columns = 1;

	OSR_matrix::Element_types _Matrix_elements_type = BYTE_TYPE;

	unsigned _Matrix_size_in_bytes = 0;

	void* Matrix_array = nullptr;

};

#ifdef __cplusplus
} // extern "C"
#endif

#endif //  MODULE_H_
/*** End of File **************************************************************/
