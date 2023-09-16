/*******************************************************************/
/* Author      : Abdalla Skar 								       */
/* Data		   : 3 August 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Description : LEDMATRIX									       */
/*******************************************************************/
#ifndef LEDMATRIX_INTERFACE_H
#define LEDMATRIX_INTERFACE_H


/* Initialization of led Matrix
 * ROWS Pins as output
 * Calms pins as output
 * Pins Number depend on configuration file */
void HLEDMATRIX_voidInit(void);

/*Display any character on led for little time */
void HLEDMATRIX_voidDisplay(u8* Copy_Pu8Data);


#define LEDMATRIX_A   0,124,18, 18, 124,0
#define LEDMATRIX_B   0,126,80, 80, 112,0
#define LEDMATRIX_C   0,60, 66, 66, 66 ,0
#define LEDMATRIX_D   0, 126, 66, 36,24,0
#define LEDMATRIX_E   0, 126, 74, 78, 0,0
#define LEDMATRIX_F   0, 126, 10, 10, 0,0
#define LEDMATRIX_G   0, 126, 66,82,114,0
#define LEDMATRIX_H   0, 126,16,16, 126,0
#define LEDMATRIX_I   0, 66, 126, 66, 0,0
#define LEDMATRIX_J   0, 0, 98, 66, 126,0
#define LEDMATRIX_K   0, 126, 24, 36,66,0
#define LEDMATRIX_L   0, 126, 64, 64, 0,0
#define LEDMATRIX_M   0, 126, 4, 8,4 ,126
#define LEDMATRIX_N   126, 4, ,16,32 ,126
#define LEDMATRIX_O   24, 36, 66,66,36,24
#define LEDMATRIX_P   0, 124, 10, 10 4, 0
#define LEDMATRIX_Q   0, 4, 10, 10,124,64
#define LEDMATRIX_R   0, 126, 26, 42,78,0
#define LEDMATRIX_S   0,78, 82, 82, 98, 0
#define LEDMATRIX_T   2, 2, 126 , 2, 2, 0
#define LEDMATRIX_U   0,126,64,64, 64,126
#define LEDMATRIX_V   0, 30, 32, 64,32,30
#define LEDMATRIX_W   62, 64, 32,32,64,62
#define LEDMATRIX_X   66, 36, 24,24,36,66
#define LEDMATRIX_Y   2, 4, 120 , 4, 2, 0
#define LEDMATRIX_Z   66,162,146,138,134,128




#endif
