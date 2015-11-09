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
	{ 0x1fc32c62, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x5d41c87c, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xb6b46a7c, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x46adf3d, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x9ca10237, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x6916acf6, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x12d54a2b, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xa877ee10, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0xa05f372e, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x5fddd203, __VMLINUX_SYMBOL_STR(init_task) },
	{ 0x5ccc8e71, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "A29A7A06A43D88D87CB4362");
