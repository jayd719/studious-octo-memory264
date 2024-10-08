################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/A7-finalPractice.c \
../src/bst.c \
../src/queue_stack.c \
../src/tree.c 

C_DEPS += \
./src/A7-finalPractice.d \
./src/bst.d \
./src/queue_stack.d \
./src/tree.d 

OBJS += \
./src/A7-finalPractice.o \
./src/bst.o \
./src/queue_stack.o \
./src/tree.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/A7-finalPractice.d ./src/A7-finalPractice.o ./src/bst.d ./src/bst.o ./src/queue_stack.d ./src/queue_stack.o ./src/tree.d ./src/tree.o

.PHONY: clean-src

