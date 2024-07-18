
# data model

https://www.notion.so/blog/data-model-behind-notion

```
Everything you see in Notion is a block.
Text, images, lists, a row in a database, even pages themselves — these are all blocks,
dynamic units of information that can be transformed into other block types or moved freely within Notion.
They’re the LEGOs we use to build and model information

```

 The attributes of a block determine how that information is rendered and organized.

 ID — each block is uniquely identifiable by its ID.

 Properties — a data structure containing custom attributes about a specific block. 

 Type — every block has a type, which defines how a block is displayed, and how the block’s properties are interpreted.

 ## indentation

 ```
Have you ever been surprised by how indentation works in Notion?
 In conventional word processors, indentation is presentational:
it only affects the spacing of text from the margins.

In Notion, indentation is structural: it’s a reflection of the structure of the render tree.
In other words, when you indent something in Notion,
you are manipulating relationships between blocks and their content, not just adding a style.
```

## real time updates

```
Every client has a long-lived WebSocket connection to MessageStore, Notion’s real-time updates service.

When the Notion client renders a block (or page, or any other kind of record),
the client subscribes to changes of that record from MessageStore using this WebSocket connection.

When your friend opens the same page as you, they’re subscribed to changes of all those blocks.
```

##  saving data

```
TransactionQueue sits empty, so the transaction to create the block is sent to Notion’s server right away in an API request.
The transaction data is serialized to JSON and posted to the /saveTransactions API endpoint

In the background, we schedule additional work depending on the kind of change made for your transaction.
For example, we schedule version history snapshots and indexing block text for Quick Find.
Importantly, we also notify MessageStore — Notion's real-time updates service — about the changes you made.
```
