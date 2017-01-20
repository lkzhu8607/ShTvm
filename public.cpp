#include <sys/time.h>
#include "public.h"

#include <stdio.h>
#include <pthread.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>

static pthread_key_t g_thread_key;
static xx1_s16 g_log_level = 0;
static xx1_s16 g_debug_level = 0;
static xx1_s8 *g_proc_name = NULL;
static xx1_s32 g_process_num = 0;
static xx1_s8 *g_log_dir = NULL;

extern xx1_s32 abnormal_ocean_task_end;


struct timespec diff(struct timespec start,struct timespec end,struct timespec *time_transfer)
{
	struct timespec temp;
	if(end.tv_nsec-start.tv_nsec <0)
	{
		temp.tv_sec=end.tv_sec-start.tv_sec-1;
		temp.tv_nsec=1000000000+end.tv_nsec-start.tv_nsec;
		
	}
	else
	{
		temp.tv_sec=end.tv_sec-start.tv_sec;
		temp.tv_nsec=end.tv_nsec-start.tv_nsec;
	}
	*time_transfer=temp;
}

void in_free_log( void );
void in_free_log_thread( void );
void in_thread_log_exit( void *thread_data );
xx1_s32 in_get_thread_log_file_name( xx1_s8 *file_name, size_t size );
void in_write_log( xx1_s8* message );

void in_free_log ( void )
{
	
	pthread_key_delete( g_thread_key );
	if ( NULL != g_proc_name )
	{
		free( ( void * )g_proc_name );
		g_proc_name = NULL;
	}
	if ( NULL != g_log_dir )
	{
		free( ( void * )g_log_dir );
		g_log_dir = NULL;
	}

}

void in_free_log_thread( void )
{
	xx1_s8 *tmp_thread_name = NULL;

	
	tmp_thread_name = ( xx1_s8 * )pthread_getspecific( g_thread_key );
	if ( NULL == tmp_thread_name )
	{
		return;
	}

	free( ( void * )tmp_thread_name );
}

void in_thread_log_exit( void *thread_data )
{
	
	in_free_log_thread();
	return;
}

xx1_s32 in_get_thread_log_file_name ( xx1_s8 *file_name, size_t size )
{
	xx1_s8 *tmp_thread_name = NULL;

	size_t time_size;
	time_t tmp_cur_time;
	xx1_u8 log_date[32 + 1] = {0};

	
	tmp_thread_name = ( xx1_s8 * )pthread_getspecific( g_thread_key );
	if ( ( NULL == tmp_thread_name ) )
	{
		return RET_FAIL;
	}

	
	tmp_cur_time = time( NULL );
	struct tm tm_result;
	localtime_r( &tmp_cur_time, &tm_result );

	time_size = strftime( ( char * )log_date, sizeof( log_date ), "%Y%m%d", &tm_result );
	if ( 0 == time_size )
	{
		return RET_FAIL;
	}

	
	snprintf( ( char * )file_name, size, "%s/%s.%s.%s.seq%d.log", g_log_dir, g_proc_name, tmp_thread_name, log_date, g_process_num );
	return RET_SUCC;
}

void in_write_log ( xx1_s8* message )
{
	FILE *file;
	xx1_s8 log_file[256 + 1] = {0};
	xx1_s32 ret;
	
	ret = in_get_thread_log_file_name ( log_file, sizeof( log_file ) );
	if ( RET_SUCC != ret )
	{
		return;
	}

	if ( ( file = fopen( log_file, "a" ) ) == NULL )
	{
		fprintf( stderr, "open %s error\n", log_file );
		return;
	}

	time_t t;
	time( &t );
	xx1_s8 buf[50];
	ctime_r( &t, buf );
	if ( buf[strlen( buf )-1] == '\n' )
		buf[strlen( buf )-1] = 0;
	fprintf( file, "%s : %s\n", buf, message );
	fclose( file );
}


xx1_s32 init_log( xx1_s32 log_level, xx1_s32 debug_level, const xx1_s8 *proc_name, const xx1_s8 *log_dir , xx1_s32 daemonid)
{
	xx1_s32 ret;

	if ( ( NULL == proc_name ) || ( NULL == log_dir ) )
	{
		return RET_ERR_ARG;
	}
	if ( ( '\0' == proc_name[0] ) || ( '\0' == log_dir[0] ) )
	{
		return RET_ERR_ARG;
	}

	
	ret = pthread_key_create( &g_thread_key, in_thread_log_exit );
	if ( 0 != ret )
	{
		return RET_FAIL;
	}

	g_process_num = daemonid;
	g_log_level = log_level;
	g_debug_level = debug_level;
	g_proc_name = ( xx1_s8 * )( strdup( proc_name ) );
	if ( NULL == g_proc_name )
	{
		return RET_FAIL;
	}
	g_log_dir = ( xx1_s8 * )( strdup( log_dir ) );
	if ( NULL == g_log_dir )
	{
		free( ( void * )g_proc_name );
		g_proc_name = NULL;

		return RET_FAIL;
	}

	int tmp_len = strlen( g_log_dir ) - 1;
	if ( ( g_log_dir[tmp_len] == '\\' ) || ( g_log_dir[tmp_len] == '/' ) )
	{
		g_log_dir[tmp_len] = '\0';
	}

	if ( atexit( in_free_log  ) != 0 )
	{
		in_free_log ();
		return RET_FAIL;
	}

	return RET_SUCC;
}


xx1_s32 init_log_thread( const xx1_s8* thread_name )
{
	pthread_t thread_id;
	xx1_s8 *tmp_thread_name = NULL;
	xx1_s32 ret;

	
	if ( NULL == thread_name )
	{
		return RET_ERR_ARG;
	}
	if ( '\0' == thread_name[0] )
	{
		return RET_ERR_ARG;
	}

	
	thread_id = pthread_self();

	
	tmp_thread_name = ( char * )malloc( strlen( ( char * )thread_name ) +  1 );
	if ( NULL == tmp_thread_name )
	{
		return RET_FAIL;
	}
	memset( tmp_thread_name, 0, strlen( ( char * )thread_name ) + 1 );
	strncpy( ( char * )tmp_thread_name, ( char * )thread_name, strlen( ( char * )thread_name ) );

	
	ret = pthread_setspecific( g_thread_key, ( void * )tmp_thread_name );
	if ( 0 != ret )
	{
		free( tmp_thread_name );
		tmp_thread_name = NULL;
		return RET_FAIL;
	}

	return RET_SUCC;
}

void xx1_log_debug( xx1_s32 level, const xx1_s8* fmt, ... )
{
	va_list tmp_list;
	char buf_fmt[XX1_BUF_LEN_BIG] = {0, };

	
	if ( NULL == fmt )
	{
		return;
	}

	if ( ( level <= g_log_level ) || ( level <= g_debug_level ) )
	{
		va_start( tmp_list, fmt );
		vsnprintf( ( char * )buf_fmt, sizeof( buf_fmt ) , (char * )fmt, tmp_list );
		va_end( tmp_list );
	}

	if ( level <= g_debug_level )
	{
		fprintf( stdout, "[%u] %s\n", ( unsigned int )pthread_self(), buf_fmt );
	}

	if ( level <= g_log_level )
	{
		in_write_log ( buf_fmt );
	}

}



xx1_s32 ini_read_string ( const xx1_s8 *config_filename, const xx1_s8 *key, xx1_s8 *value, size_t size )
{
	xx1_s32 ret = RET_FAIL;
	xx1_s32 tmp_ret;
	FILE *fp = NULL;
	xx1_s8 line_buf[XX1_BUF_LEN_NORMAL] = {0};
	xx1_s8 key_str[XX1_BUF_LEN_LESS] = {0};
	xx1_s8 value_str[XX1_BUF_LEN_LESS] = {0};
	xx1_s32 value_int;

	
	if ( NULL == config_filename )
	{
		return RET_ERR_ARG;
	}
	if ( '\0' == config_filename[0] )
	{
		return RET_ERR_ARG;
	}

	if ( NULL == key )
	{
		return RET_ERR_ARG;
	}
	if ( '\0' == key[0] )
	{
		return RET_ERR_ARG;
	}

	if ( ( NULL == value )  || ( 0 == size ) )
	{
		return RET_ERR_ARG;
	}


	
	fp = fopen( ( char * )config_filename, "r" );
	if ( NULL == fp )
	{
		return RET_FAIL;
	}

	
	while ( 1 )
	{

		if ( feof( fp ) )
		{
			break;
		}


		memset( line_buf, 0, sizeof( line_buf ) );
		if ( fgets( line_buf, sizeof( line_buf ) - 1, fp ) == NULL )
		{
			break;
		}


	
		tmp_ret = sscanf( line_buf, "%s %s", key_str, value_str );
		if ( -1 == tmp_ret )
		{
			memset( value_str, 0, sizeof( value_str ) );
			tmp_ret = sscanf( line_buf, "%s %d", key_str, &value_int );
			if ( -1 == tmp_ret )
			{
				continue;
			}
			snprintf( value_str, sizeof( value_str ), "%d", value_int );
		}


		if ( '#' == key_str[0] )
		{   
			continue;
		}
		if ( '\0' == key_str[0] )
		{   
			continue;
		}
		if ( '\0' == value_str[0] )
		{   
			continue;
		}

	
		if ( strcmp( key_str, ( char * )key ) == 0 )
		{
			strncpy( ( char * )value, value_str, size - 1 );
			ret = RET_SUCC;

			break;
		}
		else
		{
			continue;
		}


	}

	
	fclose( fp );

	return ret;
}


xx1_s32 ini_read_int ( const xx1_s8 *config_filename, const xx1_s8 *key, xx1_s32 *value )
{
	xx1_s32 ret = RET_FAIL;

	xx1_s8 int_str[XX1_BUF_LEN_TINY];

	
	if ( NULL == config_filename )
	{
		return RET_FAIL;
	}
	if ( '\0' == config_filename[0] )
	{
		return RET_ERR_ARG;
	}

	if ( NULL == key )
	{
		return RET_ERR_ARG;
	}
	if ( '\0' == key[0] )
	{
		return RET_ERR_ARG;
	}

	if ( NULL == value )
	{
		return RET_ERR_ARG;
	}

	
	ret = ini_read_string ( config_filename, key, int_str, sizeof( int_str ) );
	if ( RET_SUCC == ret )
	{
		
		*value = atoi( ( char * )int_str );
	}

	return ret;
}



xx1_s32 start_daemon ( const xx1_s8 *work_dir, const xx1_s8 *proc_name )
{
	
	
	pid_t pid;

	if ( ( NULL == work_dir ) || ( NULL == proc_name ) )
	{
		return RET_ERR_ARG;
	}
	if ( ( '\0' == work_dir[0] ) || ( '\0' == proc_name[0] ) )
	{
		return RET_ERR_ARG;
	}

	
	chdir( work_dir );

	pid = fork();
	if ( pid < 0 )  
	{
		return RET_FAIL;
	}
	else
	{
		if ( pid > 0 ) 
		{
			fprintf( stdout, "启动daemon成功\n" );
			exit( 0 );
		}
	}


	pid = getpid();


	pid = setsid();


	umask( 022 );

	fprintf( stdout, "设置为后台运行模式\n" );

	return RET_SUCC;
}


xx1_s32 check_process ( const xx1_s8 *work_dir, const xx1_s8 *proc_name )
{
	pid_t	pid;
	pid_t pid_now;
	FILE *	lockfd = 0;
	xx1_s8 pid_file[XX1_BUF_LEN_NORMAL] = {0};
	xx1_s8 *tmp_dir = NULL;

	if ( ( NULL == work_dir ) || ( NULL == proc_name ) )
	{
		return RET_ERR_ARG;
	}
	if ( ( '\0' == work_dir[0] ) || ( '\0' == proc_name[0] ) )
	{
		return RET_ERR_ARG;
	}
	tmp_dir = strdup( work_dir );
	if ( NULL == tmp_dir )
	{
		return RET_FAIL;
	}

	int tmp_len = strlen( tmp_dir ) - 1;
	if ( ( tmp_dir[tmp_len] == '\\' ) || ( tmp_dir[tmp_len] == '/' ) )
	{
		tmp_dir[tmp_len] = '\0';
	}

	snprintf( pid_file, sizeof( pid_file ), "%s/%s.pid", tmp_dir, proc_name );
	free( tmp_dir );

	if ( ( lockfd = fopen( pid_file, "r" ) ) != NULL  &&	fscanf( lockfd, "%d", &pid ) == 1 && pid > 0 )
	{
		if ( kill( pid, 0 ) >= 0 || errno != ESRCH )
		{
			;
		}
		else
		{
			pid = -1;
		}
	}
	else
	{
		pid = -1;
	}

	if ( lockfd != NULL )
	{
		fclose( lockfd );
	}

	pid_now = getpid();
	if ( ( pid > 0 ) && ( pid != pid_now ) )
	{
		return RET_TRUE;
	}

	if ( ( lockfd = fopen( pid_file, "w" ) ) != NULL )
	{
		fprintf( lockfd, "%d", pid_now );
		fclose( lockfd );
		return RET_FALSE;
	}
	else
	{
		return RET_FAIL;
	}
}

xx1_s32 init_queue (data_queue_t *queue, xx1_s32 size , xx1_s32 buffer_item_size, const xx1_s8 *queue_name, free_data_func func)
{
	
	xx1_s32 ret;
    if ( NULL == queue )
    {
        return RET_ERR_ARG;
    }

    memset( queue , 0 , sizeof( data_queue_t ) );
    
    ret = pthread_mutex_init( &( queue->mutex ), NULL );
    if ( ret )
    {
        return RET_FAIL;
    }

    if ( sem_init( &( queue->semaphore ) , 0 , 0 ) != 0 )
    {
        pthread_mutex_destroy( &( queue->mutex ) );
        return RET_FAIL;
    }

    queue->buffer = ( void ** )malloc( size * buffer_item_size );
    if ( NULL == queue->buffer )
    {
        sem_destroy( &( queue->semaphore ) );
        memset( &( queue->semaphore ) , 0 , sizeof( sem_t ) );

        pthread_mutex_destroy( &( queue->mutex ) );
        memset( &( queue->mutex ) , 0 , sizeof( pthread_mutex_t ) );
        return RET_FAIL;
    }

    queue->size = size;
    queue->free_func = func;
    if ( NULL != queue_name )
    {
        strncpy( queue->queue_name, queue_name, sizeof( queue->queue_name ) - 1 );
    }
    return RET_SUCC;
}

void add_to_queue ( data_queue_t *queue, void * data )
{
	
	 void *data_item = NULL;

    if ( ( NULL == queue ) || ( NULL == data ) )
    {
        return;
    }

    pthread_mutex_lock( &( queue->mutex ) );
    if ( queue->count >= queue->size )
    {
        queue->head = ( queue->head + 1 ) % queue->size;
        data_item = queue->buffer[queue->head];
        if ( data_item != NULL )
        {
            //debug_log( LOG_LEVEL_FAILURE , ( xx1_s8 * ) "%s队列满,将丢弃位于buffer[%d]的数据" , queue->queue_name, queue->head );
        }
        if ( NULL != queue->free_func )
        {
            queue->free_func( data_item );
        }

        queue->buffer[queue->head] = NULL;
        queue->tail = ( queue->tail + 1 ) % queue->size;
		 queue->buffer[queue->tail] = data;
    }
    else
    {
        queue->count++;
        queue->tail = ( queue->tail + 1 ) % queue->size;
        queue->buffer[queue->tail] = data;
        sem_post( &( queue->semaphore ) );
    }
    pthread_mutex_unlock( &( queue->mutex ) );
}

void *get_from_queue( data_queue_t *queue )
{
    void *data_item = NULL;
    xx1_u32 temp_head = 0;

    if ( NULL == queue )
    {
        return NULL;
    }

    sem_wait( &( queue->semaphore ) );

    pthread_mutex_lock( &( queue->mutex ) );
    temp_head = queue->head;
    temp_head = ( temp_head + 1 ) % queue->size;
    if ( queue->buffer[temp_head] != NULL )
    {
        queue->head = ( queue->head + 1 ) % queue->size;
        data_item = queue->buffer[queue->head];
        queue->buffer[queue->head] = NULL;
        queue->count--;
    }
	else
    {
        data_item = NULL;
    }

    pthread_mutex_unlock( &( queue->mutex ) );

    return data_item;
}

void free_queue( data_queue_t *queue )
{
    xx1_s32 ret;
    if ( NULL == queue )
    {
        return;
    }

    ret = sem_trywait( &( queue->semaphore ) );

    if ( ret != 0  )
    {
        sem_destroy( &( queue->semaphore ) );
        memset( &( queue->semaphore ) , 0 , sizeof( sem_t ) );
        pthread_mutex_destroy( &( queue->mutex ) );
        memset( &( queue->mutex ) , 0 , sizeof( pthread_mutex_t ) );

        free( ( void * )( queue->buffer ) );
        queue->buffer = NULL;

        memset( queue, 0, sizeof( data_queue_t ) );
		
			 return;
	}
		
			pthread_mutex_lock( &( queue->mutex ) );
			xx1_u32 i;
			for ( i = queue->head ; i < ( queue->head + queue->count ) ; i++ )
			{
				if ( NULL != queue->free_func )
				{
					queue->free_func( queue->buffer[i%queue->size] );
				}
			}
			free( ( void * )( queue->buffer ) );
			queue->buffer = NULL;
			pthread_mutex_unlock( &( queue->mutex ) );
		
			sem_destroy( &( queue->semaphore ) );
			memset( &( queue->semaphore ) , 0 , sizeof( sem_t ) );
			pthread_mutex_destroy( &( queue->mutex ) );
			memset( &( queue->mutex ) , 0 , sizeof( pthread_mutex_t ) );
		
			memset( queue, 0, sizeof( data_queue_t ) );
}

