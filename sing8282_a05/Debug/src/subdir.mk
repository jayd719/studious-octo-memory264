################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bigint.c \
../src/bigint_ptest.c \
../src/dllist.c \
../src/dllist_ptest.c \
../src/myrecord_sllist.c \
../src/myrecord_sllist_ptest.c 

OBJS += \
./src/bigint.o \
./src/bigint_ptest.o \
./src/dllist.o \
./src/dllist_ptest.o \
./src/myrecord_sllist.o \
./src/myrecord_sllist_ptest.o 

C_DEPS += \
./src/bigint.d \
./src/bigint_ptest.d \
./src/dllist.d \
./src/dllist_ptest.d \
./src/myrecord_sllist.d \
./src/myrecord_sllist_ptest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


