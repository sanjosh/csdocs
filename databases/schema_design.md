
# table

## primary key independent of content

```
Do NOT use "your problem primary key" as your logic model primary key.
For example passport number, social security number, or employee contract number as these "natural keys" can change in real world situations. Make sure to add UNIQUE constraints for these where necessary to enforce consistency.
```


https://stackoverflow.com/a/338424

## unique constraints on natural keys

Wherever artificial keys are used, you should always also declare unique constraints on the natural keys

## Prefer a numeric type because numeric types are stored in a much more compact format than character formats

## character keys instead of numeric codes for ref tables and small master tables

to avoid joins

http://database-programmer.blogspot.com/2008/01/database-skills-sane-approach-to.html

## integer keys for large master tables

## patterns

http://database-programmer.blogspot.com/2008/01/table-design-patterns.html

## Model Temporal Data Explicitly

Track time-based data with:

1. created_at, updated_at, deleted_at (soft deletes)
2. valid_from / valid_to for versioning

## indices

1. composite
2. partial
3. background indexing


# ORM

# pagination 

## pagination across databases

