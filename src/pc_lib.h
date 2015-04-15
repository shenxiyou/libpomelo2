/**
 * Copyright (c) 2014,2015 NetEase, Inc. and other Pomelo contributors
 * MIT Licensed.
 */

#ifndef PC_LIB_H
#define PC_LIB_H

#include <stddef.h>

#if defined(_WIN32) && !defined(__cplusplus)

#include <windows.h>

#define PC_INLINE __inline

typedef SOCKET pc_socket_t;
#define pc_close_socket(s) closesocket(a)
#define PC_ECONNRESET WSAECONNRESET
#define pc_invalid_socket (pc_socket_t)-1


#else

#define PC_INLINE inline

typedef int pc_socket_t;
#define pc_close_socket(s) close(s)
#define pc_invalid_socket (pc_socket_t)-1

#define PC_ECONNRESET ECONNRESET

#endif

extern void (*pc_lib_log)(int level, const char* msg, ...);
extern void* (*pc_lib_malloc)(size_t len);
extern void (*pc_lib_free)(void* data);
extern const char* pc_lib_platform_type;

const char* pc_lib_strdup(const char* str);

int pc_pipe_create(pc_socket_t p[2]);

#endif
