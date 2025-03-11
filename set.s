	.file	"set.c"
	.text
	.p2align 4
	.globl	CreateEmpty
	.def	CreateEmpty;	.scl	2;	.type	32;	.endef
	.seh_proc	CreateEmpty
CreateEmpty:
	.seh_endprologue
	movl	$0, 400(%rcx)
	ret
	.seh_endproc
	.p2align 4
	.globl	IsEmpty
	.def	IsEmpty;	.scl	2;	.type	32;	.endef
	.seh_proc	IsEmpty
IsEmpty:
	.seh_endprologue
	movl	400(%rcx), %eax
	testl	%eax, %eax
	sete	%al
	ret
	.seh_endproc
	.p2align 4
	.globl	IsFull
	.def	IsFull;	.scl	2;	.type	32;	.endef
	.seh_proc	IsFull
IsFull:
	.seh_endprologue
	cmpl	$100, 400(%rcx)
	sete	%al
	ret
	.seh_endproc
	.p2align 4
	.globl	Insert
	.def	Insert;	.scl	2;	.type	32;	.endef
	.seh_proc	Insert
Insert:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	subq	$424, %rsp
	.seh_stackalloc	424
	.seh_endprologue
	movq	%rcx, %r8
	movq	%rsp, %rdi
	movl	$50, %ecx
	movq	%rsp, %rax
	movq	%r8, %rsi
	rep movsq
	movl	(%rsi), %ecx
	movl	%ecx, (%rdi)
	movl	400(%r8), %ecx
	movslq	%ecx, %r9
	testl	%ecx, %ecx
	jle	.L9
	movslq	%ecx, %r9
	movq	%rsp, %rdi
	leaq	(%rax,%r9,4), %rax
	jmp	.L8
	.p2align 4
	.p2align 4,,10
	.p2align 3
.L15:
	addq	$4, %rdi
	cmpq	%rax, %rdi
	je	.L14
.L8:
	cmpl	(%rdi), %edx
	jne	.L15
.L5:
	addq	$424, %rsp
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
	.p2align 3
.L14:
	cmpl	$100, %ecx
	je	.L5
.L9:
	addl	$1, %ecx
	movl	%edx, (%r8,%r9,4)
	movl	%ecx, 400(%r8)
	addq	$424, %rsp
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.p2align 4
	.globl	Delete
	.def	Delete;	.scl	2;	.type	32;	.endef
	.seh_proc	Delete
Delete:
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
	subq	$448, %rsp
	.seh_stackalloc	448
	.seh_endprologue
	movq	%rcx, %r12
	leaq	32(%rsp), %rax
	movl	$50, %ecx
	movl	%edx, %ebx
	movq	%rax, %rdi
	movq	%r12, %rsi
	rep movsq
	movl	(%rsi), %edx
	movl	%edx, (%rdi)
	movl	400(%r12), %edx
	testl	%edx, %edx
	jle	.L16
	movq	%rax, %rdi
	movslq	%edx, %rax
	leaq	(%rdi,%rax,4), %rax
	jmp	.L19
	.p2align 4
	.p2align 4,,10
	.p2align 3
.L30:
	addq	$4, %rdi
	cmpq	%rax, %rdi
	je	.L16
.L19:
	cmpl	(%rdi), %ebx
	jne	.L30
	movq	%r12, %rcx
	xorl	%ebp, %ebp
	jmp	.L26
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L31:
	movl	400(%r12), %edx
	leaq	4(%rcx), %rsi
	addl	$1, %ebp
	movq	%rsi, %rcx
	cmpl	%edx, %ebp
	jge	.L16
.L26:
	cmpl	%ebx, (%rcx)
	jne	.L31
	leal	-1(%rdx), %edi
	cmpl	%ebp, %edx
	jle	.L32
	movl	%edi, %eax
	leaq	4(%rcx), %rsi
	subl	%ebp, %eax
	movq	%rsi, %rdx
	leaq	4(,%rax,4), %r8
	call	memmove
.L25:
	movl	%edi, %edx
	addl	$1, %ebp
	movl	%edi, 400(%r12)
	movq	%rsi, %rcx
	cmpl	%edx, %ebp
	jl	.L26
.L16:
	addq	$448, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
.L32:
	leaq	4(%rcx), %rsi
	jmp	.L25
	.seh_endproc
	.p2align 4
	.globl	IsMember
	.def	IsMember;	.scl	2;	.type	32;	.endef
	.seh_proc	IsMember
IsMember:
	.seh_endprologue
	movslq	400(%rcx), %rax
	testl	%eax, %eax
	jle	.L36
	leaq	(%rcx,%rax,4), %rax
	jmp	.L35
	.p2align 4
	.p2align 4,,10
	.p2align 3
.L39:
	addq	$4, %rcx
	cmpq	%rax, %rcx
	je	.L36
.L35:
	cmpl	%edx, (%rcx)
	jne	.L39
	movl	$1, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L36:
	xorl	%eax, %eax
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
	.def	memmove;	.scl	2;	.type	32;	.endef
