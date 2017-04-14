/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ��3.5.0�汾�⽨�Ĺ���ģ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO-MINI STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "delay.h"
#include "bsp_usart1.h"
#include "w25qxx.h"	 

  	 
	  //Ҫд�뵽W25Q16���ַ�������
long double TEXT_Buffer[]={1.2};
#define SIZE sizeof(TEXT_Buffer)
 int main(void)
 {	 

	long double datatemp[SIZE];
	u32 FLASH_SIZE; 
	 
	delay_init();	    	 //��ʱ������ʼ��	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
 	USART1_Config();	 	//���ڳ�ʼ��Ϊ115200
 	
	W25QXX_Init();			//W25QXX��ʼ��
	while(W25QXX_ReadID()!=W25Q16)								//��ⲻ��W25Q128
	{
 printf("error");
	}

 
	FLASH_SIZE=2*1024*1024;	//FLASH ��СΪ16M�ֽ�

	W25QXX_Write((void*)TEXT_Buffer,FLASH_SIZE-100,SIZE);			//�ӵ�����100����ַ����ʼ,д��SIZE���ȵ�����
	W25QXX_Read((void*)datatemp,FLASH_SIZE-100,SIZE);					//�ӵ�����100����ַ����ʼ,����SIZE���ֽ�
  printf("%LF\n",datatemp[0]);

		for(;;)
		{
			
		}
}


/*********************************************END OF FILE**********************/

