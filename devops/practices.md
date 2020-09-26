
canary : 
1. deploy in single box with separate metrics with bake time 
2. auto rollback on failure

Tests
1. test exceeds max tps 
2. dependency failure (increase dependency timeout, dependency down)
3. some hosts failed test
4. clean slate test - all new host test with libraries installed afresh
5. OOM test
