/*������UDP��ATָ��(ÿ��ָ�Ҫ��������)*///ATָ�����̼��ֲ�https://docs.ai-thinker.com/_media/esp8266/esp8266_at_command_examples_cn.pdf
/*--------------------------------------------------------------*/
/*��ΪAP��esp8266*/
AT+CWMODE=3//STA_AP
AT+RST
AT+CWSAP="ESP8266_AP","753951@Lee",1,3//Ƶ���ڵ�ͨ��1�����ܷ�ʽWPA_WPA2_PSK
AT+CIPMUX=0//�����ӣ�Ϊ��͸��
AT+CIPAP="192.168.22.1"//����AP��IP��Ϣ
AT+CIPSTART="UDP","192.168.22.2",6666,7777,0
AT+CIPMODE=1//ʹ��͸��
// AT+SAVETRANSLINK=1,"192.168.22.2",6666,"UDP"//͸�����ñ��浽flash���ϵ�ͽ���͸��ģʽ

//����
AT+CIPSTATE?//��ѯ TCP/UDP/SSL ������Ϣ
AT+CIFSR//��ѯAP��STA(���ӵ�AP���ܲ鵽)��IP��mac
�˳�͸����+++���е�ʱ��Ҫ��͸�ʽҪ�󣬼��ĵ�

/*��ΪSTA��esp8266*/
AT+CWMODE=3//STA_AP 
AT+RST
AT+CWJAP="ESP8266_AP","753951@Lee"
AT+CIPMUX=0//�����ӣ�Ϊ��͸��
AT+CIPSTA="192.168.22.2"
AT+CIPSTART="UDP","192.168.22.1",7777,6666,0
AT+CIPMODE=1
// AT+SAVETRANSLINK=1,"192.168.22.1",7777,"UDP"//͸�����ñ��浽flash���ϵ�ͽ���͸��ģʽ
AT+CIPSEND

//�ؼ���STA��AP��IP����Ҫ��һ��������£���Ϊ��δ��������(·����)
//����UDP���ӷ�ʽ���ڴ˴��ҵ���������(��֪���)https://docs.ai-thinker.com/_media/esp8266/docs/esp8266_series_modules_user_manual_zh_v1.5.pdf

/*��ȫ����ϸ��ATָ���ĵ�(ǿ�ҽ�����ʹ������֮ǰ���Ķ��������ݣ��˽� AT �����һЩ������Ϣ�磺AT �������	������Ϣ������ flash �е� AT ����	AT ��Ϣ)
��https://docs.espressif.com/projects/esp-at/zh-cn/release-v2.2.0.0_esp8266/AT_Command_Set/TCP-IP_AT_Commands.html 
���Ǹ�htmlҳ�治����ͨ�ĵ��Ƕ���ĵ�����һ��������Щָ��Ҫ�����������ָ�����*/

//��ʹ�õ�AT�̼���֧����AT+CWMODE_DEF����xxx_DEF��д��flash��ָ�����<AT+SYSSTORE?>��ѯ��֪������Ϣ(������ĵ�)Ĭ��д��flash������

//�ĵ���ʾ	AT+SAVETRANSLINK=1,"192.168.22.2",6666,"UDP",0	���һ������0Ϊ����tcp keep-aliveĬ��Ϊ�㵫�ǲ�������д0��д�˷���erro��	

/*
���� Wi-Fi ͸��ģʽ��ESP8266 �豸ÿ�������� 2048 �ֽڣ������ 1460 �ֽڣ����� ESP �豸ÿ�������� 8192 �ֽڣ�
����� 2920 �ֽڡ������ǰ���յ����ݳ��ȴ���������ֽ�����AT ���������ͣ����򣬽��յ����ݽ��� 20 ms �ڷ��͡�
�����뵥��һ�� +++ ʱ���˳� ͸��ģʽ �µ����ݷ���ģʽ�������ټ�� 1 ���ٷ���һ�� AT ����
*/




//esp8266_at_instruction_set_cn.pdf����ĵ���������б�ܴ��ģ�����Ӧ����<"type">ȴд��<type>