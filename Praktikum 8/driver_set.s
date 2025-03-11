	.file	"driver_set.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Ya\0"
.LC1:
	.ascii "Tidak\0"
.LC2:
	.ascii "=== Testing Modul Set ===\0"
.LC3:
	.ascii "Set awal:\0"
.LC4:
	.ascii "Apakah kosong? %s\12\0"
	.align 8
.LC5:
	.ascii "\12Menambahkan elemen ke dalam set...\0"
	.align 8
.LC6:
	.ascii "Set setelah menambahkan elemen: \0"
.LC7:
	.ascii "%d \0"
	.align 8
.LC8:
	.ascii "\12Menambahkan elemen 20 (sudah ada)...\0"
	.align 8
.LC9:
	.ascii "Set setelah mencoba menambahkan elemen 20 lagi: \0"
	.align 8
.LC10:
	.ascii "\12Menghapus elemen 20 dari set...\0"
	.align 8
.LC11:
	.ascii "Set setelah menghapus elemen 20: \0"
.LC12:
	.ascii "\12Apakah 10 anggota set? %s\12\0"
.LC13:
	.ascii "Apakah 20 anggota set? %s\12\0"
.LC14:
	.ascii "\12Mengisi set hingga penuh...\0"
.LC15:
	.ascii "Apakah set penuh? %s\12\0"
	.align 8
.LC16:
	.ascii "\12Menambahkan elemen ke set yang sudah penuh...\0"
	.align 8
.LC17:
	.ascii "Set setelah mencoba menambahkan elemen baru ke set penuh: \0"
.LC18:
	.ascii "\12=== Selesai Testing ===\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
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
	subq	$872, %rsp
	.seh_stackalloc	872
	.seh_endprologue
	call	__main
	leaq	32(%rsp), %rdi
	leaq	32(%rsp), %rbp
	leaq	448(%rsp), %rbx
	movq	%rbx, %rcx
	movq	%rbx, %rsi
	call	CreateEmpty
	leaq	.LC2(%rip), %rcx
	call	puts
	leaq	.LC3(%rip), %rcx
	call	puts
	movl	$50, %ecx
	rep movsq
	movq	%rbp, %rcx
	movl	(%rsi), %eax
	movl	%eax, (%rdi)
	call	IsEmpty
	leaq	.LC1(%rip), %rdx
	leaq	.LC4(%rip), %rcx
	testb	%al, %al
	leaq	.LC0(%rip), %rax
	cmovne	%rax, %rdx
	call	__mingw_printf
	leaq	.LC5(%rip), %rcx
	call	puts
	movl	$10, %edx
	movq	%rbx, %rcx
	call	Insert
	movl	$20, %edx
	movq	%rbx, %rcx
	call	Insert
	movl	$30, %edx
	movq	%rbx, %rcx
	call	Insert
	leaq	.LC6(%rip), %rcx
	call	__mingw_printf
	movl	848(%rsp), %r8d
	testl	%r8d, %r8d
	jle	.L3
	xorl	%edi, %edi
	leaq	.LC7(%rip), %rsi
	.p2align 4
	.p2align 3
.L4:
	movl	(%rbx,%rdi,4), %edx
	movq	%rsi, %rcx
	addq	$1, %rdi
	call	__mingw_printf
	cmpl	%edi, 848(%rsp)
	jg	.L4
.L3:
	movl	$10, %ecx
	call	putchar
	leaq	.LC8(%rip), %rcx
	call	puts
	movl	$20, %edx
	movq	%rbx, %rcx
	call	Insert
	leaq	.LC9(%rip), %rcx
	call	__mingw_printf
	movl	848(%rsp), %ecx
	testl	%ecx, %ecx
	jle	.L5
	xorl	%edi, %edi
	leaq	.LC7(%rip), %rsi
	.p2align 4
	.p2align 3
.L6:
	movl	(%rbx,%rdi,4), %edx
	movq	%rsi, %rcx
	addq	$1, %rdi
	call	__mingw_printf
	cmpl	%edi, 848(%rsp)
	jg	.L6
.L5:
	movl	$10, %ecx
	call	putchar
	leaq	.LC10(%rip), %rcx
	call	puts
	movl	$20, %edx
	movq	%rbx, %rcx
	call	Delete
	leaq	.LC11(%rip), %rcx
	call	__mingw_printf
	movl	848(%rsp), %edx
	testl	%edx, %edx
	jle	.L7
	xorl	%edi, %edi
	leaq	.LC7(%rip), %rsi
	.p2align 4
	.p2align 3
.L8:
	movl	(%rbx,%rdi,4), %edx
	movq	%rsi, %rcx
	addq	$1, %rdi
	call	__mingw_printf
	cmpl	%edi, 848(%rsp)
	jg	.L8
.L7:
	movl	$10, %ecx
	movq	%rbp, %rdi
	movq	%rbx, %rsi
	call	putchar
	movl	$50, %ecx
	leaq	32(%rsp), %rbp
	movl	$10, %edx
	rep movsq
	movq	%rbp, %rcx
	leaq	.LC0(%rip), %r12
	movl	(%rsi), %eax
	movq	%rsi, %r13
	movq	%rbx, %rsi
	movl	%eax, (%rdi)
	movq	%rbp, %rdi
	call	IsMember
	leaq	.LC1(%rip), %rdx
	leaq	.LC12(%rip), %rcx
	testb	%al, %al
	cmovne	%r12, %rdx
	call	__mingw_printf
	movl	$50, %ecx
	movl	$20, %edx
	rep movsq
	movq	%rbp, %rcx
	movl	0(%r13), %eax
	movl	%eax, (%rdi)
	call	IsMember
	leaq	.LC1(%rip), %rdx
	leaq	.LC13(%rip), %rcx
	testb	%al, %al
	cmovne	%r12, %rdx
	call	__mingw_printf
	leaq	.LC14(%rip), %rcx
	call	puts
	movl	848(%rsp), %esi
	cmpl	$99, %esi
	jg	.L11
	.p2align 4
	.p2align 3
.L12:
	addl	$1, %esi
	movq	%rbx, %rcx
	movl	%esi, %edx
	call	Insert
	cmpl	$100, %esi
	jne	.L12
.L11:
	movl	$50, %ecx
	movq	%rbp, %rdi
	movq	%rbx, %rsi
	rep movsq
	leaq	32(%rsp), %rcx
	movl	(%rsi), %eax
	movl	%eax, (%rdi)
	call	IsFull
	leaq	.LC1(%rip), %rdx
	leaq	.LC15(%rip), %rcx
	testb	%al, %al
	leaq	.LC0(%rip), %rax
	cmovne	%rax, %rdx
	call	__mingw_printf
	leaq	.LC16(%rip), %rcx
	call	puts
	movl	$101, %edx
	movq	%rbx, %rcx
	call	Insert
	leaq	.LC17(%rip), %rcx
	call	__mingw_printf
	movl	848(%rsp), %eax
	testl	%eax, %eax
	jle	.L14
	xorl	%edi, %edi
	leaq	.LC7(%rip), %rsi
	.p2align 4
	.p2align 3
.L15:
	movl	(%rbx,%rdi,4), %edx
	movq	%rsi, %rcx
	addq	$1, %rdi
	call	__mingw_printf
	cmpl	%edi, 848(%rsp)
	jg	.L15
.L14:
	movl	$10, %ecx
	call	putchar
	leaq	.LC18(%rip), %rcx
	call	puts
	xorl	%eax, %eax
	addq	$872, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
	.def	CreateEmpty;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	IsEmpty;	.scl	2;	.type	32;	.endef
	.def	Insert;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	Delete;	.scl	2;	.type	32;	.endef
	.def	IsMember;	.scl	2;	.type	32;	.endef
	.def	IsFull;	.scl	2;	.type	32;	.endef
