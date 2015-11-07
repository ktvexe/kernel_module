#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static char *command = "none";
module_param(command, charp,S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(command,"characte string");

static int hello_proc_show(struct seq_file *m, void *v) {
	if(!strcmp(command,"showall")){
		struct task_struct *task;
    	for_each_process(task){
	    	seq_printf(m,"%s [%d]\n", task->comm, task->pid);
		}
	}
	else{
		seq_printf(m, "%s\n",command);
	}
	return 0;
}

static int hello_proc_open(struct inode *inode, struct  file *file) {
	return single_open(file, hello_proc_show, NULL);
}

static const struct file_operations hello_proc_fops = {
	.owner = THIS_MODULE,
	.open = hello_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};




static int __init hello_proc_init(void) {
  proc_create("hello_proc", 0, NULL, &hello_proc_fops);
  return 0;
}

static void __exit hello_proc_exit(void) {
  remove_proc_entry("hello_proc", NULL);
}

MODULE_LICENSE("GPL");
module_init(hello_proc_init);
module_exit(hello_proc_exit);
