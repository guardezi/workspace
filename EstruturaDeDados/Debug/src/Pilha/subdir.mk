################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Pilha/pilha.c 

OBJS += \
./src/Pilha/pilha.o 

C_DEPS += \
./src/Pilha/pilha.d 


# Each subdirectory must supply rules for building sources it contributes
src/Pilha/%.o: ../src/Pilha/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


