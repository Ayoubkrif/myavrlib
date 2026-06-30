/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UART.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:36:43 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "myavrlib.h"

static uint32_t	round_div(uint32_t number, uint32_t div)
{
	uint32_t	q = (number / div);
	uint32_t	mod = (number % div);

	if (mod >= (div / 2) + (div % 2))// id it
		q++;
	return (q);
}

// Init function
void	uart_init(void)
{
	UCSR0B = 0; // disable tx
	// 19.10.5 UBRRnL and UBRRnH – USART Baud Rate Registers
	UBRR0 = round_div(F_CPU, (16 * UART_BAUDRATE)) - 1;// Set baudrate 12-bit register
	
	BITSET(UCSR0C, UCSZ01);// 8 bits character size
	BITSET(UCSR0C, UCSZ00);// (table p162)

	UCSR0B =  (1 << TXEN0) | (1 << RXEN0); //Writing this bit to one enables the USART receiver (p160)
}

// Send fonction
void	uart_tx(unsigned char data)
{
	while(!BITCHECK(UCSR0A, UDRE0))// wait the previous bus to be empty (p159 atmel datasheet)
		;
	UDR0 = data;// edit transmitter register (p159 atmel datasheet)
}

void	uart_printstr(const char* str)
{
	while (*str)
	{
		uart_tx(*str);
		++str;
	}
}

// Receive fonction
char	uart_rx(void)
{
	while(!BITCHECK(UCSR0A, RXC0))// wait a bus to receive (p159 atmel datasheet)
		;
	return (UDR0);// edit transmitter register (p159 atmel datasheet)
}

void	uart_printNb(uint32_t n)
{
	char	buffer[11];
	int		i = 0;

	if (n == 0)
	{
		uart_tx('0');
		return;
	}
	while (n)
	{
		buffer[i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	while (i > 0)
	{
		i--;
		uart_tx(buffer[i]);
	}
}

void	uart_printHex(uint32_t n)
{
	char	base[] = "0123456789ABCDEF";
	char	buffer[11];
	int		i = 0;

	if (n == 0)
	{
		uart_tx('0');
		return;
	}
	while (n)
	{
		buffer[i] = base[n % 16];
		i++;
		n /= 16;
	}
	while (i > 0)
	{
		i--;
		uart_tx(buffer[i]);
	}
}

void	uart_printHex8(uint8_t n)
{
	char	base[] = "0123456789ABCDEF";
	char	buffer[3];
	int		i = 0;

	if (n == 0)
	{
		uart_tx('0');
		return;
	}
	while (n)
	{
		buffer[i] = base[n % 16];
		i++;
		n /= 16;
	}
	while (i > 0)
	{
		i--;
		uart_tx(buffer[i]);
	}
}
void	uart_printHexByte(uint8_t n)
{
	char	base[] = "0123456789ABCDEF";

	uart_tx(base[(n >> 4) & 0xF]);
	uart_tx(base[n & 0xF]);
}

void	dbg_printstr(char *str)
{
	(void)str;
#ifdef DEBUG
	uart_printstr(str);
#endif
}

void	dbg_printNb(uint32_t n)
{
	(void)n;
#ifdef DEBUG
	uart_printNb(n);
#endif
}

void	dbg_printHex(uint32_t n)
{
	(void)n;
#ifdef DEBUG
	uart_printHex(n);
#endif
}

void	dbg_printHex8(uint8_t n)
{
	(void)n;
#ifdef DEBUG
	uart_printHex8(n);
#endif
}

void	dbg_printHexByte(uint8_t n)
{
	(void)n;
#ifdef DEBUG
	uart_printHexByte(n);
#endif
}

