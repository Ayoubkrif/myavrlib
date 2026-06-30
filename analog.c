/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:50:24 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "myavrlib.h"

inline void	ADC_Comp_Enable(void)
{
	BITSET(ADCSRB, ACME);
}

inline void	ADC_multiplexer_select(t_vref voltage, t_leftad ad, t_adcout adc)
{
	ADMUX = (voltage << 6) | (ad << 5) | adc;
}

inline void	ADC_128Pr(void)
{
	//Table 23-5. ADC Prescaler Selections
	//128
	//111
	BITSET(ADCSRA, ADPS0);
	BITSET(ADCSRA, ADPS1);
	BITSET(ADCSRA, ADPS2);
}

inline void	ADC_Enable(void)
{
	BITSET(ADCSRA, ADEN);
}

inline void	ADC_Disable(void)
{
	BITCLR(ADCSRA, ADEN);
}

inline void	ADC_Start(void)
{
	BITSET(ADCSRA, ADSC);
}

inline void	ADC_test(void)
{
	while(!BITCHECK(ADCSRA, ADSC));
}

uint8_t	ADC_check_8Bit(void)
{
	ADC_Start();
	ADC_test();
	return (ADCH);
}

uint16_t	ADC_check_16Bit(void)
{
	ADC_Start();
	ADC_test();
	return (ADC);
}
