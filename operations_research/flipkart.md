

# Flipkart supply chain

1. OMS (order id)
2. Supply chain (plan - shipment id)
3. Transport Management System (mid-mile, last mile)


## overview

https://www.youtube.com/watch?v=516CoeYlUBU

senthil PM

### problem statement

1. product categories
2. product attributes (fragile, inflammable, multi part)
3. customer segments (plus, metro, women)
4. fulfilment models (JIT, preorder, omnichannel, hyperlocal, brand warehouse)
5. supply chain services (next day, scheduled, reverse)

questions
1. how should inventory be reserved and when it should be released
2. should orders be processed real-time or batch
3. shipment flow path can be multiple
4. how to manage exceptions - (cancel, change of delivery day, strike)
5. when should transport be initiated
6. what choices to offer customer

larger problems
1. forecasting
2. demand prediction (opportunity cost)
3. inventory planning

## steps

1. estimate times - do backward propagation
2. every 12 hours, plan the shipment batch
3. every 15 minutes, monitor

## decisions

1. which warehouse ? consider future orders.  
2. identify flow paths choices (cost vs SLA tradeoff)
3. assess risks
4. inventory allocation (pre-orders versus now versus later)

## how to batch orders

1. flow path is known
2. transport connection balancing
3. transport grouping
4. backward propagation - zero queue - latest point at which shipment can be released from warehouse
5. forward propagation - earliest time to release order from warehouse

## warehouse selection

1. model into common unit - business value
2. model time into opportunity cost - business value
3. model risk as reliability coefficient - business value

objective function : max value of batch order

parameters
1. cost curve of order
2. cost of serving order
3. cost (C_t and C_s) across flow path
4. identification of path
5. identification of warehouse



## anomaly detection

govind pandey

https://www.youtube.com/watch?v=UiyQT6g7Bs8

1. seller -> pickup hubs
2. warehouse (product sorted by category)
3. sortation center (product sorted by destination)
4. delivery hubs (product sorted by final destination or truck)

started as cron, then dashboard, then alerting

### Metrics 

1. breaches (not delivered on time)
2. leading indicators : throughput per hour in each warehouse or sortation center

leading indicators more important : signal of future breach

### anomaly algo

isolation forest after massaging time series data

## control tower or cockpit

monitoring

## process 

```
Once a customer places an order and selects a delivery slot, last mile and mid-mile delivery timelines are calculated
and Flipkart arrives at the timeframe the warehouse has to put the order together.

This involves creation of the picklist, which is then downloaded on to the pickers’ app, who pick 4­–5 orders at a time and ready them for palletisation.

Once the items are in pallets, quality checks are performed and orders are cross-checked.

Finally, totes are readied for handover and considered dispatched when they are transferred to the logistics partners.

With this framework in mind, assume that the warehouse requires a chunk of 4 hours to ready an order, and the entire duration is split into 15-minute intervals. Complex models define the ideal upper and lower limit of work to be done and determine the ideal percentage of completion. Now, as metrics are measured as work done in every 15-minute interval, it’s easy to compare this information with the historical data to identify anomalies, if any.

```

https://www.linkedin.com/pulse/anomaly-detection-flipkarts-secret-ingredient-customer-konduri/

```
When a person places an order, the first point of contact is called the Order Management System (OMS). While this is outside the boundaries of what we enable at Flipkart FSG team, this is critical as the input from OMS becomes the trigger to get our supply chain engine running. So once the customer places an order and the payment is through, OMS triggers a notification to the Supply Chain system.

With Grocery, this trigger is quite different as the customers have the option to choose a delivery time slot — what we internally refer to as Slotted Deliveries. Now it is necessary to understand that there will be multiple triggers for slotted Grocery deliveries, within different time frames, and here is where our planning engine comes into the picture.

Planning is, perhaps, the most critical phase of the supply chain journey in Groceries. Once the inputs from Order Management System are in, and about 12 hours ahead of the promised slot, is when planning comes to play. Based on the volume of orders, address sets, and the time slots, the flow is triggered at the warehouse, where everything from the creation of a picklist, quality check, inventory allocation, resource allocation, and transportation are pinned down with associated time to act.

Once the planning phase is completed and the warehouse allocates orders, Grocery for particular locations and slots are allocated in a series of totes. Totes are basically the plastic containers that you would see in supermarkets, and products in each tote are segregated as per their nature — consumables separated from non-food, and thereon.

Once the totes are filled, they are batched and placed on pallets, which then move to the TMS phase (Transport Management System). Based on the size of the shipment to a particular location, the pallets are loaded into different vehicles and packed in the order of shipment slots. In most scenarios, the vehicles uses are large in capacity handling.

Here is where things change a bit. While traditionally Grocery deliveries were dispatched on an order basis, segregated at an individual order level, the new system enables Flipkart to plan ahead and segregate orders to a location, as per each shipment container. The shipment, in the new scheme of work, moves from the warehouse to a Crossdoc, which is an intersection point for multiple order deliveries. Crossdocs are location intensive and can be anywhere from a playground to a parking zone, from where Wishmasters catering to select beats within a specific geo-locate can segregate packages as per delivery slots, and effortlessly deliver them, on time.

So far, the orders have moved from the Order Management System to the Warehouse Management System, and then to the Transport Management System, and are now in the hands of the Wishmasters. For our Wishmasters to make successful deliveries, it is necessary that they have very precise direction on the drop locations within their beat. This is where Flipkart’s Geocoding technology and Automated Beat Planner or ABP comes into the picture. You can read more about it in the link above.

What Geocoding and ABP do, in short, is provide the intelligence to the Wishmaster to make his deliveries most accurate, through a Machine Learning-based solution. The Wishmaster also gains insights in the form of simple alerts, on the order of deliveries he needs to make, to ensure that promises are met on time, and RTOs are reduced drastically.

Flipkart’s algorithms are able to geocode over 90% of customer free-flow text addresses to a 200 meter level accuracy. The entire exercise of geocoding and planning takes only about 40 minutes to give the most optimal routes for 5,000 orders
```


https://www.linkedin.com/pulse/geek-behind-flipkarts-venture-groceries-general-overview-bhagat/

https://www.youtube.com/watch?v=RT2sP5_chIc

## incremental data processing (arkham)

mix of streaming and batching

1. Agility refers to the time to handle new requirements and change existing flows as business evolves. 
2. Freshness represents the time lag between a change being made to a source system and it becoming available in our system. 
3. Completeness refers to how closely the state of the data in our system matches the source system within the freshness constraints.

```
Our need was a combination of the best of both streaming and batch paradigms. We were ready to incur a higher complexity during conception of the platform to enable business agility in the future and achieve our end goal of high accuracy at significantly lower latencies.
```

### DAG

```
Transactional data models have well defined relationships across the normalized entities. They go through changes iteratively as business evolves but these are occasional for a well designed system. These relationships across entities can be captured with a directed acyclic graph (DAG) for analytical purposes. The DAG has additional metadata which helps identify different types of joins that need to be evaluated for the relationship. We express this DAG in a proprietary Transformation Description Language. This is declarative in nature and can be changed in flight. Changes are picked up with the next transform cycle. The image below a simple example of a DAG.
```
![image](https://github.com/user-attachments/assets/13a1b7fe-faa8-44fa-99a0-2f7ec9d33bf5)



https://www.linkedin.com/pulse/services-fulfilment-cockpit-why-passengers-within-flipkarts-pandey/

## beat planner

1. Geocode
2. cluster identification
3. traffic prediction

```
a ‘beat plan’ is the path that a delivery van traverses while performing deliveries. Identifying optimized paths for vans is definitely no easy feat and this was the fundamental use-case for designing the Automated Beat Planner (ABP). For Flipkart, another critical input to ensure the success of the ABP initiative was the Geocode of addresses.
```

### cost vs SLA

ABP was developed with two intentions — maximizing customer experience, and optimizing the cost on deliveries — and for a tool to achieve this, requires multiple input signals. Aside from the input signals, another critical dependency, especially in the Indian context, is the precision of address to be delivered to. In India, where many pincodes have labyrinths within them and where addresses can take myriad and often ridiculous forms, pinpointing a location every time requires a huge investment in technology.

we have a concept of ‘Cluster Identification’. Cluster identification is nothing but a geographical area with multiple pin codes. Basis input business parameters of demand density and delivery costs clusters are auto generated with a functionality to manual override and adjust the cluster boundaries bias serviceability definition. Hub employees have been enabled with the UI to modify and generate their own clusters. This ensures orders are assigned accurately to a serviceable hub which is critical for on-time delivery.

https://www.linkedin.com/pulse/how-flipkart-fsg-enabling-perfect-grocery-deliveries-geocoding-madan/

