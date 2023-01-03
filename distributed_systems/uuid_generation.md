
## requirements

1. globally unique but distributed generation (add region into id)
2. does recycling of ids pose any danger
3. ability to debug where it was generated
4. ability to query based on wildcards
5. insusceptible to guessing attacks (secure)
6. backward compatible schemes (length, unicode)
7. sortable : put timestamp 


## example twitter snowflake

timestamp + worker + thread + local counter

## example aws arn or ec2 instance id


