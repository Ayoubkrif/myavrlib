/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:45:12 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef UART_H
#define UART_H

#define UART_BAUDRATE 115200
#define NEWLINE			"\r\n"
#define ERASE			"\b \b"
#define RED				"\033[0;31m"
#define WHITE			"\033[0m"

void	uart_init(void);
// Send fonction
void	uart_tx(unsigned char data);
// Receive func
char	uart_rx(void);

void	uart_printstr(const char* str);

void	uart_printNb(uint32_t n);

void	uart_printHex(uint32_t n);

void	uart_printHex8(uint8_t n);

void	uart_printHexByte(uint8_t n);

void	dbg_printstr(char *str);

void	dbg_printNb(uint32_t n);

void	dbg_printHex(uint32_t n);

void	dbg_printHex8(uint8_t n);

void	dbg_printHexByte(uint8_t n);

#endif // !UART_H
