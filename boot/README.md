Before you start, you have to install extension version STM32Cube in vs code
1. If you add your own file, please add directory in CMakeList.txt
2. main.c file was maken by users, so you have to delete directory in cmake\stm32cubemx\CMakeLists.txt
3. It it possible to name a same file name, but same fuction or variable(except static) can lead build error.
   so you have to delete another file source you do not use.
4. check the history, you can fine all sample code in there
