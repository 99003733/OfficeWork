/*
 * stm32fxx_gpio_driver.h
 *
 *  Created on: Mar 5, 2021
 *      Author: 99003754
 */



#ifndef INC_STM32FXX_GPIO_DRIVER_H_
#define INC_STM32FXX_GPIO_DRIVER_H_
#include"stm32f4xx.h"



typedef struct{
    uint8_t GPIO_PinNum;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_Speed;
    uint8_t GPIO_OTYPE;
    uint8_t GPIO_PUPD;
    uint8_t GPIO_AltFn;
}GPIO_Pinconfig_t;



//handle structure
typedef struct{
    GPIO_RegDef *pGPIOx; //declared  a pointer variable of GPIO_REGdef type for selecting the port
    GPIO_Pinconfig_t GPIO_Pinconfig; //declaring variable for pin configuration of structure type gpio_pin_config
}GPIO_HANDLE_t;



//strcutrue for gpiopinconfig



//creating API Prototypes



// I. Peripheral Clock enable or disable
void GPIO_Peripheral_Clk(GPIO_RegDef *pGPIOx,uint8_t EN_DI);



// II. Initialisation and Dinit
void GPIO_INIT(GPIO_HANDLE_t *pGPIO_Handle);
void GPIO_DINIT(GPIO_RegDef *pGPIOx);



// III. Read/Write to/from port/pin
void GPIO_WRITEPORT(GPIO_RegDef *pGPIOx,uint16_t value);
void GPIO_WRITEPIN(GPIO_RegDef *pGPIOx,uint8_t GPIO_PIN_NUM,uint16_t value);
uint16_t GPIO_READPIN(GPIO_RegDef *pGPIOx,uint8_t GPIO_PIN_NUM);
uint16_t GPIO_READPORT(GPIO_RegDef *pGPIOx);
void GPIO_TOGGLE(GPIO_RegDef *pGPIOx,uint8_t GPIO_PIN_NUM);



//Defning macros for PinNum
#define GPIO_PIN_NUM_0 0
#define GPIO_PIN_NUM_1 1
#define GPIO_PIN_NUM_2 2
#define GPIO_PIN_NUM_3 3
#define GPIO_PIN_NUM_4 4
#define GPIO_PIN_NUM_5 5
#define GPIO_PIN_NUM_6 6
#define GPIO_PIN_NUM_7 7
#define GPIO_PIN_NUM_8 8
#define GPIO_PIN_NUM_9 9
#define GPIO_PIN_NUM_10 10
#define GPIO_PIN_NUM_11 11
#define GPIO_PIN_NUM_12 12
#define GPIO_PIN_NUM_13 13
#define GPIO_PIN_NUM_14 14
#define GPIO_PIN_NUM_15 15




#define GPIO_PIN_MODE_0 0
#define GPIO_PIN_MODE_1 1
#define GPIO_PIN_MODE_2 2
#define GPIO_PIN_MODE_3 3



#define GPIO_Speed_0 0
#define GPIO_Speed_1 1
#define GPIO_Speed_2 2
#define GPIO_Speed_3 3



#define GPIO_OTYPE_0 0
#define GPIO_OTYPE_1 1



#define GPIO_PUPD_0 0
#define GPIO_PUPD_1 1
#define GPIO_PUPD_2 2



#define GPIO_AFN_0 0
#define GPIO_AFN_1 1
#define GPIO_AFN_2 2
#define GPIO_AFN_3 3
#define GPIO_AFN_4 4
#define GPIO_AFN_5 5
#define GPIO_AFN_6 6
#define GPIO_AFN_7 7
#define GPIO_AFN_8 8
#define GPIO_AFN_9 9
#define GPIO_AFN_10 10
#define GPIO_AFN_11 11
#define GPIO_AFN_12 12
#define GPIO_AFN_13 13
#define GPIO_AFN_14 14
#define GPIO_AFN_15 15









#endif /* INC_STM32FXX_GPIO_DRIVER_H_ */
