
The N+1 query antipattern happens when a query is executed for every result of a previous query.

https://blog.appsignal.com/2020/06/09/n-plus-one-queries-explained.html

https://secure.phabricator.com/book/phabcontrib/article/n_plus_one/

instead of
```
SELECT * FROM cat WHERE ...
SELECT * FROM hat WHERE catID = 1
SELECT * FROM hat WHERE catID = 2
SELECT * FROM hat WHERE catID = 3
SELECT * FROM hat WHERE catID = 4
SELECT * FROM hat WHERE catID = 5
```

do
```
SELECT * FROM cat WHERE ...
SELECT * FROM hat WHERE catID IN (1, 2, 3, 4, 5, ...)
```
