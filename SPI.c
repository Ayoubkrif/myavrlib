/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SPI.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:27:46 by aykrifa           #+#    #+#             */
/*                                                   #####   ##########       */
/* ************************************************************************** */

#include "BitOp.h"
#include "myavrlib.h"

void	SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input
	 * MOSI = PB3
	 * SCK = PB5
	 * SS = PB2
	 */
	BITSET(DDRB, DDB5);
	BITSET(DDRB, DDB3);
	BITSET(DDRB, DDB2);

	/* Enable SPI, Master, set clock rate fck/16
	 * 
	 * https://cdn-learn.adafruit.com/assets/assets/000/084/591/original/APA102_LED.pdf?1574117503
	 * (Electrical Characteristic) p4
	 * FOSC must be between 800khz-1200khz
	 * 16Mhz/800khz = 20
	 * 16Mhz/1200khz = 13.33 
	 * so we choose 16 as prescaler
	 */
	BITSET(SPCR, SPR0);
	BITCLR(SPCR, SPR1);
	/*set mode master*/
	BITSET(SPCR, MSTR);
	/*Enable SPI*/
	BITSET(SPCR, SPE);
}

void	SPI_Transmit(uint8_t data)
{
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete 
	 * by checking SPI interrupt flag*/
	while(!BITCHECK(SPSR, SPIF));
}

// char SPI_Receive(void)
// {
// /* Wait for reception complete */
// while(!(SPSR & (1<<SPIF)))
// ;
// /* Return Data Register */
// return SPDR;
// }
