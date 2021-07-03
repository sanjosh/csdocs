
# Gmail Smart reply

Input = incoming message

output distribution = space of possible replies

we use semi-supervised learning to construct a target response space R comprising only high quality responses. 
Then we use the model described here to choose the best response in R, rather than the best response from any sequence of words in its vocabulary.

to improve specificity of responses, we apply some light normalization that penalizes responses which are applicable to a broad range of incoming messages.  

to increase the breadth of options shown to the user, we enforce diversity by exploiting the semantic structure of R

improve the utility of suggestions by first passing each message through a triggering model (described in Section 6) 
that determines whether suggestions should be generated at all.

We parse each sentence using a dependency parser and use its syntactic structure to generate a canonicalized representation.

user should never see two responses of the same intent

If the top two responses (after omitting redundant responses) contain at least one positive response and none of the top three responses are negative, 
the third response is replaced with a negative one.

## Ref

1. Kannan, et al. Smart Reply: Automated Response Suggestion for Email
