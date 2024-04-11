#pragma once

enum
{
    os_lwip = 0,
    os_lwip_timeouts,
    TINY_MACRO_OS_TASKS_MAX_NUM,
    /* 该选项不可删除或修改，用于计算任务数量去定义时间数组和状态数组，最大255个任务 
     * TINY_MACRO_OS_TASKS_MAX_NUM cannot be deleted or modified. It is used to calculate the number of tasks to define the time array and state array. The maximum number of tasks is 255.
     */
};

void lwip_loop();
