/*
	Auther		: Zaki Ahmed Hamed	
	Description	: IR_init.h file contain IR APIs and public macros
	Date		: 09-Sep-2020
	Version		: V02	

*/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef	IR_INIT_H
#define IR_INIT_H

/*************** macros for Remote buttons data values   *********************/
#define BSTOP		69
#define BMODE		70
#define BMUTE		71
#define BVOL_UP		9
#define BVOL_DOWN	21
#define BNEXT		67
#define BBACK		64
#define BRESUME		68
#define BZERO		82
#define BONE		12	
#define BTWO		24
#define BTHREE		94
#define BFOUR		8
#define BFIVE		28
#define BSIX		90
#define BSEVEN		66
#define BEIGHT		82
#define BNINE		74

/***************************************************************************/

/************************ Functions Prototypes *****************************/

void IR_voidGetFrame(void);


void IR_voidTakeAction(void);

void IR_voidCheckFram(void);







#endif	//IR_INIT_H