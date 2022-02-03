
backend

provider

data : allow Terraform to use information defined outside of Terraform

locals : 

variables (variables.tf) : Input variables to accept values from the calling module.

output (outputs.tf) : Output values to return results to the calling module.

## module

source : where to find source code for 

depends_on

A module intended to be called by one or more other modules must not contain any provider blocks.

To declare that a module requires particular versions of a specific provider, use a required_providers

dependency inversion : keep modules relatively small and pass in their dependencies.


## resource

# commands

init

validate

plan

apply

output 

destroy

state

show

# config

```
README.md
main.tf
variables.tf
output.tf

prod/
  
modules/
  module1
    README.md
    main.tf
    variables.tf
    output.tf
```

