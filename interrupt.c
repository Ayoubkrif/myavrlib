/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:04:47 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "interrupt.h"
#include "myavrlib.h"

// chapter 12-2 datasheet
// EIMSK 000000xy 
// Enable or not EXTint
// x int0
// y int1
//
// EICRA 0000abcd
// control mode Extint
// ab mode int1
// cd mode int0
// 00 low level trigger
// 01 any change
// 10 falling
// 11 rising
void	ExternInt_Enable(t_extint extint, t_sc mode)
{
	BITSET(EIMSK, extint);
	EICRA |= mode << ( 2 * extint);
}

void	ExternInt_Disable(t_extint extint)
{
	BITCLR(EIMSK, extint);
}

void	PCINT20_Enable(void)
{
	BITSET(PCMSK2, PCINT20);
	BITSET(PCICR, PCIE2);
}

inline void	PCINT20_Disable(void)
{
	BITCLR(PCMSK2, PCINT20);
	BITCLR(PCICR, PCIE2);
}
