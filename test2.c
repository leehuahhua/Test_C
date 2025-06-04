/*以下是UDP的AT指令(每条指令都要发送新行)*///AT指令例程见手册https://docs.ai-thinker.com/_media/esp8266/esp8266_at_command_examples_cn.pdf
/*--------------------------------------------------------------*/
/*作为AP的esp8266*/
AT+CWMODE=3//STA_AP
AT+RST
AT+CWSAP="ESP8266_AP","753951@Lee",1,3//频段内的通道1，加密方式WPA_WPA2_PSK
AT+CIPMUX=0//单连接，为了透传
AT+CIPAP="192.168.22.1"//更改AP的IP信息
AT+CIPSTART="UDP","192.168.22.2",6666,7777,0
AT+CIPMODE=1//使能透传
// AT+SAVETRANSLINK=1,"192.168.22.2",6666,"UDP"//透传设置保存到flash，上电就进入透传模式

//测试
AT+CIPSTATE?//查询 TCP/UDP/SSL 连接信息
AT+CIFSR//查询AP和STA(连接到AP才能查到)的IP和mac
退出透传的+++是有点时间要求和格式要求，见文档

/*作为STA的esp8266*/
AT+CWMODE=3//STA_AP 
AT+RST
AT+CWJAP="ESP8266_AP","753951@Lee"
AT+CIPMUX=0//单连接，为了透传
AT+CIPSTA="192.168.22.2"
AT+CIPSTART="UDP","192.168.22.1",7777,6666,0
AT+CIPMODE=1
// AT+SAVETRANSLINK=1,"192.168.22.1",7777,"UDP"//透传设置保存到flash，上电就进入透传模式
AT+CIPSEND

//关键是STA和AP的IP设置要在一个网络号下，因为我未设置网关(路由器)
//本次UDP连接方式可在此处找到近似历程(后知后觉)https://docs.ai-thinker.com/_media/esp8266/docs/esp8266_series_modules_user_manual_zh_v1.5.pdf

/*更全更详细的AT指令文档(强烈建议在使用命令之前先阅读以下内容，了解 AT 命令的一些基本信息如：AT 命令分类	参数信息保存在 flash 中的 AT 命令	AT 消息)
见https://docs.espressif.com/projects/esp-at/zh-cn/release-v2.2.0.0_esp8266/AT_Command_Set/TCP-IP_AT_Commands.html 
这是个html页面不是普通文档是多个文档合在一起，所以有些指令要在左边栏换个指令集搜索*/

//我使用的AT固件不支持如AT+CWMODE_DEF这类xxx_DEF能写入flash的指令，但是<AT+SYSSTORE?>查询得知这类信息(具体见文档)默认写到flash里面了

//文档显示	AT+SAVETRANSLINK=1,"192.168.22.2",6666,"UDP",0	最后一个参数0为禁用tcp keep-alive默认为零但是不让我来写0，写了返回erro。	

/*
进入 Wi-Fi 透传模式，ESP8266 设备每次最大接收 2048 字节，最大发送 1460 字节；其他 ESP 设备每次最大接收 8192 字节，
最大发送 2920 字节。如果当前接收的数据长度大于最大发送字节数，AT 将立即发送；否则，接收的数据将在 20 ms 内发送。
当输入单独一包 +++ 时，退出 透传模式 下的数据发送模式，请至少间隔 1 秒再发下一条 AT 命令
*/




//esp8266_at_instruction_set_cn.pdf这个文档里面参数列表很粗心，例如应该是<"type">却写成<type>