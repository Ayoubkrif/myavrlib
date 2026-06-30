/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:06:25 by aykrifa           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERRUPT_H
#define INTERRUPT_H

typedef enum e_sc
{
	LOW = 0,
	CHANGE,
	FALLING,
	RISING
}	t_sc;

typedef enum e_extint
{
	EXTINT0 = 0,
	EXTINT1,
}	t_extint;

void	ExternInt_Enable(t_extint extint, t_sc mode);
void	ExternInt_Disable(t_extint extint);
void	PCINT20_Enable(void);
void	PCINT20_Disable(void);

#endif // !INTERRUPT_H
