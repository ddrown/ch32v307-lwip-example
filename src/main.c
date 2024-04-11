/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
*******************************************************************************/
#include "Debug/debug.h"
#include "ch32v30x_eth.h"
#include "main.h"
#include "tcpecho.h"
#include "lwip/apps/lwiperf.h"
#include "lwipsetup.h"
#include "tiny-os-task.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    Delay_Init();
    USART_Printf_Init(115200);

    lwip_setup();

    printf("Enter main loop.\n");
    while(1) {
	lwip_loop();
    }
}

/* IP allocation success callback, users add initialization function about network process here / IP分配成功回调，用户在此增加关于网络进程的初始化函数 */
void lwip_init_success_callback(ip_addr_t *ip)
{
    printf("IP %ld.%ld.%ld.%ld\n\n",  \
        ((ip->addr)&0x000000ff),       \
        (((ip->addr)&0x0000ff00)>>8),  \
        (((ip->addr)&0x00ff0000)>>16), \
        ((ip->addr)&0xff000000)>>24);
    TCP_Echo_Init();
    lwiperf_start_tcp_server_default(NULL, NULL);
}
