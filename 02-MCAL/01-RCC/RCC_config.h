/*******************************************************************/
/* Author     : Abdalla Mahmoud 								   */
/* Data		  : 9 Dec 2022										   */
/* Verstion   : V01												   */
/*******************************************************************/
#ifndef   RCC_CONFIG_H
#define   RCC_CONFIG_H


/* Options : RCC_HSE_CRYSTAL
			 RCC_HSE_RC
			 RCC_HSI
			 RCC_PLL */

#define  RCC_CLOCK_TYPE           RCC_HSE_CRYSTAL



/* Options : RCC_PLL_IN_HSI_DIV_2
			 RCC_PLL_IN_HSE_DIV_2
			 RCC_PLL_IN_HSE   
			 */
/*PLL MUL from 2 to 16 */
/* Note : select value only when RCC_CLOCK_TYPE = RCC_PLL */
#if RCC_CLOCK_TYPE == RCC_PLL

#define  RCC_PLL_INPUT           RCC_PLL_IN_HSI_DIV_2
#define  RCC_PLL_MUL_VAL         2

#endif







#endif
