#include "yaffsfs.h"
#include "Sensor.h"
#include "stdio.h"
#include "EquipmentList.h"
#include "DataStruct.h"

void File_Set_Config_Analogue(int* f, Analogue_Config* analogue_conf);
void File_Get_Config_Analogue(int* f, Analogue_Config* analogue_conf);

void File_Set_Config_Switch(int* f, Switch_Config* switch_conf);
void File_Get_Config_Switch(int* f, Switch_Config* switch_conf);

void File_Set_Config_Accumulate(int* f, Accumulate_Config* accumulate_conf);
void File_Get_Config_Accumulate(int* f, Accumulate_Config* accumulate_conf);

void File_Set_Config_Tristate(int* f, Tristate_Config* tristate_conf);
void File_Get_Config_Tristate(int* f, Tristate_Config* tristate_conf);

/* �����ã������յ�������Ϣ�ṹ�� */
void initConf( Analogue_Config *an, Switch_Config *sw, Accumulate_Config *ac, Tristate_Config *tr )
{
    an->testpointNo=111111;
    an->sensorName = SENSOR_METHANE;
    strcpy( an->location, "The location is A.");
    an->portType = 11;
    an->outputControl=0x11;
    an->coefficient = 1.1;

    sw->testpointNo=222222;
    sw->sensorName = SENSOR_2_OPEN_OFF;
    strcpy( sw->location, "The location is B.");
    sw->portType = 22;
    sw->outputControl=0x22;

    ac->testpointNo=333333;
    ac->sensorName = SENSOR_HOOK_NUM;
    strcpy( ac->location, "The location is C.");
    ac->portType = 33;
    ac->coefficient = 3.3;

    tr->testpointNo=444444;
    tr->sensorName = SENSOR_3_OPEN_OFF;
    strcpy( tr->location, "The location is D.");
    tr->portType = 44;
    tr->outputControl=0x44;

    return;
}

void File_Create(void)
{
		int f;
		char buf[BUFFERSIZE];
		Analogue_Config     analogue_conf;
		Switch_Config       switch_conf;
		Accumulate_Config   accumulate_conf;
		Tristate_Config     tristate_conf;
	
		initConf( &analogue_conf, &switch_conf, &accumulate_conf, &tristate_conf );
	
		f = yaffs_open( "/nand/config/TestpointConfig",  O_RDWR | O_TRUNC, S_IREAD | S_IWRITE  );
		if ( f >= 0 )
		{
				File_Set_Config_Analogue( &f, &analogue_conf );
				File_Set_Config_Switch( &f, &switch_conf );
				File_Set_Config_Accumulate( &f, &accumulate_conf );
				File_Set_Config_Tristate( &f, &tristate_conf );
/*				
				memset(buf, '\0', sizeof(buf));
				sprintf( buf, "%s", "end." );
				buf[BUFFERSIZE-1] = '\n';
				n = yaffs_write(f, buf, BUFFERSIZE );
*/			
				yaffs_close(f);
		}
		return;
}

void File_Update(void)
{
		return;
}

/**************************************

						��ʼ�������ļ�

***************************************/

void File_Init(void)
{
		int f1, f2;
	
		yaffs_mount("/nand");											//����
    
		f1 = yaffs_open("nand/first_start", O_RDONLY, 0 );
	  if ( f1 >= 0 )    //���ǵ�һ�������ļ�ϵͳ 
		{			
				f2 = yaffs_open("/nand/config/TestpointConfig", O_RDONLY, 0 );    //��������ļ��Ƿ����
				if (f2 >= 0)
				{
					 printf("Open Success! Config Exist!\n");
				}
				else 																															//��������ڣ�����һ��
				{
					 f2 = yaffs_open( "/nand/config/TestpointConfig",  O_CREAT | O_RDWR | O_TRUNC, S_IREAD | S_IWRITE  );
					 if ( f2 >= 0 )
							printf("Create Success! Config doesn't exist!\n");
				}
		}
		else             //��һ�������ļ�ϵͳ
 	  {
				yaffs_format("/nand", 0, 0, 0);           //��ʽ��
				yaffs_mount("/nand");											//����
				yaffs_mkdir("/nand/config", 0666);				//����Ŀ¼
				
				f1 = yaffs_open( "/nand/first_start",  O_CREAT | O_RDWR | O_TRUNC, S_IREAD | S_IWRITE  );
				if ( f1 >= 0 )
				{
						printf("Format success!\n");
				}
			
				f2 = yaffs_open( "/nand/config/TestpointConfig",  O_CREAT | O_RDWR | O_TRUNC, S_IREAD | S_IWRITE  );
				
				if ( f2 >= 0 )
						printf("Create Success!\n");
		}
		yaffs_close(f2);
		
		File_Create();
		
		yaffs_close(f1);
				
		return;
}

/**************************************

			ģ������������Ϣд���ļ�

***************************************/

void File_Set_Config_Analogue(int* f, Analogue_Config* analogue_conf)
{
		int n;
		char buf[BUFFERSIZE];
		memset(buf, '\0', sizeof(buf));
		
		sprintf( buf, "Type: %d", SENSOR_ANALOGUE );															//��������
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d %d %d", analogue_conf->testpointNo, analogue_conf->sensorName, analogue_conf->portType, 12 );   //����ţ����������ͣ��˿����ͣ��˿ڵ�ַ
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%s", analogue_conf->location );               //��װ�ص�
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d", analogue_conf->alarm.minval, analogue_conf->alarm.maxval );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d", analogue_conf->liftAlarm.minval, analogue_conf->liftAlarm.maxval );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d", analogue_conf->measureRange.minval, analogue_conf->measureRange.maxval );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d", analogue_conf->outage.minval, analogue_conf->outage.maxval );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d", analogue_conf->recover.minval, analogue_conf->recover.maxval );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %.3f", analogue_conf->outputControl, analogue_conf->coefficient );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		return;
}

/**************************************

			��������������Ϣд���ļ�

***************************************/

void File_Set_Config_Switch(int* f, Switch_Config* switch_conf)
{
		int n;
		char buf[BUFFERSIZE];
		memset(buf, '\0', sizeof(buf));
		
		sprintf( buf, "Type: %d", SENSOR_SWITCH );															//��������
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d %d %d", switch_conf->testpointNo, switch_conf->sensorName, switch_conf->portType, 22 );   //����ţ����������ͣ��˿����ͣ��˿ڵ�ַ
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%s", switch_conf->location );               //��װ�ص�
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d", switch_conf->outputControl );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );

		return;
}

/**************************************

			�ۼ�����������Ϣд���ļ�

***************************************/

void File_Set_Config_Accumulate(int* f, Accumulate_Config* accumulate_conf)
{
		int n;
		char buf[BUFFERSIZE];
	
		memset(buf, '\0', sizeof(buf));	
		sprintf( buf, "Type: %d", SENSOR_ACCUMULATE );															//��������
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d %d %d", accumulate_conf->testpointNo, accumulate_conf->sensorName, accumulate_conf->portType, 12 );   //����ţ����������ͣ��˿����ͣ��˿ڵ�ַ
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%s", accumulate_conf->location );               //��װ�ص�
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d", accumulate_conf->measureMaxVal );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%.3f", accumulate_conf->coefficient );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );

		return;
}

/**************************************

			��̬��������������Ϣд���ļ�

***************************************/

void File_Set_Config_Tristate(int* f, Tristate_Config* tristate_conf)
{
		int n;
		char buf[BUFFERSIZE];
		memset(buf, '\0', sizeof(buf));
		
		sprintf( buf, "Type: %d", SENSOR_TRISTATE );															//��������
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d %d %d", tristate_conf->testpointNo, tristate_conf->sensorName, tristate_conf->portType, 12 );   //����ţ����������ͣ��˿����ͣ��˿ڵ�ַ
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%s", tristate_conf->location );               //��װ�ص�
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d %d", tristate_conf->correctRange.minval, tristate_conf->correctRange.maxval );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
		
		memset(buf, '\0', sizeof(buf));
		sprintf( buf, "%d", tristate_conf->outputControl );
		buf[BUFFERSIZE-1] = '\n';
		n = yaffs_write((*f), buf, BUFFERSIZE );
	
		return;
}


/**********************************************

							��ȡģ��������������

***********************************************/

void File_Get_Config_Analogue(int* f, Analogue_Config* analogue_conf)
{
		int n;
		char buf[BUFFERSIZE];
	
		printf("In Analogue Config Function:\n");
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		printf( "buf=[%s]\n", buf );
		sscanf( buf, "%d %d %d %d", &analogue_conf->testpointNo, &analogue_conf->sensorName, &analogue_conf->portType, &n );   //����ţ����������ͣ��˿����ͣ��˿ڵ�ַ
				
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		printf( "buf=[%s]\n", buf );
		strcpy( analogue_conf->location, buf );               //��װ�ص�
				
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		printf( "buf=[%s]\n", buf );
		sscanf( buf, "%d %d", &analogue_conf->alarm.minval, &analogue_conf->alarm.maxval );
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		printf( "buf=[%s]\n", buf );
		sscanf( buf, "%d %d", &analogue_conf->liftAlarm.minval, &analogue_conf->liftAlarm.maxval );
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		printf( "buf=[%s]\n", buf );
		sscanf( buf, "%d %d", &analogue_conf->measureRange.minval, &analogue_conf->measureRange.maxval );
				
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		printf( "buf=[%s]\n", buf );
		sscanf( buf, "%d %d", &analogue_conf->outage.minval, &analogue_conf->outage.maxval );
				
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		printf( "buf=[%s]\n", buf );
		sscanf( buf, "%d %d", &analogue_conf->recover.minval, &analogue_conf->recover.maxval );
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read((*f), buf, BUFFERSIZE );
		printf( "buf=[%s]\n", buf );
		sscanf( buf, "%d %f", &analogue_conf->outputControl, &analogue_conf->coefficient );
		
		printf("Quit Analogue Config Function\n");
	
		return;
}

/**************************************

			��ȡ������������������Ϣ

***************************************/

void File_Get_Config_Switch(int* f, Switch_Config* switch_conf)
{
		int n;
		char buf[BUFFERSIZE];
	
		printf("In Switch Config Function:\n");
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		sscanf( buf, "%d %d %d %d", &switch_conf->testpointNo, &switch_conf->sensorName, &switch_conf->portType, &n );   //����ţ����������ͣ��˿����ͣ��˿ڵ�ַ
				
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		strcpy( switch_conf->location, buf );               //��װ�ص�
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		sscanf( buf, "%d", &switch_conf->outputControl );	
		
		printf("Quit Switch Config Function\n");

		return;
}

/**************************************

			��ȡ�ۼ���������������Ϣ

***************************************/

void File_Get_Config_Accumulate(int* f, Accumulate_Config* accumulate_conf)
{
		int n;
		char buf[BUFFERSIZE];

		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		sscanf( buf, "%d %d %d %d", &accumulate_conf->testpointNo, &accumulate_conf->sensorName, &accumulate_conf->portType, &n );   //����ţ����������ͣ��˿����ͣ��˿ڵ�ַ
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		strcpy( accumulate_conf->location, buf );               //��װ�ص�
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		sscanf( buf, "%d", &accumulate_conf->measureMaxVal );
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		sscanf( buf, "%f", &accumulate_conf->coefficient );

		return;
}

/**************************************

			��ȡ��̬������������������Ϣ

***************************************/

void File_Get_Config_Tristate(int* f, Tristate_Config* tristate_conf)
{
		int n;
		char buf[BUFFERSIZE];
	
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		sscanf( buf, "%d %d %d %d", &tristate_conf->testpointNo, &tristate_conf->sensorName, &tristate_conf->portType, &n );   //����ţ����������ͣ��˿����ͣ��˿ڵ�ַ
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		strcpy( tristate_conf->location, buf );               //��װ�ص�
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		sscanf( buf, "%d %d", &tristate_conf->correctRange.minval, &tristate_conf->correctRange.maxval );		
		
		memset(buf, '\0', sizeof(buf));
		n = yaffs_read( (*f), buf, BUFFERSIZE );
		sscanf( buf, "%d", &tristate_conf->outputControl );
	
		return;
}
