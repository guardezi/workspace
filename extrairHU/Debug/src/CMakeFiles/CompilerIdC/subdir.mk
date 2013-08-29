################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CMakeFiles/CompilerIdC/CMakeCCompilerId.c 

C_DEPS += \
./src/CMakeFiles/CompilerIdC/CMakeCCompilerId.d 

OBJS += \
./src/CMakeFiles/CompilerIdC/CMakeCCompilerId.o 


# Each subdirectory must supply rules for building sources it contributes
src/CMakeFiles/CompilerIdC/%.o: ../src/CMakeFiles/CompilerIdC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I/usr/local/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


