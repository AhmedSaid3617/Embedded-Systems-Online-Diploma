#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#define THRESHOLD 20

int pressure;

int main()
{
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(1);
	while (1)
	{
		pressure = getPressureVal();
		for (int i = 0; i < 1000; i++)
		{
			/* code */
		}

		if (pressure > THRESHOLD)
		{
			Set_Alarm_actuator(0);
			for (int i = 0; i < 2000000; i++)
			{
				/* code */
			}
		}

		Set_Alarm_actuator(1);
	}
}
