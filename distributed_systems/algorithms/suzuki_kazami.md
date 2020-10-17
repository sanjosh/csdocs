
# prove it enters Critical section in bounded time

The token queue is of bounded length (max N). 
The token queue is transmitted with token to each site in the Privilege message  
Therefore, once a site gets into the token queue, it is guaranteed to get the token in finite time. 
 
How many request messages does it take to enter the token queue ?  
solve cases...  
* message is sent to a site having token but in Critical section,  
* message is sent to a site having token and not in Critical section,  
* message is sent to a site not having token  
