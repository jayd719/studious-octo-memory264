################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/data.c \
../src/main.c \
../src/queue_linked.c \
../src/stack_linked.c 

OBJS += \
./src/data.o \
./src/main.o \
./src/queue_linked.o \
./src/stack_linked.o 

C_DEPS += \
./src/data.d \
./src/main.d \
./src/queue_linked.d \
./src/stack_linked.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


