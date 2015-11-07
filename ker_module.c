/*
*kernel module v1.0
*
*used to write parameter,show all process,or search process parent and child by id
*
*@author LG Liu
*@link http://github.com/ktvexe/kernel_module 
*/
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

#define for_each_children(pos,head) \
list_for_each_entry(pos, &(head -> children), sibling)


/*variable of parameter*/
static char *command = "none";
static int  pid = -1;
module_param(command, charp,S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(command,"characte string");
module_param(pid, int,S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(pid,"integer");

/*task struct pointer to do process search*/
struct task_struct *task;

static int ker_proc_show(struct seq_file *m, void *v) {
	/*case of showing all process*/
	if(!strcmp(command,"showall")){
    	/*run the task pointer for each one and print to file*/
		for_each_process(task){
	    	seq_printf(m,"%-20s pid:[%d]\n", task->comm, task->pid);
	    	seq_printf(m,"		parent: %-20s pid:[%d]\n", task->parent->comm, task->parent->pid);
			
		}
	}
	/*case of search parent and child by pid*/
	else if(!strcmp(command,"parentchild")){
		struct task_struct  *task2;
		bool flag =false;
		if(pid < 0){
			seq_printf(m,"incorrect pid:%d\n",pid);
			return -1;
		}
		/*run the task pointer to search process*/
		for_each_process(task) {
        	if ( task->pid == pid ){
				seq_printf(m,"Current:\n");
				seq_printf(m,"		%-20s  pid:[%d]\n",task->comm,task->pid);
				seq_printf(m,"Parent:\n");
				seq_printf(m,"		%-20s  pid:[%d]\n",task->parent->comm,task->parent->pid);
				seq_printf(m,"Child:\n");
				for_each_children( task2 , task ){
					seq_printf(m,"		%-20s (pid:%d)\n", task2->comm, task2->pid);
				}
        		flag=true;
			}
		}
		if(!flag){
			seq_printf(m,"pid:%d does not exist!!\n",pid);
		}
	}
	/*case of print arrgument to file*/
	else{
		seq_printf(m, "%s\n",command);
	}

	return 0;
}



/*open file*/
static int ker_proc_open(struct inode *inode, struct  file *file) {
	return single_open(file, ker_proc_show, NULL);
}

/*by proc_create*/
static const struct file_operations ker_proc_fops = {
	.owner = THIS_MODULE,
	.open = ker_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};



/*called when insmod */
static int __init ker_proc_init(void) {
  /*file name:ker_proc
  	mode	 :0
	parent	 :NULL
	proc_fops:setting operation
  */
  proc_create("ker_proc", 0, NULL, &ker_proc_fops);
  return 0;
}

/*called when rmmod */
static void __exit ker_proc_exit(void) {
  remove_proc_entry("ker_proc", NULL);
}

/*GNU General Public License*/
MODULE_LICENSE("GPL");

module_init(ker_proc_init);
module_exit(ker_proc_exit);
