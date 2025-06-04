#include <REGX52.H>
#include <INTRINS.H>
sbit I2C_SCL=P3^7;
sbit I2C_SDA=P3^6;
#define I2CDelay() {_nop_();_nop_;_nop_;_nop_;}//4个机器周期的延时
void I2C_Start()
{
	I2C_SCL=1;
	I2C_SDA=1;
	I2CDelay();
	I2C_SDA=0;
	I2CDelay();
}
void I2C_Stop()
{
	I2C_SCL=1;
	I2C_SDA=0;
	I2CDelay();
	I2C_SDA=1;
	I2CDelay();
}

void I2C_SendByte()
{
    

}
void main()
{
	_nop_();
	I2C_Start();
}