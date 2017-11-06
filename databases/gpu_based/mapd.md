
# Observations
1. Use of Apache Arrow for in-memory data
2. They have their own rudimentary SQL optimizer but can also use Apache Calcite.  Apache Calcite can run in another process or inside same process in a JVM.  
3. Once the query plan is prepared by either optimizer, it is passed to the Execution Engine which uses LLVM.
4. LLVM generates JIT code and compiles it to CPU or GPU (using NVIDIA ptx backend).  This means same query can run on CPU or GPU based on configuration.  
5. Tables are fragmented so multiple GPUs can run the same query.
6. They have a rudimentary string dictionary - just a per-table mapping from integer to string.
7. The schema catalog for all tables is saved to SQLite and loaded on restart.
8. LDAP can be used for authentication
9. They use some functions of the Thrust library from Nvidia (like Alenka) 
