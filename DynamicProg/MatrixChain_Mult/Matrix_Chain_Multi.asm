	.file	"Matrix_Chain_Multi.c"
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Input the number of matrices you got!\0"
LC1:
	.ascii "%d\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$0, 24(%esp)
	movl	$0, 28(%esp)
	movl	$LC0, (%esp)
	call	_puts
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	24(%esp), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	call	_input
	movl	%eax, 28(%esp)
	movl	24(%esp), %eax
	leal	1(%eax), %edx
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_MCM
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, 28(%esp)
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "Minimised Operations Cost is :%d\12\0"
	.text
	.globl	_MCM
	.def	_MCM;	.scl	2;	.type	32;	.endef
_MCM:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$0, -12(%ebp)
	movl	$0, -28(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
	movl	$0, -24(%ebp)
	movl	$0, -32(%ebp)
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -36(%ebp)
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -40(%ebp)
	movl	$0, -12(%ebp)
	jmp	L4
L5:
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	-12(%ebp), %edx
	leal	0(,%edx,4), %ecx
	movl	-36(%ebp), %edx
	leal	(%ecx,%edx), %ebx
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	-12(%ebp), %edx
	leal	0(,%edx,4), %ecx
	movl	-40(%ebp), %edx
	leal	(%ecx,%edx), %ebx
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
L4:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	L5
	movl	$0, -12(%ebp)
	jmp	L6
L7:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	$0, (%eax)
	addl	$1, -12(%ebp)
L6:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	L7
	movl	$1, -16(%ebp)
	jmp	L8
L14:
	movl	$1, -12(%ebp)
	jmp	L9
L13:
	movl	-12(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -28(%ebp)
	movl	$2147483647, -24(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	L10
L12:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-20(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	addl	$1, %eax
	leal	0(,%eax,4), %ecx
	movl	-36(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	movl	(%eax), %eax
	leal	(%edx,%eax), %ecx
	movl	-12(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %ebx
	movl	12(%ebp), %eax
	addl	%ebx, %eax
	movl	(%eax), %eax
	imull	%eax, %edx
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %ebx
	movl	12(%ebp), %eax
	addl	%ebx, %eax
	movl	(%eax), %eax
	imull	%edx, %eax
	addl	%ecx, %eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jge	L11
	movl	-32(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	%eax, (%edx)
L11:
	addl	$1, -20(%ebp)
L10:
	movl	-28(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jg	L12
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	%eax, (%edx)
	addl	$1, -12(%ebp)
L9:
	movl	8(%ebp), %eax
	subl	-16(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jl	L13
	addl	$1, -16(%ebp)
L8:
	movl	8(%ebp), %eax
	subl	$1, %eax
	cmpl	%eax, -16(%ebp)
	jl	L14
	movl	-36(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$1073741823, %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_PRINT_OPTIMAL_PARENS
	movl	$0, -12(%ebp)
	jmp	L15
L16:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movl	$0, (%eax)
	addl	$1, -12(%ebp)
L15:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	L16
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, -36(%ebp)
	movl	$0, -40(%ebp)
	nop
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.section .rdata,"dr"
LC3:
	.ascii "A%d\0"
	.text
	.globl	_PRINT_OPTIMAL_PARENS
	.def	_PRINT_OPTIMAL_PARENS;	.scl	2;	.type	32;	.endef
_PRINT_OPTIMAL_PARENS:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jne	L18
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	jmp	L20
L18:
	movl	$40, (%esp)
	call	_putchar
	movl	12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_PRINT_OPTIMAL_PARENS
	movl	12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_PRINT_OPTIMAL_PARENS
	movl	$41, (%esp)
	call	_putchar
L20:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.section .rdata,"dr"
	.align 4
LC4:
	.ascii "Input the dimensions one by one!\0"
	.text
	.globl	_input
	.def	_input;	.scl	2;	.type	32;	.endef
_input:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -16(%ebp)
	movl	$LC4, (%esp)
	call	_puts
	movl	$0, -12(%ebp)
	jmp	L22
L23:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	addl	$1, -12(%ebp)
L22:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	L23
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.ident	"GCC: (MinGW.org GCC-8.2.0-3) 8.2.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
