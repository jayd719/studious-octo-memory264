################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/factorial.c \
../src/factorial_ptest.c \
../src/mychar.c \
../src/mychar_ptest.c \
../src/mymortgage.c \
../src/mymortgage_ptest.c 

OBJS += \
./src/factorial.o \
./src/factorial_ptest.o \
./src/mychar.o \
./src/mychar_ptest.o \
./src/mymortgage.o \
./src/mymortgage_ptest.o 

C_DEPS += \
./src/factorial.d \
./src/factorial_ptest.d \
./src/mychar.d \
./src/mychar_ptest.d \
./src/mymortgage.d \
./src/mymortgage_ptest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


