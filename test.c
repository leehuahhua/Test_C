#include "public.h"		//这个头文件里面就包含了reg52.h
#include "lcd1602.h"
#include "matrix_keyboard.h"
#include "uart.h"
#include "fan.h"
#include "heater.h"
#include "beep.h"
#include "ds18b20.h"
#include "led.h"

u16 key = 0xFF;//存放矩阵按键的值

u16 temp_value_middle = 25;	//存放温度设定的中间值

u16 temp_value_min = 24;	//存放温度设定的最小值（有一个默认值）
u16 temp_value_max = 26;	//存放温度设定的最大值 （有一个默认值）
u16 temp_value_clear_flag = 0;//存放按下清零按键的标志位
u16 temp_value_ok_flag = 0;//存放按下确认键的标志位
u16 set_temp_flag = 0;//存放设置温度的标志位
int temp_value = 0;		//存放温度的值

u8 temp_buf[10] = {0x00};  		//存放用于显示的读取到的温度的值
u8 set_temp_buf[10] = {0x00};//存放用于显示的设置温度的值

u8 manual_flag = 0;//切换手动和自动的标志位
/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	u8 i = 0;//用来做循环的打印

	fan_init();	//风扇初始化
	heater_init();//加热片初始化
	beep_init();//蜂鸣器初始化
	UART_Init(9600);//串口初始化
	lcd1602_init();//LCD1602初始化
	ds18b20_init();//初始化DS18B20
	printf("init_ok\r\n");
	
//	sprintf((char *)set_temp_buf,"T1: (%d,%d)",temp_value_min,temp_value_max);//将温度值和T2：拼接起来，然后输出
	sprintf((char *)set_temp_buf,"T1: %d",temp_value_middle);//将温度中间值和T1：拼接起来，然后输出
	lcd1602_show_string(0,0,set_temp_buf);//第1行显示
	lcd1602_show_string(0,1,"T2:");//第二行显示
	while(1)
	{		/*温度值的设置*/
			key=my_key_matrix_ranks_scan();
			if(key != 0xFF)
			{
				if(set_temp_flag == 1)//事先已经按下了温度的设置按键
				{
					if((key >=0x00) && (key <=0x09))//按下的是键盘的数字键
					{
						if(temp_value_ok_flag == 0)
						{
							temp_value_middle = temp_value_middle * 10 + key;
							printf("temp_value_middle = %d \r\n",temp_value_middle);	

						}
						else
						{
							printf("已经输入温度的最大值和最小值，请先清零\r\n");
						}
					}
					if(key == 0x0a)	//按下的是键盘的清除键
					{
						temp_value_clear_flag = 1;
						temp_value_ok_flag = 0;//将确认键的标志位清零
						temp_value_min = 0;
						temp_value_max = 0;
						temp_value_middle = 0;
						printf("按下了清除按键\r\n");
						lcd1602_clear();
						printf("temp_value_min = %d\r\n",temp_value_min);
						printf("temp_value_max = %d\r\n",temp_value_max);
						printf("temp_value_middle = %d\r\n",temp_value_middle);
//						sprintf((char *)set_temp_buf,"T1: (%d,%d)",temp_value_min,temp_value_max);//将温度值和T2：拼接起来，然后输出
						sprintf((char *)set_temp_buf,"T1: %d",temp_value_middle);//只显示middle的值
						lcd1602_show_string(0,0,set_temp_buf);//第1行显示
								
					}
					if(key == 0x0b)	//按下的是键盘的确认键
					{
						temp_value_min = temp_value_middle - 1;		//估计这个区间太小了，会导致一会风扇打开，一会儿加热片打开
						printf("temp_value_min = %d \r\n",temp_value_min);	
						temp_value_max = temp_value_middle + 1;
						printf("temp_value_max = %d \r\n",temp_value_max);	
						temp_value_ok_flag++;//将确认键标志位置一，用来输入数字的时候做判断	
//						sprintf((char *)set_temp_buf,"T1: (%d,%d)",temp_value_min,temp_value_max);//将温度值和T2：拼接起来，然后输出
						sprintf((char *)set_temp_buf,"T1: %d",temp_value_middle);//只显示middle的值
						lcd1602_show_string(0,0,set_temp_buf);//第1行显示
				
					}						
				}

				if(key == 0x0c)	//按下的是风扇的强制开关键
				{
					manual_flag =! manual_flag;
					/*读取这个引脚的高低电平，然后将他反转就行*/
					if(fan == 0)
					{
						fan_open_close(0x01);
//						led_open_close(0x03,0x01);
						printf("风扇打开\r\n");
					}
					else if(fan == 1)
					{
						fan_open_close(0x00);
//						led_open_close(0x03,0x00);
						printf("风扇关闭\r\n");
					}		
				}
				if(key == 0x0d)	//按下的是加热片的强制开关键
				{
					manual_flag =! manual_flag;
					/*读取这个引脚的高低电平，然后将他反转就行*/
					if(heater == 0)
					{
						heater_open_close(0x01);
//						led_open_close(0x02,0x01);
						printf("加热器打开\r\n");
					}
					else if(heater == 1)
					{
						heater_open_close(0x00);
//						led_open_close(0x02,0x00);
						printf("加热器关闭\r\n");
					}					
				}
				if(key == 0x0e)	//按下的是蜂鸣器的强制开关键
				{
					manual_flag =! manual_flag;
					/*读取这个引脚的高低电平，然后将他反转就行*/
					if(beep == 0)
					{
						beep_open_close(0x01);
//						led_open_close(0x01,0x01);
						printf("蜂鸣器打开\r\n");
					}
					else if(beep == 1)
					{
						beep_open_close(0x00);
//						led_open_close(0x01,0x00);
						printf("蜂鸣器关闭\r\n");
					}
					beep = 1;				
				}
				if(key == 0x0f)	//按下的是设置温度的按键
				{
					manual_flag =! manual_flag;
				  	printf("按下的是设置温度的按键\r\n");
					printf("temp_value_min = %d\r\n",temp_value_min);
					printf("temp_value_max = %d\r\n",temp_value_max);
					if(set_temp_flag == 0)
					{
						set_temp_flag = 1;
						lcd1602_clear();//将第一行的值清零
//						sprintf((char *)set_temp_buf,"T1:(%d,%d) SET",temp_value_min,temp_value_max);//将温度值和T2：拼接起来，然后输出
						sprintf((char *)set_temp_buf,"T1: %d",temp_value_middle);//只显示middle的值
						lcd1602_show_string(0,0,set_temp_buf);//第1行显示					
					}
					else
					{
						set_temp_flag = 0;
						lcd1602_clear();//将第一行的值清零
//						sprintf((char *)set_temp_buf,"T1:(%d,%d)",temp_value_min,temp_value_max);//将温度值和T2：拼接起来，然后输出
						sprintf((char *)set_temp_buf,"T1: %d",temp_value_middle);//只显示middle的值
						lcd1602_show_string(0,0,set_temp_buf);//第1行显示
					}
				}
			}
			/*温度值的读取*/
			temp_value=ds18b20_read_temperture() * 100;//只保留两位小数
//			printf("temp_value = %d\r\n",temp_value);
			sprintf((char *)temp_buf,"T2:%.2f",temp_value / 100.0);//将温度值和T2：拼接起来，然后输出
			lcd1602_show_string(0,1,temp_buf);//第二行显示
			if(set_temp_flag == 0)	//当按下温度的设置按钮是就不用进行比较了，直到温度值设置好，才进行比较
			{
				if(temp_value <= temp_value_min * 100)
				{
					printf("cold, open heater\r\n");
					/*打开加热片，同时关闭风扇和打开蜂鸣器*/
					fan_open_close(0x00);
					heater_open_close(0x01);
					beep_open_close(0x01);
				}
				else if (temp_value >= temp_value_max * 100 )
				{
					printf("hot, open fan\r\n");
					/*关闭加热片，同时打开风扇和打开蜂鸣器*/
					fan_open_close(0x01);
					heater_open_close(0x00);
					beep_open_close(0x01);						
				}
				else
				{
					//printf("温度正常\r\n");
					if(manual_flag == 1)	//开启了手动模式
					{
							
					}
					else		  //开启了自动模式
					{
//						printf("normal close all\r\n");
						/*温度正常就全部关闭*/
						fan_open_close(0x00);
						heater_open_close(0x00);
						beep_open_close(0x00);
							
					}
				}			
			}	
	}	
}
