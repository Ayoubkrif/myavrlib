/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PortIO.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:50:40 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "myavrlib.h"

void	led_init(void)
{
	BITSET(DDRB, DDB0); // B0 Output (B0 = D1 Led)
	BITSET(DDRB, DDB1); // B1 Output (B1 = D2 Led)
	BITSET(DDRB, DDB2); // B2 Output (B2 = D3 Led)
	BITSET(DDRB, DDB4); // B4 Output (B4 = D4 Led)
}

inline void	D1_init(void)
{
	BITSET(DDRB, DDB0); // B0 Output (B0 = D1 Led)
}

inline void	D1Tog(void)
{
	BITTOG(PORTB, PORTB0);
}

inline void	D2_init(void)
{
	BITSET(DDRB, DDB1); // B1 & OC1A Output (B1 = D1 Led) 
}

inline void	SW1_PUD_init(void)
{
	BITCLR(DDRD, DDD2);
	BITSET(PORTD, PORTD2);
}

inline void	SW2_PUD_init(void)
{
	BITCLR(DDRD, DDD4);
	BITSET(PORTD, PORTD4);
}

void	D5_init(void)
{
	BITSET(DDRD, DDD3); // D5 Blue Output (PD3)
	BITSET(DDRD, DDD5); // D5 Red Output (PD5)
	BITSET(DDRD, DDD6); // D5 Green Output (PD6)
	// BITCLR(PORTD, PORTD3); // D5 Blue Output (PD3)
	// BITCLR(PORTD, PORTD5); // D5 Red Output (PD5)
	// BITCLR(PORTD, PORTD6); // D5 Green Output (PD6)
}

/// TOGGLE
void	D5Tog_Blue(void)
{
	BITTOG(PORTD, PORTD3); // D5 Blue Toggle (PD3)
}

void	D5Tog_Green(void)
{
	BITTOG(PORTD, PORTD6); // D5 Green Toggle (PD6)
}

void	D5Tog_Red(void)
{
	BITTOG(PORTD, PORTD5); // D5 Red Toggle (PD5)
}

/// CLEAR
void	D5Clr_Blue(void)
{
	BITCLR(PORTD, PORTD3); // D5 Blue Clear (PD3)
}

void	D5Clr_Green(void)
{
	BITCLR(PORTD, PORTD6); // D5 Green Clear (PD6)
}

void	D5Clr_Red(void)
{
	BITCLR(PORTD, PORTD5); // D5 Red Clear (PD5)
}

/// SET
void	D5Set_Blue(void)
{
	BITSET(PORTD, PORTD3); // D5 Blue Set (PD3)
}

void	D5Set_Green(void)
{
	BITSET(PORTD, PORTD6); // D5 Green Set (PD6)
}

void	D5Set_Red(void)
{
	BITSET(PORTD, PORTD5); // D5 Red Set (PD5)
}
