/*
 * MEGA32A_SPI_LIBRARY.cpp
 *
 * Created: 4/30/2015 12:21:55 PM
 *  Author: Jimmy
 */ 

#include <avr/io.h>

void InitSPI(void) {
	//Clear port B SPI pins for init
	DDRB &= ~_BV(6); // MISO input
	
	//Set SCK (PB7), MOSI (PB5) , SS (PB4)  as outport
	//OBS!!! Has to be set before SPI-Enable below
	DDRB |= _BV(7) | _BV(5) | _BV(4);
	
	// Enable SPI, Master, set clock rate fck/16 .. clock rate not to important..
	//SPCR |= (1<<SPE)|(1<<MSTR) |(1<<SPR0); // |(1<<SPR1);
	
	SPCR = ((1<<SPE)|               // SPI Enable
	(0<<SPIE)|              // SPI Interrupt Enable
	(0<<DORD)|              // Data Order (0:MSB first / 1:LSB first)
	(1<<MSTR)|              // Master/Slave select
	(1<<SPR1)|(0<<SPR0)|    // SPI Clock Rate (clk/64)
	(0<<CPOL)|              // Clock Polarity (0:SCK low / 1:SCK hi when idle)
	(0<<CPHA));             // Clock Phase (0:leading / 1:trailing edge sampling)
	
	SPSR |= (0<<SPI2X); // operate at clk*2
}

//Sends and receives a byte through SPI
uint8_t WriteByteSPI(uint8_t cData) {
	//Load byte to Data register
	SPDR = cData;
	
	/* Wait for transmission complete */
	while((SPSR & (1<<SPIF))==0);
	
	//Return what's received from the nRF
	return SPDR;
}
