/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myavrlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:43:18 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYAVRLIB
# define MYAVRLIB

#include <avr/io.h>
#include "isr.h"
#include "BitOp.h"
#include "PortIO.h"
#include "UART.h"
#include "interrupt.h"
#include "isr.h"
#include "analog.h"
#include "i2c.h"
#include "EEPROM.h"
#include "SPI.h"

//mod 01
void	CTC_Toggle_Timer1(void);

void	FastPWM_ICR1TOP_Timer1(void);

void	CTC_interrupt_Timer1(void);// mod02 ex01

//mod03

void	Timer1_FastPWM_TopICR1A(void);
void	Timer1_noPr(void);
void	Timer1_1024Pr(void);
void	Timer1_CTC(void);
void	Timer1_AClearOnComp(void); // work on fast pwm

void	Timer2_FastPWM(void);
void	Timer2_1024Pr(void);
void	Timer2_noPr(void);
void	Timer2_BClearOnComp(void); // work on fast pwm

void	Timer0_FastPWM(void);
void	Timer0_CTC(void);// mod01 ex02
void	Timer0_normal(void); 
void	Timer0_1024Pr(void);
void	Timer0_64Pr(void);
void	Timer0_noPr(void);
void	Timer0_AClearOnComp(void); // work on fast pwm
void	Timer0_BClearOnComp(void); // work on fast pwm
void	Timer0_Int_A_Enable(void);// mod01 ex02
void	Timer0_Int_A_Disable(void);// mod01 ex02
void	Timer0_Int_Ov_Enable(void);// mod01 ex02
void	Timer0_Int_Ov_Disable(void);// mod01 ex02
//
//
#endif
