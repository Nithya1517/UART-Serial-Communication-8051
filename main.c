#include <reg51.h>

void UART_Init()
{
    TMOD = 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
}

void UART_Tx(char ch)
{
    SBUF = ch;
    while(TI == 0);
    TI = 0;
}

void UART_String(char *str)
{
    while(*str)
    {
        UART_Tx(*str);
        str++;
    }
}

void delay()
{
    int i,j;
    for(i=0;i<500;i++)
    for(j=0;j<1275;j++);
}

void main()
{
    UART_Init();

    while(1)
    {
        UART_String("HELLO FROM 8051\r\n");
        delay();
    }
}