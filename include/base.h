/* 
	@Author: gatsby
	@Mail: i-careforu＠foxmail.com
    ＠Comment: 基本的数据结构与宏定义。
*/

#ifndef __BASE_H
#define __BASE_H

/* 如果未定义DEBUG宏或者_DEBUG，则定义NDEBUG（assert根据此宏决定是否生成代码） */
#if !defined(DEBUG) && !defined(_DEBUG)
#define NDEBUG
#endif

/*
#if defined(WIN32) || defined(_WIN32)
#define LINUX
#endif

#ifdef LINUX
#define STDCALL
#else
#define STDCALL __stdcall
#endif */

#define STDCALL /* 标准调用约定 */
#define CALLBACK

/* 包含基本的头文件 */
#include <assert.h>
#include <sys/epoll.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

/* 功能性宏 */

// 安全删除指针
#define SAFE_DELETE(ptr) do{ \
if(ptr != NULL){ \
	free(ptr); ptr = NULL; \
}}while(0)
//　初始化结构体
#define ZEROMEMORY(o) memset((void *)&o, sizeof(o), 0)
// 将文件描述符设置为异步模式
#define ASYNCFD(fd) do{ \
int _flags = fcntl(fd, F_GETFL, 0); \
if(_flags != -1){ \
	_flags = fcntl(fd, F_SETFL, _flags | O_NONBLOCK); \
	assert(_flags != -1); \
}}while(0)
// 跳出错误处理结构
#define JUMP(o) if(o == -1){break; perror("error:");}


/* 数据类型声明 */
typedef void *HENV;
typedef unsigned long ulong;


#endif

