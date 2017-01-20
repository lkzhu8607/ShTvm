
#ifndef PUBLIC_H
#define PUBLIC_H


#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include "define.h"

#define LOG_LEVEL_MUST 		0
#define	LOG_LEVEL_FAILURE	0	
#define	LOG_LEVEL_ERROR		1	
#define	LOG_LEVEL_WARNING	2	
#define	LOG_LEVEL_NOTICE	3	
#define	LOG_LEVEL_DEBUG		4	


#define STR(s) # s
#define DEBUGHEAD(file, line) file":" STR(line) "> "
struct timespec diff(struct timespec start,struct timespec end,struct timespec *time_transfer);

xx1_s32 init_log(xx1_s32 log_level, xx1_s32 debug_level, const xx1_s8 *proc_name, const xx1_s8 *log_dir, xx1_s32 daemonid);
xx1_s32 init_log_thread(const xx1_s8* thread_name);
void xx1_log_debug(xx1_s32 level, const xx1_s8* fmt,...);

xx1_s32 ini_read_string (const xx1_s8 *config_filename, const xx1_s8 *key, xx1_s8 *value, size_t size);
xx1_s32 ini_read_int (const xx1_s8 *config_filename, const xx1_s8 *key, xx1_s32 *value);

xx1_s32 start_daemon (const xx1_s8 *work_dir, const xx1_s8 *proc_name);


xx1_s32 check_process (const xx1_s8 *work_dir, const xx1_s8 *proc_name);

xx1_u64 get_pre_cost_time(xx1_s32 ciphertext_num, xx1_u64 task_pwd_count, const xx1_s8 *system_capability, xx1_s32 crack_type);

typedef xx1_s32 (*free_data_func)(void *item);
typedef struct tag_data_queue
{
	void **buffer;                  
	xx1_u32 head;                            
	xx1_u32 tail;                            
	xx1_u32 count;                           
	xx1_u32 size;                            
	pthread_mutex_t mutex;  
	
	pthread_cond_t cond;   
	sem_t semaphore;
	free_data_func free_func;               
	xx1_s8 queue_name[XX1_BUF_LEN_TINY];              
	xx1_s32 value;                   
} data_queue_t;   

#define  READ_DATE_DIR 0
#define  READ_AUTH_DIR 1
#define READ_NO_AUTH_DIR 2

xx1_s32 init_queue (data_queue_t *queue, xx1_s32 size , xx1_s32 buffer_item_size, const xx1_s8 *queue_name, free_data_func func);
void add_to_queue ( data_queue_t *queue, void * data );
void *search_from_queue ( data_queue_t *queue , 	xx1_s8  *task_id );

void *get_from_queue ( data_queue_t *queue );
void free_queue ( data_queue_t *queue );

#endif

