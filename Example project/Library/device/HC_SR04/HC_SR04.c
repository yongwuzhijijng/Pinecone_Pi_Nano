/**
  ******************************************************************************
  * @file    hc_sr04.c
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This article will be used for  driving  hc_sr04.
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *	The frequency of crystal oscillator is 24 Mhz
  *
  *  
  * 
  * 
  * 
  * 
  *
  * 
  ******************************************************************************
	**/
#include"hc_sr04.h"

unsigned int time_start; //����������ʱ��
unsigned int time_end;   //�յ�������ʱ�� 
												//Echo_Pin�ߵ�ƽ������ʱ��=�յ�������ʱ��-����������ʱ��

//========================================================================
// ����: delay_us_hc_sr04(unsigned int us)
// ����: ��ʱ������
// ����: us,Ҫ��ʱ��us��, ����ֻ֧��1~10000 (10ms) us
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: delay_us(1000);//�ӳ�1us
//========================================================================
void delay_us_hcsr04(unsigned int us){
  unsigned int k;
	unsigned char i;
	for(k=0;k<us;k++)
	{
	i = 6;
	while (--i);
	}
}
//========================================================================
// ����: void timer_init()
// ����: ��ʼ����ʱ��3 ��16λ�Զ����أ���
// ����: 
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע:
//========================================================================
void timer_init()
{
	T4T3M |= 0x02;		//��ʱ��ʱ��1Tģʽ
	T3L = 0x00;		//���ö�ʱ��ֵ
	T3H = 0x00;		//���ö�ʱ��ֵ
	T4T3M |= 0x08;		//��ʱ��3��ʼ��ʱ
}
//========================================================================
// ����: HC_SR04_Init()
// ����: ��ʼ��HC_SR04����Ӳ����
// ����: 
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע:
//========================================================================
void HC_SR04_Init()
{
	timer_init();
}
//========================================================================
// ����: HC_SR04_Start()
// ����: ��ʼ����������
// ����: 
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע:
//========================================================================
void HC_SR04_Start()
{
	Trig_Pin = 0;
	delay_us_hcsr04(45);
	Trig_Pin = 1;
}
//========================================================================
// ����: int HC_SR04_Loop()
// ����: ���ؾ��롣
// ����: 
// ����: distance:���루��λ�����ף�.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע:
//========================================================================
int HC_SR04_Loop()
{
	int distance;//����
	HC_SR04_Start();
	 while(!Echo_Pin);		//��RXΪ��ʱ�ȴ�
//	 TR0=1;			    //��������
		 time_start=T3H*256+T3L;
	 while(Echo_Pin);			//��RXΪ1�������ȴ�
//	 TR0=0;				//�رռ���
	time_end=T3H*256+T3L;
  distance=((time_end-time_start)/24)/58;     //�������CM(int)
	return distance;
}
															
															
															
															
															