//    This is MCU Specific Header File
#include<stdio.h>
//memory location macros
#define SRAM1_BASE_ADDR 0x20000000U
#define SRAM2_BASE_ADDR 0x2001C000U
#define FLASH_MEM_ADDR 0x08000000U
#define ROM_ADDR 0x1FFF0000U



//macros for bus
#define ENABLE    1
#define DISABLE   0
#define SET       1
#define RESET     0



#define APB1_BASE_ADDR 0x40000000U
#define APB2_BASE_ADDR 0x40010000U
#define AHB1_BASE_ADDR 0x40020000U
#define AHB2_BASE_ADDR 0x50000000U
#define AHB3_BASE_ADDR 0xA0000000U



//Macros for rcc
#define RCC_BASE_ADDR (AHB1_BASE_ADDR+ 0x3800)




//MACROS FOR PERIPHERAL ON APB1 BUS



#define TIM2_BASE_ADDR (APB1_BASE_ADDR+0x00)
#define TIM3_BASE_ADDR (APB1_BASE_ADDR+0x0400)
#define TIM4_BASE_ADDR (APB1_BASE_ADDR+0x0800)
#define TIM5_BASE_ADDR (APB1_BASE_ADDR+0x0C00)
#define TIM6_BASE_ADDR (APB1_BASE_ADDR+0x1000)
#define TIM7_BASE_ADDR (APB1_BASE_ADDR+0x1400)
#define TIM12_BASE_ADDR (APB1_BASE_ADDR+0x1800)
#define TIM13_BASE_ADDR (APB1_BASE_ADDR+0x1C00)
#define TIM14_BASE_ADDR (APB1_BASE_ADDR+0x2000)
#define DAC_BASE_ADDR (APB1_BASE_ADDR + 0x7400)
#define PWR_BASE_ADDR (APB1_BASE_ADDR + 0x7000)
#define CAN2_BASE_ADDR (APB1_BASE_ADDR + 0x6800)
#define CAN1_BASE_ADDR (APB1_BASE_ADDR + 0x6400)
#define I2C3_BASE_ADDR (APB1_BASE_ADDR + 0x5C00)
#define I2C2_BASE_ADDR (APB1_BASE_ADDR + 0x5800)
#define I2C1_BASE_ADDR (APB1_BASE_ADDR + 0x5400)
#define UART8_BASE_ADDR (APB1_BASE_ADDR + 0x7C00)
#define UART7_BASE_ADDR (APB1_BASE_ADDR + 0x7800)
#define UART5_BASE_ADDR (APB1_BASE_ADDR + 0x5000)
#define UART4_BASE_ADDR (APB1_BASE_ADDR + 0x4C00)
#define USART3_BASE_ADDR (APB1_BASE_ADDR + 0x4800)
#define USART2_BASE_ADDR (APB1_BASE_ADDR + 0x4400)
#define I2S3EXT_BASE_ADDR (APB1_BASE_ADDR + 0x4000)
#define RTC_BKP_BASE_ADDR (APB1_BASE_ADDR + 0x2800)
#define WWDG_BASE_ADDR (APB1_BASE_ADDR + 0x2C00)
#define IWDG_BASE_ADDR (APB1_BASE_ADDR + 0x3000)
#define I2S2EXT_BASE_ADDR (APB1_BASE_ADDR + 0x3400)
#define SPI2_BASE_ADDR (APB1_BASE_ADDR + 0x3800)
#define SPI3_BASE_ADDR (APB1_BASE_ADDR + 0x3C00)



//Macros for peripherals managing onto APB2
#define TIM1_BASE_ADDR (APB2_BASE_ADDR + 0x0000)
#define TIM8_BASE_ADDR (APB2_BASE_ADDR + 0x0400)
#define USART1_BASE_ADDR (APB2_BASE_ADDR + 0x1000)
#define USART6_BASE_ADDR (APB2_BASE_ADDR + 0x1400)
#define ADC_BASE_ADDR (APB2_BASE_ADDR + 0x2000)
#define SDIO_BASE_ADDR (APB2_BASE_ADDR + 0x2C00)
#define SPI1_BASE_ADDR (APB2_BASE_ADDR + 0x3000)
#define SPI4_BASE_ADDR (APB2_BASE_ADDR + 0x3400)
#define SYSCFG_BASE_ADDR (APB2_BASE_ADDR + 0x3800)
#define EXTI_BASE_ADDR (APB2_BASE_ADDR + 0x3C00)
#define TIM9_BASE_ADDR (APB2_BASE_ADDR + 0x4000)
#define TIM10_BASE_ADDR (APB2_BASE_ADDR + 0x4400)
#define TIM11_BASE_ADDR (APB2_BASE_ADDR + 0x4800)
#define SPI5_BASE_ADDR (APB2_BASE_ADDR + 0x5000)
#define SPI6_BASE_ADDR (APB2_BASE_ADDR + 0x5400)
#define SAI1_BASE_ADDR (APB2_BASE_ADDR + 0x5800)
#define LCDTFT_BASE_ADDR (APB2_BASE_ADDR + 0x6800)





//MACROS FOR GPIO
#define GPIOA_BASE_ADDR (AHB1_BASE_ADDR + 0x00)
#define GPIOB_BASE_ADDR (AHB1_BASE_ADDR + 0x0400)
#define GPIOC_BASE_ADDR (AHB1_BASE_ADDR + 0x0800)
#define GPIOD_BASE_ADDR (AHB1_BASE_ADDR + 0x0C00)
#define GPIOE_BASE_ADDR (AHB1_BASE_ADDR + 0x1000)
#define GPIOF_BASE_ADDR (AHB1_BASE_ADDR + 0x1400)
#define GPIOG_BASE_ADDR (AHB1_BASE_ADDR + 0x1800)
#define GPIOH_BASE_ADDR (AHB1_BASE_ADDR + 0x1C00)
#define GPIOI_BASE_ADDR (AHB1_BASE_ADDR + 0x2000)
#define GPIOJ_BASE_ADDR (AHB1_BASE_ADDR + 0x2400)
#define GPIOK_BASE_ADDR (AHB1_BASE_ADDR + 0x2800)



//GPIO register definitions
typedef struct{
volatile uint32_t MODER; //+0x00 offset
volatile uint32_t OTYPER;// 0x04 0ffset
volatile uint32_t OSPEEDR;//+0x08
volatile uint32_t PUPDR;//+0x0C
volatile uint32_t IDR;//+0x10
volatile uint32_t ODR;//+0x14
volatile uint32_t BSRR;//+0x18
volatile uint32_t LCKR;//+0x1C
volatile uint32_t AFR[2];//+0x20
}GPIO_RegDef;





typedef struct{
    volatile uint32_t RCC_CR; //0x00
    volatile uint32_t RCC_PLLCFGR; //0x04
    volatile uint32_t RCC_CFGR;//0x08
    volatile uint32_t RCC_CIR;//0x0c
    volatile uint32_t RCC_AHB1RSTR;//0x10
    volatile uint32_t RCC_AHB2RSTR;//0x14
    volatile uint32_t RCC_AHB3RSTR;//0x18
    uint32_t      RESERVED0;
    volatile uint32_t RCC_APB1RSTR;//0x20
    volatile uint32_t RCC_APB2RSTR;//0x24
    uint32_t      RESERVED1[2];
    volatile uint32_t RCC_AHB1ENR;//0x30
    volatile uint32_t RCC_AHB2ENR;//0x34
    volatile uint32_t RCC_AHB3ENR;//0x38
    uint32_t      RESERVED2;
    volatile uint32_t RCC_APB1ENR;//040
    volatile uint32_t RCC_APB2ENR;//0x44
    uint32_t      RESERVED3[2];
    volatile uint32_t RCC_AHB1LPENR;//0x50
    volatile uint32_t RCC_AHB2LPENR;//0x54
    volatile uint32_t RCC_AHB3LPENR;//0x58
    uint32_t      RESERVED4;
    volatile uint32_t RCC_APB1LPENR;//0x60
    volatile uint32_t RCC_APB2LPENR;//0x64
    uint32_t      RESERVED5[2];
    volatile uint32_t RCC_BDCR;//0x70
    volatile uint32_t RCC_CSR;//0x74
    uint32_t      RESERVED6[2];
    volatile uint32_t RCC_SSCGR;//0x80
    volatile uint32_t RCC_PLLI2SCFGR;//0x84
}RCC_RegDef;



#define RCC ((RCC_RegDef*)RCC_BASE_ADDR)



#define GPIOA (GPIO_RegDef*)GPIOA_BASE_ADDR
#define GPIOB (GPIO_RegDef*)GPIOB_BASE_ADDR
#define GPIOC (GPIO_RegDef*)GPIOC_BASE_ADDR
#define GPIOD (GPIO_RegDef*)GPIOD_BASE_ADDR
#define GPIOE (GPIO_RegDef*)GPIOE_BASE_ADDR
#define GPIOF (GPIO_RegDef*)GPIOF_BASE_ADDR
#define GPIOG (GPIO_RegDef*)GPIOG_BASE_ADDR
#define GPIOH (GPIO_RegDef*)GPIOH_BASE_ADDR
#define GPIOI (GPIO_RegDef*)GPIOI_BASE_ADDR
#define GPIOJ (GPIO_RegDef*)GPIOJ_BASE_ADDR
#define GPIOK (GPIO_RegDef*)GPIOK_BASE_ADDR







//macros for enabling clock for gpios



#define GPIOA_PCLOCK_ENABLE (RCC -> RCC_AHB1ENR = (1<<0))
#define GPIOB_PCLOCK_ENABLE (RCC->RCC_AHB1ENR=(1<<1))
#define GPIOC_PCLOCK_ENABLE (RCC->RCC_AHB1ENR=(1<<2))
#define GPIOD_PCLOCK_ENABLE (RCC->RCC_AHB1ENR=(1<<3))
#define GPIOE_PCLOCK_ENABLE (RCC->RCC_AHB1ENR=(1<<4))
#define GPIOF_PCLOCK_ENABLE (RCC->RCC_AHB1ENR=(1<<5))
#define GPIOG_PCLOCK_ENABLE (RCC->RCC_AHB1ENR=(1<<6))
#define GPIOH_PCLOCK_ENABLE (RCC->RCC_AHB1ENR=(1<<7))
#define GPIOI_PCLOCK_ENABLE (RCC->RCC_AHB1ENR=(1<<8))



//macros for DISBALING clock for gpios
#define GPIOA_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<0))
#define GPIOB_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<1))
#define GPIOC_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<2))
#define GPIOD_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<3))
#define GPIOE_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<4))
#define GPIOF_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<5))
#define GPIOG_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<6))
#define GPIOH_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<7))
#define GPIOI_PCLOCK_DISABLE (RCC->RCC_AHB1ENR=~(1<<8))
