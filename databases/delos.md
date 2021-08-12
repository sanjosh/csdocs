
https://engineering.fb.com/2019/06/06/data-center-engineering/delos/

```
Delos is designed around the novel abstraction of a VirtualLog, a type of distributed shared log. 

Individual servers maintain consistency for local copies of state via the VirtualLog.

The replicated state can take any form, ranging from a key-value store to a relational database. 

The VirtualLog abstraction provides the benefits of a shared log design, hiding the complexity of distributed 
coordination and allowing materialization logic to be oblivious to distributed asynchrony and failures.
```
