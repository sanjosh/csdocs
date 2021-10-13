
https://www.infoq.com/articles/Testing-With-Persistence-Layers/

“All tests should be isolated” really means is each test should be able to run independently of all other tests. Or in other words, you can run any test or set of tests in any order at any time.

The fundamental goal of testing is to produce information. A test should tell you something about the thing being tested you may not have known before. 

 size matters when it comes to databases.

1. create  (data-driven for default columns; dup insert)
2. create-read
2. create-update-read
3. create-delete
4. filtered-read test (only matching rows returned, non-matching not returned)

https://github.com/Grauenwolf/TestingWithDatabases/tree/main/TestingWithDatabases

https://grauenwolf.github.io/DotNet-ORM-Cookbook/index.htm
