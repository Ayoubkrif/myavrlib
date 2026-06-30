#ifndef ISR_H
#define ISR_H

// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf#page=49&zoom=140,45,199

#define ISR_(n) __attribute__((signal)) void __vector_##n()

#define ISR_RESET                       ISR_(0)
#define ISR_EXTERNAL_0                  ISR_(1)
#define ISR_EXTERNAL_1                  ISR_(2)
#define ISR_PIN_CHANGE_0                ISR_(3)
#define ISR_PIN_CHANGE_1                ISR_(4)
#define ISR_PIN_CHANGE_2                ISR_(5)
#define ISR_WATCHDOG_TIMEOUT            ISR_(6)
#define ISR_TC2_COMPARE_MATCH_A         ISR_(7)
#define ISR_TC2_COMPARE_MATCH_B         ISR_(8)
#define ISR_TC2_OVERFLOW                ISR_(9)
#define ISR_TC1_CAPTURE                 ISR_(10)
#define ISR_TC1_COMPARE_MATCH_A         ISR_(11)
#define ISR_TC1_COMPARE_MATCH_B         ISR_(12)
#define ISR_TC1_OVERFLOW                ISR_(13)
#define ISR_TC0_COMPARE_MATCH_A         ISR_(14)
#define ISR_TC0_COMPARE_MATCH_B         ISR_(15)
#define ISR_TC0_OVERFLOW                ISR_(16)
#define ISR_SPI_TRANSFER_COMPLETE       ISR_(17)
#define ISR_USART_RECEPTION_COMPLETE    ISR_(18)
#define ISR_USART_DATA_REGISTER_EMPTY   ISR_(19)
#define ISR_USART_TRANSMISSION_COMPLETE ISR_(20)
#define ISR_ADC_CONVERSION_COMPLETE     ISR_(21)
#define ISR_EEPROM_READY                ISR_(22)
#define ISR_ANALOG_COMPARATOR           ISR_(23)
#define ISR_TWI                         ISR_(24)
#define ISR_SPM_READY                   ISR_(25)

#endif
