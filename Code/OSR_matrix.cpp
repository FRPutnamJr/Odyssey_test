/*******************************************************************************
* Title                 :   OSR Matrix Class
* Filename              :   OSR_matrix.cpp
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-11
* Version               :   1.0
* Compiler              :   Microsoft Visual Studio 2019 C30 v3.30c
* Target                :   PC
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description
*  2019/06/11       0.1              FRP      Created.
*  2019/06/12       0.2              FRP      Implemented constructor, destructor, overloaded get_element, overloaded set_element.
*  2019/06/13       0.3              FRP      Reworked overloaded get_element, overloaded set_element.
*                                             Implemented overloaded operator=, overloaded operator+=, overloaded+.
*  2019/06/14       0.4              FRP      Implemented overloaded operator*= (Scaler Multiplication).
*  2019/06/15       0.5              FRP      Implemented overloaded Transpose.
*  2019/06/17       1.0              FRP      Release.
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

#include "OSR_matrix.h"


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
	unsigned Element_count = this->get_number_of_rows() * this->get_number_of_columns();

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

OSR_matrix& OSR_matrix::operator*=(int Scaler_value)   // Scaler multiplication. 
{
	OSR_matrix& Scaler_matrix(*this);

	unsigned Position = 0;

	int* The_matrix_array = (int*)Matrix_array;
	int* Scaler_matrix_array = (int*)Scaler_matrix.Matrix_array;

	for (Position = 0; Position < this->_Number_of_elements; Position++)
	{
		*Scaler_matrix_array++ = *The_matrix_array++ * Scaler_value;
	}

	return  (Scaler_matrix);
}


OSR_matrix& OSR_matrix::operator*= (unsigned Scaler_value)
{
	OSR_matrix& Scaler_matrix(*this);

	unsigned Position = 0;

	unsigned* The_matrix_array    = (unsigned*)Matrix_array;
	unsigned* Scaler_matrix_array = (unsigned*)Scaler_matrix.Matrix_array;

	for (Position = 0; Position < this->_Number_of_elements; Position++)
	{
		*Scaler_matrix_array++ = *The_matrix_array++ * Scaler_value;
	}

	return  (Scaler_matrix);


}


OSR_matrix& OSR_matrix::operator*= (float Scaler_value)
{
	OSR_matrix& Scaler_matrix(*this);

	unsigned Position = 0;

	float* The_matrix_array    = (float*)Matrix_array;
	float* Scaler_matrix_array = (float*)Scaler_matrix.Matrix_array;

	for (Position = 0; Position < this->_Number_of_elements; Position++)
	{
		*Scaler_matrix_array++ = *The_matrix_array++ * Scaler_value;
	}

	return  (Scaler_matrix);
}


OSR_matrix& OSR_matrix::operator*= (char Scaler_value)
{
	OSR_matrix& Scaler_matrix(*this);

	unsigned Position = 0;

	char* The_matrix_array    = (char*)Matrix_array;
	char* Scaler_matrix_array = (char*)Scaler_matrix.Matrix_array;

	for (Position = 0; Position < this->_Number_of_elements; Position++)
	{
		*Scaler_matrix_array++ = *The_matrix_array++ * Scaler_value;
	}

	return  (Scaler_matrix);
}

/* 
   * Create return matrix derived of A_matrix.
   * Create array of elements to hold results of A_matrix * B_matrix.
   * Multiply A_matrix_row_elements by B_matrix_column_elements.
   * Add array of elements into return matrix elements.
   * Return new matrix.
*/
OSR_matrix& OSR_matrix::operator*=(OSR_matrix& Matrix_B)
{
	OSR_matrix Matrix_C(*this);				// Create return matrix derived of A_matrix.
	
	int* A_matrix_array = (int*)Matrix_array;
	int* B_matrix_array = (int*)Matrix_B.Matrix_array;
	int* C_matrix_array = (int*)Matrix_C.Matrix_array;


	int* AB_array = new int(_Number_of_elements);			// Create array of elements to hold results of A_matrix * B_matrix.

	unsigned Index = 0;
	unsigned Position = 0;

	// Multiply A_matrix_row_elements by B_matrix_column_elements.
	for (int A_row = 0; A_row < _Number_of_rows; A_row++)
	{
		B_matrix_array = (int*)Matrix_B.Matrix_array;

		for (int A_column = 0; A_column < _Number_of_columns; A_column++)
		{
			for (int B_row = 0; B_row < _Number_of_rows; B_row++)
			{
				AB_array[Index++] = (int)(*A_matrix_array * *B_matrix_array++);
			}

			A_matrix_array++;
		}
	}

	// Add array of elements into return matrix elements.
	*C_matrix_array = 0;

	for (Position = 0; Position < _Number_of_elements; Position++)
	{
		Index = Position;

		for (int Ix = 0; Ix < _Number_of_columns; Ix++)
		{
			*C_matrix_array += (int)AB_array[Index];

			Index += _Number_of_columns;
		}

		C_matrix_array++;
	}
	
	return  (Matrix_C);
}


const OSR_matrix OSR_matrix::Transpose(int Dummy_type)						// Transpose a matrix of signed integer elements.
{
	const OSR_matrix Transpose_matrix = OSR_matrix(this->get_number_of_columns(), this->get_number_of_rows(), this->get_type_of_element());
	
	int* Matrix_array_column_element = (int*)this->Matrix_array;
	int* Transpose_array_row_element = (int*)Transpose_matrix.Matrix_array;

	unsigned Row    = 0;
	unsigned Column = 0;

	for (Column=0; Column < Transpose_matrix._Number_of_columns; Column++)
	{
		for (Row = 0; Row < Transpose_matrix._Number_of_rows; Row++)
		{
			*(Transpose_array_row_element + (Row * Transpose_matrix._Number_of_columns)) = *Matrix_array_column_element++;
		}

		Transpose_array_row_element++;
	}

	return  (Transpose_matrix);
}


const OSR_matrix OSR_matrix::Transpose(unsigned Dummy_type)									// Transpose a matrix of unsigned integer elements.
{
	const OSR_matrix Transpose_matrix = OSR_matrix(this->get_number_of_columns(), this->get_number_of_rows(), this->get_type_of_element());

	unsigned* Matrix_array_column_element = (unsigned*)Matrix_array;
	unsigned* Transpose_array_row_element = (unsigned*)Transpose_matrix.Matrix_array;

	unsigned Row = 0;
	unsigned Column = 0;

	for (Column = 0; Column < Transpose_matrix._Number_of_columns; Column++)
	{
		for (Row = 0; Row < Transpose_matrix._Number_of_rows; Row++)
		{
			*(Transpose_array_row_element + (Row * Transpose_matrix._Number_of_columns)) = *Matrix_array_column_element++;
		}

		Transpose_array_row_element++;
	}

	return  (Transpose_matrix);
}

const OSR_matrix OSR_matrix::Transpose(float Dummy_type) 	 								// Transpose a matrix of float elements.
{
	const OSR_matrix Transpose_matrix = OSR_matrix(this->get_number_of_columns(), this->get_number_of_rows(), this->get_type_of_element());

	float* Matrix_array_column_element = (float*)this->Matrix_array;
	float* Transpose_array_row_element = (float*)Transpose_matrix.Matrix_array;

	unsigned Row = 0;
	unsigned Column = 0;

	for (Column = 0; Column < Transpose_matrix._Number_of_columns; Column++)
	{
		for (Row = 0; Row < Transpose_matrix._Number_of_rows; Row++)
		{
			*(Transpose_array_row_element + (Row * Transpose_matrix._Number_of_columns)) = *Matrix_array_column_element++;
		}

		Transpose_array_row_element++;
	}

	return  (Transpose_matrix);
}

const OSR_matrix OSR_matrix::Transpose(char Dummy_type)										// Transpose a matrix of byte elements.
{
	const OSR_matrix Transpose_matrix = OSR_matrix(this->get_number_of_columns(), this->get_number_of_rows(), this->get_type_of_element());

	char* Matrix_array_column_element = (char*)this->Matrix_array;
	char* Transpose_array_row_element = (char*)Transpose_matrix.Matrix_array;

	unsigned Row = 0;
	unsigned Column = 0;

	for (Column = 0; Column < Transpose_matrix._Number_of_columns; Column++)
	{
		for (Row = 0; Row < Transpose_matrix._Number_of_rows; Row++)
		{
			*(Transpose_array_row_element + (Row * Transpose_matrix._Number_of_columns)) = *Matrix_array_column_element++;
		}

		Transpose_array_row_element++;
	}

	return  (Transpose_matrix);
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