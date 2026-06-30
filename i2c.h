/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i2c.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:05:30 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */


#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include <util/twi.h>

#define SCL_CLOCK 100000L
#define TWI_STATUS TWSR & TW_STATUS_MASK

typedef	enum e_ack
{
	NACK = 0,
	ACK = 1
}	t_ack;

void	i2c_init(void);

void	i2c_write(uint8_t);

void	i2c_start(void);

void	i2c_stop(void);

void	i2c_wait(void);

void	i2c_start(void);

uint8_t	i2c_read(t_ack);
#endif

