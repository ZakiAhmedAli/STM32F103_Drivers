#ifndef	AFIO_PRIVATE_H
#define	AFIO_PRIVATE_H

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];//EXTICR0,EXTICR1,EXTICR2,EXTICR3,EXTICR4
	volatile u32 MAPR2;
	
}AFIO_Type;


#define AFIO ((volatile AFIO_Type *)(0x40010000))




#endif
