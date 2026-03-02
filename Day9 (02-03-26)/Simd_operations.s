	.file	"Simd_operations.cpp"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Enter a len of N: \0"
.LC1:
	.ascii "Enter a A[\0"
.LC2:
	.ascii "]: \0"
.LC3:
	.ascii "Enter a B[\0"
.LC4:
	.ascii "Sum: \0"
.LC5:
	.ascii "\12Sub: \0"
.LC6:
	.ascii " \0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB9857:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt4cout(%rip), %rbx
	movl	$18, %r8d
	leaq	.LC0(%rip), %rdx
	movl	$0, 44(%rsp)
	movq	%rbx, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	.refptr._ZSt3cin(%rip), %r14
	leaq	44(%rsp), %rdx
	movq	%r14, %rcx
	call	_ZNSirsERi
	movslq	44(%rsp), %rsi
	movabsq	$2305843009213693950, %rax
	cmpq	%rsi, %rax
	jb	.L2
	leaq	0(,%rsi,4), %rcx
	call	_Znay
	leaq	0(,%rsi,4), %rcx
	movq	%rax, %r13
	call	_Znay
	leaq	0(,%rsi,4), %rcx
	movq	%rax, %r12
	call	_Znay
	leaq	0(,%rsi,4), %rcx
	movq	%rax, %rbp
	call	_Znay
	movq	%rax, %rdi
	testl	%esi, %esi
	je	.L12
	movq	%r13, %r15
	xorl	%esi, %esi
	.p2align 4
	.p2align 3
.L5:
	movl	$10, %r8d
	leaq	.LC1(%rip), %rdx
	movq	%rbx, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	%esi, %edx
	movq	%rbx, %rcx
	addl	$1, %esi
	call	_ZNSolsEi
	movl	$3, %r8d
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	%r15, %rdx
	movq	%r14, %rcx
	addq	$4, %r15
	call	_ZNSirsERi
	movl	44(%rsp), %eax
	cmpl	%esi, %eax
	jg	.L5
	testl	%eax, %eax
	jle	.L12
	movq	%r12, %r15
	xorl	%esi, %esi
	.p2align 4
	.p2align 3
.L6:
	movl	$10, %r8d
	leaq	.LC3(%rip), %rdx
	movq	%rbx, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	%esi, %edx
	movq	%rbx, %rcx
	addl	$1, %esi
	call	_ZNSolsEi
	movl	$3, %r8d
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	%r15, %rdx
	movq	%r14, %rcx
	addq	$4, %r15
	call	_ZNSirsERi
	movl	44(%rsp), %edx
	cmpl	%esi, %edx
	jg	.L6
	leal	-8(%rdx), %ecx
	cmpl	$8, %edx
	jle	.L20
	movl	%ecx, %r8d
	xorl	%eax, %eax
	.p2align 6
	.p2align 4
	.p2align 3
.L11:
	vmovdqu	0(%r13,%rax,4), %ymm0
	vmovdqu	(%r12,%rax,4), %ymm1
	vpaddd	%ymm0, %ymm1, %ymm2
	vpsubd	%ymm1, %ymm0, %ymm0
	vmovdqu	%ymm2, 0(%rbp,%rax,4)
	vmovdqu	%ymm0, (%rdi,%rax,4)
	addq	$1, %rax
	cmpq	%rax, %r8
	jne	.L11
.L10:
	cmpl	%ecx, %edx
	jle	.L42
	movl	%edx, %eax
	subl	%ecx, %eax
	leal	-1(%rax), %r8d
	cmpl	$6, %r8d
	jbe	.L21
	movslq	%ecx, %r8
	vmovdqu	0(%r13,%r8,4), %ymm0
	vmovdqu	(%r12,%r8,4), %ymm1
	vpaddd	%ymm0, %ymm1, %ymm2
	vpsubd	%ymm1, %ymm0, %ymm0
	vmovdqu	%ymm2, 0(%rbp,%r8,4)
	vmovdqu	%ymm0, (%rdi,%r8,4)
	testb	$7, %al
	je	.L42
	movl	%eax, %r8d
	andl	$-8, %r8d
	leal	(%r8,%rcx), %r9d
.L13:
	subl	%r8d, %eax
	leal	-1(%rax), %r10d
	cmpl	$2, %r10d
	jbe	.L15
	movslq	%ecx, %rcx
	addq	%r8, %rcx
	vmovdqu	0(%r13,%rcx,4), %xmm0
	vmovdqu	(%r12,%rcx,4), %xmm1
	vpaddd	%xmm1, %xmm0, %xmm2
	vpsubd	%xmm1, %xmm0, %xmm0
	vmovdqu	%xmm2, 0(%rbp,%rcx,4)
	vmovdqu	%xmm0, (%rdi,%rcx,4)
	testb	$3, %al
	je	.L42
	andl	$-4, %eax
	addl	%eax, %r9d
.L15:
	movslq	%r9d, %rax
	movl	0(%r13,%rax,4), %ecx
	movl	(%r12,%rax,4), %r8d
	leal	(%rcx,%r8), %r10d
	subl	%r8d, %ecx
	movl	%ecx, (%rdi,%rax,4)
	leal	1(%r9), %ecx
	movl	%r10d, 0(%rbp,%rax,4)
	cmpl	%ecx, %edx
	jle	.L42
	movl	4(%r13,%rax,4), %ecx
	movl	4(%r12,%rax,4), %r8d
	addl	$2, %r9d
	leal	(%r8,%rcx), %r10d
	subl	%r8d, %ecx
	movl	%r10d, 4(%rbp,%rax,4)
	movl	%ecx, 4(%rdi,%rax,4)
	cmpl	%r9d, %edx
	jle	.L42
	movl	8(%r13,%rax,4), %edx
	movl	8(%r12,%rax,4), %ecx
	leal	(%rdx,%rcx), %r8d
	subl	%ecx, %edx
	movl	%r8d, 8(%rbp,%rax,4)
	movl	%edx, 8(%rdi,%rax,4)
	vzeroupper
	jmp	.L12
.L42:
	vzeroupper
.L12:
	leaq	.LC4(%rip), %rdx
	movl	$5, %r8d
	movq	%rbx, %rcx
	xorl	%esi, %esi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	44(%rsp), %edx
	leaq	.LC6(%rip), %r12
	testl	%edx, %edx
	jle	.L9
	.p2align 4
	.p2align 3
.L8:
	movl	0(%rbp,%rsi,4), %edx
	movq	%rbx, %rcx
	addq	$1, %rsi
	call	_ZNSolsEi
	movl	$1, %r8d
	movq	%r12, %rdx
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	cmpl	%esi, 44(%rsp)
	jg	.L8
.L9:
	movl	$6, %r8d
	leaq	.LC5(%rip), %rdx
	movq	%rbx, %rcx
	xorl	%esi, %esi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	44(%rsp), %eax
	leaq	.LC6(%rip), %r12
	testl	%eax, %eax
	jle	.L37
	.p2align 4
	.p2align 3
.L17:
	movl	(%rdi,%rsi,4), %edx
	movq	%rbx, %rcx
	addq	$1, %rsi
	call	_ZNSolsEi
	movl	$1, %r8d
	movq	%r12, %rdx
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	cmpl	%esi, 44(%rsp)
	jg	.L17
.L37:
	xorl	%eax, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L21:
	movl	%ecx, %r9d
	xorl	%r8d, %r8d
	jmp	.L13
.L20:
	xorl	%ecx, %ecx
	jmp	.L10
.L2:
	call	__cxa_throw_bad_array_new_length
	nop
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev11, Built by MSYS2 project) 15.2.0"
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_Znay;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__cxa_throw_bad_array_new_length;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
