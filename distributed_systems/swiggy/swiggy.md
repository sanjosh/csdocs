
https://bytes.swiggy.com

# Delivery Logistics

three-way marketplace : consumers, delivery people restaurants

https://bytes.swiggy.com/the-swiggy-delivery-challenge-part-one-6a2abb4f82f6

Delivery Time = Max (Assignment Delay + First Mile Time, Prep Time) + Last Mile Time

## how to find all serviceable restaurants ?

1. show too few => may not order
2. show too many => takes too long
3. show small delivery times => cannot deliver
4. show too high delivery time => may not order

https://en.wikipedia.org/wiki/Goldilocks_principle

## estimate delivery time

food becomes stale beyond a point, depending on its category

cannot use Google maps
1. too slow to calc times for all combinations of routes
2. expensive
3. not accurate for 2 wheelers
4. cannot predict time from gate to flat

solution
1. leverage historical data
2. enhance with real time signal

## estimate restaurant preparation time

1. type of item
2. quantity of item
3. load at restaurant

## delivery executive assignment and first mile (reach the restaurant)

if 10 customers in order process, cannot prematurely assign delivery person to one customer before order

# Distance service

1. all restaurants in proximity to customer
2. first mile time
3. last mile time
4. figure out if 2 orders are on same route

Google Distance Matrix API (GDMA)
Open Street Maps

divide region into cells - geohash - at what precision

cache the results from GDMA - redis or aerospike
key = source geohash + dest geohash

# Communication service

1. define templates
2. priorities (transaction, marketing)
3. channel : push, SMS, email

https://bytes.swiggy.com/kabootar-swiggys-communication-platform-e5a43cc25629

# User service

Grand Master

# Delivery App

1. maps not loading
2. earnings not visible quickly
3. app drains battery
4. where should they be present to get more orders

principles

1. build for muscle memory
2. imp stuff up front (repetitive tasks)
3. big bold visuals (variety of lighting conditions)
4. deliver new function without downloading app

https://bytes.swiggy.com/other-side-of-the-swiggy-verse-166bf34cc59c

# Analytics SDK

https://bytes.swiggy.com/swiggylytics-5046978965dc

