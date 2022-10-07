CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(testcommand
    Tasks/Tasks.cpp
    Task/Task.cpp
    Project/Project.cpp
    Strategysrc/Prioritize.cpp
    #Strategy/Scheduler.cpp
    #Strategy/Completed.cpp
    commandtest.cpp
    Tasks/Tasks.cpp
    taskmock/TaskMock.cpp
    taskmock/ProjectMock.cpp
    taskcommandssrc/addtask.cpp
    taskcommandssrc/changetaskname.cpp
    taskcommandssrc/changetaskdeadline.cpp
    taskcommandssrc/changetaskstatus.cpp
    taskcommandssrc/changetaskdescription.cpp
    taskcommandssrc/printTasks.cpp
    prioritizemock/SchedulerMock.cpp
    prioritizemock/CompletedMock.cpp
)

ADD_EXECUTABLE(testProject Project/Project_test.cpp Project/Project.cpp Task/Task.cpp Tasks/Tasks.cpp)

ADD_EXECUTABLE(test menu/menu_test.cpp)

ADD_EXECUTABLE(testTask Task/Task_test.cpp Task/Task.cpp Tasks/Tasks.cpp)

ADD_EXECUTABLE(main 
        main.cpp 
        menu/menu.cpp 
        Task/Task.cpp 
        Tasks/Tasks.cpp
        taskcommandssrc/addtask.cpp 
        taskcommandssrc/changetaskname.cpp 
        taskcommandssrc/changetaskdescription.cpp 
        taskcommandssrc/changetaskdeadline.cpp 
        taskcommandssrc/changetaskstatus.cpp 
        taskcommandssrc/printTasks.cpp
        Project/Project.cpp 
 	Strategysrc/Prioritize.cpp 
	Strategysrc/Completed.cpp 
	Strategysrc/Scheduler.cpp 
)

ADD_EXECUTABLE(compositevalgrindcomp
    valgrindtests/compositetestcomp.cpp 
    Task/Task.cpp
    Tasks/Tasks.cpp
    Project/Project.cpp
)

ADD_EXECUTABLE(compositevalgrind
    valgrindtests/compositetest.cpp
    Task/Task.cpp
    Tasks/Tasks.cpp
    Project/Project.cpp
)

ADD_EXECUTABLE(commandvalgrind
    valgrindtests/commandtest.cpp
    Task/Task.cpp
    Tasks/Tasks.cpp
    Project/Project.cpp
    taskcommandssrc/addtask.cpp
    taskcommandssrc/changetaskname.cpp
    taskcommandssrc/changetaskdeadline.cpp
    taskcommandssrc/changetaskstatus.cpp
    taskcommandssrc/changetaskdescription.cpp
    taskcommandssrc/printTasks.cpp
    Strategysrc/Prioritize.cpp 
    Strategysrc/Scheduler.cpp
    Strategysrc/Completed.cpp
)
ADD_EXECUTABLE(testStrategy
	Strategysrc/Strategy_test.cpp
        Strategysrc/Prioritize.cpp
        Strategysrc/Completed.cpp
        Strategysrc/Scheduler.cpp
        Task/Task.cpp
        Tasks/Tasks.cpp
        Project/Project.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_LINK_LIBRARIES(testTask gtest)
TARGET_LINK_LIBRARIES(testcommand gtest)
TARGET_LINK_LIBRARIES(testProject gtest)
TARGET_LINK_LIBRARIES(testStrategy gtest)
TARGET_COMPILE_DEFINITIONS(testProject PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(testTask PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(testcommand PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(testStrategy PRIVATE gtest_disable_pthreads=ON)

