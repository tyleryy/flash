/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   用3.5.0版本库建的工程模板
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO-MINI STM32 开发板 
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "delay.h"
#include "bsp_usart1.h"
#include "w25qxx.h"	 

  	 
	  //要写入到W25Q16的字符串数组
long double TEXT_Buffer[]={1.2};
#define SIZE sizeof(TEXT_Buffer)
 int main(void)
 {	 

	long double datatemp[SIZE];
	u32 FLASH_SIZE; 
	 
	delay_init();	    	 //延时函数初始化	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
 	USART1_Config();	 	//串口初始化为115200
 	
	W25QXX_Init();			//W25QXX初始化
	while(W25QXX_ReadID()!=W25Q16)								//检测不到W25Q128
	{
 printf("error");
	}

 
	FLASH_SIZE=2*1024*1024;	//FLASH 大小为16M字节

	W25QXX_Write((void*)TEXT_Buffer,FLASH_SIZE-100,SIZE);			//从倒数第100个地址处开始,写入SIZE长度的数据
	W25QXX_Read((void*)datatemp,FLASH_SIZE-100,SIZE);					//从倒数第100个地址处开始,读出SIZE个字节
  printf("%LF\n",datatemp[0]);

		for(;;)
		{
			
		}
}


/*********************************************END OF FILE**********************/

