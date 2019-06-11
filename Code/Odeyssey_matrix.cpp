/*******************************************************************************
* Title                 :   OSR Matrix Class
* Filename              :   OSR_matrix.h
* Author                :   Frank Putnam, Jr.
* Origin Date           :   2019-06-11
* Version               :   1.0.0
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
/** @file XXX.c
 *  @brief This module contains the
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
#define   CONSTANT					5

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
  * Function : Pwm_Init()
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
  *    Pwm_Init();
  * @endcode
  *
  * @see Pwm_Enable
  *
  *  ----------------------
  *  - HISTORY OF CHANGES -
  *  ----------------------
  *    Date    Software Version    Initials   Description
  *  XX/XX/XX    XXXXXXXXXXX         JWB      Function Created.
  *
  *******************************************************************************/


/*************** END OF FUNCTIONS ***************************************************************************/
// Odeyssey_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "OSR_matrix.h"

int main()
{
	OSR_matrix* A_matrix = new OSR_matrix(2,2,OSR_matrix::UINT_TYPE);

	std::cout << "Rows " << A_matrix->get_number_of_rows() << "   Columns " << A_matrix->get_number_of_columns() << '/n';
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages 
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
