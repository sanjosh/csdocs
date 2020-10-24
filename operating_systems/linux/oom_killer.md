
track procs by mem usage;
ps -e -o pid,user,cpu,size,rss,cmd --sort -size,-rss | head

possible val from -17 to 15
echo -17 > /proc/<pid>/oom_adj

badness score
in /proc/pid/oom_score

The badness score is computed using the original memory size of the process, its CPU time (utime + stime), the run time (uptime - start time) and its oom_adj value. 
