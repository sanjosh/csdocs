
# type-1 vs type-2 hypervisors

machine has user and kernel mode instructions

a machine is virtualizable if the sensitive instruction is a subset of privileged instruction.
- Popek and Goldberg (1974)

this principle is used in bare metal hypervisors

type-2 hypervisors use binary translation

Paravirtualization modifies source of guest OS to replace sensitive instructions.

