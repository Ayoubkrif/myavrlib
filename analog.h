/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analog.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:52:53 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALOG_H
#define ANALOG_H

#include <stdint.h>

typedef enum e_vref
{
	AREF = 0,
	AVCC = 1,
	INTERNAL_1_1V = 3
}	t_vref;

typedef enum e_adcout
{
	ADC0 = 0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ADC8
}	t_adcout;

typedef enum e_leftad
{
	R10_BIT = 0,
	R8_BIT = 1
}	t_leftad;

void		ADC_Enable(void);

void		ADC_Disable(void);

void		ADC_Start(void);

void		ADC_Comp_Enable(void);

void		ADC_multiplexer_select(t_vref, t_leftad,t_adcout);

void		ADC_128Pr(void);

void		ADC_test(void);

uint8_t		ADC_check_8Bit(void);

uint16_t	ADC_check_16Bit(void);

//23.8.1 Manufacturing Calibration p216
// #define TS_OFFSET	(-320)
// #define TS_GAIN		(1)
#define TS_OFFSET	(250) // pour avoir une valeur okay
#define TS_GAIN		(1) // 128 / 164 = 0.78 pente ~= 1

#endif
