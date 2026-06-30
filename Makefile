# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 09:53:35 by aykrifa           #+#    #+#              #
#                                                                              #
# **************************************************************************** #

# =============================[ Project Config ]============================= #
NAME        = myavrlib.a
BUILD_DIR   = build

SRC         = Timer.c \
			  PortIO.c \
			  interrupt.c \
			  UART.c \
			  analog.c \
			  i2c.c \
			  EEPROM.c \
			  SPI.c

OBJ         = $(SRC:%.c=$(BUILD_DIR)/%.o)

MCU         = atmega328p
F_CPU       = 16000000UL

CC          = avr-gcc
AR          = avr-ar
CFLAGS      = -Wall -Wextra -Werror -Os
PREPROC     = -DF_CPU=$(F_CPU) -mmcu=$(MCU)

# ===============================[ Rules ]==================================== #
all: $(NAME)
.PHONY: all

debug: PREPROC += -DDEBUG
debug: all
.PHONY: debug

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(PREPROC) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
