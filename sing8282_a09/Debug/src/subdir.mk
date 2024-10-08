################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/common_queue_stack.c \
../src/expression_symbol.c \
../src/expression_symbol_ptest.c \
../src/hash.c \
../src/hash_ptest.c \
../src/heap.c \
../src/heap_ptest.c 

C_DEPS += \
./src/common_queue_stack.d \
./src/expression_symbol.d \
./src/expression_symbol_ptest.d \
./src/hash.d \
./src/hash_ptest.d \
./src/heap.d \
./src/heap_ptest.d 

OBJS += \
./src/common_queue_stack.o \
./src/expression_symbol.o \
./src/expression_symbol_ptest.o \
./src/hash.o \
./src/hash_ptest.o \
./src/heap.o \
./src/heap_ptest.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/common_queue_stack.d ./src/common_queue_stack.o ./src/expression_symbol.d ./src/expression_symbol.o ./src/expression_symbol_ptest.d ./src/expression_symbol_ptest.o ./src/hash.d ./src/hash.o ./src/hash_ptest.d ./src/hash_ptest.o ./src/heap.d ./src/heap.o ./src/heap_ptest.d ./src/heap_ptest.o

.PHONY: clean-src

