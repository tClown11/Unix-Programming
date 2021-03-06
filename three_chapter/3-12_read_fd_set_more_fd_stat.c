/* 对于一个文件描述符开启一个或多个文件状态标志 */
#include "../apue.h"
#include <fcntl.h>

void
set_fl(int fd, int flags) /* flags are file status flags to return on */
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");

    val |= flags;   /* turn on flags */

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}