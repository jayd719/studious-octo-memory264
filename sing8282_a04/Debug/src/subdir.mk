################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/myrecord.c \
../src/myrecord_ptest.c \
../src/mysort.c \
../src/mysort_ptest.c \
../src/test.c 

C_DEPS += \
./src/myrecord.d \
./src/myrecord_ptest.d \
./src/mysort.d \
./src/mysort_ptest.d \
./src/test.d 

OBJS += \
./src/myrecord.o \
./src/myrecord_ptest.o \
./src/mysort.o \
./src/mysort_ptest.o \
./src/test.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/myrecord.d ./src/myrecord.o ./src/myrecord_ptest.d ./src/myrecord_ptest.o ./src/mysort.d ./src/mysort.o ./src/mysort_ptest.d ./src/mysort_ptest.o ./src/test.d ./src/test.o

.PHONY: clean-src

