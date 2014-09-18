/*********************************************************************************/
/*��������:	strmcpy()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)�ַ����鿽����				
*�޸���־��
*[2006-3-6 17:07] 	Ver. 1.00
		��ʼ��д��
		��ɣ�										
/*										 */
/*********************************************************************************/

void strmcpy(unsigned char dest[], unsigned char src[], int count)
{
	int i;
	
	for(i = 0; i < count; i ++)
	{
		dest[i] = src[i];
	}
	dest[i] = '/0';
}

/*****************************************************************************/


/*********************************************************************************/
/*��������:	bitmcpy()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)���������鿽����				
*�޸���־��
*[2006-3-7 14:59] 	Ver. 1.00
		��ʼ��д��
		��ɣ�										
/*										 */
/*********************************************************************************/

void bitmcpy(int dest[], int src[], int count)
{
	int i;
	
	for(i = 0; i < count; i ++)
	{
		dest[i] = src[i];
	}
}

/*****************************************************************************/


/*********************************************************************************/
/*��������:	strmcmp()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)�ַ�����Ƚϣ���ͬ�򷵻�0������ͬ�򷵻�1��				
*�޸���־��
*[2006-3-6 17:41] 	Ver. 1.00
		��ʼ��д��
		��ɣ�										
/*										 */
/*********************************************************************************/

int strmcmp(unsigned char str1[], unsigned char str2[], int count)
{
	int i;
	
	for(i = 0; i < count; i ++)
	{
		if(str1[i] != str2[i])
		{
			return 1;		
		}
	}
	return 0;
}

/*****************************************************************************/


/*********************************************************************************/
/*��������:	Datamcmp()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)��������Ƚϣ���ͬ�򷵻�0������ͬ�򷵻�1��				
*�޸���־��
*[2006-3-6 18:05] 	Ver. 1.00
		��ʼ��д��
		��ɣ�		
*[2006-3-9 13:52]
		����һ�����ţ���ǰ�Ǵ����
		if(!((data1[i] - data2[i] < 0.0001) && (data1[i] - data2[i] > -0.0001)))										
/*										 */
/*********************************************************************************/

int Datamcmp(float data1[], float data2[], int count)
{
	int i;
	
	for(i = 0; i < count; i ++)
	{
		if(!((data1[i] - data2[i] < 0.0001) && (data1[i] - data2[i] > -0.0001)))
		{
			return 1;		
		}
	}
	return 0;
}

/*****************************************************************************/


/*********************************************************************************/
/*��������:	Bitmcmp()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)����������Ƚϣ���ͬ�򷵻�0������ͬ�򷵻�1��				
*�޸���־��
*[2006-3-6 18:10] 	Ver. 1.00
		��ʼ��д��
		��ɣ�										
/*										 */
/*********************************************************************************/

int Bitmcmp(int data1[], int data2[], int count) 
{ 
	int i;
	
	for(i = 0; i < count; i ++)
	{
		if(data1[i] != data2[i])
		{
			return 1;		
		}
	}
	return 0;
}

/*****************************************************************************/


/*********************************************************************************/
/*��������:	GetCRC16()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)CRC16У�飻 ����У���룻				
*�޸���־��
*[2005-11-28 16:40] 	Ver. 1.00
		��ʼ��д��
		��ɣ�										
/*										 */
/*********************************************************************************/

unsigned short GetCRC16(unsigned char *puchMsg, unsigned short usDataLen) 
{ 
	/* CRC ��λ�ֽ�ֵ�� */ 
	unsigned char auchCRCHi[256] = {
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
	}; 
	
	unsigned char auchCRCLo[256] = {
	0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 
	0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 
	0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 
	0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 
	0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4, 
	0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 
	0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 
	0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 
	0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 
	0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 
	0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 
	0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 
	0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 
	0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 
	0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 
	0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 
	0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 
	0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 
	0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 
	0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 
	0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 
	0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 
	0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 
	0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 
	0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 
	0x43, 0x83, 0x41, 0x81, 0x80, 0x40
	};
	
	unsigned char uchCRCHi = 0xFF ; /* ��CRC�ֽڳ�ʼ�� */ 
	unsigned char uchCRCLo = 0xFF ; /* ��CRC �ֽڳ�ʼ�� */ 
	unsigned uIndex = 0; /* CRCѭ���е����� */ 
	
	while (usDataLen--) /* ������Ϣ������ */ 
	{ 
		uIndex = uchCRCHi ^ *puchMsg++ ; /* ����CRC */ 
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex] ; 
		uchCRCLo = auchCRCLo[uIndex] ; 
	} 
	return (unsigned short)((unsigned short)uchCRCHi << 8 | uchCRCLo) ; 
} 
/*****************************************************************************/


/*********************************************************************************/
/*��������:	SendRtuCmdToModBus()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	��
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)����ModBus RTU ָ� Modbus Slave,����CRC16У���룻 				
*�޸���־��
*[2005-11-28 16:40] 	Ver. 1.00
		��ʼ��д��
		��ɣ�	
*[2006-3-1 9:02]
		�������͸�Ϊvoid��										
/*										 */
/*********************************************************************************/

void SendRtuCmdToModBus(int ModPort, unsigned char cmd[], unsigned short len)
{ 
	unsigned short CRC16;
	
  	CRC16=GetCRC16(cmd,len);
  	ToComBufn(ModPort,cmd,len);
  	ToCom(ModPort, (unsigned char)(CRC16 >> 8 & 0x00FF));  	/* send CRC16 high */
  	ToCom(ModPort, (unsigned char)(CRC16 & 0x00FF));  	/* send CRC16 low */  	
}
/*****************************************************************************/


/*********************************************************************************/
/*��������:	ReadModBusRtuSlave()							
*���������	�� 8 ��������
*���������	�� 5 ��������
*����ֵ��	�ɹ����	1���ɹ��� 2��ʧ�ܣ�
*�财��Ĳ����� �� 0 ��������	
*���ܽ��ܣ�	
		(1)��ȡModBusRtuSlave����������������ַ���������ݣ� 
		ReadModBusRtuSlave(COMPORT1, ModAddr, ModFunction, ModByteNum, 
			ModData, &ModDataLen, ModTimeout=10, waitTime=30)		
*�޸���־��
*[2005-11-28 16:40] 	Ver. 1.00
		��ʼ��д��
		��ɣ�	
*[2006-3-1 9:23]
		������int counter = 0;
		unsigned char ModBusMessage[MOD_STR_MAX_LEN];	
*[2006-3-1 13:46]		
		������ strmcpy(ModData, ModBusMessage + 3, ModBusIdx - 5);									
/*										 */
/*********************************************************************************/

int ReadModBusRtuSlave(int ModPort, unsigned char *ModAddr, unsigned char *ModFunction, unsigned char *ModByteNum, 
	unsigned char ModData[], unsigned char *ModDataLen, unsigned ModTimeout, unsigned waitTime)
{ 	
	unsigned char data;
  	unsigned long t;
  	int i;
	unsigned short CRC16;
	int ModBusIdx = 0;
	int counter = 0;
	unsigned char ModBusMessage[MOD_STR_MAX_LEN] = {'/0'};
	
  	while((!(IsCom(ModPort)) && (counter < waitTime)))
	{
		DelayMs(1);
		counter ++;
	}
	
	StopWatchStart(MODBUS_STOP_WATCH);
  	do
  	{
  		while(IsCom(ModPort) && (ModBusIdx < MOD_STR_MAX_LEN - 1))
  		{
     			data = ReadCom(ModPort);
     			ModBusMessage[ModBusIdx ++]=data;
     			StopWatchStart(MODBUS_STOP_WATCH);
			/*     Print("[%02X]",data); */
  		}
  		StopWatchReadValue(MODBUS_STOP_WATCH, &t);
	}
     	while(t <= ModTimeout);
     	  	
  	if (ModBusIdx == 0) return 0;
  	ModBusMessage[ModBusIdx] = '/0';
  	StopWatchStop(MODBUS_STOP_WATCH);
     		
	
	CRC16 = GetCRC16(ModBusMessage,ModBusIdx - 2);
	/* for(i=0; i> 8 & 0x00FF) == ModBusMessage[ModBusIdx - 2] && (unsigned char)(CRC16 & 0x00FF) == ModBusMessage[ModBusIdx - 1])
	{
		*ModAddr = ModBusMessage[0];
		*ModFunction = ModBusMessage[1];
		*ModByteNum = ModBusMessage[2];
		
		strmcpy(ModData, ModBusMessage + 3, ModBusIdx - 5);	
	/*	Print(" idx%d  ", ModBusIdx - 5);	/*test*/
		/*	for(i = 3; i < ModBusIdx - 2; i++)
		{
			ModData[i - 3] = ModBusMessage[i];
		}
		ModData[i] = '/0';	
		*/
	   	*ModDataLen = ModBusIdx - 5;
	   	/*	Print("{DataLen=%d}/n/r", *ModDataLen);	*/
	   	return 1;
	}
	else 
	{
		*ModDataLen = 0;
		return 0;
		/* CRC16 error */
	/*	Print("{CRC16 Error}/n/r");	*/
	}    
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	ResponseFromModBusRtuSlave()							
*���������	�� 8 ��������
*���������	�� 5 ��������
*����ֵ��	�ɹ����	1���ɹ��� 2��ʧ�ܣ�
*�财��Ĳ����� �� 0 ��������	
*���ܽ��ܣ�	
		(1)д������ModBusRtuSlave��ModbusRtuSlave�����ַ�����
				
*�޸���־��
*[2006-3-1 12:34] 	Ver. 1.00
		��ʼ��д��
*[2006-3-1 12:48]		
		��ɣ�	
*[2006-3-6 16:32]
		strcpy(totalStr, ModBusMessage);
		��Ϊ strmcpy(totalStr, ModBusMessage, ModBusIdx);										
/*										 */
/*********************************************************************************/

int ResponseFromModBusRtuSlave(int ModPort, unsigned char totalStr[], 
	unsigned char *ModAddr, unsigned char *ModFunction, unsigned short *ModDataAddr, 
	unsigned short *ModDataNum, unsigned ModTimeout, unsigned waitTime)
{ 		
	unsigned char data;
  	unsigned long t;  	
	unsigned short CRC16;	
	int ModBusIdx = 0;
	int counter = 0;
	unsigned char ModBusMessage[MOD_STR_MAX_LEN] = {'/0'};
	
  	while((!(IsCom(ModPort)) && (counter < waitTime)))
	{
		DelayMs(1);
		counter ++;
	}
	
	StopWatchStart(MODBUS_STOP_WATCH);
  	do
  	{
  		while(IsCom(ModPort) && (ModBusIdx < MOD_STR_MAX_LEN - 1))
  		{
     			data = ReadCom(ModPort);
     			ModBusMessage[ModBusIdx ++]=data;
     			StopWatchStart(MODBUS_STOP_WATCH);
			/*     Print("[%02X]",data); */
  		}
  		StopWatchReadValue(MODBUS_STOP_WATCH, &t);
	}
     	while(t <= ModTimeout);
     	  	
  	if (ModBusIdx == 0) return 0;
  	ModBusMessage[ModBusIdx] = '/0';
  	strmcpy(totalStr, ModBusMessage, ModBusIdx);
  	StopWatchStop(MODBUS_STOP_WATCH);
     		
	
	CRC16 = GetCRC16(ModBusMessage,ModBusIdx - 2);
	
	if((unsigned char)(CRC16 >> 8 & 0x00FF) == ModBusMessage[ModBusIdx - 2] && (unsigned char)(CRC16 & 0x00FF) == ModBusMessage[ModBusIdx - 1])
	{
		*ModAddr = ModBusMessage[0];
		*ModFunction = ModBusMessage[1];
		
		*ModDataAddr = (unsigned short)((unsigned short)ModBusMessage[2] << 8 | ModBusMessage[3]);
		*ModDataNum  = (unsigned short)((unsigned short)ModBusMessage[4] << 8 | ModBusMessage[5]);
					
	   	return 1;
	}
	else 
	{
		return 0;
		/* CRC16 error */
	/*	Print("{CRC16 Error}/n/r");	*/
	}    
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	ResponseSingleBitFromModBus()							
*���������	�� 8 ��������
*���������	�� 5 ��������
*����ֵ��	�ɹ����	1���ɹ��� 2��ʧ�ܣ�
*�财��Ĳ����� �� 0 ��������	
*���ܽ��ܣ�	
		(1)д������ModBusRtuSlave��ModbusRtuSlave�����ַ�����
				
*�޸���־��
*[2006-3-7 14:40] 	Ver. 1.00
		��ʼ��д��
*[2006-3-7 14:40]		
		��ɣ�											
/*										 */
/*********************************************************************************/

int ResponseSingleBitFromModBus(int ModPort, unsigned char totalStr[], 
	unsigned char *ModAddr, unsigned char *ModFunction, unsigned short *ModDataAddr, 
	unsigned short *ModDataState, unsigned ModTimeout, unsigned waitTime)
{ 		
	unsigned char data;
  	unsigned long t;  	
	unsigned short CRC16;	
	int ModBusIdx = 0;
	int counter = 0;
	unsigned char ModBusMessage[MOD_STR_MAX_LEN] = {'/0'};
	
  	while((!(IsCom(ModPort)) && (counter < waitTime)))
	{
		DelayMs(1);
		counter ++;
	}
	
	StopWatchStart(MODBUS_STOP_WATCH);
  	do
  	{
  		while(IsCom(ModPort) && (ModBusIdx < MOD_STR_MAX_LEN - 1))
  		{
     			data = ReadCom(ModPort);
     			ModBusMessage[ModBusIdx ++]=data;
     			StopWatchStart(MODBUS_STOP_WATCH);
			/*     Print("[%02X]",data); */
  		}
  		StopWatchReadValue(MODBUS_STOP_WATCH, &t);
	}
     	while(t <= ModTimeout);
     	  	
  	if (ModBusIdx == 0) return 0;
  	ModBusMessage[ModBusIdx] = '/0';
  	strmcpy(totalStr, ModBusMessage, ModBusIdx);
  	StopWatchStop(MODBUS_STOP_WATCH);
     		
	
	CRC16 = GetCRC16(ModBusMessage,ModBusIdx - 2);
	
	if((unsigned char)(CRC16 >> 8 & 0x00FF) == ModBusMessage[ModBusIdx - 2] && (unsigned char)(CRC16 & 0x00FF) == ModBusMessage[ModBusIdx - 1])
	{
		*ModAddr = ModBusMessage[0];
		*ModFunction = ModBusMessage[1];
		
		*ModDataAddr = (unsigned short)((unsigned short)ModBusMessage[2] << 8 | ModBusMessage[3]);
		if(ModBusMessage[4])   *ModDataState  = 1;
		else   *ModDataState  = 0;
					
	   	return 1;
	}
	else 
	{
		return 0;
		/* CRC16 error */
	/*	Print("{CRC16 Error}/n/r");	*/
	}    
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	ChangeAllParameterDataByModBus()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	��
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1) ��MODBUSSLAVE���ص������ַ�ת��Ϊ����ֵ��
		(2) void *memcpy(void *dest, const void *src, size_t n)	
		(3) �ĸ��ַ���˳��Ӧ��һ�¡�			
*�޸���־��
*[2006-3-1 14:10] 	Ver. 1.00
		��ʼ��д��
*[2006-3-1 14:35]
		��ɣ�	
*[2006-3-6 15:57]
		�ĸ��ַ���˳��Ӧ��һ�¡�													
/*										 */
/*********************************************************************************/

void ChangeAllParameterDataByModBus(float parameterData[], unsigned char ModDataBack[], unsigned short num)
{
	int i;
	char singleStr[5] = {'/0','/0','/0','/0','/0'};	
	float *pf;
        float dataf = 0;       
        int len = 4;	
        
        pf = &dataf;
        	
	for(i = 0; i < num; i ++)
	{
		singleStr[0] = ModDataBack[i * 4 + 3];
		singleStr[1] = ModDataBack[i * 4 + 2];
		singleStr[2] = ModDataBack[i * 4 + 1];
		singleStr[3] = ModDataBack[i * 4 ];
		singleStr[4] = '/0';
		memcpy(pf, singleStr, len);
		parameterData[i] = *pf;
	/*	Print("%-6.2f/t", parameterData[i]);	/*test*/
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	ChangeAllButtonsDataByModBus()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	��
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1) ��MODBUSSLAVE���ص������ַ�ת��Ϊ��ťֵ��				
*�޸���־��
*[2006-3-1 14:03] 	Ver. 1.00
		��ʼ��д��	
*[2006-3-1 14:10]
		��ɣ�											
/*										 */
/*********************************************************************************/

void ChangeAllButtonsDataByModBus(int buttonData[], unsigned char ModDataBack[], unsigned short num)
{
	unsigned char button8Data = 0;
	int i, j;
		
	for(j = 0; j < (int)(num / 8); j ++)	
	{
		button8Data = ModDataBack[j];
		for(i = 0; i < 8; i ++)
		{
			buttonData[i + j * 8] = (int)(button8Data & (int) pow(2, i)) / (int) pow(2, i);
		}
	}
	button8Data = ModDataBack[j];
	for(i = 0; i < num % 8; i ++)
	{
		buttonData[i + j * 8] = (int)(button8Data & (int) pow(2, i)) / (int) pow(2, i);
	}	
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	WordDataToModbusStr()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	��
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)parameterData ��AIDataת��ΪMODBUSSLAVE��WORDֵ��STR�� 
		(2) void *memcpy(void *dest, const void *src, size_t n)	
		(3) �ĸ��ַ���˳��Ӧ��һ�¡�				
*�޸���־��
*[2006-3-1 14:37] 	Ver. 1.00
		��ʼ��д��
*[2006-3-1 14:49]		
		��ɣ�	
*[2006-3-6 15:57]
		�ĸ��ַ���˳��Ӧ��һ�¡�									
/*										 */
/*********************************************************************************/

void WordDataToModbusStr(unsigned char writeCmdStr[], float data[], unsigned short num, unsigned short startAddr)
{
	int i;
	char singleStr[5] = {'/0','/0','/0','/0','/0'};	
	float *pf;
	unsigned char *pstr;
        float dataf = 0;       
        int len = 4;	
        
        pf = &dataf;
        pstr = singleStr;
        	
	for(i = 0; i < num; i ++)
	{
		*pf = data[i];
		memcpy(pstr, pf, len);
		writeCmdStr[startAddr + i * 4 + 3] = singleStr[0];
		writeCmdStr[startAddr + i * 4 + 2] = singleStr[1];
		writeCmdStr[startAddr + i * 4 + 1] = singleStr[2];
		writeCmdStr[startAddr + i * 4 ] = singleStr[3];		
	}	
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	BitDataToModbusStr()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	��
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)dataת��ΪMODBUSSLAVE��WORDֵ��STR�� 				
*�޸���־��
*[2006-3-1 14:51] 	Ver. 1.00
		��ʼ��д��	
*[2006-3-1 15:02]
		��ɣ�										
/*										 */
/*********************************************************************************/

void BitDataToModbusStr(unsigned char writeCmdStr[], int data[], unsigned short num, unsigned short startAddr)
{
	int i, j;	
	unsigned char button8Data = 0;
		
	for(j = 0; j < (int)(num / 8); j ++)	
	{
		button8Data = 0;
		for(i = 0; i < 8; i ++)
		{
			button8Data += data[i + j * 8] * (int) pow(2, i);
		}
		writeCmdStr[startAddr + j] = button8Data;
	}
	
	if(num % 8)
	{
		button8Data = 0;
		for(i = 0; i < num % 8; i ++)
		{
			button8Data += data[i + j * 8] * (int) pow(2, i);
		}
		writeCmdStr[startAddr + j] = button8Data;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	ReadWordFromModBusSlave()							
*���������	�� 2 ��������
*���������	�� 1 ��������
*����ֵ��	�ɹ����
*�财��Ĳ����� �� 1 ��������	
*���ܽ��ܣ�	
		(1) �Ӵ������ж�ȡ�趨����ֵ��
		(2) ��ȡָ��Ϊ 01 03 HA LA HN LN HC LC������ 01 ΪMODBUSSLAVE�ĵ�ַ��
		    03 Ϊ���������WORD�Ĵ����Ĺ����룬HA LA Ϊ��һ���Ĵ����ĸߵ�λ��ַ��
		    HN LN Ϊ�Ĵ��������ĸߵ�λ��HC LC ΪCRCУ���룻
		(3) ������reset������������㣬7188��⵽��״̬��������������趨������
*�޸���־��
*[2005-11-28 16:51] 	Ver. 1.00
		��ʼ��д��
*[2005-11-28 18:10]		
		��ɳ��壬δ���ԣ�
*[2006-3-3 9:38]
		static unsigned char oldModDataBack[400];��Ϊ�βΣ�
*[2006-3-3 17:58]
		����int kind�βΣ�	
*[2006-3-6 16:34]		
		strmcpy(oldModDataBack, ModDataBack, ModDataLenBack);	
*[2006-3-9 12:33]
		ȥ��		
		(strmcmp(oldModDataBack, ModDataBack, ModDataLenBack))									
/*										 */
/*********************************************************************************/

int ReadWordFromModBusSlave(int kind, int comPort, float parameterData[], unsigned short num, 
	unsigned short ModDataAddr, int parameterEEPROMAddr, unsigned char oldModDataBack[])
{			
	float parameterJudge[50];	
	
	unsigned char readCmdStr[15];
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 3;
	unsigned short ModDataNum;		
	unsigned short readCmdLen = 6;
	int isReadOK = 0;	
	
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned char ModByteNumBack = 0;
	unsigned char ModDataBack[MOD_STR_MAX_LEN] = {'/0'};

	unsigned char ModDataLenBack = 0;
	
/*	unsigned short ModWord[100];	*/
	
	int parameterDecimalEEPROM[PARAMETER_DATA_NUM] = PARAMETER_DECIMAL_EEPROM;	/* adjust */
	int parameterStartAddr = 0;
	char i7188Addr[5];
	strcpy(i7188Addr, I7188_ADDRESS);		/* adjust */
	
	if(kind == 1)
	{
		strcpy(i7188Addr, I7188_ADDRESS);
	}
	else if(kind == 2)
	{
		strcpy(i7188Addr, I7188_ADDRESS_2);
	}
	else if(kind == 3)
	{
		strcpy(i7188Addr, I7188_ADDRESS_3);
	}
		
	ModDataNum = (unsigned short)num * 2;
		
	readCmdStr[0] = ModAddr;
	readCmdStr[1] = ModFunction; 
	readCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	readCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);
	readCmdStr[4] = (unsigned char)(ModDataNum >> 8 & 0x00FF);
	readCmdStr[5] = (unsigned char)(ModDataNum & 0x00FF);	
	readCmdStr[6] = '/0';
	
	ClearCom(comPort);
	SendRtuCmdToModBus(comPort, readCmdStr, readCmdLen);
		
	isReadOK = ReadModBusRtuSlave(comPort, &ModAddrBack, &ModFunctionBack, &ModByteNumBack, 
		ModDataBack, &ModDataLenBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{	
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModByteNumBack == ModDataLenBack)) 
		{
			if (ModDataNum * 2 == ModDataLenBack)		/*!!!*/
			{					
				ChangeAllParameterDataByModBus(parameterJudge, ModDataBack, num);	
			/*	Print(" %f  %f  %f /t", parameterData[0], parameterData[1],parameterData[2]);	
				Print("/n%f  %f  %f /t", parameterJudge[0], parameterJudge[1],parameterJudge[2]);	
			*/	if(parameterJudge[0] >= 0.1)		/* ���¶��趨ֵΪ�жϵ��ж���ȷ�� */
				{
				/*	Print(" cp1.5 /n");	*/
					
					if(Datamcmp(parameterData, parameterJudge, num))
					{
						Print(" cp1.6 /n");
						ChangeAllParameterDataByModBus(parameterData, ModDataBack, num);	
					
						if(IS_RS485)  Set485DirToTransmit(COMPORT1);
						SendParameterDataToPCForwardly(COMPORT1, parameterData, i7188Addr);
						if(IS_RS485)  WaitTransmitOver(COMPORT1);
						if(IS_RS485)  {DelayMs(2); Set485DirToReceive(COMPORT1);}
					
						WriteDataToEEPROM(parameterData, parameterDecimalEEPROM, num, parameterEEPROMAddr, parameterStartAddr);
					}
					
					strmcpy(oldModDataBack, ModDataBack, ModDataLenBack);
				}
				else
				{
					/*δ��ʼ�������������Գ�ʼ*/					
					WriteMultipleWordToModBusSlave(comPort, parameterData, num, ModDataAddr);
				}
			/*	Print("/n %f  %f  %f /t", parameterData[0], parameterData[1],parameterData[2]); */
			}
			return 1;
		}
		else
		{
			/*�յ����ַ�����ƥ��*/
			return 0;
		}
	}
	else
	{
		/*δ�յ��ַ�����CRCУ�����*/
		return 0;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	ReadBitFromModBusSlave()							
*���������	�� 2 ��������
*���������	�� 1 ��������
*����ֵ��	�ɹ����
*�财��Ĳ����� �� 1 ��������	
*���ܽ��ܣ�	
		(1) �Ӵ������ж�ȡ��ťֵ��
		(2) ��ȡָ��Ϊ 01 01 HA LA HN LN HC LC������ 01 ΪMODBUSSLAVE�ĵ�ַ��
		    01 Ϊ���������BIT��Ȧ�Ĺ����룬HA LA Ϊ��һ��BIT�ĸߵ�λ��ַ��
		    HN LN ΪBIT�����ĸߵ�λ��HC LC ΪCRCУ���룻
*�޸���־��
*[2005-11-28 18:10] 	Ver. 1.00
		��ʼ��д��
*[2005-11-28 18:42]		
		��ɳ��壬δ���ԣ�
*[2006-3-3 9:38]
		static unsigned char oldModDataBack[400];��Ϊ�βΣ�
*[2006-3-3 17:58]
		����int kind�βΣ�
*[2006-3-6 16:35]
		strmcpy(oldModDataBack, ModDataBack, ModDataLenBack);	
*[2006-3-9 12:35]
		ȥ�� 	(strmcmp(oldModDataBack, ModDataBack, ModDataLenBack))													
/*										 */
/*********************************************************************************/

int ReadBitFromModBusSlave(int kind, int comPort, int buttonData[], unsigned short num, 
	unsigned short ModDataAddr, int buttonNVRAMAddr, unsigned char oldModDataBack[])
{	
	int buttonJudge[30];
	unsigned char readCmdStr[15];
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 1;	
	unsigned short ModDataNum;	
	unsigned short readCmdLen = 6;
	int isReadOK = 0;	
	
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned char ModByteNumBack = 0;
	unsigned char ModDataBack[300] = {'/0'};

	unsigned char ModDataLenBack = 0;
	
/*	unsigned short ModBit[100];	*/
	char i7188Addr[5];
	strcpy(i7188Addr, I7188_ADDRESS);		/* adjust */
	
	if(kind == 1)
	{
		strcpy(i7188Addr, I7188_ADDRESS);
	}
	else if(kind == 2)
	{
		strcpy(i7188Addr, I7188_ADDRESS_2);
	}
	else if(kind == 3)
	{
		strcpy(i7188Addr, I7188_ADDRESS_3);
	}
	
	ModDataNum = (unsigned short)num;
	
	readCmdStr[0] = ModAddr;
	readCmdStr[1] = ModFunction; 
	readCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	readCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);
	readCmdStr[4] = (unsigned char)(ModDataNum >> 8 & 0x00FF);
	readCmdStr[5] = (unsigned char)(ModDataNum & 0x00FF);	
	readCmdStr[6] = '/0';
	
	ClearCom(comPort);
	SendRtuCmdToModBus(comPort, readCmdStr, readCmdLen);
		
	isReadOK = ReadModBusRtuSlave(comPort, &ModAddrBack, &ModFunctionBack, &ModByteNumBack, 
		ModDataBack, &ModDataLenBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{		
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModByteNumBack == ModDataLenBack)) 
		{
			ChangeAllButtonsDataByModBus(buttonJudge, ModDataBack, num);		
							
			if(Bitmcmp(buttonData, buttonJudge, num))
			{
				ChangeAllButtonsDataByModBus(buttonData, ModDataBack, num);		
			
				if(IS_RS485)  Set485DirToTransmit(COMPORT1);
				SendButtonDataToPC(COMPORT1, buttonData, i7188Addr);	
				if(IS_RS485)  WaitTransmitOver(COMPORT1);
				if(IS_RS485)  {DelayMs(2); Set485DirToReceive(COMPORT1);}
				WriteButtonToNVRAM(buttonData, num, buttonNVRAMAddr);	
			}					
							
			strmcpy(oldModDataBack, ModDataBack, ModDataLenBack);		
					
			return 1;
		}
		else
		{
			/*�յ����ַ�����ƥ��*/
			return 1;
		}
	}
	else
	{
		/*δ�յ��ַ�����CRCУ�����*/
		return 0;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	WriteMultipleWordToModBusSlave()							
*���������	�� 2 ��������
*���������	�� 1 ��������
*����ֵ��	�ɹ����
*�财��Ĳ����� �� 1 ��������	
*���ܽ��ܣ�	
		(1) �Ӵ�������д���趨����ֵ��
		(2) ָ��Ϊ 01 16 HA LA HN LN HD LD ...... HC LC������ 01 ΪMODBUSSLAVE�ĵ�ַ��
		    16 Ϊд�������WORD�Ĵ����Ĺ����룬HA LA Ϊ��һ���Ĵ����ĸߵ�λ��ַ��
		    HN LN Ϊ�Ĵ��������ĸߵ�λ��HC LC ΪCRCУ���룻
		    HD LD Ϊ���ݸߵ�λ��
*�޸���־��
*[2005-11-28 18:43] 	Ver. 1.00
		��ʼ��д��
*[2006-3-1 12:20]		
		�м���˺ܶ�ʱ�䣻
		��ɳ��壬δ���ԣ�							
/*										 */
/*********************************************************************************/

int WriteMultipleWordToModBusSlave(int comPort, float parameterData[], unsigned short num, unsigned short ModDataAddr)
{	
	unsigned char writeCmdStr[MOD_STR_MAX_LEN];				/* adjust */
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 16;	
	unsigned short ModDataNum;	
	unsigned short readCmdLen;
	int isReadOK = 0;	
	
	unsigned short byteCount;
	unsigned char totalStrBack[300] = {'/0'};
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned short ModDataAddrBack;
	unsigned short ModDataNumBack;
	
	ModDataNum = (unsigned short)num * 2;
	byteCount = (unsigned short)num * 4;
	readCmdLen = 7 + byteCount;
	
	writeCmdStr[0] = ModAddr;
	writeCmdStr[1] = ModFunction; 
	writeCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	writeCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);
	writeCmdStr[4] = (unsigned char)(ModDataNum >> 8 & 0x00FF);
	writeCmdStr[5] = (unsigned char)(ModDataNum & 0x00FF);	
	writeCmdStr[6] = (unsigned char)(byteCount  & 0x00FF);
	WordDataToModbusStr(writeCmdStr, parameterData, num, 7);
	writeCmdStr[7 + byteCount] = '/0';
	
	ClearCom(comPort);
	SendRtuCmdToModBus(comPort, writeCmdStr, readCmdLen);
		
	isReadOK = ResponseFromModBusRtuSlave(comPort, totalStrBack, 
		&ModAddrBack, &ModFunctionBack, &ModDataAddrBack, 
		&ModDataNumBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{			
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModDataAddr == ModDataAddrBack)
			&& (ModDataNum == ModDataNumBack)) 
		{			
			return 1;
		}
		else
		{			
			return 0;	
		}
	}
	else
	{
		/*δ�յ��ַ�����CRCУ�����*/
		return 0;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	WriteMultipleBitToModBusSlave()							
*���������	�� 2 ��������
*���������	�� 1 ��������
*����ֵ��	�ɹ����
*�财��Ĳ����� �� 1 ��������	
*���ܽ��ܣ�	
		(1) �Ӵ�������д��BIT��
		(2) ָ��Ϊ 01 15 HA LA HN LN HD LD ...... HC LC������ 01 ΪMODBUSSLAVE�ĵ�ַ��
		    16 Ϊ���������WORD�Ĵ����Ĺ����룬HA LA Ϊ��һ��BIT�ĸߵ�λ��ַ��
		    HN LN ΪBIT�����ĸߵ�λ��HC LC ΪCRCУ���룻
		    HD LD Ϊ���ݸߵ�λ��
*�޸���־��
*[2006-3-1 12:58] 	Ver. 1.00
		��ʼ��д��	
*[2006-3-1 13:29]
		��ɣ�								
/*										 */
/*********************************************************************************/

int WriteMultipleBitToModBusSlave(int comPort, int DOData[], unsigned short num, unsigned short ModDataAddr)
{	
	unsigned char writeCmdStr[100];		
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 15;
	unsigned short ModDataNum;		
	unsigned short readCmdLen;
	int isReadOK = 0;	
	
	unsigned short byteCount;
	unsigned char totalStrBack[300] = {'/0'};
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned short ModDataAddrBack;
	unsigned short ModDataNumBack;
	
	ModDataNum = (unsigned short)num;
	if(num % 8)
		byteCount = (unsigned short)(num / 8 + 1);
	else 	byteCount = (unsigned short)(num / 8);
	
	readCmdLen = 7 + byteCount;
	
	writeCmdStr[0] = ModAddr;
	writeCmdStr[1] = ModFunction; 
	writeCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	writeCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);
	writeCmdStr[4] = (unsigned char)(ModDataNum >> 8 & 0x00FF);
	writeCmdStr[5] = (unsigned char)(ModDataNum & 0x00FF);	
	writeCmdStr[6] = (unsigned char)(byteCount  & 0x00FF);
	BitDataToModbusStr(writeCmdStr, DOData, num, 7);
	writeCmdStr[7 + byteCount] = '/0';
	
	ClearCom(comPort);
	SendRtuCmdToModBus(comPort, writeCmdStr, readCmdLen);
		
	isReadOK = ResponseFromModBusRtuSlave(comPort, totalStrBack, 
		&ModAddrBack, &ModFunctionBack, &ModDataAddrBack, 
		&ModDataNumBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{	
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModDataAddr == ModDataAddrBack)
			&& (ModDataNum == ModDataNumBack)) 
		{
			return 1;
		}
		else
		{
			return 0;	
		}
	}
	else
	{
		/*δ�յ��ַ�����CRCУ�����*/
		return 0;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	WriteSingleBitToModBusSlave()							
*���������	�� 2 ��������
*���������	�� 1 ��������
*����ֵ��	�ɹ����
*�财��Ĳ����� �� 1 ��������	
*���ܽ��ܣ�	
		(1) �Ӵ�������д��BIT��
		(2) ָ��Ϊ 01 05 HA LA HD LD ...... HC LC������ 01 ΪMODBUSSLAVE�ĵ�ַ��
		    05 Ϊд����BIT�����룬HA LA Ϊ��һ��BIT�ĸߵ�λ��ַ��
		    HN LN ΪBIT�����ĸߵ�λ��HC LC ΪCRCУ���룻
		    HD LD Ϊ���ݸߵ�λ��
*�޸���־��
*[2006-3-7 14:06] 	Ver. 1.00
		��ʼ��д��	
*[2006-3-7 14:40]
		��ɣ�	
*[2006-3-9 12:44]
		ȥ���˵ȴ����շ����Ĺ��ܣ�									
/*										 */
/*********************************************************************************/

int WriteSingleBitToModBusSlave(int comPort, int DOData[], unsigned short num, unsigned short ModDataAddr)
{	
	unsigned char writeCmdStr[15];		
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 5;
	unsigned short ModDataState;		
	unsigned short readCmdLen = 6;
/*	int isReadOK = 0;	
	
	unsigned short byteCount;
	unsigned char totalStrBack[100];
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned short ModDataAddrBack;
	unsigned short ModDataStateBack;
*/	
	ModDataState = DOData[num];
	
	writeCmdStr[0] = ModAddr;
	writeCmdStr[1] = ModFunction; 
	writeCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	writeCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);		
	if(ModDataState)    writeCmdStr[4] = (unsigned char)(0x00FF);
	else  	writeCmdStr[4] = (unsigned char)(0x0000);	
	writeCmdStr[5] = (unsigned char)(0x0000);
	writeCmdStr[6] = '/0';
	
/*	ClearCom(comPort);	*/
	SendRtuCmdToModBus(comPort, writeCmdStr, readCmdLen);
	return 1;
	
/*		
	isReadOK = ResponseSingleBitFromModBus(comPort, totalStrBack, 
		&ModAddrBack, &ModFunctionBack, &ModDataAddrBack, 
		&ModDataStateBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{		
		Print("/tB %u %u   %u %u  %u %u  %u %u", ModAddr, ModAddrBack, ModFunction, ModFunctionBack, ModDataAddr, ModDataAddrBack, ModDataState, ModDataStateBack);
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModDataAddr == ModDataAddrBack)
			&& (ModDataState == ModDataStateBack)) 
		{
			Print("/tretur sB1 /t");
			return 1;
		}
		else
		{
			Print("/tretur sB0 /t");
			return 0;	
		}
	}
	else
	{
		/*δ�յ��ַ�����CRCУ�����* /
		return 0;
	}
*/	
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	WriteBitByBitToModBusSlave()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	�ɹ����
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1) һ��һ���ؽ�BITд�紥�����У�
		(2) ���ܺܺ�ʱ��	
*�޸���־��
*[2006-3-7 14:40] 	Ver. 1.00
		��ʼ��д��	
*[2006-3-7 14:51]
		��ɣ�								
/*										 */
/*********************************************************************************/

int WriteBitByBitToModBusSlave(int comPort, int DOData[], int dataOld[], unsigned short num, unsigned short ModDataAddr)
{	
	int i;
	
	for(i = 0; i < num; i ++)
	{
		if(DOData[i] != dataOld[i])
		{		
			DelayMs(1);
			WriteSingleBitToModBusSlave(comPort, DOData, i, ModDataAddr + i);					
		}
	}
	return 1;
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	WriteAllBitByBitToModBusSlave()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	�ɹ����
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1) һ��һ���ؽ�BITд�紥�����У�
		(2) ���ܺܺ�ʱ��	
*�޸���־��
*[2006-3-9 12:52] 	Ver. 1.00
		��ʼ��д��	
*[2006-3-9 12:52]
		��ɣ�								
/*										 */
/*********************************************************************************/

int WriteAllBitByBitToModBusSlave(int comPort, int DOData[], unsigned short num, unsigned short ModDataAddr)
{	
	int i;
	
	for(i = 0; i < num; i ++)
	{		
		DelayMs(1);
		WriteSingleBitToModBusSlave(comPort, DOData, i, ModDataAddr + i);					
		
	}
	return 1;
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*��������:	ListenToTouch()							
*���������	��  ��������
*���������	��  ��������
*����ֵ��	�ޣ�
*�财��Ĳ����� ��  ��������	
*���ܽ��ܣ�	
		(1)���Touch��������
		(2) init�Ĺ����� WriteMultipleWordToModBusSlave �Ƿ�ɹ���
		(3) ����ҪDelayMs(50)����ʹһ�¸�response��ȷ��
*�޸���־��
*[2006-3-1 17:19] 	Ver. 1.00
		��ʼ��д��	
*[2006-3-1 17:33]
		��ɣ�	
*[2006-3-9 14:10]
		����ͨ����								
/*										 */
/*********************************************************************************/

void ListenToTouch(int comPort, int buttonData[], float parameterData[], int DOData[], float AIData[])
{
	int kind = 1;					/* adjust */
	
	unsigned short parameterNum = PARAMETER_DATA_NUM;
	unsigned short parameterAddr = PARAMETER_MODBUS_ADDR_1;	/* adjust */
	
	unsigned short buttonNum = BUTTON_DATA_NUM;
	unsigned short buttonAddr = BUTTON_MODBUS_ADDR_1;	/* adjust */
	
	unsigned short DONum = DIGITAL_OUT_DATA_NUM;
	unsigned short DOAddr = DO_MODBUS_ADDR_1;	/* adjust */
	
	unsigned short AINum = ANALOG_IN_DATA_NUM;
	unsigned short AIAddr = AI_MODBUS_ADDR_1;	/* adjust */
	
	int buttonNVRAMAddr = BUTTON_ADDR_1;		/* adjust */	
	int parameterEEPROMAddr = EEPROM_BLOCK;		/* adjust */
	
	static unsigned char oldModWordBack[MOD_STR_MAX_LEN] = {'/0'};	/* ��ǰ��str */
	static unsigned char oldModBitBack[MOD_STR_MAX_LEN] = {'/0'};
	
	static int responseFromTouch_init = 0;		/*�״γ�ʼ��*/
/*	static int responseFromTouch_P = 0;
	static int responseFromTouch_Btn = 0;	
	static int oldButtonData[30] = {0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0};
	static int oldDOData[30] = {0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0};
*/	
	int response;		/*test*/
	
/*	Print("/n/n");	*/
	if(0 == responseFromTouch_init)		/* ��һ��д��Touch_Btnʧ������д */
	{	
	/*	responseFromTouch_Btn = WriteMultipleBitToModBusSlave(comPort, buttonData, buttonNum, buttonAddr);
	*/	response = WriteAllBitByBitToModBusSlave(comPort, buttonData, buttonNum, buttonAddr);		
	/*	bitmcpy(oldButtonData, buttonData, buttonNum);	*/
	}
	else
	{
		/* ��ȡ��ťֵ */
		response = ReadBitFromModBusSlave(kind, comPort, buttonData, buttonNum, buttonAddr, buttonNVRAMAddr, oldModBitBack);
	}
	DelayMs(50);
/*	Print(" rb%d", response);	*/
	
	if(0 == responseFromTouch_init)			/* ��һ��д��Touch_Pʧ������д */
	{		
		responseFromTouch_init = WriteMultipleWordToModBusSlave(comPort, parameterData, parameterNum, parameterAddr);
		response = responseFromTouch_init;
	/*	responseFromTouch_P = 1;	/*test*/
	}	
	else
	{
		/* ��ȡ�趨���� */
		response = ReadWordFromModBusSlave(kind, comPort, parameterData, parameterNum, parameterAddr, parameterEEPROMAddr, oldModWordBack);
	}
	
/*	Print(" p%d", responseFromTouch_P);
	Print(" rp%d", response);	*/
	DelayMs(2);
	/* д�뿪���� */
/*	response = WriteMultipleBitToModBusSlave(comPort, DOData, DONum, DOAddr);	
*/	
	response = WriteAllBitByBitToModBusSlave(comPort, DOData, DONum, DOAddr);
/*	bitmcpy(oldDOData, DOData, DONum);	*/
		
/*	Print(" d%d", response);	*/
	DelayMs(40);
	/* д�����ֵ */
	response = WriteMultipleWordToModBusSlave(comPort, AIData, AINum, AIAddr);
/*	Print(" a%d", response);	*/
	if(response);
}

/*-------------------------------------------------------------------------------*/

