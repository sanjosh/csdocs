
http://geeki.wordpress.com/2010/10/30/ways-of-sleeping-in-linux-kernel/

(1)
set_current_state(TASK_INTERRUPTIBLE);
schedule();

(2) use wait queue
DECLARE_WAIT_QUEUE_HEAD(my_event);
wait_event_interruptible(my_event, (cond==x));

(3) call msleep()

