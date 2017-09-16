#include <REG52.H>    /* special function register declarations */
#include <stdio.h>    /* prototype declarations for I/O functions */
#include <intrins.h>
#include <Absacc.h>
#include <string.h>
#include <ctype.h>

#define byte unsigned char
#define uchar unsigned char
#define word unsigned int
#define uint unsigned int
#define ulong unsigned long
#define BYTE 	unsigned char
#define WORD 	unsigned int

#define TRUE  1
#define FALSE 0

extern void initUart(void);/*��ʼ������*/
extern void time(unsigned int ucMs);//��ʱ��λ��ms

void delay(uchar xms)				
{
	uint i,j;
	for(i=xms;i>0;i--)		      //i=xms����ʱԼxms����
		for(j=110;j>0;j--);
}