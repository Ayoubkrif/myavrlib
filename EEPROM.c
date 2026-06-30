/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EEPROM.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:05 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "myavrlib.h"

void EEPROM_write(uint32_t addr, uint8_t data)
{
	/* Wait for completion of previous write */
	while(BITCHECK(EECR, EEPE));
	/* Set up address and Data Registers */
	EEAR = addr;
	EEDR = data;
	/* Write logical one to EEMPE */
	EECR |= (1<<EEMPE);
	/* Start eeprom write by setting EEPE */
	EECR |= (1<<EEPE);
}

uint8_t	EEPROM_read(uint32_t addr)
{
	/* Wait for completion of previous write */
	while(BITCHECK(EECR, EEPE));
	/* Set up address register */
	EEAR = addr;
	/* Start eeprom read by writing EERE */
	BITSET(EECR, EERE);
	/* Return data from Data Register */
	return (EEDR);
}
