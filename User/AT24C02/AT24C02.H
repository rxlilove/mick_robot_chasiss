#ifndef __AT24C02_H
#define	__AT24C02_H

#include "stm32f10x.h"

 
#define  AT24C02_EEPROM_ADDRESS     0xA0   /* E2 = 0 */
#define  I2C_PageSize               8	  	/* AT24C01/02ÿҳ��8���ֽ� *//* AT24C04/08A/16Aÿҳ��16���ֽ� */






extern void AT24C02_I2C_BufferRead(I2C_TypeDef* I2Cx,u8* pBuffer, u8 ReadAddr, u16 NumByteToRead);
extern void AT24C02_I2C_WaitEepromStandbyState(void); 
extern void AT24C02_I2C_BufferWrite(I2C_TypeDef* I2Cx,u8* pBuffer, u8 WriteAddr, u16 NumByteToWrite);
 
 
 
 
#endif  

/***************************AT24C02���Ժ���***************************************************

void AT24C02_Test(void)
{
	unsigned int i=0;
  UART_send_string(USART1,"д�������\n");//�ַ�������  
	for (i=0; i<256; i++ ) //��仺��
  {   
      I2c_Buf_Write[i] = 68;
  
   }
   UART_send_string(USART1,I2c_Buf_Write);//�ַ�������  
  //��I2c_Buf_Write��˳�����������д��EERPOM�� 
 
  AT24C02_I2C_BufferWrite(I2C1,I2c_Buf_Write,0x64,7); 
  UART_send_string(USART1,"\nд�ɹ�\n");//�ַ������� 
	UART_send_string(USART1,"\n����������\n");//�ַ������� 
  //��EEPROM��������˳�򱣳ֵ�I2c_Buf_Read��
  I2C_STM32_Read_Bytes(I2C1,AT24C02_EEPROM_ADDRESS,0x64,I2c_Buf_Read,7); 
  //��I2c_Buf_Read�е�����ͨ�����ڴ�ӡ
	for (i=0; i<7; i++)
	{	
		
		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
		{			
      UART_send_string(USART1,"����:");//�ַ�������  
      UART_send_char(USART1,i+48); 		
			UART_send_string(USART1,"����:I2C EEPROMд������������ݲ�һ��\n");//�ַ�������  
			return;
		}
     
	}
  UART_send_string(USART1,I2c_Buf_Read);//�ַ�������   
	UART_send_string(USART1,"\nI2C(AT24C02)��д���Գɹ�\n");//�ַ�������  
}

******************************************************************************/