
# Lazy defenses for caching (Scaled TTL)

## Soft and hard TTL. 

On Read, if soft TTL expired, treat it as cache hit but refresh cache in background.

## darkmoding 

circuit breakr to downstream and serve from cache (20 min)

## Scaled TTL

(how complex systems fail - richard cook)

cache inconsistencies should fix themselves
1. adjust TTL based on likelihood that value is correct.  
2. start low and ramp up 
3. if value stays same on consecutive reads, its probably accurate, so increase TTL
4. impl : keep a counter for number of successive consistent reads
5. adapts well to different query patterns 
6. have to ensure short TTL does not cause cache refresh rate to overwhelm backend DB

## Reference

1. Bonnie Eisenmann Twitter @ Strange loop https://www.youtube.com/watch?v=kxMKnx__uso
2. Slides http://bit.ly/strangeloop-cache
