

# prove critical section is accessed in increasing order of timestamp

proof of the contrapositive 

Take the base case of 2 sites (TODO)

Take the case of 3 sites.   

Now assume the contradiction has happened - that the critical section was indeed entered in decreasing order.   

Then work backwards by examining each message exchange to prove this cannot happen.  

Say site 2 entered the critical section with lower timestamp than site 1.   

Work out the series of request-reply exchanges that could have triggered this condition.  

You will arrive at a case where this would contradict with the algorithm itself.  
