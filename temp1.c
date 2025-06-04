wifiAudio的usart1和esp8266的uart3都是指向电脑的的串口
void HAL_UART_IRQHandler(huart2)
{   
    
    if(__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) !== RESET )//USART_GetITStatus( USART2, USART_IT_RXNE ) != RESET//Lee
    {
		HAL_UART_Transmit(&huart2,&rx_data2,1,50);
        if(ESP8266_Fram_Record_Struct .InfBit .FramLength < ( RX_BUF_MAX_LEN - 1 ) ) 
        {

            ESP8266_Fram_Record_Struct .Data_RX_BUF[ ESP8266_Fram_Record_Struct .InfBit .FramLength ++ ]  = rx_data2;   
        }
        HAL_UART_Receive_IT(&huart1, &rx_data2, 1);//再次启动接收中断
                    
    }

    if( __HAL_UART_GET_FLAG(&huart2, UART_FLAG_IDLE) == SET )                                         //如果总线空闲
    {
        ESP8266_Fram_Record_Struct .InfBit .FramFinishFlag = 1;

        //ucCh = USART_ReceiveData( USART2 );                                                              //由软件序列清除中断标志位（先读USART_SR,然后读USART_DR）
		__HAL_UART_CLEAR_IDLEFLAG(&huart2);
        TcpClosedFlag = strstr ( ESP8266_Fram_Record_Struct .Data_RX_BUF, "CLOSED\r\n" ) ? 1 : 0;

    }   

}




void HAL_UART_IRQHandler( huart1 )
{   
    // u8 ucCh;//Lee

    if(__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) !== RESET )//USART_GetITStatus( USART2, USART_IT_RXNE ) != RESET//Lee
    {
        HAL_UART_Transmit(&huart2,&rx_data1,1,50);          // ucCh  = USART_ReceiveData( USART3 );//从电脑端得到的数据

        if(ESP8266_Fram_Record_Struct .InfBit .FramLength < ( RX_BUF_MAX_LEN - 1 ) ) 
        {
            //留最后一位做结束位
            ESP8266_Fram_Record_Struct .Data_RX_BUF[ ESP8266_Fram_Record_Struct .InfBit .FramLength ++ ]  = rx_data1;   
        }                      
    }

    if( __HAL_UART_GET_FLAG(&huart2, UART_FLAG_IDLE) == SET )                              //如果总线空闲即一帧数据发完
    {
        ESP8266_Fram_Record_Struct .InfBit .FramFinishFlag = 1;
        __HAL_UART_CLEAR_IDLEFLAG(&huart1);                                                              //由软件序列清除中断标志位（先读USART_SR,然后读USART_DR）
        TcpClosedFlag = strstr ( ESP8266_Fram_Record_Struct .Data_RX_BUF, "CLOSED\r\n" ) ? 1 : 0;

    }   

}
