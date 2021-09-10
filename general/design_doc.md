
# Document the decision process from the Requirements to the Alternative Solutions

Between the Requirements and Solution, there are certain Constraints which need to be documented.

Before you decided on a few alternative solutions, you had identified certain constraints which drove your decision process. For example, “Service_A has a 4K limit so we cannot go this route, whereas Service_B cannot throttle so we need to do XYZ to work-around this limitation”. Document this thought process in your design doc so discussions are more focused.

# Clearly bring out the differences in the alternative solutions

Sometimes it is not clear why one option is different or better than the other. Why is SQS better than Kinesis, or Lambda better than DJS ? Clearly highlight the distinction.

# Flesh out the Assertion 

For example, saying this option has “less maintenance” or “lower latency” is a maxim that cannot be verified. Describe why you think so. Cite some benchmark, sage post, email list posting, internal link to explain.

# Diagrams

In the design doc, paste a link to the original diagram created in the diagram editor (drawio, etc) that you used. This helps in case you want to change the diagram a few months later. Shade the boxes(services) that are being changed.Shade the boxes(services) belonging to your team (as opposed to other teams)Number the arrows so that the reader can trace the call sequence.

# FAQ

Why this and why not that ?


## outline

1. principles
1. requirements
1. perf
1. security
1. cost
1. data model
1. hld
1. lld : lang, env,
1. operational : metrics, upgrade

