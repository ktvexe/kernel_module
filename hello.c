#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

#define for_each_children(pos,head) \
list_for_each_entry(pos, &(head -> children), sibling)
#define for_each_sibling(pos,head) \
for_each_children(pos, (head->parent) )
static char *command = "none";
static int  pid = -1;
module_param(command, charp,S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(command,"characte string");
module_param(pid, int,S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(pid,"integer");
struct task_struct *task;

static int hello_proc_show(struct seq_file *m, void *v) {
	if(!strcmp(command,"showall")){
    	for_each_process(task){
	    	seq_printf(m,"%s pid:[%6d]\n", task->comm, task->pid);
	    	seq_printf(m,"		parent: %s pid:[%6d]\n", task->parent->comm, task->parent->pid);
			
		}
	}

	else if(!strcmp(command,"parentchild")){
		struct task_struct  *task2;
		if(pid < 0){
			printk("incorrect pid\n");
			return -1;
		}
		for_each_process(task) {
        	if ( task->pid == pid ){
				seq_printf(m,"Current:\n");
				seq_printf(m,"		%s  pid:[%6d]\n",task->comm,task->pid);
				seq_printf(m,"Parent:\n");
				seq_printf(m,"		%s  pid:[%6d]\n",task->parent->comm,task->parent->pid);
			
				seq_printf(m,"Child:\n");
				for_each_children( task2 , task ){
					seq_printf(m,"		%s (pid:%6d)\n", task2->comm, task2->pid);
				}
        	}
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
