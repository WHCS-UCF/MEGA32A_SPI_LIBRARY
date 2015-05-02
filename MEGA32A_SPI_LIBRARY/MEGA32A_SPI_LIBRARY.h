/*
 * MEGA32A_SPI_LIBRARY.h
 *
 * Created: 4/30/2015 12:22:34 PM
 *  Author: Jimmy
 */ 


#ifndef MEGA32A_SPI_LIBRARY_H_
#define MEGA32A_SPI_LIBRARY_H_

void InitSPI(void);

//Sends and receives a byte through SPI
uint8_t WriteByteSPI(uint8_t cData);

#endif /* MEGA32A_SPI_LIBRARY_H_ */