################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fibonacci.c \
../src/fibonacci_ptest.c \
../src/matrix.c \
../src/matrix_ptest.c \
../src/polynomial.c \
../src/polynomial_ptest.c 

OBJS += \
./src/fibonacci.o \
./src/fibonacci_ptest.o \
./src/matrix.o \
./src/matrix_ptest.o \
./src/polynomial.o \
./src/polynomial_ptest.o 

C_DEPS += \
./src/fibonacci.d \
./src/fibonacci_ptest.d \
./src/matrix.d \
./src/matrix_ptest.d \
./src/polynomial.d \
./src/polynomial_ptest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


