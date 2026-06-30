/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PortIO.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bitman <bitman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:48:53 by bitman            #+#    #+#             */
/*   Updated: 2025/11/06 20:34:19 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORTIO_H
# define PORTIO_H

void		led_init(void);
void	D1_init(void);
void	D1Tog(void);
void	D2_init(void);

void	SW1_PUD_init(void);
void	SW2_PUD_init(void);

//mod03
void	D5_init(void);

void	D5Tog_Blue(void);
void	D5Tog_Green(void);
void	D5Tog_Red(void);

void	D5Clr_Blue(void);
void	D5Clr_Green(void);
void	D5Clr_Red(void);

void	D5Set_Blue(void);
void	D5Set_Green(void);
void	D5Set_Red(void);

#endif
