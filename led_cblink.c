/*
 * led.c
 *
 *  Created on: Mar 5, 2021
 *      Author: 99003754
 */




/*
 * led_blink.c
 *
 *  Created on: Mar 5, 2021
 *      Author: 99003751
 */







#include"stm32fxx_gpio_driver.h"






void delay(void)
{
    for(uint32_t i=0;i<500000;i++);
}



uint8_t GPIO_PinNum;
uint8_t GPIO_PinMode;
uint8_t GPIO_Speed;
uint8_t GPIO_OTYPE;
uint8_t GPIO_PUPD;
uint8_t GPIO_AltFn;




int main()
{
    GPIO_HANDLE_t Gpio_led;
    Gpio_led.pGPIOx = GPIOD;
    Gpio_led.GPIO_Pinconfig. GPIO_PinNum=GPIO_PIN_NUM_14;
    //Gpio_led.GPIO_Pinconfig. GPIO_PinNum=GPIO_PIN_NUM_12;
    Gpio_led.GPIO_Pinconfig.GPIO_PinMode = GPIO_PIN_MODE_1;
    Gpio_led.GPIO_Pinconfig.GPIO_Speed = GPIO_Speed_3;
    Gpio_led.GPIO_Pinconfig.GPIO_OTYPE = GPIO_OTYPE_0;
    Gpio_led.GPIO_Pinconfig.GPIO_PUPD = GPIO_PUPD_2;
    GPIO_Peripheral_Clk(GPIOD, ENABLE);
    GPIO_INIT(&Gpio_led);


    while(1)
    {
        GPIO_TOGGLE(GPIOD,GPIO_PIN_NUM_14);
        //GPIO_WRITEPIN(GPIOD,GPIO_PIN_NUM_12,1);
        delay();
        //GPIO_TOGGLE(GPIOD,GPIO_PIN_NUM_12);
        //GPIO_WRITEPIN(GPIOD,GPIO_PIN_NUM_12,1);
        //delay();
    }
}
