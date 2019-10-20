
# Pattern matching at scale

netflix

https://www.youtube.com/watch?v=WykSdgtLDD0

https://www.thestrangeloop.com/2019/pattern-matching-at-scale-using-finite-state-machine.html

## requirements

1. signup flow : select plan, enter credential, select payment
2. existing user : how did user get to this page like “add to watchlist, playback”
3. then there are A/B tests running

ques
1. how much time spent on page
1. was page abandoned
1. pages get changed
1. find loops where user stuck
1. left for external page
1. page has widgets rendered by multiple services

## Solution

typical solutions
1. wildcard matching
1. filter & window functions (record the page, lead, lag)
1. build graph data model

## Conduit

timestamp, page, country, customer (guid?)

apache spark : scales well, heterogenous sources, transformations

use event filter to eliminate logs which are not needed by regex

1. parse the regex into a AST
1. use scala parser combinator
1. convert AST into FSM
1. partition data by GUID ?
1. then match event log against FSM

do u support multiple pattern match in single pass of data ?
