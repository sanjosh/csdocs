
# using modified preorder traversal

each node has 2 numbers - first during walk down, second during walk up


parent | title | left | right
--------------------------------
       | food  |  1   | 18
food   | fruit  |  2   | 11

## retrieve subtree

SELECT * FROM tree WHERE lft BETWEEN 2 AND 11;

## path to node

SELECT title FROM tree WHERE lft < 4 AND rgt > 5 ORDER BY lft ASC;

## number of descendants

descendants = (right + left - 1) / 2

## adding a node

update left & right values of all nodes

## ref

https://www.sitepoint.com/hierarchical-data-database-3/

https://searchoracle.techtarget.com/tip/Trees-in-SQL

