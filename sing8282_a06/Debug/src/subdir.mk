################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/common.c \
../src/expression.c \
../src/expression_ptest.c \
../src/queue.c \
../src/queue_ptest.c \
../src/stack.c \
../src/stack_ptest.c 

OBJS += \
./src/common.o \
./src/expression.o \
./src/expression_ptest.o \
./src/queue.o \
./src/queue_ptest.o \
./src/stack.o \
./src/stack_ptest.o 

C_DEPS += \
./src/common.d \
./src/expression.d \
./src/expression_ptest.d \
./src/queue.d \
./src/queue_ptest.d \
./src/stack.d \
./src/stack_ptest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


