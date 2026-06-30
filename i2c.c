/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i2c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:10:50 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "myavrlib.h"

inline void	i2c_wait(void)
{
	while (!(BITCHECK(TWCR, TWINT)));
}

inline void i2c_init(void)
{
    // prescaler = 1
    BITSET(TWSR, TWPS0);
    BITCLR(TWSR, TWPS1);

    TWBR = ((F_CPU/SCL_CLOCK) - 16) / 2; // Baudrate SCL = 72
}

inline void i2c_write(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
	i2c_wait();
}

inline void i2c_stop(void)
{
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while (BITCHECK(TWCR, TWSTO)); // wait for STOP to finish
}

inline void i2c_start(void)
{
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	i2c_wait();
}

inline uint8_t i2c_read(t_ack ack)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | ((ack != 0) << TWEA);
	i2c_wait();
    return (TWDR);
}
