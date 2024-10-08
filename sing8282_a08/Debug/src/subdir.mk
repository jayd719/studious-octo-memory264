################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/avl.c \
../src/avl_ptest.c \
../src/myrecord_avl.c \
../src/myrecord_avl_ptest.c 

C_DEPS += \
./src/avl.d \
./src/avl_ptest.d \
./src/myrecord_avl.d \
./src/myrecord_avl_ptest.d 

OBJS += \
./src/avl.o \
./src/avl_ptest.o \
./src/myrecord_avl.o \
./src/myrecord_avl_ptest.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/avl.d ./src/avl.o ./src/avl_ptest.d ./src/avl_ptest.o ./src/myrecord_avl.d ./src/myrecord_avl.o ./src/myrecord_avl_ptest.d ./src/myrecord_avl_ptest.o

.PHONY: clean-src

