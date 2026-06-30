/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EEPROM.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:16:09 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef EEPROM__H
#define EEPROM__H

#include <stdint.h>

#define EEPROM_START 0x0
#define EEPROM_END 0x3FF

void	EEPROM_write(uint32_t addr, uint8_t data);
uint8_t	EEPROM_read(uint32_t addr);

#endif
