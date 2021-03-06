/*
 * stm32fxx_gpio_driver.c
 *
 *  Created on: Mar 5, 2021
 *      Author: 99003754
 */
#include"stm32fxx_gpio_driver.h"




void GPIO_Peripheral_Clk(GPIO_RegDef *pGPIOx,uint8_t EN_DI)
{
    if(EN_DI==ENABLE)
    {
        if(pGPIOx==GPIOA)
        {
            GPIOA_PCLOCK_ENABLE;
        }
        else if(pGPIOx==GPIOB)
        {
            GPIOB_PCLOCK_ENABLE;
        }
        else if(pGPIOx==GPIOC)
        {
            GPIOC_PCLOCK_ENABLE;
        }
        else if(pGPIOx==GPIOD)
        {
            GPIOD_PCLOCK_ENABLE;
        }
        else if(pGPIOx==GPIOE)
        {
            GPIOE_PCLOCK_ENABLE;
        }
        else if(pGPIOx==GPIOF)
        {
            GPIOF_PCLOCK_ENABLE;
        }
        else if(pGPIOx==GPIOH)
        {
            GPIOH_PCLOCK_ENABLE;
        }
        else if(pGPIOx==GPIOI)
        {
            GPIOI_PCLOCK_ENABLE;
        }



    }
    else
    {
        if(pGPIOx==GPIOA)
        {
            GPIOA_PCLOCK_DISABLE;
        }
        else if(pGPIOx==GPIOB)
        {
            GPIOB_PCLOCK_DISABLE;
        }
        else if(pGPIOx==GPIOC)
        {
            GPIOC_PCLOCK_DISABLE;
        }
        else if(pGPIOx==GPIOD)
        {
            GPIOD_PCLOCK_DISABLE;
        }
        else if(pGPIOx==GPIOE)
        {
            GPIOE_PCLOCK_DISABLE;
        }
        else if(pGPIOx==GPIOF)
        {
            GPIOF_PCLOCK_DISABLE;
        }
        else if(pGPIOx==GPIOH)
        {
            GPIOH_PCLOCK_DISABLE;
        }
        else if(pGPIOx==GPIOI)
        {
            GPIOI_PCLOCK_DISABLE;
        }
    }
}




void GPIO_INIT(GPIO_HANDLE_t *pGPIO_Handle)
{
    //configure the pin mode
    uint32_t temp;



            temp = ((pGPIO_Handle ->GPIO_Pinconfig.GPIO_PinMode) << (2*pGPIO_Handle->GPIO_Pinconfig.GPIO_PinNum));
            pGPIO_Handle ->pGPIOx->MODER = ~(0x3) << (2*pGPIO_Handle->GPIO_Pinconfig.GPIO_PinNum);
            pGPIO_Handle ->pGPIOx->MODER = temp;






            //####################  2. config Pin OTYPER ####################





            uint16_t dummy;
            dummy = (pGPIO_Handle ->GPIO_Pinconfig.GPIO_OTYPE) << (pGPIO_Handle->GPIO_Pinconfig.GPIO_PinNum);
            pGPIO_Handle ->pGPIOx->OTYPER = ~(0x1) << (pGPIO_Handle->GPIO_Pinconfig.GPIO_PinNum);
            pGPIO_Handle ->pGPIOx->OTYPER = dummy;






            //#################### 3. Config Ospeed ####################





            uint32_t result;
            result = (pGPIO_Handle ->GPIO_Pinconfig.GPIO_Speed) << (2*pGPIO_Handle->GPIO_Pinconfig.GPIO_PinNum);



            pGPIO_Handle->pGPIOx->OSPEEDR &= ~( 0x3 << ( 2 * pGPIO_Handle->GPIO_Pinconfig.GPIO_PinNum)); //clearing
            pGPIO_Handle->pGPIOx->OSPEEDR |= result;






            // #################### 4. Config PUPD ####################
            uint32_t result1;
            result1 = (pGPIO_Handle ->GPIO_Pinconfig.GPIO_PUPD) << (2*pGPIO_Handle->GPIO_Pinconfig.GPIO_PinNum);
            pGPIO_Handle ->pGPIOx->PUPDR = ~(0x3 << (2*pGPIO_Handle->GPIO_Pinconfig.GPIO_PinNum));
            pGPIO_Handle ->pGPIOx->PUPDR = result1;







            //####################  Config Alt fxn  ####################
            uint8_t temp1, temp2;
            temp1 = pGPIO_Handle ->GPIO_Pinconfig.GPIO_PinNum/8;
            temp2 = pGPIO_Handle ->GPIO_Pinconfig.GPIO_PinNum % 8;
            pGPIO_Handle->pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2 ) ); //clearing
            pGPIO_Handle->pGPIOx->AFR[temp1] |= (pGPIO_Handle->GPIO_Pinconfig.GPIO_AltFn << ( 4 * temp2 ) );



}
void GPIO_DINIT(GPIO_RegDef *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_PCLOCK_DISABLE;
	}
	else if (pGPIOx == GPIOB)
	{
		GPIOB_PCLOCK_DISABLE;
	}
	else if (pGPIOx == GPIOC)
	{
		GPIOC_PCLOCK_DISABLE;
	}
	else if (pGPIOx == GPIOD)
	{
		GPIOD_PCLOCK_DISABLE;
	}
	else if (pGPIOx == GPIOE)
	{
		GPIOE_PCLOCK_DISABLE;
	}
	else if (pGPIOx == GPIOF)
	{
		GPIOF_PCLOCK_DISABLE;
	}
	else if (pGPIOx == GPIOG)
	{
		GPIOG_PCLOCK_DISABLE;
	}
	else if (pGPIOx == GPIOH)
	{
		GPIOH_PCLOCK_DISABLE;
	}
	else if (pGPIOx == GPIOI)
	{
		GPIOI_PCLOCK_DISABLE;
	}

}



// III. Read/Write to/from port/pin
void GPIO_WRITEPORT(GPIO_RegDef *pGPIOx,uint16_t value)
{
    pGPIOx->ODR=value;
}
void GPIO_WRITEPIN(GPIO_RegDef *pGPIOx,uint8_t GPIO_PIN_NUM,uint16_t value)
{
    if(value==SET)
    {
        pGPIOx->ODR |=1<<GPIO_PIN_NUM;
    }
    else
    {
        pGPIOx->ODR &=~(1<<GPIO_PIN_NUM);
    }
}



uint16_t GPIO_READPIN(GPIO_RegDef *pGPIOx,uint8_t GPIO_PIN_NUM)
{
    uint8_t temp;
    temp= (uint8_t)(pGPIOx -> IDR>>GPIO_PIN_NUM & 0x00000001);
    return temp;
}




uint16_t GPIO_READPORT(GPIO_RegDef *pGPIOx)
{
    uint16_t temp;
    temp=pGPIOx->IDR;
    return temp;
}







void GPIO_TOGGLE(GPIO_RegDef *pGPIOx,uint8_t GPIO_PIN_NUM)
{
    pGPIOx->ODR ^=(1<<GPIO_PIN_NUM);
}
