#include "main.h"

int main(void)
{
	Key_Init();
	LED_Init();
	COM1Init(115200);
	while(1)
	{
	  	printf("\n\rUSARTx configured as follow:\n\r");
	  	printf("\n\rBaudRate = 115200 baud\n\r");
	  	printf("\n\rWord Length = 8 Bits\n\r");
	  	printf("\n\rOne Stop Bit\n\r");
		//while(Get_Key(KEY1)==1);
		LEDTog(LED1);
		delay_ms(200);
	}
}


