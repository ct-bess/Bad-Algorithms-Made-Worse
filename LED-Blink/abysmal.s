.data
pin: .int 18 
delay_time: .int 1
output: .int 1
GPIO_BASE: .long 0x3F200000
FUN_SEL_OFFSET: .int 0x0
SET_OFFSET: .int 0x1C
CLEAR_OFFSET: .int 0x28
fileName: .asciz "/dev/mem"
MAP_SHARED: .int 1
MAP_FAILED: .word -1
PROT_READ: .int 1
PROT_WRITE: .int 2
O_RDWR: .int 2
openFailed: .asciz "open() failed\n"
mapFailed: .asciz "mmap() failed\n"

.text
.global main
.extern open
.extern close
.extern mmap
.extern fprintf
.extern sleep
.extern printf

@r0%r1
modulus:
	push {lr}
	udiv r2, r0, r1
	mls r0, r1, r2, r0
	pop {pc}

@r0 is gpioBase, r1 is pin, r2 is mode 
setPinMode:
	push {r4-r7, lr}
	ldr r3, =FUN_SEL_OFFSET
	ldr r3, [r3] 
	add r4, r0, r3 @r4= gpioBase + FUN_SEL_OFFSET (ie gpioFunSel)
	mov r5, #10
	udiv r6, r1, r5 @r6=pin/10 (ie funSelIndex)
	mov r7, r2 @r7 = mode
	mov r0, r1
	mov r1, r5
	bl modulus @r0 = pin%10
	mov r1, #3
	mul r0, r1, r0 @r0=3*(pin%10) (ie funSelShift)
	ldr r1, [r4, r6, lsl #2] @r1=gpioFunSel[funSelIndex]
	orr r1, r1, r7, lsl r0 @r1= gpioFunSel[funSelIndex] | (mode<<funSelShift)
	str r1, [r4, r6, lsl #2] @write data back to register
	pop {r4-r7, pc}

@r0 is gpioBase, r1 is pin
setPinOn:
	push {r4-r5, lr}
	mov r4, r0
	mov r0, r1
	mov r1, #32
	udiv r5, r0, r1 @r3=pin/32 (ie gpioSCIndex)
	bl modulus @r0 = pin%32 (ie gpioSCShift)
	ldr r2, =SET_OFFSET
	ldr r2, [r2]
	add r4, r4, r2 @add SET_OFFSET to gpioBase
	mov r1, #1
	lsl r2, r1, r0 @r2= (1<<gpioSCShift)
	str r2, [r4, r5, lsl #2] @store the value back in the register
	pop {r4-r5, pc}

@r0 is gpioBase, r1 is pin
setPinOff:
	push {r4-r5, lr}
	mov r4, r0
	mov r0, r1
	mov r1, #32
	udiv r5, r0, r1 @r3=pin/32 (ie gpioSCIndex)
	bl modulus @r0 = pin%32 (ie gpioSCShift)
	ldr r2, =CLEAR_OFFSET
	ldr r2, [r2]
	add r4, r4, r2 @add CLEAR_OFFSET to gpioBase
	mov r1, #1
	lsl r2, r1, r0 @r2= (1<<gpioSCShift)
	str r2, [r4, r5, lsl #2] @store the value back in the register
	pop {r4-r5, pc}

main:
	push {ip, lr} @stores information needed when the program exits
	ldr r1, =O_RDWR
	ldr r1, [r1]
	ldr r0, =fileName
	bl open
	mov r11, r0 @save the file discriptor
	subs r0, r0, #-1 @will set flags based on the subtraction
	beq openError @if r0 == -1 go to openError
	sub sp, sp, #8
	ldr r0, =GPIO_BASE
	ldr r0, [r0]
	str r0, [sp, #4]
	str r11, [sp]
	ldr r3, =MAP_SHARED
	ldr r3, [r3]
	ldr r2, =PROT_READ
	ldr r2, [r2]
	ldr r0, =PROT_WRITE
	ldr r0, [r0]
	orr r2, r2, r0
	mov r1, #4096
	mov r0, #0
	bl mmap
	add sp, sp, #8
	ldr r1, =MAP_FAILED
	ldr r1, [r1]
	subs r1, r0, r1 @will set flags based on the subtraction
	beq mapError @if r0 == MAP_FAILED go to mapError
	mov r10, r0 @keep gpioBase
	ldr r1, =pin @loads addr of pin into r0
	ldr r1, [r1] @loads value at addr stored in r0 (pin) into r0
	ldr r2, =output
	ldr r2, [r2]
	bl setPinMode @calls setPinMode
	mov r4, #0
loopStart:
	subs r5, r4, #10
	bge exit0 @if r4 >= 10 end the loop
	mov r0, r10
	ldr r1, =pin
	ldr r1, [r1]
	bl setPinOn @turns pin on (with 3 prev lines too)
	ldr r0, =delay_time
	ldr r0, [r0]
	bl sleep @waits a bit
	mov r0, r10
	ldr r1, =pin
	ldr r1, [r1]
	bl setPinOff @turns the pin off
	ldr r0, =delay_time
	ldr r0, [r0]
	bl sleep @waits a bit
	add r4, r4, #1 @increment by 1
	b loopStart
exit0:
	mov r0, r11
	bl close
	mov r0, #0 @puts 0 as the return value
	pop {ip, pc}

openError:
	ldr r0, =openFailed
	bl printf
	mov r0, #1 @puts 1 as the return value
	pop {ip, pc}

mapError:
	mov r0, r11
	bl close
	ldr r0, =mapFailed
	bl printf
	mov r0, #1 @puts 1 as the return value
	pop {ip, pc}
