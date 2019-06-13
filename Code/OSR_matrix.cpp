/*******************************************************************************
* Title                 :   OSR Matrix Class
* Filename              :   OSR_matrix.cpp
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-11
* Version               :   0.0.3
* Compiler              :   Microsoft Visual Studio 2019 C30 v3.30c
* Target                :   PC
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description
*  2019-06-11       0.1              FRP      Created.
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
*  2019/06/11       0.1              FRP      Function Created.
*  2019/06/12       0.2              FRP      Implemented constructor, destructor, overloaded get_element, overloaded set_element.
*  2019/06/13       0.3              FRP      Reworked overloaded get_element, overloaded set_element.
*                                             Implemented overloaded operator=, overloaded operator+=, overloaded+.
*
*******************************************************************************/

#include "OSR_matrix.h"


void OSR_matrix::Transpose(void)
{
	;
}

void OSR_matrix::get_element(unsigned Row, unsigned Column, unsigned* Element)
{
	unsigned _Position = 0;
	unsigned* Location = nullptr;

	if ((Row > 0) && (Row <= _Number_of_rows) && (Column > 0) && (Column <= _Number_of_columns))
	{
		_Position = (Row - 1) * _Number_of_columns;

		_Position += (Column - 1);

		Location = (unsigned*)Matrix_array;
		Location += _Position;

		*Element = *Location;
	}
}

void OSR_matrix::get_element(unsigned Row, unsigned Column, int* Element)
{
	unsigned _Position = 0;
	int* Location = nullptr;

	if ((Row > 0) && (Row <= _Number_of_rows) && (Column > 0) && (Column <= _Number_of_columns))
	{
		_Position = (Row - 1) * _Number_of_columns;

		_Position += (Column - 1);

		Location = (int*)Matrix_array;
		Location += _Position;

		*Element = *Location;
	}
}

void OSR_matrix::get_element(unsigned Row, unsigned Column, float* Element)
{
	unsigned _Position = 0;
	float* Location = nullptr;

	if ((Row > 0) && (Row <= _Number_of_rows) && (Column > 0) && (Column <= _Number_of_columns))
	{
		_Position = (Row - 1) * _Number_of_columns;

		_Position += (Column - 1);

		Location = (float*)Matrix_array;
		Location += _Position;

		*Element = *Location;
	}
}

void OSR_matrix::get_element(unsigned Row, unsigned Column, char* Element)
{
	unsigned _Position = 0;
	char* Location = nullptr;

	if ((Row > 0) && (Row <= _Number_of_rows) && (Column > 0) && (Column <= _Number_of_columns))
	{
		_Position = (Row - 1) * _Number_of_columns;

		_Position += (Column - 1);

		Location = (char*)Matrix_array;
		Location += _Position;

		*Element = *Location;
	}
}

void OSR_matrix::set_element(unsigned Row, unsigned Column, unsigned Data)
{
	unsigned _Position = 0;
	unsigned* Location = nullptr;

	if ((Row > 0) && (Row <= _Number_of_rows) && (Column > 0) && (Column <= _Number_of_columns))
	{
		_Position = (Row - 1) * _Number_of_columns;

		_Position += (Column - 1);

		Location = (unsigned*)Matrix_array;
		Location += _Position;

		*Location = Data;
	}
}

void OSR_matrix::set_element(unsigned Row, unsigned Column, int Data)
{
	unsigned _Position = 0;
	int* Location = nullptr;

	if ((Row > 0) && (Row <= _Number_of_rows) && (Column > 0) && (Column <= _Number_of_columns))
	{
		_Position = (Row - 1) * _Number_of_columns;

		_Position += (Column - 1);

		Location = (int*)Matrix_array;
		Location += _Position;

		*Location = Data;
	}
}

void OSR_matrix::set_element(unsigned Row, unsigned Column, float Data)
{
	unsigned _Position = 0;
	float* Location = nullptr;

	if ((Row > 0) && (Row <= _Number_of_rows) && (Column > 0) && (Column <= _Number_of_columns))
	{
		_Position = (Row - 1) * _Number_of_columns;

		_Position += (Column - 1);

		Location = (float*)Matrix_array;
		Location += _Position;

		*Location = Data;
	}
}


void OSR_matrix::set_element(unsigned Row, unsigned Column, char Data)
{
	unsigned _Position = 0;
	char* Location = nullptr;

	if ((Row > 0) && (Row <= _Number_of_rows) && (Column > 0) && (Column <= _Number_of_columns))
	{
		_Position = (Row - 1) * _Number_of_columns;

		_Position += (Column - 1);

		Location = (char*)Matrix_array;
		Location += _Position;

		*Location = Data;
	}
}

OSR_matrix& OSR_matrix::operator=(OSR_matrix& Right_matrix) 
{
	unsigned Position      = 0;
	unsigned Element_count = _Number_of_rows * _Number_of_columns;

	switch (_Matrix_elements_type)
	{
		case BYTE_TYPE:
		{
			char* Left_matrix_array  = (char*)Matrix_array;
			char* Right_matrix_array = (char*)Right_matrix.Matrix_array;
			int Data = 0;

			for (Position = 0; Position < Element_count; Position++)
			{
				Data = (char)* Right_matrix_array++;
				*Left_matrix_array++ = Data;
			}

			break;
		}


		case SINT_TYPE:
		{
			int* Left_matrix_array  = (int*)Matrix_array;
			int* Right_matrix_array = (int*)Right_matrix.Matrix_array;
			int Data = 0;

			for (Position = 0; Position < Element_count; Position++)
			{
				Data = (int)* Right_matrix_array++;
				*Left_matrix_array++ = Data;
			}

			break;
		}

		case UINT_TYPE:
		{
			unsigned* Left_matrix_array  = (unsigned*)Matrix_array;
			unsigned* Right_matrix_array = (unsigned*)Right_matrix.Matrix_array;
			int Data = 0;

			for (Position = 0; Position < Element_count; Position++)
			{
				Data = (unsigned)* Right_matrix_array++;
				*Left_matrix_array++ = Data;
			}

			break;
		}

		case FLOAT_TYPE:
		{
			float* Left_matrix_array  = (float*)Matrix_array;
			float* Right_matrix_array = (float*)Right_matrix.Matrix_array;
			float Data = 0;

			for (Position = 0; Position < Element_count; Position++)
			{
				Data = (float)* Right_matrix_array++;
				*Left_matrix_array++ = Data;
			}

			break;
		}

		default:
		{
			break;
		}
	}
	
	return (*this);
}

OSR_matrix& OSR_matrix::operator+=(OSR_matrix& Matrix_B)   // Addition. 
{
	unsigned Position = 0;
	unsigned Element_count = _Number_of_rows * _Number_of_columns;

	switch (_Matrix_elements_type)
	{
		case BYTE_TYPE:
		{
			char* Left_matrix_array  = (char*)Matrix_array;
			char* Right_matrix_array = (char*)Matrix_B.Matrix_array;

			for (Position = 0; Position < Element_count; Position++)
			{
				*Left_matrix_array++ += *Right_matrix_array++;
			}

			break;
		}


		case SINT_TYPE:
		{
			int* Left_matrix_array  = (int*)Matrix_array;
			int* Right_matrix_array = (int*)Matrix_B.Matrix_array; 
			
			for (Position = 0; Position < Element_count; Position++)
			{
				*Left_matrix_array++ += *Right_matrix_array++;
			}
			
			break;
		}

		case UINT_TYPE:
		{
			unsigned* Left_matrix_array  = (unsigned*)Matrix_array;
			unsigned* Right_matrix_array = (unsigned*)Matrix_B.Matrix_array;

			for (Position = 0; Position < Element_count; Position++)
			{
				*Left_matrix_array++ += *Right_matrix_array++;
			}
			
			break;
		}

		case FLOAT_TYPE:
		{
			float* Left_matrix_array = (float*)Matrix_array;
			float* Right_matrix_array = (float*)Matrix_B.Matrix_array;

			for (Position = 0; Position < Element_count; Position++)
			{
				*Left_matrix_array++ += *Right_matrix_array++;
			}
			
			break;
		}

		default:
			{
				break;
			}
	}
	return  (*this);
}

OSR_matrix OSR_matrix::operator+(OSR_matrix& Matrix_B)   // Addition. 
{ 
	const OSR_matrix Matrix_C(*this);
	
	unsigned Position = 0;
	unsigned Element_count = _Number_of_rows * _Number_of_columns;

	switch (_Matrix_elements_type)
	{
		case BYTE_TYPE:
		{
			char* Matrix_A_array = (char*)Matrix_array;
			char* Matrix_B_array = (char*)Matrix_B.Matrix_array;
			char* Matrix_C_array = (char*)Matrix_C.Matrix_array;

			for (Position = 0; Position < Element_count; Position++)
			{
				*Matrix_C_array++ = *Matrix_A_array++ + *Matrix_B_array++;
			}

			break;
		}


		case SINT_TYPE:
		{
			int* Matrix_A_array = (int*)Matrix_array;
			int* Matrix_B_array = (int*)Matrix_B.Matrix_array;
			int* Matrix_C_array = (int*)Matrix_C.Matrix_array;

			for (Position = 0; Position < Element_count; Position++)
			{
				*Matrix_C_array++ = *Matrix_A_array++ + *Matrix_B_array++;
			}

			break;
		}

		case UINT_TYPE:
		{
			unsigned* Matrix_A_array = (unsigned*)Matrix_array;
			unsigned* Matrix_B_array = (unsigned*)Matrix_B.Matrix_array;
			unsigned* Matrix_C_array = (unsigned*)Matrix_C.Matrix_array;

			for (Position = 0; Position < Element_count; Position++)
			{
				*Matrix_C_array++ = *Matrix_A_array++ + *Matrix_B_array++;
			}

			break;
		}

		case FLOAT_TYPE:
		{
			float* Matrix_A_array = (float*)Matrix_array;
			float* Matrix_B_array = (float*)Matrix_B.Matrix_array;
			float* Matrix_C_array = (float*)Matrix_C.Matrix_array;

			for (Position = 0; Position < Element_count; Position++)
			{
				*Matrix_C_array++ = *Matrix_A_array++ + *Matrix_B_array++;
			}

			break;
		}

		default:
		{
			break;
		}
	}
		
	return  (Matrix_C);
}