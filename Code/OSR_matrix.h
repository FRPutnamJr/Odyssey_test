/****************************************************************************
* Title                 :   OSR Matrix Class
* Filename              :   OSR_matrix.h
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-08
* Version               :   1.0.0
* Compiler              :   Microsoft Visual Studio 2019 C30 v3.30c
* Target                :   PC
* Notes                 :   None
*****************************************************************************/
/************************* CHANGE LIST **************************************
*
*    Date      Software Version    Initials   Description
*  2019-06-11       0.1              FRP      Created.
*
*****************************************************************************/
/** @file tsk.h
 *  @brief This module contains continuous tasks.
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
		: _Number_of_rows{ 1 }, _Number_of_columns{ 1 }, _Matrix_elements_type{ BYTE_TYPE }, Matrix_array{ new char[1] }
	{
		Matrix_array = 0;
	}

	OSR_matrix(const int initial_number_of_rows, const int initial_number_of_columns, OSR_matrix::Element_types initial_matrix_type)
		: _Number_of_rows{ initial_number_of_rows }, _Number_of_columns{ initial_number_of_columns }, _Matrix_elements_type{ initial_matrix_type }
	{
			
		int Matrix_size = initial_number_of_rows * initial_number_of_columns;

		switch (_Matrix_elements_type)
		{
			case UINT_TYPE :
			{
				Matrix_array = new unsigned[Matrix_size];
				break;
			}
			
			case SINT_TYPE :
			{
				Matrix_array = new int[Matrix_size];
				break;
			}

			case FLOAT_TYPE :
			{
				Matrix_array = new float[Matrix_size];
				break;
			}

			default :
			{
				Matrix_array = new char[Matrix_size];
				break;
			}
		}
	}
	
	int get_number_of_rows(void)    { return _Number_of_rows; }
	int get_number_of_columns(void) { return _Number_of_columns; }
	
	OSR_matrix::Element_types get_type_of_element(void) { return _Matrix_elements_type; }

	void Transpose(void);

private:
	
	int _Number_of_rows    = 1;
	int _Number_of_columns = 1;

	OSR_matrix::Element_types _Matrix_elements_type = BYTE_TYPE;

	void* Matrix_array;

};

#ifdef __cplusplus
} // extern "C"
#endif

#endif //  MODULE_H_
/*** End of File **************************************************************/
