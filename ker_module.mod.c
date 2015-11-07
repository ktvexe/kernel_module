#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x44abaccb, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x5d41c87c, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xb6b46a7c, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x85c3f5b9, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x2c5f651d, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0xfec50a8d, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x8f5295ee, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xec510803, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x6042549c, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x933d2f1a, __VMLINUX_SYMBOL_STR(init_task) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x887680f1, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "8984318DE12C1A9910BCC69");
