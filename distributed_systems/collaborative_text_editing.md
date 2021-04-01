
# requirements

1. consistency
2. handle delete - tombstone
3. handle undo
4. latency
5. scale - central relay vs peer to peer(WebRTC)
6. offline editing

# Naive

send each op to all other users - introduces race conditions

# Google Docs - Wave - Operational Transform

OT invented in 1989 in GROVE

before applying op, transform it based on previous ops at same position

not commutative

# differential sync

diff patch match

https://neil.fraser.name/writing/sync/

# CRDT

...structuring the document in a certain way, and not really on structuring the operations. 

...while OT will take more time to process than CRDTs, CRDTs will usually end up using significantly more memory than OT.

# use of ordered list CRDT
1. each character has unique identifier (siteId, siteCounter)
1. insert this char with identifier (siteId, siteCounter) after character with this identifier (siteId1, siteCounter2)

what if two sites insert new character after same character ?
1.  while inserting, you can skip over existing elements with greater id

at 36 min, https://www.youtube.com/watch?v=B5NULPSiOGw

Solution

## (SiteId, SiteCounter) 

The 1st requirement is that each character object must be globally unique. 

This is achieved by assigning Site ID and Site Counter properties whenever a new character is inserted. 

Since the Site Counter at each site increments whenever inserting or deleting a character, we ensure the global uniqueness of all characters.

## (Fractional Indices) 

The 2nd requirement for a collaborative text editor CRDT has to do with the positioning of characters. 

Since we’re building a text editor, preserving the order of characters within a text document is required. 

But for a collaborative text editor where each user has their own copy of the document, we must go a step further. 

We need all the characters to be globally ordered and consistent. 

That means that when a user inserts a character, it will be placed in the same position on every user’s copy of the shared document.

## difference 

Relative positions are the key concept that differentiates a CRDT from OT. 

The positions of characters in a CRDT never change even if the characters around them are removed. 

Furthermore, the relative position can always be used to determine the location of the character in the document.


# references

1. https://medium.com/@ravernkoh/collaborative-text-editing-with-logoot-a632735f731f
2. https://medium.com/@srijancse/how-real-time-collaborative-editing-work-operational-transformation-ac4902d75682
3. https://github.com/facebook/draft-js/issues/93
4. https://github.com/ritzyed/ritzy/blob/master/docs/DESIGN.adoc
5. Victor Grishchenko Causal Trees
6. https://conclave-team.github.io/conclave-site/#operational-transformation-ot
7. https://stackoverflow.com/questions/5086699/real-time-collaborative-editing-how-does-it-work
8. Ahmed-Nacer Evaluating CRDTs for Real-time Document Editing
9. https://en.wikipedia.org/wiki/Operational_transformation#Consistency_models
