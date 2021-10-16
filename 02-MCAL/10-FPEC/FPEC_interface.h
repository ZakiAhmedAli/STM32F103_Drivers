/*******************************************************************/
/*	Auther	    : zaki ahmed hamed						`		   */
/*  Date 	    : 10 October 2020								   */
/*  Description : FPEC_interface.h file contain function prototypes*/
/*  Version     : V02											   */
/*  LOG			: V01 -> Initial creation						   */
/*              : V02 -> Add function void FPEC_voidEraseMass(void)*/
/*******************************************************************/


/**************************************************************************
* Description : Guard to Protect this file from include more than one time*
**************************************************************************/	
#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

/*
	Function Name        : FPEC_voidUnLock
	Function Returns     : void
	Function Arguments   : void
	Function Description : Check FLASH_CR_LOCK and Perform unlock sequency.
*/
void FPEC_voidUnLock(void);

/*
	Function Name        : MFPEC_voidEraseAppArea
	Function Returns     : void
	Function Arguments   : void
	Function Description : This function is used to erase the app area.
	PRE-CONDITION		 : Internal clock cycle must be enabled.
	PRE-CONDITION		 : The first page number in app area must be defined in FPEC_config.
	PRE-CONDITION		 : The last  page number in app area must be defined in FPEC_config.
	POST-CONDITION       : None
*/
void MFPEC_voidEraseAppArea(void);


/*
	Function Name        : FPEC_voidWriteWord

	Function Returns     : void

	Function Arguments   : u32 Copy_u32Address, u16 *Copy_u16Data , u8 Copy_u8Length

	Function Description : This function is used to write code on the flash using flash driver peripheral.

	PRE-CONDITION		 : Internal clock cycle must be enabled.

	PRE-CONDITION		 : App area must be erased before writing operation.

	POST-CONDITION       : None
*/
void FPEC_voidWriteWord(u32 Copy_u32Address, u16 *Copy_u16Data , u8 Copy_u8Length);

/*
	Function Name        : FPEC_u8WriteHalfPage

	Function Returns     : u8 -> The state of writing done or not.

	Function Arguments   : u32 Copy_u32Address, u16 Copy_u16Data

	Function Description : This function is used to write code on the flash using flash driver peripheral.

	PRE-CONDITION		 : Internal clock cycle must be enabled.

	PRE-CONDITION		 : App area must be erased before writing operation.

	POST-CONDITION       : None
*/
u8 FPEC_u8WriteHalfPage(u32 Copy_u32Address, u16 Copy_u16Data );


/*
	Function Name        : FPEC_voidErsePage

	Function Returns     : void

	Function Arguments   : u32 Copy_u32Address

	Function Description : This function is used to erase page of the flash.

	PRE-CONDITION		 : Internal clock cycle must be enabled.

	POST-CONDITION       : None
*/
void FPEC_voidErsePage(u32 Copy_u32Address);

/*
	Function Name        : FPEC_voidEraseMass

	Function Returns     : void

	Function Arguments   : void

	Function Description : This function is used to erase full flash.

	PRE-CONDITION		 : Internal clock cycle must be enabled.

	POST-CONDITION       : None
*/
void FPEC_voidEraseMass(void);



#endif //FPEC_INTERFACE_H