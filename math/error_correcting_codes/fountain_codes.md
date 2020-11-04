
# Fountain codes (rateless)

## theory 

Handles only packet loss and not transmission errors

Rate = ratio of N/K (N = encoded blocks; K = original blocks)
Reed-solomon codes : rate has to be set prior to encoding

Fountain codes : are rateless.  Can generated infinite coded blocks from fixed set of source blocks

## Online codes

## LT code

## Raptor code

## Tornado code

## engineering

RFC 5053
https://tools.ietf.org/html/rfc5053

## implementation

https://github.com/google/gofountain/blob/master/raptor.go

https://github.com/obolo/freeRaptor

https://openrq-team.github.io/openrq/

https://github.com/openrq-team/OpenRQ

https://github.com/catid/wirehair

## exposition

https://divan.dev/posts/fountaincodes/
