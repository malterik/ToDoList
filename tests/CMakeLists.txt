
add_executable(test_task test_task.cpp ../src/Task.cpp)

add_test(NAME test_task COMMAND test_task)
