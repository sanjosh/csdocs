
# awesome

https://github.com/Funkmyster/awesome-supply-chain


# warehousing

1. demand forecasting
2. inventory management

# transportation

# intra-city logistics

1. VRP


# Rough notes

## Demand forecasting

1. product attributes, placement, discount
2. store characteristics
3. seasonal
4. customer demographic, number of customers around store
5. competitors
6. sudden factors (war, shocks)
7. substitution
8. complementarity

## Customer table

## Item table
1. SKU
2. Details
3. Expiration time if perishable
4. Size of item
5. type of item
6. weight of item
7. temperature handling


## Vendor table

1. Vendor
2. Bank account
3. Address


## Item Purchase table
1. SKU
2. Price
3. Vendor
4. time of price
5. Discounts


## Supplier table
1. SKU
2. Replenishment time to each warehouse
3. Price

## Order table
1. Order
2. Customer
3. Items
4. Price + Payment
5. Priority
6. Returned - return order number

## Returned Order table
1. Returned number
2. Original order number

## Warehouse table
1. Item
2. Quantity
3. Amount Reserved for order

## Warehouse arrival table

## Warehouse departure table

## Backfill table (to replenish items which were ordered)

## Item movement table
1. Item
2. Time of recording
3. Location

## Transport schedule table
1. Type (truck, air)
2. Capacity (containerize?)
3. Start time
4. End time
   
## Freight Movement plan
1. Transport number
2. Items in this plan
3. Start time
4. End time

## questions

1. where is the item
2. what to replenish and when
3. what is current ETA
4. what was ETA given when order was placed 
5. find nearest warehouse to customer
6. order priority and replenishables decides use of network
7. plan again if disruption in network after guaranteeing order
8. generate macro plan and then micro plan
9. how to model flexible capacity (pay more, ship faster - add attribute tag to each order)
10. alternative network routes
11. Demand variability (Fast, average, slow movers)
12. Replenish time for item
13. Purchase and sale price, find Turnover


## ETA given when order was placed

1. breakdown the number of hops
2. assign container sequence number to destination based on number of pending orders divided by container size
3. estimate time per hop

## Network routing from warehouse to warehouse

1. Get all pending orders
2. allocate to containers
3. assign to freight

## Hyperlocal routing

1. Get all items to be delivered to each locality
2. Find capacity of each delivery person
3. Plan the route for each delivery
4. Save


# Inventory management algo

## Economic order quantity (EOQ)

## Day Sales inventory (DSI)
   
