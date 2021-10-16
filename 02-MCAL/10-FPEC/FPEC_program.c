/*
  Auther	  : zaki ahmed hamed						`		   
  Date 	      : 10 October 2020								   
  file        : FPEC_program.c
  Description : This file includes FPEC Driver implementations			   
  Version     : V02											   
  LOG		  : V01 -> Initial creation						   
              : V02 -> Add function void FPEC_voidEraseMass(void)
*/

/* Includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"
#include "FPEC_config.h"
#include "FPEC_private.h"




void FPEC_voidUnLockSequence(void)
{
	if(GET_BIT(FPEC-> FLASH_CR , LOCK))
	{
		/*perform unlock sequence*/
		FPEC -> FLASH_KEYR = FPEC_KEY1;
		FPEC -> FLASH_KEYR = FPEC_KEY2;
	}
	
}

void MFPEC_voidEraseAppArea(void)
{
	u8 LOC_u8Counter = 0;
	for(LOC_u8Counter = FIRST_PAGE_APP_AREA ; LOC_u8Counter < LAST_PAGE_APP_AREA ; LOC++)
	{
		FPEC_voidErsePage(LOC_u8Counter);
	}
	
}
void FPEC_voidWriteWord(u32 Copy_u32Address, u16 *Copy_u16Data , u8 Copy_u8Length);
{
	u16 LOC_u8State=0;
	
	u8 Counter=0;
	
	/*Check that no main Flash memory operation is ongoing.*/
    while(GET_BIT(FPEC->FLASH_SR, BSY));
	
	/* 	Check if FPEC is locked or not,
		perform unlock sequence*/
	FPEC_voidUnLockSequence();
	
	for(Counter =0 ; Counter < Copy_u8Length ; Counter++)
	{
		/*Write FLASH programming*/
		SET_BIT(FPEC-> FLASH_CR , PG);
	   	
		/*Perform half-word write at the desired address*/
		*((u16*)Copy_u32Address) = Copy_u16Data[Counter];
		
		Copy_u32Address +=2;
	
		/* Wait till the wirte is done */
		while(GIT_BIT ((FPEC -> FLASH_SR ), BSY ));
		
		/* End of operation*/
		SET_BIT(FPEC-> FLASH_SR , EOP);
		
		/*disable Page Erase chosen.*/
		CLR_BIT(FPEC-> FLASH_CR , PG);
		
	}
}

u8 FPEC_u8WriteHalfPage(u32 Copy_u32Address, u16 Copy_u16Data )
{
	u8 = LOC_u8State=0;
	
	/*perform unlock sequence*/
	FPEC_voidUnLockSequence();
	
	
	/* This indicates that a Flash operation is in progress. 
	  This is set on the beginning of a Flash operation   */
    while(GET_BIT(FPEC->FLASH->SR, BSY));
	
	/*select page erase*/
	SET_BIT(FPEC->FLASH_CR , PG);
	
	/*Perform the data write (half-word) at the desired address.*/
	*((volatile u16*)Copy_u32Address) =  Copy_u16Data;
	
	/* Wait till the erase is done */
	while(GET_BIT(FPEC->FLASH->SR, BSY));
	
	/*End of operation*/
	SET_BIT(FPEC->FLASH_SR , EOP);
	
	/*page erase*/
	CLR_BIT(FPEC->FLASH_CR , PG);
	
	if( *((volatile u16*)Copy_u32Address) == Copy_u16Data )
	{
		 LOC_u8State  = WRITE_COMPLETE;
	}
	else
  	{
		LOC_u8State = WRITE_ERROR;
	}
	
	return LOC_u8State;

}


void FPEC_voidErsePage(u32 Copy_u32Address)
{
	 /*Check that no main Flash memory operation is ongoing.*/
    while(GET_BIT(FPEC->FLASH_SR, BSY));
	
	/*perform unlock sequence*/
	FPEC_voidUnLockSequence();
	
	/*enable Page Erase Operation */
	SET_BIT(FPEC-> FLASH_CR , PER);
	
	/*write the address within the page to erase*/
	
	FPEC->FLASH_AR = FLASH_START_ADDRESS + (u32)(Copy_u32Address * PAGE_SIZE);
	
	/* Start erase operation*/
	SET_BIT(FPEC-> FLASH_CR , STAR);
	
	/* Wait till the erase is done */
	while(GIT_BIT(FPEC -> FLASH_SR , BSY ));
	
	/* End of operation*/
	SET_BIT(FPEC-> FLASH_SR , EOP);
	
	/*disable Page Erase chosen.*/
	CLR_BIT(FPEC-> FLASH_CR , PER);
}

void FPEC_voidEraseMass(void)
{
		/*Check that no main Flash memory operation is ongoing.*/
    while(GET_BIT(FPEC->FLASH_SR, BSY));
	
	/* 	Check if FPEC is locked or not,
		perform unlock sequence*/
	FPEC_voidUnLockSequence();
	
	/*Erase of all user pages*/
	SET_BIT(FPEC->FLASH_CR , MER);
	
	/* Set the STRT bit in the FLASH_CR register to start mass erase operation.*/
    SET_BIT(FPEC->FLASH_CR, STRT);
	
	/*Wait for the BSY bit to be reset*/
    while(GET_BIT(FPEC->FLASH_SR, BSY));
	/*End of operation*/
	SET_BIT(FPEC->FLASH_SR , EOP);
	/*page erase*/
	CLR_BIT(FPEC->FLASH_CR , PG);
}