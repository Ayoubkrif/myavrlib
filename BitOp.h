/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitOp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bitman <bitman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:48:53 by bitman            #+#    #+#             */
/*   Updated: 2025/11/11 14:09:04 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITDEFINE
# define BITDEFINE

# define BITSET(Reg, Bit)	((Reg) |=  (1 << (Bit)))
# define BITCLR(Reg, Bit)	((Reg) &= ~(1 << (Bit)))
# define BITTOG(Reg, Bit)	((Reg) ^=  (1 << (Bit)))
# define BITCHECK(Reg, Bit)	((Reg) & (1 << (Bit)))

#define FIRST_BYTE 0
#define SECOND_BYTE 8
#define THIRD_BYTE 16
#define LAST_BYTE 24

#endif
