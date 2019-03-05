#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>

static LIST_HEAD(birthday_list);

struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;
};

int birthday_list_init(void)
{
	struct birthday *person;     
	for(i = 0; i < 5 ;i++) {  
	
		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->day = 2+i;
		person->month = 8 + i;
		person->year = 1995 + i;
		
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &birthday_list);
	}

	printk(KERN_INFO "Loading Module\n");
	printk(KERN_INFO "The list has been created\n");
	
	list_for_each_entry(person, &birthday_list, list) {
		printk(KERN_INFO "Day: %d Month: %d Year: %d\n", person->day, person->month, person->year);
	}

	return 0;
}

void birthday_list_exit(void)
{
	struct birthday *person, *next;
	
	list_for_each_entry_safe(person, next, &birthday_list, list) {
		printk(KERN_INFO "Deleting node\n");
		list_del(&person->list);
		kfree(person);
	}
	printk(KERN_INFO "delete success\n");
	printk(KERN_INFO "Removing Module\n");
}

module init(birthday_list_init);
module exit(birthday_list_exit);

MODULE LICENSE("GPL");
MODULE DESCRIPTION("Kernel Data Structures");
MODULE AUTHOR("Hassan Kandil");